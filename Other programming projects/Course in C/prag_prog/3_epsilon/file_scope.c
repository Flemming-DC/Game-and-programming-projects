#include <stdio.h>

int N=1000;
/* This N is in file-scope, it is visible to all functions inside
this file (unless shadowed). */

void hello(void) /* also file scope */
{
	const char greeting[]="Hello, I have been called %i times.";
	/* a const variable cannot be changed */

	/* Variable 'greeting' is in function-scope, it is visible
	only inside function hello; it gets deleted when hello exits; */

	static int number_of_calls=0;
	/* a static variable survives between function calls */
	number_of_calls++;

	printf(greeting,number_of_calls);
	printf(" N=%i\n",N); /* prints N from the file scope. */
}

int main(void)
{
	int N=10;
	/* This N is in function-scope and shadows the file-scope N. This
	N replaces the file-scope N inside main. */

	printf("N=%i\n",N);  /* prints N from the function-scope. */

	hello(); /* hello prints N from the file-scope. */
	hello();
	hello();

	for(int N=1;N<10;N++)
	/* This N is in block-scope, it replaces (shadows) N from the
	function scope, it is only visible inside the block, it gets
	deleted when block exits */

	{
		printf("%i\n",N); /* prints the block-scope N */
	}
return 0;
}
