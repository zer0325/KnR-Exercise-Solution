/* Exercise 5-13. Write the program tail, which prints the last n lines of its
 * input. By default,  n is 10, let us say, but it can be changed by an optional
 * argument, so that
 *
 *		tail -n
 *
 * prints the last n lines. The program should behave rationally no matter how
 * unreasonable the input or the value of n. Write the program so it makes the
 * best use of available storage; lines should be stored as in the sorting
 * program of Section 5.6, not in a two-dimensional array of fixed size. 
 */

#include <stdio.h>
#define DEFAULT 10

int is_num(char *);

main(int argc, char *argv[])
{
	int n = DEFAULT;
	char *opt;

	while(--argc > 0 && (*++argv)[0] == '-'){	
		opt = &*++argv[0];	
		if(is_num(opt))
			n = atoi(opt);
		else{
			printf("invalid option\n");
			return -1;
		}
	}

	if(argc > 0){
		printf("Usage: tail -n\n");
		return -1;
	}

	printf("debug: n = %d\n", n);
	

	return 0;
}

int is_num(char *s)
{
	int c;

	while((c = *s++) != '\0')
		if(!isdigit(c))
			return 0;

	return 1;
}
