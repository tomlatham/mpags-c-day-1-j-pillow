#include <iostream>
int main()
{
	// This is a comment
	/* This is a 
	Multiline comment */

	//std::cout << "Hello World!\n";
	
	int a{9};
	int b{124};
	int c{1};
	
	c = a + b;
	
	std::cout << c << std::endl;
	
	double d{142.6};
	
	std::cout << d << std::endl;
	
	int h{d};
	
	std::cout << h << std::endl;
	
	return 0;
	
}