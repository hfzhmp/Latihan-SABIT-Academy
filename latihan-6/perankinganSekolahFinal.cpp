#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Peserta {
  int idPeserta;
  string nisn;
  string nama;
  string noTelp;
  string alamat;
};

struct Nilai {
  int idPeserta;
  int P1; // Logika & Penalaran
  int P2; // Kreativitas & Estetika
  int P3; // Ketekunan & Praktik
  int P4; // Komunikasi
  int P5; // Nilai Akademik
  int P6; // Religiusitas / Nilai Keagamaan
  int P7; // Adaptasi Sosial

  float skorSMA = 0;
  float skorSMK = 0;
  float skorMA = 0;
  float skorPesantren = 0;
  float skorInternasional = 0;
};

vector<Peserta> daftarPeserta;
vector<Nilai> daftarNilai;
// mencegah duplikasi ID peserta
int nextIdPeserta = 0; 

const float bobotTambahan[2] = {0.05, 0.05};
// Bobot per poin untuk setiap aspek penilaian

const int relevansi[5][7] = {
  {3, 2, 1, 2, 3, 1, 2}, // SMA
  {2, 3, 3, 3, 2, 1, 2}, // SMK
  {2, 1, 2, 1, 3, 3, 2}, // MA
  {1, 0, 2, 1, 2, 3, 1}, // Pesantren
  {3, 3, 1, 3, 3, 1, 3}  // Internasional
};

bool cekNISN(const string& nisn) {
  for (const Peserta& p : daftarPeserta) {
    if (p.nisn == nisn) return true;
  }
  return false;
}

void konfirmasi() {
  cout << "\nTekan [Enter] untuk kembali ke menu...";
  cin.ignore();
  cin.get();
  return;
}

bool cekPeserta() {
  if (daftarPeserta.empty()) {
    cout << "Tidak ada peserta yang terdaftar.\n";
    konfirmasi();
    return true;
  }
  return false;
}

void menu2() {
  cout << "1. Berdasarkan NISN\n";
  cout << "2. Berdasarkan ID Peserta\n";
  cout << "0. Kembali ke Menu\n";
  cout << "Pilih: ";
}

// Create
void tambahPeserta() {
  bool lanjut = true;
  Peserta p;

  do {
    cout << "\n[Tambah Peserta]\n";
    p.idPeserta = nextIdPeserta++;
    cout << "ID Peserta : " << p.idPeserta << endl;
    // Validasi NISN
    bool nisn = true;
    while (nisn) {
      cout << "NISN       : ";
      cin >> p.nisn;

      if(cin.fail()){
        cout << "NISN tidak Valid. \n";
        cin.clear();
      } else {
        if (cekNISN(p.nisn)) {
          cout << "NISN sudah digunakan.\n";
        } else {
          break;
        }
      }
    }

    cout << "Nama       : "; cin.ignore(); getline(cin, p.nama);
    cout << "No Telp    : "; cin >> p.noTelp;
    cout << "Alamat     : "; cin.ignore(); getline(cin, p.alamat);

    daftarPeserta.push_back(p);

    char param;
    cout << "Ingin menambah? [Y/T] : ";
    cin >> param;
    if (param == 'T' || param == 't') {
      lanjut = false;
    }

  } while (lanjut);
}

// Read
void listPeserta() {
  cout << "\n[Daftar Peserta]\n";
  if (cekPeserta()) return;
  cout << "Total Peserta: " << daftarPeserta.size() << endl;
  cout << "-----------------------------------\n";
  int no = 1;
  for (const Peserta& p : daftarPeserta) {
    cout << no++ << ". ID: " << p.idPeserta 
          << ", NISN: " << p.nisn
          << ", Nama: " << p.nama 
          << ", No Telp: " << p.noTelp
          << ", Alamat: " << p.alamat << endl;
  }
  konfirmasi();    
}

