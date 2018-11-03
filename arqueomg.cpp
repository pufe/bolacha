#include <cstdio>

int main() {
  int n, x, y, a;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d %d", &x, &y);
    a = y-x;
    if (x*y<0)
      a--;
    printf("%d\n", a);
  }
  return 0;
}
