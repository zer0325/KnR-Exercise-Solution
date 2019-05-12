/* Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw the histogram with the bars horizontal; a
 * vertical orientation is more challenging. */

/* vertical histogram version */


#include <stdio.h>

#define IN	1		/* inside a word */
#define OUT	0		/* outside a word */
#define WORDS 35	/* can be any size. */
					/* I use 35 because the histogram */
					/* for every 35 words fit nicely on my screen */

main()
{
	int c, state, length, i, highest_length;
	int lengths[WORDS];

	for (i = 0; i < WORDS; ++i)
		lengths[i] = 0;

	i = length = highest_length = 0;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				lengths[i] = length;
				++i;
				length = 0;
			}
			state = OUT;
		}
		else if (state == OUT) 
			state = IN;

		if (state == IN)
			++length;

		/* Routine to print the histogram for every 35 words */
		if (i == WORDS) {
			/* Find the highest length to serve as a reference for displaying
			 * the histogram */
			for (i = 0; i < WORDS; ++i) {
				if (lengths[i] > highest_length)
					highest_length = lengths[i];
			}
			/* Actual routine to print the histogram */
			while (highest_length > 0) {
				printf("%2d | ", highest_length);
				for (i = 0; i < WORDS; ++i) {
					if (lengths[i] >= highest_length)
						putchar('|');
					if (lengths[i] < highest_length)
						putchar(' ');
					printf("%2c", ' ');
				}
				printf("\n");
				--highest_length;
			}
			printf("%4c", '|');
			for (i = 0; i < WORDS; ++i)
				printf("---");

			printf("\n");
			printf("%4c", ' ');
			for (i = 0; i < WORDS; ++i)
				printf("%2d ", lengths[i]);

			printf("\n\n");
			/* reinitialize the lenghts array and the variable i */
			for (i = 0; i < WORDS; ++i)
				lengths[i] = 0;
			i = 0;
		}
	}

	/* Routine for the remaining or less than WORDS words */
	/* Find the highest length to serve as a reference */
	for (i = 0; lengths[i] > 0; ++i) {
		if (lengths[i] > highest_length)
			highest_length = lengths[i];
	}
	/* Actual routine to print the histogram */
	while (highest_length > 0) {
		printf("%2d | ", highest_length);
		for (i = 0; lengths[i] > 0; ++i) {
			if (lengths[i] >= highest_length)
				putchar('|');
			if (lengths[i] < highest_length) 
				putchar(' ');
			printf("%2c", ' ');
		}
		printf("\n");
		--highest_length;
	}
	printf("%4c", '|');
	for (i = 0; lengths[i] > 0; ++i)
		printf("---");

	printf("\n");
	printf("%4c", ' ');
	for (i = 0; lengths[i] > 0; ++i)
		printf("%2d ", lengths[i]);

	printf("\n");
}

