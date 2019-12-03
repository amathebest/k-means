#include <random>
#include "utils.h"
using namespace std;

int main() {
    printf("K-means initialization\n");

    // Dataset creation and filling, centroid randomization
    Points dataset, centroids;
    int niter = 10;
    createPoints(&dataset);
    chooseCentroids(&dataset, &centroids);

    // Compute K-Means on the given 2D points in the dataset
    computeKMeans(&dataset, &centroids, niter);

    // Outputs the final position of the centroids
    for (int i = 0; i < NUM_CENTR; ++i) {
        printf("Final position of the centroid number %i: x = %f, y = %f\n", i+1, centroids.x[i], centroids.y[i]);
    }

    return 0;
}
