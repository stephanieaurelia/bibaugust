#include "main.h"

int hitungBaris(char *filename)
{
    FILE *dbFile = fopen(filename, "r");
    int counter = 0;
    char tmp;

    while ((tmp = fgetc(dbFile)) != EOF)
    {
        if (tmp == '\n')
        {
            counter++;
        }
    }

    fclose(dbFile);
    return counter;
}

int binarySearch(Buku *daftarBuku, char *keyword, int start, int end)
{
    int length = end - start + 1;
    int idx = (length % 2) ? (start + length / 2) : (start + length / 2) - 1;

    for (int i = start; i <= idx; i++)
    {
        if (strcmp(daftarBuku[i].judul, keyword) == 0)
        {
            return i;
        }
    }

    if (start == end)
    {
        return -1;
    }

    binarySearch(daftarBuku, keyword, idx + 1, end);
}

void loadDatabase(char *filename, Buku *daftarBuku, int n)
{
    FILE *dbFile = fopen(filename, "r");

    for (int i = 0; i < n; i++)
    {
        fscanf(dbFile, "%[^#]#%i#%[^#]#%i#%lf#%lld#%f#%i\n", daftarBuku[i].judul,
                &daftarBuku[i].tahunTerbit, daftarBuku[i].penulis,
                &daftarBuku[i].halaman, &daftarBuku[i].berat,
                &daftarBuku[i].isbn, &daftarBuku[i].rating,
                &daftarBuku[i].dipinjam);
    }

    fclose(dbFile);
}

void loadRiwayat(char *filename, Riwayat *daftarRiwayat, int n)
{
    FILE *histFile = fopen(filename, "r");

    for (int i = 0; i < n; i++)
    {
        fscanf(histFile, "%[^#]#%[^#]#%[^#]\n", daftarRiwayat[i].tanggal,
                daftarRiwayat[i].judul,
                daftarRiwayat[i].peminjam);
    }

    fclose(histFile);
}

void updateDatabase(char *filename, Buku **daftarBuku, int *jumlahBuku)
{
    int jumlahTmp = hitungBaris(filename);
    *jumlahBuku = jumlahTmp;

    Buku *daftarTmp = realloc(*daftarBuku, jumlahTmp * sizeof(Buku));
    Buku tmp;

    if (daftarTmp == NULL)
    {
        printf("Terjadi kesalahan!");
        return;
    }

    FILE *dbFile = fopen(filename, "r");

    for (int i = 0; i < jumlahTmp; i++)
    {
        fscanf(dbFile, "%[^#]#%i#%[^#]#%i#%lf#%lld#%f#%i\n", tmp.judul,
                &tmp.tahunTerbit, tmp.penulis,
                &tmp.halaman, &tmp.berat,
                &tmp.isbn, &tmp.rating, &tmp.dipinjam);
    }

    fclose(dbFile);

    daftarTmp[jumlahTmp - 1] = tmp;
    *daftarBuku = daftarTmp;
}

void updateRiwayat(char *filename, Riwayat **daftarRiwayat, int *jumlahRiwayat)
{
    int jumlahTmp = hitungBaris(filename);
    *jumlahRiwayat = jumlahTmp;

    Riwayat *daftarTmp = realloc(*daftarRiwayat, jumlahTmp * sizeof(Riwayat));
    Riwayat tmp;

    if (daftarTmp == NULL)
    {
        printf("Terjadi kesalahan!");
        return;
    }

    FILE *histFile = fopen(filename, "r");

    for (int i = 0; i < jumlahTmp; i++)
    {
        fscanf(histFile, "%[^#]#%[^#]#%[^#]\n", tmp.tanggal,
                tmp.judul, tmp.peminjam);
    }

    fclose(histFile);

    daftarTmp[jumlahTmp - 1] = tmp;
    *daftarRiwayat = daftarTmp;
}