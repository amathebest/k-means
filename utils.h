//
// Created by Matteo on 02/12/2019.
//
#ifndef K_MEANS_UTILS_H
#define K_MEANS_UTILS_H

using namespace std;

// Number of points and centroids
const int NUM_POINTS = 200000;
const int NUM_CENTR = 20;

// Struct that defines the shape of the dataset.
// It will be defined as a SOA with 3 arrays: one for x value, one for the y value and the last one for the cluster that the point belongs to.
class Dataset {
private:
    vector<float> x;
    vector<float> y;
    vector<int> cluster;
    int length;

public:
    Dataset(vector<float> x, vector<float> y, vector<int> cluster) {
        this->x = x;
        this->y = y;
        this-> cluster;
        this->length = x.size();
    }

    // Getters
    const vector<float> &getXorY(bool type) {
        if (type == true) {
            return this->x;
        } else {
            return this->y;
        }
    }

    const vector<int> &getClusters() {
        return this->cluster;
    }

    // Setters
    void setCluster(int i, int cluster) {
        this->x[i] = cluster;
    }

};

struct Points {
    vector<float> x;
    vector<float> y;
    vector<int> cluster;
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

void addPointToCluster(Points *dataset, Centroids *centroids, int idxPoint);

#endif //K_MEANS_UTILS_H