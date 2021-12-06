//
// Created by Marnix on 3-12-2021.
//

#include <cmath>
#include <cstdio>
#include <random>
#include <iostream>

std::linear_congruential_engine<unsigned long, 1103515245, 12345, 2147483647> lcg;

std::subtract_with_carry_engine<unsigned long, 32, 128, 159> swc;

float smooth(float x) {
    return 6*x*x*x*x*x - 15*x*x*x*x + 10*x*x*x;
}

///-------------------------------------------------------------------------------------

unsigned int lcg_hash(unsigned int a) {
    lcg.seed(a);
    return lcg();
}

unsigned int lcg_ivalue(int x, int y) {
    return lcg_hash(y<<16|x)&0xff;
}

float lcg_value(float x, float y) {
    int ix = floor(x);
    int iy = floor(y);
    float fx = smooth(x-ix);
    float fy = smooth(y-iy);

    int v00 = lcg_ivalue(iy+0, ix+0);
    int v01 = lcg_ivalue(iy+0, ix+1);
    int v10 = lcg_ivalue(iy+1, ix+0);
    int v11 = lcg_ivalue(iy+1, ix+1);
    float v0 = v00*(1-fx) + v01*fx;
    float v1 = v10*(1-fx) + v11*fx;
    return v0*(1-fy) + v1*fy;
}

///-------------------------------------------------------------------------------------

unsigned int swc_hash(unsigned int a) {
    swc.seed(a);
    return swc();
}

unsigned int swc_ivalue(int x, int y) {
    return swc_hash(y<<16|x)&0xff;
}

float swc_value(float x, float y) {
    int ix = floor(x);
    int iy = floor(y);
    float fx = smooth(x-ix);
    float fy = smooth(y-iy);

    int v00 = swc_ivalue(iy+0, ix+0);
    int v01 = swc_ivalue(iy+0, ix+1);
    int v10 = swc_ivalue(iy+1, ix+0);
    int v11 = swc_ivalue(iy+1, ix+1);
    float v0 = v00*(1-fx) + v01*fx;
    float v1 = v10*(1-fx) + v11*fx;
    return v0*(1-fy) + v1*fy;
}

///-------------------------------------------------------------------------------------

unsigned int std_rand_hash(unsigned int a) {
    srand(a);
    return rand();
}

unsigned int std_rand_ivalue(int x, int y) {
    return std_rand_hash(y<<16|x)&0xff;
}

float std_rand_value(float x, float y) {
    int ix = floor(x);
    int iy = floor(y);
    float fx = smooth(x-ix);
    float fy = smooth(y-iy);

    int v00 = std_rand_ivalue(iy+0, ix+0);
    int v01 = std_rand_ivalue(iy+0, ix+1);
    int v10 = std_rand_ivalue(iy+1, ix+0);
    int v11 = std_rand_ivalue(iy+1, ix+1);
    float v0 = v00*(1-fx) + v01*fx;
    float v1 = v10*(1-fx) + v11*fx;
    return v0*(1-fy) + v1*fy;
}

///-------------------------------------------------------------------------------------


unsigned char pic[1024*1024];

int main() {

    int choice{};
    std::string engine{};

    std::cout << "Please select the engine to use\n"
                 "\t1: Linear congruential engine\n"
                 "\t2: Subtract with carry engine\n"
                 "\t3: Std::rand() (C++11 rand)" << std::endl;

    std::cin >> choice;

    switch (choice){
        case 1:
            std::cout << "Using LCG engine" << std::endl;
            for (int y=0; y<1024; y++) {
                for (int x=0; x<1024; x++) {
                    float v = 0;

                    for (int o=0; o<=9; o++) {
                        v += lcg_value(x/64.0f*(1<<o), y/64.0f*(1<<o))/(1<<o);
                    }

                    int r = rint(v*0.5f);

                    pic[y*1024+x] = r;
                }
            }
            engine = "lcg";
            break;
        case 2:
            std::cout << "Using SWC engine" << std::endl;
            for (int y=0; y<1024; y++) {
                for (int x=0; x<1024; x++) {
                    float v = 0;

                    for (int o=0; o<=9; o++) {
                        v += swc_value(x/64.0f*(1<<o), y/64.0f*(1<<o))/(1<<o);
                    }

                    int r = rint(v*0.5f);

                    pic[y*1024+x] = r;
                }
            }
            engine = "swc";
            break;
        case 3:
            std::cout << "Using C++11 std::rand()" << std::endl;
            for (int y=0; y<1024; y++) {
                for (int x=0; x<1024; x++) {
                    float v = 0;

                    for (int o=0; o<=9; o++) {
                        v += std_rand_value(x/64.0f*(1<<o), y/64.0f*(1<<o))/(1<<o);
                    }

                    int r = rint(v*0.5f);

                    pic[y*1024+x] = r;
                }
            }
            engine = "std_rand";
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            return 0;
    }

    std::string filename = "gradient_noise_" + engine + ".pnm";

    FILE *f = fopen(filename.c_str(), "wb");
    fprintf(f, "P5\n1024 1024\n255\n");
    fwrite(pic, 1, 1024*1024, f);
    fclose(f);

    std::cout << "Image saved to: " << filename << std::endl;
}