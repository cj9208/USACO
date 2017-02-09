/*
ID: cjdyx202
PROG: friday
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isleap(int year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 100 ==0 && year % 400 == 0);
}

int main() {
    ifstream fin("friday.in");
    ofstream fout("friday.out");
 
 	int days_of_month[] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30}; //start from Dec
 																				// since we add the number of days of previous month
	vector<int> count(7,0);
	
	int n;
	fin>>n;
	int w = 2;  //0 stands for Monday
				//the previous 13th is Wednesday 
 	for(int i = 0; i< n; i++){
		for(int j = 0; j < 12; j++){
			if(j == 2 && isleap(1900+i)){  // the previous month is Feb
				w += 29;
			}
			else{
				w += days_of_month[j];
			}
			w %= 7;
			count[w]++; 
		}
	}
	for(int i = 5; i < 12; i++){
		if(i != 5){
			fout<<" ";
		}
		fout<<count[i%7];
	}
 	fout<<endl;
 	
    return 0;
}
