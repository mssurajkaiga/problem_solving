#include <iostream>
using namespace std;

int rev(int num) {
	int d, rev=0;
	while (num!=0){
		d = num%10;
		rev = rev*10 +d;
		num /=10;
	}
	return rev;
}

int main()
{
	int n, a, b;
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a>>b;
		cout<<rev(rev(a)+rev(b))<<'\n';
	}

	return 0;
}