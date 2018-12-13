#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * KMP算法网址:https://blog.csdn.net/v_july_v/article/details/7041827
 */

void GetNext(char *pattern, int next[])
{
  next[0] = -1;
  int pattern_len = strlen(pattern);

  int k = -1; int j = 0;
  while(j < pattern_len - 1) {
    
    if (k == -1 || pattern[k] == pattern[j]) {
      ++k; ++j;
      
      if (pattern[k] != pattern[j]) {
        next[j] = k;
      
      } else {
        next[j] = next[k];
      
      }
    } else {

      k = next[k];
    }

  }

}

int KmpSearch(char *text, char *pattern)
{
  int text_len    = strlen(text);
  int pattern_len = strlen(pattern);

  int i = 0, j = 0;
  int next[pattern_len];

  memset(next, 0, pattern_len);

  GetNext(pattern, next);
  while(i < text_len && j < pattern_len) {

    if(j == -1 || text[i] == pattern[j]) {
      i++; j++;
    } else {
      j = next[j];
    }

  }

  if (j == pattern_len) {
    return i - j;
  }

  return -1;
}

int main(void)
{
  char text[]    = "abacababc";
  char pattern[] = "abab";
  
  int index = KmpSearch(text, pattern);
  printf("index of pattern in text:[%d]\n", index);

  return 0;
}
