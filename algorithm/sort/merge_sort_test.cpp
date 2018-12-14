#include <iostream>

using namespace std;

#if 0
void MergeArray(int a[], int first, int mid, int last, int temp[])
{
  int i = first, j = mid + 1;
  int m = mid,  n = last;

  int k = first;
  while(i <= m && j <= n) {
    if(a[i] <= a[j]) {
      temp[k++] = a[i++];
    } else {
      temp[k++] = a[j++];
    }
  }

  while(i <= m) {
    temp[k++] = a[i++];
  }

  while(j <= n) {
    temp[k++] = a[j++];
  }
  for(int index = first; index <= last; index++) {
    a[index] = temp[index];
  }
}
#endif

/*
 * 下面链接为归并排序博客地址 <时间复杂度(o(N*logN))>
 * <href> https://blog.csdn.net/MoreWindows/article/details/6678165 </href>
 */
// 将两个有序数列a[first...mid]和a[mid, last]合并
void MergeArray(int a[], int first, int mid, int last, int temp[])
{
  int i = first, j = mid + 1;
  int m = mid,  n = last;

  int k = 0;
  while(i <= m && j <= n) {
    if(a[i] <= a[j]) {
      temp[k++] = a[i++];
    } else {
      temp[k++] = a[j++];
    }
  }

  while(i <= m) {
    temp[k++] = a[i++];
  }

  while(j <= n) {
    temp[k++] = a[j++];
  }
  
  for(int i = 0; i < k; i++) {
    a[first +i] = temp[i];
  }
}

void MergeSort2(int a[], int first, int last, int temp[])
{
  if(first < last) {
    int mid = (first + last) / 2;
    MergeSort2(a, first, mid, temp);
    MergeSort2(a, mid + 1, last, temp);
    MergeArray(a, first, mid, last, temp);
  }
}

bool MergeSort(int a[], int n)
{
  int *p = new int[n];
  if(p == NULL) {
    return false; 
  }

  MergeSort2(a, 0, n - 1, p);
  
  delete[] p;
  return true;
}

int main(void)
{
  int a[10] = {23, 10, 233, 2, 123, 99, 100, 168, 70, 9};
  
  MergeSort(a, sizeof(a)/sizeof(a[0]));
  
  for(int i = 0; i < 10; i++) {
    cout << a[i] << " ";
  }
  
  cout << endl;
  return 0;
}
