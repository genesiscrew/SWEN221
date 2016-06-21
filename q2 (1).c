

#include <stdio.h>
#define SIZE 10

void v_exchange_a(int a[]);
void v_exchange_p(int *p);
int b;
int main(void)

{
int i, x[SIZE];
/* x[] has 10 int elements */
for
 (i=0; i<SIZE; i++) {
    x[i] = i;}
/* assign i to x[i] */
  v_exchange_a(x);
  // printf("%d\n", b);
/* call for value exchange */
for
 (i=0; i<SIZE; i++) {
    printf("x[%d]=%d, &x[%d]=%x\n", i, x[i], i, &x[i]);
    }
    v_exchange_p(x);
/* call for value exchange */
for
 (i=0; i<SIZE; i++)
    printf("x[%d]=%d, &x[%d]=%x\n", i, x[i], i, &x[i]);
return
 0;
}

void v_exchange_a(int a[]) {
int b = a[0];
 //printf("%d", "%s", b, "value of b is");
a[0] = a[SIZE-1];
a[SIZE-1] = b;



}

void v_exchange_p(int *p){
int b = *p;
 //printf("%d", "%s", b, "value of b is");
p = (p+SIZE-1);
*(p+SIZE-1) = b;



}
