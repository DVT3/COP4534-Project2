#include "Queue.hpp"

Queue::Queue(int n, float lamda, float mu, int M)
{
	serverAvailableCnt = M;
	numCustomers = n;
	this->mu = mu;

	for(int i = 0; n < 200; i++)
	{
		int arrivalTime = GetNextRandomInterval(lamda)
		InsertIntoPriorityQueue(new Customer(arrivalTime));
		numCustomers--;
	}

	while(isEmpty() == false)
	{
		processNextEvent();
		if()
	}
}

bool Queue::isEmpty()
{
	if(front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float GetNextRandomInterval(float avg)
{
	srand(time(NULL));
	float f = (float)rand()/1;
	float IntervalTime = -1 * (1.0/avg) * log(f);
	return IntervalTime;
}

void InsertIntoPriorityQueue(Customer * Cust)
{
	Customer * temp;
	if(front == NULL || Cust->getPriority() < front->getPriority())
	{
		Cust->setNextCustomer = front;
		front = Cust;
	}
	else
	{
		temp = front;
		while(temp->getNextCustomer() != NULL && temp->getNextCustomer()->getPriority() <= Cust->getPriority())
		{
			temp = temp->getNextCustomer();
			Cust->getNextCustomer() = temp->getNextCustomer();
			temp->getNextCustomer = Cust;
		}
	}
}

void Queue::processNextEvent()
{
	Customer * Cust = front;
	front = front->getNextCustomer();
	if(Cust->isArrival() == true)
	{
		if(serverAvailableCnt > 0)
		{
			serverAvailableCnt--;
			float startOfServiceTime = Cust->getArrivalTime();
			float interval = GetNextRandomInterval(mu);
			float departureTime = arrivalTime + interval;
			Cust->setDepartureTime(departureTime);
			Cust->customerIsDeparting();
			InsertIntoPriorityQueue(Cust);
		}
		else
		{
			FIFO.push(Cust);
		}
	}
	else
	{
		Customer * temp;
		serverAvailableCnt++;
		processStatistics();
		if(!FIFO.empty())
		{
			temp = FIFO.pop();
			float startOfServiceTime = Cust->getDepartureTime();
			float interval = GetNextRandomInterval(mu);
			float departureTime = arrivalTime + interval;
			temp->setDepartureTime(departureTime);
			temp->customerIsDeparting();
			InsertIntoPriorityQueue(temp);
		}
	}
}