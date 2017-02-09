/*
ID: cjdyx202
LANG: C++
TASK: namenum
*/
 

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
using namespace std;
 
/*
given a number, construct all possible character combinations, and check it in the dict
  1. make the dict hash, so that the search takes O(1) time
  2. or when look in the dict, check the name by length, first character
  3. or sort the dict, and generate the name from given number according to alphabet order, 
     thus when do the searching, we could start from previous position.
     As a result, we would only go over the dict once (the dict is already in alphabetical order)
*/ 
 
/*
For each character, the corresponding number is unique
so check each name in dict with the number given
*/ 
const char code[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
char a[13], b[13], c[13];
 
int main()
{
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	freopen("dict.txt", "r", stderr);
	bool flag = false;
	int i;
	cin>>a;  
	
	while (fscanf(stderr, "%s", b) != EOF)
	{
		if (code[b[0]-'A'] != a[0]) {
			continue;   //use first character to rule out most cases
						//could also use length
		}
		for (i = 0; b[i]; ++i){
			c[i] = code[b[i]-'A'];
		}
		c[i] = '\0';    //change to corresponding number
		
		if (!strcmp(a, c)){  //use string to avoid overflow
			flag = true;
			cout<<b<<endl;
		}
	}
	if (!flag) puts("NONE");
	
	
	return 0;
}
