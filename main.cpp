#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <math.h>

#include "Queue.hpp"

/***************************************************************
Student Name: Daniel Tran
File Name: main.cpp
Assignment number: Project 2

This the the main file for project 2. This file will ask the user
for 2 integer inputs and 2 float inputs. It will then calculate
and print out the analytical model of the simulation in this
project. It will then run the simulation, which will also print
out the simulation results.
***************************************************************/

int n;
float lambda;
float mu;
int M;

void menu();

void AnalyzeModel();
float CalculateIdleTime();
float CalculateAvgNumPeopleSystem(float Po);
float CalculateAvgTimeInSystem(float L);
float CaluclateAvgCustomerQueue(float L);
float CalculateAvgWait(float Lq);
float CalculateUtilizationFactor();
int factorial(int num);

int main()
{
	menu();
	AnalyzeModel();
	new Queue(n, lambda, mu, M);
}

void AnalyzeModel()
{
	float Po = CalculateIdleTime();
	float L = CalculateAvgNumPeopleSystem(Po);
	float W = CalculateAvgTimeInSystem(L);
	float Lq = CaluclateAvgCustomerQueue(L);
	float Wq = CalculateAvgWait(Lq);
	float rho = CalculateUtilizationFactor();

	std::cout << "Analytical Model:" << std::endl;
	std::cout << "Idle Time - " << Po << std::endl;
	std::cout << "Average Number of People in System - " << L << std::endl;
	std::cout << "Average Time Customer Spends in System - " << W << std::endl;
	std::cout << "Average Number of Customers in Queue - " << Lq << std::endl;
	std::cout << "Average Time Customer is in Queue - " << Wq << std::endl;
	std::cout << "Utilization Factor for the System - " << rho << std::endl;
}

int factorial(int num)
{
	int fact = 1;
	for(int i = 0; i <= num; i++)
	{
		fact = fact * i;
	}
	return fact;
}

float CalculateIdleTime()
{
	float summation = 0;
	float number;
	for(int i = 0; i <= M - 1; i++)
	{
		number = (1 / factorial(i)) * pow((lambda / mu), i);
		summation += number;
	}
	float IdleTime = 1 / (summation + (1 / factorial(M)) * pow((lambda / mu), M) * ((M * mu) / (M * mu - lambda)));
	return IdleTime;
}

float CalculateAvgNumPeopleSystem(float Po)
{
	float L = ((lambda * mu * pow((lambda / mu), M)) / ((factorial(M - 1)) * pow((M * mu - lambda), 2))) * Po + (lambda / mu);
	return L;
}

float CalculateAvgTimeInSystem(float L)
{
	return L / lambda;
}

float CaluclateAvgCustomerQueue(float L)
{
	return L - (lambda / mu);
}

float CalculateAvgWait(float Lq)
{
	return Lq / lambda;
}

float CalculateUtilizationFactor()
{
	return lambda / (M * mu);
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