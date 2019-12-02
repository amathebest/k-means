#include <random>
#include "utils.h"
using namespace std;

int main() {
    printf("K-means initialization\n");

    // dataset creation and filling
    Points dataset, centroids;
    createPoints(&dataset);

    chooseCentroids(&dataset, &centroids);

    
    return 0;
}
