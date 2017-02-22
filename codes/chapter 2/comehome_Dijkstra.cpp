/*
ID: cjdyx202
PROG: comehome
LANG: C++                  
*/

#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;
 
bool flag[52] = {};
int a[52][52], dist[52];
 
int main()
{
	int p;
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	for (int i = 0; i < 52; ++i)
		fill_n(a[i], 52, INT_MAX/2);
	for (scanf("%d", &p); p; --p)
	{
		char u, v;
		int w;
		scanf("%*c%c %c%d", &u, &v, &w);
		u = islower(u) ? u-'a' : u-'A'+26;
		v = islower(v) ? v-'a' : v-'A'+26;
		if (w < a[u][v])
			a[u][v] = w, a[v][u] = w;
	}
	copy(a[51], a[51]+52, dist);
	for(;;)
	{
		int min_dist = INT_MAX, u;
		for (int i = 0; i < 51; ++i)
			if (!flag[i] && dist[i] < min_dist)
				min_dist = dist[i], u = i;
		if (u >= 26) return printf("%c %d\n", u-26+'A', min_dist), 0;
		flag[u] = true;
		for (int i = 0; i < 51; ++i)
			if (!flag[i] && dist[u]+a[u][i] < dist[i])
				dist[i] = dist[u]+a[u][i];
	}
}
