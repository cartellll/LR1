//#include <iostream>
//#include "MathLibrary.h"

//int main()
//{
//    std::cout << geron(0,0,0,3,3,0);
//}

#include <iostream>
#include <string>
#include "MathLibrary.h"
const char EOLN = '\n';
const char YES_CHAR = 'Y';
const char NO_CHAR = 'N';
const int LEFT_BOUND = -1000000000;
const int RIGHT_BOUND = +1000000000;
const std::string ABOUT_MESSAGE = "Area of a triangle";
const std::string CONTINUE_MESSAGE =
"Continue? (Y/N)>";
const std::string INCORRECT_MESSAGE =
"Input is incorrect. Try again>";

const std::string INPUT_MESSAGE = "Input an integer > ";
const std::string OUT_OF_BOUNDS_MESSAGE =
"This number is out of bounds";
const std::string OUTPUT_MESSAGE = "Result: ";
const std::string SKIP_CHARACTERS = " ";


int ReadCorrectValue(int num) {
	while (!(std::cin >> num) || (std::cin.peek() != '\n')) {
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Input is incorrect. Try again>\n";
	}
	return num;
}

int main()
{
	std::cout << ABOUT_MESSAGE << std::endl;
	std::string ok = "";

	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	int x3 = 0;
	int y3 = 0;

	do
	{
		ok = "";
		std::cout << "x1:" << std::endl;
		x1 = ReadCorrectValue(x1);
		
		std::cout << "y1:" << std::endl;
		y1 = ReadCorrectValue(y1);
		
		std::cout << "x2:" << std::endl;
		x2 = ReadCorrectValue(x2);

		std::cout << "y2:" << std::endl;
		y2 = ReadCorrectValue(y2);

		std::cout << "x3:" << std::endl;
		x3 = ReadCorrectValue(x3);

		std::cout << "y3:" << std::endl;
		y3 = ReadCorrectValue(y3);

		double area = geron(x1, y1, x2, y2, x3, y3);
		if (area == 0)
		{
			std::cout << "points are located on one straight line" <<std::endl;
		}

		else
		{

			std::cout << OUTPUT_MESSAGE <<
				area << std::endl;
		}
		
		while (ok != "y" && ok != "n")
		{
			std::cout << "Continue? y/n: ";
			std::cin >> ok;
		}
	} while (ok == "y");
	return 0;
}