#include <random>
#include "utils.h"
using namespace std;

int main() {
    printf("K-means initialization\n");

    Points dataset;

    createPoints(&dataset);

    printf("Size: %d", sizeof(dataset.x));




    return 0;
}
