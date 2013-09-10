#include <iostream>
#include <math.h>
using namespace std;

long long getZeros(long long num)
{
	if (num==0) {
		return 0;
	}

	if (num%5!=0) {
		return getZeros(num-(num%5));
	}

	long long a=num;
	long long s = 0LL;
	long long b = 0LL;

	while (a!=0 && a%5==0) {
		a = a/5;
		s++;
	}

	b = pow(5,s);
	return (b-1)/4 + getZeros(num-b);
}

int main()
{
	long T=0L;
	long long a=0LL, z=0LL;
	cin>>T;

	for (long i=0; i<T; i++) {
		cin>>a;
		cout<<getZeros(a)<<"\n";
	}

	return 0;
}

/* Use sorted stored values of prev inputs factorial and compute current no.s factorial using that data */