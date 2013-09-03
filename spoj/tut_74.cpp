#include <iostream>
using namespace std;

int main()
{
	long i, j, T;
	long *a, *sum;
	cin>>T;
	a = new (nothrow) long[T];
	sum = new (nothrow) long[T];
	for (i=0;i<T;i++) {
		cin>>a[i];
		sum[i] = 0;
	}

	for (i=0; i <T; i++) {
		for (j=1; j<a[i]; j++){
			if (a[i]%j==0) {
				sum[i] += j;
			}
		}
	}

	for (i=0; i<T; i++) {
		cout<<sum[i]<<"\n";
	}

	return 0;
}