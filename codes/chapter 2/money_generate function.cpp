/*
ID: cjdyx202
PROG: money
LANG: C++                  
*/

#include <stdio.h>
#include <stdlib.h>
#define _DEBUG 0
#define MAX_C 25 
#define MAX_MONEY 10000 

 
int main(){
	long long c1[MAX_MONEY+1];
	long long c2[MAX_MONEY+1];
    long long coins[MAX_MONEY+1];
	int v,n;
 
	freopen("money.in","r",stdin);
//	freopen("money.out","w",stdout);

	int i,j,k,c;
	scanf("%d %d",&v,&n);
	for(i=0;i<v;++i){
		scanf("%ld",&coins[i]);
	}
	for(i=0;i<=n;++i){
		c1[i]=0;
		c2[i]=0;
	}
	c1[0]=1;
 
	for(i=0;i<=n;i+=coins[0]){  
		c1[i]=1;
	}
	for(i=1;i<v;++i){
		c=coins[i];
		for(j=0;j<=n;++j){
			for(k=0;k<=n && j+k<=n;k+=c){ //very clever, avoid duplicate counting
				c2[j+k]+=c1[j];
			}
		}
		for(j=0;j<=n;++j){  
			c1[j]=c2[j];
			c2[j]=0;
		}
	}
	printf("%lld\n",c1[n]);
}

