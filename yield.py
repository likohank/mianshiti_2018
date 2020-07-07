import os,sys

def flatten(nested):
	try:
		try: nested+''
		except TypeError: pass
		else: raise TypeError

		for sublist in nested:
			for element in flatten(sublist):
				yield element
	except TypeError:
		yield nested

aa = [[4,5],[1,2],[3]]
r = flatten(aa)
print r.next()
print r.next()
print r.next()

print list(r)
