//
// Created by Matteo on 02/12/2019.
//
#include <stdio.h>
#include <time.h>
#include <cmath>
#include "utils.h"

// Function that creates the dataset composed of N points
void createPoints(Points *dataset) {
    int upper_bound = 100.0;
    srand(time(NULL));

    for (int i = 0; i < NUM_POINTS; ++i) {
        dataset->x[i] = (float)rand() / (float)RAND_MAX * upper_bound;
        dataset->y[i] = (float)rand() / (float)RAND_MAX * upper_bound;
    }
}

// Function that computes and returns the Euclidean Distance between two chosen points
double euclideanDistance(Points *dataset, int idx1, int idx2) {
    return sqrt(pow(dataset->x[idx1] - dataset->x[idx2], 2) + pow(dataset->y[idx1] - dataset->y[idx2], 2));
}
