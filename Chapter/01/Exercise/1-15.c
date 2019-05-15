/* Exercise 1-15. Rewrite the temperture conversion program
 * of Section 1.2 to use a function for conversion */

#include <stdio.h>

/* print Fahrenheit-Celcius table for fahr = 0, 20, ..., 300 */

int celcius(int fahr);

main()
{
	int fahr;
	int lower, upper, step;

	lower = 0; 		/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */

	fahr = lower;
	while (fahr <= upper) {
		printf("%d\t%d\n", fahr, celcius(fahr));
		fahr = fahr + step;
	}
}

/* celcius: converts temp in fahr to celcius */
int celcius(int fahr)
{
	return 5 * (fahr-32) / 9;
}
