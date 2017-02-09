/*
ID: cjdyx202
PROG: frac1
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
  short x,y;// x>=y
}num[12890];

short gcd(short x,short y){  //x >= y
  return y==0?x:gcd(y,x%y);
}

bool cmp(node a, node b){
	return (a.y * b.x < a.x * b.y);
}
int main(){
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);

/*
1. all all fractions to list, then sort them
2. could use merge sort since 1/n, 2/n,.. is already sorted
3. could use map, since all elements in map are sorted
4. �����������������Ĳ�һ��>=1/��160*159��������ֱ�Ӱ����з�������50880��
���������ֱ��Ͱ���򣬶���һ������һ���ţ�ֻ��Ҫͬʱ��¼���ӷ�ĸ������
������ʡ�ˣ�������ֵͬ����������Ϊ֮ǰ�ض���һ����ֵ��С�ķ����������ֵ��
*/	
	int n; 
	cin>>n;
	
	int top = 0;
	for(short i = 1; i <= n; i++){
		for(short j = 0; j <=i; j++){
			if(gcd(i,j) == 1){
				num[top].x = i;
				num[top].y = j;
				top++; 
			}
		}
	}
	
	sort(num, num+top, cmp);
	for(int i = 0; i < top; i++){
		cout<<num[i].y<<"/"<<num[i].x<<endl;
	}
	return 0;
}

