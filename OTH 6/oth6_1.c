#include <stdio.h>
#include <stdlib.h>

// Definisikan struktur Node untuk merepresentasikan simpul dalam linked list
struct Node {
    char* alphabet; // Menyimpan karakter huruf
    struct Node* link; // Menyimpan alamat (pointer) ke simpul berikutnya
};

int main() {
    // Deklarasi node-node
    struct Node l1, l2, l3, l4, l5, l6, l7, l8, l9;
    struct Node *link, *l3ptr;

    // Inisialisasi node-node dengan menggunakan potongan kode soal
    l1.link = NULL;
    l1.alphabet = "F";

    l2.link = NULL;   // Mengatur pointer link node l2 menjadi NULL (akhir dari linked list)
    l2.alphabet = "M";  // Menyimpan huruf "M" dalam node l2

    l3.link = &l6;  // Menyambungkan node l3 ke node l6
    l3.alphabet = "A";  // Menyimpan huruf "A" dalam node l3

    l4.link = &l7;  // Menyambungkan node l4 ke node l7
    l4.alphabet = "I";  // Menyimpan huruf "I" dalam node l4

    l5.link = &l3;  // Menyambungkan node l5 ke node l3
    l5.alphabet = "K";  // Menyimpan huruf "K" dalam node l5

    l6.link = &l9;  // Menyambungkan node l6 ke node l9
    l6.alphabet = "T";  // Menyimpan huruf "T" dalam node l6

    l7.link = &l1;  // Menyambungkan node l7 ke node l1
    l7.alphabet = "N";  // Menyimpan huruf "N" dalam node l7

    l8.link = &l2;  // Menyambungkan node l8 ke node l2
    l8.alphabet = "O";  // Menyimpan huruf "O" dalam node l8

    l9.link = &l4;  // Menyambungkan node l9 ke node l4
    l9.alphabet = "R";  // Menyimpan huruf "R" dalam node l9

    // Mengatur koneksi antar node sesuai dengan urutan yang diinginkan
    l7.link = &l1;  // Menyambungkan ke l1
    l1.link = &l8;  // Menyambungkan ke l8
    l8.link = &l2;  // Menyambungkan ke l2
    l2.link = &l5;  // Menyambungkan ke l5
    l5.link = &l3;  // Menyambungkan ke l3
    l3.link = &l6;  // Menyambungkan ke l6
    l6.link = &l9;  // Menyambungkan ke l9
    l9.link = &l4;  // Menyambungkan ke l4
    l4.link = &l7;  // Menyambungkan ke l7

    // Starting point
    l3ptr = &l7;

    // Akses data menggunakan printf
    printf("%s", l3.link->link->link->alphabet); // Menampilkan huruf I
    printf("%s", l3.link->link->link->link->alphabet); // Menampilkan huruf N
    printf("%s", l3.link->link->link->link->link->alphabet); // Menampilkan huruf F
    printf("%s", l3.link->link->link->link->link->link->alphabet); // Menampilkan huruf O
    printf("%s", l3.link->link->alphabet); // Menampilkan huruf R
    printf("%s", l3.link->link->link->link->link->link->link->alphabet); // Menampilkan huruf M
    printf("%s", l3.alphabet); // Menampilkan huruf A
    printf("%s", l3.link->alphabet); // Menampilkan huruf T
    printf("%s", l3.link->link->link->alphabet); // Menampilkan huruf I 
    printf("%s", l3.link->link->link->link->link->link->link->link->alphabet); // Menampilkan huruf K
    printf("%s", l3.alphabet); // Menampilkan huruf A

    return 0;
}
