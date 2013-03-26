#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

/*file *in = stdin ,затем fopen("Myfile","r")
  fgets (buf,size,in);*/

/*typedef struct information_1 {
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
} information_2;*/
/* enum variant_of_union {"variant_1","variant_2","variant_3"}; */

typedef struct student {
    char *surname;
    char *name;
    char *patronymic;
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
} student;

char *fun_check_input();
void fun_students_quantity(int *);
void fun_select_input(student *, int);
void fun_input_information_1(student *, int);
void fun_output_main_information(student *, int);
void fun_input_aditional_information(student *, int);

int main()
{
    int number_of_students = 0;
    puts("\n---------- Input ----------");
    fun_students_quantity(&number_of_students);
    student array[number_of_students];
    fun_select_input(array, number_of_students);
    puts("\nAnd one week more.\n");
    return 0;
}

char *fun_check_input()    /* function for checking input infomation (srting).*/
{                               
    char *input_text;
    input_text = (char *) malloc(30 * sizeof(char));
    do {
        __fpurge(stdin);
        fgets(input_text, 30, stdin);
        if (input_text[0] == '\n' || input_text[0] == '0'
            || input_text[0] == '9') {
            puts("Invalid input, try again.");
            continue;
        } else if (input_text[0] > '0' && input_text[0] < '9') {
            puts("Invalid input, try again.");
            continue;
        } else
            break;
    } while (1);
    return input_text;
}

void fun_students_quantity(int *number_of_students)    /* function for input number of students.*/
{                                
    puts("\nEnter, please,  number of students:");
    while (!scanf("%d", &*number_of_students) || *number_of_students < 1) {    /* n - number of students. */
        __fpurge(stdin);
        puts("Invalid input, try again.");
    }
}

void fun_select_input(student * array, int number_of_students)    /* select input. */
{                               
    int check = 0, select;
    puts("\nSelect type of input (enter 1 or 2):\n1)Only surname, name, patronymic.\n2)Surname, name, patronymic and information about family.");
    while (check == 0) {
        scanf("%d", &select);
        switch (select) {
        case 1:
            fun_input_main_information(array, number_of_students);
            check = 1;
            break;
        case 2:
            /* fun_exams_filling (array); */
            check = 1;
            break;
        default:
            puts("Invalid input, try again.");
        }
    }
}

void fun_select_output(student * array, int number_of_students)    /* select input. */
{                               
    int check = 0, select;
    puts("\nSelect type of output (enter 1 or 2):\n1)Only surname, name, patronymic.\n");
    puts("2)Surname, name, patronymic and information about family.");
    while (check == 0) {
        scanf("%d", &select);
        switch (select) {
        case 1:
            fun_output_main_information(array, number_of_students);
            check = 1;
            break;
        case 2:
            /* fun_exams_filling (array); */
            check = 1;
            break;
        default:
            puts("Invalid input, try again.");
        }
    }
}

void fun_input_main_information(student * array, int number_of_students)
{
    for (int i = 0; i < number_of_students; i++) {
        printf("Enter, please, information about student number %d)",
               i + 1);
        puts("\nsurname: ");
        array[i].surname = fun_check_input();
        puts("name: ");
        array[i].name = fun_check_input();
        puts("patronymic: ");
        array[i].patronymic = fun_check_input();
    }
}

void fun_output_main_information(student * array, int number_of_students)
{
    puts("\n---------- Output ----------");
    for (int i = 0; i < number_of_students; i++) {
        printf("Information about student number %d)", i + 1);
        printf("\nsurname: %s", array[i].surname);
        printf("name: %s", array[i].name);
        printf("patronymic: %s", array[i].patronymic);
    }
}
