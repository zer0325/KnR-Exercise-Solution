/* Exercise 4-7. Write a routine ungets(s) that will push back an
 * entire string onto the input. Should ungets know about buf and
 * bufp, or it should just use ungetch? */

/* General idea:

   void ungets(char s[])
   {
		int i;

		i = 0;
		while(s[i] != '\0') {
			if(bufp > BUFSIZE)
				printf("error\n");
			else
				buf[bufp++] = s[i++];
		}
    }
   
   modified version..

   void ungets(char s[])
   {
		int i;

		i = 0;
		while(s[i] != '\0') 
			ungetch(s[i++]);
					
    }

	From this, ungets(s) should just use the ungetch function and it
	does not have to know buf and  bufp.

*/

void ungets(char s[])
{
	int i;

	i = 0;
	while(s[i] != '\0')
		ungetch(s[i++]);
	
	ungetch(s[i]);		/* push back the NULL character */
}

