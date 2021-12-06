//
// Created by Marnix on 3-12-2021.
//

#include <cmath>
#include <cstdio>
#include <random>
#include <iostream>

//To keep it simple, we will just use some globally defined engines.
std::linear_congruential_engine<unsigned long, 1103515245, 12345, 2147483647> lcg;
std::subtract_with_carry_engine<unsigned long, 32, 128, 159> swc;
std::mersenne_twister_engine<std::uint_fast64_t, 64, 312, 156, 31,
        0xb5026f5aa96619e9, 29,
        0x5555555555555555, 17,
        0x71d67fffeda60000, 37,
        0xfff7eee000000000, 43, 6364136223846793005> mtw;

float smooth(float x) {
    return 6*x*x*x*x*x - 15*x*x*x*x + 10*x*x*x;
}

///-------------------------------------------------------------------------------------

//The actual function that creates the random sequence
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

//The actual function that creates the random sequence
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

//The actual function that creates the random sequence
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

//The actual function that creates the random sequence
unsigned int mt_hash(unsigned int a) {
    mtw.seed(a);
    return mtw();
}

unsigned int mt_ivalue(int x, int y) {
    return mt_hash(y<<16|x)&0xff;
}

float mt_value(float x, float y) {
    int ix = floor(x);
    int iy = floor(y);
    float fx = smooth(x-ix);
    float fy = smooth(y-iy);

    int v00 = mt_ivalue(iy+0, ix+0);
    int v01 = mt_ivalue(iy+0, ix+1);
    int v10 = mt_ivalue(iy+1, ix+0);
    int v11 = mt_ivalue(iy+1, ix+1);
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
                 "\t3: Mersenne twister\n"
                 "\t4: Std::rand() (C++11 rand)\n\n"
                 "Choice: ";

    std::cin >> choice;
    std::cout << std::endl;

    //Switch-case to choose which engine to use
    switch (choice){
        case 1:
            std::cout << "Using the linear congruential engine" << std::endl;
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
            std::cout << "Using the subtract-with-carry engine" << std::endl;
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
            std::cout << "Using the Mersenne-twister engine" << std::endl;
            for (int y=0; y<1024; y++) {
                for (int x=0; x<1024; x++) {
                    float v = 0;

                    for (int o=0; o<=9; o++) {
                        v += mt_value(x/64.0f*(1<<o), y/64.0f*(1<<o))/(1<<o);
                    }

                    int r = rint(v*0.5f);

                    pic[y*1024+x] = r;
                }
            }
            engine = "mt";
            break;
        case 4:
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
            //For simplicity's sake the program quits when a different choice is made.
            std::cout << "Invalid choice" << std::endl;
            return 0;
    }

    std::string filename = "gradient_noise_" + engine + ".pnm";

    //Opening the output file and writing the data to it.
    FILE *f = fopen(filename.c_str(), "wb");
    fprintf(f, "P5\n1024 1024\n255\n");
    fwrite(pic, 1, 1024*1024, f);
    fclose(f);

    std::cout << "Image saved to: " << filename << std::endl;
}