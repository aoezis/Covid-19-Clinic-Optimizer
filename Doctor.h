#pragma once
#include <iostream>
using namespace std;
class Doctor {
public:
	Doctor(int id);
	Doctor();
	void operator=(const Doctor&);
	int id;
	int avalaible;
};