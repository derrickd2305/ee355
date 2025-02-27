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
    
