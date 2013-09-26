#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void add(string a, string b)
{
	int size_a = a.size()-1;
	int size_b = b.size()-1;
	int s=0, c=0, size_f, d;
	int i = max(size_a+1, size_b+1);
	string f (i+1, '0');
	string bar;

	while(i>=0){

		if(size_a<0 && size_b>=0){
			s = b[size_b]- 48 + c;
		}
		else if (size_b<0 && size_a>=0){
			s = a[size_a] - 48 + c;
		}
		else if (size_a<0 && size_b<0){
			s = c;
		}

		else {
			s = a[size_a] + b[size_b] -96 + c;
		}

		if (s>9) {
			c=1;
			f[i] = s + 38;
		}
		else {
			c=0;
			f[i] = s + 48;
		}
		i--;
		size_b--;
		size_a--;
	}
	if (f[0]=='0') f.erase(0,1);
	size_f = f.size();

	size_a = a.size();
	size_b = b.size();

	if (size_f>size_a && size_f>size_b+1) {
		cout<<a.insert(0, size_f-size_a, ' ')<<"\n";
		b.insert(0,1,'+');
		cout<<b.insert(0, size_f-size_b-1, ' ')<<"\n";
		cout<<bar.insert(0,size_f, '-')<<"\n";
		cout<<f<<"\n";
	}

	else if (size_a>=size_f && size_a>size_b+1){
		cout<<a<<"\n";
		b.insert(0,1,'+');
		cout<<b.insert(0, size_a-size_b-1, ' ')<<"\n";
		cout<<bar.insert(0,size_a, '-')<<"\n";
		cout<<f.insert(0, size_a-size_f, ' ')<<"\n";
	}

	else {
		cout<<a.insert(0, size_b-size_a+1, ' ')<<"\n";
		cout<<'+'<<b<<"\n";
		cout<<bar.insert(0,size_b+1, '-')<<"\n";
		cout<<f.insert(0, size_b+1-size_f, ' ')<<"\n";	
	}

}

string add_ret(string a, string b)
{
	int size_a = a.size()-1;
	int size_b = b.size()-1;
	int s=0, c=0;
	int i = max(size_a+1, size_b+1);
	string f (i+1, '0');
	while(i>=0){

		if(size_a<0 && size_b>=0){
			s = b[size_b]- 48 + c;
		}
		else if (size_b<0 && size_a>=0){
			s = a[size_a] - 48 + c;
		}
		else if (size_a<0 && size_b<0){
			s = c;
		}

		else {
			s = a[size_a] + b[size_b] -96 + c;
		}

		if (s>9) {
			c=1;
			f[i] = s + 38;
		}
		else {
			c=0;
			f[i] = s + 48;
		}
		i--;
		size_b--;
		size_a--;
	}
	return f;
}


void subtract(string a, string b)
{
	int size_a = a.size()-1;
	int size_b = b.size()-1;
	int s=0, c=0, size_f;
	int i = max(size_a, size_b);

	string f (i+1, '0');
	string bar;

	while(i>=0){

		if(size_a>=0 && size_b<0){
			s = a[size_a] - 48 - c;
		}

		else {
			s = a[size_a] - b[size_b] - c;
		}

		if (s<0) {
			c=1;
			f[i] = s + 58;
		}
		else {
			c=0;
			f[i] = s + 48;
		}
		i--;
		size_b--;
		size_a--;
	}
	
	size_f = f.size();
	for (i=0;f[i]=='0' && i<size_f-1;i++) ;;
	f.erase(0,i);
	size_f -= i;

	size_a = a.size();
	size_b = b.size();

	if (size_f>size_a && size_f>size_b+1) {
		cout<<a.insert(0, size_f-size_a, ' ')<<"\n";
		b.insert(0,1,'-');
		cout<<b.insert(0, size_f-size_b-1, ' ')<<"\n";
		cout<<bar.insert(0,size_f, '-')<<"\n";
		cout<<f<<"\n";
	}

	else if (size_a>=size_f && size_a>size_b+1){
		cout<<a<<"\n";
		b.insert(0,1,'-');
		cout<<b.insert(0, size_a-size_b-1, ' ')<<"\n";
		if (size_b+1>size_f) {
			string bar (size_b+1, '-');
			cout<<bar.insert(0, size_a-size_b-1, ' ')<<"\n";
		}
		else {
			string bar (size_f, '-');
			cout<<bar.insert(0, size_a-size_f, ' ')<<"\n";
		}
		cout<<f.insert(0, size_a-size_f, ' ')<<"\n";
	}

	else {
		cout<<a.insert(0, size_b-size_a+1, ' ')<<"\n";
		cout<<'-'<<b<<"\n";
		string bar (size_b+1, '-');
		cout<<bar<<"\n";
		cout<<f.insert(0, size_b+1-size_f, ' ')<<"\n";	
	}

}

