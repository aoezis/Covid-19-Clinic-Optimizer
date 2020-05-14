#pragma once
#include"Patient.h"
static int staticSize = 10;
class maxHeap2 {
public:
	maxHeap2();
	~maxHeap2();
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