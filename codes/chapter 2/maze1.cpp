/*
ID: cjdyx202
PROG: maze1
LANG: C++                  
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
 
typedef pair<int, int> pii;
const int MAXN = 500;

const int dx[4] = {-1, +0, +0, +1},
          dy[4] = {+0, -1, +1, +0};
          
int n, m;

int tmp[MAXN];
int g[MAXN][MAXN]; //record if there exists fence
int dis[MAXN][MAXN];
 
queue<pii> q; 

void bfs(int x1, int y1, int x2, int y2) {
    memset(dis, -1, sizeof(dis));
    
    dis[x1][y1] = dis[x2][y2] = 0;
    q.push(make_pair(x1, y1)); 
	q.push(make_pair(x2, y2));
	
    while (!q.empty()) {
        pii head = q.front(); q.pop();
        
        int ux = head.first, uy = head.second;
        for (int i = 0; i < 4; i++) {
            int vx = ux + dx[i], vy = uy + dy[i];
            if (vx < 0 || vx >= n || vy < 0 || vy >= m || g[vx][vy]) { //out of range
            	continue;
			}
			
            if (dis[vx][vy] == -1 || dis[vx][vy] > dis[ux][uy]) { //not visited or distance can be reduced
                q.push(make_pair(vx, vy));
                if (vx % 2 == 0 || vy % 2 == 0) dis[vx][vy] = dis[ux][uy]; 
                else dis[vx][vy] = dis[ux][uy] + 1;
            }
        }
    }
}
int main()
{
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
    
    scanf("%d%d", &m, &n); getchar();
    
    n = n * 2 + 1; m = m * 2 + 1;
    
    int x1 = -1, y1 = -1, x2, y2; //two exits 
    
    for (int i = 0; i < n; i++, getchar())
        for (int j = 0; j < m; j++) {
            char ch ; scanf("%c", &ch); 
            if (ch == ' ') g[i][j] = 0;
            else g[i][j] = 1;
            if (g[i][j] == 0 && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
                if (x1 == -1) {x1 = i; y1 = j;}
                else {x2 = i; y2 = j;}
        }
    bfs(x1, y1, x2, y2);
    int ans = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            ans = max(ans, dis[i][j]);
    printf("%d\n", ans);
    fclose(stdin); fclose(stdout);
    return 0;
}
