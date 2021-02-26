#include <string>
#include <iostream>
#include <vector>

#include "student.h"
#include "roster.h"
#include "degree.h"

// Constructor
Roster::Roster() {

	this->classRosterArray = new std::vector<Student>;

	return;
}
// Copy Constructor
Roster::Roster(const Roster& source) {

	classRosterArray = new std::vector<Student>;
	
	for (int i = 0; i < classRosterArray->size(); i++) {
		classRosterArray[i] = source.classRosterArray[i];
	}

	return;
}
// Copy Assignment Operator
Roster& Roster::operator=(const Roster& source) {

	if (this == &source) {
		return *this;
	}

	for (int i = 0; i < classRosterArray->size(); i++) {
		classRosterArray[i] = source.classRosterArray[i];
	}

	return *this;
}
// Destructor
Roster::~Roster() {

	std::cout << std::endl << "DESTRUCTOR CALLED" << std::endl;
	std::vector<Student>().swap(*classRosterArray);

	return;
}

// Takes parsed student data, creates a new student object containing the data and adds the new student to classRosterArray
void Roster::Add(std::string studentID, std::string firstName, std::string lastName,
				 std::string emailAddress, std::string age, std::string daysInCourse1,
				 std::string daysInCourse2, std::string daysInCourse3, std::string degreeProgram) {
	
	// Converts the strings into the proper data type for each data member
	int convertedAge = stoi(age);
	int convertedDaysInCourse1 = stoi(daysInCourse1);
	int convertedDaysInCourse2 = stoi(daysInCourse2);
	int convertedDaysInCourse3 = stoi(daysInCourse3);
	DegreeProgram convertedDegreeProgram;

	if (degreeProgram == "SECURITY") {
		convertedDegreeProgram = SECURITY;
	}
	else if (degreeProgram == "NETWORK") {
		convertedDegreeProgram = NETWORK;
	}
	else if (degreeProgram == "SOFTWARE") {
		convertedDegreeProgram = SOFTWARE;
	}

	Student* student = nullptr;
	student = new Student(studentID, firstName, lastName, emailAddress, convertedAge, convertedDaysInCourse1,
		convertedDaysInCourse2, convertedDaysInCourse3, convertedDegreeProgram);
	classRosterArray->push_back(*student);

	return;
}

// Loops through classRosterArray and finds specified student by matching provided studentID and removes the student from classRosterArray if present
void Roster::Remove(std::string studentID) {
	bool studentPresent = false;

	for (int i = 0; i < classRosterArray->size(); i++) {
		if (classRosterArray->at(i).GetStudentId() == studentID) {
			std::cout << "Student removed" << std::endl << std::endl;
			
			classRosterArray->erase(classRosterArray->begin() + i);
			studentPresent = true;
			break;
		}
	}
	if (studentPresent == false) {
		std::cout << "ERROR - student not found in roster" << std::endl;
	}

	return;
}

// Calls the Student class Print function for each student object in classRosterArray
void Roster::PrintAll() const {
	
	std::cout << "All students in roster:" << std::endl << std::endl;

	for (int i = 0; i < classRosterArray->size(); i++) {
		classRosterArray->at(i).Print();
		std::cout << std::endl;
	}

	return;
}

// Calculates average days in courses for a specified student and prints out the average
void Roster::PrintAverageDaysInCourse(std::string studentID) const {
	bool studentPresent = false;
	int averageDays = 0;

	for (int i = 0; i < classRosterArray->size(); i++) {
		if (classRosterArray->at(i).GetStudentId() == studentID) {
			averageDays += classRosterArray->at(i).GetDaysInCourse1();
			averageDays += classRosterArray->at(i).GetDaysInCourse2();
			averageDays += classRosterArray->at(i).GetDaysInCourse3();

			std::cout << "Average number of days in courses for "<< classRosterArray->at(i).GetFirstName() << 
				" " << classRosterArray->at(i).GetLastName() << ": " << averageDays / 3 << std::endl;

			studentPresent = true;
			break;
		}
	}

	if (!studentPresent) {
		std::cout << "ERROR - student not found in roster" << std::endl;
	}
	
	return;
}

