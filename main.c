#include <stdio.h>
#include <stdlib.h>
#include "lib1.h"
#include <string.h>

#define MAX_STUD_NUM 30
#define MAX_STR 60

typedef struct info1 {
    char name[MAX_STR];
	char surname[MAX_STR];
	char patronymic[MAX_STR];
} info1_t;
 
typedef struct var1 {
    char father[MAX_STR];
} var1_t;

typedef struct var2 {    
	char father[MAX_STR];
    char sister[MAX_STR];
} var2_t;

typedef struct var3 {
    char sister[MAX_STR];
} var3_t;

typedef struct info2 {
    char brother[MAX_STR];
    char mother[MAX_STR];
    union additional_info {
        var1_t var1;
        var2_t var2;
        var3_t var3;
	} additional_info;
} info2_t;

void str_input(char *, char *, int );
void help_output();
void command_line(int , char** , info1_t *);
int check_command(int , char **, info1_t *, int );
int info1(info1_t *, int );
int info2(info1_t *, int, char **);
int input_main_info(info1_t *, int );
void output_main_info(info1_t *, int );
int input_addition_info(info1_t *, info2_t *, int , int);
int output_addition_info(info1_t *, info2_t *, int , int);

int main(int argc, char **argv)
{
    info1_t stud[MAX_STUD_NUM];
    command_line(argc, argv, stud);
    return 0;
}

void command_line(int argc, char **argv, info1_t *stud)
{
    int stud_number = 0;
    if(!check_command(argc, argv, stud, stud_number)) {
        puts("\nInvalid input.\n");
        help_output();
        exit(0);
    }
}

int check_command(int argc, char **argv, info1_t *stud, int stud_number)
{
    if (argc > 1 && !strcmp(argv[1],"-h")) {
        help_output();
        exit(0);
    }
    if (argc == 2 && !strcmp(argv[1], "-main")) {
        return info1(stud, stud_number);
    }
    else if (argc == 3) {
        if (!strcmp(argv[1], "-main")) {
            if (!strcmp(argv[2], "-mfb") || !strcmp(argv[2], "-mfbs") || 
                                            !strcmp(argv[2], "-mbs")) {
                return info2(stud, stud_number, argv); 
            } 
        }
    }
    return 0;
}

int info1(info1_t *stud, int stud_number)
{
    stud_number = input_main_info(stud, stud_number);
    output_main_info(stud, stud_number);
    return 1;
}

int info2(info1_t *stud, int stud_number, char **argv)
{   
    int var;
    stud_number = input_main_info(stud, stud_number);
    info2_t all_info[stud_number];
    if (!strcmp(argv[2],"-mfb")) {
        var = input_addition_info(stud, all_info, stud_number, 1);
    }
    else if (!strcmp(argv[2],"-mfbs")) {
        var = input_addition_info(stud, all_info, stud_number, 2);
    }
    else {
        var = input_addition_info(stud, all_info, stud_number, 3);
    }
    if (output_addition_info(stud, all_info, stud_number, var)) {
        puts ("\n                  All is done. \n");
    }
    return 1;
}

int input_main_info(info1_t *stud, int stud_number)
{
    char next[MAX_STR];
    strcpy(next, "next");
    puts ("\n---------- Input of main infomation ----------\n");
    for (stud_number = 0; stud_number < MAX_STUD_NUM && !strcmp(next, "next"); stud_number++) {
        printf ("Information about student number %d) :", stud_number + 1);
        str_input("\nSurname :", stud[stud_number].surname, MAX_STR);
        str_input("Name :", stud[stud_number].name, MAX_STR);
        str_input("Patronymic :", stud[stud_number].patronymic, MAX_STR);
        str_input("\nIf you want to continue input - enter 'next' :", next, MAX_STR);
    }
    return stud_number;
}

void output_main_info(info1_t *stud, int stud_number)
{
    int i;
    puts ("\n---------- Output of main infomation ----------\n");
    for (i = 0; i < stud_number; i++) {
        printf("\n%d.\n surname: %s\n name: %s\n patronymic: %s \n", i + 1,
                stud[i].surname, stud[i].name, stud[i].patronymic);
    }
}

int input_addition_info(info1_t *stud, info2_t *all_info, int stud_number, int var)
{
    int i;
    puts ("\n---------- Input of additional information ----------");
    for (i = 0; i < stud_number; i++) {
        printf ("\nEnter info about %s %s :\n",stud[i].surname, stud[i].name);
        if (var == 1) {
            str_input("\nFather :", all_info[i].additional_info.var1.father, MAX_STR);
        }
        else if (var == 2) {
            str_input("\nSister :", all_info[i].additional_info.var2.sister, MAX_STR);
            str_input("Father :", all_info[i].additional_info.var1.father, MAX_STR);
        }
        else {
            str_input("\nSister :", all_info[i].additional_info.var2.sister, MAX_STR);
        }
        str_input("Mother:", all_info[i].mother, MAX_STR);
        str_input("Brother :", all_info[i].brother, MAX_STR);
    }
    return var ;
}
    
int output_addition_info(info1_t *stud, info2_t *all_info, int stud_number, int var)
{
    int i;
    puts ("\n---------- Output of all information ----------");
    for (i = 0; i < stud_number; i++) {
        printf("\n%d.\n surname: %s\n name: %s\n patronymic: %s\n mother: %s\n brother: %s\n "
                , i + 1, stud[i].surname, stud[i].name, stud[i].patronymic,
                all_info[i].mother, all_info[i].brother);
        if (var == 1) {
            printf ("father: %s\n",all_info[i].additional_info.var1.father );
        }
        else if (var == 2) {
            printf ("father: %s\n",all_info[i].additional_info.var2.father );
            printf ("sister: %s\n",all_info[i].additional_info.var2.sister );
        }
        else {
            printf ("sister: %s\n",all_info[i].additional_info.var3.sister );
        }
    }
    return 1;
}
