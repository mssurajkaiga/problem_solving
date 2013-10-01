#include <iostream>
#include <string>
#include <stdlib.h>
#define z break;
#define r case
using namespace std;string c(""),l(0,32768);int k=0;int e(){cout<<"COMPILE ERROR";exit(0);}int f(int s,int v){int j;for(int i=s;i<v;i++)switch(c[i]){r'>':++k%=32768;z r'<':if(--k<0)k=32767;z r'+':if(++l[k]>255)l[k]=0;z r'-':if(--l[k]<0)l[k]=255;z r'.':cout<<l[k];z r'[':for(j=i+1;c[j]!=']';j++);if(l[k]>0)f(i--+1,j);else i=j;z r']':e();}}int main(){string b;int o=0,x=0,i;while(cin){b="";getline(cin,b);for(i=0;i<b.size();i++){if(b[i]=='%')b.resize(i);else b[i]=='['?o++:b[i]==']'?x++:0;}c.append(b);}if(o!=x)e();f(0,c.size());}