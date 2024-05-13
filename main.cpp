//
//  main.cpp
//  ClassRoster2
//
//  Created by Parvaty Chery on 2024-04-23.
//

#include <iostream>
#include <iomanip>
#include "roster.hpp"
using namespace std;

int main(){
    //printing the course title, language used and my information
    cout << "C867- Scripting and Programming: Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU STUDENT ID: 011120687" << endl;
    cout << "Programmer: Parvaty Chery" << endl;
    cout << endl;
    
    const string studentData[]= {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY","A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK","A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE","A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY","A5,Parvaty,Chery,pchery1@wgu.edu,21,20,25,32,SOFTWARE"
        /*setting up the student data array and adding my personal information at the end*/
        };
    
    const int numStudents = 5;
    Roster classRoster;//creating the classRoster object
    
    for (int i = 0; i < numStudents; i++)
        classRoster.parse(studentData[i]);
    cout << "Display All Students: " << endl;
    classRoster.printAll();
    cout << endl;/*first thing is to parse and add the students to the roster and print all of the students*/
    
    cout << "Display Invalid emails: " << endl;
    classRoster.printInvalidEmails();
    cout << endl;//next, we display the invalid emails
    
    cout << "Display average days: " << endl;
    for(int i = 0; i < numStudents; i++){
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());/*this will display the averages days for each student*/
    }
    cout << endl;
    
    cout << "Display software students: "  << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl; /*this will only print by the degree program and showcase only the students who are in the SOFTWARE degree program*/
    
    
    cout << "Remove student A3" << endl;
    classRoster.remove("A3");
    cout << endl;
    classRoster.printAll();
    cout << endl;
    classRoster.remove("A3");
    cout << endl; /*here we remove the student with ID A3 and print out the results*/
    

        
    
    return 0;
    
    //lastly the destructor will be initialized
};

