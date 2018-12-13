#include <iostream>
#include <cstring>

using namespace std;

// bm算法链接 https://blog.csdn.net/v_JULY_v/article/details/6545192

void BuildBadCharacterShift(const char *p, int plen, int *shift) {
  for(int i = 0; i < 256; i++) {
    *(shift + i) = plen;
  }

  while(plen > 0) {
    *(shift + (unsigned char)*p++) = --plen;
  }
}

int BmSearch(const char *s, int slen, const char *p, int plen) {
  int s_idx = plen, p_idx;
  
  if(plen <= 0) {
    return -1;
  }
  
  int bad_shift[256] = {0};
  BuildBadCharacterShift(p, plen, bad_shift);
  
  while(s_idx <= slen) {
    p_idx = plen;
    
    while(s[--s_idx] == p[--p_idx]) {
      if(p_idx == 0) {
        return s_idx;
      }
    }

    int bad_stride = bad_shift[s[s_idx]];  
    //s_idx += (plen - p_idx) + 1;
    s_idx += (bad_stride > plen - p_idx ? bad_stride : plen - p_idx) + 1;
  }
}

int main(void) {
  char s[] = "abacababc";
  char p[] = "abab";
  
  int slen = strlen(s);
  int plen = strlen(p);
  
  cout << "slen = " << slen << endl;
  cout << "plen = " << plen << endl;

  int index = BmSearch(s,slen, p, plen);
  cout << "index=" << index << endl;

  return 0;
}
