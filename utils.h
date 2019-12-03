//
// Created by Matteo on 02/12/2019.
//
#ifndef K_MEANS_UTILS_H
#define K_MEANS_UTILS_H

#endif //K_MEANS_UTILS_H

// Number of points and centroids
const int NUM_POINTS = 100000;
const int NUM_CENTR = 20;

const int NUM_POINTS_t = 12;
const int NUM_CENTR_t = 2;


// Struct that defines the shape of the dataset.
// It will be defined as a SOA (= Structure Of Array), with 2 arrays: one for x value and one for the y value.
struct Points {
    float x[NUM_POINTS];
    float y[NUM_POINTS];
};

void createPoints(Points *dataset);

void chooseCentroids(Points *dataset, Points *centroids);

double euclideanDistance(Points **dataset, Points **centroids, int idxPoint, int idxCentr);

void computeKMeans(Points *testdata, Points *testcentr, int niter);


// Test functions
void createTestPoints(Points *testdata);

void chooseTestCentroids(Points *testcentr);