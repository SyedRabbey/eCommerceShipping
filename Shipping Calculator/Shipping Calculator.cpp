//Syed Rabbey
//For shipping usage

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm> //compare/ranges

using namespace std;

// const variables for shipping costs
const float fragileShipping = 2.00;
const float notFragile = 0.00;

const float freeShipping = 0.00;

const float usaShipping1 = 6.00;
const float usaShipping2 = 9.00;
const float usaShipping3 = 12.00;

const float canShipping1 = 8.00;
const float canShipping2 = 12.00;
const float canShipping3 = 15.00;

const float ausShipping1 = 10.00;
const float ausShipping2 = 14.00;
const float ausShipping3 = 17.00;



int main()
{

    string itemName;
    string fragile;
    float orderCost;
    string destination;
    float shippingCost;
    float finalCost;
    float extraShipping;
    float totalShipping;

    // writing to order file
    ofstream outFile;
    outFile.open("Order.txt");
    if (outFile.fail())
    {
        return 0;
    }

    cout << fixed << setprecision(2);

    // introduction statement
    cout << setw(50) << setfill('*') << "" << endl;
    cout << "International Shipping Calculator" << endl;
    cout << setw(50) << setfill('*') << "" << endl;

    // user input 
    cout << "Please enter the item name (no spaces)" << setfill('.') << setw(11) << ":" << itemName;
    cin >> itemName;

    transform(itemName.begin(), itemName.end(), itemName.begin(), toupper);


    cout << "Is this item fragile? (y=yes/n=no)" << setw(15) << ":" << fragile;
    cin >> fragile;
    // else if statement to calculate the shipping cost
    if (fragile == "Y")
        extraShipping = fragileShipping;
    else if (fragile == "y")
        extraShipping = fragileShipping;
    else if (fragile == "N")
        extraShipping = notFragile;
    else if (fragile == "n")
        extraShipping = notFragile;
    else {
        cout << "Invalid entry, program canceled" << endl;
        // returning 0 will exit the program
        return 0;
    }


    // collect the user input for the order total
    cout << "Please enter your order total" << setw(20) << ":";
    cin >> orderCost;

    // collect user input for the destination of the item
    cout << "Please enter your destination. (usa/can/aus)" << setw(5) << ":" << destination;
    cin >> destination;

    transform(destination.begin(), destination.end(), destination.begin(), toupper);

    // if statement to calculate shipping cost based on destination and order total

    // shipping to usa
    if (destination == "USA")
        if (orderCost <= 50.00)
            shippingCost = usaShipping1;
        else if ((orderCost >= 50.01) && (orderCost <= 100.00))
            shippingCost = usaShipping2;
        else if ((orderCost >= 100.01) && (orderCost >= 150.00))
            shippingCost = usaShipping3;
        else
            shippingCost = freeShipping;
    // shipping to canada
    else if (destination == "CAN")
        if (orderCost <= 50.00)
            shippingCost = canShipping1;
        else if ((orderCost >= 50.01) && (orderCost <= 100.00))
            shippingCost = canShipping2;
        else if ((orderCost >= 100.01) && (orderCost >= 150.00))
            shippingCost = canShipping3;
        else
            shippingCost = freeShipping;
    // shipping to australia
    else if (destination == "AUS")
        if (orderCost <= 50.00)
            shippingCost = ausShipping1;
        else if ((orderCost >= 50.01) && (orderCost <= 100.00))
            shippingCost = ausShipping2;
        else if ((orderCost >= 100.01) && (orderCost >= 150.00))
            shippingCost = ausShipping3;
        else
            shippingCost = freeShipping;
    
    else {
        cout << "Invalid entry, exiting" << endl;
        return 0;
    }

    // calculating total shipping cost
    totalShipping = extraShipping + shippingCost;

    // calculating final cost
    finalCost = totalShipping + orderCost;

    cout << "" << endl;

    cout << "Your item is" << setw(30) << itemName << endl;

    cout << "Your shipping cost is" << setw(18) << totalShipping << endl;

    cout << "You are shipping to" << setw(22) << destination << endl;

    cout << "Your total shipping costs are" << setw(10) << "$" << finalCost << endl;

    // writing output to new file - Order.txt
    outFile << "Your item is" << setw(30) << itemName << endl;
    outFile << "Your shipping cost is" << setw(18) << totalShipping << endl;
    outFile << "You are shipping to" << setw(22) << destination << endl;
    outFile << "Your total shipping costs are" << setw(10) << "$" << finalCost << endl;

    outFile.close();

    return 0;
}
