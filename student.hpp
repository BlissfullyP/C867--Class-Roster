//
//  student.hpp
//  ClassRoster2
//
//  Created by Parvaty Chery on 2024-04-23.
//

#ifndef student_hpp
#define student_hpp

#pragma once
#include <iostream>
#include <stdio.h>
#include "degree.h"
#include <vector>

using namespace std;

class Student{
    
public:
       const static int daysArray = 3; // this is the size of the array
    /*each student based on table have 3 elements showing how many days they've spent in 3 courses.*/
    
private:
    
    
    string studentID;// //student's ID number
    string firstName; //student's first name
    string lastName; //student's last name
    string emailAddress;//student's email address
    int age; //student's age
    int numDays[daysArray]; /*created an array as there are 3 elements for each student*/
    DegreeProgram degreeProgram;/*these are the variables i created and made it private */ /*this is a special data type created with enum in degree header*/
    
public:
    
    Student(); // parameterless constructor
    Student(string studentID, string firstName, string lastName,string emailAddress, int age, int numDays[], DegreeProgram degreeProgram);
    ~Student(); //this is the destructor
    
    
    /*establishing getters or accessors for each instance variable*/
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getNumDays();
    DegreeProgram getDegreeProgram();
    
    
    /*establishing setters or mutators for each instance variable*/
    void setStudentID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setNumDays(int numDays[]);
    void setDegreeProgram(DegreeProgram dp);
    
    
    
    
    static void printHeader();
    //this will print and display the header for the data
    
    void print();
    //this display the particular student's data
    
};
#endif /* student_hpp */

/*THIS IS FOR SECTION D1*/


