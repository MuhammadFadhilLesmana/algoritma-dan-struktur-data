#include <iostream>
using namespace std;

struct kendaraan
{
    string plat;
    string jenis;
    string nama;
    string alamat;
    string kota;
};

int main()
{
    kendaraan data;

    // Input
    cout << "Plat Nomor Kendaraan : ";
    getline(cin, data.plat);

    cout << "Jenis Kendaraan      : ";
    getline(cin, data.jenis);

    cout << "Nama Pemilik         : ";
    getline(cin, data.nama);

    cout << "Alamat               : ";
    getline(cin, data.alamat);

    cout << "Kota                 : ";
    getline(cin, data.kota);

    // Output
    cout << "\n--- Data Kendaraan ---\n";
    cout << "Plat Nomor Kendaraan : " << data.plat << endl;
    cout << "Jenis Kendaraan      : " << data.jenis << endl;
    cout << "Nama Pemilik         : " << data.nama << endl;
    cout << "Alamat               : " << data.alamat << endl;
    cout << "Kota                 : " << data.kota << endl;

    return 0;
}