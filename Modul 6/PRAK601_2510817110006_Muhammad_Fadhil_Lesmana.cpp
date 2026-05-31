#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sequentialSearch()
{
    system("cls");

    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;

    srand(time(NULL));

    cout << "Generating 100 number..." << endl;

    for(int i = 0; i < 100; i++)
    {
        data[i] = rand() % 100 + 1;
        cout << data[i] << " ";
    }

    cout << "\n\nMencari angka : " << cari << endl;

    for(int i = 0; i < 100; i++)
    {
        if(data[i] == cari)
        {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if(flag == 1)
    {
        cout << "\nData ada sebanyak " << counter << " kali" << endl;
        cout << "Pada indeks ke-" << save << endl;
    }
    else
    {
        cout << "\nData tidak ada" << endl;
    }
}

void binarySearch()
{
    system("cls");

    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukkan jumlah data : ";
    cin >> n;

    int angka[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Angka ke-" << i + 1 << " : ";
        cin >> angka[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(angka[j] > angka[j + 1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "\nData yang telah diurutkan:\n";
    for(int i = 0; i < n; i++)
    {
        cout << angka[i] << " ";
    }

    cout << "\n\nMasukkan angka yang dicari : ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;

    while(kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;

        if(key == angka[tengah])
        {
            ketemu = true;
            break;
        }
        else if(key < angka[tengah])
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = tengah + 1;
        }
    }

    if(ketemu)
    {
        cout << "\nAngka ditemukan pada indeks ke-" << tengah << endl;
    }
    else
    {
        cout << "\nAngka tidak ditemukan" << endl;
    }
}

void penjelasan() {
    system("cls");

    cout << "==============================================" << endl;
    cout << "PERBEDAAN SEQUENTIAL SEARCH & BINARY SEARCH" << endl;
    cout << "==============================================" << endl;

    cout << "\n1. Sequential Searching" << endl;
    cout << "- Mencari data satu per satu dari awal hingga akhir." << endl;
    cout << "- Tidak memerlukan data yang terurut." << endl;
    cout << "- Cocok untuk data berukuran kecil." << endl;
    cout << "- Kompleksitas waktu O(n)." << endl;

    cout << "\nKelebihan Sequential Searching:" << endl;
    cout << "- Mudah diimplementasikan." << endl;
    cout << "- Tidak perlu melakukan sorting data." << endl;

    cout << "\nKekurangan Sequential Searching:" << endl;
    cout << "- Proses pencarian lebih lambat pada data besar." << endl;
    cout << "- Harus memeriksa elemen satu per satu." << endl;

    cout << "\n----------------------------------------------" << endl;

    cout << "\n2. Binary Searching" << endl;
    cout << "- Mencari data dengan membagi data menjadi dua bagian." << endl;
    cout << "- Data harus dalam keadaan terurut." << endl;
    cout << "- Cocok untuk data berukuran besar." << endl;
    cout << "- Kompleksitas waktu O(log n)." << endl;

    cout << "\nKelebihan Binary Searching:" << endl;
    cout << "- Jauh lebih cepat dibanding Sequential Search." << endl;
    cout << "- Efisien untuk jumlah data yang besar." << endl;

    cout << "\nKekurangan Binary Searching:" << endl;
    cout << "- Data harus diurutkan terlebih dahulu." << endl;
    cout << "- Implementasi lebih kompleks." << endl;

    cout << "\n\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

int main() {
    int pilih;

    do
    {
        system("cls");

        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        switch(pilih)
        {
            case 1:
                sequentialSearch();
                break;

            case 2:
                binarySearch();
                break;

            case 3:
                penjelasan();
                break;

            case 4:
                cout << "\nProgram selesai..." << endl;
                break;

            default:
                cout << "\nPilihan tidak tersedia!" << endl;
        }

        if(pilih != 3 && pilih != 4)
        {
            cout << "\n\nTekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
        }
    } while(pilih != 4);
    return 0;
}