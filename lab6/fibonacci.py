import subprocess
import sys

# using sys to pass the input from command line
input = sys.argv[1]

subprocess.run(["g++", "fibonacci_dp.cpp", "-o", "./fibonacci_dp.out"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
result = subprocess.run(["./fibonacci_dp.out", str(input)], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

output = result.stdout.decode().strip().splitlines()
for n in output:
    print(n)