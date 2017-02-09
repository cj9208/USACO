/*
ID: cjdyx202
PROG: pprime
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath> //for pow
using namespace std;

int POW[9] = {1, 10, 100, 1000, 10000, 100000,1000000,10000000,100000000};

bool isprime(int n){
	for(int i = 2; i * i <= n; i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

int len(int n){
	int len = 0;
	while(n){
		len++;
		n/=10;
	}
	return len;
}

int generate(int a, int b){//generate a number aba', a' means reversed a, 0<=b<=9
	int l = len(a);
	int ng = a * POW[l+1] + b * POW[l];
	int i = l - 1;
	while(a){
		ng += (a%10)*POW[i--];
		a /= 10;
	}
	return ng;
}

int main(){
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	
	int a, b; //5 <= a < b <= 1e8
	cin>>a>>b;
	
/*
generate all palindrames, check it is prime
	space O(1)
	time O(sqrt(n) * sqrt(n)) = O(n)
1. only pprime with even digits is 11 since they are all divisiable by 11
2. deal with one/two digits specifically 
3. generate the number from small to big
	generate the first half orderly 
	aa' < bb' <=> a < b
*/	
	if(a==5) {	
		cout<<"5\n7\n11"<<endl;
	} 
	else if(a==6||a==7) {
		cout<<"7\n11"<<endl;
	} 
	else if(a>=8 && a<=11) {
		cout<<"11"<<endl;
	}
	
	int lena, lenb;
	lena = max(3, len(a)); //less than 3 digits have been considered
	lenb = len(b);
	
	int ng;
	
	for(int i = lena; i <= lenb; i++){ 
		if(i%2 == 1){ //only need consider odd length
			int t = i/2; 
			for(int j = pow(10, t - 1); j < pow(10, t); j++){
				for(int k = 0; k <=9; k++){
					ng = generate(j,k);
					if(ng < a){
						continue;
					}
					if(ng > b){
						break;
					}
					if(isprime(ng)){
						cout<<ng<<endl;
					}
				}
			}
		}
	}
	
	
	return 0;
}
	

