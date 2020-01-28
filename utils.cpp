//
// Created by Matteo on 02/12/2019.
//
#include <time.h>
#include <cmath>
#include <limits>
#include <algorithm>
#include <vector>
#include <iostream>
#include <omp.h>
#include "utils.h"

using namespace std;

// Function that chooses random points from the dataset to be the cluster's initial centroids
void chooseCentroids(Dataset &dataset, Centroids *centroids) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CENTR; i++) {
        int centr_idx = rand() % NUM_POINTS;
        centroids->x[i] = dataset.getXValue(centr_idx);
        centroids->y[i] = dataset.getYValue(centr_idx);
        centroids->x_accumulator[i] = 0;
        centroids->y_accumulator[i] = 0;
        centroids->npoints[i] = 0;
    }
};

// Function that computes and returns the Euclidean Distance between two chosen points
float euclideanDistance(Dataset &dataset, Centroids *centroids, int idxPoint, int idxCentr) {
    return sqrt(pow(dataset.getXValue(idxPoint) - centroids->x[idxCentr], 2) + pow(dataset.getYValue(idxPoint) - centroids->y[idxCentr], 2));
}

// Function that resets the coordinate accumulators of a centroid
void reset_centroid_acc(Centroids *centroids, int idxCentr) {
    centroids->x_accumulator[idxCentr] = 0;
    centroids->y_accumulator[idxCentr] = 0;
    centroids->npoints[idxCentr] = 0;
}

// Function that adds a point to a cluster using OpenMP atomic directive to make each operation atomic
void addPointToCluster(Dataset &dataset, Centroids *centroids, int idxPoint) {
    centroids->x_accumulator[dataset.getCluster(idxPoint)] += dataset.getXValue(idxPoint);
    centroids->y_accumulator[dataset.getCluster(idxPoint)] += dataset.getYValue(idxPoint);
    centroids->npoints[dataset.getCluster(idxPoint)] += 1;
}

// Actual K-Means function. Computes K-Means on a given 2D dataset with previously chosen centroids.
// It progressively modifies the coordinates of the centroids and stops when the problem converges.
void computeKMeans(Dataset &dataset, Centroids *centroids) {
    // Looping on iterations
    for (int i = 0; i < niter; i++) {
        // Looping on points
        for (int j = 0; j < NUM_POINTS; j++) {
            int closest_centr = 0;
            float smallest_dist = numeric_limits<float>::max();
            // Looping on centroids to find the closest
            for (int k = 0; k < NUM_CENTR; k++) {
                float current_dist = euclideanDistance(dataset, centroids, j, k);
                // Assigning the j-th point to the closest cluster
                if (current_dist < smallest_dist) {
                    smallest_dist = current_dist;
                    closest_centr = k;
                }
            }
            dataset.setCluster(j, closest_centr);
            addPointToCluster(dataset, centroids, j);
        }

        // Computing the new centroid coordinates
        for (int k = 0; k < NUM_CENTR; k++) {
            if (centroids->x_accumulator[k] != 0) {
                centroids->x[k] = centroids->x_accumulator[k] / std::max(centroids->npoints[k], 1);
                centroids->y[k] = centroids->y_accumulator[k] / std::max(centroids->npoints[k], 1);
            }
            reset_centroid_acc(centroids, k);
        }
    }
};

// Parallel version of the K-Means function. Computes K-Means on a given 2D dataset with previously chosen centroids.
// It progressively modifies the coordinates of the centroids and stops when the problem converges.
void computeKMeans_parallel(Dataset &dataset, Centroids *centroids) {
    // Looping on iterations
    for (int i = 0; i < niter; i++) {
        int closest_centr;
        float smallest_dist;
        Centroids local_centroids;
        // Looping on centroids to find the closest (parallel version)
#pragma omp parallel default(shared) private(smallest_dist, closest_centr, local_centroids)
        {
            local_centroids = *centroids;
#pragma omp for schedule(static)
            for (int j = 0; j < NUM_POINTS; ++j) {
                closest_centr = 0;
                smallest_dist = numeric_limits<float>::max();
                for (int k = 0; k < NUM_CENTR; ++k) {
                    float current_dist = euclideanDistance(dataset, centroids, j, k);
                    // Assigning the j-th point to the closest cluster
                    if (current_dist < smallest_dist) {
                        smallest_dist = current_dist;
                        closest_centr = k;
                    }
                }
                dataset.setCluster(j, closest_centr);
                local_centroids.x_accumulator[closest_centr] += dataset.getXValue(j);
                local_centroids.y_accumulator[closest_centr] += dataset.getYValue(j);
                ++local_centroids.npoints[closest_centr];
            }
#pragma omp critical
            for (int k = 0; k < NUM_CENTR; ++k) {
                centroids->x_accumulator[k] += local_centroids.x_accumulator[k];
                centroids->y_accumulator[k] += local_centroids.y_accumulator[k];
                centroids->npoints[k] += local_centroids.npoints[k];
            }
        }

        // Computing the new centroid coordinates
        for (int k = 0; k < NUM_CENTR; k++) {
            if (centroids->x_accumulator[k] != 0) {
                centroids->x[k] = centroids->x_accumulator[k] / std::max(centroids->npoints[k], 1);
                centroids->y[k] = centroids->y_accumulator[k] / std::max(centroids->npoints[k], 1);
            }
            reset_centroid_acc(centroids, k);
        }
    }
}
