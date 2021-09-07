#include "main.h"

void cariBuku(Buku **daftarBuku, int jumlahBuku)
{
    for (int i = 0; i < jumlahBuku; i++)
    {
        printf("%s\n", (*daftarBuku)[i].judul);
    }
}

void hapusBuku(Buku **daftarBuku, int *jumlahBuku)
{
    int indexHapus;
    char judul[128];
    printf("Panjang buku: %i\n", *jumlahBuku);
    printf("Masukkan nama buku yang ingin dihapus: ");
    scanf("%[^\n]", judul);
    getchar();

    if ((indexHapus = binarySearch(*daftarBuku, judul, 0, *jumlahBuku)) == -1)
    {
        printf("Buku tidak ditemukan!\n");
        return;
    }

    FILE *dbFile = fopen("db.txt", "r");
    FILE *tmpFile = fopen("tmp", "w");
    int i = 0;
    char buffer[256];

    while (fscanf(dbFile, "%[^\n]\n", buffer) != EOF)
    {
        if (i == indexHapus)
        {
            i++;
            continue;
        }
        fprintf(tmpFile, "%s\n", buffer);
        i++;
    }

    fclose(dbFile);
    fclose(tmpFile);

    dbFile = fopen("db.txt", "w");
    tmpFile = fopen("tmp", "r");

    while (fscanf(tmpFile, "%[^\n]\n", buffer) != EOF)
    {
        fprintf(dbFile, "%s\n", buffer);
    }

    fclose(dbFile);
    fclose(tmpFile);

    updateDatabase("db.txt", daftarBuku, jumlahBuku);
    printf("Buku berhasil dihapus");
}

void tambahBuku(Buku **daftarBuku, int *jumlahBuku)
{
    Buku bukuTambahan;

    printf("Masukkan data buku yang ingin Anda tambahkan ke dalam database!\n");
    printf("Judul Buku: ");
    scanf("%[^\n]", bukuTambahan.judul);
    getchar();
    printf("Tahun Terbit: ");
    scanf("%d", &bukuTambahan.tahunTerbit);
    getchar();
    printf("Nama Penulis: ");
    scanf("%[^\n]", bukuTambahan.penulis);
    getchar();
    printf("Jumlah Halaman: ");
    scanf("%d", &bukuTambahan.halaman);
    getchar();
    printf("Berat Buku: ");
    scanf("%lf", &bukuTambahan.berat);
    getchar();
    printf("ISBN: ");
    scanf("%lld", &bukuTambahan.isbn);
    getchar();
    printf("Rating Buku: ");
    scanf("%f", &bukuTambahan.rating);
    getchar();
    printf("Dipinjam (Masukkan 1 = True, 0 = False): ");
    scanf("%i", &bukuTambahan.dipinjam);
    getchar();

    // menambahkan input user ke dalam db.txt
    FILE *dbFile = fopen("db.txt", "a+");
    fprintf(dbFile, "%s#%d#%s#%d#%lf#%lld#%f#%i\n", bukuTambahan.judul,
            bukuTambahan.tahunTerbit, bukuTambahan.penulis,
            bukuTambahan.halaman, bukuTambahan.berat, bukuTambahan.isbn,
            bukuTambahan.rating, bukuTambahan.dipinjam);

    fclose(dbFile);
    // update array
    updateDatabase("db.txt", daftarBuku, jumlahBuku);

    printf("Buku Anda telah ditambahkan ke database kami!\n");
}


struct History
{
	long long int tanggalPeminjaman;
	char namaBuku [100];
	char namaPeminjam[100];
}

void lihatRiwayat(){
    FILE *fp = fopen("./history.txt", "r");
    struct History hs;
    while(fscanf(fp, "%lf#%[^#]%[^#]\n",hs.tanggalPeminjaman, hs.namaBuku, hs.namaPeminjam) != EOF)
	{
		printf("Tanggal Peminjaman\n", hs.tanggalPeminjaman);
        printf("Nama Buku: %s\n", hs.namaBuku);
        printf("Nama Peminjam: %s\n", hs.namaPeminjam);
        
    }
}
