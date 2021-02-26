#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <vector>

#include "student.h"
#include "degree.h"

class Roster {
	public:
		Roster();
		Roster(const Roster& source);
		Roster& operator=(const Roster& source);
		~Roster();

		void Add(std::string studentID, std::string firstName, std::string lastName, 
				 std::string emailAddress, std::string age, std::string daysInCourse1,
				 std::string daysInCourse2, std::string daysInCourse3, std::string degreeProgram);
		void Remove(std::string studentID);

		void PrintAll() const;
		void PrintAverageDaysInCourse(std::string studentID) const;
		void PrintInvalidEmails() const;
		void PrintByDegreeProgram(DegreeProgram degreeProgram) const;
		void LoopThroughStudentAverages() const;

	private:
		std::vector<Student>* classRosterArray;
};

#endif