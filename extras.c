#include <stdio.h>
#include "extras.h"
#include <string.h>
#include <stdlib.h>
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

void choose_condition(Record records[]){
 int choose1, choose2;
 printf("choose 2 conditions to search what you want\n(1:name, 2:entry year,3:room 4:gender(f,m)):");
 scanf("%d %d",&choose1,&choose2);
 search_student_data(records,choose1,choose2);
 }

void search_student_data(Record records[],int choose1, int choose2){
 char dummy;
 char name[20];
 char gender[2];
 char entry_year[10];
 char room_no[10];
 char *year = (char*)malloc(sizeof(char)*1000);
 char *room = (char*)malloc(sizeof(char)*1000);
 char *gen = (char*)malloc(sizeof(char)*1000);
 int n=1;
 int i;
 int count = load_txt2(records);

for(i=0;i<count;i++){
 sprintf(year,"%d",records[i].entry);
 sprintf(room,"%d",records[i].room);
 sprintf(gen,"%c",records[i].fm);
}


 if(choose1==1){
     printf("Enter name(more than 2 words)>");
     scanf("%s",name);
   if(choose2==2){
     printf("Enter entry year to find users(e.g 2019)>");
     scanf("%s",entry_year);
     getchar();
     for(i = 0; i < count; i++){
	 sprintf(year,"%d",records[i].entry);
      if(strncmp(records[i].name,name,strlen(name))==0&&strncmp(year,entry_year,strlen(entry_year))==0 ){
	printf("%2d",n++);
       printf("%d %s [%c] %d %d %d\n", i+1, records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
     }
    }
   }
   else if (choose2==3){
     printf("Enter room number to find users>");
     scanf("%s",room_no);
     getchar();
    for(i = 0; i < count; i++){
      sprintf(room,"%d",records[i].room);
	if(strncmp(records[i].name,name,strlen(name))==0 && strncmp(room,room_no,strlen(room_no))==0){
       printf("%2d",n++);
       printf("%d %s [%c] %d %d %d\n", i+1, records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
      }
     }
   }
   else if(choose2==4){
     printf("Enter gender to find users>");
     scanf("%s",gender);
     getchar();
     for(i = 0; i < count; i++){
       sprintf(gen,"%c",records[i].fm);
	if(strncmp(records[i].name,name,strlen(name))==0 && strncmp(gen,gender,1)==0){
        printf("%2d",n++);
        printf("%d %s [%c] %d %d %d\n", i+1, records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
       }
      }
   }
   else{
     printf("retry, Quit program.");
   }
 }
//2
 else if(choose1==2){
  printf("Enter entry year to find users(e.g 2019)>");
  scanf("%c",&dummy);
  scanf("%s",entry_year);
    if(choose2==1){
        printf("Enter name(more than 2 words)>");
        scanf("%c",&dummy);
        scanf("%s",name);
        getchar();
  for(i = 0; i < count; i++){
   sprintf(year,"%d",records[i].entry);
   if(strncmp(year,entry_year,strlen(entry_year))==0 && strncmp(records[i].name,name,strlen(name))==0){
     printf("%2d",n++);
    printf("%d %s [%c] %d %d %d\n", i+1, records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
    }
   }
  }
  else if (choose2==3){
    printf("Enter room number to find users>");
    scanf("%c",&dummy);
    scanf("%s",room_no);
    getchar();
   for(i = 0; i < count; i++){
   sprintf(year,"%d",records[i].entry);
 sprintf(room,"%d",records[i].room);
    if(strncmp(year,entry_year,strlen(entry_year))==0 && strncmp(room,room_no,strlen(room_no))==0){
      printf("%2d",n++);
      printf("%d %s [%c] %d %d %d\n", i+1, records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
     }
    }
  }
  else if(choose2==4){
    printf("Enter gender to find users>");
    scanf("%c",&dummy);
    scanf("%s",gender);
      getchar();
    for(i = 0; i < count; i++){
        sprintf(year,"%d",records[i].entry);
       sprintf(gen,"%c",records[i].fm); 
     if(strncmp(year,entry_year,strlen(entry_year))==0 && strncmp(gen,gender,1)==0){
       printf("%2d",n++);
       printf("%d %s [%c] %d %d %d\n", i+1, records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
      }
     }
  }
  else{
    printf("retry, Quit program.");
  }
 }
 //3
 else if(choose1==3){
  printf("Enter room number to find users>");
  scanf("%c",&dummy);
  scanf("%s",room_no);
   if(choose2==1){
       printf("Enter name(more than 2 words)>");
       scanf("%c",&dummy);
       scanf("%s",name);
       getchar();
 for(i = 0; i < count; i++){
 sprintf(room,"%d",records[i].room);
  if(strncmp(room,room_no,strlen(room_no))==0 && strncmp(records[i].name,name,strlen(name))==0){
   printf("%2d",n++);
   printf("%d %s [%c] %d %d %d\n", i+1, records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
   }
  }
 }
  else if(choose2==2){
     printf("Enter entry year to find users(e.g 2019)>");
     scanf("%c",&dummy);
     scanf("%s",entry_year);
     getchar();
     for(i = 0; i < count; i++){
      sprintf(room,"%d",records[i].room);
	   sprintf(year,"%d",records[i].entry);
      if(strncmp(room,room_no,strlen(room_no))==0 && strncmp(year,entry_year,strlen(entry_year))==0){
       printf("%2d",n++);
       printf("%d %s [%c] %d %d %d\n", i+1, records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
      }
     }
   }
   else if(choose2==4){
     printf("Enter gender to find users>");
     scanf("%c",&dummy);
     scanf("%s",gender);
       getchar();
     for(i = 0; i < count; i++){
      sprintf(room,"%d",records[i].room);
       sprintf(gen,"%c",records[i].fm);
      if(strncmp(room,room_no,strlen(room_no))==0 && strncmp(gen,gender,1)==0){
        printf("%2d",n++);
        printf("%d %s [%c] %d %d %d\n", i+1, records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
       }
      }
   }
   else{
     printf("retry, Quit program.");
   }
 }
 //4
 else if(choose1==4){
  printf("Enter gender to find users>");
  scanf("%c",&dummy);
  scanf("%s",gender);
    if(choose2==1){
        printf("Enter name(more than 2 words)>");
        scanf("%c",&dummy);
        scanf("%s",name);
        getchar();
    for(i = 0; i < count; i++){
     sprintf(gen,"%c",records[i].fm);

    if(strncmp(gen,gender,1)==0 && strncmp(records[i].name,name,strlen(name))==0){
    printf("%2d",n++);
    printf("%d %s [%c] %d %d %d\n", i+1, records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
     }
    }
   }
    else if(choose2==2){
      printf("Enter entry year to find users(e.g 2019)>");
      scanf("%c",&dummy);
      scanf("%s",entry_year);
      getchar();
      for(i = 0; i < count; i++){
        sprintf(gen,"%c",records[i].fm);
	sprintf(year,"%d",records[i].entry);
	if(strncmp(gen,gender,1)==0 && strncmp(year,entry_year,strlen(entry_year))==0){
        printf("%2d",n++);
        printf("%d %s [%c] %d %d %d\n", i+1, records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
       }
      }
    }
    else if (choose2==3){
      printf("Enter room number to find users>");
      scanf("%c",&dummy);
      scanf("%s",room_no);
      getchar();
     for(i = 0; i < count; i++){
      sprintf(gen,"%c",records[i].fm);
      sprintf(room,"%d",records[i].room);
      if(strncmp(gen,gender,1)==0 && strncmp(room,room_no,strlen(room_no))==0){
        printf("%2d",n++);
        printf("%d %s [%c] %d %d %d\n", i+1, records[i].name, records[i].fm, records[i].entry, records[i].room, records[i].point);
       }
      }
    }
 }
 else{
  printf("retry. Quit program.");
}
 fflush(stdin);
 free(year);
 free(room);
free(gen);
}
