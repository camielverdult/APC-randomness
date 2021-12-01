# APC-randomness

![](https://assets.amuniversal.com/321a39e06d6401301d80001dd8b71c47)

## True randomness and how to get it

Random number generation is a tough if not impossible thing to do. That’s why we have the best next thing, pseudorandom number generators. You’ll learn why the C library rand() is not random at all and what alternatives there are. You’ll investigate the properties of different pseudorandom numbers generating algorithms, find out what cryptographically-strong PRNGs are and be able to show really cool looking graphs for others to admire! And of course you’ll add a couple of new terms to your vocabulary like Mersenne Twister or permuted congruential generator that are guaranteed to impress just about everybody during a family dinner.

## Project use explanation

This project has an executable for each example, this way you can try different examples and compare their behaviour. For example, to run the std_rand example executable: go to the configuration drop-down in CLion and select `std_rand_example`.

![Configuration selection example](imgs/configurations_preview.png)

## Different random number generating methods

Random number engines generate pseudo-random numbers using seed data as [entropy](https://en.wikipedia.org/wiki/Entropy) source. Several classes of pseudo-random number generation algorithms are implemented as templates that can be customized. 

The choice of which engine to use involves a number of tradeoffs: the linear congruential engine is moderately fast and has a very small storage requirement for state. The lagged Fibonacci generators are very fast even on processors without advanced arithmetic instruction sets, at the expense of greater state storage and sometimes less desirable spectral characteristics. The Mersenne twister is slower and has greater state storage requirements but with the right parameters has the longest non-repeating sequence with the most desirable spectral characteristics (for a given definition of desirable).

## RNG engine summary

| engine                                                                                      | name in `<random>`         | Speed     | Storage     | Characteristics                    | Randomness comment                                                                                                |
|---------------------------------------------------------------------------------------------|----------------------------|-----------|-------------|------------------------------------|-------------------------------------------------------------------------------------------------------------------|
| [Linear Congruential](https://en.wikipedia.org/wiki/Linear_congruential_generator)          | linear_congruential_engine | 🔥        | very little | Fast and easy, highly configurable | Period length is parameter dependant, smaller initialization polynomials can reduce the period length drastically |
| [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister)                          | mersenne_twister_engine    | Moderate  | A lot       | "Damn"                             | Period length is chosen to be a Mersenne prime                                                                    |
| [Subtract with carry / Lagged Fibonacci](https://en.wikipedia.org/wiki/Subtract_with_carry) | subtract_with_carry_engine | Very fast | Greater     | "Meh"                              | Maximum period of (2k − 1)×2M-1 or y = xk + xj + 1                                                                |

## In-depth overview of RNGs

### Linear Congruential

The linear congruential random number generation uses a piecewise linear function (AKA several linear formulas, the one being used is dependent on parameters provided to the function). For the LCG, this formula is the following:
```
X(n+1) = (aXn + c) % m
```
where: 
- m: modulus
- a: multiplier
- c: increment
- X0: start value

Here's what that formula could look like as a Python function:
```py
def lcg(modulus: int, a: int, c: int, seed: int) -> Generator[int, None, None]:
    """Linear congruential generator."""
    # Returns a generator with pseudo-random numbers
    while True:
        seed = (a * seed + c) % modulus
        yield seed
```

Here is an example of the output of this function with different parameters:

![](https://upload.wikimedia.org/wikipedia/commons/0/02/Linear_congruential_generator_visualisation.svg)

### Mersenne Twister

