Derrick Kim 
6778144851
derrickd@usc.edu

debugging process for brokengdb1.cpp:
  1.  first, set a break at line 20
  2.  type "c" to go through the recursive calls of factorial. When reaching each break point, 
      it shows the value of "n" for that function call, and this showed that the value of n
      did not properly decrement for the function call. This was because the function call was 
      originally "factorial(n--)", which calls the function "factorial(n)" and then decrements it,
      so this would cause an infinite loop
  3.  replaced "factorial(n--)" with "factorial(--n)"
  4.  compiled the code again, placing a break at line 20, and typing "c" to go through each function call.
      This showed that n was now properly decrementing, and continuing to press c until n = 0, but then this
      returned val = 0, so there must have been somewhere in the code that the value was being multiplied by zero.
  5.  for the function call when n=0, i went through line-by-line by pressing s, which showed that the if statement
      was working as intended, so that was not the issue. Looking at the code, this was because n was decremented, and
      then our return value was multiplied by n. This meant that for the function call when n = 1, it would multiply by
      0.
  6.  replaced "return factorial(--n)*n" with "return n*factorial(--n)". The code is now correct.
    
debugging process for brokenASan.cpp:
  1.  we first get a stack-buffer-overflow error of type "READ" on lines 5, 30, and 50, which means that the program
      is most likely trying to access an illegal array index. Line 50: "quickSort(arr, 0, n)", so there must be something
      wrong with how we called this function. Line 30, which is within quickSort: "int pi = partition(arr, low, high)", 
      so we go look at line 5 of partition: "int pivot = arr[high]". For this function call, high = n, which is the size
      of arr[]. arr[n] does not exist, so line 50 should instead be "quickSort(arr, 0, n-1)".
  2.  after this change is made and ASan is run again, it returns the same error type (so another illegal array index) 
      this time on line 41 in printArray() which prints each element of the array, called by line 52 in main(). Looking
      at these lines we see taht printArray was called with size = n, and the for loop checking i <= size, which means
      that the print statement would try to print arr[n], which does not exist. To resolve this issue, we changed line 40 
      so that the for loop checks if i < size instead of i <= size. 
