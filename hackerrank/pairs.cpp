#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	long N, K, *arr;
	int i, j, count = 0;
	arr = new (nothrow) long[N];
	int elements = sizeof(arr) / sizeof(arr[0]);

	if (arr==0) {
		cout<<"No memory allocated";
	}

	cin>>N>>K;

	for (i=0; i<N; i++) {
		cin>>arr[i];
		i++;
	}

	sort(arr, arr + elements);

	for (i=0; i<N; i++) {
		
	}

	return 0;
}