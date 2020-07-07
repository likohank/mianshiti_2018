import numpy as np
import time

matrix = np.matrix('1 1;1 0')


#该矩阵list 是从 matrix 一次方开始， 斐波那切数列第二个元素 对应 本列表第一个矩阵； 第三个元素对应本列表第二个矩阵
def Fibonacci_Matrix_Tool(n):
	matrix = np.matrix('1 1;1 0')
	if n == 1: 
		return pow(matrix,1)

	elif n%2 == 1: 
		return Fibonacci_Matrix_Tool( (n-1)/2 ) ** 2 * matrix
	else:
		return Fibonacci_Matrix_Tool( n/2  ) ** 2

def Fibonacci_Matrix_Tool2(n):
	Matrix = np.matrix('1 1;1 0 ')
	return pow(Matrix,n-1)

def Fibonacci_Matrix(n):
	res = []
	for i in range(0,n):
		res.append(np.array(Fibonacci_Matrix_Tool2(i))[0][0])
	print res
#Fibonacci_Matrix(5)

n  = 5

t_1 = time.clock()
print np.array( Fibonacci_Matrix_Tool2(n))[0][0] 
t_2 = time.clock()
print t_2-t_1



t_1 = time.clock()
print np.array( Fibonacci_Matrix_Tool(n-1))[0][0] 
t_2 = time.clock()
print t_2-t_1
