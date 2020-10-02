void radixLsdSort(std::vector<int>& toSort) {
    std::vector<std::list<int>> sortedLists(10);
    int factor = 10;
    bool digitsExist = true;
    while (digitsExist) {
        digitsExist = false;
        for (int value : toSort) {
            size_t currentDigit = (value % factor) / (factor / 10);
            sortedLists[currentDigit].push_back(value);

            if (value / factor > 0) {
                digitsExist = true;
            }
        }

        size_t index = 0;
        for (auto sortedList : sortedLists) {
            for (int sortedValue : sortedList) {
                toSort[index] = sortedValue;
                ++index;
            }
        }

        factor *= 10;
        for (auto& sortedList : sortedLists) {
            sortedList.clear();
        }
    }
}