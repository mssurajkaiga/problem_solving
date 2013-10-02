#include <iostream>
using namespace std;
int main()
{
	int n[1000000],i,j,s;
	for (i=0;i<1000000;i++) n[i]=1;
	for (i=0;i<1000000;i++){
		j=i;
		s=0;
		while(j!=0) {
			s+=j%10;
			j/=10;
		}
		if(i+s<1000000) n[i+s]=0;
	}
	for (i=0;i<1000000;i++) if(n[i]) cout<<i<<'\n';
}