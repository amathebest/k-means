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
// It will be defined as a SOA with 2 arrays: one for x value and one for the y value.
struct Points {
    float x[NUM_POINTS];
    float y[NUM_POINTS];
    int cluster[NUM_POINTS];
};

struct Centroids {
    float x[NUM_CENTR];
    float y[NUM_CENTR];
    float x_accumulator[NUM_CENTR];
    float y_accumulator[NUM_CENTR];
    int npoints[NUM_CENTR];
};

void createPoints(Points *dataset);

void chooseCentroids(Points *dataset, Centroids *centroids);

float euclideanDistance(Points *dataset, Centroids *centroids, int idxPoint, int idxCentr);

void reset_centroid_acc(Centroids *centroids, int idxCentr);

void computeKMeans(Points *dataset, Centroids *centroids, int niter);

void computeKMeans_parallel(Points *dataset, Centroids *centroids, int niter);
