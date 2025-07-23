import torch
import transformers
from transformers import AutoModelForCausalLM, AutoTokenizer, AutoModel
from transformers import BitsAndBytesConfig, GenerationConfig
from openai import OpenAI

wizardcoder_chat_template = '''
Below is an instruction that describes a task. Write a response that appropriately completes the request.

### Instruction:
{instruction}

### Response:       
'''

model_list = {
    "llama": ["deepseek-r1-distill-llama3.1-8b", "llama3.1-8b-instruct", "llama3-8b-instruct", "llama2-7b-chat", "llama2-13b-chat"],
    "deepseek": ["deepseek-v2-lite-chat", "deepseek-coder-v2-lite-instruct"],
    "codellama": ["codellama-7b-instruct", "codellama-13b-instruct"],
    "qwen": ["qwen2.5-coder-7b-instruct", "qwen2.5-coder-14b-instruct", "qwen2.5-7b-instruct", "qwen2.5-14b-instruct", "qwen2-7b-instruct", "qwen1.5-7b-chat", "qwen1.5-14b-chat"],
    "chatglm": ["chatglm3-6b", "internlm2-7b-chat"],
    "wizardcoder": ["wizardcoder-15b"],
    "VC-Judge": ["VC-Judge"],
}

class LLM_models:
    def __init__(self, model_name, model_path, api_key=None, api_base=None):
        self.model_name = model_name
        self.model_path = model_path
        self.api_key = api_key
        self.api_base = api_base

        if self.model_name == "chatgpt" or self.model_name == "gpt-4" or self.model_name == "gpt-4o" or self.model_name == "claude3":
            self.model = OpenAI(api_key=self.api_key, base_url=self.api_base)

        elif self.model_name == "deepseek-v2-lite-chat" or self.model_name == "deepseek-coder-v2-lite-instruct":
            self.tokenizer = AutoTokenizer.from_pretrained(model_path, trust_remote_code=True)
            self.model = AutoModelForCausalLM.from_pretrained(model_path, trust_remote_code=True, torch_dtype=torch.bfloat16).cuda()
            self.model.generation_config = GenerationConfig.from_pretrained(model_path)
            self.model.generation_config.pad_token_id = self.model.generation_config.eos_token_id

        elif self.model_name == "chatglm3-6b" or self.model_name == "internlm2-7b-chat":
            self.tokenizer = AutoTokenizer.from_pretrained(model_path, trust_remote_code=True)
            self.model = AutoModel.from_pretrained(model_path, trust_remote_code=True).half().cuda()
           
        else:
            self.model = AutoModelForCausalLM.from_pretrained(model_path, device_map='auto', trust_remote_code=True, low_cpu_mem_usage=True, torch_dtype=torch.bfloat16).eval()
            self.tokenizer = AutoTokenizer.from_pretrained(model_path, trust_remote_code=True)

    def generate(self, prompt):
        if self.model_name in model_list["llama"]:
            messages = [
                {"role": "system", "content": "You are a helpful assistant!"},
                {"role": "user", "content": prompt},
            ]

            input_ids = self.tokenizer.apply_chat_template(
                messages,
                add_generation_prompt=True,
                return_tensors="pt"
            ).to(self.model.device)

            terminators = [
                self.tokenizer.eos_token_id,
                self.tokenizer.convert_tokens_to_ids("<|eot_id|>")
            ]

            outputs = self.model.generate(
                input_ids,
                max_new_tokens=4096,
                eos_token_id=terminators,
                do_sample=True,
                temperature=0.6,
                top_p=0.9,
            )
            response = outputs[0][input_ids.shape[-1]:]
            outputs = self.tokenizer.decode(response, skip_special_tokens=True)
            return outputs
        
        elif self.model_name in model_list["deepseek"]:
            messages=[
                { 'role': 'user', 'content': prompt}
            ]
            inputs = self.tokenizer.apply_chat_template(messages, add_generation_prompt=True, return_tensors="pt").to(self.model.device)
            outputs = self.model.generate(inputs, max_new_tokens=512, do_sample=False, top_k=50, top_p=0.95, num_return_sequences=1, eos_token_id=self.tokenizer.eos_token_id)
            response = self.tokenizer.decode(outputs[0][len(inputs[0]):], skip_special_tokens=True)
            return response

        elif self.model_name == "codeshell-7b-chat":
            history = []
            response = self.model.chat(prompt, history, self.tokenizer)
            return response

        elif self.model_name == "mistral-7b-instruct":
            messages = [
                {"role": "user", "content": prompt},
            ]
            input_ids = self.tokenizer.apply_chat_template(messages, return_tensors="pt").to(self.model.device)
            outputs = self.model.generate(input_ids, max_new_tokens=1000, do_sample=True)
            response = outputs[0][input_ids.shape[-1]:]
            outputs = self.tokenizer.decode(response, skip_special_tokens=True)
            return outputs
        elif self.model_name == "qwen2.5-coder-7b-instruct" or self.model_name == "qwen2.5-coder-14b-instruct" or self.model_name == "qwen2.5-7b-instruct" or self.model_name == "qwen2.5-14b-instruct" or self.model_name == "qwen2-7b-instruct" or self.model_name == "qwen1.5-7b-chat" or self.model_name == "qwen1.5-14b-chat":
            messages = [
                {"role": "system", "content": "You are a helpful assistant."},
                {"role": "user", "content": prompt}
            ]
            text = self.tokenizer.apply_chat_template(
                messages,
                tokenize=False,
                add_generation_prompt=True
            )
            model_inputs = self.tokenizer([text], return_tensors="pt").to(self.model.device)

            generated_ids = self.model.generate(
                model_inputs.input_ids,
                max_new_tokens=512
            )
            generated_ids = [
                output_ids[len(input_ids):] for input_ids, output_ids in zip(model_inputs.input_ids, generated_ids)
            ]

            response = self.tokenizer.batch_decode(generated_ids, skip_special_tokens=True)[0]
            return response
        elif self.model_name == "chatgpt" or self.model_name == "gpt-4" or self.model_name == "gpt-4o" or self.model_name == "claude3":
            flag = True
            while(flag):
                try:
                    completion = self.model.chat.completions.create(
                        model=self.model_path,
                        messages=[
                            {"role": "system", "content": "You are a helpful assistant."},
                            {"role": "user", "content": prompt}
                        ]
                        )
                    response = completion.choices[0].message.content
                    flag = False
                    print(flag)
                    return response
                except Exception as e:
                    continue
        elif self.model_name == "chatglm3-6b" or self.model_name == "internlm2-7b-chat":
            response, history = self.model.chat(self.tokenizer, prompt, history=[])
            return response
        
        elif self.model_name == "codellama-7b-instruct" or self.model_name == "codellama-13b-instruct" or "codellama" in self.model_name:
            messages = [
                {"role": "system", "content": "You are a helpful assistant!"},
                {"role": "user", "content": prompt},
            ]

            input_ids = self.tokenizer.apply_chat_template(
                messages,
                add_generation_prompt=True,
                return_tensors="pt"
            ).to(self.model.device)

            terminators = [
                self.tokenizer.eos_token_id,
                self.tokenizer.convert_tokens_to_ids("<|eot_id|>")
            ]

            outputs = self.model.generate(
                input_ids,
                max_new_tokens=512,
                eos_token_id=terminators,
                do_sample=True,
                temperature=0.6,
                top_p=0.9,
            )
            response = outputs[0][input_ids.shape[-1]:]
            outputs = self.tokenizer.decode(response, skip_special_tokens=True)
            return outputs
        
        elif self.model_name == "wizardcoder-15b":
            prompt = wizardcoder_chat_template.format(instruction=prompt)
            input_ids = torch.as_tensor(self.tokenizer([prompt]).input_ids).cuda()
            attention_mask = torch.as_tensor(self.tokenizer([prompt]).attention_mask).cuda()

            outputs = self.model.generate(
                input_ids=input_ids,
                attention_mask=attention_mask,
                do_sample=True,
                temperature=0.1,
                max_new_tokens=512,
                num_return_sequences=1,
            )

            response = outputs[0][input_ids.shape[-1]:]
            outputs = self.tokenizer.decode(response, skip_special_tokens=True)
            return outputs


        elif self.model_name == "VC-Judge":
            messages = [
                {"role": "system", "content": "You are a helpful assistant!"},
                {"role": "user", "content": prompt},
            ]

            input_ids = self.tokenizer.apply_chat_template(
                messages,
                add_generation_prompt=True,
                return_tensors="pt"
            ).to(self.model.device)

            terminators = [
                self.tokenizer.eos_token_id,
                self.tokenizer.convert_tokens_to_ids("<|eot_id|>")
            ]

            outputs = self.model.generate(
                input_ids,
                max_new_tokens=512,
                eos_token_id=terminators,
                do_sample=True,
                temperature=0.1,
                top_p=0.9,
            )
            response = outputs[0][input_ids.shape[-1]:]
            outputs = self.tokenizer.decode(response, skip_special_tokens=True)
            return outputs