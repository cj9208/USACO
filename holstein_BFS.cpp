/*
  ID: cjdyx202
  PROG: holstein
  LANG: C++
*/

//something went wrong 

#include <fstream>
#include <vector>
#include <deque>
using namespace std;


 
static int type_of_vitamin;
static int type_of_feed;
static vector<int> vitamin;
static  vector< vector<int> > feeds;
 
vector<int> GetMinFeed();
inline bool IsEnough(const vector<int> &feed);
inline vector<int> GetState(int feed);
inline void AddFeed(vector<int> &state, const vector<int> feed);
vector<int> BitToVector(int feed);
 
// BFS,��λ��¼�������,ע���֦
int main() {
  ifstream fin("holstein.in");
  ofstream fout("holstein.out");
 
  fin >> type_of_vitamin;
  int v;
  for (int i = 0; i < type_of_vitamin; i++) {
    fin >> v;
    vitamin.push_back(v);
  }
 
  fin >> type_of_feed;
  int g;
  vector<int> feed;
  for(int i = 0; i < type_of_feed; i++){
  	for(int j = 0; j < type_of_vitamin; j++){
  		fin>>g;
  		feed.push_back(g);
	}
	feeds.push_back(feed);
  } 
 
  vector<int> min_feed = GetMinFeed();
  
  fout << min_feed.size();
  for (int i = 0; i < min_feed.size(); ++i) {
    fout <<" "<< min_feed[i];
  }
  fout << endl;
  return 0;
}
 
vector<int> GetMinFeed() {
  vector<bool> is_searched(1 << type_of_feed + 1, false); // ��¼��������Ƿ��ѱ�������,�2^15 + 1
  deque<int> q;
  
  int feed = 0, current_feed = 0;  // ��bitλ����¼���������������
  vector<int> state, current_state; // ��¼������ϵ�ά������
 
  while (true) {
    if (!q.empty()) {
      feed = q.front();
      q.pop_front();
      state = GetState(feed);
    }
 
    for (int i = 0; i < type_of_feed; ++i) {
      current_feed = feed;
      current_state = state;
 
      current_feed |= (1 << i);  // �û�����ѵ�ǰ�����ϼӵ�ԭ�е���ϵ���
      // ���������֮��δ��,���������ظ�����, ����ǰ����ѷ���, ��Ҳ�ɼ�֦
      if (current_feed == feed || is_searched[current_feed]) 
        continue;
 
      is_searched[current_feed] = true;      
      AddFeed(current_state, feeds[i]);
      
      if (IsEnough(current_state))
        return BitToVector(current_feed);
      else
        q.push_back(current_feed);
    }
  }
}
 
inline bool IsEnough(const vector<int> &feed) {
  // �ж�һ����������Ƿ�������Ҫ
  if (feed.empty()) return false;
  for (int i = 0; i < type_of_vitamin; ++i)
    if (feed[i] < vitamin[i])
      return false;
  return true;
}
 
inline vector<int> GetState(int feed) {
  // ��һ����ȡ��������λ������������ϼ���ά������
  vector<int> state;
  int bit = 0;
  while (feed) {
    if (feed & 1)
      AddFeed(state, feeds[bit]);
    ++bit;
    feed >>= 1;
  }
  return state;
}
 
inline void AddFeed(vector<int> &state, const vector<int> feed) {
  // ��һ���µ����ϼӵ�ԭ�еĵ���������в�����ά������
  if (state.empty()) {
    state = feed;
  } 
  else {
    for (int i = 0; i < type_of_vitamin; ++i)
      state[i] += feed[i];
  }
}
 
vector<int> BitToVector(int feed) {
  // ��һ���������������ת��������,����������
  vector<int> feeds;
  int bit = 0;
  while (feed) {
    if (feed & 1)
      feeds.push_back(bit + 1);
    ++bit;
    feed >>= 1;
  }
  return feeds;
}
