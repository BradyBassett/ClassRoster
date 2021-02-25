#include <string>
#include <iostream>
#include <vector>

#include "student.h"
#include "roster.h"
#include "degree.h"


Roster::Roster() {

	this->classRosterArray = new std::vector<Student>;

	return;
}

Roster::Roster(const Roster& source) {

	classRosterArray = new std::vector<Student>;
	
	for (int i = 0; i < classRosterArray->size(); i++) {
		classRosterArray[i] = source.classRosterArray[i];
	}

	return;
}

Roster& Roster::operator=(const Roster& source) {

	if (this == &source) {
		return *this;
	}

	for (int i = 0; i < classRosterArray->size(); i++) {
		classRosterArray[i] = source.classRosterArray[i];
	}

	return *this;
}

Roster::~Roster() {

	std::vector<Student>().swap(*classRosterArray);

	return;
}

void Roster::Add(std::string studentID, std::string firstName, std::string lastName,
				 std::string emailAddress, int age, int daysInCourse1,
				 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	
	Student* student = nullptr;
	student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1,
		daysInCourse2, daysInCourse3, degreeProgram);

	classRosterArray->push_back(*student);

	return;
}

void Roster::Remove(std::string studentID) {
	bool studentPresent = false;

	for (int i = 0; i < classRosterArray->size(); i++) {
		if (classRosterArray->at(i).GetStudentId() == studentID) {
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

void Roster::PrintAll() const {
	
	for (int i = 0; i < classRosterArray->size(); i++) {
		classRosterArray->at(i).Print();
		std::cout << std::endl;
	}

	return;
}

void Roster::PrintAverageDaysInCourse(std::string studentID) const {
	bool studentPresent = false;
	int averageDays = 0;

	for (int i = 0; i < classRosterArray->size(); i++) {
		if (classRosterArray->at(i).GetStudentId() == studentID) {
			averageDays += classRosterArray->at(i).GetDaysInCourse1();
			averageDays += classRosterArray->at(i).GetDaysInCourse2();
			averageDays += classRosterArray->at(i).GetDaysInCourse3();

			std::cout << "Average number of days in courses: " << averageDays / 3 << std::endl;

			studentPresent = true;
			break;
		}
	}

	if (!studentPresent) {
		std::cout << "ERROR - student not found in roster" << std::endl;
	}
	
	return;
}

void Roster::PrintInvalidEmails() const {
	bool valid = true;
	std::vector<std::string> invalidEmails;
	int atPos = -1;
	int dotPos = -1;
	
	for (int i = 0; i < classRosterArray->size(); i++) {
		while(valid){
			if (!isalpha(classRosterArray->at(i).GetEmailAddress()[0])) {
				valid = false;
				invalidEmails.push_back(classRosterArray->at(i).GetEmailAddress());
				break;
			}
			for (int j = 0; j < classRosterArray->at(i).GetEmailAddress().length(); j++) {
				if (classRosterArray->at(i).GetEmailAddress()[j] == '@') {
					atPos = j;
				}
				else if (classRosterArray->at(i).GetEmailAddress()[j] == '.') {
					dotPos = j;
				}
			}
			if (atPos == -1 || dotPos == -1) {
				valid == false;
				invalidEmails.push_back(classRosterArray->at(i).GetEmailAddress());
				break;
			}
			if (atPos > dotPos) {
				valid == false;
				invalidEmails.push_back(classRosterArray->at(i).GetEmailAddress());
				break;
			}
			if (dotPos >= (classRosterArray->at(i).GetEmailAddress().length() - 1)) {
				valid == false;
				invalidEmails.push_back(classRosterArray->at(i).GetEmailAddress());
				break;
			}
		}
		valid = true;
		int atPos = -1;
		int dotPos = -1;
	}
	if (invalidEmails.size() > 0){
		for (int i = 0; i < invalidEmails.size(); i++) {
			std::cout << "Invalid Emails:" << std::endl;
			std::cout << invalidEmails[i] << std::endl;
		}
	}
	return;
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) const {
	bool noMatch = true;
	
	for (int i = 0; i < classRosterArray->size(); i++) {
		if (classRosterArray->at(i).GetDegreeProgram() == degreeProgram) {
			classRosterArray->at(i).Print();
			noMatch = false;
		}
	}

	if (noMatch) {
		std::cout << "No students matching that degree program in roster" << std::endl;
	}

	return;
}