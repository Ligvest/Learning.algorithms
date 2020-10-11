#include <iostream>
#include <vector>

/*
 * backpack packing problem
 * find the maximum value of all items which can be accomodated
 *
 * Solution formula:
 * costTable[curWeight][curBagItem] = std::max(costTable[curWeight][curBagItem - 1],
 * 												costTable[curWeight - curBagItemWeight][curBagItem - 1]  + curBagItemCost);
 */

struct bagItem{
	uint16_t weight{};
	uint16_t cost{};
};

std::vector<bagItem> createBagItemsArray() {
	uint16_t bagItemsNumber{};
	std::cout << "Enter number of bag items: ";
	std::cin >> bagItemsNumber;

	std::vector<bagItem> bagItems;
	bagItems.resize(bagItemsNumber);

	for(int i = 0; i < bagItemsNumber; ++i){
		uint16_t bagItemWeight{};
		std::cout<<"Enter the " << i << " bag item weight: ";
		std::cin >> bagItemWeight;

		uint16_t bagItemCost{};
		std::cout<<"Enter the " << i << " bag item cost: ";
		std::cin >> bagItemCost;

		bagItems[i].cost = bagItemCost;
		bagItems[i].weight = bagItemWeight;
	}

	return bagItems;
}

auto createCostTable(uint16_t backpackCapacity, std::vector<bagItem>& bagItems) {

	// will be initialized by default ( with zeros)
	std::vector<std::vector<uint16_t>> costTable;
	costTable.resize(backpackCapacity + 1);
	for(auto& row : costTable){
		row.resize(bagItems.size() + 1);
	}

	// calculate full cost table
	for(uint16_t curBagItem = 1; curBagItem <= bagItems.size(); ++curBagItem){
		uint16_t curBagItemWeight = bagItems[curBagItem - 1].weight;
		uint16_t curBagItemCost = bagItems[curBagItem - 1].cost;

		//if the current item is too big for the backpack then just keep previous values
		for(uint16_t curWeight = 1; curWeight < curBagItemWeight; ++curWeight ){
			costTable[curWeight][curBagItem] = costTable[curWeight][curBagItem - 1];
		}

		//if the current item is can be placed in the backpack:
		for(uint16_t curWeight = curBagItemWeight; curWeight <= backpackCapacity; ++curWeight ){
			uint16_t costWithCurBagItem = costTable[curWeight - curBagItemWeight][curBagItem - 1] + curBagItemCost;
			costTable[curWeight][curBagItem] = std::max(costTable[curWeight][curBagItem - 1], costWithCurBagItem);
		}
	}

	return costTable;
}

void showCostTable(std::vector<std::vector<uint16_t>>& costTable){
	for(uint16_t curWeight = 0;  curWeight < costTable.size(); ++curWeight){
		std::cout << curWeight << '\t';
		for(uint16_t curBagItem = 0; curBagItem < costTable[curBagItem].size(); ++curBagItem ){
			std::cout << costTable[curWeight][curBagItem] << ' ';
		}
		std::cout << '\n';
	}
}

int main() {
	uint16_t backpackCapacity{};
	std::cout << "Enter the capacity of the backpack: ";
	std::cin >> backpackCapacity;
	auto bagItems = createBagItemsArray();
	auto costTable = createCostTable(backpackCapacity, bagItems);
	showCostTable(costTable);

	return 0;
}
