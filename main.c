#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//#include<stdio_ext>

typedef struct information_1 {
	char *surname;
	char *name;
	char *patronymic;
} information_1;

typedef struct information_2 {
	char *surname, *name, *patronymic;
	//int input_variant;
	union {
		struct {
			char *mother, *fother, *brother;
		} variant_1;
		struct {
			char *father, *sister, *brother, *mother;
		} variant_2;
		struct {
			char *mother, *brother, *sister;
		} variant_3;
	} variant;
} information_2;

int main () {
	information_1 array_1;
	information_2 array_2;
	printf("%s",array_2.surname);
	puts("\nAnd one week more.\n");
	return 0;
}

