#include <string>
#include <iostream>

#include "roster.h"
#include "student.h"
#include "degree.h"


int main() {
	const std::string studentData[5] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
										 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
										 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
										 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
										 "A5,Brady,Bassett,bbass38@wgu.edu,20,30,46,52,SOFTWARE" };

	std::string tempStudentId;
	std::string tempFirstName;
	std::string tempLastName;
	std::string tempEmailAddress;
	int tempAge;
	int tempClass1;
	int tempClass2;
	int tempClass3;
	DegreeProgram tempDegreeProgram;

	std::cout << "Scripting and Programming - Applications - C867" << std::endl;
	std::cout << "C++" << std::endl;
	std::cout << "Brady Bassett - 002616010" << std::endl << std::endl << std::endl;

	Roster classRoster;

	for (int i = 0; i < sizeof(studentData); i++) {
		tempStudentId = "l";
	}

	//FIXME - call print all function from the Roster class

	//FIXME - call print invalid emails from Roster class (unsure if need to fix invalid emails)

	/* 	FIXME - loop through classRosterArray and for each element print out the average days to
	complete all courses */

	//FIXME - print out all of the students in the SOFTWARE degree program

	//FIXME - remove student a3

	//FIXME - print out all students

	//FIXME - attempts to remove student a3 once again (should print an error message)

	//FIXME - implement destructor (should probably be done within the roster class to release each instance of student)

	return 0;
}