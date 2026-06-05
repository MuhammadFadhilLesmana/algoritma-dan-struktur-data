#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void urutkanArray(int arr[], int ukuran) {
    for (int i = 1; i < ukuran; i++) {
        int kunci = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > kunci) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = kunci;
    }
}

int cariDanHitung(int arr[], int batasKiri, int batasKanan, int target) {
    int jumlahKetemu = 0;
    int indeksDitemukan = -1;

    int low = batasKiri;
    int high = batasKanan;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            indeksDitemukan = mid;
            break; 
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (indeksDitemukan != -1) {
        jumlahKetemu++; 

        int cekKiri = indeksDitemukan - 1;
        while (cekKiri >= batasKiri && arr[cekKiri] == target) {
            jumlahKetemu++;
            cekKiri--;
        }

        int cekKanan = indeksDitemukan + 1;
        while (cekKanan <= batasKanan && arr[cekKanan] == target) {
            jumlahKetemu++;
            cekKanan++;
        }
    }

    return jumlahKetemu;
}

int main() {
    int nElemen, nilaiX;

    cout << "Masukkan N (jumlah elemen) dan X (target penjumlahan): ";
    if (!(cin >> nElemen >> nilaiX)) return 0;

    if (nElemen < 10) {
        cout << "Peringatan: Sesuai instruksi, N harus >= 10.\n";
        return 0;
    }

    int* deretAngka = new int[nElemen];

    srand(time(0));

    cout << "\n--- ARRAY ACAK (RENTANG 1-25) ---\n";
    cout << "Kondisi Awal  : ";
    for (int i = 0; i < nElemen; i++) {
        deretAngka[i] = (rand() % 25) + 1;
        cout << deretAngka[i] << " ";
    }
    cout << "\n";

    urutkanArray(deretAngka, nElemen);

    cout << "Setelah Sort  : ";
    for (int i = 0; i < nElemen; i++) {
        cout << deretAngka[i] << " ";
    }
    cout << "\n---------------------------------\n\n";

    int totalPasangan = 0;

    for (int i = 0; i < nElemen - 1; i++) {
        int angkaPelengkap = nilaiX - deretAngka[i];
        
        totalPasangan += cariDanHitung(deretAngka, i + 1, nElemen - 1, angkaPelengkap);
    }

    cout << "Output Akhir: \n";
    cout << totalPasangan << "\n";
    cout << "(Total ada " << totalPasangan << " pasang elemen yang jika ditambahkan menjadi " << nilaiX << ")\n";

    delete[] deretAngka;
    return 0;
}