// Search data Peserta by NISN
void cariPesertaNISN() {
  cout << "\n[Cari Peserta Berdasarkan NISN]\n";
  string nisn;
  cout << "Masukkan NISN Peserta: ";
  cin >> nisn;

  bool ditemukan = false;
  for (const Peserta& p : daftarPeserta) {
    if (p.nisn == nisn) {
      // data peserta
      cout << "\n[Data Peserta]\n";
      cout << "ID Peserta : " << p.idPeserta << endl;
      cout << "NISN       : " << p.nisn << endl;
      cout << "Nama       : " << p.nama << endl;
      cout << "No Telp    : " << p.noTelp << endl;
      cout << "Alamat     : " << p.alamat << endl;
      ditemukan = true;

      // cek nilai
      bool nilaiDitemukan = false;
      for (const Nilai& n : daftarNilai) {
        if (n.idPeserta == p.idPeserta) {
          cout << "\n[Nilai & Skor Rekomendasi]\n";
          cout << "Logika & Penalaran       : " << n.P1 << endl;
          cout << "Kreativitas & Estetika   : " << n.P2 << endl;
          cout << "Ketekunan & Praktik      : " << n.P3 << endl;
          cout << "Komunikasi               : " << n.P4 << endl;
          cout << "Nilai Akademik           : " << n.P5 << endl;
          cout << "Religiusitas / Keagamaan : " << n.P6 << endl;
          cout << "Adaptasi Sosial          : " << n.P7 << endl;
          cout << "\nSkor Rekomendasi Sekolah:\n";
          cout << "SMA          : " << n.skorSMA << endl;
          cout << "SMK          : " << n.skorSMK << endl;
          cout << "MA           : " << n.skorMA << endl;
          cout << "Pesantren    : " << n.skorPesantren << endl;
          cout << "Internasional: " << n.skorInternasional << endl;
          nilaiDitemukan = true;
          break;
        }
      }
      if (!nilaiDitemukan) {
        cout << "\nNilai belum diinput.\n";
      } 
      return;
    }
  }
  if (!ditemukan) {
    cout << "Peserta tidak ditemukan.\n";
    konfirmasi();
  }
}
// Searh data Peserta by ID
void cariPesertaId() {
  cout << "\n[Cari Peserta Berdasarkan ID]\n";
  int id;
  cout << "Masukkan ID Peserta: ";
  cin >> id;

  bool ditemukan = false;
  for (const Peserta& p : daftarPeserta) {
    if (p.idPeserta == id) {
      // data peserta
      cout << "\n[Data Peserta]\n";
      cout << "ID Peserta : " << p.idPeserta << endl;
      cout << "NISN       : " << p.nisn << endl;
      cout << "Nama       : " << p.nama << endl;
      cout << "No Telp    : " << p.noTelp << endl;
      cout << "Alamat     : " << p.alamat << endl;
      ditemukan = true;

      // cek nilai
      bool nilaiDitemukan = false;
      for (const Nilai& n : daftarNilai) {
        if (n.idPeserta == id) {
          cout << "\n[Nilai & Skor Rekomendasi]\n";
          cout << "Logika & Penalaran       : " << n.P1 << endl;
          cout << "Kreativitas & Estetika   : " << n.P2 << endl;
          cout << "Ketekunan & Praktik      : " << n.P3 << endl;
          cout << "Komunikasi               : " << n.P4 << endl;
          cout << "Nilai Akademik           : " << n.P5 << endl;
          cout << "Religiusitas / Keagamaan : " << n.P6 << endl;
          cout << "Adaptasi Sosial          : " << n.P7 << endl;
          cout << "\nSkor Rekomendasi Sekolah:\n";
          cout << "SMA          : " << n.skorSMA << endl;
          cout << "SMK          : " << n.skorSMK << endl;
          cout << "MA           : " << n.skorMA << endl;
          cout << "Pesantren    : " << n.skorPesantren << endl;
          cout << "Internasional: " << n.skorInternasional << endl;
          nilaiDitemukan = true;
          break;
        }
      }
      if (!nilaiDitemukan) {
        cout << "\nNilai belum diinput.\n";
      }
      return;
    }
  }

  if (!ditemukan) {
    cout << "Peserta tidak ditemukan.\n";
  }
}
// Menu Search Peserta
void cariPeserta() {
  bool lanjut = true;
  do{
    cout << "\n[Cari Peserta]\n";
    if (cekPeserta()) return;
    menu2();
    int pilihan;
    cin >> pilihan;
    switch (pilihan) {
    case 1: cariPesertaNISN(); break;
    case 2: cariPesertaId(); break;
    case 0: lanjut = false; break;
    default: 
      cout << "Pilihan tidak valid.\n"; 
      break;
    }
  } while(lanjut);
}

