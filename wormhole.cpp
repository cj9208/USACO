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
int n;	//n���涴
int ans=0;	//���
int b[13]= {0};	//��¼������

struct A {	//��¼�������
	int x;
	int y;
} a[13];

int my(const A &i,const A &j) {	//����ĺ���
	return (i.y < j.y) || (i.y == j.y && i.x < j.x);
}


int doit(int num,int x, int begin,int into) {//ģ��ţ�߶������,into��ʾ����õ�ķ�ʽ��0��ʾ�ڸõ��߳��涴��1��ʾ�ߵ��õ�
	if(num!=1&&x==begin&&into==0) {	//�������ʼ���߳�����˵��ѭ����
		return 1;
	}
	if(into==0) {	//���ڸõ��߳��涴������ǰ��
		if(a[x].y==a[x+1].y) {	//���ǰ���г涴�����߽�ȥ
			return doit(num+1,x+1,begin,1);
		} 
		else {	//���ǰ��û�г涴����˵��ѭ������
			return 0;
		}
	}
	if(into==1) {	//�����ߵ��õ㣬���߽�ȥ
		return doit(num+1,b[x],begin,0);
	}
}
int judge() {	//�ж�
	int i,j;
	for(i=1; i<=n; i++) {	//�ӵ�i���㿪ʼ��
		if(doit(1,i,i,0)==1) {
			return 1;
		}
	}
	return 0;
}

void mpair(int x) {	//���
	int i,j;
	if(x==n+1) {	//���Ѿ�������
		if(judge()==1) {	//decide wheter it is a valid pair
			ans++;
		}
		return ;
	}
	if(b[x]==0) {	//�����ǰ�涴��Ϊ��ԣ���Ϊ�����
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
	else {	//�����ǰ�涴�ѱ���ԣ��ͼ�������һ���涴
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
	sort(a+1,a+n+1,my);	//���򣬷������ͬһ�еĳ涴
	mpair(1);	//�ӵ�һ���涴��ʼ���
	cout<<ans<<endl;
	return 0;
}

/*
1. recursive way to find all possible pairs
2. brute force to find whether their is a cycle 
*/




