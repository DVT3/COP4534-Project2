#include "Queue.hpp"

/***************************************************************
Student Name: Daniel Tran
File Name: Queue.cpp
Assignment number: Project 2

This is the Queue file. This file will take in the user inputs
and run the simulated queue. The program will start by inserting
a fixed amount of customers into the priority queue. Afterwards,
the simulation will continue to add customers into the queue as
long as there are remaining customers and the queue is not full.
If the queue is full, then the customer will be moved to the FIFO
queue. When leaving the queue, the program checks if the Customer
is leaving or not. If so, then the customer is removed from the
priority queue, and some statistics will be calculated. Then the
customer is inserted back into the queue lableded as departing. If
the customer is departing, the program processes the statistics
for that customer, and then checks if there is a customer in the
FIFO queue. if so, then that customer is added into the priority
queue. After the simulation is over, the simulation results is 
printed out.
***************************************************************/

Queue::Queue(int n, float lamda, float mu, int M)
{
	serverAvailableCnt = TotalServers = M;
	numCustomers = n;
	this->mu = mu;

	this->heap_size = 0;

	for(int i = 0; i < M; i++)
	{
		InsertIntoPQ(new Customer(GetNextRandomInterval(lamda)));
		numCustomers--;
	}

	while(heap_size != 0)
	{
		processNextEvent();
		if(numCustomers > 0 && this->heap_size <= M + 1)
		{
			InsertIntoPQ(new Customer(GetNextRandomInterval(lamda)));
			numCustomers--;
		}
	}

	std::cout << "Simulation Results:" << std::endl;
	std::cout << "Idle Time - " << IdleTime << std::endl;
	std::cout << "Average Time Customer Spends in System - " << (TotalServiceTime + TotalWaitTime) / n << std::endl;
	std::cout << "Average Time Customer is in Queue - " << TotalWaitTime / n << std::endl;
	std::cout << "Utilization Factor for the System - " << (M * (TotalServiceTime + TotalWaitTime)) / TotalServiceTime << std::endl;
}

float Queue::GetNextRandomInterval(float avg)
{
	srand(time(NULL));
	float f = (float)rand()/1;
	float IntervalTime = -1 * (1.0/avg) * log(f);
	return IntervalTime;
}

void Queue::InsertIntoPQ(Customer * C)
{
	this->heap_size++;
	int i = this->heap_size - 1;
	PQ[i] = C;

	while(i != 0 && PQ[parent(i)]->getPriority() > PQ[i]->getPriority())
	{
		Customer * temp = PQ[i];
		PQ[i] = PQ[parent(i)];
		PQ[parent(i)] = temp;
		i = parent(i);
	}
}

Customer * Queue::DeleteFromPQ()
{
	if(this->heap_size == 1)
	{
		this->heap_size--;
		return PQ[0];
	}

	Customer * root = PQ[0];
	PQ[0] = PQ[this->heap_size - 1];
	this->heap_size--;
	MinHeapify(0);

	return root;
}

void Queue::MinHeapify(int num)
{
	int l = left(num);
	int r = right(num);
	int min = num;
	if(l < this->heap_size && PQ[l]->getPriority() < PQ[num]->getPriority())
	{
		min = l;
	}
	if(r < this->heap_size && PQ[r]->getPriority() < PQ[min]->getPriority())
	{
		min = r;
	}
	if(min != num)
	{
		Customer * temp = PQ[num];
		PQ[num] = PQ[min];
		PQ[min] = temp;
		MinHeapify(min);
	}
}

void Queue::processStatistics()
{
	if(PQ[0]->getWaitTime() > 0)
	{
		CustomerWaitedCnt++;
	}
	TotalWaitTime += PQ[0]->getWaitTime();
	TotalServiceTime += (PQ[0]->getDepartureTime() + PQ[0]->getStartOfServiceTime());
	if(serverAvailableCnt == TotalServers)
	{
		IdleTime += (PQ[0]->getStartOfServiceTime() - PQ[0]->getArrivalTime());
	}
}

void Queue::processNextEvent()
{
	if(PQ[0]->isArrival() == true)
	{
		Customer * C = DeleteFromPQ();
		if(serverAvailableCnt > 0)
		{
			serverAvailableCnt--;
			C->setStartOfServiceTime(C->getArrivalTime());
			C->setDepartureTime(GetNextRandomInterval(mu) + C->getArrivalTime());
			C->customerIsDeparting();
			InsertIntoPQ(C);
		}
		else
		{
			FIFO.push(C);
		}
	}
	else
	{
		serverAvailableCnt++;
		processStatistics();
		Customer * C = DeleteFromPQ();
		if(!FIFO.empty())
		{
			Customer * F = FIFO.front();
			FIFO.pop();
			F->setStartOfServiceTime(C->getDepartureTime());
			F->setDepartureTime(GetNextRandomInterval(mu) + F->getStartOfServiceTime());
			F->setWaitTime(F->getStartOfServiceTime() - F->getArrivalTime());
			F->customerIsDeparting();
			InsertIntoPQ(F);
			serverAvailableCnt--;
		}
	}
}