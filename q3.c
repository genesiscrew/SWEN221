#include <stdio.h>
#include <stdlib.h>
void grade(void);
int main(void)
{ 
 grade();

}

void grade(void){
char g;
int aCount = 0; /* total a grades */
int bCount = 0; /* total b grades */
int cCount = 0; /* total c grades */
int dCount = 0; /* total d grades */
int eCount = 0; /* total e grades */

printf("Enter the grades (enter z when you finish): \n  ");

/* while statement that loops a scan function until the user inputs 'z' */
   while (g != 'z'){
   scanf("%c", &g);
/* switch statement that increments the grade counters */
   switch(toupper(g)) {
      case 'A' :
         aCount++;
         break;
      case 'B' :
      bCount++;
      break;
      case 'C' :
         cCount++;
         break;
      case 'D' :
         cCount++;
         break;
      case 'E' :
        eCount++;
         break;
           case 'Z' :
     printf("End of Input\n" );
         break;
          default :
         printf("Please input a Grade or enter Z to exit \n" );
         break;
   }

   }

   printf( "%s%d\n", "The total number of A grades is: ",  aCount);
   printf( "%s%d\n", "The total number of B grades is: ",  bCount);
   printf( "%s%d\n", "The total number of C grades is: ",  cCount);
   printf( "%s%d\n", "The total number of D grades is: ",  dCount);
   printf( "%s%d\n", "The total number of E grades is: ",  eCount);



}
