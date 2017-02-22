/*
ID: cjdyx202
PROG: runround
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;


bool check(unsigned long num){
    int count_num[10]={0};
    int digit_num[10]= {0};
    int digit_num2[10] = {0};
    int check_pos[10] = {0};
    unsigned long temp = num;
    
	int length=0;
	
    while (temp){
        int i=temp%10;
        if(i == 0){
        	return false;
		}
		
        digit_num2[length] = i; //for not reversed 
        count_num[i]++;
        if (count_num[i]>1) //duplcate number
            return false;
            
        temp/=10;
        length++;
    }
    for(int i = 0; i < length; i++){
    	digit_num[length - 1 - i] = digit_num2[i];
	}
    
    for (int i=0,count=0;count<length;count++){
        i+=digit_num[i];
        i %= length;
        check_pos[i]++;
    }
    
    bool flag = true;
    for (int i=0;i<length;i++){
    	if (check_pos[i] != 1)
            flag = false;
	}
    	
        
 
    return flag;
}
 
int main(){
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    
//judge or generate     
    int m;
    cin>>m;
    for(int i = m+1; ;i++){
    	if(check(i)){
    		cout<<i<<endl;
    		break;
		}
	}
     
    return 0;
}
