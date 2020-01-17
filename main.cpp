#include <random>
#include <chrono>
#include <stdio.h>
#include <omp.h>
#include "utils.h"
using namespace std;

int main() {
    printf("K-means initialization\n");
    srand(time(NULL));
    // Dataset creation and filling, centroid randomization
    Points dataset;
    Centroids centroids;
    int niter = 10;
    bool parallel = true;

    createPoints(&dataset);
    chooseCentroids(&dataset, &centroids);

    // Compute K-Means on the given 2D points in the dataset.
    // Returns the number of points per cluster.
    if (parallel == true) {
        computeKMeans_parallel(&dataset, &centroids, niter);
    } else {
        for (int i = 0; i < NUM_CENTR; ++i) {
            printf("Starting position of the centroid number %i: x = %f, y = %f\n", i+1, centroids.x[i], centroids.y[i]);
        }
        double time_1 = omp_get_wtime();
        computeKMeans(&dataset, &centroids, niter);
        double time_2 = omp_get_wtime();
        float time = time_2 - time_1;
        printf("--------------------------------------------------------------------- Computation took %f seconds\n", time);
        // Outputs the final position of the centroids
        for (int i = 0; i < NUM_CENTR; ++i) {
            printf("Final position of the centroid number %i: x = %f, y = %f\n", i+1, centroids.x[i], centroids.y[i]);
        }
    }

    return 0;
}
