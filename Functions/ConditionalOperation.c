/*************************************************************************/
/* Known as Conditional Operator or Ternary Operator, it's a single line */
/* simplified expression to write if-else conditional statements 		 */
/*************************************************************************/

// Cases of use

#define MIN(a, b) ((a < b) ? a : b)
/*
	int MIN(int a, int b)
	{
		if(a < b)
			return a;
		else
			return b;
	}
*/

#define MAX(a, b) ((a > b) ? a : b)
/*
	int MAX(int a, int b)
	{
		if(a > b)
			return a;
		else
			return b;
	}
*/

(a>b) ? (c=25) : (c=45);     SAME AS     c = (a>b) ? 25 : 45;
/*
	if(a > b)
		c = 25;
	else
		c = 45;
*/

a = x ? x : y;     SAME AS     a = x ? : y;
/*
	if(x)
		a = x;
	else
		a = y;
*/

(num%2 == 0) ? printf("Even") : printf("Odd");
/*
	if(num%2 == 0)
		printf("Even");
	else
		printf("Odd");
*/

