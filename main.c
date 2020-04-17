#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], Record[]);
void display_menu();

// main function
int main(){

	Record records[MAX_RECORDS];
	char user_input[64] = "";
	while(strcmp(user_input, "99") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[]){

	// TODO: Modify this function as you need

	if(!strcmp(input, "1"))
		readfile_save(records);
  else if(!strcmp(input, "2"))
    add_a_record(records);
	else if(!strcmp(input, "3"))
		find_members(records);
  else if(!strcmp(input, "4"))
		print_all_records(records);	
	else if(!strcmp(input, "5"))
		change_room(records);
  else if(!strcmp(input, "6"))
		delete_student(records);	
  else if(!strcmp(input, "7"))
		plus_minuspoint(records);
  else if(!strcmp(input, "8"))
		display_stats(records);	
  else if(!strcmp(input, "9"))
		student_classification(records);
  else if(!strcmp(input, "10"))
		fm_error(records);
  else if(!strcmp(input, "11"))
		save_report(records);
	else if(!strcmp(input, "99"))
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	// TODO: Modify this function as you need

	printf("\n******************************\n");
	printf(" Management dormitory students \n");
	printf("******************************\n");
	printf(" 1. Add a new membber from txt file\n");
  printf(" 2. Add a new membber from keyboard\n");
  printf(" 3. Search student's information\n");
  printf(" 4. Print all members\n");
  printf(" 5. Change room\n");
  printf(" 6. Delete student\n");
  printf(" 7. Plus minus point\n");
	printf(" 8. Member statistics\n");
  printf(" 9. Calssificate student with entry year\n");
  printf(" 10. Find room number error\n");
  printf(" 11. Save dormitary report\n");
	printf(" 99. Quit\n");
}
