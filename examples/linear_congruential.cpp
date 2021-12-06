// This example code is from: https://en.cppreference.com/w/cpp/numeric/random

#include <iostream>
#include <random>
#include "noise_mapper.h"

int main()
{

    long long seed = 0;

    while(true){

        // Here we use the following values to initialize our engine:
        // These values come from glibc (used by GCC)

        //modulus m: 2^31 - 1
        const unsigned long m = 2147483647;

        //multiplier a: 1103515245
        const unsigned long a = 1103515245;

        // increment c: 74
        const unsigned long c = 12345;


        std::linear_congruential_engine<unsigned long, a, c, m> lcg;


        std::cout << "Enter a number to use as seed \n\t- enter '0' to use auto-generate seed\n\t- enter '-1' to exit program: ";
        std::cin >> seed;
        std::cout << std::endl;

        if(seed == -1){
            std::cout << "Quitting program." << std::endl;
            return 0;
        }
        else if(seed == 0){
            seed = (int)time(nullptr);
        }

        std::cout << "Using seed: " << seed << std::endl;

        lcg.seed(seed);

        std::function<unsigned long()> random = lcg;

        noise_mapper mapper(1024, "../linear_congruential.pnm", random);

        // roll 6-sided dice 10 times
        for (int n = 0; n < 10; ++n) {
            unsigned int x = 7;
            while(x > 6) {
                x = 1 + lcg() / (m / 6);
                std::cout << x << ' ';
            }
        }

        std::cout << std::endl;
    }
}