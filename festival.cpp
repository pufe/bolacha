#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

const int maxt=86410;
const int maxm=1010;
const int maxn=10;

struct show_t {
  int start, finish;
  int stage;
  int points;
};

int timestamp[maxt];
show_t show[maxm];
vector<int> adj[2*maxm];
int score[2*maxm][1<<maxn];

int main() {
  int n, m, mm;
  int N, c;
  scanf(" %d", &n);
  N = 1<<n;
  m=0;
  for(int i=0; i<maxt; ++i)
    timestamp[i]=-1;
  for(int i=0; i<n; ++i) {
    scanf(" %d", &mm);
    for(int j=0; j<mm; ++j) {
      scanf(" %d %d %d", &show[m].start, &show[m].finish, &show[m].points);
      timestamp[show[m].start]=1;
      timestamp[show[m].finish]=1;
      show[m].stage = i;
      ++m;
    }
  }
  c=0;
  for(int i=0; i<maxt; ++i) {
    if (timestamp[i]>0)
      timestamp[i]=c++;
  }
  for(int i=0; i<m; ++i) {
    show[i].start = timestamp[show[i].start];
    show[i].finish = timestamp[show[i].finish];
    adj[show[i].start].push_back(i);
  }
  for(int i=0; i<c; ++i) {
    for(int j=0; j<N; ++j)
      score[i][j]=-1;
  }
  score[0][0]=0;
  for(int i=0; i<c-1; ++i) {
    for(int j=0; j<N; ++j) {
      if (score[i][j]>=0) {
        score[i+1][j]=max(score[i][j], score[i+1][j]);
        for(int & k : adj[i]) {
          score[show[k].finish][j|(1<<show[k].stage)] = max(score[show[k].finish][j|(1<<show[k].stage)],
                                                            score[i][j]+show[k].points);
        }
      }
    }
  }
  printf("%d\n", score[c-1][N-1]);
  return 0;
}
