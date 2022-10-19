#pragma once
#include <iostream>
using namespace std;

class Attendee {
private:
	string firstname;
	string lastname;
public: 
	void setFirstName(string fn);
	void setLastName(string ln);
	string getFirstName() const;
	string getLastName() const;
	Attendee(string fn, string ln);
};
