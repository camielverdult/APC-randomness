# APC-randomness

## True randomness and how to get it

Random number generation is a tough if not impossible thing to do. That’s why we have the best next thing, pseudorandom number generators. You’ll learn why the C library rand() is not random at all and what alternatives there are. You’ll investigate the properties of different pseudorandom numbers generating algorithms, find out what cryptographically-strong PRNGs are and be able to show really cool looking graphs for others to admire! And of course you’ll add a couple of new terms to your vocabulary like Mersenne Twister or permuted congruential generator that are guaranteed to impress just about everybody during a family dinner.

## Different random number generating methods

Random number engines generate pseudo-random numbers using seed data as entropy source. Several different classes of pseudo-random number generation algorithms are implemented as templates that can be customized. 

The choice of which engine to use involves a number of tradeoffs: the linear congruential engine is moderately fast and has a very small storage requirement for state. The lagged Fibonacci generators are very fast even on processors without advanced arithmetic instruction sets, at the expense of greater state storage and sometimes less desirable spectral characteristics. The Mersenne twister is slower and has greater state storage requirements but with the right parameters has the longest non-repeating sequence with the most desirable spectral characteristics (for a given definition of desirable).

## C++11 random engines

| engine                                                                             | name in <random>           |
|------------------------------------------------------------------------------------|----------------------------|
| [Linear Congruential](https://en.wikipedia.org/wiki/Linear_congruential_generator) | linear_congruential_engine |
| [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister)                 | mersenne_twister_engine    |
| [Subtract with carry](https://en.wikipedia.org/wiki/Subtract_with_carry)           | subtract_with_carry_engine |