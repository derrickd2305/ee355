import subprocess
import argparse

# using argparse to pass the input from command line
parser = argparse.ArgumentParser()
parser.add_argument("n", type = int)
args = parser.parse_args()

subprocess.run(["g++", "fibonacci_dp.cpp", "-o", "./fibonacci_dp.out"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text = True)
result = subprocess.run(["./fibonacci_dp.out", str(args.n)], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text = True)

print(result.stdout)