#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <queue>

#include "Customer.hpp"

class Queue
{
	public:
		Queue();
		void PriorityQueue();
		void processStatistics();
		void processNextEvent();
	private:
		int serverAvailableCnt;
		std::queue <Customer> FIFO;
};

#endif