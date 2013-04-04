#include <stdio.h>
#include <stdlib.h>
#include "lib1.h"
#include <string.h>

#define MAX_NUMBER_OF_STUDENTS 30
#define MAX_NUMBER_OF_SYMBOLS 60

typedef struct information1 {
    char name[MAX_NUMBER_OF_SYMBOLS];
	char surname[MAX_NUMBER_OF_SYMBOLS];
	char patronymic[MAX_NUMBER_OF_SYMBOLS];
} information1_t;

typedef struct variant1 {
    char brother[MAX_NUMBER_OF_SYMBOLS];
    char mother[MAX_NUMBER_OF_SYMBOLS];
    char father[MAX_NUMBER_OF_SYMBOLS];
} variant1_t;

typedef struct variant2 {
    char brother[MAX_NUMBER_OF_SYMBOLS];
    char mother[MAX_NUMBER_OF_SYMBOLS];
	char father[MAX_NUMBER_OF_SYMBOLS];
    char sister[MAX_NUMBER_OF_SYMBOLS];
} variant2_t;

typedef struct variant3 {
    char brother[MAX_NUMBER_OF_SYMBOLS];
    char mother[MAX_NUMBER_OF_SYMBOLS];
    char sister[MAX_NUMBER_OF_SYMBOLS];
} variant3_t;

typedef struct information2 {
    union additional_information{
		variant1_t variant1;
        variant2_t variant2;
        variant3_t variant3;
	} additional_information;
} information2_t;

/* function from lib1.h */
void input_valid_string_data(char *, char *, int );
int auxiliary_information_for_user(int , char **);

/* functions for working with command line */
void working_with_command_line(int , char** , information1_t *);
int checking_commond_line(int , char **, information1_t *, int );

/* functions for working with information about students */
int working_with_information1(information1_t *, int );
int working_with_information2(information1_t *, int, char **);
int input_of_main_information(information1_t *, int );
void output_of_main_infomation(information1_t *, int );
void information2_variant1(information1_t *, information2_t *, int );
void information2_variant2(information1_t *, information2_t *, int );
void information2_variant3(information1_t *, information2_t *, int );

int main(int argc, char **argv)
{
    information1_t students_main[MAX_NUMBER_OF_STUDENTS];
    working_with_command_line(argc, argv, students_main);
    return 0;
}

void working_with_command_line(int argc, char **argv, information1_t *students_main)
{
    int number_of_students = 0;
    if(!checking_commond_line(argc, argv, students_main, number_of_students)) {
        puts("\nInvalid input.\n"
              "If you want to read manual, enter './bin -h' in command line.\n");
        exit(0);
    }
}

int checking_commond_line(int argc, char **argv, information1_t *students_main, int number_of_students)
{
    if ( auxiliary_information_for_user(argc, argv)) {
        exit(0);
    }
    else if (!strcmp(argv[1],"-1") && !strcmp(argv[2],"-1")) {
       return working_with_information1(students_main, number_of_students);
    }
    else if ((!strcmp(argv[1],"-2") && !strcmp(argv[2],"-1")) ||
             (!strcmp(argv[1],"-2") && !strcmp(argv[2],"-2")) ||
             (!strcmp(argv[1],"-2") && !strcmp(argv[2],"-3")) ) {
       return working_with_information2(students_main, number_of_students, argv);
    }
    return 0;
}

int working_with_information1(information1_t *students_main, int number_of_students)
{
    number_of_students = input_of_main_information(students_main, number_of_students);
    output_of_main_infomation(students_main, number_of_students);
    return 1;
}

int working_with_information2(information1_t *students_main, int number_of_students, char **argv)
{
    number_of_students = input_of_main_information(students_main, number_of_students);
    information2_t students_all[number_of_students];
    if (!strcmp(argv[1],"-2") && !strcmp(argv[2],"-1")) {
        information2_variant1(students_main, students_all, number_of_students);
    }
    else if (!strcmp(argv[2],"-2")) {
        information2_variant2(students_main, students_all, number_of_students);
    }
    else {
        information2_variant3(students_main, students_all, number_of_students);
    }
    return 1;
}

