import requests
def compare_function(a, b):#this function takes 2 parameters, they are strings
	return (a if min(a) < min(b) else b)#they get compared and returned to the c-program
