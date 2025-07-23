# CUDA_VISIBLE_DEVICES=1 python evaluation.py \
#     --task_type code_completion \
#     --model_name qwen2.5-7b-instruct \
#     --model_path /home/myt/Models/Qwen2.5-7B-Instruct \
#     --save_dir ./results

CUDA_VISIBLE_DEVICES=1 python judge.py \
    --task_type vulnerability_repair \
    --model_name llama3.1-8b-instruct \
    --eval_dir ./results/vulnerability_repair \
    --output_dir ./results \
    --judge_model_name gpt-4o \
    --judge_model_path gpt-4o \
    --api_key xxx \
    --api_base xxx
