#include <iostream>
#include <vector>
#include <random>
#include <chrono>

int merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;
    int comparisons = 0;

    while (i < n1 && j < n2) {
        comparisons++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }

    return comparisons;
}

int mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        int comparisonsLeft = mergeSort(arr, left, middle);
        int comparisonsRight = mergeSort(arr, middle + 1, right);

        int comparisonsMerge = merge(arr, left, middle, right);

        return comparisonsLeft + comparisonsRight + comparisonsMerge;
    }

    return 0;
}

int partition(std::vector<int>& arr, int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high, int& comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);

        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

std::vector<int> generateRandomDigits(int length) {
    std::vector<int> result;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1000);

    for (int i = 0; i < length; i++) {
        result.push_back(dis(gen));
    }

    return result;
}

int main() {
    int lungime;
    std::cout << "Cate elemente sa aiba Vectorul:";
    std::cin>>lungime;
    std::vector<int> arr = generateRandomDigits(lungime);
    std::vector<int> arr2 = arr;
    int n = arr.size();

    auto start1 = std::chrono::high_resolution_clock::now();
    int comparisons1 = mergeSort(arr, 0, n - 1);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
    std::cout << "Time taken by function MergeSort: "
              << duration1.count() << " seconds" << std::endl;


    auto start = std::chrono::high_resolution_clock::now();
    int comparisons2 = 0;
    quickSort(arr2, 0, n - 1, comparisons2);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken by function Quick Sort: "
         << duration.count() << " seconds" << std::endl;


    std::cout << "Vectorul Sortat cu MergeSort: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";

    std::cout << "Vectorul Sortat cu QuickSort: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\nNumber of comparisons MergeSort: " << comparisons1;

    std::cout << "\nNumber of comparisons QuickSort: " << comparisons2;

    return 0;
}
