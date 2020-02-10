#include <iostream>
#include <string>
#include <sstream>
#include <limits>

#include "Queue.hpp"

int n;
int lambda;
int mu;
int M;
void menu();

int main()
{
	menu();
}

void menu()
{
	do
	{
		std::string error = "";
		std::cout << "Input number of arrivals (1000 <= n <= 5000)" << std::endl;
		try
		{
			std::cin >> n;
			if(std::cin.fail())
			{
				throw error;
			}
			if(n < 1000 || n > 5000)
			{
				throw n;
			}
		}
		catch(int)
		{
			std::cout << "Input must be greater than or equal to 1000 and less than or equal to 5000" << std::endl;
		}
		catch(std::string error)
		{
			std::cout << "Invalid Input. Please input number" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
	} while(n < 1000 || n > 5000);

	std::cout << "Input average arrivals in a time period" << std::endl;
	std::cin >> lambda;

	std::cout << "Input average number served in a time period" << std::endl;
	std::cin >> mu;

	std::cout << "Input the number of service channels (1 <= M <= 10)" << std::endl;
	do
	{
		std::cin >> M;
		if(M < 1 || M > 10)
		{
			std::cout << "Input must be greater than or equal to 1 and less than or equal to 10" << std::endl;
		}
	} while(M < 1 || M > 10);
}