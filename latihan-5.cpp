#include <iostream>
#include <string>

using namespace std;

struct Waktu {
  int jam;
  int menit;
  int detik;
};

class KumpulanLatihan {
private:
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

  int waktuKeDetik(const Waktu& waktu) {
    return (waktu.jam * 3600) + (waktu.menit * 60) + waktu.detik;
  }

  string tambahNol(int angka) {
    if (angka < 10 && angka >= 0) {
      return "0" + to_string(angka);
    } else {
      return to_string(angka);
    }
  }

  string formatWaktu(const Waktu& waktu) {
    return "(" + tambahNol(waktu.jam) + ":" + tambahNol(waktu.menit) + ":" + tambahNol(waktu.detik) + ")";
  }

  Waktu detikKeWaktu(long totalDetik) {
    Waktu hasil;
    hasil.jam = totalDetik / 3600;
    hasil.menit = (totalDetik % 3600) / 60;
    hasil.detik = totalDetik % 60;
    return hasil;
  }

  string hitungDurasi(Waktu mulai, Waktu selesai) {
    int totalDetikMulai = waktuKeDetik(mulai);
    int totalDetikSelesai = waktuKeDetik(selesai);

    int selisihDetik = totalDetikSelesai - totalDetikMulai;

    if (selisihDetik < 0) {
      selisihDetik += 24 * 3600;
    }

    Waktu durasi = detikKeWaktu(selisihDetik);
    return formatWaktu(durasi);
  }

  void konfirmasi() {
    cout << "\nTekan [Enter] untuk kembali ke menu...";
    cin.ignore();
    cin.get();
    return;
  }

public:
  void latihan1() {
    cout << "\n--- Latihan 1: Tiket Parkir Sederhana ---\n";
    int total, detik, jam, menit, biaya = 1000;

    cout << "Tiket Parkir \n";
    cout << "Masukkan waktu parkir dalam detik: ";
    cin >> total;

    if (total > 0) {
      jam = total / 3600;
      menit = (total % 3600) / 60;
      detik = total % 60;

      cout << "Waktu parkir: " << jam << " Jam, " << menit << " Menit, " << detik << " Detik. \n";

      if (total > 3600) {
        biaya += 2000 * jam;
      }

      cout << "Total biaya parkir: Rp " << biaya << endl;
    }
    konfirmasi();
  }

  void latihan2() {
    cout << "\n--- Latihan 2: Tiket Parkir Dinamis ---\n";
    bool lanjut = true;

    while (lanjut) {
      int total, detik, jam, menit, biaya = 1000;
      string kendaraan, kondisi;

      cout << "Tiket Parkir \n";
      bool jenis = true;
      while (jenis) {
        cout << "Masukkan Jenis Kendaraan [Mobil/Motor]: ";
        cin >> kendaraan;
        if (kendaraan == "mobil" || kendaraan == "Mobil" || kendaraan == "motor" || kendaraan == "Motor") {
          jenis = false;
        } else {
          cout << "Kendaraan tidak valid, masukkan ulang. \n";
        }
      }
      cout << "Masukkan waktu parkir dalam detik: ";
      cin >> total;

      if (total > 0) {
        jam = total / 3600;
        menit = (total % 3600) / 60;
        detik = total % 60;
        if (total > 3600) {
          if (kendaraan == "mobil" || kendaraan == "Mobil") {
            biaya += 3000 * jam;
            kendaraan = "Mobil";
          } else if (kendaraan == "motor" || kendaraan == "Motor") {
            biaya += 2000 * jam;
            kendaraan = "Motor";
          }
        }
        cout << "Jenis kendaraan [Mobil/Motor] : " << kendaraan << endl;
        cout << "Waktu parkir : " << jam << " Jam, " << menit << " Menit, " << detik << " Detik. \n";
        cout << "Total Biaya Parkir : Rp " << biaya << endl;
      }

      bool verif = true;
      while (verif) {
        cout << "Lanjut menginput? [Y/T] : ";
        cin >> kondisi;
        if (kondisi == "t" || kondisi == "T") {
          cout << "Terimakasih.";
          verif = false;
          lanjut = false;
        } else if (kondisi == "y" || kondisi == "Y") {
          cout << "Lanjut. \n";
          verif = false;
        } else {
          cout << "Tidak Valid. \n";
        }
      }
    }
    cout << endl;

    konfirmasi();
  }

