#include "main.h"

int main(void)
{
    int jumlahBuku = hitungBaris("db.txt");
    Buku *daftarBuku = malloc(jumlahBuku * sizeof(Buku));

    if (daftarBuku == NULL)
    {
        fprintf(stderr, "Telah terjadi kesalahan!");
    }

    loadDatabase("db.txt", daftarBuku, jumlahBuku);

    int jumlahRiwayat = hitungBaris("history.txt");
    Riwayat *daftarRiwayat = malloc(jumlahRiwayat * sizeof(Riwayat));

    if (daftarRiwayat == NULL)
    {
        fprintf(stderr, "Telah terjadi kesalahan!");
    }

    loadRiwayat("history.txt", daftarRiwayat, jumlahRiwayat);

    int input;
    do
    {
        printf("-----------------------------------\n");
        printf("|            BIBAUGUST            |\n");
        printf("|                                 |\n");
        printf("| 1. Cari buku                    |\n");
        printf("| 2. Pinjam buku                  |\n");
        printf("| 3. Tambah buku                  |\n");
        printf("| 4. Hapus buku                   |\n");
        printf("| 5. Riwayat peminjaman           |\n");
        printf("| 6. Daftar buku                  |\n");
        printf("| 7. Exit                         |\n");
        printf("-----------------------------------\n");
        printf("Masukkan angka dari menu: ");
        scanf("%i", &input);
        getchar();

        switch(input)
        {
            case 1:
                cariBuku(&daftarBuku, jumlahBuku);
                break;
            case 2:
                break;
            case 3:
                tambahBuku(&daftarBuku, &jumlahBuku);
                break;
            case 4:
                hapusBuku(&daftarBuku, &jumlahBuku);
                break;
            case 5:
                break;
            case 6:
                break;
        }
    }
    while (input != 7);

    free(daftarBuku);
    free(daftarRiwayat);
}
