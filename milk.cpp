/*
ID: cjdyx202
PROG: milk 
LANG: C++                  
*/
#include <iostream>
#include <fstream>

#include <vector>
#include <utility>  //for pair
#include <algorithm> //for sort

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	return (a.first<b.first);
}
int main(){
	
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int n,m;  //n : the amount of milk, m : number of farmers
	cin>>n>>m;
	
	vector<pair<int, int> > pa;
	int p, a;
	for(int i = 0; i < m; i++){
		cin>>p>>a;
		pa.push_back(make_pair(p,a));
	}
	sort(pa.begin(), pa.end(), cmp);
	
	int cost = 0;
	int left = n; //the amount of milk left
	int i = 0;
	while(left){
		if(pa[i].second <= left){
			cost += pa[i].first * pa[i].second;
			left -= pa[i].second;
			i++;
		}
		else{
			cost += pa[i].first * left;
			left = 0;
		}
		
	}
	cout<<cost<<endl;
	
	return 0;
} 
