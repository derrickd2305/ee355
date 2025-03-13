Derrick Kim
6778144851
EE355 - lab 8

lab8.cpp contains the code to do various image processes to a png and saves those processed images
the code must be compiled like so: 
  g++ -std=c++11 lab8.cpp lodepng.cpp -o lab8.o
  ./lab8.o lena.png

running the code without a file will prompt a unique error code. 
Running the code with a png file that is not within the same directory will also prompt a unique error code. 

some issues i encountered:
-  at first, i had no idea of rd, gen, etc. worked
-  i had a lot of variable type mismatches, which caused a lot of errors, which were fixed using static cast, rounding
-  i was confused on why the grayscale image was a smaller vector (i don't know why i assumed it still had RGBA values)
