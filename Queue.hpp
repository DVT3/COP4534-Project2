#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <queue>
#include <math.h>
#include <time.h>
#include <string>

#include "Customer.hpp"

class Queue
{
	public:
		Queue(int n, float lamda, float mu, int M);
		float GetNextRandomInterval(float avg);
		void InsertIntoPQ(Customer * C);
		int parent(int num) {return (num-1)/2;}
		int left(int num) {return (2*num + 1);}
		int right(int num) {return (2*num - 1);}
		void processStatistics();
		void processNextEvent();
		Customer * DeleteFromPQ();
		void MinHeapify(int num);
		void PrintResults();
	private:
		int TotalServers;
		int serverAvailableCnt;
		int numCustomers;
		float mu;
		int CustomerWaitedCnt = 0;
		float TotalWaitTime = 0;
		float TotalServiceTime = 0;
		float IdleTime = 0;
		int heap_size;
		Customer * PQ[10] = {nullptr};
		std::queue<Customer*> FIFO;
};

#endif