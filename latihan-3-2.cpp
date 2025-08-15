#include <iostream>

using namespace std;

int main() {
  int n = 2;
  int m = 5;
  int A[n][m] = {{1, 7, 6, 4, 9}, {5, 3, 10, 2, 8}};

  int max = A[0][0];
  int min = A[0][0];
  int cari;
  bool ditemukan = false;
  cout << "Masukkan nilai yang ingin dicari: ";
  cin >> cari;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (A[i][j] > max) {
        max = A[i][j];
      }
      if (A[i][j] < min) {
        min = A[i][j];
      }
      if (A[i][j] == cari) {
        ditemukan = true;
      }
    }
  }
  cout << "Nilai maksimum pada array A: " << max << endl; 
  cout << "Nilai minimum pada array A: " << min << endl;
  if (!ditemukan) {
    cout << "Nilai " << cari << " tidak ditemukan dalam array A." << endl;
  } else {
    cout << "Nilai " << cari << " ditemukan dalam array A." << endl;
  }
  return 0;
}