// Update
void hapusPesertaId() {
  cout << "\n[Hapus Peserta dan Nilai Berdasarkan ID]\n";
  int id;
  cout << "Masukkan ID Peserta yang ingin dihapus: ";
  cin >> id;

  bool pesertaDitemukan = false;

  // Cari dan hapus peserta
  for (int i = 0; i < daftarPeserta.size(); i++) {
    if (daftarPeserta[i].idPeserta == id) {
      cout << "\nData yang akan dihapus:\n";
      cout << "ID Peserta : " << daftarPeserta[i].idPeserta << endl;
      cout << "NISN       : " << daftarPeserta[i].nisn << endl;
      cout << "Nama       : " << daftarPeserta[i].nama << endl;
      cout << "No Telp    : " << daftarPeserta[i].noTelp << endl;
      cout << "Alamat     : " << daftarPeserta[i].alamat << endl;

      char konfirmasi;
      cout << "\nYakin ingin menghapus data ini? [Y/T]: ";
      cin >> konfirmasi;

      if (konfirmasi == 'Y' || konfirmasi == 'y') {
        // Hapus dari daftarPeserta
        daftarPeserta.erase(daftarPeserta.begin() + i);
        pesertaDitemukan = true;

        // Hapus nilai terkait
        for (int j = 0; j < daftarNilai.size(); j++) {
          if (daftarNilai[j].idPeserta == id) {
            daftarNilai.erase(daftarNilai.begin() + j);
            break;
          }
        }

        cout << "Data peserta dan nilai berhasil dihapus.\n";
      } else {
        cout << "Penghapusan dibatalkan.\n";
      }

      break;
    }
  }

  if (!pesertaDitemukan) {
    cout << "Peserta tidak ditemukan.\n";
  }
}

void updatePesertaId() {
  cout << "\n[Update Data Peserta dan Nilai Berdasarkan Id]\n";
  int id;
  cout << "Masukkan ID Peserta: ";
  cin >> id;

  bool pesertaDitemukan = false;
  for (Peserta& p : daftarPeserta) {
    if (p.idPeserta == id) {
      cout << "\n[Data Peserta Saat Ini]\n";
      cout << "NISN    : " << p.nisn << endl;
      cout << "Nama    : " << p.nama << endl;
      cout << "No Telp : " << p.noTelp << endl;
      cout << "Alamat  : " << p.alamat << endl;

      char paramData;
      cout << "\nApakah ingin mengubah data peserta? [Y/T]: ";
      cin >> paramData;
      if (paramData == 'Y' || paramData == 'y') {
        cout << "\n[Masukkan Data Baru]\n";
        // Validasi NISN
        bool nisn = true;
        while (nisn) {
          cout << "NISN    : ";
          cin >> p.nisn;

          if (cekNISN(p.nisn)) {
            cout << "NISN sudah digunakan.\n";
          } else {
            break;
          }
        }
        cout << "Nama    : "; cin.ignore(); getline(cin, p.nama);
        cout << "No Telp : "; cin >> p.noTelp;
        cout << "Alamat  : "; cin.ignore(); getline(cin, p.alamat);
        cout << "Data peserta berhasil diperbarui.\n";
      } else {
        cout << "Data peserta tidak diubah.\n";
      }

      pesertaDitemukan = true;

      // Temukan dan tampilkan nilai
      bool nilaiDitemukan = false;
      for (Nilai& n : daftarNilai) {
        if (n.idPeserta == id) {
          cout << "\n[Nilai Saat Ini]\n";
          cout << "Logika & Penalaran       : " << n.P1 << endl;
          cout << "Kreativitas & Estetika   : " << n.P2 << endl;
          cout << "Ketekunan & Praktik      : " << n.P3 << endl;
          cout << "Komunikasi               : " << n.P4 << endl;
          cout << "Nilai Akademik           : " << n.P5 << endl;
          cout << "Religiusitas / Keagamaan : " << n.P6 << endl;
          cout << "Adaptasi Sosial          : " << n.P7 << endl;

          char paramNilai;
          cout << "\nApakah ingin mengubah nilai? [Y/T]: ";
          cin >> paramNilai;
          if (paramNilai == 'Y' || paramNilai == 'y') {
            cout << "\n[Masukkan Nilai Baru (0-5)]\n";
            cout << "Logika & Penalaran       : "; cin >> n.P1;
            cout << "Kreativitas & Estetika   : "; cin >> n.P2;
            cout << "Ketekunan & Praktik      : "; cin >> n.P3;
            cout << "Komunikasi               : "; cin >> n.P4;
            cout << "Nilai Akademik           : "; cin >> n.P5;
            cout << "Religiusitas / Keagamaan : "; cin >> n.P6;
            cout << "Adaptasi Sosial          : "; cin >> n.P7;

            // Hitung ulang skor
            n.skorSMA = n.skorSMK = n.skorMA = n.skorPesantren = n.skorInternasional = 0;
            int aspek[7] = {n.P1, n.P2, n.P3, n.P4, n.P5, n.P6, n.P7};
            for (int i = 0; i < 7; i++) {
              n.skorSMA         += aspek[i] * relevansi[0][i];
              n.skorSMK         += aspek[i] * relevansi[1][i];
              n.skorMA          += aspek[i] * relevansi[2][i];
              n.skorPesantren   += aspek[i] * relevansi[3][i];
              n.skorInternasional += aspek[i] * relevansi[4][i];
            }
            cout << "Nilai berhasil diperbarui.\n";
          } else {
            cout << "Nilai tidak diubah.\n";
          }

          nilaiDitemukan = true;
          break;
        }
      }

      if (!nilaiDitemukan) {
        cout << "\nNilai belum diinput.\n";
      }

      return;
    }
  }

  if (!pesertaDitemukan) {
    cout << "Peserta tidak ditemukan.\n";
  }
}

