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
 
// BFS,用位记录饲料组合,注意剪枝
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
  vector<bool> is_searched(1 << type_of_feed + 1, false); // 记录饲料组合是否已被搜索到,最长2^15 + 1
  deque<int> q;
  
  int feed = 0, current_feed = 0;  // 用bit位来记录搜索到的饲料组合
  vector<int> state, current_state; // 记录饲料组合的维他命数
 
  while (true) {
    if (!q.empty()) {
      feed = q.front();
      q.pop_front();
      state = GetState(feed);
    }
 
    for (int i = 0; i < type_of_feed; ++i) {
      current_feed = feed;
      current_state = state;
 
      current_feed |= (1 << i);  // 用或运算把当前的饲料加到原有的组合当中
      // 如果或运算之后未变,则搜索到重复饲料, 若当前组合已访问, 则也可剪枝
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
  // 判断一个饲料组合是否满足需要
  if (feed.empty()) return false;
  for (int i = 0; i < type_of_vitamin; ++i)
    if (feed[i] < vitamin[i])
      return false;
  return true;
}
 
inline vector<int> GetState(int feed) {
  // 从一个数取出二进制位并生成饲料组合及其维他命数
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
  // 将一个新的饲料加到原有的的饲料组合中并计算维他命数
  if (state.empty()) {
    state = feed;
  } 
  else {
    for (int i = 0; i < type_of_vitamin; ++i)
      state[i] += feed[i];
  }
}
 
vector<int> BitToVector(int feed) {
  // 把一个二进制饲料组合转化成数组,用于最后输出
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
