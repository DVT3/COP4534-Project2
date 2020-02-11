#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <queue>
#include <math.h>
#include <time.h>

#include "Customer.hpp"

class Queue
{
	public:
		Queue(int n, float lamda, float mu, int M);
		bool isEmpty();
		float GetNextRandomInterval(float avg);
		void InsertIntoPriorityQueue();
		void processStatistics();
		void processNextEvent();
	private:
		Customer * front == NULL;
		int serverAvailableCnt;
		int numCustomers;
		float mu;
		std::queue <Customer> FIFO;
};

#endif