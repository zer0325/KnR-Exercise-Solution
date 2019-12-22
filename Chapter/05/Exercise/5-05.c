/* Exercise 5-5. Write versions of the library functions strncpy,
 * strncat, and strncmp, which operate on at most the first n
 * characters of their argument strings. For example, strncpy(s,t,n)
 * copies at most n characters of t to s. Full descriptions are in
 * Appendix B. */

/* General idea:

   For strncpy, our return value will be void. We will pad with '\0'
   if t has fewer characters than n.

   For strncat, our return value will be void. Concatenate at most n
   characters of t to s. We will terminate s with '\0'.

   For strncmp, our return value will be int. We are going to compare
   at most n characters of t to s.

*/

/* strncpy: copies at most n characters of string t to s. */
void strncpy(char *s, char *t, int n)
{
	while(n > 0){
		*s++ = (*t == '\0' ? '\0' : *t++);
		--n;
	}
	*s = '\0';
}

/* strncat: copies at most n characters of t at the end of s */
void strncat(char *s, char *t, int n)
{
	while(*s) 	/* find the end of string s */
		s++;

	while(n > 0 && (*s++ = *t++))
		--n;

	*s = '\0';
}

/* strcmp: compares at most n character of t to s. retuns 0, negative
 * or positive number if t is lexicographically equal to, less
 * than, or greater than, s, respectively.
 */

int strncmp(char *s, char *t, int n)
{
	for(; n > 0 && (*s == *t); --n){
		if(*s == '\0')
			return 0;
		s++, t++;
	}
	if(n == 0)
		return 0;
	else
		return *s - *t;
}


