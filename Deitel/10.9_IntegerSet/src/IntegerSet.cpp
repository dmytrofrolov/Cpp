#include "IntegerSet.h"
#include <iostream>
IntegerSet::IntegerSet()
{
    for(int i = 0; i<setSize; i++)
        a[i] = 0;
}

IntegerSet::IntegerSet(int arr[], int n)
{
    for(int i = 0; i<setSize; i++)
        a[i] = 0;
    for(int i = 0; i<n; i++)
        a[arr[i]] = 1;
}

void IntegerSet::printIt(){
    for(int i = 0; i<setSize; i++)
        if(a[i]==1) std::cout << i << " " ;
    std::cout << std::endl;
}

IntegerSet IntegerSet::unionOfSet(IntegerSet set1, IntegerSet set2){
    IntegerSet returnSet;
    for(int i = 0; i < setSize; i++)
        if(set1.getItem(i)==1 || set2.getItem(i)==1)
            returnSet.insertItem(i);
    return returnSet;
}

IntegerSet IntegerSet::intersectionOfSets(IntegerSet set1, IntegerSet set2){
    IntegerSet returnSet;
    for(int i = 0; i < setSize; i++)
        if(set1.getItem(i)==1 && set2.getItem(i)==1)
            returnSet.insertItem(i);
    return returnSet;
}

bool IntegerSet::isEqual(IntegerSet set1, IntegerSet set2){
    for(int i = 0; i < setSize; i++){
        if(set1.getItem(i) != set2.getItem(i))
            return false;
    }
    return true;
}

