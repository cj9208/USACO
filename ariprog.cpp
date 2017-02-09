/*
ID: cjdyx202
PROG: ariprog
LANG: C++                  
*/
#include <iostream>
#include <fstream>

#include <vector>
#include <utility>  //for pair
#include <algorithm> //for sort

using namespace std;

#define N 25
#define M 250 


bool cmp(pair<int,int> a, pair<int,int> b){
	return (a.second < b.second);
}

// smallest-difference sequences first and smallest starting number within those sequences first 
int main(){
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	
	int n,m;    //n: the length of progression
				//m:the upper bound to limit the search to bisquares  0<=p,q<=m
	cin>>n>>m;
	
	//find all bisquare within the limit
	int bisqu[M*M+1];
	bool isbisqu[2*M*M+1];
	int k = 0; //for the length of bisquares
	
	for(int i = 0; i <= m; i++){
		int t = i * i;
		for(int j = 0; j <= m; j++){
			isbisqu[t+j*j] = true;
		}
	}
	for(int i = 0; i <= 2*m*m; i++){  //avoid duplicates and already sorted
		if(isbisqu[i]){
			bisqu[k++] = i;
		}		
	} 
	
	vector<pair<int, int> > ans;
	
	//here k is length of possible bisquares
	for(int i = 0; i + n - 1 < k; i++){  
		for(int j = i + 1; j < k && j + n -2 < k; j++){
			int d = bisqu[j] - bisqu[i];  
			if(bisqu[i] + (n-1) * d > bisqu[k-1]){
				break;   
			}
			//complete check
			bool flag = true;
			for(int t = 2; t < n; t++){
				if(!isbisqu[bisqu[i] + t*d]){
					flag = false;
					break;
				}
			}
			//true
			if(flag){
				ans.push_back(make_pair(bisqu[i],d));  
			}
		}
	} 
	
	//output
	if(ans.empty()){
		cout<<"NONE"<<endl;
	}
	else{
		sort(ans.begin(), ans.end(), cmp);
		for(vector<pair<int, int> >::iterator iter = ans.begin(); iter != ans.end(); iter++){
			cout<<(*iter).first<<" "<<(*iter).second<<endl;
		}
	}
	
	
	return 0;
}


