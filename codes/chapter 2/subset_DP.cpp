/*
ID: cjdyx202
PROG: subset
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define N 40

int main(){
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    
	int n;
	cin>>n;
	
	int sum = (n+1)*n/2;
	
	if(sum % 2 != 0){
		cout<<0<<endl;
		return 0;
	}
	
	unsigned long dp[N*N] = {0};  //use long, since for n = 39, it will exceed the range of int
	sum /=2 ;
	dp[0]=1;
    for (int i=1;i<=n;i++){
        for(int j=sum;j>=i;j--)
            dp[j]=dp[j]+dp[j-i];
    }
    cout<<dp[sum]/2<<endl; //for a possible patition, we count twice
     
    return 0;
}
/*
1. dynamic programming : f[i][j] represents the number of subset of previous i number which adds up to j
						can be further reduce to one dimensional dynamic programming
2. DFS
*/
