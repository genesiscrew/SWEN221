#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4
/* function prototypes */
void minimum(
int grades[][ EXAMS ],
int pupils,
int tests );
void maximum(
int grades[][ EXAMS ],
int pupils,
int tests );
void average(
int grades[][ EXAMS ],
int pupils,
int tests );
void printArray(
int grades[][ EXAMS ],
int pupils,
int tests );
void printMenu(void);
int main(void)
{
/* pointer to a function that takes as parameters a
      two-dimensional array and two integer values
*/
void
 ( *processGrades[ 4 ] )(int [][ EXAMS ], int, int) = { printArray, minimum, maximum, average};
int choice = 0;
/* menu choice */
/* array of student grades */
int studentGrades[ STUDENTS ][ EXAMS ] = { { 77, 68, 86, 73 },
                                              { 96,87, 89, 78 },
                                              { 70,90, 86, 81 } };
/* loop while user does not choose option 4 */
while
 ( choice != 4 ) {
/* display menu and read user's choice */
do
 {
         printMenu();
         scanf("%d", &choice );
      }
while
 ( choice < 0 || choice > 4 );
/* end do...while */
/* pass choice into the array */
/* for you to complete */
 processGrades[choice](studentGrades, STUDENTS, EXAMS);
   }
/* end while */
return
 0;
/* indicate successful termination */
}
/* end main */
/* search for the minimum value */
void minimum(int grades[][ EXAMS ],int pupils, int tests )
{  int i;
/* loop counter */
int lowGrade = 100;
for (i = 0; i < pupils; ++i) {
int j;
for (j = 0; j < tests; ++j) {

if (grades[i][j] < lowGrade) {

lowGrade = grades[i][j]; }

}

}

/* loop counter */

/* set lowGrade to highest possible score */
/* for you to complete */
   printf( "\n\tThe lowest grade is %d\n", lowGrade );
}
/* end function minimum */
/* search for maximum value */
void maximum(int grades[][ EXAMS ], int pupils, int tests )
{
int i;
/* loop counter */
int highGrade = 0;
for (i = 0; i < pupils; ++i) {
int j;
for (j = 0; j < tests; ++j) {

if (grades[i][j]> highGrade) {

highGrade = grades[i][j]; }

}

}
/* set highGrade to lowest possible score */
/* for you to complete */
   printf("\n\tThe highest grade is %d\n", highGrade );
}
/* end function maximum */
/* calculate average */
void
 average( int grades[][ EXAMS ], int pupils,int tests )
{
int i;

/* loop counter */
for (i = 0; i < pupils; ++i) {
int total = 0;
int j;
int sum;
for (j = 0; j < tests; ++j) {
total += grades[i][j];


}
total = total/tests;
 printf( "%s%d%s%d\n","the average for student ",i+1," is ", total );
}
/* loop counter */

/* sum of all grades */
   printf( "\n");
/* for you to complete */
}
/* end function average */
/* print the contents of the array */
void printArray(int grades[][ EXAMS ], int pupils, int tests )
{
printf( "\n\t   [ 0 ]  [ 1 ]  [ 2 ]  [ 3 ]");
printf( "\n");
int i;
for (i = 0; i < pupils; ++i)  {
int j;
int count = 0;
for (j = 0; j < tests; ++j)  {
count++;
if (count < 4) {
printf( "\t     %d", grades[i][j]  );
}
else {
printf( "    %d\n", grades[i][j]  );
}


}

}
/* loop counter */
int j;
/* loop counter */

/* for you to complete */

}
/* end function printArray */
/* display the menu */
void printMenu(void)
{
   printf("\n\tEnter a choice:\n""\t  0  Print the array of grades\n""\t  1  Find the minimum grade\n"
   "\t  2  Find the maximum grade\n"
    "\t  3  Print the average on all"" tests for each student\n"
   "\t  4  End program\n"
"\t? "
 );
}
/* end function printMenu */

