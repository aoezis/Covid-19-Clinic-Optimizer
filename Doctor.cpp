#include "Doctor.h"
Doctor::Doctor(int id) {
	this->id = id;
	this->avalaible = 0;
}
Doctor::Doctor() {

}
void Doctor::operator=(const Doctor& doc) {
	id = doc.id;
	avalaible = doc.avalaible;
}