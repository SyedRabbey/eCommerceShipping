#include <iostream>
#include "Attendee.h"
#include "attendeelist.h"

using namespace std;

void addAttendeeDialog(AttendeeList& aList) { //requests required info to add an attendee
    if (aList.getSize() >= 5) {
        cout << "List is full. A new attendee cannot be added." << endl;
        return;
    }

    string fn, ln;

    cout << "\t--- Add an attendee ---";
    cout << "\n\tEnter attendee's first name: ";
    cin >> fn;
    cout << "\tEnter attendee's last name: ";
    cin >> ln;

    aList.addAttendee(fn, ln);
}

int main() {

    AttendeeList list;

    int option = 1;

    list.print();

    while (option != 2) {

        cout << "\n--- MENU ---";
        cout << "\n1. Add an attendee.";
        cout << "\n2. Exit.";
        cout << "\nChoose an option [1-2]: ";

        cin >> option;

        switch (option) {
        case 1: {
            addAttendeeDialog(list);
            list.print();
            break;
        }

        case 2:
            break;

        default:
            cout << "Invalid option. Try again." << endl;
        }

    }

    return 0;
}