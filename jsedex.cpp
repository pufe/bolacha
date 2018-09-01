#include <cstdio>

int main() {
  int h,l,p,d;
  scanf("%d%d%d%d",&d,&h,&l,&p);
    if(d<=h && d<=l && d<=p){
      printf("S\n");
    }
    else
      printf("N\n");

  return 0;
}
