//
// Created by Matteo on 02/12/2019.
//
#include <iostream>
#include <random>
#include "utils.h"


// Function that creates the dataset composed of N points
void createPoints(Points *dataset) {
    int bounds = 100.0;

    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_real_distribution<> dis(0.0, 10.0);



    for (int i = 0; i < NUM_POINTS; i++) {
        dataset->x[i] = dis(gen);
        dataset->y[i] = dis(gen);
    }


}