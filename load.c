#include "main.h"

int binary_search(buku daftar_buku[], char *keyword, int start, int end)
{
    int length = end - start + 1;
    int idx = (length % 2) ? (start + length / 2) : (start + length / 2) - 1;
    for (int i = start; i <= idx; i++)
    {
        if (strcmp(daftar_buku[i].nama, keyword) == 0)
        {
            return i;
        }
    }
    if (start == end)
    {
        return -1;
    }
    binary_search(daftar_buku, keyword, idx + 1, end);
}

int hitung_baris(char *db)
{
    FILE *fp = fopen(db, "r");
    int counter = 0;
    char tmp;
    while ((tmp = fgetc(fp)) != EOF)
    {
        if (tmp == '\n')
        {
            counter++;
        }
    }
    fclose(fp);
    return counter;
}

void load_database(int n, char *filename, buku daftar_buku[n])
{
    FILE *fp = fopen(filename, "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%[^#]#%i#%[^#]#%i#%lf#%f#%i\n", &daftar_buku[i].nama, &daftar_buku[i].tahun_terbit,
               &daftar_buku[i].penulis, &daftar_buku[i].jumlah_halaman, &daftar_buku[i].berat_buku,
               &daftar_buku[i].rating, &daftar_buku[i].dipinjam);
    }
    fclose(fp);
}

void load_history(int n, char *filename, riwayat daftar_riwayat[n])
{
    FILE *fp = fopen(filename, "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%[^#]#%[^#]#%[^#]\n", &daftar_riwayat[i].tanggal, &daftar_riwayat[i].nama_buku, &daftar_riwayat[i].nama_peminjam);
    }
    fclose(fp);
}