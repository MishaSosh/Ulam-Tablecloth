#include <iostream>
#include "math/prime_nums.h"

bool isPrime(int num) {
    // int div = 0;
    // int ans;

    // if (num < 0) {
    //     ans = 1;
    // } else {
    //     for (int i = 1; i <= num; i++) {
    //         if (num % i == 0) {
    //             div++;
    //         }
    //     }
    //     if (div > 2) {
    //         ans = 1;
    //     } else {
    //         ans = 0;
    //     }
    // }
    // return ans;

    if (num < 2) {return false;}
    if (num % 2 == 0) {return false;}
    if (num == 2) {return true;}
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {return false;}
    }
    return true;
}