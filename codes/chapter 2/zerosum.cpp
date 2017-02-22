/*
ID: cjdyx202
PROG: zerosum
LANG: C++                  
*/
#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
 
using namespace std;
 
int n;
 
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
 
int sgn(int k)
{
	if(k>0)return 1;
	if(k<0)return -1;
	return 0;
}
 
void dfs(int sum,int last,int k,string ss)
{
	if(k==n+1){
		if(sum==0)fout<<ss<<endl;
		return;
	}
	dfs(sum+(last*9+sgn(last)*k),last*10+sgn(last)*k,k+1,ss+" "+(char)(k+48));
	dfs(sum+k,k,k+1,ss+"+"+(char)(k+48));
	dfs(sum-k,-k,k+1,ss+"-"+(char)(k+48));
}
 
int main()
{
	fin>>n;
	dfs(1,1,2,"1");
	return 0;
}

