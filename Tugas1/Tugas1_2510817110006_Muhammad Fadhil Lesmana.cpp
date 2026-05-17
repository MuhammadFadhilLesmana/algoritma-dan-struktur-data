#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

typedef struct TNode{
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan[2];
string dataBaru, dataDelete;

void init();
int isEmpty();

void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main()
{
    init();

    do {
        cout<<"Single Linked List Circular (SLLC)"<<endl;
        cout<<"=================================="<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampilkan Data"<<endl;
        cout<<"6. Hapus Semua Elemen"<<endl;
        cout<<"7. Cari Data"<<endl;
        cout<<"8. Hapus Setiap Data Tertentu"<<endl;
        cout<<"9. Sisipkan Node/Data Baru Sebelum Data Tertentu"<<endl;
        cout<<"10. Sisipkan Node/Data Baru Setelah Data Tertentu"<<endl;
        cout<<"11. Quit"<<endl;
        cout<<"Pilihan : ";

        cin>>pilihan;
        pil=atoi(pilihan);

        switch(pil) {
        case 1:
            tambahDepan();
            break;
        case 2:
            tambahBelakang();
            break;
        case 3:
            hapusDepan();
            break;
        case 4:
            hapusBelakang();
            break;
        case 5:
            tampilkan();
            break;
        case 6:
            reset();
            break;
        case 7:
            cariData();
            break;
        case 8:
            hapusData();
            break;
        case 9:
            sisipkanSebelum();
            break;
        case 10:
            sisipkanSetelah();
            break;
        default:
            cout<<"\nTERIMA KASIH"<<endl;
            cout<<"Program was made by Muhammad Fadhil Lesmana (2510817110006)."<<endl;
        }

        cout<<"\nPress any key to continue!"<<endl;
        getch();
        system("cls");

    } while (pil < 11);
}

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if(head == NULL) return 1;
    else return 0;
}

void tambahDepan() {

    string input;
    cin.ignore();

    cout<<"Masukkan beberapa data (pisahkan dengan spasi) : ";
    getline(cin, input);

    stringstream ss(input);
    string data;

    string arr[100];
    int jumlah = 0;

    while(ss >> data){
        arr[jumlah++] = data;
    }
    for(int i = jumlah - 1; i >= 0; i--) {
        TNode *baru;
        baru = new TNode;

        baru->data = arr[i];

        if(isEmpty() == 1) {
            head = baru;
            tail = baru;
            baru->next = head;
        } else {
            baru->next = head;
            head = baru;
            tail->next = head;
        }
    }
    cout<<"Data berhasil ditambahkan di bagian depan."<<endl;
}

void tambahBelakang() {
    cout<<"Masukkan data : ";
    TNode *baru;
    baru = new TNode;

    cin>>dataBaru;

    baru->data = dataBaru;
    baru->next = baru;

    if(isEmpty() == 1) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }

    cout << "Data \""<<dataBaru<<"\" berhasil dimasukkan dibagian belakang."<<endl;
}

void hapusDepan() {
    if(isEmpty() == 0) {
        int n, jumlah = 0, posisi = 1;
        cout<<"Hapus node ke-N dari depan : ";
        cin>>n;

        TNode *bantu = head;

        do{
            jumlah++;
            bantu = bantu->next;
        } while(bantu != head);
        if(n > jumlah) n = jumlah;
        if(n == jumlah) {
            TNode *hapus = tail;
            dataDelete = hapus->data;

            if(head == tail) {
                init();
            } else {
                TNode *newTail = head;
                while(newTail->next != tail) {
                    newTail = newTail->next;
                }
                tail = newTail;
                tail->next = head;
            }
            delete hapus;
            cout<<"Data \""<<dataDelete<<"\" berhasil dihapus."<<endl;
            return;
        }

        TNode *hapus = head;
        TNode *sebelum = tail;

        while(posisi < n) {
            sebelum = hapus;
            hapus = hapus->next;
            posisi++;
        }

        dataDelete = hapus->data;

        if(hapus == head) {
            head = head->next;
            tail->next = head;
        } else {
            sebelum->next = hapus->next;
        }
        delete hapus;
        cout<<"Data \""<<dataDelete<<"\" berhasil dihapus."<<endl;
    } else {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void hapusBelakang(){
    if(isEmpty() == 0) {
        int n, jumlah = 0;
        cout<<"Hapus node ke-N dari belakang : ";
        cin>>n;

        TNode *bantu = head;

        do{
            jumlah++;
            bantu = bantu->next;
        } while(bantu != head);
        if(n > jumlah) n = jumlah;

        int posisiDepan = jumlah - n + 1;

        if(posisiDepan <= 0)
            posisiDepan = 1;

        TNode *hapus = head;
        TNode *sebelum = tail;

        for(int i = 1; i < posisiDepan; i++) {
            sebelum = hapus;
            hapus = hapus->next;
        }

        dataDelete = hapus->data;

        if(head == tail) {
            init();
        } else if(hapus == head) {
            head = head->next;
            tail->next = head;
        } else if(hapus == tail) {
            tail = sebelum;
            tail->next = head;
        } else {
            sebelum->next = hapus->next;
        }
        delete hapus;
        cout<<"Data \""<<dataDelete<<"\" berhasil dihapus."<<endl;
    } else {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void tampilkan() {
    if(isEmpty() == 0) {
        TNode *bantu;
        bantu = head;

        cout<<"Isi Linked List : ";

        do {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        } while(bantu != head);

        cout<<endl;

    } else {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void reset() {
    if(isEmpty() == 0) {
        int nomor = 1;
        while(head != NULL) {
            TNode *hapus = head;
            cout<<"Menghapus node ke-"<<nomor
                <<" dengan isi \""<<hapus->data<<"\""<<endl;
            if(head == tail) {
                head = NULL;
                tail = NULL;
            } else {
                head = head->next;
                tail->next = head;
            }
            delete hapus;
            nomor++;
        }
        cout<<"Seluruh elemen pada Linked List telah dibersihkan."<<endl;
    } else {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void cariData(){
    if(isEmpty() == 0) {
        string cari;

        cout<<"Masukan data yang ingin dicari : ";
        cin>>cari;

        TNode *bantu, *bantuTampilkan;
        bool apaDitemukan = false;
        bantu = head;
        do {
            if(cari == bantu->data){
                cout<<"Setiap data yang berada di dalam tanda kurung siku ([...]) merupakan data yang anda cari."<<endl;
                cout<<"Linked List : ";
                bantuTampilkan = head;
                do {
                    if(cari == bantuTampilkan->data)
                        cout<<"["<<bantuTampilkan->data<<"] ";
                    else
                        cout<<bantuTampilkan->data<<' ';
                    bantuTampilkan = bantuTampilkan->next;
                } while(bantuTampilkan != head);
                apaDitemukan = true;
                cout<<endl;
                break;
            }

            bantu = bantu->next;

        } while(bantu != head);
        if(apaDitemukan == false)
            cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
        } else {
            cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void hapusData(){
    cout<<"Fungsi tetap seperti program awal."<<endl;
}

void sisipkanSebelum() {
    cout<<"Fungsi tetap seperti program awal."<<endl;
}
void sisipkanSetelah() {
    cout<<"Fungsi tetap seperti program awal."<<endl;
}