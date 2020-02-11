#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

class Customer
{
	public:
		Customer(float arrival) {arrivalTime = arrival; priority = arrival;}
		void setStartOfServiceTime(float service) {startOfServiceTime = service;}
		void setDepartureTime(float departure) {departureTime = departure; priority = departure;}
		void setNextCustomer(Customer * next) {nextCustomer = next;}
		float getPriority() {return priority;}
		float getArrivalTime() {return arrivalTime;}
		void customerIsDeparting() {customerArrival = false;}
		bool isArrival() {return customerArrival;}
	private:
		float arrivalTime;
		float startOfServiceTime;
		float departureTime;
		float priority;
		bool customerArrival = true;
		Customer * nextCustomer;
};

#endif