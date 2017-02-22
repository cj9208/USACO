/*
ID: cjdyx202
PROG: fracdec
LANG: C++                  
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<fstream>
 
using namespace std;
 
int y[100002],c[100002];
bool hash[100001];
int hashi[100001];
 
int main()
{
	ifstream fin("fracdec.in");
	ofstream fout("fracdec.out");
	int n,m;
	fin>>n>>m;
	fout<<n/m; //integral part
	
	int o=n/m==0?2:log10(n/m)+2; //control output
	n%=m;
	if(n==0){ //no decimal part
		fout<<".0"<<endl;
		return 0;
	}
	
	fout<<'.';
	
	int kb=-1;
	int i;
	
	c[1]=0;
	y[1]=n;
	hash[n]=true;
	hashi[n]=1;  
	
	n*=10;
	for(i=2;kb==-1;i++){
		c[i]=n/m;
		y[i]=n%m;
		n=y[i]*10;
		if(hash[y[i]]){
			kb=hashi[y[i]];
			break;
		}
		else{
			hash[y[i]]=true;
			hashi[y[i]]=i;
		}
		if(n==0)break;
	}
	
	if(kb>0)kb++;
	
	for(int k=2;k<=i;k++){
		o++;
		if(k==kb)fout<<"(",o++;
		fout<<c[k];
		if(o%76==0)fout<<endl;
	}
	if(kb!=-1)fout<<')';
	fout<<endl;
	return 0;
}
