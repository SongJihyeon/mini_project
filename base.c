#include <stdio.h>
#include "base.h"
#include <string.h> 

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
void print_all_records(Record records[]){
  //print records in members.txt(members.txt has all data)
  FILE *file;
  file = fopen("members.txt","r");
  int n;
  n = load_txt(records);
  for(int i=0; i< n; i++){
    printf("%d %s [%c] %d %d %d\n", (i+1), records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
  }
}

// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
void add_a_record(Record records[]){
  //Create a new record from the standard input (keyboard)
  //load members.txt and add record from keyboard input.
  int count;
  FILE *file;
  file = fopen("members.txt","a");
  count = load_txt(records); //load members.txt and count the line
  printf("name sex(f or m) entry_year room_number minus_point\n");
  scanf("%s %c %d %d %d", records[count].name, &(records[count].fm), &(records[count].entry), &(records[count].room), &(records[count].point));
  getchar(); //scanf's last '\n' delete
  fprintf(file, "%s %c  %d  %d  %d\n", records[count].name, records[count].fm, records[count].entry, records[count].room, records[count].point); //write input records in members.txt
  
  fclose(file);
}


// TODO: Add more functions to fulfill the requirements
int load_txt(Record p[]){
  //load data from members.txt file and count number of lines in members.txt
  //Read the entire data from filesystem(members.txt contains all records)
	FILE *file;
	int n=0;
	file = fopen("members.txt","rt");
	while(!feof(file)){
		fscanf(file,"%s %c %d %d %d",p[n].name,&(p[n].fm),&(p[n].entry),&(p[n].room),&(p[n].point));
    //read members.txt's data and save it to record
		n++;
	}
  n= n-1;
	fclose(file);
	return n;
}

void readfile_save(Record p[]){
  //create data record from data file.
  //open two files(load.txt, members.txt) read load.txt's context and save it in members.txt
  FILE *file;
  file = fopen("load.txt", "r");
  FILE *file1;
  file1 = fopen("members.txt", "a");
  int n=load_txt(p);
  int i = n;
  while(!feof(file)){
    fscanf(file, "%s %c %d %d %d",p[n].name,&(p[n].fm),&(p[n].entry),&(p[n].room),&(p[n].point));
    //scan load.txt's content and save it to record.
    fprintf(file1, "%s %c %d %d %d\n",p[n].name,p[n].fm,p[n].entry,p[n].room,p[n].point);
    //append load.txt's data to members.txt
    n++;
  }
  fclose(file);
  fclose(file1);
}

void find_members(Record records[]){
  //search name with user's input and print that student's informations
  //According to user specified conditions, print a record, multiple or all records to the standard output (monitor)
  int n;
  n = load_txt(records)+1;
	int i;
	char name[20];
	printf("Input student's name(over two character): ");
	scanf("%s", name);
  //scan student's name(over two character) from the user
  getchar();
  printf("NO Name Sex Entry Room_number minus_point\n");
  for(i=0; i<n; i++){
    if(strstr(records[i].name,name)){
      printf("%d %s [%c] %d %d %d\n", i+1, records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
      //print if user input is in studnet's name in records
    }
  }
}

void save_report(Record records[]){
  //write a report in txt file
  //Export the entire data in a report format as a .txt file
  int n;
  n = load_txt(records);
	FILE* file1;
	file1 = fopen("report.txt","wt");
	int i;
	int f=0, m=0;
  fprintf(file1, "[Dormitory Student Report]\n");
  for(i=0; i<n; i++){
    if(records[i].fm =='F'){ //if student is female,
      f++;
    }
    else{ //student is male
      m++;
    }
  }
  fprintf(file1, "Students number in dormitory : %d (male: %d, female: %d)\n",n, m,f);
  //print all student's number, male students number, female students number
  for(i=0; i<n; i++){
    fprintf(file1,"======================\n");
    fprintf(file1,"Name: %s\n", records[i].name);
    fprintf(file1,"Sex: %c\n", records[i].fm);
    fprintf(file1,"Entry year: %d\n", records[i].entry);
    fprintf(file1,"Room number: %d\n", records[i].room);
    fprintf(file1,"Minus point: %d\n", records[i].point);
    fprintf(file1,"======================\n\n");
  } //write student's data to report.txt
	fclose(file1);
}	

void change_room(Record records[]){
    //change student's room
    //Update a specific field of a record, multiple or all records (according to user specified conditions)
    char name[20];
    Record *rp;
    int i, found=0, newroom;
    int n = load_txt(records);
    FILE *file;
    file = fopen("members.txt","w");
    
    //find student
    printf("Student name? : ");
    scanf("%s", name);
    getchar();
    for(i=0;i<n;i++){
      if(strcmp(records[i].name,name)==0){
        found=1;
        rp=&records[i];
        break;
      }
    }
    //if student is in list, print student's information and change room number
    if(found==1){
      printf("Name Sex Entry Room Point\n");
      printf("%s [%c] %d %d %d\n", rp->name, rp->fm, rp->entry, rp->room, rp->point);

      printf("Enter a new room number : ");
      scanf("%d", &newroom); 
      getchar();
      rp->room = newroom;
      for(i=0; i<n; i++){
        fprintf(file, "%s %c %d %d %d\n",records[i].name,records[i].fm,records[i].entry,records[i].room,records[i].point);
      }
      printf("complete!\n");
    }
    else{
      printf("This student is not here\n");
    }
    fclose(file);
}

void delete_student(Record records[]){
  //find student name and delete all of his/her Record.
  //Delete a record, multiple or all records (according to user specified conditions)
  char name[20];
  Record *rp, temp;
  int i, found=0;
  int n = load_txt(records);
  FILE *file;

  //find student
  printf("Student name? : ");
  scanf("%s", name);
  getchar();
  for(i=0;i<n;i++){
    if(strcmp(records[i].name,name)==0){
      found=1;
      rp=&records[i];
      break;
    }
  }
  //if student is in list, remove his/her information
  if(found==1){
    rp->name[0] = '\0';
    rp->fm = '\0';
    rp->entry = '\0';
    rp->room = '\0';
    rp->point = '\0';
    //swap deleted records to last records and save to file members.txt  
    temp = *rp;
    *rp = records[n-1];
    records[n-1] = temp;
    i=0;
    file = fopen("members.txt","w");
    while(records[i].fm != '\0'){
      fprintf(file, "%s %c %d %d %d\n",records[i].name,records[i].fm,records[i].entry,records[i].room,records[i].point);
      i++;
    }
    printf("complete!\n");
  }
  else{
    printf("This student is not here\n");
  }
  fclose(file);
}
