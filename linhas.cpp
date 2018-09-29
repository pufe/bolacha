#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100100;
const int inf = 0x3fff3fff;

struct node_t {
  int bfs_number;
  int first, last;
  int height;
  vector<int> adj;
};

node_t node[maxn];
int bfs_index[maxn];
int rmq[4*maxn];
int rmq_size=0;

int rmq_parent(int p) {
  if (p>=0)
    return p/2+rmq_size;
  return -1;
}
int query(int left, int right) {
  int r=inf;
  while(left<=right) {
    r=min(rmq[left], r);
    r=min(rmq[right], r);
    left=rmq_parent(left+1);
    right=rmq_parent(right-1);
  }
  return r;
}
int lca(int a, int b) {
  int left = min(node[a].first, node[b].first);
  int right = max(node[a].last, node[b].last);
  return bfs_index[query(left, right)];
}

void bfs_number(int root) {
  int c=0;
  queue<int> q;
  node[root].height=0;
  q.push(root);
  while(!q.empty()) {
    int n=q.front();
    q.pop();
    node[n].bfs_number = c;
    bfs_index[c]=n;
    c++;
    for(int &i : node[n].adj) {
      if (node[i].height<0) {
        node[i].height=node[n].height+1;
        q.push(i);
      }
    }
  }
}

void dfs(int n, int parent) {
  node[n].first=node[n].last=rmq_size;
  rmq[rmq_size++]=node[n].bfs_number;
  for(int & i : node[n].adj) {
    if (i!=parent) {
      dfs(i, n);
      node[n].last=rmq_size;
      rmq[rmq_size++]=node[n].bfs_number;
    }
  }
}

int solve(int a, int b, int c, int d) {
  int ab=lca(a, b);
  int cd=lca(c, d);
  if (ab==cd) {
    return node[lca(a,c)].height
      + node[lca(a,d)].height
      + node[lca(b,c)].height
      + node[lca(b,d)].height
      - 4*node[ab].height
      + 1;
  }
  int abcd = lca(ab, cd);
  if (abcd==ab) { // cd dentro de ab
    if (lca(a, cd)==cd) { // a dentro de cd
      return node[lca(a, c)].height
        + node[lca(a, d)].height
        - 2*node[cd].height
        + 1;
    }
    if (lca(b, cd)==cd) { // b dentro de cd
      return node[lca(b, c)].height
        + node[lca(b, d)].height
        - 2*node[cd].height
        + 1;
    }
  }
  if (abcd==cd) { // ab dentro de cd
    if (lca(c, ab)==ab) { // c dentro de ab
      return node[lca(c, a)].height
        + node[lca(c, b)].height
        - 2*node[ab].height
        + 1;
    }
    if (lca(d, ab)==ab) { // d dentro de ab
      return node[lca(d, a)].height
        + node[lca(d, b)].height
        - 2*node[ab].height
        + 1;
    }
  }
  return 0; // os dois são disjuntos
}

int main() {
  int n, q;
  int a, b, c, d;
  int root;
  scanf(" %d %d", &n, &q);
  for(int i=1; i<=n; ++i)
    node[i].height=-1;
  for(int i=1; i<n; ++i) {
    scanf(" %d %d", &a, &b);
    node[a].adj.push_back(b);
    node[b].adj.push_back(a);
  }
  root = -1;
  for(int i=1; i<=n; ++i) {
    if (node[i].adj.size() > 1) {
      root=i;
      break;
    }
  }
  bfs_number(root);
  dfs(root, root);
  for(int i=0; i<rmq_size; ++i) {
    rmq[i+rmq_size]=min(rmq[2*i], rmq[2*i+1]);
  }
  for(int i=0; i<q; ++i) {
    scanf(" %d %d %d %d", &a, &b, &c, &d);
    printf("%d\n", solve(a, b, c, d));
  }
  return 0;
}
