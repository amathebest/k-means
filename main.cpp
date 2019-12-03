#include <random>
#include "utils.h"
using namespace std;

int main() {
    printf("K-means initialization\n");
    /*
    // dataset creation and filling, centroid randomization
    Points dataset, centroids;
    createPoints(&dataset);
    chooseCentroids(&dataset, &centroids);
    */
    Points testdata, testcentr;
    int niter = 10;

    createTestPoints(&testdata);
    chooseTestCentroids(&testcentr);

    computeKMeans(&testdata, &testcentr, niter);


    for (int i = 0; i < NUM_CENTR_t; ++i) {
        printf("Final position of the centroid number %i: x = %f, y = %f\n", i+1, testcentr.x[i], testcentr.y[i]);
    }

    return 0;
}
