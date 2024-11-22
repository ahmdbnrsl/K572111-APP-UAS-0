#include <iostream>
using namespace std;

class Karyawan
{
public:
    int upahKerja, jamKerja, hasil, jamLembur, hasilLembur, upahLembur;
    char Golongan;
    string namaKaryawan;

    void golongan()
    {
        cout << "Masukkan nama karyawan : ";
        cin >> namaKaryawan;
        cout << "Masukkan golongan : ";
        cin >> Golongan;

        switch (Golongan)
        {
        case 'A':
            upahKerja = 4000;
            cout << "Masukkan jam kerja : ";
            cin >> jamKerja;
            hasil = jamKerja * upahKerja;
            cout << "Nama karyawan : " << namaKaryawan << endl;
            cout << "Golongan : " << Golongan << endl;
            printDetail();
            break;
        case 'B':
            upahKerja = 3000;
            cout << "Masukkan jam kerja : ";
            cin >> jamKerja;
            hasil = jamKerja * upahKerja;
            cout << "Nama karyawan : " << namaKaryawan << endl;
            cout << "Golongan : " << Golongan << endl;
            printDetail();
            break;
        case 'C':
            upahKerja = 2000;
            cout << "Masukkan jam kerja : ";
            cin >> jamKerja;
            hasil = jamKerja * upahKerja;
            cout << "Nama karyawan : " << namaKaryawan << endl;
            cout << "Golongan : " << Golongan << endl;
            printDetail();
            break;
        case 'D':
            upahKerja = 1000;
            cout << "Masukkan jam kerja : ";
            cin >> jamKerja;
            hasil = jamKerja * upahKerja;
            cout << "Nama karyawan : " << namaKaryawan << endl;
            cout << "Golongan : " << Golongan << endl;
            printDetail();
            break;
        default:
            cout << "Pilihan yang Anda masukkan tidak ada" << endl;
        }
    }

    void printDetail()
    {
        cout << "==============================" << endl;
        cout << "Nama karyawan : " << namaKaryawan << endl;
        cout << "Golongan : " << Golongan << endl;
        cout << "Jam kerja : " << jamKerja << " jam" << endl;
        cout << "Upah per jam : " << upahKerja << endl;
        cout << "Total upah (sebelum lembur): " << hasil << endl;
        cout << "==============================" << endl;
        confirmAccess();
    }

    bool confirmAccess()
    {
        upahLembur = 4000;
        char response;
        cout << "Apakah dia lembur? [Y/N] : ";
        cin >> response;

        if (response == 'Y' || response == 'y')
        {
            cout << "Masukkan jam lembur : ";
            cin >> jamLembur;
            hasilLembur = (upahLembur * jamLembur) + hasil;
            cout << "Maka total gaji Anda adalah " << hasilLembur << endl;
        }
        else
        {
            cout << "Maka total gaji Anda adalah " << hasil << endl;
        }
        return true;
    }
};

int main()
{
    Karyawan karyawan;
    karyawan.golongan();
    return 0;
}
