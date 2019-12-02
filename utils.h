//
// Created by Matteo on 02/12/2019.
//
#ifndef K_MEANS_UTILS_H
#define K_MEANS_UTILS_H

#endif //K_MEANS_UTILS_H

// Number of points and centroids
const int NUM_POINTS = 100000;
const int NUM_CENTR = 20;

// Struct that defines the shape of the dataset.
// It will be defined as a SOA (= Structure Of Array), with 2 arrays: one for x value and one for the y value.
struct Points {
    double x[NUM_POINTS];
    double y[NUM_POINTS];
};


void createPoints(Points *dataset);