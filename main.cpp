#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "roster.h"
#include "degree.h"


int main() {
	// provided student data table
	const int DATASIZE = 5;
	const std::string studentData[DATASIZE] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
												"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
												"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
												"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
												"A5,Brady,Bassett,bbass38@wgu.edu,20,30,46,52,SOFTWARE" };
	
	std::cout << "Scripting and Programming - Applications - C867" << std::endl;
	std::cout << "C++" << std::endl;
	std::cout << "Brady Bassett - 002616010" << std::endl << std::endl << std::endl;

	// Declaration of classRoster object of type Roster
	Roster classRoster;

	// Using a stringstream to parse through each string at each index within the data table and assigning the parsed data to
	// a student pointer using the Add() function
	for (int i = 0; i < DATASIZE; i++) {
		std::string extractedData = studentData[i];
		std::vector<std::string> parsedData;
		std::stringstream strStream(extractedData);
		while (strStream.good()) {
			std::string substr;
			std::getline(strStream, substr, ',');
			parsedData.push_back(substr);
		}
		classRoster.Add(parsedData[0], parsedData[1], parsedData[2], parsedData[3], parsedData[4],
			parsedData[5], parsedData[6], parsedData[7], parsedData[8]);
	}

	// Main functionality check
	classRoster.PrintAll();
	std::cout << std::endl;
	classRoster.PrintInvalidEmails();
	std::cout << std::endl;
	classRoster.LoopThroughStudentAverages();
	std::cout << std::endl;
	classRoster.PrintByDegreeProgram(SOFTWARE);
	std::cout << std::endl;
	classRoster.Remove("A3");
	std::cout << std::endl;
	classRoster.PrintAll();
	std::cout << std::endl;
	classRoster.Remove("A3");
	std::cout << std::endl;

	return 0;
}