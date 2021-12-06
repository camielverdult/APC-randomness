//
// Created by Camiel Verdult on 12/6/2021.
//

#ifndef APC_RANDOMNESS_NOISE_MAPPER_H
#define APC_RANDOMNESS_NOISE_MAPPER_H

#include <string>
#include <memory>

class noise_mapper {
public:
    noise_mapper(unsigned int resolution, std::string path, std::string filename);

private:
    unsigned int hash(unsigned int a);

    unsigned int ivalue(int x, int y);

    float smooth(float x);

    float value(float x, float y);

    unsigned int m_resolution;
    std::string m_path;
    std::string m_filename;
    char *pic;

};

#endif //APC_RANDOMNESS_NOISE_MAPPER_H
