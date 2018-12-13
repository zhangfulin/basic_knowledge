#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int violence_search(char *text, char *pattern, int pos)
{
  if(text == NULL || pattern == NULL) {
    return -1;
  }

  int text_len    = strlen(text);
  int pattern_len = strlen(pattern);
  int i = pos; int j = 0;

  while(i < text_len && j < pattern_len) {
    if(text[i] == pattern[j]) {
      i++; j++;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }

  if(j == pattern_len) {
    return i - j;
  } else {
    return 0;
  }
}

int main(void)
{
  char text[]    = "abcdabce";
  char pattern[] = "bce";
  
  int index = violence_search(text, pattern, 0);

  printf("match index:%d\n", index);

  return 0;
}