void multiply(string a, string b)
{

	int size_a = a.size()-1;
	int size_b = b.size()-1;
	int s=0, c=0, size_f, size_0;
	int i = max(size_a+1, size_b+1);
	int p=0, j=0, k=0;
	string* fs;
	fs = new (nothrow) string[size_b+1];
	string f(i, '0');
	string bar;
	i = size_b;
	while(i>=0){
		j = size_a;
		string temp(j+2, '0');
		c=0;
		while(j>=0 || c>0){
			if (j<0) {
				temp[j+1] = c + 48;
				break;
			}
			p = (int)(a[j]-48) * (int)(b[i]-48) + c;
			temp[j+1] = p%10 + 48;
			if (p>9) c = p/10;
			else c=0;
			j--;
		}
		i--;
		fs[k] = temp;
		temp.append(k,'0');
		f = add_ret(f,temp);
		k++;
	}

	size_f = f.size();
	for (i=0;f[i]=='0' && i<size_f-1;i++) ;;
	f.erase(0,i);
	size_f -=i;

	if (size_b+2 >= size_f) {
		cout<<a.insert(0, size_b+1-size_a, ' ')<<"\n";
		cout<<'*'<<b<<"\n";
		cout<<bar.insert(0, size_b+2, '-')<<"\n";
		for (i=0; i<k; i++) {
			for (j=0;fs[i][j]=='0' && j<fs[i].size()-1;j++) ;;
			fs[i].erase(0,j);
			cout<<fs[i].insert(0, size_b+2-fs[i].size()-i, ' ')<<"\n";
		}
		if (k>1) {
			string bar(size_f, '-');
			cout<<bar.insert(0, size_b+2-size_f, ' ')<<"\n";
			cout<<f.insert(0, size_b+2-size_f, ' ')<<"\n";
		}
	}

	else {
		cout<<a.insert(0, size_f-size_a-1, ' ')<<"\n";
		b.insert(0,1,'*');
		cout<<b.insert(0, size_f-size_b-2, ' ')<<"\n";
		size_0 = fs[0].size();
		for (j=0;fs[0][j]=='0' && j<size_0-1;j++) ;;
		fs[0].erase(0,j);
		size_0 -= j;
		if (k>1) {
			if (size_0 >= size_b+2) {
				bar.insert(0, size_0, '-');
				cout<<bar.insert(0, size_f-size_0, ' ')<<"\n";
			}
			else {
				bar.insert(0, size_b+2, '-');
				cout<<bar.insert(0, size_f-size_b-2, ' ')<<"\n";
			}
			cout<<fs[0].insert(0, size_f-size_0, ' ')<<"\n";
			for (i=1; i<k; i++) {
				for (j=0;fs[i][j]=='0' && j<fs[i].size()-1;j++) ;;
				fs[i].erase(0,j);
				cout<<fs[i].insert(0, size_f-fs[i].size()-i, ' ')<<"\n";
			}
		}
			cout<<string(size_f, '-')<<"\n";
			cout<<f<<"\n";
	}
	
}

int main()
{
	int T, pos;
	cin>>T;
	for (int i=0; i<T; i++) {
		string a,b;
		cin>>a;
		pos = a.find('+');

		if (pos != string::npos) {
			b = a.substr(pos+1);
			a = a.substr(0,pos);
			add(a,b);
		}

		else {
			pos = a.find('-');
			if (pos != string::npos) {
				b = a.substr(pos+1);
				a = a.substr(0,pos);
				subtract(a,b);
			}

			else {
				pos = a.find('*');
				b = a.substr(pos+1);
				a = a.substr(0,pos);
				multiply(a,b);
			}
		}
		
		cout<<"\n";
	}
return 0;
}