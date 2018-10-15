#include <cstdio>
#include <cstring>

const int maxn=2020;
const int valor_especial=10000;

char palavra[maxn];
bool especial[maxn];
int memo[maxn][maxn];

int melhor_resultado(int comeco, int fim) {
  if (fim < comeco)
    return 0;
  if (fim == comeco) {
    if (especial[fim])
      return valor_especial+1;
    else
      return 1;
  }
  if (memo[comeco][fim]!=0)
    return memo[comeco][fim];
  int esquerda, direita, meio;
  esquerda = melhor_resultado(comeco, fim-1);
  direita = melhor_resultado(comeco+1, fim);
  if (palavra[comeco]==palavra[fim]) {
    meio = melhor_resultado(comeco+1, fim-1);
    if (especial[comeco])
      meio += valor_especial;
    if (especial[fim])
      meio += valor_especial;
    meio+=2;
  }
  else {
    meio = 0;
  }
  if (meio > direita && meio > esquerda) {
    memo[comeco][fim]=meio;
  }
  else if (direita > esquerda) {
    memo[comeco][fim]=direita;
  }
  else {
    memo[comeco][fim]=esquerda;
  }
  return memo[comeco][fim];
}

int main() {
  int n, m, x;
  scanf("%s", palavra);
  scanf(" %d", &m);

  for(int i=0; i<m; ++i) {
    scanf(" %d", &x);
    especial[x-1]=true;
  }
  /*
     n=0;
     while(palavra[n]!='\0')
       n++;
  */
  n = strlen(palavra);
  x = melhor_resultado(0, n-1);
  printf("%d\n", x%valor_especial);
  return 0;
}
