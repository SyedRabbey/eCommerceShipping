#include "Attendee.h"
using namespace std;

void Attendee::setFirstName(string fn) {
	firstname = fn;
}
string Attendee::getFirstName()const {
	return firstname;
}

void Attendee::setLastName(string ln) {
	lastname = ln;
}
string Attendee::getLastName() const {
	return lastname;
}

Attendee::Attendee(string fn, string ln) {
	setFirstName(fn);
	setLastName(ln);
}
