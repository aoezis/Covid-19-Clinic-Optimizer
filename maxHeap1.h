#pragma once
#include"Patient.h"
const int MAX_PATIENT = 2000;
class maxHeap1 {
public:
	maxHeap1();
	~maxHeap1();
	void insert(const Patient& patient);
	void remove(Patient& patient);
	
	bool isEmpty() const;
	bool decide(const int pat1, const int pat2);
	void print();
protected:
	void heapify(int node); //rebuilds the semiheap in node to heap
private:
	Patient* patients;
	int size;
};