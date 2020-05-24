/* Exercise 4-6. Add commands for handling variables. (It's easey to
 * provide twenty-six variables with single-letter names.) Add a
 * variable for the most recently printed value. */

/* General idea:

   We can use two possible commands that handles variables. A command
   to set the value of the variable and the other is to show the
   value of the variable. We can assign the equal sign (=) as the
   command to set the value of the variable. And the  question mark
   (?) to view the value of the variable.

   When an '=' sign is received, we set the variable to the value at
   the top of the stack. When a '?' is received, we push the value of
   the variable to the top of the stack.

   main() 
   {
   		...
			case '=':
				value = pop();
				variables[var - 'A'] = value;
				push(value);
				break;
			case  '?:
				push(variables[var - 'A']);
				break;
		...
	}

   This procedure will be added as a case label of the switch
   statement in the main function.

   The variable will be  equal to s[0].
   These will be set if a VARIABLE signal is received by the main
   function from the getop function. A VARIABLE signal is sent if the
   length of the string, s, is 1 and its content is an upper case
   letter. 

   main()
   {
   			...
			case VARIABLE:
				var = s[0];
				break;
			...
	}

	int getop(char s[])
	{
			...
			if(i == 1 && isupper(s[0]))
				return VARIABLE;
			...
	}

   Note that the variables can be used as operands in an operation.
   We need to push the value of the variables into the stack whenever
   ta variable is received.

   main()
   {
   			...
			case VARIABLE:
				var = s[0];
				push(variables[var - 'A']);
				break;
			...
	}

	Since the old  value of the  variable is pushed onto the stack,
	we need to modify the case label for '=' by removing first the
	old value from the stack before assigning the correct value to
	the variable. Modifying the case label for '=' sign:

	main()
	{  	
			...
			case '=':
				pop();
				value = pop();
				variables[var - 'A'] = value;
				push(value);
				break;
			...
	}

	Second requirement: Add a variable for the most recently printed
	value.

	The most recently printed value, is  the value at the top of the
	stack which is being popped. This is value is printed whenever a
	newline character is received. We need to save first the value at
	the top of the stack, before it is being popped. To add a
	variable for the saved value, we just need to use the set command
	or the equal sign. This code will be added in the case label for
	'\n' character.

	main()
    {
			....
			case '\n':
				dup();
				printf("\t%.8g\n", pop());
				break;
			...
	}
*/

#include <stdio.h>
#include <stdlib.h>		/* for atof() */
#include <math.h>

#define MAXOP	100		/* max size of operand or operator */
#define NUMBER	'0'		/* signal that a number was found */
#define OPERATOR	'1' /* signal that an operator was found */
#define COMMAND		'2'	/* signal that a command was found */
#define MATH_OPER	'3'	/* signal that a math operator was found */
#define VARIABLE		'4'	/* signal that a variable was found */

int getop(char []);
void push(double);
double pop(void);
void print(void);
void dup(void);
void swap(void);
void clear(void);

/* reverse Polish Calculator */
main()
{
	int type;
	double op2, op1;
	char s[MAXOP];
	double variables[26] = {0.0};
	char var;
	int  strindex(char s[], char t[]);

	while ((type = getop(s)) != EOF) {
		switch(type) {
			case NUMBER:
				push(atof(s));
				break;
			case OPERATOR:
				switch(s[0]) {
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
					if(op2 != 0.0)
						push(pop() / op2);
					else
						printf("error: zero divisor\n");
					break;
				case '%':
					op2 = pop();
					if(op2 != 0.0)
						push((int)pop() % (int)op2);
					else
						printf("error: zero divisor\n");
					break;
				case '=':
					pop();
					push(variables[var - 'A'] = pop());
					break;
				case  '?':
					push(variables[var - 'A']);
					break;
				}
				break;
			case COMMAND:
				switch(s[0]) {
					case 'p':
					print();
					break;
				case 'd':
					dup();
					break;
				case 's':
					swap();
					break;
				case 'c':
					clear();
					break;
				}
				break;
			case MATH_OPER:
				if(strindex(s, "sin") == 0) 
					push(sin(pop()));
				else if(strindex(s, "exp") == 0) 
					push(exp(pop()));
				else if(strindex(s, "pow") == 0) {
					op2 = pop(); 	/* y in the x^y */
					op1 = pop();	/* x in the x^y */
					push(pow(op1, op2));
				}
				break;
			case  VARIABLE:
				var = s[0];
				push(variables[var - 'A']);
				break;
			case '\n':
				dup();
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

#define MAXVAL	100		/* maximum depth of value stack */

int sp = 0;				/* next free stack position */
double val[MAXVAL];		/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, cant push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
/* print: prints the top of the stack without popping */
void print(void)
{
	if(sp > 0)
		printf("\t%.8g\n", val[sp - 1]);
}
/* dup: duplicates the top of the stack */
void dup(void)
{
	if(sp > 0 && sp < MAXVAL) 
		push(val[sp - 1]);
}
/* swap: swaps the top two elements of the stack */
void swap(void)
{
	double first, second;
	if(sp > 1 && sp <= MAXVAL) {
		first = pop(), second = pop();
		push(first), push(second);
	}
}
/* clear: clears the stack */
void clear(void)
{
	sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c, op, sign = 0;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if(c == '\n')
		return c;

	i = 0;

	/* collect all the characters */
	while(isalnum(s[++i] = c = getch()) || c == '.')
		;

	s[i] = '\0';
	if(c != EOF)
		ungetch(c);

	/* determine if it is a NUMBER, a COMMAND, an OPERATOR, or a
	 * MATH_OPER */
	if(i == 1 && !isalnum(s[0]))
			return OPERATOR;
	else if(i == 1 && islower(s[0]))
		return COMMAND;
	else if(i == 1 && isupper(s[0]))
		return VARIABLE;
	else if(i > 1 &&  isalpha(s[0]))
		return MATH_OPER;
	else
		return NUMBER;

}

#define BUFSIZE	100

char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;			/* next free position in buf */

int getch(void)			/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}







