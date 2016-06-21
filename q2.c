#include <stdio.h>
#include <stdlib.h>
void asterisk(void);
int main(void)
{ 
asterisk();


}

void asterisk(void) {
int row;
int col;
/* for loop to print each iteration of stars on a new line */
for (row = 0; row < 4; row++){
printf("\n");
/* nested for loop to print a number of stars dependant on the iteration level of first for loop */
for (col = 0; col < row+1; col++){
 printf("*");
}

}
}
