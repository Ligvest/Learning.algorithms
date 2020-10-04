#include <iostream>
#include <algorithm>

const int16_t MAX_BUFFER_SIZE = 50;

void generatePermutations(uint16_t currentPosition, uint16_t numberOfObjects, int16_t buffer[]){
	if(currentPosition == numberOfObjects){
		for(uint16_t i = 0; i < numberOfObjects; ++i){
			std::cout << buffer[i]<< ' ';
		}
		std::cout << "\n";
	} else {
		for(uint16_t currentObject = 0; currentObject < numberOfObjects; ++currentObject){
			if(std::find(buffer, buffer + currentPosition, currentObject) != (buffer + currentPosition)){continue;}
			buffer[currentPosition] = currentObject;
			generatePermutations(currentPosition + 1, numberOfObjects, buffer);
		}
	}
}


int main() {
	int16_t buffer[MAX_BUFFER_SIZE];
	generatePermutations(0, 4, buffer);
	return 0;
}


