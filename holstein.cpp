/*
ID: cjdyx202
PROG: holstein
LANG: C++                  
*/

/*
1.枚举每种可能
2.DFS
3.BFS 
	the first ansver found by BFS is optimal
	
use bit operation:
const bin:array[1..15]of integer=
(1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767);
*/
#include <fstream>
#include <bitset>
using namespace std;
ifstream cin("holstein.in");
ofstream cout("holstein.out");
int V,vit[26],G,feed[16][26],vc;  

bitset<16> minbit(0); //最小饲料 注意这里bitset里1个数相同的情况下bit越大的是答案

int main()
{
	int in;
	vc = 17; 
	
	cin>>V;
	for(int i=0;i!=V;i++)
		cin >> vit[i];
	cin>>G;
	for(int i=0;i!=G;i++)
		for(int j=0;j!=V;j++)
			cin >>feed[i][j];
			
	for(int i=0;i<(1<<G);i++)  //search for possible combinations 
	{
		int v[26]={0};
		bitset<16> bit(i);
		for(int b=0;b!=G;b++) {
			if(bit[b]){
				for(int j=0;j!=V;j++){
					v[j]+= feed[b][j];
				} 		
			} 		
		} 
					
		bool ok =  true;
		for(int j=0;j!=V;j++)
			if(v[j] < vit[j]){
				ok = false;
				break;
			}
			
		if(ok && int(bit.count()) < vc && bit.to_ulong() > minbit.to_ulong())	{
			vc = bit.count();
			minbit=bit;
		}	
	}
	cout << vc;
	for(int i=0;i!=G;i++)if(minbit[i])
	        cout << " " <<i+1 ;
	cout << endl;
	return 0;
}
