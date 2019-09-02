#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

bool compareDouble(double a, double b){
    return fabs(a - b) < 0.001;   
}

int main(){
    bool read = true;
    double value;

    while(read){
        cin >> value;

        if(compareDouble(value, 0.00)){ //checks if read value is equal to 0.00
            read = false;
        } else {
            cout << fixed << setprecision(2) << left << setw(17) 
            << value << "4" << endl;
            cout << fixed << setprecision(2) << left << setw(17) 
            << "200.00" << "293" << endl;
        }
    }

    return 0;
}