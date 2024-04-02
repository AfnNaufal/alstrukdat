#include <stdio.h>

// Fungsi untuk menghitung jumlah maksimum elemen yang dapat diambil dari kedua tumpukan
int twoStacks(int maxSum, int a[], int n, int b[], int m) {
    int sum = 0, count = 0, temp = 0, i = 0, j = 0;

    // Iterasi pertama pada tumpukan A untuk menentukan berapa banyak elemen yang dapat diambil tanpa melebihi maxSum
    while (i < n && sum + a[i] <= maxSum) { 
        sum += a[i++]; // Tambahkan elemen ke sum dan naikkan indeks i
    }
    count = i; // Set count sebagai jumlah elemen yang sudah diambil dari tumpukan A

    // Iterasi kedua pada tumpukan B
    while (j < m && i >= 0) { 
        sum += b[j++]; // Tambahkan elemen tumpukan B ke sum dan naikkan indeks j
        // Ketika sum melebihi maxSum, kurangi elemen dari tumpukan A sampai sum tidak melebihi maxSum
        while (sum > maxSum && i > 0) {
            sum -= a[--i];
        }
        // Jika sum masih tidak melebihi maxSum dan jumlah total elemen yang diambil dari kedua tumpukan lebih besar dari count,
        // update count dengan jumlah total elemen tersebut
        if (sum <= maxSum && i + j > count) {
            count = i + j;
        }
    }
    return count; // Kembalikan jumlah maksimum elemen yang dapat diambil dari kedua tumpukan
}

int main() {
    int g;
    scanf("%d", &g); // Input jumlah kasus uji
    while (g--) {
        int n, m, maxSum;
        scanf("%d%d%d", &n, &m, &maxSum); // Input ukuran tumpukan A, tumpukan B, dan maxSum
        int a[n], b[m];
        // Input elemen-elemen tumpukan A
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        // Input elemen-elemen tumpukan B
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        // Panggil fungsi twoStacks untuk menghitung jumlah maksimum elemen yang dapat diambil dari kedua tumpukan
        printf("%d\n", twoStacks(maxSum, a, n, b, m));
    }
    return 0;
}
