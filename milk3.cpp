/*
ID: cjdyx202
PROG: milk3
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <utility>  //for pair
#include <algorithm> //for sort

using namespace std;

#define MAX 21

int vist[MAX][MAX][MAX] = {0};
int milk[MAX] = {0};
int b[3];  //the capacity of A,B,C

void dfs(int a[]){
	if(vist[a[0]][a[1]][a[2]]){
		return;
	}
	vist[a[0]][a[1]][a[2]] = 1;
	if(a[0] == 0){  //want : all the possible amounts of milk that can be in bucket C when bucket A is empty
		milk[a[2]] = 1;
	}
		
	for (int i = 0; i < 3; ++i) {  //pour i to j
		for (int j = 0; j < 3; ++j) {
			if (j == i) {  //same bucket
				continue;
			}
			
			if (a[j] < b[j] && a[i] > 0) {
				int rec = min(b[j]- a[j], a[i]);
				a[j] += rec;
				a[i] -= rec;
				dfs(a);
				a[j] -= rec;
				a[i] += rec;
			}
		}
	}
	
} 

int main(){
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	
	cin>>b[0]>>b[1]>>b[2];
/*
1. DFS
2. Mathematically calculate
*/		
	int a[3] = {0, 0, b[2]};
	dfs(a);
	
	bool blank = false;
	for(int i = 0; i <= b[2]; i++){
		if(milk[i]){
			if(!blank){
				blank = true;
			}
			else{
				cout<<" ";
			}
			cout<<i;
		}
	}
	cout<<endl;
	
	return 0;	
}



