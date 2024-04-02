#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Deklarasi fungsi isBalanced yang mengembalikan nilai boolean
bool isBalanced(const char *s) {
    // Menghitung panjang string input
    int len = strlen(s);
    // Membuat array stack berukuran sama dengan panjang string
    char stack[len];
    // Inisialisasi top stack dengan nilai -1
    int top = -1;

    // Looping untuk setiap karakter dalam string input
    for (int i = 0; i < len; i++) {
        // Jika karakter adalah '(', '{', atau '['
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            // Push karakter tersebut ke stack
            stack[++top] = s[i];
        } 
        // Jika karakter adalah ')', '}', atau ']'
        else if (s[i] == ')' && top >= 0 && stack[top] == '(') {
            // Jika stack tidak kosong dan karakter terakhir dalam stack adalah pasangan '('
            // Pop karakter terakhir dari stack
            top--;
        } 
        else if (s[i] == '}' && top >= 0 && stack[top] == '{') {
            // Jika stack tidak kosong dan karakter terakhir dalam stack adalah pasangan '{'
            // Pop karakter terakhir dari stack
            top--;
        } 
        else if (s[i] == ']' && top >= 0 && stack[top] == '[') {
            // Jika stack tidak kosong dan karakter terakhir dalam stack adalah pasangan '['
            // Pop karakter terakhir dari stack
            top--;
        } 
        else {
            // Jika karakter tidak sesuai dengan aturan pengecekan
            // Return false (tidak seimbang)
            return false;
        }
    }

    // Jika stack kosong setelah proses pengecekan
    // Return true (seimbang)
    return top == -1;
}

// Fungsi utama
int main() {
    // Deklarasi array char untuk menyimpan input
    char str[100];

    // Meminta pengguna untuk memasukkan string
    printf("Enter a string: ");
    scanf("%s", str);

    // Memanggil fungsi isBalanced dan menampilkan hasil
    if (isBalanced(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
