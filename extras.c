#include <stdio.h>
#include "extras.h"
#include <string.h>

// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Leave a brief information about the function
void defragment(Record records[]){
  //I wrote this function in delete.
}

void display_stats(Record records[]){
  //sort with students name
  //Arrange (sort) the order of data records based on user specified conditions
  FILE *file;
	int n = load_txt2(records);
  Record temp;
  for(int i =0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(strcmp(records[i].name,records[j].name)>=0){
        temp = records[i];
        records[i] = records[j];
        records[j] = temp;
      }
    }
  }
  //write all records in members.txt file
  file = fopen("members.txt","w");
  for(int i=0; i<n; i++){
    fprintf(file, "%s %c %d %d %d\n",records[i].name,records[i].fm,records[i].entry,records[i].room,records[i].point);
  }
  fclose(file);
}


// TODO: Add more functions to fulfill the optional requirements
int load_txt2(Record p[]){
  //load data from members.txt file and count number of lines in members.txt
  //return student number
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

void plus_minuspoint(Record records[]){
  //find student with student name, choose the reason of minus point and plus the students minus point.
  Record *rp;
  FILE *file;
  int n = load_txt2(records);
  char name[20];
  int reason;
  printf("Student name? : ");
  scanf("%s", name);
  getchar();
  for(int i=0;i<n;i++){
    if(strcmp(records[i].name,name)==0){
      rp=&records[i];
      printf("Choose reason(1: Stay out overnight, 2: no show a dormitory roll call) : ");
      scanf("%d", &reason);
      getchar();
      if(reason== 1){
        rp->point++;
      }
      else if(reason == 2){
        rp->point += 2;
      }
      else{
        printf("There's no reason about this number.");
      }
      break;
    }
  }
  file = fopen("members.txt","w");
  for(int i=0; i<n; i++){
    fprintf(file, "%s %c %d %d %d\n",records[i].name,records[i].fm,records[i].entry,records[i].room,records[i].point);
  }
  fclose(file);
}

void student_classification(Record records[]){
  //classificate student with their entry year
  //print user's input year's student's name
  int n = load_txt2(records);
  int year;
  printf("Entry year: ");
  scanf("%d", &year);
  getchar();
  if(year == 2016){
    for(int i=0; i<n; i++){
      if(records[i].entry == 2016){
        printf("%s\n", records[i].name);
      }
    }
  }
  else if(year == 2017){
    for(int i=0; i<n; i++){
      if(records[i].entry == 2017){
        printf("%s\n", records[i].name);
      }
    }
  }
  else if(year == 2018){
    for(int i=0; i<n; i++){
      if(records[i].entry == 2018){
        printf("%s\n", records[i].name);
      }
    }
  }
  else if(year == 2019){
    for(int i=0; i<n; i++){
      if(records[i].entry == 2019){
        printf("%s\n", records[i].name);
      }
    }
  }
}

void fm_error(Record records[]){
  //guess female students' room number are always 101~199 and male students' room number are always 201~299
  //find wrong room number's student and print their name and room number
  int n = load_txt2(records);
  for(int i=0; i<n; i++){
    if(records[i].fm == 'F'){
      if(records[i].room<101 || records[i].room>199){
        printf("%s : %d\n", records[i].name, records[i].room);
      }
    }
    else{
      if(records[i].room<201 || records[i].room>299){
        printf("%s : %d\n", records[i].name, records[i].room);
      }
    }
  }
}
