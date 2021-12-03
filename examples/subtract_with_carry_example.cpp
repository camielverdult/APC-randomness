// This example code is from: https://en.cppreference.com/w/cpp/numeric/random

#include <iostream>
#include <random>

int main()
{

    long long seed = 0;

    while(seed != -1){

//        std::cout << "Enter a number to use as seed (enter '-1' to exit program): ";
//        std::cin >> seed;
//        std::cout << std::endl;
//
//        if(seed == -1){
//            std::cout << "Quitting program.";
//            return 0;
//        }
//        std::cout << "Using seed: " << seed << std::endl;

        // short_lag S
        const unsigned long short_lag = 128;

        // long_lag L
        const unsigned long long_lag = 159;

        // w: word size
        const unsigned long word_size = 32;

        std::subtract_with_carry_engine<unsigned long, word_size, short_lag, long_lag> swc;


        std::cout << "Enter a number to use as seed \n\t- enter '0' to use auto-generate seed\n\t- enter '-1' to exit program: ";
        std::cin >> seed;
        std::cout << std::endl;

        if(seed == -1){
            std::cout << "Quitting program." << std::endl;
            return 0;
        }
        else if(seed == 0){
            std::cout << "Using seed: " << (int)time(nullptr) << std::endl;
            swc.seed((int)time(nullptr));
        }
        else{
            std::cout << "Using seed: " << seed << std::endl;
            std::srand(seed);
        }




        swc.seed(seed);

        // roll 6-sided dice 10 times
        for (int n = 0; n < 10; ++n) {
            unsigned int x = 7;
            while(x > 6) {

                // Word size is 32, so we divide our output by 2^32, then by 6 to get values from <0, 6>
                x = 1 + swc() / (4294967296 / 6);
                std::cout << x << ' ';
            }
        }

        std::cout << std::endl;
    }

    return 0;
}