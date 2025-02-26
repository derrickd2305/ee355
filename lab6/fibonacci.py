import subprocess
import sys

# using sys to pass the input from command line
input = sys.argv[1]

subprocess.run(["g++", "fibonacci_dp.cpp", "-o", "./fibonacci_dp.out"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
result = subprocess.run(["./fibonacci_dp.out", str(input)], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

output = result.stdout.decode().strip().splitlines()

if output[0] == 1:
    print(f"Congratulations! You have the Fibonacci {input}")
elif output[0] == 0:
    print(f"Sorry! {input} is not a Fibonacci number but the next Fibonacci number to it is {output[1]}")
else:
    print("something went wrong with output of cpp function")