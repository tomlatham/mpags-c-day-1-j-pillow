#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]){
/* Cipher that currently can take take a user input and creates an output following:
	- All letters are uppercase
	- All numbers are converted to words
	- All non-alphas are removes */
	
	std::string versionNumber{"v0.1.0"}; 	// Current version number
	
	std::vector<std::string> cmdLineArgs{argv, argv+argc};
	
	std::string oFile_name{""};		// Create strings for input/output file names
	std::string iFile_name{""};
	
	for(size_t i=0;i<cmdLineArgs.size();i++){							// Check cmd line arguments
		if(cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help"){		// Provides help if asked
			std::cout << "You have requested help!. This is some help. I hope it was helpful. Goodbye!" << std::endl;
			return 0;
		}
		if(cmdLineArgs[i] == "--version"){											// Provides version number if asked
			std::cout << "You have requested the version! Current version is: " << versionNumber << std::endl;
			return 0;
		}
		if(cmdLineArgs[i] == "-o"){													// Checks for output file
			if(i+1==cmdLineArgs.size()){
				std::cout << "Error! Error! No output file given!" << std::endl;
				return 0;
			}
			else{
				oFile_name = cmdLineArgs[i+1];
				std::cout << "Output file: " << cmdLineArgs[i+1] << std::endl;
				i++;
			}
		}
		if(cmdLineArgs[i] == "-i"){													// Checks for input file
			if(i+1==cmdLineArgs.size()){
				std::cout << "Error! Error! No input file given!" << std::endl;
				return 0;
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
	
	std::cout << "Please provide user input. When done press Enter followed by Ctrl+D." << std::endl;	// Provide instructions for use 
		
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
		
		else continue; 										// - Ignore any other (non-alpha) characters
		
	}
	
	std::cout << "My string is: " << my_str << std::endl;	// print out the new string
	
	return 0;
	
}