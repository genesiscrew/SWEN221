#include <stdio.h>
#include <stdlib.h>
void smallest(void);
void asterisk(void);
void grade(void);
int swap_ptr(int **d1, int **d2);
int main(void)
{ int p = 11, q = 22;
  int *ptrp = &p, *ptrq = &q;
 // printf("%d/%d/", *ptrp, *ptrp);
  int **ppp = &ptrp, **ppq  = &ptrq;
 // printf("%d %d ", **ppp, **ppq);
  printf("%d %d\n", **ppp, **ppq);
  swap_ptr(ppp,ppq);
  printf("%d %d", **ppp, **ppq);     /* &ptrp, &ptrq passed */
                                   /* to swap_ptr() */
  return 0;
}



int swap_ptr(int **d1, int **d2) {
//printf("%d %d", d1, d2);
  int d3 = **d1;
  *d1 = *d2;
  *d2 = &d3;
  //printf("%d %d", **d1, **d2);
}






