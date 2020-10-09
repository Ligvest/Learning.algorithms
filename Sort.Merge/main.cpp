#include <iostream>
#include <algorithm>

const int16_t MAX_BUFFER_SIZE = 9;

void mergeArrays(int16_t array[], uint16_t leftSize, uint16_t rightSize){
	int16_t* left = array;
	int16_t* right = array + leftSize;
	uint16_t arraySize = leftSize + rightSize;

	int16_t* buffer = new int16_t[arraySize];
	uint16_t bufferIndex{};
	uint16_t leftIndex{};
	uint16_t rightIndex{};

    // Merge left and right arrays
    while(leftIndex < leftSize && rightIndex < rightSize){
		if(left[leftIndex] <= right[rightIndex]){
			buffer[bufferIndex++] = left[leftIndex++];
		} else {
			buffer[bufferIndex++] = right[rightIndex++];
		}
	}


    // If left array is appeared shorter than right then move last elements from left array
	while(leftIndex < leftSize ){
		buffer[bufferIndex++] = left[leftIndex++];
	}

    // If right array is appeared shorter than left then move last elements from right array
    while(rightIndex < rightSize ){
		buffer[bufferIndex++] = right[rightIndex++];
	}

	for(uint16_t i = 0; i < arraySize; ++i){
		array[i] = buffer[i];
	}

	delete[] buffer;
}

void mergeSort(int16_t array[], uint16_t arraySize){
	if(arraySize < 2) { return; }

	uint16_t leftSize = arraySize / 2;
	uint16_t rightSize = arraySize - leftSize;
	int16_t* left = array;
	int16_t* right = array + leftSize;

	// divide array
	mergeSort(left, leftSize);
	mergeSort(right, rightSize);

	// merge divided array into one solid
	mergeArrays(array,leftSize, rightSize);
}

void fillArray(int16_t array[], uint16_t size){
	for(uint16_t i = 0; i < size; ++i){
		array[i] =	std::rand()%10;
	}
}


void printArray(int16_t array[], uint16_t size){
	for(uint16_t i = 0; i < size; ++i){
		std::cout<< array[i] << ' ';
	}
	std::cout << std::endl;
}



int main() {
	int16_t buffer[MAX_BUFFER_SIZE];
	fillArray(buffer, MAX_BUFFER_SIZE);
	printArray(buffer, MAX_BUFFER_SIZE);
	mergeSort(buffer, MAX_BUFFER_SIZE);
	printArray(buffer, MAX_BUFFER_SIZE);

	return 0;
}


