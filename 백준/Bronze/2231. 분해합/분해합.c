#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n;
  int total = 0, m = 1, a = 1;
  scanf("%d", &n);
  while(n >= m)
    {
      total += m;
      while(m != 0)
        {
          total += m%10;
          m = m/10;
        }
      if(total == n)
      {
        printf("%d\n", a);
        break;
      }
      a++;
      m = a;
      total = 0;
    }
  if(n <= m)
  {
    printf("%d\n", 0);
  }
  return 0;
}