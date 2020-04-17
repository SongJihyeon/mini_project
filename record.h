#ifndef _RECORD_H_
#define _RECORD_H_

// type defition
typedef struct{
	//int id;

	// TODO: define your own structure type here
  char name[20];	// name			
	char fm;		// sex ('F' female, 'M' male)				
	int entry;		// entry year
	int room;		// room number
	int point;		// minus point

} Record;

#endif
