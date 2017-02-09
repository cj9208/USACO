/*
ID: cjdyx202
PROG: combo
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>     /* abs */

using namespace std;


int main(){
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	
	int n;
	int john[3];
	int master[3];
	cin>>n;
	for(int i = 0; i < 3; i++){
		cin>>john[i];
	}
	for(int i = 0; i < 3; i++){
		cin>>master[i];
	}
	
	
	//or set operation  near John + near Master - near both
	int nb = 1;
	if(n<=5){
		cout<<n*n*n<<endl;
	}
	else{
		for(int i=0;i<3;++i){
			int a=abs(john[i]-master[i]);
			nb *= (a<=4?5-a:0)+(n-4<=a?5-n+a:0);
		}
		cout<<250-nb<<endl;
	}
	


	
	
	return 0;
}
