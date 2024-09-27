#include <stdio.h>
#include "palindrome.h"

int size(long n)
{
    int i = 0;
    for(i = 1;;i++)
    {
        n/=10;
        if(n==0)
            return i;
    }
    return 0;
}

long pow_10(int n){
    long value = 1;
    int i = 0;
    for(i =0;i<n;i++)
    {
        value*=10;
    }
    return value;
}
int is_palindrome(long n) {
    int Size = size(n);
    int i = 0;    
    
    if(n < 0)
        return 0;

    for(i =0;i<Size;i++)
    {
        char leftmost = n / pow_10(Size-i-1) % 10;
        char rightmost = n / pow_10(i) % 10;
        if(leftmost!=rightmost)
            return 0;
    }
    return 1;
}