/*
ID: cjdyx202
PROG: dualpal
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define BaseMax 10
#define BaseMin 2
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

bool isdualpal(int num){
	int count = 0;
	for(int i = BaseMin; i <= BaseMax; i++){
		if(ispal(convert(num,i))){
			count++;
		}
		if(count >= 2){ //alredy find two bases
			return true;
		}
	}
	return false;
}

int main(){
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	
	int n, s;
	cin>>n>>s;
	
	for(int i = 0, j = s + 1; i < n; j++){
		if(isdualpal(j)){
			cout<<j<<endl;
			i++;
		}
	}
	
	return 0;
}
