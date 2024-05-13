//
//  roster.cpp
//  ClassRoster2
//
//  Created by Parvaty Chery on 2024-04-23.
//

#include "roster.hpp"// including the roster header file to use the Roster class
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

//this is the function to parse the student data and add it to the roster
void Roster::parse(string allstudentdata){
    
    
    //will allow to find and extract each piece of info from the input string
    
    //first we find the position of the first comma
    std::string::size_type rightside = allstudentdata.find(','); // this finds the comma
    string studentid = allstudentdata.substr(0, rightside);
    //second, it extracts the student ID from the beginning of teh string
    
    
    //move on to the next comma in the data and find its position
    std::string::size_type leftside = rightside + 1; // this moves past the previous comma
    rightside = allstudentdata.find(',', leftside);
    string firstname = allstudentdata.substr(leftside, rightside - leftside); //first name- extract the first name from the string
    
    //this process repeats for the last name, email and age and the degree program
    
    leftside = rightside + 1; // this keeps the loop going
    rightside = allstudentdata.find(',', leftside);
    string lastname = allstudentdata.substr(leftside, rightside - leftside); //last name
    
    leftside = rightside + 1; //keeps going
    rightside = allstudentdata.find(',', leftside);
    string emailaddress = allstudentdata.substr(leftside, rightside - leftside); //email address
    
    leftside = rightside + 1; // keeps going
    rightside = allstudentdata.find(',', leftside);
    int studentage = stoi(allstudentdata.substr(leftside, rightside - leftside));
    
    leftside = rightside + 1; // continue on to the next one
    rightside = allstudentdata.find(',', leftside);
    int daysforcourse1 = stod(allstudentdata.substr(leftside, rightside - leftside)); /*first element for days in course*/
    leftside = rightside + 1; // continue on to the next one
    rightside = allstudentdata.find(',', leftside);
    int daysforcourse2 = stod(allstudentdata.substr(leftside, rightside - leftside)); /*second element for days in course*/
    leftside = rightside + 1; // continue on to the next one
    rightside = allstudentdata.find(",", leftside);
    int daysforcourse3 = stod(allstudentdata.substr(leftside, rightside - leftside)); /*third element for days in course*/
    
    leftside = rightside + 1;
    rightside = allstudentdata.find(",", leftside);
    
    DegreeProgram dp = SECURITY;//set the default program to SECURITY
    if (allstudentdata[leftside] == 'S') {/*CHECKS IF THE FIRST CHARACTER AFTER THE COMMA IS S; THEN WE ADD ANOTHER IF CONDITION*/
        
        /*CHECKS IF THE NEXT CHARACTER IS E FOR SECURITY*/
        if (allstudentdata[leftside + 1] == 'E') dp = SECURITY;
        else if (allstudentdata[leftside + 1] == 'O') dp = SOFTWARE;
        /*CHECKS IF THE NEXT CHARACTER IS 0 FOR SOFTWARE*/
    } else if (allstudentdata[leftside] == 'N') {
        dp = NETWORK;//CHECKS IF FIRST CHARACTER AFTER THE COMMA IS N FOR NETWORK
    }
    add(studentid, firstname, lastname, emailaddress, studentage, daysforcourse1, daysforcourse2, daysforcourse3, dp);//ADDING THE STUDENT TO THE ROSTER
}
    

    



 void Roster::add(string studentID,string firstName,string lastName,string emailAddress,int age,int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){//FUNCTION TO ADD STUDENT TO THE ROSTER
                                                
     int daysinarray[3] = {daysInCourse1,daysInCourse2,daysInCourse3};
// THE ARRAY STORES THE DAYS SPENTS IN EACH COURSE

    
     classRosterArray[++lastindex] = new Student(studentID, firstName, lastName, emailAddress,age,daysinarray,degreeProgram);/*ADDING THE STUDENT TO THE CLASSROSTERARRAY*/
        
    }

void Roster::remove(string studentID) {
    bool studentfound = false; /*initialize a boolean to track if the student was found*/
    for (int i = 0; i <= lastindex; i++) { // doing a for loop
        if (classRosterArray[i]->getStudentID() == studentID) {/*checking if the studentid matches the one to remove*/
            delete classRosterArray[i]; // Delete the student object from memory
            studentfound = true;
            for (int j = i; j < lastindex; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }/*shift the remaining students to fill the gaps and move the pointers down in the array*/
            classRosterArray[lastindex] = nullptr; // Nullify the last element
            lastindex--;
            break;
        }
    }
    if (studentfound) {
        cout << "Student with ID: " << studentID << " found and removed." << endl;
    } else {
        cout << "Error: Student with ID " << studentID << " not found." << endl;
    }
}


void Roster::printAll()
{//prints out all students in the roster
    Student::printHeader();/*prints out the header(format of how the data is organized*/
    for (int i = 0; i <= Roster::lastindex; i++) Roster::classRosterArray[i]->print();/*this for loop will go through each student and print out their information.*/
        
        
    }

   //this function will print out the average days in course for each student
void Roster::printAverageDaysInCourse(string studentID){
    for (int i = 0; i <= Roster::lastindex; i++)
    {/*use a for loop to find the student and calcualte and print out the average days*/
        if (classRosterArray[i]->getStudentID() == studentID){
            int* days = classRosterArray[i]->getNumDays();
            int averageDays = (days[0] + days[1] + days[2]) / 3;
            cout << studentID << ": " << averageDays << endl;
            return;
            
        }
        
    }
    
}


void Roster::printInvalidEmails(){
    
    bool anyinvalid = false;// set the boolean value to false as default
    
    for (int i = 0; i <= Roster::lastindex; i++)//looping through each student
    {Student& student = *classRosterArray[i];//getting a reference
        string email = student.getEmailAddress();/*using a getter to get the email address of a student*/
        
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos){/*check if the email is valid- if ther is no @ sign or . and there is spaces, it is not valid*/
            
            anyinvalid = true;
            cout << "Invalid email: " << email << classRosterArray[i]->getFirstName() << endl;;
        }
    }
    if (!anyinvalid)
        cout << "No Invalid Email!" << endl;
}//if there are no invalid emails, it prints out this message above





//this function prints students by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    
    Student::printHeader();/*first, this will print the header to organize student data*/
    for (int i = 0; i <= Roster::numStudents; i++){
        if (classRosterArray[i] != nullptr) {/*next, it will loop through each student and make sure the current student is no emty(nullptr)*/
            if(degreeProgram == classRosterArray[i]-> Student::getDegreeProgram()){
                classRosterArray[i]->Student::print();/*checks if the student's degree program matches the input degree program and if matches, the details of the student will be printed.*/
            }}
        }
    cout << endl;
    }



Roster::~Roster(){
    
    cout << "Destructor is called!" << endl;
    for (int i = 0; i < numStudents; i++){//removing each student
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
        
    }
};
//removes objects that are dynamically allocated;

    /*I Had to fix my code because I was getting errors when trying to properly implement the destructor to dynamically remove the student objects. In my previous code I was not actually deleting the student object - now I am on the Remove function which allowed me to delete the object when declaring the destructor.*/
        
        
        
        
    
    
    
    
    
    
    
    
    
    
    
    

