

#include <time.h>
#include <stdio.h>

unsigned int sum1( unsigned int from, unsigned int to); /* recursion */
unsigned int sum;
unsigned int count;
unsigned int sum2( unsigned int from, unsigned int to); /* iteration */
unsigned int sum3(unsigned int from, unsigned int to); /* algorithm */

int main(void)

{
unsigned int s;
//unsigned int sum;
unsigned from, to;
double t1, t2;

    printf("Enter the fist integer:");
    scanf("%d", &from);
    printf("Enter the second integer:");
    scanf("%d", &to);
    t1 = clock();
    s = sum1(from, to);
    t2 = clock();
    printf("sum1=%d, %fseconds.\n", s, (t2-t1)/CLOCKS_PER_SEC);
    t1 = clock();
    s = sum2(from, to);
    t2 = clock();
    printf("sum2=%d, %fseconds.\n", s, (t2-t1)/CLOCKS_PER_SEC);
    t1 = clock();
    s = sum3(from, to);
   t2 = clock();
    printf("sum3=%d, %fseconds.\n", s, (t2-t1)/CLOCKS_PER_SEC);
return 0;
}

unsigned int sum1(unsigned int from, unsigned int to) {

if (from <= to) {
sum = from + sum1(from+1, to);
}

return sum;


}

unsigned int sum2( unsigned int from, unsigned int to) {

while (from <= to) {
from = from+1;
sum = sum +from;

}

return sum;
}
unsigned int sum3( unsigned int from, unsigned int to) {

to = ((to*to)+to)/2;
from =(from-1);
sum = to-from;

return sum;


}


