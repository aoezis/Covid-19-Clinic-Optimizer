#include"Patient.h"
Patient::Patient() {

}
Patient::Patient(int id, int prio, int timeArrived, int treatmentTime) {
	this->id = id;
	this->prio = prio;
	this->timeArrived = timeArrived;
	this->treatmentTime = treatmentTime;
}
Patient::~Patient()
{
}
int Patient::getId() const {
	return id;
}
int Patient::getPrio() const{
	return prio;
}
 int Patient::getTimeArrived() const {
	return timeArrived;
}
 int Patient::getTreatmentTime() const{
	return treatmentTime;
}
void Patient::operator=(const Patient& patient)
{
	id = patient.getId();
	prio = patient.getPrio();
	timeArrived = patient.getTimeArrived();
	treatmentTime = patient.getTreatmentTime();
}
void Patient::print()
{
	cout << id << " " << prio << " " << timeArrived << " " << treatmentTime << endl;
}
