/*
ID: cjdyx202
PROG: transform
LANG: C++                  
*/
#include <iostream>
#include <fstream>
using namespace std;

#define Maxn 10
char st[Maxn][Maxn];
char ed[Maxn][Maxn];
 
int n,ans=7;
 
void Init()
{
	cin>>n;
	for(int i=0;i<n;i++)	cin >> st[i];
	for(int i=0;i<n;i++)	cin >> ed[i];
	return ;
}


void Comp(int x)
{
	bool flag=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(st[i][j]!=ed[i][j])	{
				flag=false;
				continue;
			}
		if(!flag){
			continue;
		}
	}
		 
	if(flag)	ans=min(ans,x);
}
 
void DegRot90()
{
	char tmp[Maxn][Maxn];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			tmp[j][n-i-1]=st[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			st[i][j]=tmp[i][j];
}
 
void Ref()
{
	char tmp[Maxn][Maxn];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			tmp[i][n-j-1]=st[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			st[i][j]=tmp[i][j];
}
 
void Solve()
{
	Comp(6);
	DegRot90();
	Comp(1);
	DegRot90();
	Comp(2);
	DegRot90();
	Comp(3);
	DegRot90();
	Ref();
	Comp(4);
	for(int i=1;i<=3;i++)
	{
		DegRot90();
		Comp(5);
	}
	cout << ans << endl;
}
 
int main()
{
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	Init();
	Solve();
	return 0;
}
