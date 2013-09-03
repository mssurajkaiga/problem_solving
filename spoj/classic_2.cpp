#include <iostream>
using namespace std;

int checkPrime(long a) {
	if (a==1) return 0;
	for (long i=2; i<a; i++) {
		if (a%i==0) {
			return 0;
		}
	}
	return 1;
}

int main() 
{
	int t, i, j;
	long *m, *n;
	cin>>t;

	m = new (nothrow) long[t];
	n = new (nothrow) long[t];

	for (i=0; i<t; i++) cin>>m[i]>>n[i];
	for (i=0; i<t; i++) {
		for (j=m[i]; j<=n[i]; j++) {
			if (checkPrime(j)) {
				cout<<j<<"\n";
			}
		}
		cout<<"\n";
	}
}