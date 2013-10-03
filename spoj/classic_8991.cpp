#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string url,seed,guess;
	int t,i,j,a,b;
	char target[6];
	while(cin>>url){
		seed = url.substr(37,6);
		guess = url.substr(43,6);
		i=0;
		t=0;
		a=0;
		b=0;
		while(i<3){
			swap(seed[i], seed[(i+3)%6]);
			i++;
		}
		i=0;
		while(i<6){
			t=t*10+seed[i]-48;
			i++;
		}
		t = (991036+t)%1000000;
		for(i=0;i<6;i++) {
			target[5-i]=t%10+48;
			t/=10;
			if(target[5-i]==guess[5-i]) a++;
		}

		for(i=0;i<6;i++) {
			for(j=0;j<6;j++){
				if(j!=i && target[i]==guess[j]) b++;
			}
		}
		cout<<a<<"A"<<b<<"B\n";
	}
	return 0;
}