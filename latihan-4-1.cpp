#include <iostream>

using namespace std;

void hitungJumlahGenap(int n) {
  if (n < 0) {
    cout << "N tidak boleh negatif." << endl;
    return;
  }
  int jumlah = 0;
  for (int i = 0; i < n; i++) {
    jumlah += 2 * i;
  }
  cout << "Jumlah dari " << n << " bilangan genap pertama adalah: " << jumlah << endl;
}

int main() {
  int N;
  cout << "Masukkan jumlah bilangan genap pertama (N): ";
  cin >> N;
  
  hitungJumlahGenap(N);
  
  return 0;
}