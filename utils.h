//
// Created by Matteo on 02/12/2019.
//
#ifndef K_MEANS_UTILS_H
#define K_MEANS_UTILS_H

using namespace std;

// Initialization of constants
const int NUM_POINTS = 200000;
const int NUM_CENTR = 20;
const float upper_bound = 1000.0;
const int niter = 10;
const bool parallel = true;

// Class that defines the shape of the dataset.
// It will be defined as a SOA with 3 arrays: one for x value, one for the y value and the last one for the cluster that the point belongs to.
class Dataset {
private:
    vector<float> x;
    vector<float> y;
    vector<int> cluster;

public:
    Dataset(vector<float> x, vector<float> y, vector<int> cluster) {
        this->x = x;
        this->y = y;
        this->cluster = cluster;
    }

    // Getters
    float getXValue(int index) {
        return this->x[index];
    }

    float getYValue(int index) {
        return this->y[index];
    }

    int getCluster(int index) {
        return this->cluster[index];
    }

    // Setters
    void setCluster(int i, int cluster) {
        this->cluster[i] = cluster;
    }
};

struct Centroids {
    float x[NUM_CENTR];
    float y[NUM_CENTR];
    float x_accumulator[NUM_CENTR];
    float y_accumulator[NUM_CENTR];
    int npoints[NUM_CENTR];
};

// Functions declarations
void chooseCentroids(Dataset &dataset, Centroids *centroids);

float euclideanDistance(Dataset &dataset, Centroids *centroids, int idxPoint, int idxCentr);

void reset_centroid_acc(Centroids *centroids, int idxCentr);

void computeKMeans(Dataset &dataset, Centroids *centroids);

void computeKMeans_parallel(Dataset &dataset, Centroids *centroids);

void addPointToCluster_par(Dataset &dataset, Centroids *centroids, int idxPoint);

#endif //K_MEANS_UTILS_H