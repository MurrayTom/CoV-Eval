# SG-Bench
This is the official implementation of "**Can You Really Trust Code Copilots? Evaluating Large Language Models from a Code Security Perspective**", accepted to the 63rd Annual Meeting of the Association for Computational Linguistics (ACL 2025) Dataset & Benchmark Track

This study proposes CoV-Eval, a multi-task benchmark for code security evaluation in large language models (LLMs). CoV-Eval covers diverse task types and a broad range of code security vulnerabilities. We evaluate various general LLMs and code LLMs from a security perspective, focusing on vulnerabilities in generated code as well as their capabilities in vulnerability detection, classification and repair.

## 📚 Resources
- **[Paper](https://aclanthology.org/2025.acl-long.849/):** Details the evaluation benchmark design and key experimental results.

## Contents
- [Install](#install)
- [Usage](#Usage)

## Install
You need to install some packages. We suggest that the python version >= 3.9
```shell
pip install -r requirement
```

## Usage
Next, we provide some reference scripts to guide how to evaluate the code security of LLMs based on CoV-Eval.

### Code Completion
```
CUDA_VISIBLE_DEVICES=1 python evaluation.py \
    --task_type code_completion \
    --model_name qwen2.5-7b-instruct \
    --model_path /home/xxx/Models/Qwen2.5-7B-Instruct \
    --save_dir ./results
```
```
CUDA_VISIBLE_DEVICES=1 python judge.py \
    --task_type vulnerability_repair \
    --model_name llama3.1-8b-instruct \
    --eval_dir ./results/vulnerability_repair \
    --output_dir ./results \
    --judge_model_name gpt-4o \
    --judge_model_path gpt-4o \
    --api_key xxx \
    --api_base xxx
```

### Vulnerability Repair
```
CUDA_VISIBLE_DEVICES=1 python main_test.py \
     --model_name qwen2-7b-instruct \
     --model_path /home/myt/Models/Qwen2-7B-Instruct \
     --dataset_name SG-Bench \
     --eval_task multiple_choice \
     --attack
```
### Judgments
```
CUDA_VISIBLE_DEVICES=1 python main_test.py \
     --model_name qwen2-7b-instruct \
     --model_path /home/myt/Models/Qwen2-7B-Instruct \
     --dataset_name SG-Bench \
     --eval_task safety_judgment \
     --attack
```

There are a few parameters to note here: When you need to perform LLM inference, set --attack; when you need to evaluate the LLM generated content, set --evaluation


## 🖊️ Citing Info

```bibtex
@article{mou2024sg,
  title={SG-Bench: Evaluating LLM Safety Generalization Across Diverse Tasks and Prompt Types},
  author={Mou, Yutao and Zhang, Shikun and Ye, Wei},
  journal={arXiv preprint arXiv:2410.21965},
  year={2024}
}
```
