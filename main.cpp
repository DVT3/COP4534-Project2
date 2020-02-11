#include <iostream>
#include <string>
#include <sstream>
#include <limits>

#include "Queue.hpp"

int n;
float lambda;
float mu;
int M;
void menu();

int main()
{
	menu();
}

void menu()
{
	std::string error = "";

	do
	{
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

	do
	{
		std::cout << "Input average arrivals in a time period" << std::endl;
		try
		{
			std::cin >> lambda;
			if(std::cin.fail())
			{
				throw error;
			}
			if(lambda <= 0)
			{
				throw lambda;
			}
		}
		catch(float)
		{
			std::cout << "Input must be greater than 0" << std::endl;
		}
		catch(std::string error)
		{
			std::cout << "Invalid Input. Please input number" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
	} while(lambda <= 0);

	do
	{
		std::cout << "Input average number served in a time period" << std::endl;
		try
		{
			std::cin >> mu;
			if(std::cin.fail())
			{
				throw error;
			}
			if(mu <= 0)
			{
				throw mu;
			}
		}
		catch(float)
		{
			std::cout << "Input must be greater than 0" << std::endl;
		}
		catch(std::string error)
		{
			std::cout << "Invalid Input. Please input number" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
	} while(mu <= 0);

	do
	{
		std::cout << "Input the number of service channels (1 <= M <= 10)" << std::endl;
		try
		{
			std::cin >> M;
			if(std::cin.fail())
			{
				throw error;
			}
			if(M < 1 || M > 10)
			{
				throw M;
			}
		}
		catch(int)
		{
			std::cout << "Input must be greater than or equal to 1 or less then or equal to 10" << std::endl;
		}
		catch(std::string error)
		{
			std::cout << "Invalid Input. Please input number" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
	} while(M < 1 || M > 10);
}