#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Employee
{
    int id;
    string name;
    string position;
};

struct Attendance
{
    int employeeId;
    string date;
    string status;
};

vector<Employee> employees;
vector<Attendance> attendances;

void addEmployee()
{
    Employee employee;
    cout << "Masukkan ID Karyawan: ";
    cin >> employee.id;
    cin.ignore();
    cout << "Masukkan Nama Karyawan: ";
    getline(cin, employee.name);
    cout << "Masukkan Posisi Karyawan: ";
    getline(cin, employee.position);

    employees.push_back(employee);
    cout << "Karyawan berhasil ditambahkan.\n";
}

void recordAttendance()
{
    int employeeId;
    string date, status;

    cout << "Masukkan ID Karyawan: ";
    cin >> employeeId;
    cin.ignore();
    cout << "Masukkan Tanggal (DD-MM-YYYY): ";
    getline(cin, date);
    cout << "Masukkan Status (Hadir/Izin/Sakit): ";
    getline(cin, status);

    bool found = false;
    for (const auto &employee : employees)
    {
        if (employee.id == employeeId)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        Attendance attendance{employeeId, date, status};
        attendances.push_back(attendance);
        cout << "Absensi berhasil dicatat.\n";
    }
    else
    {
        cout << "ID Karyawan tidak ditemukan.\n";
    }
}

void viewAttendance()
{
    cout << left << setw(10) << "ID" << setw(20) << "Nama"
         << setw(15) << "Tanggal" << setw(10) << "Status" << endl;
    cout << string(55, '-') << endl;

    for (const auto &attendance : attendances)
    {
        for (const auto &employee : employees)
        {
            if (employee.id == attendance.employeeId)
            {
                cout << left << setw(10) << employee.id
                     << setw(20) << employee.name
                     << setw(15) << attendance.date
                     << setw(10) << attendance.status << endl;
            }
        }
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n=== Aplikasi Absensi Karyawan ===\n";
        cout << "1. Tambah Karyawan\n";
        cout << "2. Catat Kehadiran\n";
        cout << "3. Lihat Data Kehadiran\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            recordAttendance();
            break;
        case 3:
            viewAttendance();
            break;
        case 4:
            cout << "Terima kasih telah menggunakan aplikasi ini.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 4);

    return 0;
}
