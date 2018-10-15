#include <cstdio>

const int limite=1000000;
int memo[limite];

int calcula(long long int x) {
  if (x==1)
    return 1;
  if (x < limite && memo[x]!=0)
    return memo[x];
  if (x%2==0) {
    if (x < limite) {
      memo[x] = 1+calcula(x/2);
      return memo[x];
    }
    else {
      return 1+calcula(x/2);
    }
  }
  else {
    if (x < limite) {
      memo[x] = 1+calcula(3*x+1);
      return memo[x];
    }
    else {
      return 1+calcula(3*x+1);
    }
  }
}

int main() {
  int i, j, inferior, superior;
  int maior_ciclo;
  while(true) {
    if (scanf(" %d %d", &i, &j)!=2)
      break;
    maior_ciclo=0;
    if (i<j) {
      inferior = i;
      superior = j;
    }
    else {
      inferior = j;
      superior = i;
    }
    for(int x=inferior; x<=superior; ++x) {
      int ciclo = calcula(x);
      if (ciclo > maior_ciclo)
        maior_ciclo = ciclo;
    }
    printf("%d %d %d\n", i, j, maior_ciclo);
  }
  return 0;
}
