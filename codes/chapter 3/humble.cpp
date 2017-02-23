/*
ID: cjdyx202
PROG: humble
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <vector>
#include <cstring>
#include <climits> //fir INT_MAX

using namespace std;

	
 
int main(){
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
  	
  	int k,n;
	int p[101] = {0};

	int pindex[101];	
	int humble[100001] = {0};
	int i;
  	
	int minimum;	
	int j,l;
	
	
	cin>>k>>n;
	for(i = 1; i <= k; i++){
		cin>>p[i];
		pindex[i] = 1;
		humble[i] = p[i];
	} //here i = k+1
	
	//in case that p1*p2*.. <p3
	vector<bool> isin(humble[k]+1, false);
	bool flag = true; //if add new element
	int t0 = 1, t1 = i;
	while(flag){
		for(j=1; j<=k;j++){
			for(l = t0; l < t1;l++){
				int temp =  humble[l] * p[j];
				if(temp < humble[k] && !isin[temp]){
					humble[i++] = temp;
					isin[temp] = true;
				}
			}
		}
		if(t1 == i){ //no element being added
			flag = false;
		}
		t0 = t1;
		t1 = i;
	}
	
	
	sort(humble+1, humble+i);
	
	for(j = 1; j <= k; j++){
		pindex[j] = 1;
	}
	
	for(; i <= n; i++){
		minimum = INT_MAX;
		for(j = 1; j <= k; j++){			
			for(l = pindex[j]; humble[l] * p[j] <= humble[i-1]; l++){
				;
			}
			pindex[j] = l;
			minimum = min(minimum, humble[l]*p[j]);
		}
		humble[i] = minimum;
	}
	cout<<humble[n]<<endl;
/*	
	for(int i = 1; i <= 30; i++){
		cout<<humble[i]<<endl;
	}
*/	 
    return 0;
}


