/*
ID: cjdyx202
PROG: subset
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// exceed time limit when n >= 31 
int dfs(int sum, int start, int target, int max) {
	if(sum == target){ //already bigger than what we want
		return 1;
	}
	if(sum > target){
		return 0;
	}
	
	int count = 0;
	for(int i = start; i <= max && sum + i <= target; i++){
		count += dfs(sum+i, i+1, target, max);
	}
	return count;
}
int main(){
//    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    
	int n;
	cin>>n;
	
	int count = 0;
	
	int sum = (n+1)*n/2;
	if(sum % 2 == 0){
		count = dfs(0, 1, sum/2, n);
	} 
    cout<<count/2<<endl; //for a possible patition, we count twice
     
    return 0;
}
/*
1. dynamic programming : f[i][j] represents the number of subset of previous i number which adds up to j
						can be further reduce to one dimensional dynamic programming
2.
*/
