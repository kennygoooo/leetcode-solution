#include <stdio.h>

// function to add two numbers without using arithmetic operators
int sum(int a, int b) {

    while (b != 0){
        int carry = (a & b) << 1;
        
        a = a ^ b;

        b = carry;
    }

    return a;
}


int main() {
    int a = -1, b = 2;
  
    printf("%d\n", sum(a, b));
    return 0; 
}