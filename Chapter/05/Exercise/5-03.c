/* Exercise 5-3. Write a pointer version of the function strcat that
 * we showed in Chapter 2; strcat(s,t) copies the string t to the end
 * of s.
 */

/* General idea:

   Similar to the strcat version in Chapter 2, we will find first the
   end of the string s, then copy string t to the end of s.

*/


/* strcat: concatenate t to end of s. */
void strcat(char *s, char *t)
{
	while(*s)
		++s;

	while(*s++ = *t++)
		;
}
