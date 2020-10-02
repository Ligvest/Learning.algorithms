#include <iostream>

void hanoi(uint16_t sourcePin, uint16_t destinationPin, uint32_t numberOfRings){
	if(numberOfRings == 1){
		std::cout<< "move from pin " << sourcePin << " to pin " << destinationPin << "\n";
	} else {
		uint16_t tempPin = 6 - (sourcePin + destinationPin);
		hanoi(sourcePin, tempPin, numberOfRings - 1); // ask friend to move all rings except one from 1 pin to 3
		std::cout<< "move from pin " << sourcePin << " to pin " << destinationPin << "\n"; // move last ring by myself from 1 pin to 2
		hanoi(tempPin, destinationPin , numberOfRings - 1); // ask friend to move all rings from 3 pin to 2
	}
}

int main() {
	hanoi(1,2,2);
	return 0;
}


