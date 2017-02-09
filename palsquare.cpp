/*
ID: cjdyx202
PROG: palsquare
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define N 300 // the maximum number to consider

//use list as dictionary
char NUMBER[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
                   'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

string convert(int num, int base){
	string numb;
	while(num){
		numb.insert(numb.begin(), NUMBER[num%base]);
		num /= base;
	}
	return numb;
}
bool ispal(string num){
	for(string::iterator forward = num.begin(), back = num.end()-1; forward < back; back--, forward++){
		if(*back != *forward){
			return false;
		}
	}
	return true;
}


int main(){
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	
	int b;
	cin>>b;

	string ib;
	for(int i = 1; i <= N; i++){
		ib = convert(i*i, b);  //for square, cannot use ^
		if(ispal(ib)){
			cout<<convert(i,b)<<" "<<ib<<endl;
		}
	}
	
	
	return 0;
}
