#include <iostream>
#include <math.h>
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
		if (a[i]%2!=0) {
			for (j=3; j<=sqrt(a[i]); j+=2){
				if (a[i]%j==0) {
					sum[i] += j;
					sum[i] += (a[i]/j);
				}
			}
		}
		else {
			for (j=2; j<=sqrt(a[i]); j++){
				if (a[i]%j==0) {
					sum[i] += j;
					sum[i] += (a[i]/j);
				}
			}
		}
		sum[i] +=1;
		if (sqrt(a[i]) == floor(sqrt(a[i]))) {
			sum[i] -= sqrt(a[i]);
		}
	}

	for (i=0; i<T; i++) {
		cout<<sum[i]<<"\n";
	}

	return 0;
}