#include "common.h"

#if 1
/* 从下往上冒 */
void BubbleSort1(SqList *L) {
  int i,j;
  if(L == NULL || (L->length > (MAXSIZE+1))) {
    return;
  }
 
  bool flag = true;
  for(i = 1; i < L->length && flag; i++) {
    //flag = false;
    for(j = L->length - 1; j >= i; j--) {
      if(L->r[j] > L->r[j+1]) {
        swap(L, j, j + 1);
        //flag = true;
      } else {
        flag = false;
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
  L.r[1] = 2;
  L.r[2] = 1;
  L.r[3] = 3;
  L.r[4] = 4;
  L.r[5] = 5;
  L.r[6] = 6;
  L.r[7] = 7;
  L.r[8] = 8;
  L.r[9] = 9;
  L.r[10] = 10;

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
