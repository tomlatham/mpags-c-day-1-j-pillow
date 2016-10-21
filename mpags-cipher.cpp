#include <iostream>
#include <string>

int main()
{
	// Take each letter from user input and in each case:
	
	
	std::string my_str = {""};
	char in_char{'x'};
	char upper_char{'y'};
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
		
		else continue; 										// - Ignore any other (on-alpha) characters
		
	}
	
	std::cout << "My string is: " << my_str << std::endl;	// print out the new string
	
	return 0;
	
}