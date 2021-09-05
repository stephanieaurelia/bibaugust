#include "main.h"

void hapus_buku(int n, char *filename)
{
    FILE *fp = fopen(filename, "r");
    FILE *tmpfile = fopen("tmp", "w");
    int i = 0;
    char buffer[512];

    while (fscanf(fp, "%[^\n]\n", buffer) != EOF)
    {
        if (i != n)
        {
            fprintf(tmpfile, "%s\n", buffer);
        }
        i++;
    }
struct bukuTambahan{
    char judul[1000];
    int tahunTerbit;
    char penulis[500];
    int jumlahHalaman;
    double beratBuku;
    float ratingBuku;
    long long int ISBN;
    char availability[10];
};
    
void tambahBuku (){
    struct bukuTambahan buku;

    scanf("%[^\n]", buku.judul);
    getchar();
    scanf("%d", &buku.tahunTerbit);
    getchar();
    scanf("%[^\n]", &buku.penulis);
    getchar();
    scanf("%d", &buku.jumlahHalaman);
    getchar();
    scanf("%lf", &buku.beratBuku);
    getchar();
	scanf("%f", &buku.ratingBuku);
    getchar();
    scanf("%lld", &buku.ISBN);
    getchar();
    scanf("%s", buku.availability);
    getchar();

    FILE *fAppend = fopen("database.txt", "a");         // menambahkan input user ke dalam database.txt
    fprintf(fAppend, "%s#%d#%s#%d#%lf#%f#%lld#%s\n", buku.judul, buku.tahunTerbit, buku.penulis,
            buku.jumlahHalaman, buku.beratBuku, buku.ratingBuku, buku.ISBN,
            &buku.availability);
    fclose(fAppend);
}

    fclose(fp);
    fclose(tmpfile);

    fp = fopen(filename, "w");
    tmpfile = fopen("tmp", "r");

    while (fscanf(tmpfile, "%[^\n]\n", buffer) != EOF)
    {
        fprintf(fp, "%s\n", buffer);
    }

    fclose(fp);
    fclose(tmpfile);
}
