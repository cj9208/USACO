/*
ID: cjdyx202
PROG: frac1
LANG: C++                  
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n;

/*
���ǿ��԰�0/1��1/1��Ϊ���˵㡱��
ͨ�������������ķ�����ӡ���ĸ��ӵõ����·�����Ϊ�е����ݹ飨��ͼ��
0/1                                                              1/1
                              1/2
                 1/3                      2/3
       1/4              2/5         3/5                 3/4
   1/5      2/7     3/8    3/7   4/7   5/8       5/7         4/5
   
�μ�����������ѧ�� 
*/
void sch(int a1,int a2,int b1,int b2)
{
     if (a1+b1>n || a2+b2>n) return;
     else {
        int m1=a1+b1,m2=a2+b2;
        sch(a1,a2,m1,m2);              //������Ϊ��˳�����
         cout<<a1+b1<<"/"<<a2+b2<<endl; //..
        sch(m1,m2,b1,b2);              //..
     }
}
int main(void)
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    cin>>n;
    cout<<0<<"/"<<1<<endl;
    sch(0,1,1,1);
    cout<<1<<"/"<<1<<endl;
}
