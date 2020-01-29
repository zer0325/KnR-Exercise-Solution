/* Exercise 5-10. Write the program expr, which evaluates a reverse Polish
 * expression from the command line, where each operator or operand is a
 * separate argument. For example,
 *
 *		expr 2 3 4 + *
 *
 * evaluates 2 x (3 + 4).
 */

/* General idea:

   We are going to use a template the program rpn.c discussed in chapter 4.
   
   The program structure is as follows:

   		while(argument is greater than zero)
			get next operator or operand
				if(number)
					push it
				else if(operator)
					pop operands
					do operation
					push result
				else
					error

		print the result

*/

#include <stdio.h>
#define NUMBER 1

int getop(char *s);
void push(int);
int pop(void);

main(int argc, char *argv[])
{
	int op2, type;
	if(argc == 1){
		printf("Usage: expr num1 num2 [num3 ..] oper1 [oper2 ...]\n");
		return -1;
	}else{
		while(--argc > 0){
			type = getop(*++argv);
			switch(type){
				case NUMBER:
					push(atoi(*argv));
					break;
				case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '-':
					op2 = pop();
					push(pop() - op2);
					break;
				case '/':
					op2 = pop();
					if(op2 != 0)
						push(pop() / op2);
					else{
						printf("error. division by zero\n");
						return -1;
					}
					break;
				default:
					printf("error. invalid argument %s\n", *argv);
					return -1;
			}
		}
	}
	printf("%d\n", pop());

	return 0;
}

int getop(char *s)
{
	int c;
	while(isdigit(c = *s++))
		;
	if(c == '\0')
		return NUMBER;
	else
		return c;
}

#define MAXVAL 100

int sp = 0;			/* stack pointer */
int val[MAXVAL];	/* stack */	

void push(int i)
{
	if(sp > MAXVAL)
		printf("error. stack full\n");
	else
		val[sp++] = i;
}

int pop(void)
{
	if(sp <= 0)
		printf("error. stack empty\n");
	else
		return val[--sp];
}
