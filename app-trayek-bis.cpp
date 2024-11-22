#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Trayek
{
    int id;
    string namaTrayek;
    string asal;
    string tujuan;
};

class ManajemenTrayek
{
private:
    vector<Trayek> daftarTrayek;
    int nextId = 1;

public:
    void tambahTrayek()
    {
        Trayek trayek;
        trayek.id = nextId++;
        cout << "Masukkan nama trayek: ";
        cin.ignore();
        getline(cin, trayek.namaTrayek);
        cout << "Masukkan kota asal: ";
        getline(cin, trayek.asal);
        cout << "Masukkan kota tujuan: ";
        getline(cin, trayek.tujuan);

        daftarTrayek.push_back(trayek);
        cout << "Trayek berhasil ditambahkan!\n\n";
    }

    void tampilkanTrayek()
    {
        if (daftarTrayek.empty())
        {
            cout << "Tidak ada trayek yang tersedia.\n\n";
            return;
        }

        cout << "Daftar Trayek:\n";
        for (const auto &trayek : daftarTrayek)
        {
            cout << "ID: " << trayek.id
                 << " | Nama Trayek: " << trayek.namaTrayek
                 << " | Asal: " << trayek.asal
                 << " | Tujuan: " << trayek.tujuan << "\n";
        }
        cout << "\n";
    }

    void hapusTrayek()
    {
        if (daftarTrayek.empty())
        {
            cout << "Tidak ada trayek yang tersedia untuk dihapus.\n\n";
            return;
        }

        int id;
        cout << "Masukkan ID trayek yang ingin dihapus: ";
        cin >> id;

        for (auto it = daftarTrayek.begin(); it != daftarTrayek.end(); ++it)
        {
            if (it->id == id)
            {
                daftarTrayek.erase(it);
                cout << "Trayek berhasil dihapus.\n\n";
                return;
            }
        }
        cout << "Trayek dengan ID " << id << " tidak ditemukan.\n\n";
    }
};

int main()
{
    ManajemenTrayek manajemen;
    int pilihan;

    do
    {
        cout << "=== Aplikasi Manajemen Trayek Bis ===\n";
        cout << "1. Tambah Trayek\n";
        cout << "2. Tampilkan Trayek\n";
        cout << "3. Hapus Trayek\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            manajemen.tambahTrayek();
            break;
        case 2:
            manajemen.tampilkanTrayek();
            break;
        case 3:
            manajemen.hapusTrayek();
            break;
        case 4:
            cout << "Terima kasih telah menggunakan aplikasi ini.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Coba lagi.\n\n";
        }
    } while (pilihan != 4);

    return 0;
}
