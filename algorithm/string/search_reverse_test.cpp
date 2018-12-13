#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int search_reverse(const char *s, int slen, const char *p, int plen) {
  int s_idx = plen, p_idx;
  if(plen <= 0) return -1;
  
  while(s_idx <= slen) {
    p_idx = plen;
    while(s[--s_idx] == p[--p_idx]) {
      if(p_idx == 0) {
        return s_idx;
      }
    }
    
    s_idx += (plen - p_idx) +1;
  }

  return -1;
}

int main(void) {
  char s[] = "abacababc";
  char p[] = "abab";
  
  int slen = strlen(s);
  int plen = strlen(p);
  
  cout << "slen = " << slen << endl;
  cout << "plen = " << plen << endl;

  int index = search_reverse(s,slen, p, plen);
  cout << "index=" << index << endl;

  return 0;
}
