import subprocess
import sys

# using sys to pass the input from command line
n = sys.argv[1]

# using subprocess to run the the c++""
subprocess.run(["g++", "fibonacci_dp.cpp", "-o", "./fibonacci_dp.out"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
result = subprocess.run(["./fibonacci_dp.out", str(n)], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

# store the output in an array
output = result.stdout.decode().strip().splitlines()

if output[0] == "1":
    print("Congratulations! You have the Fibonacci {}".format(n))
elif output[0] == "0":
    print("Sorry! {} is not a Fibonacci number but the next Fibonacci number to it is {}".format(n, output[1]))
else:
    print("something went wrong with output of cpp function")