//  Course Name: CS110B Spring 2020
//  Lab Name: a14.1
//  Student Name: Daisy L Whitfield
//  Student ID: W54363682

#include <iostream>
#include <cstring>
using namespace std;




void reverseWithinBounds(char list[], int left, int right);
void reverseCstring(const char * str);



/*
int main() {
    
    
    char sentence[] = "some one a day";
    reverseCstring(sentence);
    
    return 0;
}
*/





void reverseWithinBounds(char list[], int left, int right) {

    
    if (left == right) {
        cout << list << endl;
        
        
    } else if (right == left + 1) {
        swap(list[left], list[right]);
        cout << list << endl;
        
        
    } else {
        swap(list[left], list[right]);
        reverseWithinBounds(list, left + 1, right - 1);
        
        
    }
}






void reverseCstring(const char * str) {
    
    int strSize = static_cast<int>(strlen(str)) - 1;
    
    
    char list[strSize];
    strcpy(list, str);

    reverseWithinBounds(list, 0, strSize);
}

