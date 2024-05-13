//
//  student.cpp
//  ClassRoster2
//
//  Created by Parvaty Chery on 2024-04-23.
//

#include "student.hpp" //include the student header file
#include <iostream>
using namespace std;



Student::Student(){/*The constructor is used to initialize the variables to defaul values*/
    
    this->studentID = ""; /*this initializes the student ID to empty string*/
    this->firstName = ""; /*this initializes the student's first name to empty string*/
    this->lastName = ""; /*initializes the student's last name to empty string*/
    this->emailAddress = ""; /*initializes the student's email to empty strings*/
    this->age = 0; /*initializes student's age to 0*/
    for (int i = 0; i < daysArray; i++) this->numDays[i] = 0;/*loops throught the array and initializes each element to 0*/
    this->degreeProgram = DegreeProgram::SECURITY; /*initializes the degree program type to SECURITY*/
    }
    


Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeProgram degreeProgram){
    
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysArray; i++) this->numDays[i] = numDays[i];
    this->degreeProgram = degreeProgram;
}/* In this section, the constructor initialize the variables with the provided values*/
    
Student::~Student(){}
/*the destructor- even if does nothing dynamically in this case, still need to add it*/
    
    //accessors- they will retrieve the values of the member variables
    
    string Student::getStudentID() {return this->studentID;} /*returns student id*/
    string Student::getFirstName()  {return this->firstName;} /*returns first name*/
    string Student::getLastName() {return this->lastName;}/*returns last name*/
    string Student::getEmailAddress() {return this-> emailAddress;} /*returns email address*/
    int Student::getAge(){return this->age;}/*returns age*/
    int* Student::getNumDays(){return this->numDays;}/*returns the pointer to the array of days spent in each course*/
    DegreeProgram Student::getDegreeProgram(){return this->degreeProgram;}/*this returns the degree program*/
    
    //end of accessors


  //beginning of setters or mutators to modidy the values of each variable

void Student::setStudentID(string ID){this->studentID = ID;} /*sets the student's id*/
void Student::setFirstName(string firstName){this->firstName = firstName;}/*sets the student first name*/
void Student::setLastName(string lastName){this->lastName = lastName;} /*sets the student's last name*/
void Student::setEmailAddress(string emailAddress){this->emailAddress = emailAddress;} /*sets the student's email*/
void Student::setAge(int age){this->age = age;} /*sets the student's age*/
void Student::setNumDays(int numDays[]){ /*sets each number of days separately*/
    
    for (int i = 0; i < daysArray; i++) this->numDays[i] = numDays[i];
}
void Student::setDegreeProgram(DegreeProgram dp){this->degreeProgram = dp;} /*sets the degree program*/
//end of setters or mutators


void Student::printHeader(){//prints out the header
    
    cout << "ID" << "\t" << "FIRST" << "\t" << "LAST" << "\t" << "EMAIL ADDRESS" << "\t" << "AGE" << "\t" << "DAYS IN COURSE" << "\t" << "DEGREE PROGRAM" << endl; //format of printout for the student data
};
void Student::print()/*this function prints out the data of a student, including their student id, name, email , age and etc.*/
//numDays are grabbed separately
{
    
    cout << this->getStudentID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmailAddress() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getNumDays()[0] << '\t';
    cout << this->getNumDays()[1] << '\t';
    cout << this->getNumDays()[2] << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << '\n'; //outputs degree program of the student as a string- reference degree header
    
};
    

