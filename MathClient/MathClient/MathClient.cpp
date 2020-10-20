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
void ClearInputStream(std::istream& in)
{
	in.clear();
	while (in.peek() != EOLN && in.peek() != EOF)
	{
		in.get();
	}
}
int Seek(std::istream& in)
{
	while (in.peek() != EOLN &&
		SKIP_CHARACTERS.find((char)in.peek()) !=
		std::string::npos)
	{
		in.get();
	}
	return in.peek();
}
bool CheckBounds(int n)
{
	bool ok = (LEFT_BOUND <= n && n <=
		RIGHT_BOUND);
	if (!ok)
	{
		std::cout << OUT_OF_BOUNDS_MESSAGE << " [" << LEFT_BOUND << ", " << RIGHT_BOUND << "]" << 
			std::endl;
	}
	return ok;
}
int ReadInt(std::istream& in)
{
	
	std::cout << INPUT_MESSAGE;
	int ans;
	in >> ans;
	while (!in || Seek(in) != EOLN ||
		!CheckBounds(ans))
	{
		ClearInputStream(in);
		std::cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans;
}


bool NeedContinue(std::istream& in)
{
	std::cout << CONTINUE_MESSAGE;
	char ans;
	in >> ans;
	while (!in || Seek(in) != EOLN || ans !=
		YES_CHAR && ans != NO_CHAR)
	{
		ClearInputStream(in);
		std::cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans == YES_CHAR;
}

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
	std::string ok = "y";
	
	do
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0; 
		int y2 = 0;
		int x3 = 0; 
		int y3 = 0;

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
		
		while (ok != "y" || ok != "n")
		{
			std::cout << "Continue? y/n: ";
			std::cin >> ok;
		}
	} while (ok == "y");
	return 0;
}