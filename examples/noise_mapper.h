//
// Created by Camiel Verdult on 12/6/2021.
//

#ifndef APC_RANDOMNESS_NOISE_MAPPER_H
#define APC_RANDOMNESS_NOISE_MAPPER_H

#include <string>
#include <functional>   // std::function, std::negate

class noise_mapper {
public:
    noise_mapper(unsigned int resolution, const std::string& filename, std::function<unsigned long()> random);

private:
    unsigned int hash(unsigned int a);

    unsigned int ivalue(int x, int y);

    float smooth(float x);

    float value(float x, float y);

    unsigned int m_resolution;
};

#endif //APC_RANDOMNESS_NOISE_MAPPER_H
