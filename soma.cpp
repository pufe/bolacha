#include <cstdio>

int main() {
  int n, x, total;
  scanf("%d", &n);
  total=0;

  //repete n vezes
  for(int i=0; i<n; ++i) {
    scanf("%d", &x);
    total = total+x;
  }

  printf("%d\n", total);
  return 0;
}
