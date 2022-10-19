#!/bin/bash
#SBATCH    --job-name=EXO1
#SBATCH    --ntasks=1
#SBATCH    --cpus-per-task=1
#SBATCH    --partition=gpu
#SBATCH    --gpus-per-node=1
#SBATCH    --mem=3G
#SBATCH    --time=2:00:00

time ./exo1