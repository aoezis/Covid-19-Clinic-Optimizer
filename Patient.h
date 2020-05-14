#pragma once
#include <iostream>
using namespace std;
class Patient {
public:
	Patient(int id, int prio, int timeArrived, int treatmentTime);
	Patient();
	~Patient();
	void operator=(const Patient&);
	void print();
	 int getId() const;
	int getPrio() const;
	 int getTimeArrived() const;
	int getTreatmentTime() const; 
private:
	int id;
	int prio;
	int timeArrived;
	int treatmentTime;
};