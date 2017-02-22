/*
ID: cjdyx202
PROG: ttwo
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <algorithm> 

#include <string>
using namespace std;

#define N 11 
int maze[N][N] = {0}; 
int fx, fy;
int cx, cy;
int fd = 0, cd = 0;  // direction, 0 : north, 1 : east, 2 : south, 3 : west
int d[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

void move(){
	int tx, ty;
	
	tx = fx + d[fd][0];
	ty = fy + d[fd][1];
	if(tx<1 || tx >10 || ty<1 || ty>10 || maze[tx][ty] == 1){ //out of range or meet obstacle
		fd = (fd+1)%4;
	}
	else{
		fx = tx;
		fy = ty;
	}
	
	tx = cx + d[cd][0];
	ty = cy + d[cd][1];
	if(tx<1 || tx >10 || ty<1 || ty>10 || maze[tx][ty] == 1){ //out of range or meet obstacle
		cd = (cd+1)%4;
	}
	else{
		cx = tx;
		cy = ty;
	}
}

bool meet(){
	return fx == cx && fy == cy;
} 


int main(){
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
     
/*
1. The number of all states : 10*10*4 = 400 
2. can use list to record states 
*/	char c;
	for(int i = 1; i<N; i++){
		for(int j = 1; j < N; j++){
			cin>>c;
			if(c == '*'){
				maze[i][j] = 1;
			}
			else if(c == 'F'){
				fx = i;
				fy = j;
			}
			else if(c == 'C'){
				cx = i;
				cy = j;
			}			
		}
	} 
	 
	//simulate the move of farmer and cows
	
	int count = 0;
	while(! meet()){
		
		move();
		count++;
		
		if(count > 200000){
			break;  //at most 160000 states
		}
		
	}
	if(count <= 200000){
		cout<<count<<endl;
	} 
	else{
		cout<<0<<endl;
	}
    return 0;
}
