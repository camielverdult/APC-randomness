//
// Created by Camiel Verdult on 12/6/2021.
//

#include "noise_mapper.h"
#include <cmath>
#include <cstdio>
#include <iostream>

noise_mapper::noise_mapper(size_t resolution, const std::string& filename, std::function<unsigned long()> random) {

    unsigned char pic[resolution*resolution];

    for (unsigned int y = 0; y < resolution; y++) {
        for (int x = 0; x < resolution; x++) {
            float v = 0;

            for (int o=0; o<=9; o++) {
                v += random();
            }

            int r = rint(v*0.5f);

            pic[y*resolution+x] = r;
        }
    }

    FILE *f = fopen(filename.c_str(), "wb");
    std::string header = "P5\n" + std::to_string(resolution) + " " + std::to_string(resolution) + "\n255\n";
    fprintf(f, header.c_str());
    fwrite(pic, 1, resolution*resolution, f);
    fclose(f);
}

unsigned long test() {
    return 1;
}
