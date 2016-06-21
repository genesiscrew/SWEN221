#include <stdio.h>
#include <stdlib.h>
void smallest(void);



int main(void)
{ 
smallest();


}

void smallest(void) {
int count;
int smallest = +32767;
    printf("this program displays the smallest integer from a list of integers that you have entered\n");
    printf("please enter how many integers you will input:\n");
    scanf("%d", &count);
    int value[count-1];
/* for loop to scan and enter each integer into an array */
    for (int i = 0; i <count; i++) { 
        scanf("%d", &value[i]);
                                    }
/* for loop to find the smallest integer in the array */

    for (int i = 0; i <count; i++) {

      if (value[i] < smallest){
          smallest = value[i];
                                   }
                                    }


       printf( "%s%d", "the smallest integer is: ", smallest);
    }








