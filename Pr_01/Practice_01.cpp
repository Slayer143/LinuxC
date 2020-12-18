#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

void CalculateFunc(){
    double f;

    for (size_t col = 0; col < 100000; col++){
    int 
        prev, 
        next, 
        i = 1;
    
    double 
        factorial = 1, 
        step = 6, 
        sum,
        func1 = prev/((step)* factorial);

    step *= 6;

    double func2 = next / ((step) * factorial);

    int fib = prev + next;
        const double eps = 0.000001;
        f = func1 + func2;
        sum = f;
        i = 3;
        do{
            step*=6;
            i++;
            factorial*=i;
            f = fib/((step)*factorial);
            sum+=f;
            prev = fib;
            fib += next;
            next = prev;
        } while (f > eps);
    }
}
int main(){
    CalculateFunc();
}
