#include <cstdio>

int main() {
  int num_teste=1;
  int a,b,r;
  int total_aldo, total_beto;

  while(true) {
    total_aldo=0;
    total_beto=0;
    scanf("%d",&r);
    if (r==0)
      break;
    for(int i=0; i<r; ++i) {
      scanf(" %d %d", &a, &b);
      total_aldo += a;
      total_beto += b;
    }
    printf("Teste %d\n", num_teste);
    num_teste++;
    if (total_aldo > total_beto)
      printf("Aldo\n");
    else
      printf("Beto\n");
    printf("\n");
  }

  return 0;
}
