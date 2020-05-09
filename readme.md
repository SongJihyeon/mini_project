# **OSSL_Mini Project**

## Dormitory Student Management Program

User can choose number what he or she want to do. 

In this program, user can add members from txt file and keyboard. 

User can search the study's information and print the desired student's information.

User can change the student's room number or give him a penalty if put his name in it.

User can classify students with the year of admission, and user can find something wrong with the room number.

All changes made here are stored in memers.txt without blank and this file can be sorted. 

Also, txt file reports can be made with this txt file.

#### **[Create: Create a new data record from a data file]**

if user wants to add members from txt file, loads txt file(*members.txt*) and save the data to struct for count lines. 

loads *load.txt* file and add that data to struct and save to *members.txt* too.


#### **[Create: Create a new record from the standard input]**

I have a txt file(*“members.txt”*) and if I run add a record, it loads txt file and save the data to struct. 

Input from the user and save it both struct and add member in *members.txt* file.


#### **[Read: According to user specified conditions, print a record, multiple or all records to the standard output]**

If user’s input is 3(search student’s information). 

User can type over two characters and if that character is in struct student’s name, print the student’s information.


#### **[Read: Read/write the entire data from/to filesystem]**

If user select 4(print all members), print all member’s list from the *members.txt* file.


#### **[Read: Export the entire data in a report format as a .txt file]**

If user select save dormitory report, save report with txt file. 

This is the file that saved report. 

In this report, you can see student number and all student’s information.


#### **[Update: Update a specific field of a record, multiple or all records]**

Find student with name and if student is in list, print student’s information and change room number.


#### **[Delete: Delete a record, multiple or all records]**

Find student name and delete all of his/her record and replace that blank to the last record.


#### **[Extra: Perform a data defragmentation]**

I wrote this to code with delete function, if user want to delete something, delete that and replace with last element in records.


#### **[Extra: Arrange (sort) the order of data records]**

I sort all records and I save it to members.txt again.


#### **[Extra: plus specific field of a record’s number]**

find student with student name

If the name exists, choose the reason of minus point and plus the students minus point.


#### **[Extra: classificate student with specific field of a record]**

If user want to show 2018’s student print user's input year's student's name.


#### **[Extra: find wrong data from the record]**

guess female students' room number are always 101~199 and male students' room number are always 201~299

find wrong room number's student and print their name and room number
