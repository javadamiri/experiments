#include <array>
#include <iostream>

constexpr int ARR_SIZE = 9;

void swap(std::array<int, ARR_SIZE> &arr, int left, int right) {
  std::cout << "swap( " << arr[left] << ", " << arr[right] << ")\n";
  const auto tmp = arr[left];
  arr[left] = arr[right];
  arr[right] = tmp;

  std::cout << "[";
  for (const auto &number : arr) {
    std::cout << number << ", ";
  }
  std::cout << "]\n";
}

int partition(std::array<int, ARR_SIZE> &arr, int left, int right) {
  std::cout << "partition( " << left << ", " << right << ")\n";
  int pivot = arr[right];
  //   int pivot = arr[(left + right) / 2];
  while (left < right) {
    while (arr[left] < pivot) {
      left++;
    }
    while (arr[right] > pivot) {
      right--;
    }
    if (left < right) {
      swap(arr, left, right);
      left++;
      right--;
    }
  }
  std::cout << "-> " << left << "\n";
  return left;
}

void quick_sort(std::array<int, ARR_SIZE> &arr, int left, int right) {
  std::cout << "quick_sort( " << left << ", " << right << ")\n";
  auto index = partition(arr, left, right);
  if (left < index - 1) {
    quick_sort(arr, left, index - 1);
  }
  if (index < right) {
    quick_sort(arr, index, right);
  }
}

int main() {
  std::array<int, ARR_SIZE> in_arr = {15, 3, 9, 8, 5, 2, 7, 6, 1};
  quick_sort(in_arr, 0, ARR_SIZE - 1);

  std::cout << "[";
  for (const auto &number : in_arr) {
    std::cout << number << ", ";
  }
  std::cout << "]\n";

  return 0;
}