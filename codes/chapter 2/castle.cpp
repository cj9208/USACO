/*
ID: cjdyx202
PROG: castle
LANG: C++                  
*/

#include <fstream>
#include <iostream> 

#include <algorithm>  
using namespace std; 
  
int n,t,m;
int visit[52][52];  //the number of room it belongs to, -1 means not visited
int room[52*52];    //record the number of rooms correspondng to certain component                                        

bool wall[52][52][5] = {false};     
  
void deal(int w, int i, int j){
	if(w&1){
		wall[i][j][1]=true;
	}
	if(w&2){
		wall[i][j][2]=true;
	}
	if(w&4){
		wall[i][j][3]=true;
	}
	if(w&8){
		wall[i][j][4]=true;
	}    
}

bool ff(int i,int j){
     bool *a=wall[i][j];
     
     if(visit[i][j]!=-1){  //have visited
     	return false;
	 }
	 
     visit[i][j]=t;
     room[t]++;
     
     if(!a[1]) ff(i,j-1);
     if(!a[2]) ff(i-1,j);
     if(!a[3]) ff(i,j+1);
     if(!a[4]) ff(i+1,j);
     
     return true;
}


int main(){
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    
    cin>>m>>n;
    
    for(int i = 1; i <= n; i++){  //always start from 1
    	for(int j = 1; j <= m; j++){
    		cin>>t;
    		deal(t,i,j);
    		visit[i][j] = -1;
		}
	}

    t=0;
    for(int i = 1; i <= n; i++){  
    	for(int j = 1; j <= m; j++){
    		if(ff(i,j)){
    			t++;
			}
		}
	}
	
    cout<<t<<endl;
    cout<<*max_element(room,room+t)<<endl;

	int maxi,maxj,maxr = 0;      
	char maxw;  
	
	for(int j = 1; j <= m; j++){  //search for optimial with farthest to west, farthest to south
		for(int i = n; i >= 1; i--){
			if( i-1 >= 1 && visit[i][j]!=visit[i-1][j]){  
				t=room[visit[i][j]]+room[visit[i-1][j]];
			}
            if(t>maxr){
                maxi=i;
				maxj=j;
				maxw='N';
				maxr=t;
            }
            
			if(j+1<=m && visit[i][j]!=visit[i][j+1]){
            	t=room[visit[i][j]]+room[visit[i][j+1]];
			}
                            
            if(t>maxr){
        		maxi=i;
				maxj=j;
				maxw='E';
				maxr=t;
            } 
            
             
		}
	}
	cout<<maxr<<endl;
	cout<<maxi<<" "<<maxj<<" "<<maxw<<endl;     
	
	return 0; 
}
