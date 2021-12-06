//
// Created by Marnix on 3-12-2021.
//

#include <cmath>
#include <cstdio>

int seed = 10;

unsigned int hash(unsigned int a) {
    a = (a ^ 61) ^ (a >> 16);
    a = a + (a << 3);
    a = a ^ (a >> 4);
    a = a * 0x27d4eb2d;
    a = a ^ (a >> 15);
    return a;
}

unsigned int ivalue(int x, int y) {
    srand(seed++);
    return rand()&0xff;

    //return hash(y<<16|x)&0xff;
}

float smooth(float x) {
    return 6*x*x*x*x*x - 15*x*x*x*x + 10*x*x*x;
}

float value(float x, float y) {
    int ix = floor(x);
    int iy = floor(y);
    float fx = smooth(x-ix);
    float fy = smooth(y-iy);

    int v00 = ivalue(iy+0, ix+0);
    int v01 = ivalue(iy+0, ix+1);
    int v10 = ivalue(iy+1, ix+0);
    int v11 = ivalue(iy+1, ix+1);
    float v0 = v00*(1-fx) + v01*fx;
    float v1 = v10*(1-fx) + v11*fx;
    return v0*(1-fy) + v1*fy;
}

unsigned char pic[1024*1024];

int main() {

    srand(1);

    for (int y=0; y<1024; y++) {
        for (int x=0; x<1024; x++) {
            float v = 0;

            for (int o=0; o<=9; o++) {
                v += value(x/64.0f*(1<<o), y/64.0f*(1<<o))/(1<<o);
                //v += rand()/(RAND_MAX/1024);
            }

            int r = rint(v*0.5f);

            pic[y*1024+x] = r;
        }
    }

    FILE *f = fopen("rand.pnm", "wb");
    fprintf(f, "P5\n1024 1024\n255\n");
    fwrite(pic, 1, 1024*1024, f);
    fclose(f);
}
