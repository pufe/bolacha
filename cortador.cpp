#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long int huge;
const int maxn = 100100;

int vet[maxn];
int aux[maxn];

//                   [start, finish)
huge count_inversions(int start, int finish) {
  if (finish<=start+1) {
    return 0;
  }
  huge c=0;
  int mid=(start+finish)/2;
  c+=count_inversions(start, mid);
  c+=count_inversions(mid, finish);
  for(int i=start; i<finish; ++i)
    aux[i]=vet[i];
  int p1=start;
  int p2=mid;
  int p3=start;
  while(p1<mid && p2<finish) {
    if (aux[p1]<aux[p2]) {
      vet[p3++]=aux[p1++];
    }
    else {
      c+=mid-p1;
      vet[p3++]=aux[p2++];
    }
  }
  while(p1<mid) {
    vet[p3++]=aux[p1++];
  }
  while(p2<finish) {
    vet[p3++]=aux[p2++];
  }
  return c;
}

pair<int, int> cortes[maxn];


int main() {
  huge d[2];
  huge r=0;

  scanf(" %*d %*d %lld %lld", &d[0], &d[1]);
  for(int k=0; k<2; ++k) {
    for(int i=0; i<d[k]; i++) {
      scanf(" %d %d", &cortes[i].first, &cortes[i].second);
    }
    sort(cortes, cortes+d[k]);
    for(int i=0; i<d[k]; ++i)
      vet[i]=cortes[i].second;
    r+=count_inversions(0, d[k]);
  }
  printf("%lld\n", (d[0]+1ll)*(d[1]+1ll)+r);
  return 0;
}
