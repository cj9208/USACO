/*
ID: cjdyx202
PROG: sprime
LANG: C++                  
*/
#include <iostream>
#include <fstream>
using namespace std;

int c[4] {1,3,7,9}; //other digits

bool isprime(int n){
	for(int i = 2; i*i<=n; i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
	
}

void dfs(int num, int cur, int n){
	if(cur == n){
		if(isprime(num)){
			cout<<num<<endl;
		}
		return;
	}
	for(int i = 0; i < 4; i++){
		int temp = num*10+b[i];
		if(isprime(temp)){
			dfs(temp, cur+1, n);
		}
		
	}
}

int main(){
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	//DFS
	int n;	
	cin>>n;
	int b[4] = {2,3,5,7}; //first digit
	for(int i = 0; i < 4; i++){
		dfs(b[i],1, n);
	}
		
	return 0;
}
