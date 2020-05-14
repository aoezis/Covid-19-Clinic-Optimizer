#pragma once
#include <string>
#include "maxHeap1.h"
#include "Doctor.h"
class simulator
{
public:
	simulator();
	~simulator();
	void simulate(string fileName, int max);
	int findOptimumDoctors(int maxAverage);

private:
	int numPatients;
	int numDoctors;
	Doctor* doctors;
	maxHeap1* prioque;
	Patient* patientarray;
};