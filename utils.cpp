//
// Created by Matteo on 02/12/2019.
//
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <limits>
#include <omp.h>
#include <algorithm>
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

// Function that chooses random points from the dataset to be the cluster's initial centroids
void chooseCentroids(Points *dataset, Centroids *centroids) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CENTR; ++i) {
        int centr_idx = rand() % NUM_POINTS;
        centroids->x[i] = dataset->x[centr_idx];
        centroids->y[i] = dataset->y[centr_idx];
    }
};

// Function that computes and returns the Euclidean Distance between two chosen points
float euclideanDistance(Points *dataset, Centroids *centroids, int idxPoint, int idxCentr) {
    return sqrt(pow(dataset->x[idxPoint] - centroids->x[idxCentr], 2) + pow(dataset->y[idxPoint] - centroids->y[idxCentr], 2));
}


// Actual K-Means function. Computes K-Means on a given 2D dataset with previously chosen centroids.
// It progressively modifies the coordinates of the centroids and stops when the problem converges.
void computeKMeans(Points *dataset, Centroids *centroids, int niter) {
    Centroids coords;
    int clustering[NUM_POINTS];
    int npoints[NUM_CENTR] = {0};

    // Looping on iterations
    for (int i = 0; i < niter; ++i) {
        // Looping on points
        for (int j = 0; j < NUM_POINTS; ++j) {
            int closest_centr = 0;
            float smallest_dist = std::numeric_limits<float>::max();
            // Looping on centroids to find the closest
            for (int k = 0; k < NUM_CENTR; ++k) {
                float current_dist = euclideanDistance(dataset, centroids, j, k);
                // Assigning the j-th point to the closest cluster
                if (current_dist < smallest_dist) {
                    smallest_dist = current_dist;
                    closest_centr = k;
                }
            }
            clustering[j] = closest_centr;
        }

        // Computing the sum of the coordinates for each cluster
        for (int j = 0; j < NUM_POINTS; ++j) {
            coords.x[clustering[j]] += dataset->x[j];
            coords.y[clustering[j]] += dataset->y[j];
            npoints[clustering[j]] += 1;
        }

        // Computing the new centroid coordinates
        for (int k = 0; k < NUM_CENTR; ++k) {
            if (coords.x[k] != 0) {
                centroids->x[k] = coords.x[k] / std::max(npoints[k], 1);
                centroids->y[k] = coords.y[k] / std::max(npoints[k], 1);
            }
        }
    }
};

// Actual K-Means function. Computes K-Means on a given 2D dataset with previously chosen centroids.
// It progressively modifies the coordinates of the centroids and stops when the problem converges.
void computeKMeans_parallel(Points *dataset, Centroids *centroids, int niter) {
    printf("Using %d processors for computation.\n", omp_get_num_procs());

}