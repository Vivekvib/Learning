#include <iostream>
#include <vector>

using namespace std;
int merge(vector<int>& arr, int left, int right) {
    if (left == right) {
        return 0;
    }
    
    int mid = (left + right) / 2;
    int comparisons = 0;

    comparisons += merge(arr, left, mid);  // Left half
    comparisons += merge(arr, mid + 1, right);  // Right half

    // Merging step
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        comparisons++;
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = 0; i < temp.size(); i++) {
        arr[left + i] = temp[i];
    }

    return comparisons;
}

int merge_sort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return 0;  // No comparisons needed
    }
    int mid = (left + right) / 2;
    int comparisons = 0;
    
    comparisons += merge_sort(arr, left, mid);  // Left part
    comparisons += merge_sort(arr, mid + 1, right);  // Right part

    comparisons += merge(arr, left, right);  // Merging the two halves

    return comparisons;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};  // Sample array
    int n = arr.size();
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int comparisons = merge_sort(arr, 0, n - 1);  // Sorting the array

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Total comparisons made: " << comparisons << endl;

    return 0;
}
