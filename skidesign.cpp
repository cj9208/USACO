/*
ID: cjdyx202
PROG: skidesign
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define N 1000
#define Range 100

int main(){
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	
	int n;
	cin>>n;
	
	int a[N];
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	int ans = 0x7FFFFFFF; //maximum number possible
	
	for(int i = 0; i <= Range - 17; i++){
		int tans = 0;
		for(int j = 0; j < n; j++){
			if(a[j] < i){
				tans += ( i - a[j])*( i - a[j]);
			}
			if(a[j] > i + 17){
				tans += ( i + 17 - a[j])*(i + 17 - a[j]);
			}
		}
		ans = min(ans, tans);
	}
	
	cout<<ans<<endl;
	return 0;
}


