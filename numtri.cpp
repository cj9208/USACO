/*
ID: cjdyx202
PROG: numtri
LANG: C++                  
*/


#include<stdio.h>
#include<iostream>
#include<fstream>
//#define fin cin
//#define fout cout
using namespace std;

int n;
int a[1001][1001]={0},f[1001]={0};
int main() {
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	int i,j;
	fin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			fin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=i;j>=1;j--){
			f[j]=max(f[j]+a[i][j],f[j-1]+a[i][j]);
		}
	}
	int s=0;
	for(i=1;i<=n;i++){
		s=max(s,f[i]);
	}
	fout<<s<<endl;
	return 0;
}




