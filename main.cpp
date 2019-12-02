#include <iostream>
#include <random>

#include "utils.h"

int main() {
    printf("K-means initialization\n");

    //Points my_points;
    int bounds = 100.0;

    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_real_distribution<> dis(0.0, 10.0);

    for (int i = 0; i < 10; i++) {
        float x = dis(gen);
        float y = dis(gen);
        printf("x: %f, y: %f\n", x, y);
    }


    /*
    for (int i = 0; i < NUM_POINTS; i++) {
        my_points.x[i] =
        my_points.y[i]
    }
    */




    return 0;
}
