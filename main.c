#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int line_count(char *db);
void load_database(int n, char *db, buku daftar_buku[n]);
void load_history(int n, char *db, riwayat daftar_riwayat[n]);
int binary_search(buku arr[], char *keyword, int start, int end);
void merge(int arr[], int left, int mid, int right);
void split(int arr[], int left, int right);
void sort(int arr[], int n);

typedef struct buku
{
    char nama[32];
    int tahun_terbit;
    char penulis[32];
    int jumlah_halaman;
    double berat_buku;
    float rating;
    bool dipinjam;
} buku;

typedef struct riwayat
{
    char tanggal[32];
    char nama_buku[32];
    char nama_peminjam[32];
} riwayat;

int main(void)
{
    int jumlah_buku = line_count("db.txt");
    buku daftar_buku[jumlah_buku];
    load_database(jumlah_buku, "db.txt", daftar_buku);

    int jumlah_riwayat = line_count("history.txt");
    riwayat daftar_riwayat[jumlah_riwayat];
    load_history(jumlah_riwayat, "history.txt", daftar_riwayat);

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
        printf("Masukan angka dari menu: ");
        scanf("%i", &input);

        switch(input)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }
    }
    while (input != 7);
}

int line_count(char *db)
{
    FILE *fp = fopen(db, "r");
    int c = 0;
    char a;
    while ((a = fgetc(fp)) != EOF)
    {
        if (a == '\n')
        {
            c++;
        }
    }
    fclose(fp);
    return c;
}

void load_database(int n, char *db, buku daftar_buku[n])
{
    FILE *fp = fopen(db, "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%[^#]#%i#%[^#]#%i#%lf#%f#%i\n", &daftar_buku[i].nama, &daftar_buku[i].tahun_terbit,
               &daftar_buku[i].penulis, &daftar_buku[i].jumlah_halaman, &daftar_buku[i].berat_buku,
               &daftar_buku[i].rating, &daftar_buku[i].dipinjam);
    }
    fclose(fp);
}

void load_history(int n, char *db, riwayat daftar_riwayat[n])
{
    FILE *fp = fopen(db, "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%[^#]#%[^#]#%[^#]\n", &daftar_riwayat[i].tanggal, &daftar_riwayat[i].nama_buku, &daftar_riwayat[i].nama_peminjam);
    }
    fclose(fp);
}

int binary_search(buku arr[], char *keyword, int start, int end)
{
    int l = end - start + 1;
    int idx = (l % 2) ? (start + l / 2) : (start + l / 2) - 1;
    for (int i = start; i <= idx; i++)
    {
        if (strcmp(arr[i].nama, keyword) == 0)
        {
            return i;
        }
    }
    if (start == end)
    {
        return -1;
    }
    binary_search(arr, keyword, idx + 1, end);
}

void merge(int arr[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArr[leftSize];
    int rightArr[rightSize];

    for(int i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[i + left];
    }
    for(int i = 0; i < rightSize; i++)
    {
        rightArr[i] = arr[i + mid + 1];
    }

    int idx = left;
    int idxL = 0;
    int idxR = 0;

    while(idxL < leftSize && idxR < rightSize)
    {
        if(leftArr[idxL] < rightArr[idxR])
        {
            arr[idx] = leftArr[idxL];
            idx++;
            idxL++;
        }
        else
        {
            arr[idx] = rightArr[idxR];
            idx++;
            idxR++;
        }
    }

    while(idxL < leftSize)
    {
        arr[idx] = leftArr[idxL];
        idx++;
        idxL++;
    }

    while(idxR < rightSize)
    {
        arr[idx] = rightArr[idxR];
        idx++;
        idxR++;
    }

}

void split(int arr[], int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    split(arr, left, mid);
    split(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void sort(int arr[], int n)
{
    split(arr, 0, n - 1);
}