void updatePesertaNISN() {
  cout << "\n[Update Data Peserta dan Nilai Berdasarkan NISN]\n";
  string nisn;
  cout << "Masukkan NISN Peserta yang ingin dihapus: ";
  cin >> nisn;

  bool pesertaDitemukan = false;
  for (Peserta& p : daftarPeserta) {
    if (p.nisn == nisn) {
      cout << "\n[Data Peserta Saat Ini]\n";
      cout << "NISN    : " << p.nisn << endl;
      cout << "Nama    : " << p.nama << endl;
      cout << "No Telp : " << p.noTelp << endl;
      cout << "Alamat  : " << p.alamat << endl;

      char paramData;
      cout << "\nApakah ingin mengubah data peserta? [Y/T]: ";
      cin >> paramData;
      if (paramData == 'Y' || paramData == 'y') {
        cout << "\n[Masukkan Data Baru]\n";
        cout << "NISN    : " << p.nisn << endl;
        cout << "Nama    : "; cin.ignore(); getline(cin, p.nama);
        cout << "No Telp : "; cin >> p.noTelp;
        cout << "Alamat  : "; cin.ignore(); getline(cin, p.alamat);
        cout << "Data peserta berhasil diperbarui.\n";
      } else {
        cout << "Data peserta tidak diubah.\n";
      }

      pesertaDitemukan = true;

      // Temukan dan tampilkan nilai
      bool nilaiDitemukan = false;
      for (Nilai& n : daftarNilai) {
        if (n.idPeserta == p.idPeserta) {
          cout << "\n[Nilai Saat Ini]\n";
          cout << "Logika & Penalaran       : " << n.P1 << endl;
          cout << "Kreativitas & Estetika   : " << n.P2 << endl;
          cout << "Ketekunan & Praktik      : " << n.P3 << endl;
          cout << "Komunikasi               : " << n.P4 << endl;
          cout << "Nilai Akademik           : " << n.P5 << endl;
          cout << "Religiusitas / Keagamaan : " << n.P6 << endl;
          cout << "Adaptasi Sosial          : " << n.P7 << endl;

          char paramNilai;
          cout << "\nApakah ingin mengubah nilai? [Y/T]: ";
          cin >> paramNilai;
          if (paramNilai == 'Y' || paramNilai == 'y') {
            cout << "\n[Masukkan Nilai Baru (0-5)]\n";
            cout << "Logika & Penalaran       : "; cin >> n.P1;
            cout << "Kreativitas & Estetika   : "; cin >> n.P2;
            cout << "Ketekunan & Praktik      : "; cin >> n.P3;
            cout << "Komunikasi               : "; cin >> n.P4;
            cout << "Nilai Akademik           : "; cin >> n.P5;
            cout << "Religiusitas / Keagamaan : "; cin >> n.P6;
            cout << "Adaptasi Sosial          : "; cin >> n.P7;

            // Hitung ulang skor
            n.skorSMA = n.skorSMK = n.skorMA = n.skorPesantren = n.skorInternasional = 0;
            int aspek[7] = {n.P1, n.P2, n.P3, n.P4, n.P5, n.P6, n.P7};
            for (int i = 0; i < 7; i++) {
              n.skorSMA         += aspek[i] * relevansi[0][i];
              n.skorSMK         += aspek[i] * relevansi[1][i];
              n.skorMA          += aspek[i] * relevansi[2][i];
              n.skorPesantren   += aspek[i] * relevansi[3][i];
              n.skorInternasional += aspek[i] * relevansi[4][i];
            }
            cout << "Nilai berhasil diperbarui.\n";
          } else {
            cout << "Nilai tidak diubah.\n";
          }

          nilaiDitemukan = true;
          break;
        }
      }

      if (!nilaiDitemukan) {
        cout << "\nNilai belum diinput.\n";
      }

      return;
    }
  }

  if (!pesertaDitemukan) {
    cout << "Peserta tidak ditemukan.\n";
  }
}

