#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024 //pendefinisian batas maksimum text 
#define MIN_LENGTH 1945 //pendefinisian batas minimal text

// Fungsi untuk menangani kasus ketika panjang teks kurang dari panjang minimum yang ditentukan
void lessThanRequired(int *lengthOfText) {
    printf("The length of your text is less than specified, please update your text\n");
    *lengthOfText = MIN_LENGTH; // Memperbarui panjang teks menjadi panjang minimum yang diperlukan
}

// Fungsi untuk menangani kasus ketika panjang teks sama dengan panjang minimum yang ditentukan
void equalThanRequired(int *lengthOfText) {
    //ketika banyak character yang dimasukkan = 1945 character, maka akan menampilkan output dibawah
    printf("Thank you, Your text length is correct\n");
}

// Fungsi untuk menangani kasus ketika panjang teks lebih dari panjang maksimum yang ditentukan
void moreThanRequired(int *lengthOfText) {
    printf("Your text is too long, please reduce the text\n");
    *lengthOfText = MIN_LENGTH; // Memperbarui panjang teks menjadi panjang minimum yang diperlukan
}

// Fungsi untuk memeriksa persyaratan panjang teks dan mengembalikan kode yang sesuai
int checkLengthRequirement(char *text) {
    int length = strlen(text); // Menghitung panjang teks
    if (length < MIN_LENGTH) // Jika panjangnya kurang dari yang dibutuhkan
        return 0;
    else if (length == MIN_LENGTH) // Jika panjangnya sama dengan yang dibutuhkan
        return 1;
    else // Jika panjangnya lebih dari yang dibutuhkan
        return 2;
}

int main() {
    int lengthOfText, selectOption; // Variabel untuk menyimpan panjang teks dan pilihan opsi
    FILE *fptr = NULL; // Variabel penunjuk file
    char text[MAX_LENGTH]; // Array untuk menyimpan teks yang dibaca dari file

    fptr = fopen("file.txt", "r"); // Membuka file dalam mode baca

    if (fptr == NULL) { // Jika gagal membuka file
        printf("Error");
        exit(1); // Keluar dari program dengan kode kesalahan
    }

    fgets(text, MAX_LENGTH, fptr); // Membaca satu baris dari file ke dalam array teks

    fclose(fptr); // Menutup file

    selectOption = checkLengthRequirement(text); // Memeriksa persyaratan panjang teks

    // Array pointer fungsi untuk menangani berbagai kasus panjang
    void (*functionArray[])(int *) = {lessThanRequired, equalThanRequired, moreThanRequired};

    lengthOfText = MIN_LENGTH; // Menginisialisasi panjang teks menjadi panjang minimum yang dibutuhkan
    functionArray[selectOption](&lengthOfText); // Memanggil fungsi yang sesuai berdasarkan kasus panjang

    printf("\nThe Length is updated to %d", lengthOfText); // Mencetak panjang teks yang diperbarui

    return 0; // Menandakan penyelesaian program yang sukses
}
