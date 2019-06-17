/* Exercise 3-1. Our binary search makes two tests inside the loop,
 * when one would suffice (at the price of more tests outside). Write
 * a version with only one test inside the loop and measure the
 * difference in run-time */

#include <stdio.h>

int binsearch(int x, int v[], int n);

main()
{
	int num[10] = {0, 0, 1, 3, 5, 9, 11, 15, 18, 200};

	printf("%d\n", binsearch(100, num, 10));

	return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch (int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;

	mid = 0;
	while (low <= high && x != v[mid] ) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (x == v[mid]) 
		return mid;
	else
		return -1;		

}

/* To answer the second question, which is to measure the difference
 * in run time. The runtime can be measured using the time command in
 * linux. The syntax will be:
 *
 *		$ time ./a.out
 *
 * When measured using the binsearch function from this exercise the
 * output is:
 *
 *	real: 0m0.005s
 *	user: 0m0.000s
 *	sys:  0m0.005s
 *
 * when measured using the original binsearch funtion the output is:
 *
 *	real: 0m0.004s
 *	user: 0m0.000s
 *	sys:  0m0.004s
 *
 */
