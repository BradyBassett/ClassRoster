#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <vector>

#include "student.h"
#include "degree.h"

class Roster {
	public:
		~Roster();

		void Add(std::string studentID, std::string firstName, std::string lastName, 
				 std::string emailAddress, int age, int daysInCourse1, 
				 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		void Remove(std::string studentID);

		void PrintAll() const;
		void PrintAverageDaysInCourse(std::string studentID) const;
		void PrintInvalidEmails() const;
		void PrintByDegreeProgram(DegreeProgram degreeProgram) const;

	private:
		std::vector<Student>* classRosterArray;
		
};

#endif