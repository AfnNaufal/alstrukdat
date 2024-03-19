#include <stdio.h>// Include library untuk fungsi input-output standar
#include <string.h>// Include library untuk fungsi-fungsi pemrosesan string

// Fungsi untuk menukar nilai dua elemen dalam array
void tukar(char *a, char *b) {// Deklarasi fungsi tukar dengan parameter pointer karakter
    char temp = *a;// Variabel lokal untuk menyimpan nilai sementara dari a
    *a = *b;// Isi nilai a dengan nilai b
    *b = temp;// Isi nilai b dengan nilai sementara (nilai awal a)
}

// Fungsi untuk mencetak array
void printArray(char arr[], int size) {// Deklarasi fungsi printArray dengan parameter array karakter dan ukuran
    for (int i = 0; i < size; i++) {// Looping untuk setiap elemen dalam array
        printf("%c ", arr[i]);// Cetak nilai elemen array ke layar
    }
    printf("\n");// Cetak baris baru setelah mencetak semua elemen array
}

// Fungsi untuk mengurutkan kartu dan mengembalikan jumlah minimum pertukaran
int urutKartu(char kartu[], int size) {// Deklarasi fungsi urutKartu dengan parameter array karakter dan ukuran
    int minTukar = 0;// Inisialisasi variabel untuk jumlah minimum pertukaran

    // Loop untuk setiap elemen di array
    for (int i = 0; i < size - 1; i++) {// Looping sebanyak ukuran array dikurangi satu
        int minIndex = i;// Inisialisasi variabel untuk indeks elemen terkecil, diawali dengan i

        // Temukan indeks elemen terkecil dari sisa array
        for (int j = i + 1; j < size; j++) {// Looping untuk mencari nilai terkecil dari array yang belum diurutkan
            // Membuat urutan "1-10-J-Q-K"
            char urutan[] = "123456789JQK";// Array untuk urutan kartu yang benar
            if (strchr(urutan, kartu[j]) < strchr(urutan, kartu[minIndex])) {  // Membandingkan urutan kartu
                minIndex = j;// Perbarui indeks elemen terkecil
            }
        }

        // Jika elemen terkecil tidak di posisi saat ini, tukar mereka
        if (minIndex != i) {// Jika indeks elemen terkecil tidak sama dengan i
            tukar(&kartu[i], &kartu[minIndex]);// Panggil fungsi tukar untuk menukar elemen array
            minTukar++;// Tambahkan jumlah pertukaran
            printf("Pertukaran ke-%d: ", minTukar);  // Cetak pesan pertukaran ke layar
            printArray(kartu, size);// Cetak array setelah pertukaran
        }
    }

    return minTukar;// Kembalikan jumlah minimum pertukaran
}

int main() {
    int noKartu;// Deklarasi variabel untuk jumlah kartu

    printf("Masukkan jumlah kartu: ");// Cetak pesan ke layar untuk meminta input jumlah kartu

    scanf("%d", &noKartu);// Minta input jumlah kartu dari user

    char kartu[noKartu];// Deklarasi array kartu dengan ukuran sejumlah noKartu
    printf("Masukkan nilai kartu : ");// Cetak pesan ke layar untuk meminta input nilai kartu
    for (int i = 0; i < noKartu; i++) {// Looping untuk meminta input nilai setiap kartu
        scanf(" %c", &kartu[i]);// Input nilai kartu dari user
    }

    int minTukar = urutKartu(kartu, noKartu); // Panggil fungsi urutKartu untuk mengurutkan kartu dan dapatkan jumlah minimum pertukaran

    printf("Jumlah minimum pertukaran: %d\n", minTukar);// Cetak jumlah minimum pertukaran ke layar

    return 0;// Kembalikan nilai 0 untuk menandakan program berjalan dengan sukses
}
