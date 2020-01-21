#include <random>
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
    Points dataset;
    Centroids centroids;
    int niter = 10;
    bool parallel = false;

    createPoints(&dataset);
    chooseCentroids(&dataset, &centroids);

    for (int i = 0; i < NUM_CENTR; ++i) {
        printf("Starting position of the centroid number %i: x = %f, y = %f\n", i+1, centroids.x[i], centroids.y[i]);
    }

    steady_clock::time_point time_1 = steady_clock::now();
    // Compute K-Means on the given 2D points in the dataset.
    // Returns the number of points per cluster.
    // The parallel bool variable defines which function is called.
    if (parallel == false) {
        computeKMeans_parallel(&dataset, &centroids, niter);
    } else {
        computeKMeans(&dataset, &centroids, niter);
    }
    steady_clock::time_point time_2 = steady_clock::now();

    printf("---------------------------------------------------------------------\n");
    if (parallel == true) {
        printf("Using %d processors for computation. Total time: %d[ms]\n", omp_get_num_procs(), duration_cast<milliseconds>(time_2 - time_1).count());
    } else {
        printf("Running on single thread. Total time: %d[ms]\n", duration_cast<milliseconds>(time_2 - time_1).count());
    }
    // Outputs the final position of the centroids
    for (int i = 0; i < NUM_CENTR; ++i) {
        printf("Final position of the centroid number %i: x = %f, y = %f\n", i+1, centroids.x[i], centroids.y[i]);
    }

    return 0;
}
