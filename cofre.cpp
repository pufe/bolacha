#include <cstdio>

int main() {
  int n;
  int cofre_j;
  int cofre_z;
  int num_teste=1;
  int total_cofre_j=0,total_cofre_z=0,total=0;

  while(true) {
    scanf("%d",&n);
    total_cofre_j=0;
    total_cofre_z=0;
    if (n==0)
      break;

    printf("Teste %d\n", num_teste);
    num_teste++;

    for(int i=1; i<=n; ++i){
      scanf("%d", &cofre_j);
      total_cofre_j += cofre_j;
      scanf("%d", &cofre_z);
      total_cofre_z += cofre_z;
      printf("%d\n", total_cofre_j - total_cofre_z);
    }
    printf("\n");
  }
  return 0;
}
