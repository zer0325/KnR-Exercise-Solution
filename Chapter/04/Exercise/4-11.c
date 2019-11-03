/* Exercise 4-11. Modify getop so that it doesn't need to use
 * ungetch. Hint: use an internal static variable */

/* General Idea:
	
   Since the exercise requires us to use an internal static variable,
   let us look at the getop function and see what is the best
   candidate for a static variable.

   Looking at the original code of the getop function, the best
   candidate for a static variable is the variable c.

   Since the exercise requires to not use the ungetch function, it is
   safe to assume that the getch function will not be utilized in
   this exercise. So we will also change the getch function to
   getchar.

   We know that the functions ungetch and getch are created to
   address the problem of unwanted character being read. 

   We will now focus on the structure of the input to solve the
   exercise.

   Using the original getop function, let us check what is the value
   of the excess character before getop returns to the caller.

   Based on the output of original program, the excess character is
   either a space (32) or an operator.
	
   If the excess character is a space, it is as if we have a leading
   space or blanks. So the original code is still applicable with
   getch changed to getchar.

   If the excess character is an operator, it will just be
   overwritten in the statement, s[0] = c = getchar(), in the first
   while statement. So the original code is still applicable with
   getch changed to getchar.

   So the only modification on the original getop function is the
   changed to static int for the variable c and the changing of the
   getch function to getchar.
	
*/

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	static int c;
	int i;

	while((s[0] = c = getchar()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.')  
		return c;			/* not a number */
	
	i = 0;
	if (isdigit(c))			/* collect integer part */
		while (isdigit(s[++i] = c = getchar()))
			;
	if (c == '.')			/* collect fraction part */
		while (isdigit(s[++i] = c = getchar()))
			;
	s[i] = '\0';
	return NUMBER;
}
