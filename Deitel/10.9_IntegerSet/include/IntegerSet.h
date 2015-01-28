#ifndef INTEGERSET_H
#define INTEGERSET_H


class IntegerSet
{
    public:
        IntegerSet();
        IntegerSet(int arr[], int n);
        ~IntegerSet();
        void insertItem(int i){if(i<101 && i>=0)a[i]=1;};
        void deleteItem(int i){if(i<101 && i>=0)a[i]=0;};
        int getItem(int i) const {if(i<101 && i>=0)return a[i];};
        void printIt();
        static IntegerSet unionOfSet(IntegerSet set1, IntegerSet set2);
        static IntegerSet intersectionOfSets(IntegerSet set1, IntegerSet set2);
        static bool isEqualTo(IntegerSet set1, IntegerSet set2);
    private:
        int a[101];
};

#endif // INTEGERSET_H
