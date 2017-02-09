/*
ID: cjdyx202
PROG: ride
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define N 47

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
  //  cout<<"input two string :"<<endl;
  //  cin >> comet >> group;
    fin >> comet >> group;
	int c = 1;
    int g = 1;
    for(int i = 0; i < comet.size(); i++){
		c *= comet[i] - 'A' + 1;
		c = c % N;  //in case overflow
	}
    for(int i = 0; i < group.size(); i++){
		g *= group[i] - 'A' + 1;
		g = g % N;
	}
	if(c == g){
		fout<<"GO"<<endl;
//		cout<<"GO"<<endl;
	}
	else{
		fout<<"STAY"<<endl;
//		cout<<"STAY"<<endl;
	}
    
    
    return 0;
}
