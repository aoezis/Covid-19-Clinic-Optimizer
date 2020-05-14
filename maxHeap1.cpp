#include"maxHeap1.h"
maxHeap1::maxHeap1() {
	patients = new Patient[MAX_PATIENT];
	size = 0;
}
maxHeap1::~maxHeap1() {
	if (patients != NULL) {
		delete[] patients;
		patients = NULL;
	}
}
bool maxHeap1::decide(const int pat1, const int pat2) {
	return patients[pat1].getPrio() > patients[pat2].getPrio() ||
		(patients[pat1].getPrio() == patients[pat2].getPrio() && patients[pat1].getTimeArrived() < patients[pat2].getTimeArrived());
}
void maxHeap1::insert(const Patient& patient) {
	if (size >= MAX_PATIENT) {
		cout << "Cannot add more patients to the queue" << endl;
		return;
	}
	patients[size] = patient;
	int current = size;
	int parent = (current - 1) / 2;
	while (current > 0 && decide(current, parent))
	{
		Patient temp = patients[parent];
		patients[parent] = patients[current];
		patients[current] = temp;
		current = parent;
		parent = (current - 1) / 2;
	}
	size++;
}
void maxHeap1::remove(Patient& patient) {
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
		return;
	}
	patient = patients[0];
	size--;
	patients[0] = patients[size];

		heapify(0);
	
}
void maxHeap1::heapify(int node) {
	int child = node * 2 + 1;
	if (child < size) {
		int right = child + 1;
		if (right<size && decide(right,child))
			child = right;
		if (decide(child, node)) {
			Patient temp = patients[node];
			patients[node] = patients[child];
			patients[child] = temp;
			heapify(child);
		}		
	}
}
bool maxHeap1::isEmpty() const {
	return size == 0;
}
void maxHeap1::print() {
	for (int i = 0; i < size; i++)
		patients[i].print();
}