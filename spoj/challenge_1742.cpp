#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

string code(""), mem(0, 32768);
int k=0, M=32768;
char l;
void e() {cout<<"COMPILE ERROR"; exit(0);}

void run(int start){
	for(int i=start; l=code[i]; i++) 
			switch(code[i]) {
				case '>':
					++k%=M;
					break;

				case '<':
					if(--k<0) k=M-1;
					break;

				case '+':
					if (++mem[k]>255) mem[k]=0;
					break;

				case '-':
					if (--mem[k]<0) mem[k]=255;
					break;

				case '.':
					cout<<mem[k];
					break;

				case '[':
					if (mem[k]>0) {run(i--+1);}
					else {
						for(int o=1;o&&code[i++];) {
							if(code[i]=='[') o++;
							if (code[i]==']') o--;
						}
					}
					break;
				case ']': return;
				}
			
}

int main() {
	string temp;
	int open_loop = 0,i=0;
	while(getline(cin, temp)) {
		for (i=0; l=temp[i]; i++) {
			l=='[' ? open_loop++ : l==']' ? open_loop-- : l=='%' ?  temp[i--]=0 : 0;
		}
		code.append(temp,0,	i);
	}
	if (open_loop) {
		e();
	}

	run(0);
	return 0;
}