#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes
void print_all_records(Record[]);
void add_a_record(Record[]);
int load_txt(Record p[]);
void readfile_save(Record records[]);
void find_members(Record records[]);
void save_report(Record records[]);
void change_room(Record records[]);
void delete_student(Record records[]);
#endif