  void latihan3_1() {
    cout << "\n--- Latihan 3-1: Pengecekan Elemen Array ---\n";
    int n = 5;
    // Array A dengan elemen yang sama semua
    int A[n] = {7, 7, 7, 7, 7};
    bool semuaSama = true;

    int elemenPertamaA = A[0];
    for (int i = 1; i < n; i++) {
      if (A[i] != elemenPertamaA) {
        semuaSama = false;
        break;
      }
    }

    if (semuaSama) {
      cout << "Semua elemen pada array A sama." << endl;
    } else {
      cout << "Elemen pada array A tidak sama." << endl;
    }

    int B[n] = {7, 7, 5, 7, 7};
    bool semuaSamaB = true;
    int elemenPertamaB = B[0];
    for (int i = 1; i < n; i++) {
      if (B[i] != elemenPertamaB) {
        semuaSamaB = false;
        break;
      }
    }

    if (semuaSamaB) {
      cout << "Semua elemen pada array B sama." << endl;
    } else {
      cout << "Elemen pada array B tidak sama." << endl;
    }
    konfirmasi();
  }

  void latihan3_2() {
    cout << "\n--- Latihan 3-2: Min, Max, dan Cari pada Array 2D ---\n";
    const int n = 2;
    const int m = 5;
    int A[n][m] = {{1, 7, 6, 4, 9}, {5, 3, 10, 2, 8}};

    int maxVal = A[0][0];
    int minVal = A[0][0];
    int cari;
    bool ditemukan = false;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> cari;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (A[i][j] > maxVal) {
          maxVal = A[i][j];
        }
        if (A[i][j] < minVal) {
          minVal = A[i][j];
        }
        if (A[i][j] == cari) {
          ditemukan = true;
        }
      }
    }
    cout << "Nilai maksimum pada array A: " << maxVal << endl;
    cout << "Nilai minimum pada array A: " << minVal << endl;
    if (!ditemukan) {
      cout << "Nilai " << cari << " tidak ditemukan dalam array A." << endl;
    } else {
      cout << "Nilai " << cari << " ditemukan dalam array A." << endl;
    }
    konfirmasi();
  }

  void latihan4_1() {
    cout << "\n--- Latihan 4-1: Jumlah N Bilangan Genap Pertama ---\n";
    int N;
    cout << "Masukkan jumlah bilangan genap pertama (N): ";
    cin >> N;

    hitungJumlahGenap(N);
    konfirmasi();
  }

  void latihan4_2() {
    cout << "\n--- Latihan 4-2: Kalkulator Durasi Waktu ---\n";
    Waktu mulai = {8, 30, 15};
    Waktu selesai = {11, 45, 5};
    cout << "Waktu mulai: " << formatWaktu(mulai) << endl;
    cout << "Waktu selesai: " << formatWaktu(selesai) << endl;
    cout << "Durasi: " << hitungDurasi(mulai, selesai) << endl;
    konfirmasi();
  }
};

void tampilkanMenu() {
  cout << "\n===== KUMPULAN LATIHAN SABIT =====" << endl;
  cout << "1. Latihan 1: Tiket Parkir Sederhana" << endl;
  cout << "2. Latihan 2: Tiket Parkir Dinamis" << endl;
  cout << "3. Latihan 3-1: Cek Elemen Array Identik" << endl;
  cout << "4. Latihan 3-2: Min, Max, Cari Array 2D" << endl;
  cout << "5. Latihan 4-1: Jumlah Bilangan Genap" << endl;
  cout << "6. Latihan 4-2: Kalkulator Durasi Waktu" << endl;
  cout << "0. Keluar" << endl;
  cout << "Pilih :";
}

int main() {
  KumpulanLatihan latihan; // Membuat objek dari kelas KumpulanLatihan
  int pilihan;

  do {
    tampilkanMenu();
    cin >> pilihan;

    switch (pilihan) {
    case 1:
      latihan.latihan1();
      break;
    case 2:
      latihan.latihan2();
      break;
    case 3:
      latihan.latihan3_1();
      break;
    case 4:
      latihan.latihan3_2();
      break;
    case 5:
      latihan.latihan4_1();
      break;
    case 6:
      latihan.latihan4_2();
      break;
    case 0:
      cout << "Terima kasih telah menggunakan program ini." << endl;
      break;
    default:
      cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
      break;
    }
  } while (pilihan != 0);

  return 0;
}