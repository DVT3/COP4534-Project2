#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

class Customer
{
	public:
		Customer(float arrival) {arrivalTime = arrival;}
		void setStartOfServiceTime(float service) {startOfServiceTime = service;}
		void setDepartureTime(float departure) {departureTime = departure;}
		void setNextCustomer(Customer * next) {nextCustomer = next;}
	private:
		float arrivalTime;
		float startOfServiceTime;
		float departureTime;
		Customer * nextCustomer;
};

#endif