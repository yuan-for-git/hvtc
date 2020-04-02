
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

void tiny_printf(char *format, ...)
{
	int i;

	va_list ap;
	va_start(ap, format);
	printf("%p\n", ap);
	for (i = 0; format[i] != '\0'; i++) {
		switch (format[i]) {
			case 's':
				printf("%s ", va_arg(ap, char*));
				printf("%p\n", ap);
				break;
			case 'd':
				printf("%d ", va_arg(ap, int));
				printf("%p\n", ap);
				break;
			default:
				assert(0);
		}
	}
	va_end(ap);
	putchar('\n');
}

int main(void)
{
	int a =0;
	int b =2;
	int c = 3;
	int *d =&a;

	printf("%d",a);
	return 0;
 }