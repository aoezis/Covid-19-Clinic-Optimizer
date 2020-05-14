all:
	g++ simulator.cpp maxHeap1.cpp Patient.cpp Doctor.cpp -o simulator_Q1
	g++ simulator2.cpp maxHeap2.cpp Patient.cpp Doctor.cpp -o simulator_Q2
	./simulator_Q1
	./simulator_Q2
