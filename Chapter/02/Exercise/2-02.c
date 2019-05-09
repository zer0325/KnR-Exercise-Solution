/* Exercise 2-2. Write a loop equivalent to the for loop above without using &&
 * or ||. */

/* The for loop mentioned is:

   for (i = 0; i<lim-1 && (c=getchar())!='\n' && c!=EOF; ++i)
   		s[i] = c;


	General statement:

  		if (cond1 && cond2)
  			expr1
		else
			expr2

	Equivalent if-else statement

		if (cond1)
			if (cond2)
				expr1
			else
				expr2
		else
			expr2
*/

#include <stdio.h>
#define lim 1000

main()
{
	int i, c;
	char s[lim];
/*
	for (i = 0; i<lim-1 && (c=getchar())!='\n' && c!=EOF; ++i)
		s[i] = c;
*/

	/* The actual equivalent of the for loop */
	int out_of_loop;
	
	i = 0;
	out_of_loop = 0;
	while(!out_of_loop) {
		if (i < lim - 1) 
			if ((c = getchar()) != '\n')
				if (c != EOF) {
					s[i] = c;
					++i;
				} else
					out_of_loop = 1;
			else
				out_of_loop = 1;
		else 
			out_of_loop = 1;
	}
	/* This is to test if the two loops are the same */
	/* To test, comment the equivalent loop and uncomment the for loop above */
	s[i] = '\0';
	printf("%d: %s", i, s);

	return 0;
}
