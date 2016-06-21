#include <stdio.h>
int stringcmp(const char *s1, const char *s2 );
/* prototype */
int main(void)
{
char string1[ 80 ];
/* create a string */
char string2[ 80 ];
/* create another string */
  printf( "Enter two strings: ");
  scanf("%s%s", string1 , string2 );
  printf("The result is %d\n", stringcmp( string1, string2 ) );
return
 0;
}
int stringcmp(const char *s1, const char *s2 ) {


int match;
int count1 = 0;
int count2 = 0;
// loops through each char in first string and compares to second string
for (int i = 0; *(s1+i)!= '\0'; i++) {

// increments count when there is mismatch
if (*(s1+i) != *(s2+i)) {


++count1;


}

}

// loops through each char in second string and compares to first string
for (int i = 0; *(s2+i)!= '\0'; i++) {

// increments count when there is mismatch
if (*(s1+i) != *(s2+i)) {


++count2;


}

}

// returns 0 if one or both counters is more than zero
if (count1 > 0 || count2 > 0) {
return 0;

}
else {

return 1;}


}
