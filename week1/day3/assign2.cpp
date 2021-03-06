#include <iostream>

using namespace std;

int main() {
    int a = 2;
    float b = 1.4;
    char c = 'a';
    void* arr[3]; // Using a void pointer to an array, it is possible to store elements of mixed types
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;

    cout << *(int *) arr[0] << "\n";
    cout << *(float *) arr[1] << "\n";
    cout << *(char *) arr[2] << "\n";

}

/*
In my particular example, it is not possible to automatically recognize the type of each element. You need to manually cast the type. This is 
because I use a void pointer to the array to make it typeless. This way, I can created a mixed array of ints, floats, and chars. The downside is that you
need to manually cast the type if you want to get the elements.

*/





