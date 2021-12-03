// This example code is from: https://en.cppreference.com/w/cpp/numeric/random

#include <iostream>
#include <random>

int main()
{

    long long seed = 0;

    while(true){

        // Here we use the following values to initialize our engine:
        // modulus m: 2^32 + 1
        const unsigned long m = 65536 + 1;

        // multiplier a: 75
        const unsigned long a = 75;

        // increment c: 74
        const unsigned long c = 74;

        std::linear_congruential_engine<unsigned long, a, c, m> lcg;


        std::cout << "Enter a number to use as seed \n\t- enter '0' to use auto-generate seed\n\t- enter '-1' to exit program: ";
        std::cin >> seed;
        std::cout << std::endl;

        if(seed == -1){
            std::cout << "Quitting program." << std::endl;
            return 0;
        }
        else if(seed == 0){
            lcg.seed((int)time(nullptr));
        }

        std::cout << "Using seed: " << seed << std::endl;

        lcg.seed(seed);

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

    return 0;
}