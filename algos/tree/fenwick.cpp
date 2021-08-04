#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define FOR(i, n) for(int (i) = 0 ; (i) < (n); (i)++)



const int SIZE = 1000;
int A[SIZE];

#define LSBIT(i) ((i) & -(i))

// Returns the sum of the first i elements (indices 0 to i-1)
int prefix_sum(unsigned int i) {
	int sum = 0;
	for (; i > 0; i -= LSBIT(i)) {
		sum += A[i - 1];
	}
	return sum;
}

// Add delta to element with index i (zero-based)
void add(unsigned int i, int delta) {
	for (; i < SIZE; i += LSBIT(i+1)) A[i] += delta;
}

// Returns the sum of elements from i to j-1
int range_sum(unsigned int i, unsigned int j) {
	int sum = 0;
	for (; j > i; j -= LSBIT(j)) sum += A[j-1];
	for (; i > j; i -= LSBIT(i)) sum -= A[i-1];
	return sum;
}

// Convert A[] in place to Fenwick tree form
void init() {
	for (int i = 0; i < SIZE; i++) {
		unsigned int j = i + LSBIT(i+1);
		if (j < SIZE) A[j] += A[i];
    }
}

// Return a single element's value
int get(unsigned int i) {
	return range_sum(i, i+1);
}

// Set (as opposed to adjust) a single element's value
void set(unsigned int i, int value) {
	add(i, value - get(i));
}


// Find the largest i with prefix_sum(i) <= value, requires that all values are non-negative!
unsigned int rank_query(int value) {
	unsigned i = 0, j = SIZE;

	while (j != LSBIT(j)) j -= LSBIT(j);

	for (; j > 0;  j >>= 1) {
		if (i + j <= SIZE && A[i + j - 1] <= value) {
			value -= A[i + j - 1];
			i += j;
		}
	}
	return i;
}

int main() {
    FOR(i, SIZE) {
        A[i] = i;
    }

    init();

	cout << prefix_sum(SIZE);
}