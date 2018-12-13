
#include "common.h"

void InsertionSort0(SqList *L) {
  int i,j;
  if(L == NULL || (L->length > (MAXSIZE+1))) {
    return;
  }
  
  for(i = 2; i <= L->length; i++) {
    
    if(L->r[i] < L->r[i-1]) {
      
      L->r[0] = L->r[i];
      
      for(j = i - 1; L->r[j] > L->r[0];j--) {
        L->r[j+1] = L->r[j];
      }

      L->r[j+1] = L->r[0];
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
 
  cout << "InsertionSort before: ";
  for(auto &val: L.r) {
    cout << val << " ";
  }
  cout << endl;
  
  InsertionSort0(&L);

  cout << "InsertionSort after: ";
  for(auto &val: L.r) {
    cout << val << " ";
  }
  cout << endl;
}
