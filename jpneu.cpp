#include <cstdio>

int main() {
  int pressao_desejada, pressao_lida;
  scanf(" %d %d", &pressao_desejada, &pressao_lida);
  printf("%d\n", pressao_desejada - pressao_lida);
  return 0;
}
