#include <stdio.h>

void f(int a) {
	printf("In f() a = %d\n", a);
	a = a * 5;
	printf("In f() a = %d\n", a);
}

void g(int *p) {
	printf("In g() *p = %d\n", *p);
	*p = *p * 5;
	printf("In g() *p = %d\n", *p);
}

int main(void)
{
	int a = 5;
	int b = 6;

	printf("In main() a = %d\n", a);
	printf("In main() b = %d\n", b);

	f(a);
	g(&b);

	printf("In main() a = %d\n", a);
	printf("In main() b = %d\n", b);

	return 0;
}