// For each student in classRosterArray, validats the students email address. Adds each invalid email address to a vector and then prints out all invalid emails
void Roster::PrintInvalidEmails() const {
	bool valid = true;
	std::vector<std::string> invalidEmails;
	int atPos;
	int dotPos;
	std::size_t found;
	
	for (int i = 0; i < classRosterArray->size(); i++) {
		// While the email address is still valid, continue the loop. Break out of loop and add email to vector if invalid email is found
		while(valid){
			// Checks if the first character in the email address string is a letter
			if (!isalpha(classRosterArray->at(i).GetEmailAddress()[0])) {
				valid = false;
				invalidEmails.push_back(classRosterArray->at(i).GetEmailAddress());
				break;
			}
			// Checks if there are any spaces within the email address
			for (int j = 0; j < classRosterArray->at(i).GetEmailAddress().length(); j++) {
				if (classRosterArray->at(i).GetEmailAddress()[j] == ' ') {
					valid == false;
					invalidEmails.push_back(classRosterArray->at(i).GetEmailAddress());
					break;
				}
			}
			// Finding position of the first @ and . in the email address
			atPos = -1;
			dotPos = -1;
			for (int j = 0; j < classRosterArray->at(i).GetEmailAddress().length(); j++) {
				if (classRosterArray->at(i).GetEmailAddress()[j] == '@') {
					atPos = j;
				}
				else if (classRosterArray->at(i).GetEmailAddress()[j] == '.') {
					dotPos = j;
				}
			}
			// If no @ or . found add email to invalidEmails
			if (atPos == -1 || dotPos == -1) {
				valid == false;
				invalidEmails.push_back(classRosterArray->at(i).GetEmailAddress());
				break;
			}
			// if the @ is located after the . add email to invalidEmails
			if (atPos > dotPos) {
				valid == false;
				invalidEmails.push_back(classRosterArray->at(i).GetEmailAddress());
				break;
			}
			// if the dot is at the end of the email address string add email to invalidEmails
			if (dotPos >= (classRosterArray->at(i).GetEmailAddress().length() - 1)) {
				valid == false;
				invalidEmails.push_back(classRosterArray->at(i).GetEmailAddress());
				break;
			}
			break;
		}
		valid = true;
	}
	// Printing out invalid emails if any are present
	if (invalidEmails.size() > 0){
		std::cout << "Invalid Emails:" << std::endl << std::endl;
		for (int i = 0; i < invalidEmails.size(); i++) {
			std::cout << invalidEmails[i] << std::endl;
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "No invalid emails" << std::endl << std::endl;
	}

	return;
}

// Attempts to match degreeProgram to all DegreeProgram values and prints out each student that matches
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) const {
	bool noMatch = true;
	
	// Determining which program to print
	switch (degreeProgram) {
	case SECURITY:
		std::cout << "Students in the Security degree program: " << std::endl << std::endl;
		break;
	case NETWORK:
		std::cout << "Students in the Network degree program: " << std::endl << std::endl;
		break;
	case SOFTWARE:
		std::cout << "Students in the Software degree program: " << std::endl << std::endl;
		break;
	}

	// Calling the student Print function if students degreeProgram matches degreeProgram in parameter
	for (int i = 0; i < classRosterArray->size(); i++) {
		if (classRosterArray->at(i).GetDegreeProgram() == degreeProgram) {
			classRosterArray->at(i).Print();
			std::cout << std::endl;
			noMatch = false;
		}
	}

	if (noMatch) {
		std::cout << "No students matching that degree program in roster" << std::endl;
	}

	return;
}

// For each student in classRosterArray, calls PrintAverageDaysInCourse
void Roster::LoopThroughStudentAverages() const {
	std::cout << "Average number of days in each course:" << std::endl << std::endl;
	
	for (int i = 0; i < classRosterArray->size(); i++) {
		PrintAverageDaysInCourse(classRosterArray->at(i).GetStudentId());
	}
	std::cout << std::endl;
	return;
}