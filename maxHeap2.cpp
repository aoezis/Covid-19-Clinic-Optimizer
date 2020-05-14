#include"maxHeap2.h"
maxHeap2::maxHeap2() {
	patients = new Patient[staticSize];
	size = 0;
}
maxHeap2::~maxHeap2() {
	if (patients != NULL) {
		delete[] patients;
		patients = NULL;
	}
}
bool maxHeap2::decide(const int pat1, const int pat2) {
	return patients[pat1].getPrio() > patients[pat2].getPrio() ||
		(patients[pat1].getPrio() == patients[pat2].getPrio() && patients[pat1].getTimeArrived() < patients[pat2].getTimeArrived());
}
void maxHeap2::insert(const Patient& patient) {
	if (size >=staticSize) {
		Patient* temp = new Patient[staticSize];
		
		for (int i = 0; i < staticSize; i++) {
			temp[i] = patients[i];
		}
		delete[] patients;
		patients = new Patient[staticSize * 2];
		for (int i = 0; i < staticSize; i++) {
			patients[i] = temp[i];
		}
		delete[] temp;
		staticSize = staticSize * 2;
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
void maxHeap2::remove(Patient& patient) {
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
		return;
	}
	patient = patients[0];
	size--;
	patients[0] = patients[size];
	if (size <= staticSize / 2 &&size>=10) {
		Patient* temp = new Patient[size];

		for (int i = 0; i < size; i++) {
			temp[i] = patients[i];
		}
		delete[] patients;
		patients = new Patient[staticSize/2];
		for (int i = 0; i < size; i++) {
			patients[i] = temp[i];
		}
		delete[] temp;
		staticSize = staticSize / 2;
	}
	heapify(0);

}
void maxHeap2::heapify(int node) {
	int child = node * 2 + 1;
	if (child < size) {
		int right = child + 1;
		if (right < size && decide(right, child))
			child = right;
		if (decide(child, node)) {
			Patient temp = patients[node];
			patients[node] = patients[child];
			patients[child] = temp;
			heapify(child);
		}
	}
}
bool maxHeap2::isEmpty() const {
	return size == 0;
}
void maxHeap2::print() {
	for (int i = 0; i < size; i++)
		patients[i].print();
}