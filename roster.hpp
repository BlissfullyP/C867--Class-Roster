//
//  roster.hpp
//  ClassRoster2
//
//  Created by Parvaty Chery on 2024-04-23.
//

#ifndef ROSTER_H
#define ROSTER_H

#pragma once


#include <stdio.h>
#include <iostream>

#include "student.hpp"

class Roster {/*declaring thet roster class with several functions to manage the student's data*/
    
    
    
public:
    
    
    //these are the function declarations
    void parse(string recordRow);/*declaration used to extract information and create a student object from that information*/
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram dp); /*adds student to the roster*/
    void remove(string studentID);/*removes a student from the roster*/
    void printAll();/*prints all of the student data*/
    void printAverageDaysInCourse(string studentID);/*prints out the average days spent on a course for a student*/
    void printInvalidEmails(); /*prints out invalid emails*/
    /* a valid email should include a '@' symbol and a period '.'*/
    void printByDegreeProgram(DegreeProgram dp);/*prints out student by degree program*/
    ~Roster();
    
    
    
    
    
public:
    int lastindex = -1; //this is the index of the last student in the roster
    const static int numStudents = 5;
    Student* classRosterArray[numStudents]; /*array is created to store the numStudents object*/
    
    
};


    




#endif // ROSTER_H

