#include <stdio.h>
int stringlen(const char *s );
/* prototype */
int main(void)
{
char string[ 80 ];
/* create char array */
   printf("Enter a string: ");
   scanf("%[^\n]", string );
   printf( "%d\n", stringlen( string ) );
return
 0;
}

int stringlen(const char *s ) {

int count = 0;

//loops till end of string and increment count each time

for (int i = 0; *(s+i)!= '\0'; i++) {


++count;

}

return count;
}
