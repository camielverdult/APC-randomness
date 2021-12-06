//
// Created by Camiel Verdult on 12/6/2021.
//

#include "noise_mapper.h"
#include <cmath>
#include <iostream>
#include <fstream>

noise_mapper::noise_mapper(unsigned int resolution, std::string path, std::string filename): m_resolution (resolution), m_path(path), m_filename (filename) {

//    pic = static_cast<char *>(malloc(resolution * resolution * sizeof(char)));

    std::ofstream noise_file;
    noise_file.open(path.append(filename));

    for (unsigned int y = 0; y < m_resolution; y++) {
        for (int x = 0; x < m_resolution; x++) {
            float v = 0;

            for (int o=0; o<=9; o++) {
                v += this->value(x / 64.0f * ( 1 << o),  y / 64.0f * (1 << o) ) / ( 1<<o );
            }

            int r = rint(v*0.5f);

            noise_file << r;
        }
    }

//    std::ofstream noise_file;
//    noise_file.open(path.append(filename));
//    noise_file << pic;
    noise_file.close();
}

unsigned int noise_mapper::hash(unsigned int a) {
    a = (a ^ 61) ^ (a >> 16);
    a = a + (a << 3);
    a = a ^ (a >> 4);
    a = a * 0x27d4eb2d;
    a = a ^ (a >> 15);
    return a;
}

unsigned int noise_mapper::ivalue(int x, int y) {
    return this->hash(y<<16|x)&0xff;
}

float noise_mapper::smooth(float x) {
    return 6*x*x*x*x*x - 15*x*x*x*x + 10*x*x*x;
}

float noise_mapper::value(float x, float y) {
    int ix = floor(x);
    int iy = floor(y);
    float fx = this->smooth(x-ix);
    float fy = this->smooth(y-iy);

    int v00 = this->ivalue(iy+0, ix+0);
    int v01 = this->ivalue(iy+0, ix+1);
    int v10 = this->ivalue(iy+1, ix+0);
    int v11 = this->ivalue(iy+1, ix+1);
    float v0 = v00*(1-fx) + v01*fx;
    float v1 = v10*(1-fx) + v11*fx;
    return v0*(1-fy) + v1*fy;
}

int main() {
    noise_mapper mapper(1024, "../", "noise.pnm");

    return 0;
}