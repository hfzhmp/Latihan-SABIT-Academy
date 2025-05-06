#include <iostream>

using namespace std;

int main(){

  int total, detik, jam, menit, biaya = 1000;

  cout << "Tiket Parkir \n";
  cout << "Masukkan waktu parkir dalam detik: ";
  cin >> total;

  if(total > 0){

    jam = total / 3600;
    menit = (total % 3600) / 60;
    detik = total % 60;

    cout << "Waktu parkir :" << jam << " Jam, " << menit << " Menit, " << detik << " Detik. \n";

    if(jam < 1){
      cout << "total biaya parkir: Rp " << biaya;
    }else if (total > 3600){
      biaya += 2000 * jam;
    }

    cout << "total biaya parkir: Rp " << biaya;

  }

  return 0;
}