/* Exercise 5-4. Write the function strend(s,t), which returns 1 if
 * the string t occurs at the end of the string s, and zero
 * otherwise. */


/* Genaral idea:

   Since the exercise requires us to return a 1 or a zero, the return
   type of our function will be int.

   This is just a specialized version of strcmp.
   First we find where in s the location of the first character in t.
   And starting from that position we do a string compare. We return
   0 if s is greater than or less than t. We return 1 if s is equal
   to t.


*/

/* strend: */
int strend(char *s, char *t)
{
	for( ; *s != *t; s++) 	/* find the location in s where the first
							   character in t occurs */
		if(*s == '\0')		
			return 0;

	for( ; *s == *t; s++, t++)
		if(*s == '\0')
			return 1;
	return 0;
}
