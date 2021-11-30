#include <iostream>
#include <random>
#include <ctime>

int main(int argc, char* argv[]) {

    // https://en.cppreference.com/w/cpp/numeric/random/rand
    // Returns a pseudo-random integral value between 0 and RAND_MAX

    std::srand(std::time(nullptr)); // use current time as seed for random generator
                                    // clang-tidy does not like this, clang-tidy errors:
    // Clang-Tidy: Random number generator seeded with a disallowed source of seed value will generate a predictable sequence of values
    // Clang-Tidy: Rand() has limited randomness; use C++11 random library instead

    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: "
              << random_variable << '\n';

    // roll 6-sided dice 20 times
    for (int n=0; n != 20; ++n) {
        unsigned int x = 7;
        while(x > 6)
            x = 1 + std::rand()/((RAND_MAX + 1u)/6);  // Note: 1+rand()%6 is biased
            // (RAND_MAX + 1u)/6 = ((2^31 - 1) + 1)/6 = 2^31/6 =
        std::cout << x << ' ';
    }

    return 0;
}