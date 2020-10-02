void insertionSort(std::vector<int>& vec) {
    int key{};
    for (int current = 0; current < vec.size(); ++current) {
        key = vec[current];
        int sortIndex = current - 1;

        while (sortIndex >= 0 && vec[sortIndex] > key) {
            vec[sortIndex + 1] = vec[sortIndex];
            --sortIndex;
        }

        vec[sortIndex + 1] = key;
    }
}