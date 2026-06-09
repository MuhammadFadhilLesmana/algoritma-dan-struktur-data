#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct Node
{
    int data;
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int databaru)
{
    if (*root == NULL)
    {
        Node *baru = new Node;

        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;

        *root = baru;

        cout << "\nData berhasil ditambahkan!";
    }
    else if (databaru < (*root)->data)
    {
        tambah(&((*root)->kiri), databaru);
    }
    else if (databaru > (*root)->data)
    {
        tambah(&((*root)->kanan), databaru);
    }
    else
    {
        cout << "\nData sudah ada!";
    }
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main()
{
    int pil, data;
    Node *pohon = NULL;

    do
    {
        system("cls");

        cout << "================================\n";
        cout << "      PROGRAM BST TREE\n";
        cout << "================================\n";
        cout << "1. Tambah Data\n";
        cout << "2. PreOrder\n";
        cout << "3. InOrder\n";
        cout << "4. PostOrder\n";
        cout << "5. Exit\n";
        cout << "================================\n";
        cout << "Pilihan : ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            cout << "\nMasukkan Data : ";
            cin >> data;
            tambah(&pohon, data);
            break;

        case 2:
            cout << "\nHasil PreOrder : ";
            if (pohon != NULL)
                preOrder(pohon);
            else
                cout << "Tree masih kosong!";
            break;

        case 3:
            cout << "\nHasil InOrder  : ";
            if (pohon != NULL)
                inOrder(pohon);
            else
                cout << "Tree masih kosong!";
            break;

        case 4:
            cout << "\nHasil PostOrder: ";
            if (pohon != NULL)
                postOrder(pohon);
            else
                cout << "Tree masih kosong!";
            break;

        case 5:
            cout << "\nProgram selesai...\n";
            break;

        default:
            cout << "\nPilihan tidak tersedia!";
        }

        getch();

    } while (pil != 5);
    return 0;
}