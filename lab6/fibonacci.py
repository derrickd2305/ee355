import subprocess
import argparse

# using argparse to pass the input from command line
parser = argparse.ArgumentParser()
parser.add_argument("n", type = int)
args = parser.parse_args()

subprocess.run(["g++", "fibonacci_dp.cpp", "-o", "./fibonacci_dp.out"])
result = subprocess.run(["./fibonacci_dp.out", args.n], capture_output = True, text = True)

output_lines = result.stdout