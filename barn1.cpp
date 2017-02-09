/*
ID: cjdyx202
PROG: barn1
LANG: C++                  
*/
#include <iostream>
#include <fstream>

#include <vector>
#include <utility>  //for pair
#include <algorithm> //for sort

using namespace std;

int main(){
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	
	int m,s,c;  // m : maximum number of boards that can be purcased
				// s : total number of stalls
				// c : the number of cows
	cin>>m>>s>>c;
	
	vector<int> sc; //store the number of stall with cow in it
	int num;
	for(int i = 0; i < c; i++){
		cin>>num;
		sc.push_back(num);
	}
	
	//sort it
	sort(sc.begin(), sc.end());
	
	vector<int> interval;  // store the interval between cows
	for(int i = 1; i < sc.size(); i++){
		interval.push_back(sc[i] - sc[i-1] - 1);
	}
	sort(interval.begin(), interval.end(), greater<int>());
	
	int total = sc[sc.size() - 1] - sc[0] + 1;
	
	int t = min(m-1, c-1); //possible step
	for(int i = 0; i < t; i++){
		total -= interval[i];
	}
	
	cout<<total<<endl;
	
	return 0;
}


/*
DP:
suppose f[i,j] represents that the minimum length of using i boards to cover j cows
f[i,j]=min{f[i-1,j-1]+1,f[i,j-1]+a[j]-a[j-1]}  

*/
