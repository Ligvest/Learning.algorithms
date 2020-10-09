#include <iostream>
/*
 * grasshoper
 * cell prices are accending by 1
 * grasshoper can jump on the next cell or vie one cell
 * each cell adds its price to end cost
 * find a way to get cellNum by the cheapest way.
 *
 * Solution formula:
 * the cheapest destination cell number cost = previous the cheapest cell number cost + destination cell price
 * cheapestCosts[dstCellNum] = min(cheapestCosts[dstCellNum - 1], cheapestCosts[dstCellNum - 2]) + prices[dstCellNum];
 */

uint32_t cheaperCellCostRecursive(uint16_t cellNum){
	if(cellNum == 2){
		return cellNum + 1;
	} else if (cellNum < 2) {
		return cellNum;
	} else {
		return (cellNum + std::min(cheaperCellCostRecursive(cellNum - 1), cheaperCellCostRecursive(cellNum - 2)));
	}
}


uint32_t cheaperCellCostDynamic(uint16_t cellNum){
	uint16_t cellMinCosts[cellNum + 1];
	cellMinCosts[1] = 1;
	cellMinCosts[2] = cellMinCosts[1] + 2;
	for(uint16_t cellPrice = 3; cellPrice <= cellNum; ++cellPrice){
		cellMinCosts[cellPrice] = std::min(cellMinCosts[cellPrice-1], cellMinCosts[cellPrice-2]) + cellPrice;
	}

	return cellMinCosts[cellNum];
}

int main() {
	uint16_t num = 1;
	while (num > 0){
		std::cin >> num;
		std::cout << cheaperCellCostDynamic(num) << std::endl;
	}
	return 0;
}
