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
int main()
{
	std::cout << ABOUT_MESSAGE << std::endl;
	bool cont = true;
	while (cont)
	{
		std::cout << "x1:" << std::endl;
		int x1 = ReadInt(std::cin);
		
		std::cout << "y1:" << std::endl;
		int y1 = ReadInt(std::cin);
		
		std::cout << "x2:" << std::endl;
		int x2 = ReadInt(std::cin);

		std::cout << "y2:" << std::endl;
		int y2 = ReadInt(std::cin);

		std::cout << "x3:" << std::endl;
		int x3 = ReadInt(std::cin);

		std::cout << "y3:" << std::endl;
		int y3 = ReadInt(std::cin);

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
		
		cont = NeedContinue(std::cin);
	}
	return 0;
}