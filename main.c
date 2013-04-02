#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

typedef struct information_1 {
	char *surname;
	char *name;
	char *patronymic;
} information_1;

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
} student_t;

char *fun_check_input();
void fun_students_quantity(int *);

int main()
{
	int max_number_of_students = 30;
	student_t array[max_number_of_students];
    int number_of_students;
    puts("\n---------- Input ----------");
    fun_students_quantity(&number_of_students);
    fun_select_input(array, number_of_students);
    puts("\nAnd one week more.\n");
    return 0;
}

/* -h */
void auxiliary_information_for_user(int argc, char **argv)
{
    if (argc > 1 && !strcmp(argv[1], "-h")) {
        puts("\n=====================================================================\n"
             "MANUAL:\n\n"
             "1)Select variant of input of exams:\n"
             "- automatic input.\n"
             "- manual input of exams.\n"
             "2)Enter information about students:\n"
             "- name.\n"
             "- sername.\n"
             "- patronymic.\n"
             "- marks.\n"
             "3)Enter number of semester, for output information about this semester.\n"
             "                      >>And output of main task<< \n"
             "=====================================================================\n");
        exit(0);
    }
}

char *fun_check_input()    /* function for checking input infomation (srting).*/
{                               
    char *input_text;
    input_text = (char *) malloc( sizeof(char));
    do {
        __fpurge(stdin);
        fgets(input_text, 30, stdin);
        if (input_text[0] == '\n' || input_text[0] == ' ') {
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

void fun_select_input(student_t * array, int number_of_students)    /* select input. */
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

void fun_select_output(student_t * array, int number_of_students)    /* select input. */
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

void fun_input_main_information(student_t * array, int number_of_students)
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

void fun_output_main_information(student_t * array, int number_of_students)
{
    puts("\n---------- Output ----------");
    for (int i = 0; i < number_of_students; i++) {
        printf("Information about student number %d)", i + 1);
        printf("\nsurname: %s", array[i].surname);
        printf("name: %s", array[i].name);
        printf("patronymic: %s", array[i].patronymic);
    }
}
