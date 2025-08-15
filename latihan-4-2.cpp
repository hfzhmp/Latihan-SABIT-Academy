#include <iostream>
#include <string>

using namespace std;

struct Waktu {
  int jam;
  int menit;
  int detik;
};

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

  // Negatif = lewat tengah malam, tambah 24 jam
  if (selisihDetik < 0) {
    selisihDetik += 24 * 3600;
  }

  Waktu durasi = detikKeWaktu(selisihDetik);

  return formatWaktu(durasi);
}

int main() {
  Waktu mulai1 = {8, 30, 15};
  Waktu selesai1 = {11, 45, 5};
  cout << "Waktu mulai: " << formatWaktu(mulai1) << endl;
  cout << "Waktu selesai: " << formatWaktu(selesai1) << endl;
  cout << "Durasi: " << hitungDurasi(mulai1, selesai1) << endl;

  return 0;
}