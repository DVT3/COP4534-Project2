#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

/***************************************************************
Student Name: Daniel Tran
File Name: Customer.hpp
Assignment number: Project 2

This is the customer file. This is where all the information
pertaining to the customer is stored. The customer object is
initialized with an arrival time. Afterwards, The start of service
time and departing time is set later. The customer also has a 
priority value, which determine where they go in the priority
queue. The priority value is set based off the arrival time
and the departing time. The customer also has a boolean value
that tells the simulation whether or not the customer is arriving
or departing.
***************************************************************/

class Customer
{
	public:
		Customer(float arrival) {arrivalTime = arrival; priority = arrival;}
		void setStartOfServiceTime(float serviceStart) {startOfServiceTime = serviceStart;}
		void setDepartureTime(float departure) {departureTime = departure; priority = departure;}
		void setWaitTime(float wait) {waitTime = startOfServiceTime - arrivalTime;}
		void setNextCustomer(Customer * next) {nextCustomer = next;}
		float getPriority() {return priority;}
		float getArrivalTime() {return arrivalTime;}
		float getDepartureTime() {return departureTime;}
		float getStartOfServiceTime() {return startOfServiceTime;}
		float getWaitTime() {return waitTime;}
		void customerIsDeparting() {customerArrival = false;}
		bool isArrival() {return customerArrival;}
	private:
		float arrivalTime;
		float startOfServiceTime;
		float departureTime;
		float waitTime = 0;
		float priority;
		bool customerArrival = true;
		Customer * nextCustomer = nullptr;
};

#endif