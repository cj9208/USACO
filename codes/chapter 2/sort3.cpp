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
int ar[MAX];//初始位置
int br[MAX];//正确位置
int n;//奖牌个数
int c[4][4]={0};//c[i][j] : 某个位置应该是i但却是j，这样的位置的个数
int csum=0;//等待交换的数的个数


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
			//如果有i->j，又有j->i，就该尽可能的先将它们交换，每对儿这样的i与j耗费1次交换
			int t = min(c[i][j], c[j][i]);
			ans += t;
			c[i][j] -= t;
			c[j][i] -= t;
			//待交换的数的个数减少了
			csum -= 2*t;
		}
	}
	//剩下待交换的数的个数肯定是3的倍数，即只会出现i->j j->k k->i，这种情况耗费2次交换
	ans += csum/3*2;
	cout << ans << endl;
	return 0;
}
