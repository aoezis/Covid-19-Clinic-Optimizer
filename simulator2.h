#pragma once
#include <string>
#include "maxHeap2.h"
#include "Doctor.h"
class simulator2
{
public:
	simulator2();
	~simulator2();
	void simulate(string fileName, int max);
	int findOptimumDoctors(int maxAverage);

private:
	int numPatients;
	int numDoctors;
	Doctor* doctors;
	maxHeap2* prioque;
	Patient* patientarray;
};