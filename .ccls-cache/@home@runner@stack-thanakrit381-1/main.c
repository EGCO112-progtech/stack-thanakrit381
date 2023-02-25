#include "node.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  int i, N, j;
  Stack s;
  s.top = NULL;
  s.size = 0;
  int incorrect = 1;
  int c = 0;
  printf("Checking the parentheses in argv arguments\n");
  for (i = 1; i < argc; i++) {
    char p;
    incorrect = 1;
    for (j = 0; j < strlen(argv[i]); j++)
    {
      switch (argv[i][j]) {
      case '{':
      case '[':
        push(&s, argv[i][j]);
        break;
      case '}':
        p = pop(&s);
        if (p == '3') incorrect = 3;
        else if (p != '{') incorrect = 0;
        break;
      case ']':
        p = pop(&s);
        if (p == '3') incorrect = 3;
        else if (p != '[') incorrect = 0;
        break;
      }
    }
    if (s.size > 0) incorrect = 2;

    if (incorrect == 0) printf("argv %d: incorrect: mismatch\n", i);
    else if (incorrect == 2) printf("argv %d: incorrect: too many open parenthesis\n", i);
    else if (incorrect == 3)printf("argv %d: incorrect: too many closed parenthesis\n", i);
    else printf("argv %d: correct\n", i);
    pop_all(&s);
  }
  pop_all(&s);
  return 0;
}