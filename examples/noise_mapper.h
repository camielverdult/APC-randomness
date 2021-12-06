//
// Created by Camiel Verdult on 12/6/2021.
//

#ifndef APC_RANDOMNESS_NOISE_MAPPER_H
#define APC_RANDOMNESS_NOISE_MAPPER_H

#include <string>
#include <functional>   // std::function, std::negate

class noise_mapper {
public:
    noise_mapper(size_t resolution, const std::string& filename, std::function<unsigned long()> random);
};

#endif //APC_RANDOMNESS_NOISE_MAPPER_H
