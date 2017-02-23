/*
ID: cjdyx202
PROG: contact
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

ifstream in ("contact.in");
ofstream out ("contact.out");

struct trie{
  int count;
  trie* next[2];
  trie(){
    count=0;
    next[0]=next[1]=0;
  }
}*root;


struct res{
  char num[13];
  int count;
};

void append(trie* root, const char data[], int len) {
  const char* end=data+len;
  while(data<end){
    trie** follow=&(root->next[*data-'0']);//ref is also okay
    if(*follow==0)
      *follow=new trie;
    root=*follow;
    data++;
  }
  root->count++;
}

char data[200001];
int len = 0;
int A,B,N;
 
res freqs[10000];
int nfreq;
char curr[13];

void processFreqs(trie* root,int level)
{
  if(root==0)
    return;
  if(level>=A && level<=B && root->count!=0){
    curr[level]='\0';
    strcpy(freqs[nfreq].num,curr);
    freqs[nfreq].count=root->count;
    nfreq++;
  }
  curr[level]='0';
  processFreqs(root->next[0],level+1);
  curr[level]='1';
  processFreqs(root->next[1],level+1);
}

int resSort(const res* a,const res* b)
{
  if(b->count!=a->count)
    return b->count-a->count;
  if(strlen(a->num)!=strlen(b->num))
    return strlen(a->num)-strlen(b->num);
  return strcmp(a->num,b->num);
}

int main()
{
  root=new trie;
 
  in>>A>>B>>N;
  
  char buf[81];
  while(in>>buf){
    strcpy(data+len,buf);
    len+=strlen(buf);
  }
  
  for(int l=A;l<=B;l++)
  	for(int p=0;p+l<=len;p++)
      append(root,data+p,l);
 
  processFreqs(root,0);
  qsort(freqs,nfreq,sizeof(res), (int(*)(const void*,const void*))resSort);
 
  int Nprint=0,sprint=0;//segment
  res* s=freqs,*c=freqs;
  while(Nprint!=N){
    out<<s->count<<endl;
    while(s->count==c->count){
      if(c==freqs+nfreq){
        out<<endl;
        return 0;
      }
      if(c!=s)
        out<<(sprint%6?' ':'\n');
      out<<c->num;
      sprint++;
      c++;
    }
    if(c==freqs+nfreq){
      out<<endl;
      return 0;
    }
    out<<endl;
    Nprint++;
    sprint=0;
    s=c;
  }
  return 0;
}
