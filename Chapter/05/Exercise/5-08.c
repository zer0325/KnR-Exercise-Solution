/* Exercise 5-8. There is no error checking in day_of_year or
 * month_day. Remedy this defect. */

/* General idea:

   The month_day and day_of_year functions mentioned are functions
   from the book discussed prior to this excercise.

   The day_of_year function converts the month and day into the day
   of the year. The parameters for the function are the month and the
   day. The error check routine involves making sure that the month
   will be less than 12 and the day will be not greater than the
   number of days corresponding to the month. If there is an error,
   the return value will be -1, otherwise return day.

   The month_day function converts the day of the year into the month
   and day. The error check routine involves making sure that the day
   of the year will be less than the total number of days in a year.
   Since the return value of the  function is void, we will send a
   value of -1 for both the month and day if there is an error.

*/
#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

main()
{
	int month, day;

	month_day(1987, 365, &month, &day);
	printf("%d %d\n", month, day);

	printf("%d\n", day_of_year(1987, 2, 29));
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

	/* Error check routine */
	if(month > 12 || day > daytab[leap][month])
		return -1;

	for(i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap, days_in_a_year = 0;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	/* error check routine */
	for(i = 1; i <= 12; i++)
		days_in_a_year += daytab[leap][i];

	if(yearday > days_in_a_year) {
		*pmonth = *pday = -1;
		return;
	}

	for(i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];

	*pmonth = i;
	*pday = yearday;
}
