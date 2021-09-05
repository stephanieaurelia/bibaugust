#include "main.h"

int main(void)
{
    int jumlah_buku = hitung_baris("db.txt");
    buku daftar_buku[jumlah_buku];
    load_database(jumlah_buku, "db.txt", daftar_buku);

    int jumlah_riwayat = hitung_baris("history.txt");
    riwayat daftar_riwayat[jumlah_riwayat];
    load_history(jumlah_riwayat, "history.txt", daftar_riwayat);

    int input;
    int index_hapus;
    char nama_buku[32];    

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
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                printf("Masukkan nama buku yang ingin dihapus: ");
                scanf("%[^\n]", nama_buku);
                getchar();                
                if ((index_hapus = binary_search(daftar_buku, nama_buku, 0, jumlah_buku)) == -1)
                {
                    printf("Buku tidak ditemukan!\n");
                    break;
                }
                hapus_buku(index_hapus, "db.txt");
                break;
            case 5:
                break;
            case 6:
                break;
        }
    }
    while (input != 7);
}
