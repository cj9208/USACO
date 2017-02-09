/*
ID: cjdyx202
PROG: milk2
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	return (a.first < b. first) || (a.first == b.first && a.second < b.second);
}
//sort alphabetly

int main(){
	ifstream fin("milk2.in");
    ofstream fout("milk2.out");
	
	int n;
	fin>>n;
//	cin>>n;
	vector< pair<int, int> > intervals;
	int start, end;
	for(int i = 0; i < n; i++){
		fin>>start>>end;
		intervals.push_back(make_pair(start, end));
	}
	sort(intervals.begin(), intervals.end(), cmp);
	
	
	start = intervals[0].first;
	end = intervals[0].second;
	int cts = end - start;
	int idle = 0;
	for(int i = 1; i < n; i++){
		if(intervals[i].first <= end){
			end = max(end, intervals[i].second);
			cts = max(cts, end - start);
		}
		else{
			idle = max(idle, intervals[i].first - end);
			start = intervals[i].first;
			end = intervals[i].second;	
		}
	}
	
	fout<<cts<<" "<<idle<<endl;
	
	
	return 0;
} 