void updatePeserta() {
  bool lanjut = true;
  do{
    cout << "\n[Update Peserta & Nilai]\n";
    if (cekPeserta()) return;
    menu2();
    int pilihan;
    cin >> pilihan;
    switch (pilihan) {
      case 1: updatePesertaNISN(); break;
      case 2: updatePesertaId(); break;
      case 0: lanjut = false; break;
      default:
        cout << "Pilihan tidak valid.\n"; 
        break;
    }
  } while(lanjut);
}

void hapusPesertaNISN() {
  cout << "\n[Hapus Peserta dan Nilai Berdasarkan NISN]\n";
  string nisn;
  cout << "Masukkan NISN Peserta yang ingin dihapus: ";
  cin >> nisn;

  bool pesertaDitemukan = false;
  // Cari dan hapus peserta
  for (int i = 0; i < daftarPeserta.size(); i++) {
    if (daftarPeserta[i].nisn == nisn) {
      cout << "\nData yang akan dihapus:\n";
      cout << "ID Peserta : " << daftarPeserta[i].idPeserta << endl;
      cout << "NISN       : " << daftarPeserta[i].nisn << endl;
      cout << "Nama       : " << daftarPeserta[i].nama << endl;
      cout << "No Telp    : " << daftarPeserta[i].noTelp << endl;
      cout << "Alamat     : " << daftarPeserta[i].alamat << endl;

      int id = daftarPeserta[i].idPeserta;

      char konfirmasi;
      cout << "\nYakin ingin menghapus data ini? [Y/T]: ";
      cin >> konfirmasi;

      if (konfirmasi == 'Y' || konfirmasi == 'y') {
        // Hapus dari daftarPeserta
        daftarPeserta.erase(daftarPeserta.begin() + i);
        pesertaDitemukan = true;

        // Hapus nilai terkait
        for (int j = 0; j < daftarNilai.size(); j++) {
          if (daftarNilai[j].idPeserta == id) {
            daftarNilai.erase(daftarNilai.begin() + j);
            break;
          }
        }

        cout << "Data peserta dan nilai berhasil dihapus.\n";
      } else {
        cout << "Penghapusan dibatalkan.\n";
      }

      break;
    }
  }

  if (!pesertaDitemukan) {
    cout << "Peserta tidak ditemukan.\n";
  }
}

void hapusPeserta() {
  bool lanjut = true;
  do{
    cout << "\n[Hapus Peserta & Nilai]\n";
    if (cekPeserta()) return;
    menu2();
    int pilihan;
    cin >> pilihan;
    switch (pilihan) {
      case 1: hapusPesertaNISN(); break;
      case 2: hapusPesertaId(); break;
      case 0: lanjut = false; break;
      default:
        cout << "Pilihan tidak valid.\n"; 
        break;
    }
  } while(lanjut);
}

