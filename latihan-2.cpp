#include <iostream>

using namespace std;

int main(){

  bool lanjut = true;

  while(lanjut){
    int total, detik, jam, menit, biaya = 1000;
    string kendaraan, kondisi;

    cout << "Tiket Parkir \n";
    bool jenis = true;
    while(jenis){
      cout << "Masukkan Jenis Kendaraan [Mobil/Motor]: ";
      cin >> kendaraan;
      if(kendaraan == "mobil" || kendaraan == "Mobil"){
        jenis = false;
      }
      else if(kendaraan == "motor" || kendaraan == "Motor"){
        jenis = false;
      }
      else{
        cout << "Kendaraan tidak valid, masukkan ulang. \n";
      }
    }
    cout << "Masukkan waktu parkir dalam detik: ";
    cin >> total;

    if(total > 0){

      jam = total / 3600;
      menit = (total % 3600) / 60;
      detik = total % 60;
      if(jam < 1){
        cout << "Jenis kendaraan [Mobil/Motor] : " << kendaraan << endl;
        cout << "Waktu parkir : " << jam << " Jam, " << menit << " Menit, " << detik << " Detik. \n";
        cout << "Total Biaya Parkir : Rp " << biaya;
      }else if (total > 3600){
        if(kendaraan == "mobil" || kendaraan == "Mobil"){
          biaya += 3000 * jam;
          kendaraan = "Mobil";
        }
        else if(kendaraan == "motor" || kendaraan == "Motor"){
          biaya += 2000 * jam;
          kendaraan = "Motor";
        }
      }
      cout << "Jenis kendaraan [Mobil/Motor] : " << kendaraan << endl;
      cout << "Waktu parkir : " << jam << " Jam, " << menit << " Menit, " << detik << " Detik. \n";
      cout << "Total Biaya Parkir : Rp " << biaya << endl;
    }

    bool verif = true;
    while(verif){
      cout << "Lanjut menginput? [Y/T] : ";
      cin >> kondisi;
      if(kondisi == "t" || kondisi == "T"){
        cout << "Terimakasih.";
        verif = false;
        lanjut = false;
      }else if(kondisi == "y" || kondisi == "Y"){
        cout << "Lanjut. \n";
        verif = false;
      }else{
        cout << "Tidak Valid. \n";
      }
    }
  }
  return 0;
}