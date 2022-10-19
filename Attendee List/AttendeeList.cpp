#include "AttendeeList.h"
#include <iostream>
using namespace std;

AttendeeList::AttendeeList() {
    position = 0;

    for (int i = 0; i < 5; ++i) {
        list[i] = nullptr;
    }
}

AttendeeList::~AttendeeList() {
    for (int i = 0; i < position; ++i) {
        delete list[i];
    }
}

void AttendeeList::addAttendee(string fn, string ln) {
    if (position == 5) { //business rule
        return; //do nothing
    }
    list[position++] = new Attendee(fn, ln);
}
Attendee* AttendeeList::getAttendee(int i) const {
    if (i < 0 || i >= position) { //business rule
        return nullptr; 
    }
    return list[i];
}

int AttendeeList::getSize() const {
    return position;
}

void AttendeeList::print() const {

    cout << "--- ATTENDEE LIST ---" << endl;

    for (int i = 0; i < 5; ++i) {
        if (list[i] != nullptr) {
            cout << list[i]->getFirstName() + " " + list[i]->getLastName();
        }
        else {
            cout << "[Empty]";
        }
        cout <<endl;
    }
}