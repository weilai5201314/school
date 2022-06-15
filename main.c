#include <stdio.h>
#include "milk.h"
int main()
{
  int a, b;
  int n = 0;
  int code;
  while (1)
  {
    while ((code = control()) != 6)
    {
      switch (code)
      {
      case 1:
        menu(n);
        n++;
        break;
      case 2:
        revise(n);
        break;
      case 3:
        check(n);
        break;
      case 4:
        delete (n);
        break;
      case 5:
        statistic(n);
        break;
      case 6:
        return 0;
      // default:
      //     break;
      case 7:
        output(n);
        break;
      }
    }
    printf("Thank you.");
    return 0;
  }
  return 0;
}
