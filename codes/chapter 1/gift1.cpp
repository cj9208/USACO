/*
ID: cjdyx202
PROG: gift1
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
 
    int n;
    fin >> n;
    //keep the order for output
    vector<string> givers;
    string name;
    for (int i = 0; i < n; ++i) {
        fin >> name;
        givers.push_back(name);
    }
 	
    map<string, int> people;
    int money, gift, people_num;
    string giver, reciever;
    for (int i = 0; i < n; ++i) {
        fin >> giver >> money >> people_num;
        if (money == 0 || people_num == 0)
            continue;
 
        gift = money / people_num;
        for (int j = 0; j < people_num; ++j) {
            fin >> reciever;
            people[reciever] += gift;
        }
        people[giver] -= gift * people_num;
    }
 
    for (vector<string>::iterator iter = givers.begin(); iter != givers.end(); ++iter) {
        fout << *iter << " " << people[*iter] << "\n";
    }
 
    return 0;
}
