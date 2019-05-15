/* Exercise 1-4. Write a program to print the corresponding
 * Celcius to Fahrenheit table. */


#include <stdio.h>

/* print Celcius-Fahrenheit table for celcius = 0, 20, ...,
 * 300: floating-point version */

main()
{
	float fahr, celcius;
	float lower, upper, step;

	lower = 0;		/* lower limit of temperature scale */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */

	printf("============\n");
	printf("%2c %5c\n", 'C', 'F');
	printf("============\n");
	celcius = lower;
	while (celcius <= upper) {
		fahr = (9.0/5.0) * celcius + 32.0;
		printf("%3.0f %6.1f\n", celcius, fahr);
		celcius = celcius + step;
	}
}
