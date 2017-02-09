/*
ID: cjdyx202
PROG: holstein
LANG: C++                  
*/

/*
1.枚举每种可能
2.DFS
3.BFS 
	the first ansver found by BFS is optimal
	
use bit operation:
const bin:array[1..15]of integer=
(1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767);
*/

#include <iostream>
#include <fstream>
 
using namespace std;
 
int n,v[26],m,g[16][26];
int now[26]; 
int res[16],dat[16];//res: find comniniation, dat: current combination
int minn=2147483647;//record the minimum types of combination
 
void dfs(int deep,int count)
{
    if (deep==m+1){
        for (int i=1;i<=n;i++)
            if (now[i]<v[i]) 
				return ;
				
        if (count<minn){
            minn=count;
            for (int i=1;i<=minn;i++)
                res[i]=dat[i];
        }
        return ;
    }
     
    for (int i=1;i<=n;i++)
        now[i]+=g[deep][i];        
    dat[count+1]=deep;
    dfs(deep+1,count+1);
    
    for (int i=1;i<=n;i++)
        now[i]-=g[deep][i];
    dfs(deep+1,count);
}
 
int main()
{
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");
 
    fin>>n;
    for (int i=1;i<=n;i++)
        fin>>v[i];
    fin>>m;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
            fin>>g[i][j];
    }
    
    for (int i=1;i<=n;i++)
        now[i]=0;
        
    dfs(1,0);
    
    fout<<minn;
    for (int i=1;i<=minn;i++)
        fout<<" "<<res[i];
    fout<<endl;
    return 0;
}
