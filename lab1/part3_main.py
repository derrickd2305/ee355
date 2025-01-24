import numpy as np
import subprocess

arrs = np.loadtxt("data_table.csv", delimiter=",", dtype=str)
#print(arrs)
#print(arrs.shape)

arrs = [i for i in arrs if len(i[0])>0]
print(arrs)
print(np.array(arrs).shape)

#=== array preparation ===
#1. Split arrs into two lists (arr1 and arr2), each of them store the numbers of one column in data_table.csv
#2. Convert arr1 and arr2 to strings (don't forget to include square brackets). E.g., arr1 = "[1.3, 2.4, 4.2, 5.0]"

# Please insert your code here




#=== call C part === (Please don't modify code below this line)
subprocess.run(["gcc", "part3_calc_cov_and_var.c", "-o", "part3_calc_cov_and_var.out"])
direct_output = subprocess.run(["./part3_calc_cov_and_var.out", arr1, arr2], stdout=subprocess.PIPE)

outprint = str(direct_output.stdout)[2:-3]
print(outprint)
