#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE = 10;

struct SqList {
  /* 用于存储要排序数组, r[0]用作哨兵或临时变量 */ 
  int r[MAXSIZE + 1];
  /* 用于记录顺序表的长度 */
  int length;
};

void swap(SqList *L, int i, int j) {
  int temp = L->r[i];
  L->r[i]  = L->r[j];
  L->r[j]  = temp;
}
