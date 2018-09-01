#include <cstdio>

int main() {
  int n,posicao;
  int num_teste=1;

  while(true) {
    scanf("%d",&n);
    if (n==0)
      break;
    printf("Teste %d\n", num_teste);
    for(int i=1;i<=n;++i) {
      scanf("%d",&posicao);
      if(posicao==i){
        printf("%d\n",posicao);
      }
    }
    num_teste++;
    printf("\n");
  }
  return 0;
}
