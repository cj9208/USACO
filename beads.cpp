/*
ID: cjdyx202
PROG: beads
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



int main() {
    ifstream fin("beads.in");
    ofstream fout("beads.out");
 
 	int len;
 	string beads;
 	fin>>len>>beads;
 	beads = beads + beads; //double to make it like cycle
 	
 	int a = 0, b = 0, w = 0; // a : the current longest beads of reversed order without white color
 							 // b : the current longest beads of same color
 							 // w : current longest beads of white color
 	char c = '0';
	int ans = 0;
	for(int i = 0; i < beads.size(); i++){
		if(beads[i] == 'w'){ //white bead
			b++;
			w++;
		}
		else if(beads[i] == c){ //the same color as before
			b++;
			w=0;
		}
		else { //change color
			if( a + b > ans){  //decide if max length 
				ans = a + b;
			}
			a = b - w;
			b = w + 1;
			w = 0;
			c = beads[i]; 
			
		}
		
	} 
	if( a + b > ans){  //decide if max length 
		ans = a + b;
	}  
 	if(ans > len){
 		ans = len;
	 }
 	fout<<ans<<endl;

    return 0;
}


