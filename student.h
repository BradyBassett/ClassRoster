#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
	public:
		Student(std::string studentID = "none", std::string firstName = "none", std::string lastName = "none", 
			std::string emailAddress = "none", int studentAge = -1, std::vector<int> daysToCompleteCourses = {},
			std::string degreeProgram = "none");

		void SetStudentID(std::string studentID);
		void SetFirstName(std::string firstName);
		void SetLastName(std::string lastName);
		void SetEmailAddress(std::string lastName);
		void SetStudentAge(int studentAge);
		void SetdaysToCompleteCourses(std::vector<int> &daysToCompleteCourses);
		void SetDegreeProgram(std::string degreeProgram);

		std::string GetStudentId() const;
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetEmailAddress() const;
		int GetStudentAge() const;
		std::vector<int> GetDaysToCompleteCourses() const;
		std::string GetDegreeProgram() const;

		// Implement a Print() function which can print specific student data

	private:
		std::string studentID;
		std::string firstName;
		std::string lastName;
		std::string emailAddress;
		int studentAge;
		std::vector<int> daysToCompleteCourses;
		std::string degreeProgram; // Might need to turn this into a degree object instead of just a string
};

#endif