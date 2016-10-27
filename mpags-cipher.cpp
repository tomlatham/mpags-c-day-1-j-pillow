#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]){
	/* Cipher that currently can take take a user input and creates an output following:
	   - All letters are uppercase
	   - All numbers are converted to words
	   - All non-alphas are removed
	 */

	// Current version number
	std::string versionNumber{"v0.1.0"};
	
	// Convert command line arguments to useable form
	const std::vector<std::string> cmdLineArgs{argv, argv+argc};
	
	// Create strings for input/output file names
	std::string oFile_name{""};
	std::string iFile_name{""};
	
	// Check cmd line arguments
	for (size_t i{0}; i<cmdLineArgs.size(); i++) {
		// TEL: There is a rule of thumb that each bit of code should do one job.
		//      The job of this loop is to process the command line arguments and determine the setup for the program.
		//      The actions should occur afterwards.
		//      e.g. it is best to separate the action of printing the help message from determining that help is required.
		//      See the model solution.
		if(cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help"){
			// Provides help if asked
			// TEL: This could be a more helpful message!
			std::cout << "You have requested help!. This is some help. I hope it was helpful. Goodbye!" << std::endl;
			return 0;
		}
		if(cmdLineArgs[i] == "--version"){
			// Provides version number if asked
			std::cout << "You have requested the version! Current version is: " << versionNumber << std::endl;
			return 0;
		}
		if(cmdLineArgs[i] == "-o"){
			// Checks for output file
			if(i+1==cmdLineArgs.size()){
				// No filename provided - print error message and return 1 to indicate failure
				std::cout << "Error! Error! No output file given!" << std::endl;
				return 1;
			}
			else{
				oFile_name = cmdLineArgs[i+1];
				std::cout << "Output file: " << cmdLineArgs[i+1] << std::endl;
				i++;
			}
		}
		if(cmdLineArgs[i] == "-i"){
			// Checks for input file
			if(i+1==cmdLineArgs.size()){
				// No filename provided - print error message and return 1 to indicate failure
				std::cout << "Error! Error! No input file given!" << std::endl;
				return 1;
			}
			else{
				iFile_name = cmdLineArgs[i+1];
				std::cout << "Input file: " << cmdLineArgs[i+1] << std::endl;
				i++;
			}
		}
	}
	
	//std::cout << "Output file: " << oFile_name << " | Input file: " << iFile_name << std::endl;
		
	std::string my_str = {""};
	char in_char{'x'};
	char upper_char{'y'};
	
	// Provide instructions for use 
	std::cout << "Please provide user input. When done press Enter followed by Ctrl+D." << std::endl;
		
	while(std::cin >> in_char){
		/* Loop until the user
		presses Enter then Ctrl+D */
		
		if(isalpha(in_char)){
			upper_char = (toupper(in_char)); 				// convert to upper case
			my_str += upper_char;							// - In each case, add result to a string variable
		} 
		
		else if(isdigit(in_char)){ 							// - Change numbers to words
			
			std::string num {""};
		
			switch (in_char){
				
				case '0':
					num = "ZERO";
					break;
				case '1':
					num = "ONE";
					break;
				case '2':
					num = "TWO";
					break;
				case '3':
					num = "THREE";
					break;
				case '4':
					num = "FOUR";
					break;
				case '5':
					num = "FIVE";
					break;
				case '6':
					num = "SIX";
					break;
				case '7':
					num = "SEVEN";
					break;
				case '8':
					num = "EIGHT";
					break;
				case '9':
					num = "NINE";
					break;
				
				default: break;
			}
			my_str += num;									// - In each case, add result to a string variable
		}
		
		// TEL: you don't necessarily need the line below but it also doesn't really hurt
		else continue; 										// - Ignore any other (non-alpha) characters
		
	}
	

	std::cout << "My string is: " << my_str << std::endl;	// print out the new string
	
	return 0;
	
}
