#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

int hitung_baris(char *db);
int binary_search(buku daftar_buku[], char *keyword, int start, int end);
void load_database(int n, char *filename, buku daftar_buku[n]);
void load_history(int n, char *filename, riwayat daftar_riwayat[n]);
void merge(int arr[], int left, int mid, int right);
void split(int arr[], int left, int right);
void sort(int arr[], int n);
void hapus_buku(int n, char *filename);