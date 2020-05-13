#ifndef _EXTRAS_H_
#define _EXTRAS_H_

#include "record.h"

// function prototypes
void defragment(Record[]);
void display_stats(Record[]);
int load_txt2(Record p[]);
void plus_minuspoint(Record records[]);
void student_classification(Record records[]);
void fm_error(Record records[]);
void search_student_data(Record records[],int choose1, int choose2);
void choose_condition(Record records[]);
#endif
