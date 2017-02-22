/*
ID: cjdyx202
PROG: nocows
LANG: C++                  
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
 
using namespace std;

int a[201][101] = {0};  

int main(){
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
	int N,K;
	cin >> N >> K;
	
/*
set a[i][j] denote the number of trees with i nodes and depth less than j
a[i][j] = sum( a[k][j-1] * a[i-1-k][j-1] ) (k in {1..i-2})
*/
	for(int i = 0; i <= K; i++){
		a[1][i] = 1;
	}
	
	for(int j = 2; j <=K; j++){
		for(int i = 3; i <= N; i+=2) { //only when the number of nodes is odd
			for(int k = 1; k <= i-2; k++){
				a[i][j] += a[k][j-1] * a[i-1-k][j-1];
			}
			a[i][j] %= 9901;
		}
	}
	
	cout<<(a[N][K] - a[N][K-1] + 9901) % 9901<<endl;
}
