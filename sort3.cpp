/*
ID: cjdyx202
PROG: sort3
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <bitset>
const char prog[] = "sort3";
char in[100],out[100];
inline void pinit() {
	sprintf(in,"%s.in",prog);
	sprintf(out,"%s.out",prog);
	freopen(in, "r", stdin);
	freopen(out, "w", stdout);
}
using namespace std;
const int MAX = 1005;
int ar[MAX];//��ʼλ��
int br[MAX];//��ȷλ��
int n;//���Ƹ���
int c[4][4]={0};//c[i][j] : ĳ��λ��Ӧ����i��ȴ��j��������λ�õĸ���
int csum=0;//�ȴ����������ĸ���


/*
only two possible kind to wrong position
1. i <-> j
2. cycle 1,j,k
*/
int main() {
	pinit();
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		cin >> ar[i];
		br[i] = ar[i];
	}
	sort(br, br+n);
	for (int i = 0; i < n; ++ i) {
		if (ar[i] != br[i]) {
			++c[br[i]][ar[i]];
			++csum;
		}
	}
	int ans = 0;
	for (int i = 1; i <= 3; ++ i) {
		for (int j = i+1; j <= 3; ++ j) {
			//�����i->j������j->i���͸þ����ܵ��Ƚ����ǽ�����ÿ�Զ�������i��j�ķ�1�ν���
			int t = min(c[i][j], c[j][i]);
			ans += t;
			c[i][j] -= t;
			c[j][i] -= t;
			//�����������ĸ���������
			csum -= 2*t;
		}
	}
	//ʣ�´����������ĸ����϶���3�ı�������ֻ�����i->j j->k k->i����������ķ�2�ν���
	ans += csum/3*2;
	cout << ans << endl;
	return 0;
}
