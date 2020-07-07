import os,sys

def fib2(n):
	if n<2: return n

	fibAhead 	= 0 
	fibBehind 	= 1

	for i in range(2,n):
		fibTemp 	= fibBehind
		fibBehind 	= fibAhead + fibBehind
		fibAhead 	= fibTemp
		#fibAhead,fibBehind = fibBehind,fibAhead+fibBehind

	fRes = fibAhead + fibBehind
	print(fRes)

fib2(6)
