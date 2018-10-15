#include <cstdio>

const int tamanho=16;

char nome_par[tamanho];
char nome_impar[tamanho];

int main() {
  int num_teste=1;
  int n, a, b;
  while(true) {
    scanf(" %d", &n);
    if (n==0)
      break;
    printf("Teste %d\n", num_teste);
    num_teste++;

    scanf(" %s %s", nome_par, nome_impar);
    for(int i=0; i<n; ++i) {
      scanf(" %d %d", &a, &b);
      if ((a+b)%2==0)
        printf("%s\n", nome_par);
      else
        printf("%s\n", nome_impar);
    }
    printf("\n");
  }
  return 0;
}
