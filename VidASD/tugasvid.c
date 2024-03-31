#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3

struct KTP {
    char nama[50];
    int usia;
};

struct KTP stack[MAX];
int top = -1;

int isStackEmpty() {
    return (top == -1);
}

int isStackFull() {
    return (top == MAX - 1);
}

void pushData(struct KTP data) {
    if (isStackFull()) {
        printf("Stack penuh, tidak bisa menambahkan data!\n");
        return;
    }
    stack[++top] = data; 
    printf("Data ke %d berhasil ditambahkan ke dalam Stack.\n", top );
}

struct KTP popData() {
    if (isStackEmpty()) {
        printf("Stack kosong, tidak bisa melakukan pop.\n");
        return (struct KTP){.nama = "", .usia = 0};
    }
    return stack[top--]; 
}

struct KTP peekData() {
    if (isStackEmpty()) {
        printf("Stack kosong!\n");
        return (struct KTP){.nama = "", .usia = 0};
    }
    return stack[top];
}

void inputData(struct KTP ktp[], int count) {
    strncpy(ktp[0].nama, "Fitra", 50);
    ktp[0].usia = 19;
    
    strncpy(ktp[1].nama, "Kevin", 50);
    ktp[1].usia = 14;

    strncpy(ktp[2].nama, "Naufal", 50);
    ktp[2].usia = 17;
}

int main() {
    struct KTP ktp[3], temp;
    
    inputData(ktp, 3);

    for (int i = 0; i < 3; i++) {
        printf("KTP %d:\n", i + 1);
        printf("Nama: %s, Usia: %d\n" , ktp[i].nama , ktp[i].usia );
    }

    printf("\033[0;31m----------------------------------------------------------------------\033[0m\n");

    for (int i = 0; i < 3; i++) {
        pushData(ktp[i]); // memasukkan value ktp ke variable data (diatas)
    }

    printf("\033[0;31m----------------------------------------------------------------------\033[0m\n");

    printf("Data yang ada di paling atas :  ");
    temp = peekData(); // melihat data teratas yang ada di dalam stack
    printf("Nama: %s, Usia: %d\n", temp.nama, temp.usia);

    printf("\033[0;31m----------------------------------------------------------------------\033[0m\n");

    while (!isStackEmpty()) {
        printf("Data yang terdapat di stack : ");
        temp = popData();
        printf("Nama: %s, Usia: %d\n", temp.nama, temp.usia);
        //mencetak value yang ada di variable temp sampai stack kosong
    }

    return 0;
}