int input_of_main_information(information1_t *students_main, int number_of_students)
{
    char continue_of_input[MAX_NUMBER_OF_SYMBOLS];
    strcpy(continue_of_input, "next");
    puts ("\n---------- Input of main infomation ----------\n");
    for (number_of_students = 0; number_of_students < MAX_NUMBER_OF_STUDENTS && !strcmp(continue_of_input, "next"); number_of_students++) {
        printf ("Information about student number %d) :",number_of_students + 1);
        input_valid_string_data("\nSurname :", students_main[number_of_students].surname, MAX_NUMBER_OF_SYMBOLS);
        input_valid_string_data("Name :", students_main[number_of_students].name, MAX_NUMBER_OF_SYMBOLS);
        input_valid_string_data("Patronymic :", students_main[number_of_students].patronymic, MAX_NUMBER_OF_SYMBOLS);
        input_valid_string_data("\nIf you want to continue input - enter 'next' :", continue_of_input, MAX_NUMBER_OF_SYMBOLS);
    }
    return number_of_students;
}

void output_of_main_infomation(information1_t *students_main, int number_of_students)
{
    int i;
    puts ("\n---------- Output of main infomation ----------\n");
    for (i = 0; i < number_of_students; i++) {
        printf("\n%d.\n surname: %s\n name: %s\n patronymic: %s \n", i + 1,
                students_main[i].surname, students_main[i].name, students_main[i].patronymic);
    }
}

void information2_variant1(information1_t *students_main, information2_t *students_all, int number_of_students)
{
    int i;
    for (i = 0; i < number_of_students; i++) {
        printf ("Information about %s %s",students_main[i].surname, students_main[i].name);
        input_valid_string_data("\nFather :", students_all[i].additional_information.variant1.father, MAX_NUMBER_OF_SYMBOLS);
        input_valid_string_data("Mother:", students_all[i].additional_information.variant1.mother, MAX_NUMBER_OF_SYMBOLS);
        input_valid_string_data("Brother :", students_all[i].additional_information.variant1.brother, MAX_NUMBER_OF_SYMBOLS);
    }
    puts ("---------- Output ----------");
    for (i = 0; i < number_of_students; i++) {
        printf("\n%d.\n surname: %s\n name: %s\n patronymic: %s\n mother: %s\n brother: %s\n father: %s\n", i + 1,
                students_main[i].surname, students_main[i].name, students_main[i].patronymic,
                students_all[i].additional_information.variant1.mother,students_all[i].additional_information.variant1.brother,
                students_all[i].additional_information.variant1.father);
    }
}

void information2_variant2(information1_t *students_main, information2_t *students_all, int number_of_students)
{
    int i;
    for (i = 0; i < number_of_students; i++) {
        printf ("Information about %s %s",students_main[i].surname, students_main[i].name);
        input_valid_string_data("\nFather :", students_all[i].additional_information.variant2.father, MAX_NUMBER_OF_SYMBOLS);
        input_valid_string_data("Mother:", students_all[i].additional_information.variant2.mother, MAX_NUMBER_OF_SYMBOLS);
        input_valid_string_data("Brother :", students_all[i].additional_information.variant2.brother, MAX_NUMBER_OF_SYMBOLS);
        input_valid_string_data("Sister :", students_all[i].additional_information.variant2.sister, MAX_NUMBER_OF_SYMBOLS);
    }
    puts ("---------- Output ----------");
    for (i = 0; i < number_of_students; i++) {
        printf("\n%d.\n surname: %s\n name: %s\n patronymic: %s\n mother: %s\n brother: %s\n father: %s\n sister: %s\n", i + 1,
                students_main[i].surname, students_main[i].name, students_main[i].patronymic,
                students_all[i].additional_information.variant2.mother, students_all[i].additional_information.variant2.brother,
                students_all[i].additional_information.variant2.father, students_all[i].additional_information.variant2.sister);
    }
}

void information2_variant3(information1_t *students_main, information2_t *students_all, int number_of_students)
{
    int i;
    for (i = 0; i < number_of_students; i++) {
        printf ("Information about %s %s",students_main[i].surname, students_main[i].name);
        input_valid_string_data("Mother:", students_all[i].additional_information.variant3.mother, MAX_NUMBER_OF_SYMBOLS);
        input_valid_string_data("Brother :", students_all[i].additional_information.variant3.brother, MAX_NUMBER_OF_SYMBOLS);
        input_valid_string_data("Sister :", students_all[i].additional_information.variant3.sister, MAX_NUMBER_OF_SYMBOLS);
    }
    puts ("---------- Output ----------");
    for (i = 0; i < number_of_students; i++) {
        printf("\n%d.\n surname: %s\n name: %s\n patronymic: %s\n mother: %s\n brother: %s\n sister: %s\n", i + 1,
                students_main[i].surname, students_main[i].name, students_main[i].patronymic,
                students_all[i].additional_information.variant3.mother, students_all[i].additional_information.variant3.brother,
                students_all[i].additional_information.variant3.sister);
    }
}
