#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

typedef struct Tnode {
    string data;
    Tnode *next;
    Tnode *prev;
};

Tnode *head, *tail;

int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

int main()
{
menu:
    cout<<"Double Linked List Non Circular (DLLNC)"<<endl;
    cout<<"======================================="<<endl;
    cout<<"1. DLLNC dengan head"<<endl;
    cout<<"2. DLLNC dengan Head dan Tail"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Pilihan : ";
    cin>>menu;
    system("cls");
    if(menu==1){

        initH();
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head)"<<endl;
            cout<<"=============================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Target"<<endl;
            cout<<"7. Clear"<<endl;
            cout<<"8. Kembali"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil){

            case 1:
                tambahDepanH();
                break;
            case 2:
                tambahBelakangH();
                break;
            case 3:
                tampilkanH();
                break;
            case 4:
                hapusDepanH();
                break;
            case 5:
                hapusBelakangH();
                break;
            case 6:
                hapusTargetH();
                break;
            case 7:
                clearH();
                break;
            default:
                system("cls");
                goto menu;
            }

            cout<<"\nPress any key...";
            getch();
            system("cls");

        } while(pil<8);
    }

    else if(menu==2){
        initHT();
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head & Tail)"<<endl;
            cout<<"======================================================"<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Target"<<endl;
            cout<<"7. Clear"<<endl;
            cout<<"8. Kembali"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil){
            case 1:
                tambahDepanHT();
                break;
            case 2:
                tambahBelakangHT();
                break;
            case 3:
                tampilkanHT();
                break;
            case 4:
                hapusDepanHT();
                break;
            case 5:
                hapusBelakangHT();
                break;
            case 6:
                hapusTargetHT();
                break;
            case 7:
                clearHT();
                break;
            default:
                system("cls");
                goto menu;
            }
            cout<<"\nPress any key...";
            getch();
            system("cls");
        } while(pil<8);
    }

    else {
        cout<<"TERIMA KASIH"<<endl;
    }
}

void initH(){
    head=NULL;
}

void initHT(){
    head=NULL;
    tail=NULL;
}

int isEmptyH(){
    return head==NULL;
}

int isEmptyHT(){
    return tail==NULL;
}

void tambahDepanH(){
    string input,x;
    vector<string> data;

    cout<<"Masukan Data : ";
    cin.ignore();
    getline(cin,input);
    stringstream ss(input);
    while(ss>>x)
        data.push_back(x);
    for(int i=data.size()-1;i>=0;i--){
        Tnode *baru=new Tnode;
        baru->data=data[i];
        baru->next=NULL;
        baru->prev=NULL;

        if(isEmptyH()){
            head=baru;
        } else {
            baru->next=head;
            head->prev=baru;
            head=baru;
        }
    }
    cout<<"Data berhasil ditambah depan";
}

void tambahDepanHT(){
    string input,x;
    vector<string> data;

    cout<<"Masukan Data : ";
    cin.ignore();
    getline(cin,input);

    stringstream ss(input);
    while(ss>>x)
        data.push_back(x);
    for(int i=data.size()-1;i>=0;i--){
        Tnode *baru=new Tnode;

        baru->data=data[i];
        baru->next=NULL;
        baru->prev=NULL;

        if(isEmptyHT()){
            head=tail=baru;
        } else {
            baru->next=head;
            head->prev=baru;
            head=baru;
        }
    }
    cout<<"Data berhasil ditambah depan";
}

void tambahBelakangH(){
    string input,x;
    vector<string> data;

    cout<<"Masukan Data : ";
    cin.ignore();
    getline(cin,input);

    stringstream ss(input);

    while(ss>>x)
        data.push_back(x);
    for(int i=0;i<data.size();i++){
        Tnode *baru=new Tnode;

        baru->data=data[i];
        baru->next=NULL;
        baru->prev=NULL;

        if(isEmptyH()){
            head=baru;
        } else {
            Tnode *bantu=head;
            while(bantu->next!=NULL)
                bantu=bantu->next;
            bantu->next=baru;
            baru->prev=bantu;
        }
    }
    cout<<"Data berhasil ditambah belakang";
}

void tambahBelakangHT(){
    string input,x;
    vector<string> data;
    cout<<"Masukan Data : ";
    cin.ignore();
    getline(cin,input);

    stringstream ss(input);

    while(ss>>x)
        data.push_back(x);
    for(int i=0;i<data.size();i++){
        Tnode *baru=new Tnode;
        baru->data=data[i];
        baru->next=NULL;
        baru->prev=NULL;

        if(isEmptyHT()){
            head=tail=baru;
        } else {
            tail->next=baru;
            baru->prev=tail;
            tail=baru;
        }
    }
    cout<<"Data berhasil ditambah belakang";
}

