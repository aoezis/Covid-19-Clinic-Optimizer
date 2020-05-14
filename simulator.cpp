#include "simulator.h"
#include <fstream>

simulator::simulator() {
	this->prioque = new maxHeap1();
	this->numDoctors = 0;
	this->numPatients = 0;
}
simulator::~simulator() {
	prioque->~maxHeap1();
	if (patientarray != NULL) {
		delete[] patientarray;
		patientarray = NULL;
	}
	if (doctors != NULL) {
		delete[] doctors;
		doctors = NULL;
	}
}
void simulator::simulate(string fileName, int max) {

	string inputline;

	fstream file;
	file.open(fileName.c_str());
	int i = -1;
	numPatients = 0;
	while (getline(file, inputline)) {
		if (i == -1) {
			numPatients = atoi(inputline.c_str());
			patientarray = new Patient[numPatients];
		}
		else {
			string space= " ";
			int pos = 0;
			string array[1000];
			int j = 0;
			int numWords = 0;
			string token;
			while ((pos = inputline.find(space)) != string::npos){
				token = inputline.substr(0, pos);
				array[j] = token;
				j++;
				numWords++;
				inputline.erase(0, pos + space.length());
			}
			int id = atoi(array[0].c_str());
			int priority = atoi(array[1].c_str());
			int arrival = atoi(array[2].c_str());
			if (array[3] == "") {
				array[3] = inputline;
				inputline.erase();
			}
			int treatment = atoi(array[3].c_str());

			
			Patient p = Patient(id, priority, arrival, treatment);
			p.print();
			patientarray[i] = p;
		}
		i++;
	}
	file.close();
	numDoctors = findOptimumDoctors(max);
	cout << "Minimum numberof doctors required: " << numDoctors << endl;
	cout << "Simulation with " << numDoctors << " doctors." << endl;

	doctors = new Doctor[numDoctors];
	for (int i = 0; i < numDoctors; i++) {
		doctors[i] = Doctor(i);
	}
	for (int minute = 1; minute < 100; minute++) {
		for (int i = 0; i < numPatients; i++) {
			if (minute == patientarray[i].getTimeArrived()) {
				prioque->insert(patientarray[i]);
			}
		}
		//prioque->print();
		for (int i = 0; i < numPatients; i++) {
			int docIndex = -1;
			for (int j = numDoctors - 1; j >= 0; j--) {
				//cout << doctors[j].avalaible << endl;
				if (doctors[j].avalaible == 0) {
					docIndex = j;
				}
			}
		//	cout << i << "th iteration" << docIndex << endl;
			if (docIndex != -1 && !prioque->isEmpty()) {
				Patient treated;
				prioque->remove(treated);
				doctors[docIndex].avalaible = treated.getTreatmentTime();
				cout << "Doctor " << docIndex << " takes patient " << treated.getId() << " at minute " << minute << " (wait: " << minute - treated.getTimeArrived() << " mins)" << endl;
			}

		//	cout << "MIN"<<minute << endl;
		}


		for (int i = 0; i < numDoctors; i++) {
			if (doctors[i].avalaible != 0) doctors[i].avalaible--;
		}


	}
	delete[] doctors;
	doctors = NULL;
	
}
int simulator::findOptimumDoctors(int max)
{

	int avg = max + 100;
	int numDoctors = 0;
	while (avg > max) {
		int totalWait = 0;
		numDoctors++;
		doctors = new Doctor[numDoctors];
		for (int i = 0; i < numDoctors; i++) {
			doctors[i] = Doctor(i);
		}
		for (int minute = 1; minute < 500; minute++) {
			for (int i = 0; i < numPatients; i++) {
				
				if (minute == patientarray[i].getTimeArrived()) {
					prioque->insert(patientarray[i]);
				
				}
				
			}
			for (int i = 0; i < numPatients; i++) {
				int docIndex = -1;
				for (int i = numDoctors - 1; i >= 0; i--) {
					if (doctors[i].avalaible == 0) docIndex = i;
				}
				if (docIndex != -1 && !prioque->isEmpty()) {
					Patient treated;
					prioque->remove(treated);
					totalWait += minute - treated.getTimeArrived();
					doctors[docIndex].avalaible = treated.getTreatmentTime();
				}

			}
			for (int i = 0; i < numDoctors; i++) {
				if (doctors[i].avalaible != 0) doctors[i].avalaible--;
			}
		}
		delete[] doctors;
		doctors = NULL;
		avg = totalWait / numPatients;
		
	}
	return numDoctors;
	
}
int main(int argc, char** argv) {
	simulator s;
	int average;
	string fileName;
	if (argc > 1) {
		fileName = argv[1];
		average = atoi(argv[2]);
	}
	else {
		average = 5;
		fileName = "patients.txt";
	}
	s.simulate(fileName, average);
	//s.~simulator();
	
	/*if (_CrtDumpMemoryLeaks()) {
		std::cout << "Memory leaks!\n";
	}
	else {
		std::cout << "No leaks\n";
	}*/
	return 0;
}