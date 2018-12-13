#include "common.h"

#if 1
/* 从下往上冒 */
void BubbleSort1(SqList *L) {
  int i,j;
  if(L == NULL || (L->length > (MAXSIZE+1))) {
    return;
  }
  for(i = 1; i < L->length; i++) {
    for(j = L->length - 1; j >= i; j--) {
      if(L->r[j] > L->r[j+1]) {
        swap(L, j, j + 1);
      }
    }
  }
}
#endif

#if 0
void BubbleSort1(SqList *L) {
  int i,j;
  if(L == NULL || (L->length > (MAXSIZE+1))) {
    return;
  }
  for(i = L->length -1; i > 1; i--) {
    for(j = 1; j <= i; j++) {
      if(L->r[j] > L->r[j+1]) {
        swap(L, j, j + 1);
      }
    }
  }
}
#endif

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
 
  cout << "BubbleSort before: ";
  for(auto &val: L.r) {
    cout << val << " ";
  }
  cout << endl;
  
  BubbleSort1(&L);

  cout << "BubbleSort after: ";
  for(auto &val: L.r) {
    cout << val << " ";
  }
  cout << endl;
}
