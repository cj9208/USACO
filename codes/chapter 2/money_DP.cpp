/*
ID: cjdyx202
PROG: money
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <algorithm> 

#include <string>
using namespace std;

#define V 26 
#define N 10001
 
int main(){
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    
	int v,n;
	cin>>v>>n;
	
	int m;
	long long num[N] = {0};
	num[0] = 1;
	
	for(int i = 0; i < v; i++){
		cin>>m;
		for(int j = m; j<=n; j++){
			num[j] += num[j-m];
		}
	} 
	
	cout<<num[n]<<endl;
		 
    return 0;
}

