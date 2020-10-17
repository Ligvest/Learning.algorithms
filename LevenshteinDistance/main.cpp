#include <iostream>
#include <vector>

/*
 * levenshtein distance
 * find the number of minimum changes which will let you to change one string to another
 *
 * Solution formula:
 * the number of minimum cahnges for strings with N and M sizes will be 1 + the minimum number between strings with:
 * N - 1 and M sizes
 * N and M - 1 sizes
 * N - 1 and M -  sizes
 * in case if last letters don't match.
 * and
 * N - 1 and M -  sizes in case if last letters match
 *
 * In code:
	if(firstWord.back() != secondWord.back()){
		return std::min(
						std::min(
							levenshteinDistanceRecursive(firstWord, secondWord.substr(0, secondWord.size() - 1)),
							levenshteinDistanceRecursive(firstWord.substr(0, firstWord.size() - 1), secondWord)),
							levenshteinDistanceRecursive(firstWord.substr(0, firstWord.size() - 1), secondWord.substr(0, secondWord.size() - 1))) + 1;
	} else {
		return levenshteinDistanceRecursive(firstWord.substr(0, firstWord.size() - 1), secondWord.substr(0, secondWord.size() - 1));
	}
 */


uint16_t levenshteinDistanceRecursive(std::string firstWord, std::string secondWord){
	uint16_t result{0};
	if(firstWord.empty() && !secondWord.empty()){
		return secondWord.size();
	}

	if(!firstWord.empty() && secondWord.empty()){
		return firstWord.size();
	}

	if(firstWord.empty() && secondWord.empty()){
		return 0;
	}

	if(firstWord.back() == secondWord.back()){
		result = levenshteinDistanceRecursive(firstWord.substr(0, firstWord.size() - 1), secondWord.substr(0, secondWord.size() - 1));
	} else {
			result = std::min(
						std::min(
							levenshteinDistanceRecursive(firstWord, secondWord.substr(0, secondWord.size() - 1)),
							levenshteinDistanceRecursive(firstWord.substr(0, firstWord.size() - 1), secondWord)),
							levenshteinDistanceRecursive(firstWord.substr(0, firstWord.size() - 1), secondWord.substr(0, secondWord.size() - 1))) + 1;
	}

	return result;
}

uint16_t levenshteinDistanceDynamic(std::string& firstWord, std::string& secondWord){
	if(firstWord.empty() && !secondWord.empty()){
		return secondWord.size();
	}

	if(!firstWord.empty() && secondWord.empty()){
		return firstWord.size();
	}

	if(firstWord.empty() && secondWord.empty()){
		return 0;
	}

	uint16_t result{0};
	// will be initialized by default ( with zeros)
	std::vector<std::vector<uint16_t>> distanceTable;
	distanceTable.resize(firstWord.size() + 1);
	for(auto& row : distanceTable){
		row.resize(secondWord.size() + 1);
	}

	for(uint16_t firstWordLetter = 1; firstWordLetter <= firstWord.size(); ++firstWordLetter){
		distanceTable[firstWordLetter][0] = firstWordLetter;
	}

	for(uint16_t secondWordLetter = 1; secondWordLetter <= secondWord.size(); ++secondWordLetter){
		distanceTable[0][secondWordLetter] = secondWordLetter;
	}

	for(uint16_t firstWordLetter = 1; firstWordLetter <= firstWord.size(); ++firstWordLetter){
		for(uint16_t secondWordLetter = 1; secondWordLetter <= secondWord.size(); ++secondWordLetter){
			if(firstWord[firstWordLetter - 1] == secondWord[secondWordLetter - 1]){
				distanceTable[firstWordLetter][secondWordLetter] = distanceTable[firstWordLetter - 1][secondWordLetter - 1];
			} else {
				distanceTable[firstWordLetter][secondWordLetter] = std::min(std::min(
							distanceTable[firstWordLetter - 1][secondWordLetter],
							distanceTable[firstWordLetter][secondWordLetter - 1]),distanceTable[firstWordLetter - 1][secondWordLetter - 1])  + 1;
			}
		}
	}

	return distanceTable[firstWord.size()][secondWord.size()];
}
int main() {
	std::string first("honda");
	std::string second("hyundai");

	std::cout<<"Levenshtein distance between \""
			<< first << "\" and \"" << second
			<< "\" is " << levenshteinDistanceRecursive(first, second) << std::endl;

	return 0;
}
