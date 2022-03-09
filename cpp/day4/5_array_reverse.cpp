#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

void generateArray(
  int minNumberInRange,
  int maxNumberInRange,
  int arraySize,
  double array[]
) {
  int rangeDiff = (maxNumberInRange + 1) - minNumberInRange;
  int currentTime = time(0);
  srand(currentTime);

  cout << "Array: ";

  for (int i = 0; i < arraySize; i++) {
    double randomNumber = (double)rand() / RAND_MAX; // generate random numbers between 0 to 1
    double randomNumberInRange = (randomNumber * rangeDiff) + minNumberInRange;
    double fixedTwoDecimalPlaces = round(randomNumberInRange * 100) / 100;

    array[i] = fixedTwoDecimalPlaces;

    cout << array[i];
    if (i != arraySize - 1) {
      cout << ", ";
    }
  }
}

void reverseArray(int arraySize, double array[], double reversedArray[]) {
  for (int j = arraySize; j > 0; j--) {
    reversedArray[arraySize - j] = array[j - 1];
  }
}

void printArray(int arraySize, double array[]) {
  cout << "Reversed array: ";

  for (int i = 0; i < arraySize; i++) {
    cout << array[i];
    if (i != arraySize - 1) {
      cout << ", ";
    }
  }
}

int main() {
  int minNumberInRange;
  int maxNumberInRange;
  int arraySize;

  cout << "Set a numbers range" << endl;
  cout << "Min: ";
  cin >> minNumberInRange;

  cout << "Max: ";
  cin >> maxNumberInRange;

  if (minNumberInRange > maxNumberInRange) {
    cout << "Min number should be less than max number" << endl;
    return 0;
  }

  cout << "Set array size: ";
  cin >> arraySize;
  cout << "==================================" << endl;

  double array[arraySize];
  double reversedArray[arraySize];

  generateArray(minNumberInRange, maxNumberInRange, arraySize, array);
  cout << endl;

  reverseArray(arraySize, array, reversedArray);
  printArray(arraySize, reversedArray);
  cout << endl;

  return 0;
}