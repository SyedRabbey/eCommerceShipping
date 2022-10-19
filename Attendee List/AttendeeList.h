#pragma once
#include <string>
#include "Attendee.h"
using namespace std;

class AttendeeList {
private: 
	Attendee* list[5];
	int position;
public:
	void addAttendee(string fn, string ln);
	Attendee* getAttendee(int i) const;
	int getSize() const;
	void print() const;
	AttendeeList();
	~AttendeeList();

};