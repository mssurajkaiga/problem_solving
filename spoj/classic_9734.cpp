#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, k, count=0;
	int *a;
	cin>>n>>k;
	a = new (nothrow) int[n];
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	vector<int> av(a, a+n);	
	sort(av.begin(), av.end());

	for (int i=0; i<n-1; i++) {
		if (binary_search(av.begin()+i, av.end(), av[i]+k))
			count++;
	}

	cout<<count;
	return 0;
}