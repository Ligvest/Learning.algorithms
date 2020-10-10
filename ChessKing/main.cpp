#include <iostream>

/*
 * chess king
 * calculate number of ways to get to certain cell from the cell [1][1]
 * allowed moves: down and right
 *
 * Solution formula:
 * number of ways is the sum of ways previous left and the previous upper cells
 * waysCountByPos[row][column] = waysCountByPos[row-1][column] + waysCountByPos[row][column - 1];
 */


uint32_t waysCountRecursive(uint16_t cellRow, uint16_t cellColumn){
	if((cellRow == 1) || (cellColumn == 1)) {
		return 1;
	} else {
		return (waysCountRecursive(cellRow - 1, cellColumn) + waysCountRecursive(cellRow, cellColumn - 1));
	}
}

uint32_t waysCountDynamic(uint16_t cellRow, uint16_t cellColumn){
	uint16_t waysCountByPos[cellRow + 1][cellColumn + 1];

	//initialize first row and first column with 1
	for(uint16_t row = 0; row <= cellRow; ++row){
		waysCountByPos[row][1] = 1;
	}
	for(uint16_t column = 0; column <= cellColumn; ++column){
		waysCountByPos[1][column] = 1;
	}


	//apply solution formula
	for(uint16_t row = 2; row <= cellRow; ++row){
		for(uint16_t column = 2; column <= cellColumn; ++column){
			waysCountByPos[row][column] = waysCountByPos[row-1][column] + waysCountByPos[row][column - 1];
		}
	}

	return waysCountByPos[cellRow][cellColumn];
}

int main() {
	while (true){
		uint16_t row, column;
		std::cout<<"Row:";
		std::cin >> row;
		std::cout<<"Column:";
		std::cin >> column;
		std::cout << "Number of ways to reach the cell ["<< row <<"]["<<column<<"] is "<<waysCountDynamic(row, column) << std::endl;
	}
	return 0;
}
