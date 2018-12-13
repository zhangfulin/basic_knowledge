#include "common.h"

void SelectSort0(SqList *L) {
  int i,j;
  if(L == NULL || (L->length > (MAXSIZE+1))) {
    return;
  }
  for(i = 1; i < L->length; i++) {
    int min = i;
    for(j = i+1; j <= L->length; j++) {
      if(L->r[min] > L->r[j]) {
        min = j;
      }
    }

    if(min != i) {
      swap(L, i, min);
    }
  }
}

int main(void) {
  SqList L;
  memset(L.r,0, MAXSIZE+1); 
  L.r[1] = 9;
  L.r[2] = 1;
  L.r[3] = 5;
  L.r[4] = 8;
  L.r[5] = 3;
  L.r[6] = 7;
  L.r[7] = 4;
  L.r[8] = 6;
  L.r[9] = 2;
  L.r[10] = 99;

  L.length = 10;
 
  cout << "SelectSort before: ";
  for(auto &val: L.r) {
    cout << val << " ";
  }
  cout << endl;
  
  SelectSort0(&L);

  cout << "SelectSort after: ";
  for(auto &val: L.r) {
    cout << val << " ";
  }
  cout << endl;
}
