#include <iostream>
#include <string>
#include <stdlib.h>
#define C case
#define B break;
using namespace std;int k=0,M=32768;string c(""),m(0,M),t;char l;int e(){cout<<"COMPILE ERROR";exit(0);}void r(int s){for(int i=s;l=c[i];i++)switch(c[i]){C'>':++k%=M;B C'<':--k<0?k=M-1:0;B C'+':++m[k]>255?m[k]=0:0;B C'-':--m[k]<0?m[k]=255:0;B C'.':cout<<m[k];B C'[':if(m[k]>0)r(i--+1);else for(int o=1;o&&c[i++];)c[i]==91?o++:c[i]==93?o--:0;B C']':return;}}int main(){int o=0,i=0;while(getline(cin,t)){for(i=0;l=t[i];i++)l==91?o++:l==93?o--:l==37?t[i--]=0:0;c.append(t,0,i);}if(o)e();r(0);}