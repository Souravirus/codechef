q=int(raw_input())
while q:
	n,k=map(int,raw_input().split( ))
	np=k
	z=0
	x=0
	for i in range(n):
		if np%2!=0:
			np//=2;
			x+=(2**(n-i))//2;
			z=x+np;
		else:
			z=x+np//2
			np//=2
	print z 
	q-=1
