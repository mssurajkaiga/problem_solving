#include <iostream>
#include <string>
#include <stdlib.h>
#define c case
#define v int
#define b break;
using namespace std;string x(""),m(0,32768);v k=0;v e(){cout<<"COMPILE ERROR";exit(0);}v r(v s,v a){v j;for(v i=s;i<a;i++)switch(x[i]){c'>':++k%=32768;b c'<':if(--k<0)k=32767;b c'+':if(++m[k]>255)m[k]=0;b c'-':if(--m[k]<0)m[k]=255;b c'.':cout<<m[k];b c'[':for(j=i+1;x[j]!=']';j++);if(m[k]>0)r(i--+1,j);else i=j;b c']':e();}}v main(){string t;v o=0,i=0;while(getline(cin,t)){for(i=0;char l=t[i];i++)l==91?o++:l==93?o--:l==37?t[i--]=0:0;x.append(t,0,i);}if(o)e();r(0,x.size());}