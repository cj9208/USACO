/*
ID: cjdyx202
PROG: concom
LANG: C++                  
*/

#include <algorithm>
#include <cstdio>
using namespace std;
 
bool flag[101]; //during DFS, record if visited
bool own[101];

int a[101][101] = {0}; //the stock of j owned by i
int cnt[101];  //the stock of j owned by current company
int m;   //the number of company involved
 
void DFS(int x){
	if (flag[x]) {
		return;
	}
	
	flag[x] = true;
	
	for (int i = m; i; --i)	{
		cnt[i] += a[x][i];
		if (cnt[i] > 50){ 
			own[i] = true;
			DFS(i);
		}
	}
}
 
int main()
{
	int n, u, v, w;
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
	
	for (scanf("%d", &n); n; --n){
		scanf("%d%d%d", &u, &v, &w);
		a[u][v] += w;
		if (u > m) m = u;
		if (v > m) m = v;  
	}
	
	for (int i = 1; i <= m; ++i){
		fill_n(cnt+1, m, 0);
		fill_n(flag+1, m, false);
		fill_n(own+1, m, false);
		
		DFS(i);
		for (int j = 1; j <= m; ++j)
			if (own[j] && i != j)
				printf("%d %d\n", i, j);
	}
}

