#include <stdio.h>

// Fungsi untuk memeriksa apakah posisi (x, y) valid pada papan catur 8x8
int cekValid(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8); // Mengembalikan nilai 1 jika posisi valid, 0 jika tidak
}

// Prosedur untuk menandai semua langkah yang mungkin dilakukan oleh kuda pada papan catur
void tandaiLangkahKuda(int i, int j, int ukuran, int *papanCatur) {
    // Langkah-langkah yang mungkin dilakukan oleh kuda
    int gerakanX[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int gerakanY[] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Menandai setiap langkah yang mungkin dilakukan oleh kuda
    for (int k = 0; k < 8; k++) {
        int nextX = i + gerakanX[k]; // Menghitung koordinat x langkah berikutnya
        int nextY = j + gerakanY[k]; // Menghitung koordinat y langkah berikutnya
        if (cekValid(nextX, nextY)) { // Memeriksa apakah langkah berikutnya valid
            *(papanCatur + nextX * ukuran + nextY) = 1; // Menandai langkah kuda dengan nilai 1
        }
    }
}

int main() {
    int i, j;
    printf("Masukkan posisi i dan j: ");
    scanf("%d %d", &i, &j); // Membaca input posisi i dan j

    const int ukuran = 8; // Ukuran papan catur
    int papanCatur[ukuran][ukuran]; // Array 2D untuk papan catur

    // Inisialisasi papan catur dengan nilai awal 0
    for (int x = 0; x < ukuran; x++) {
        for (int y = 0; y < ukuran; y++) {
            papanCatur[x][y] = 0;
        }
    }

    tandaiLangkahKuda(i, j, ukuran, (int *)papanCatur); // Memanggil prosedur untuk menandai langkah kuda

    // Menampilkan papan catur setelah langkah kuda ditandai
    printf("Papan catur setelah langkah kuda ditandai:\n");
    for (int x = 0; x < ukuran; x++) {
        for (int y = 0; y < ukuran; y++) {
            printf("%d ", papanCatur[x][y]); // Cetak nilai pada papan catur
        }
        printf("\n"); // Pindah ke baris baru setelah selesai mencetak satu baris papan catur
    }

    return 0; // Mengembalikan nilai 0 untuk menandakan program berjalan dengan sukses
}
