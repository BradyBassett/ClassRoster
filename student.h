#ifndef STUDENT_H
#define STUDENT_H

#include <string>

#include "degree.h"

class Student {
	public:
		// Constructor
		Student(std::string studentID = "none", std::string firstName = "none", std::string lastName = "none",
				std::string emailAddress = "none", int studentAge = -1, int daysInCourse1 = -1, 
				int daysInCourse2 = -1, int daysInCourse3 = -1, DegreeProgram degreeProgram = NONE);

		// Mutators
		void SetStudentID(std::string studentID);
		void SetFirstName(std::string firstName);
		void SetLastName(std::string lastName);
		void SetEmailAddress(std::string lastName);
		void SetStudentAge(int studentAge);
		void SetDaysInCourses(int course1, int course2, int course3);
		void SetDegreeProgram(DegreeProgram degreeProgram);

		// Accessors
		std::string GetStudentId() const;
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetEmailAddress() const;
		int GetStudentAge() const;
		int GetDaysInCourse1() const;
		int GetDaysInCourse2() const;
		int GetDaysInCourse3() const;
		DegreeProgram GetDegreeProgram() const;

		// Prints out all data members associated with the student object
		void Print() const;

	private:
		std::string studentID;
		std::string firstName;
		std::string lastName;
		std::string emailAddress;
		int studentAge;
		int daysInCourse1;
		int daysInCourse2;
		int daysInCourse3;
		DegreeProgram degreeProgram;
};

#endif