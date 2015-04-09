/**
* 02_Find e to the Nth Digit 
* Dmytro Frolov
* Apr, 2015
* This program can generate e number to 15th digit
*/


#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::abs;
using std::pow;
using std::setprecision;

unsigned long long factorial(int n){
	unsigned long long result = 1;
	for(int i = 1; i<=n; i++)
		result*=i;
	return result;
}
typedef double fT;
fT findE(fT previousE, int depth, int currentDepth){
	fT currentE = previousE + 1.0/(factorial(currentDepth));
	//cout << currentE << endl;
	if( abs(currentE - previousE) < pow(10, -depth) ){
		cout << currentE << " " << previousE << endl;
		return currentE;
	}
		
	else return findE( currentE, depth, currentDepth+1 );
}

int main(){
	fT eNumber = 0.000;
	int depth = 15;
	eNumber = findE(eNumber, depth, 0);
	cout << setprecision(depth+2) <<  eNumber << endl;
	return 0;
}
// 2.71828182845904523536