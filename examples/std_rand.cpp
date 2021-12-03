#include <iostream>
#include <random>
#include <ctime>
#include <string>

int main() {

    // https://en.cppreference.com/w/cpp/numeric/random/rand
    // Returns a pseudo-random integral value between 0 and RAND_MAX

    //std::srand(std::time(nullptr)); // use current time as seed for random generator
                                    // clang-tidy does not like this, clang-tidy errors:
    // Clang-Tidy: Random number generator seeded with a disallowed source of seed value will generate a predictable sequence of values
    // Clang-Tidy: Rand() has limited randomness; use C++11 random library instead

//    int random_variable = std::rand();
//    std::cout << "Random value on [0 " << RAND_MAX << "]: "
//              << random_variable << '\n';

    long long seed = 0;

    while(true){

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
        std::srand(seed);

        /* std_rand() is based on rand(), which has the following source code in the glibc: https://code.woboq.org/userspace/glibc/stdlib/random_r.c.html#__random_r
         * when taking a closer look at this code, you can see that this line: https://code.woboq.org/userspace/glibc/stdlib/random_r.c.html#364
         * closely resembles the format of calculating a random number with the Linear Congruential Engine:
         * int32_t val = ((state[0] * 1103515245U) + 12345U) & 0x7fffffff;
         * LCG(n+1) = a * Xn + c mod m
         *
         * The only difference being that the glibc implementation uses an & bitwise operation instead of a modulo operation
         * The reason for this is simple: https://en.wikipedia.org/wiki/Modulo_operation#Performance_issues
         *
         * Modulo operations might be implemented such that a division with a remainder is calculated each time.
         * For special cases, on some hardware, faster alternatives exist. For example, the modulo of powers of 2 can alternatively
         * be expressed as a bitwise AND operation (assuming x is a positive integer, or using a non-truncating definition):
         * x % 2n == x & (2n - 1)
         *
         * Examples:
         * x % 2 == x & 1
         * x % 4 == x & 3
         * x % 8 == x & 7
         */

        // roll 6-sided dice 10 times
        for (int n=0; n < 10; ++n) {
            unsigned int x = 7;
            while(x > 6) {
                x = 1 + std::rand() / ((RAND_MAX + 1u) / 6);  // Note: 1+rand()%6 is biased
                std::cout << x << ' ';
            }
        }

        std::cout << std::endl;
    }

    return 0;
}