/*
ID: cjdyx202
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int n;
int c;
bool l[1005];
int dest[1005];
vector<vector<bool> > v;
 
void read()
{
	memset(dest,-1,sizeof(dest));
	fill_n(l,1000,true);
	cin>>n>>c;
	int temp;
	while(cin>>temp)
	{
		if(temp==-1) break;
		dest[temp]=1;
	}
	while(cin>>temp)
	{
		if(temp==-1) break;
		dest[temp]=0;
	}
}
 
void oper_1()
{
	for(int i=1;i<=n;i++)
	{
		l[i]=!l[i];
	}
}
 
void oper_2()
{
	for(int i=1;i<=n;i+=2)
	{
		l[i]=!l[i];
	}
}
 
void oper_3()
{
	for(int i=2;i<=n;i+=2)
	{
		l[i]=!l[i];
	}
}
 
void oper_4()
{
	for(int i=1;i<=n;i+=3)
	{
		l[i]=!l[i];
	}
}
 
void oper(int n)
{
	switch(n)
	{
		case 1:
			oper_1();
			break;
 
		case 2:
			oper_2();
			break;
 
		case 3:
			oper_3();
			break;
 
		case 4:
			oper_4();
			break;
 
//		default:
//			cout<<"Error: n = "<<n<<endl;
//			getchar();
	}
}
 
bool equal()
{
	for(int i=1;i<=n;i++)
	{
		if(l[i]!=dest[i] && dest[i]!=-1)
		{
			return false;
		}
	}
	return true;
}
 
bool match_condition(int step)
{
	if(((c-step)&1)==0) return true;
	for(int i=1;i<=4;i++)
	{
		oper(i);
		if(equal())
		{
			oper(i);
			return true;
		}
		oper(i);
	}
	return false;
}
 
void print_light()
{
	for(int i=1;i<=n;i++)
	{
		cout<<l[i];
	}
	cout<<endl;
}
 
vector<bool> con_bv()
{
	vector<bool> temp;
	for(int i=1;i<=n;i++)
	{
		temp.push_back(l[i]);
	}
	return temp; 
}
 
void record_ans()
{
	v.push_back(con_bv());
}
 
bool is_existend(vector<bool> now)
{
	for(int i=0,t=v.size();i<t;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(now[j]!=v[i][j])
			{
				goto __exit;
			}
		}
		return true;
		__exit:;
	}
	return false;
}
 
void process_ans(int step)
{
//	cout<<"match = "<<match_condition(step)<<endl;
//	cout<<endl;
	if(match_condition(step))
	{
		if(!is_existend(con_bv()))
		{
//			print_light();
			record_ans();
		}
	}
}
 
void dfs(int col,int step)
{
//	cout<<"dfs: col = "<<col<<" step = "<<step<<endl;
//	print_light();
	if(equal()) 
	{
		process_ans(step);
//		cout<<"equal"<<endl;
	}
	if(col>4 || step>=c) return;
	dfs(col+1,step);
	oper(col);
	dfs(col+1,step+1);
	oper(col);
}
 
void put_out()
{
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<v[i][j];
		}
		cout<<endl;
	}
}
 
 
bool cmp(vector<bool> a,vector<bool> b)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			return a[i]<b[i];
		}
	}
	return true;
}
/*
simple complete search
just remember that turn a button twice is equal to no opeation 
*/ 
int main()
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);

	read();
	dfs(1,0);
	sort(v.begin(),v.end(),cmp);
	if(v.size()==0)	{
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	put_out();
}
