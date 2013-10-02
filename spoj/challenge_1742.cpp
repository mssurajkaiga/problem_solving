#include <iostream>
#include <string>
#define C case
#define B break;
#define y m[k]
using namespace std;int k=0,M=32768;string c,m(M,0),t;char l;void r(int s){for(int i=s;l=c[i];i++)switch(l){C'>':++k%=M;B C'<':--k<0?k=M-1:0;B C'+':++y>255?y=0:0;B C'-':--y<0?y=255:0;B C'.':cout<<y;B C'[':if(y>0)r(i--+1);else for(int o=1;o&&c[i++];)c[i]==91?o++:c[i]==93?o--:0;B C']':return;}}main(){int o=0,i;while(cin>>t){for(i=0;l=t[i];i++)l==91?o++:l==93?o--:l==37?t[i--]=0:0;c+=t;}if(o){cout<<"COMPILE ERROR";return 0;};r(0);}