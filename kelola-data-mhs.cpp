#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    string jurusan;
};

void tambahMahasiswa(vector<Mahasiswa> &daftar)
{
    Mahasiswa mhs;
    cout << "Masukkan Nama Mahasiswa: ";
    getline(cin >> ws, mhs.nama);
    cout << "Masukkan NIM Mahasiswa: ";
    getline(cin, mhs.nim);
    cout << "Masukkan Jurusan Mahasiswa: ";
    getline(cin, mhs.jurusan);
    daftar.push_back(mhs);
    cout << "Mahasiswa berhasil ditambahkan!\n";
}

void tampilkanMahasiswa(const vector<Mahasiswa> &daftar)
{
    if (daftar.empty())
    {
        cout << "Tidak ada data mahasiswa.\n";
        return;
    }
    cout << "\nDaftar Mahasiswa:\n";
    for (size_t i = 0; i < daftar.size(); ++i)
    {
        cout << i + 1 << ". Nama: " << daftar[i].nama
             << ", NIM: " << daftar[i].nim
             << ", Jurusan: " << daftar[i].jurusan << endl;
    }
}

void hapusMahasiswa(vector<Mahasiswa> &daftar)
{
    if (daftar.empty())
    {
        cout << "Tidak ada data mahasiswa untuk dihapus.\n";
        return;
    }
    tampilkanMahasiswa(daftar);
    int index;
    cout << "Masukkan nomor mahasiswa yang akan dihapus: ";
    cin >> index;

    if (index < 1 || index > daftar.size())
    {
        cout << "Nomor tidak valid.\n";
    }
    else
    {
        daftar.erase(daftar.begin() + (index - 1));
        cout << "Data mahasiswa berhasil dihapus.\n";
    }
}

int main()
{
    vector<Mahasiswa> daftarMahasiswa;
    int pilihan;

    do
    {
        cout << "\n=== Aplikasi Pengelolaan Data Mahasiswa ===\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tampilkan Mahasiswa\n";
        cout << "3. Hapus Mahasiswa\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahMahasiswa(daftarMahasiswa);
            break;
        case 2:
            tampilkanMahasiswa(daftarMahasiswa);
            break;
        case 3:
            hapusMahasiswa(daftarMahasiswa);
            break;
        case 4:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}