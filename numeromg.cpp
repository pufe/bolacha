#include <cstdio>
const int maxn = 10;
char conversion[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int value[256];
char str[maxn];

int read_number() {
  int x=0;
  scanf(" %s", str);
  for(int i=0; str[i]; ++i) {
    x=36*x+value[(int)str[i]];
  }
  return x;
}

void print_number(int x) {
  if (x>=36)
    print_number(x/36);
  printf("%c", conversion[x%36]);
}

int main() {
  int a, b;
  for(int i=0; conversion[i]; ++i)
    value[(int)conversion[i]]=i;
  while(true) {
    a=read_number();
    b=read_number();
    if (a+b==0)
      break;
    print_number(a+b);
    printf("\n");
  }
  return 0;
}
