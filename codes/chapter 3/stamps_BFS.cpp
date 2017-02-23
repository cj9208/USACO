
/*
ID: cjdyx202
PROG: stamps
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

ifstream fin("stamps.in");
ofstream fout("stamps.out");
 
const int maxn=2100001;  // K <= 200, value <= 10,000
int k,n;
int f[maxn];
int a[100];

void init(){
  	fin >> k >> n;
  	for (int i=1;i<=n;i++)
    	fin >> a[i];
  	f[0]=0;
}

void solve(){ //BFS
  	for (int w=0; ;w++){
    	if ((f[w] || w==0) && f[w]<=k){
      		for (int i=1;i<=n;i++){
      			if (f[w+a[i]]){
      				f[w+a[i]]=min(f[w+a[i]],f[w]+1);
				}	
	  			else{
	  				f[w+a[i]]=f[w]+1;
				}	
	  		}	  
    	}
    	else{
      		fout << w-1 << endl;
      		return;
    	}
  	}
}
int main(){
  init();
  solve();
}


