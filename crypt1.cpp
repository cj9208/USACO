

/*
ID: cjdyx202
PROG: crypt1
LANG: C++                  
*/
#include <iostream>
#include <fstream>

#include <vector>
#include <utility>  //for pair
#include <algorithm> //for sort

using namespace std;

#define jud(t) for(int x=t;x;x/=10) if((1<<(x%10)|k)!=k) flag=false;

int main(){
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	
	//complete search
	
	int n,t,k=0,cnt=0;
	cin>>n;
	
    while(n--) {
    	cin>>t;
		k|=1<<t;  
	} //use list           O(n)
	  //use bit/hash table O(1)
    
    for(int i=100;i<1000;i++)  //search for all possiblities
        for(int j=10;j<100&&i*j<10000;j++){
            if(i*(j/10)>999 || i*(j%10)>999) 
				continue;
            bool flag=true;
            jud(i);
			jud(j);
			jud(i*j);
			jud(i*(j/10));
			jud(i*(j%10));
            cnt+=flag;
        }
    cout<<cnt<<endl;
	
	
	return 0;
}
