#include <stdio.h>
int main(void)
{
  int a = 0, room = 0;
  int n = 1;
  scanf("%d", &a);

  while(1)
    {
      if(a > 3*n*n-3*n+1)
      {
        n++;
      }

      else
      {
        room = n;
        break;
      }
    }
      
  printf("%d\n", room);
  return 0;
}