#include "common.h"

using namespace std;
// 时间复杂度为 o(nlogn)
void HeapAdjust(SqList *L, int s, int m) {
  int temp,j;
  temp = L->r[s];
  for(j = 2*s; j <= m; j *= 2) {
    if(j < m && L->r[j] < L->r[j + 1]) {
      j++;
    }

    if(temp >= L->r[j]) {
      break;
    }

    L->r[s] = L->r[j];
    s = j; 
  }

  L->r[s] = temp;
}

void HeapSort(SqList *L) {
  for(int i = L->length/2; i > 0; i--) {
    HeapAdjust(L,i,L->length);
  }

  for(int i = L->length; i > 1; i--) {
    swap(L,1,i);
    HeapAdjust(L,1,i-1);
  }
}

int main(void) {
  SqList L;
  memset(L.r,0, MAXSIZE+1); 
  L.r[1] = 50;
  L.r[2] = 10;
  L.r[3] = 90;
  L.r[4] = 30;
  L.r[5] = 70;
  L.r[6] = 40;
  L.r[7] = 80;
  L.r[8] = 60;
  L.r[9] = 20;
  L.r[10] = 100;

  L.length = 10;
 
  cout << "HeapSort before: ";
  for(auto &val: L.r) {
    cout << val << " ";
  }
  cout << endl;
  
  HeapSort(&L);

  cout << "HeapSort after: ";
  for(auto &val: L.r) {
    cout << val << " ";
  }
  cout << endl;
}
