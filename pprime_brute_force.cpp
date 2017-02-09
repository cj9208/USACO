/*
ID: cjdyx202
PROG: pprime
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isprime(int n){
	for(int i = 2; i * i <= n; i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

bool ispal(int n){
	int a[10];
	int l = 1;
	while(n){
		a[l++] = n%10;
		n/=10;
	}
	l--;
	for(int i = 1; i <= l/2; i++){
		if(a[i] != a[l + 1-i]){
			return false;
		}
	}
	return true;
}


int main(){
//	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	
	int a, b; //5 <= a < b <= 1e8
	cin>>a>>b;
	
/*
1. find all prime, check it is palindromes
    space O(n) : can use bit opeation/reduce impossible cases to save space 
    time O(n)
2. generate all palindrames, check it is prime
	space O(1)
	time O(sqrt(n) * sqrt(n)) = O(n)
3. brute force 
	space O(1)
	time O(n^1.5) 
*/	
	
	for(int i = a; i <= b; i++){
		if(isprime(i) && ispal(i)){
			cout<<i<<endl;
		}
	}
		
	return 0;
}
