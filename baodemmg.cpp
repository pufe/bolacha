#include <cstdio>

int main() {
  int escolas, times, premio, total;
  scanf(" %d", &escolas);
  for(int i=0; i<escolas; ++i) {
    scanf(" %d", &times);
    total=0;
    for(int j=0; j<times; ++j) {
      scanf(" %d", &premio);
      total+=premio;
    }
    if (total>times) {
      printf("precisa\n");
    }
    else {
      printf("nao precisa\n");
    }
  }
  return 0;
}
