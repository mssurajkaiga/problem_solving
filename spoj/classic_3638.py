t = int(input())
for i in range(0,t):
	s = input()
	words = s.split()
	p = cur = P = 0
	for word in words:
		if (len(word)!=p):
			if(cur>P):
				P=cur
			cur = 1
			p = len(word)
		elif (len(word)==p):
			cur+=1
	if(cur>P):
		P = cur
	print(P)