void tambahNilai() {
  Nilai n;
  cout << "\n[Input Nilai Peserta]\n";
  cout << "ID Peserta: "; cin >> n.idPeserta;
  // cari peserta berdasarkan ID
  bool ditemukan = false;
  for (const Peserta& p : daftarPeserta) {
    if (p.idPeserta == n.idPeserta) {
      cout << "NISN  : " << p.nisn << endl;
      cout << "Nama  : " << p.nama << endl;

      // konfirmasi
      char param;
      cout << "Betul? [Y/T] : ";
      cin >> param;
      if (param == 'Y' || param == 'y') {
        // cek peserta sudah memiliki nilai atau belum
        for (const Nilai& nilai : daftarNilai) {
          if (nilai.idPeserta == n.idPeserta) {
            cout << "Peserta sudah memiliki nilai.\n";
            return;
          }
        }
        ditemukan = true;
      } else {
        cout << "Dibatalkan.\n";
        return;
      }
      break;
    }
  }
  if (!ditemukan) {
    cout << "ID Peserta tidak ditemukan.\n";
    return;
  }

  // Input nilai
  cout << "Logika & Penalaran (0-5): "; cin >> n.P1;
  cout << "Kreativitas & Estetika (0-5): "; cin >> n.P2;
  cout << "Ketekunan & Praktik (0-5): "; cin >> n.P3;
  cout << "Komunikasi (0-5): "; cin >> n.P4;
  cout << "Nilai Akademik (0-5): "; cin >> n.P5;
  cout << "Religiusitas / Nilai Keagamaan (0-5): "; cin >> n.P6;
  cout << "Adaptasi Sosial (0-5): "; cin >> n.P7;

  // aspek penilaian
  int aspek[7] = {n.P1, n.P2, n.P3, n.P4, n.P5, n.P6, n.P7};

  for (int i = 0; i < 7; i++) {
    n.skorSMA         += aspek[i] * relevansi[0][i];
    n.skorSMK         += aspek[i] * relevansi[1][i];
    n.skorMA          += aspek[i] * relevansi[2][i];
    n.skorPesantren   += aspek[i] * relevansi[3][i];
    n.skorInternasional += aspek[i] * relevansi[4][i];
  }

  daftarNilai.push_back(n);
}

void tampilkanRekomendasi() {
  cout << "\n[Rekomendasi Sekolah Tiap Peserta]\n";
  if (daftarNilai.empty()) {
    cout << "Belum ada data nilai.\n";
    return;
  }

  int no = 1;
  for (const Nilai& n : daftarNilai) {
    // cari data peserta (nama & nisn)
    Peserta peserta;
    bool ditemukan = false;

    for (const Peserta& p : daftarPeserta) {
      if (p.idPeserta == n.idPeserta) {
        peserta = p;
        ditemukan = true;
        break;
      }
    }
    if (!ditemukan) continue;

    float maxSkor = n.skorSMA;
    string sekolahTerbaik = "SMA";

    if (n.skorSMK > maxSkor) { maxSkor = n.skorSMK; sekolahTerbaik = "SMK"; }
    if (n.skorMA > maxSkor) { maxSkor = n.skorMA; sekolahTerbaik = "MA"; }
    if (n.skorPesantren > maxSkor) { maxSkor = n.skorPesantren; sekolahTerbaik = "Pesantren"; }
    if (n.skorInternasional > maxSkor) { maxSkor = n.skorInternasional; sekolahTerbaik = "Internasional"; }

    cout << no++ << ". NISN: " << peserta.nisn
          << ", Nama: " << peserta.nama 
          << ", Sekolah Terbaik: " << sekolahTerbaik << endl;
  }
}

void menu() {
  cout << "\n=== Sistem Rekomendasi Sekolah ===\n";
  cout << "1. Tambah Peserta\n";
  cout << "2. Tampilkan Peserta\n";
  cout << "3. Cari Peserta\n";
  cout << "4. Update Peserta & Nilai\n";
  cout << "5. Hapus Peserta & Nilai\n";
  cout << "6. Input Nilai Peserta\n";
  cout << "7. Hasil Rekomendasi\n";
  cout << "0. Keluar\n";
}

int main() {
  int pilihan;
  do {
    menu();
    cout << "Pilih: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1: tambahPeserta(); break;
      case 2: listPeserta(); break;
      case 3: cariPeserta(); break;
      case 4: updatePeserta(); break;
      case 5: hapusPeserta(); break;
      case 6: tambahNilai(); break;
      case 7: tampilkanRekomendasi(); break;
      default: 
        if (pilihan != 0) {
          cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }
  } while (pilihan != 0);

  return 0;
}
