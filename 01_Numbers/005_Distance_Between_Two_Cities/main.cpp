// Distance Between Two Cities - Calculates the distance between
// two cities and allows the user to specify a unit of distance.
// This program may require finding coordinates for the cities like latitude and longitude.
// Dmytro Frolov
#include <iostream>
#include <cmath>

const float EARTH_RADIUS = 6371;
const double  PI = 3.1415926535;
const float DEGREES_IN_CIRCLE = 360;
const float KILOMETERS_IN_MILE = 1.609344;

double toRad(double angle);
using namespace std;

int main() {
    double latitude1 = 49.83, longitude1 = 24.01, latitude2  = 50.45, longitude2 = 30.52, distance = 0;
    cout << "To calculate distance of two cities\nit is necessary to input lat ang long\nfor both of them\n";
    cout << "input latitude 1 : ";
    cin >> latitude1;
    cout << "input longitude 1 : ";
    cin >> longitude1;
    cout << "input latitude 2 : ";
    cin >> latitude2;
    cout << "input longitude 2 : ";
    cin >> longitude2;
    cout << "Do you want distance in kilometers - 1 or in miles - 2? \n(1 or 2): ";
    int units = 0;
    cin >> units;
    latitude1=toRad(latitude1);
    longitude1=toRad(longitude1);
    latitude2=toRad(latitude2);
    longitude2=toRad(longitude2);

    distance=acos(cos(latitude1)*cos(latitude2)*cos(longitude2-longitude1)+sin(latitude1)*sin(latitude2));
    distance*=EARTH_RADIUS;
    cout << "Distance between cities = ";
    if(units==1)
        cout << distance << " kilometers." << endl;
    else
        cout << distance / KILOMETERS_IN_MILE << " miles." << endl;
    return 0;
}



double toRad(double angle) {
    return angle / DEGREES_IN_CIRCLE * PI * 2;
}