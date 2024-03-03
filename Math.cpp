#include "Math.hpp"

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

Math::~Math() {

}