/* Execise 5-9. Rewrite the routines day_of_year and month_day with
 * pointers instead of indexing .*/

/* General idea:

   The relevant expresion where we will convert array indexing to
   pointer addressing is the expression:

   		daytab[leap][i];

	As per Appendix A7.3.1, the exprssion E1[E2] is by definition
	identical to *((E1) + (E2)).

	In the expression E1[E2][E3];

		E1[E2][E3] = *(E1[E2] + E3)
				   = *(*(E1+E2) + E3)

	From this;

		daytab[leap][i] = *(*(daytab + leap) + i)
*/
#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

main()
{
	int month, day; 
	month_day(1988, 60, &month, &day);	

	printf("%d %d\n", month, day);
	return 0;
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 31, 31}
};

/* day_of_year: set day of year form month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for(i = 1; i < month; i++)
		day += *(*(daytab + leap) + i);
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for(i = 1; yearday > *(*(daytab + leap) + i); i++)
		yearday -= *(*(daytab + leap) + i);

	*pmonth = i;
	*pday = yearday;
}

