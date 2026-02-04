#include <stdio.h>
int main()
{
    int k, i, j; //i, k가 줄이고, j가 별 개수로 하자/
    scanf("%d", &k);

    for(i = 1; i < k+1; i++)
      {
        for(j = 0; j < i; j++)
          {
            printf("*");
          }
        printf("\n");
        j = 0;
      }
  
  
    return 0;
}