void tampilkanH(){
    Tnode *bantu=head;
    if(!isEmptyH()){
        while(bantu!=NULL){
            cout<<bantu->data<<" ";
            bantu=bantu->next;
        }
    } else {
        cout<<"Linked List kosong";
    }
    cout<<endl;
}

void tampilkanHT(){
    Tnode *bantu=head;
    if(!isEmptyHT()){
        while(bantu!=NULL){
            cout<<bantu->data<<" ";
            bantu=bantu->next;
        }
    } else {
        cout<<"Linked List kosong";
    }
    cout<<endl;
}

void hapusDepanH(){
    if(isEmptyH()){
        cout<<"Linked List kosong";
        return;
    }

    Tnode *hapus=head;

    cout<<"Data \""<<hapus->data<<"\" dihapus"<<endl;
    if(head->next!=NULL){
        head=head->next;
        head->prev=NULL;
    } else {
        initH();
    }
    delete hapus;
}

void hapusDepanHT(){
    if(isEmptyHT()){
        cout<<"Linked List kosong";
        return;
    }

    Tnode *hapus=head;

    cout<<"Data \""<<hapus->data<<"\" dihapus"<<endl;

    if(head->next!=NULL){
        head=head->next;
        head->prev=NULL;
    } else {
        initHT();
    }
    delete hapus;
}

void hapusBelakangH(){
    int n;
    cout<<"Jumlah node dari belakang yang dihapus : ";
    cin>>n;

    while(n--){
        if(isEmptyH())
            break;
        Tnode *hapus=head;
        while(hapus->next!=NULL)
            hapus=hapus->next;

        cout<<"Data \""<<hapus->data<<"\" dihapus"<<endl;

        if(head->next!=NULL){
            hapus->prev->next=NULL;
        } else {
            initH();
        }
        delete hapus;
    }
}

void hapusBelakangHT(){
    int n;
    cout<<"Jumlah node dari belakang yang dihapus : ";
    cin>>n;

    while(n--){
        if(isEmptyHT())
            break;
        Tnode *hapus=tail;
        cout<<"Data \""<<hapus->data<<"\" dihapus"<<endl;
        if(head->next!=NULL){
            tail=tail->prev;
            tail->next=NULL;
        } else {
            initHT();
        }
        delete hapus;
    }
}

void hapusTargetH(){
    string target;
    cout<<"Masukan target : ";
    cin>>target;

    Tnode *bantu=head;
    int ketemu=0;

    while(bantu!=NULL){
        if(bantu->data==target){
            ketemu++;
            if(bantu==head){
                head=head->next;
                if(head!=NULL)
                    head->prev=NULL;
            } else {
                bantu->prev->next=bantu->next;
                if(bantu->next!=NULL)
                    bantu->next->prev=bantu->prev;
            }

            Tnode *hapus=bantu;
            bantu=bantu->next;

            delete hapus;

        } else {
            bantu=bantu->next;
        }
    }

    if(ketemu)
        cout<<"Semua data ditemukan dan dihapus";
    else
        cout<<"Data tidak ditemukan";
}

void hapusTargetHT(){
    string target;

    cout<<"Masukan target : ";
    cin>>target;

    Tnode *bantu=head;
    int ketemu=0;

    while(bantu!=NULL){
        if(bantu->data==target){
            ketemu++;
            if(bantu==head && bantu==tail){
                initHT();
            } else if(bantu==head){
                head=head->next;
                head->prev=NULL;
            } else if(bantu==tail){
                tail=tail->prev;
                tail->next=NULL;
            } else {
                bantu->prev->next=bantu->next;
                bantu->next->prev=bantu->prev;
            }

            Tnode *hapus=bantu;
            bantu=bantu->next;

            delete hapus;
        } else {
            bantu=bantu->next;
        }
    }

    if(ketemu)
        cout<<"Semua data ditemukan dan dihapus";
    else
        cout<<"Data tidak ditemukan";
}

void clearH(){
    int urut=1;
    while(head!=NULL){
        if(urut%2==1){
            cout<<urut<<". Hapus depan : "<<head->data<<endl;
            hapusDepanH();
        } else {
            Tnode *bantu=head;
            while(bantu->next!=NULL)
                bantu=bantu->next;
            cout<<urut<<". Hapus belakang : "<<bantu->data<<endl;
            int n=1;
            while(n--)
                hapusBelakangH();
        }
        urut++;
    }
    cout<<"Linked List kosong";
}

void clearHT(){
    int urut=1;
    while(head!=NULL){
        if(urut%2==1){
            cout<<urut<<". Hapus depan : "<<head->data<<endl;
            hapusDepanHT();
        } else {
            cout<<urut<<". Hapus belakang : "<<tail->data<<endl;
            int n=1;
            while(n--)
                hapusBelakangHT();
        }
        urut++;
    }
    cout<<"Linked List kosong";
}