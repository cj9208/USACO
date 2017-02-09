/*
ID: cjdyx202
PROG: combo
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>     /* abs */

using namespace std;
int n;

//pay attention, the number are in a circle
bool close1(int a, int b){
	return (abs(a-b)<=2) || (abs(a-b)>=n-2);
}

bool close(int a, int b, int c, int d[]){
	return close1(a,d[0]) && close1(b,d[1]) && close1(c, d[2]);
}

int main(){
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	
	int john[3];
	int master[3];
	cin>>n;
	for(int i = 0; i < 3; i++){
		cin>>john[i];
	}
	for(int i = 0; i < 3; i++){
		cin>>master[i];
	}
	
	
	//complete search
	int total = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if (close(i,j,k,john) || close(i,j,k,master)){
					total++;
				}
			}
		}
	}
	cout<<total<<endl;
	
	
	//or set operation  near John + near Master - near both
/*
	int nj = 1;
	int nm = 1;
	int nb = 1;
	
	int low, upper;
	for(int i = 0; i < 3; i++){
		low = max(1, j[i]-2);
		upper = min(n, j[i]+2);
		nj *= (upper - low + 1); 
	}
	for(int i = 0; i < 3; i++){
		low = max(1, m[i]-2);
		upper = min(n, m[i]+2);
		nm *= (upper - low + 1); 
	}
	for(int i = 0; i < 3; i++){
		low = max(1, j[i]-2);
		low = max(low, m[i]-2);
		upper = min(n, j[i]+2);
		upper = min(upper, m[i]+2);
		nb *= max(0, upper - low + 1 ); 
	}
	
	cout<<(nj + nm - nb)<<endl;

*/
	
	
	return 0;
}
