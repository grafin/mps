#include <stdio.h>

void print_string(char *string)
{
	while (string && *string) {
		putchar((int)*string);
		string++;
	}
	putchar('\n');
}

int main(int argc, char **argv)
{
	printf("%d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}

	return 0;
}
