#include <stdio.h>
int main()
{
  int i, k, j, l;
  scanf("%d", &l);
  for(k = 1; k < l+1; k++)
    {
      for(i = 0; i < l-k; i++)
        {
          printf(" ");
        }
      for(j = 0; j < k; j++)
      {
        printf("*");
      }
      printf("\n");
    }
  return 0;
}