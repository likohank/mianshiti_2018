import os,sys

def conflict(state,column):
	row = len(state)
	for i in range(0,row):
		if abs(state[i]-column) in (0,row-i):
			return True
	return False

def queue(number=8,state=()):
	for pos in range(0,number):
		if conflict(state,pos) == False:
			if len(state)==number-1:
				yield (pos,)
			else:
				results =  queue(number,state+(pos,))
				if results == None:
					continue
				for result in results:
					yield (pos,) + result

def queueSolution(number):
	aa= list(queue(number))
	print aa
	print len(aa)

queueSolution(8)
