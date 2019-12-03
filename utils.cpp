//
// Created by Matteo on 02/12/2019.
//
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <limits>
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
void chooseCentroids(Points *dataset, Points *centroids) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CENTR; ++i) {
        int centr_idx = rand() % NUM_POINTS;
        centroids->x[i] = dataset->x[centr_idx];
        centroids->y[i] = dataset->y[centr_idx];
    }
};

// Function that computes and returns the Euclidean Distance between two chosen points
float euclideanDistance(Points *dataset, Points *centroids, int idxPoint, int idxCentr) {
    return sqrt(pow(dataset->x[idxPoint] - centroids->x[idxCentr], 2) + pow(dataset->y[idxPoint] - centroids->y[idxCentr], 2));
}


// Actual K-Means function. Computes K-Means on a given 2D dataset with previously chosen centroids.
// It progressively modifies the coordinates of the centroids and stops when the problem converges.

// Once tests are done replace the points and centroids pointers to the real ones.
void computeKMeans(Points *dataset, Points *centroids, int niter) {
    Points coords;
    //int clustering[NUM_POINTS];
    //int npoints[NUM_CENTR] = {0};

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
            //clustering[j] = closest_centr;
        }
        /*
        // Computing the sum of the coordinates for each cluster
        for (int j = 0; j < NUM_POINTS; ++j) {
            coords.x[clustering[j]] += dataset->x[j];
            coords.y[clustering[j]] += dataset->y[j];
            npoints[clustering[j]] += 1;
        }

        // Computing the new centroid coordinates
        for (int k = 0; k < NUM_CENTR; ++k) {
            if (npoints[k] == 0) {
                npoints[k] = 1;
            }
            centroids->x[k] = coords.x[k] / npoints[k];
            centroids->y[k] = coords.y[k] / npoints[k];
        }
        */
    }
};



// Test dataset initialization
// Function that creates the dataset composed of N points
void createTestPoints(Points *testdata) {
    testdata->x[0] = 4.0;
    testdata->y[0] = 4.0;
    testdata->x[1] = 3.0;
    testdata->y[1] = 5.0;
    testdata->x[2] = 5.0;
    testdata->y[2] = 5.0;
    testdata->x[3] = 6.0;
    testdata->y[3] = 4.0;
    testdata->x[4] = 7.0;
    testdata->y[4] = 3.0;
    testdata->x[5] = 6.0;
    testdata->y[5] = 2.0;
    testdata->x[6] = 6.0;
    testdata->y[6] = 3.0;
    testdata->x[7] = 8.0;
    testdata->y[7] = 4.0;
    testdata->x[8] = 3.0;
    testdata->y[8] = 3.0;
    testdata->x[9] = 2.0;
    testdata->y[9] = 6.0;
    testdata->x[10] = 3.0;
    testdata->y[10] = 2.0;
    testdata->x[11] = 2.0;
    testdata->y[11] = 2.0;
}

// Function that chooses random points from the dataset to be the cluster's initial centroids
void chooseTestCentroids(Points *testcentr) {
    testcentr->x[0] = 4.0;
    testcentr->y[0] = 2.0;
    testcentr->x[1] = 4.0;
    testcentr->y[1] = 3.0;
};
