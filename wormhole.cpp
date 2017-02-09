/*
ID: cjdyx202
PROG: wormhole
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;
int n;	//n个虫洞
int ans=0;	//结果
int b[13]= {0};	//记录配对情况

struct A {	//记录点的坐标
	int x;
	int y;
} a[13];

int my(const A &i,const A &j) {	//排序的函数
	return (i.y < j.y) || (i.y == j.y && i.x < j.x);
}


int doit(int num,int x, int begin,int into) {//模拟牛走动的情况,into表示到达该店的方式，0表示在该点走出虫洞，1表示走到该点
	if(num!=1&&x==begin&&into==0) {	//如果从起始点走出来，说明循环了
		return 1;
	}
	if(into==0) {	//若在该点走出虫洞，就向前走
		if(a[x].y==a[x+1].y) {	//如果前面有虫洞，就走进去
			return doit(num+1,x+1,begin,1);
		} 
		else {	//如果前面没有虫洞，就说明循环结束
			return 0;
		}
	}
	if(into==1) {	//若是走到该点，就走进去
		return doit(num+1,b[x],begin,0);
	}
}
int judge() {	//判断
	int i,j;
	for(i=1; i<=n; i++) {	//从第i个点开始走
		if(doit(1,i,i,0)==1) {
			return 1;
		}
	}
	return 0;
}

void mpair(int x) {	//配对
	int i,j;
	if(x==n+1) {	//若已经配对完成
		if(judge()==1) {	//decide wheter it is a valid pair
			ans++;
		}
		return ;
	}
	if(b[x]==0) {	//如果当前虫洞暂为配对，就为其配对
		for(i=x+1; i<=n; i++) {
			if(b[i]==0) {
				b[x]=i;
				b[i]=x;
				mpair(x+1);
				b[x]=0;
				b[i]=0;
			}
		}
	} 
	else {	//如果当前虫洞已被配对，就继续找下一个虫洞
		mpair(x+1);
	}
	return ;
}

int main() {
	freopen("wormhole.in","r",stdin);
	freopen("wormhole.out","w",stdout);
	int i,j,k;
	cin>>n;
	for(i=1; i<=n; i++) {  //index starts from 1 
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+n+1,my);	//排序，方便查找同一行的虫洞
	mpair(1);	//从第一个虫洞开始配对
	cout<<ans<<endl;
	return 0;
}

/*
1. recursive way to find all possible pairs
2. brute force to find whether their is a cycle 
*/




