#include <iostream>

using namespace std;

int main() {
  int n = 5;
  // Array A dengan elemen yang sama semua
  int A[n] = {7, 7, 7, 7, 7};

  bool semuaSama = true;

  int elemenPertama = A[0];
  for (int i = 1; i < n; i++) {
    if (A[i] != elemenPertama) {
      semuaSama = false;
      break; 
    }
  }

  if (semuaSama) {
    cout << "Semua elemen pada array A sama." << endl;
  } else {
    cout << "Elemen pada array A tidak sama." << endl;
  }

  // Array B dengan salah satu elemen berbeda
  int B[n] = {7, 7, 5, 7, 7};
  elemenPertama = B[0];
  for (int i = 1; i < n; i++) {
    if (B[i] != elemenPertama) {
      semuaSama = false;
      break; 
    }
  }

  if (semuaSama) {
    cout << "Semua elemen pada array B sama." << endl;
  } else {
    cout << "Elemen pada array B tidak sama." << endl;
  }

  return 0;
}