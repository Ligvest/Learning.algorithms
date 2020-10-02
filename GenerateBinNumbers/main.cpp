#include <iostream>

const int16_t MAX_NUM_OF_DIGITS = 50;

void generateBinNumber(int16_t numberOfDigits){
	static int16_t top = 0;
	static int16_t digits[MAX_NUM_OF_DIGITS] = {};

	if(numberOfDigits == 0){
		for(int i = 0; i < top; ++i){
			std::cout<<digits[i]; // when current function have in parameter numberOfDigits = 0 then it
								  //means that our number is generated and we are ready to display it
		}
		std::cout<<"\n";
	} else {
		digits[top++] = 0; 						// set first digit to 0 and ask our
		generateBinNumber(numberOfDigits - 1);	// friend to make another part of digits
		--top;

		digits[top++] = 1;						 // set first digit to 1 and ask our
		generateBinNumber(numberOfDigits - 1);	 // friend to make another part of digits
		--top;
	}
}

int main() {
	generateBinNumber(3);
	return 0;
}


