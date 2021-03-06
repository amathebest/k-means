#include <random>
#include <iostream>
#include <chrono>
#include <cstdio>
#include <omp.h>
#include "utils.h"

using namespace std;
using namespace chrono;

int main() {
    printf("K-means initialization\n");
    srand(time(NULL));
    // Dataset creation and filling, centroid randomization
    Centroids centroids;

    vector<float> x(NUM_POINTS, 0.0);
    vector<float> y(NUM_POINTS, 0.0);
    vector<int> clusters(NUM_POINTS, 0);

    srand(time(NULL));
    for (int i = 0; i < NUM_POINTS; i++) {
        x[i] = ((float)rand() / RAND_MAX)*upper_bound;
        y[i] = ((float)rand() / RAND_MAX)*upper_bound;
    }

    Dataset* dataset = new Dataset(x, y, clusters);

    chooseCentroids(*dataset, &centroids);

    for (int i = 0; i < NUM_CENTR; i++) {
        printf("Starting position of the centroid number %i: x = %f, y = %f\n", i+1, centroids.x[i], centroids.y[i]);
    }

    steady_clock::time_point time_1 = steady_clock::now();
    // Compute K-Means on the given 2D points in the dataset.
    // Returns the number of points per cluster.
    // The parallel bool variable defines which function is called.
    if (parallel == true) {
        computeKMeans_parallel(*dataset, &centroids);
    } else {
        computeKMeans(*dataset, &centroids);
    }
    steady_clock::time_point time_2 = steady_clock::now();

    printf("---------------------------------------------------------------------\n");

    // Outputs the final position of the centroids
    for (int i = 0; i < NUM_CENTR; i++) {
        printf("Final position of the centroid number %i: x = %f, y = %f\n", i+1, centroids.x[i], centroids.y[i]);
    }

    if (parallel == true) {
        printf("Using %d processors for computation. Total time: %d[ms]\n", omp_get_num_procs(), duration_cast<milliseconds>(time_2 - time_1).count());
    } else {
        printf("Running on single thread. Total time: %d[ms]\n", duration_cast<milliseconds>(time_2 - time_1).count());
    }

    return 0;
}
