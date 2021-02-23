#include <string>
#include <iostream>
#include <vector>

#include "student.h"
#include "roster.h"
#include "degree.h"

Roster::~Roster() {
	//FIXME - Loop through classRosterArray and delete each Student instance

	return;
}

void Roster::Add(std::string studentID, std::string firstName, std::string lastName,
				 std::string emailAddress, int age, int daysInCourse1,
				 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	//FIXME - Add Student instance to classRosterArray;

	return;
}

void Roster::Remove(std::string studentID) {
	//FIXME - Remove student from classRosterArray

	return;
}

void Roster::PrintAll() const {
	//FIXME - iterate through each student within the array and print out the student data

	return;
}

void Roster::PrintAverageDaysInCourse(std::string studenID) const {
	//FIXME - for the specified student, print out the average number of days per class
	
	return;
}

void Roster::PrintInvalidEmails() const {
	//FIXME - iterate through each student in the array and determine if the email is invalid
	// unsure if fixing the email is necessary

	return;
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) const {
	//FIXME - iterate through each student in the array and print them out if their degree program
	// matches the one specified in the parameters

	return;
}