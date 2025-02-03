import numpy as np
import pickle

class Matrix: 
    def __init__(self, data = None):
        if data is None:    # used chatgpt to implement this line: prompt was "why am i getting error code int() argument must be a string...  [code]"
            self.data = np.zeros((10,10), dtype = int)
        else:
            self.data = np.array(data, dtype = int)
        self.target_row = -1
        self.max = None
        self.max_row = None
        self.min = None
        self.min_row = None
    
    def mat_add(self, mat2):
        result = Matrix(None)
        for i in range(10):
            for j in range(10):
                result.data[i][j] = self.data[i][j] + mat2.data[i][j]
        return result
    
    def mat_mult(self, mat2):
        result = Matrix(None)
        for i in range(10):
            for j in range(10):
                result.data[i][j] = 0
                for k in range(10):
                    result.data[i][j] = result.data[i][j] + self.data[i][k]*mat2.data[k][j]
        return result
    
    def linear_search(self):
        first_num = self.data[0][0]
        self.max = self.data[0][0]
        self.min = self.data[0][0]
        self.target_row = -1
        for i in range(10):
            for j in range(10):
                if self.max < self.data[i][j]:
                    self.max = self.data[i][j]
                    self.max_row = i
                if self.min > self.data[i][j]:
                    self.min = self.data[i][j]
                    self.min_row = i
                if i == 0 and j == 0:
                    continue
                if self.data[i][j] == first_num:
                    self.target_row = i

    def format_target_row(self):
        if(self.target_row == -1):
            return "first element not repeated"
        else:
            return self.target_row


matrix1 = Matrix(np.loadtxt("matrix_1.txt", dtype = int))
matrix2 = Matrix(np.loadtxt("matrix_2.txt", dtype = int))

sum_mat1_mat2 = matrix1.mat_add(matrix2)
mult_mat1_mat2 = matrix1.mat_mult(matrix2)

matrix1.linear_search()
matrix2.linear_search()

data = {
    "sum of matrix 1 and 2": sum_mat1_mat2.data,
    "product of matrix 1 and 2": mult_mat1_mat2.data,
    "matrix1": {
        "target_row": matrix1.format_target_row(),
        "max": matrix1.max,
        "max_row": matrix1.max_row,
        "min": matrix1.min,
    },
    "matrix2": {
        "target_row": matrix2.format_target_row(),
        "max": matrix2.max,
        "max_row": matrix2.max_row,
        "min": matrix2.min,
        "min_row": matrix2.min_row, 
    },
}

with open("output_py.pickle", "wb") as f:
    pickle.dump(data, f)
