#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <vector>

#include "student.h"
#include "degree.h"

class Roster {
	public:
		// Constructor
		Roster();
		// Implementing rule of 3 by including a copy constructor, overloading '=' to be a copy assignment operator, 
		// and a destructor to release all created student objects memory from the heap
		Roster(const Roster& source);
		Roster& operator=(const Roster& source);
		~Roster();

		// Adds a student object pointer to the classRosterArray
		void Add(std::string studentID, std::string firstName, std::string lastName, 
				 std::string emailAddress, std::string age, std::string daysInCourse1,
				 std::string daysInCourse2, std::string daysInCourse3, std::string degreeProgram);
		// Removes a student object pointer from the classRosterArray
		void Remove(std::string studentID);

		// Calls the Student.Print() function for each student object pointer in classRosterArray
		void PrintAll() const;
		// Validates each student email in classRosterArray and prints all invalid emails
		void PrintInvalidEmails() const;
		// Prints out each student that contains the specified degreeProgram
		void PrintByDegreeProgram(DegreeProgram degreeProgram) const;
		// Loops through classRosterArray and calls PrintAverageDaysInCourse to print out each students average in the array
		void LoopThroughStudentAverages() const;

	private:
		// Calculates and prints out the average days in each course for the specified student
		void PrintAverageDaysInCourse(std::string studentID) const;
		// Vector used to hold all student object pointers
		std::vector<Student>* classRosterArray;
};

#endif