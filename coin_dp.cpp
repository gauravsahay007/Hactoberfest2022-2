#include <stdio.h>
int coins[] = {12,22,13,65};
int n = 4, sum = 84;
 int soln(int sol, int i){
    if(n == 0 || sol > sum || i>=n)
        return 0;
    else if(sol == sum)
        return 1;
      return soln(sol+coins[i],i) + soln(sol,i+1) ;
}
int main()
{
    printf("Total solutions: %d",soln(0,0));
    return 0;
}