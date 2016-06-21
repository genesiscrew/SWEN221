#include <stdio.h>
#include <stdlib.h>


/* Note: Program assumes years are in the same cent
ury. */
struct date {int month, day, year};

int compare_dates(struct date *d1, struct date *d2);

void put_date(struct date *d);
int main(void)
{
  struct date d1, d2;
  printf("Enter first date (mm/dd/yy): ");

scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);
  printf("Enter second d/*ate (mm/dd/yy): ");

scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);
  if (compare_dates(&d1, &d2) < 0) {
    put_date(&d1);
    printf(" is earlier than ");
    put_date(&d2);
    printf("\n");
  } else {
    put_date(&d2);
    printf(" is earlier than ");
    put_date(&d1);
    printf("\n");
  }
  return 0;
}




int compare_dates(struct date *d1, struct date *d2) {
if (d1->year>d2->year)
 {
 return 1;
 }
 else {
 return -1;
 }
 if (d1->month>d2->month)
 {
 return 1;
 }
 else {
 return -1;
 }
  if (d1->day>d2->day)
 {
 return 1;
 }
 else {
 return -1;
 }
  return 0;

}

void put_date(struct date *d)
{
  printf("%d/%d/%.2d", d->month, d->day, d->year);
}






