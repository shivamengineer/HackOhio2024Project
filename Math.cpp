#include "Math.hpp"
#include <stdlib.h>

Math::Math(){

}

int* Math::bucket(int coords[2]) {
	int bucket[2];
	bucket[0] = coords[0];
	if (bucket[0] < 0) {
		bucket[0] *= -1;
	}
	bucket[1] = coords[1];
	if (bucket[1] < 0) {
		bucket[1] *= -1;
	}
	bucket[0] %= 10;
	bucket[1] %= 10;
	return bucket;
}

int* Math::miniBucket(int coords[2]) {
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = this->bucket(coords);
	int miniBucket[2];
	if (*bucket < 5) {
		miniBucket[0] = 0;
	} else {
		miniBucket[0] = 1;
	}
	if (*(bucket + 1) < 5) {
		miniBucket[1] = 0;
	} else {
		miniBucket[1] = 1;
	}
	return miniBucket;
}

Math::~Math() {

}