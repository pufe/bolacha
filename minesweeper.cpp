#include <cstdio>

const int maxn = 200;
char mtx[maxn][maxn];
int num_mines[maxn][maxn];

void increment_neighbors(int a, int b) {
  for(int i=a-1; i<=a+1; ++i)
    for(int j=b-1; j<=b+1; ++j)
      num_mines[i][j]++;
}

int main() {
  int n, m;
  int field=1;
  while(true) {
    scanf(" %d %d", &n, &m);
    if (n==0&&m==0)
      break;
    printf("Field #%d:\n", field);
    ++field;
    for(int i=1; i<=n; ++i)
      for(int j=1; j<=m; ++j)
        num_mines[i][j]=0;
    for(int i=1; i<=n; ++i) {
      for(int j=1; j<=m; ++j) {
        scanf(" %c", &mtx[i][j]);
        if (mtx[i][j]=='*')
          increment_neighbors(i, j);
      }
    }
    for(int i=1; i<=n; ++i) {
      for(int j=1; j<=m; ++j) {
        if (mtx[i][j]=='*')
          printf("*");
        else
          printf("%d", num_mines[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
