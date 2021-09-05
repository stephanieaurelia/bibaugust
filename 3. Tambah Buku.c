#include<stdio.h>
#include<string.h>

struct bukuTambahan;
void input3(int userInput);
void tambahBuku ();


int main(){
	int userInput;
	scanf("%d", &userInput);
	getchar();
	input3(userInput);        // memanggil fungsi input3 untuk memberikan format input kepada user
	tambahBuku();             // memanggil fungsi untuk menamabhkan
	puts("Buku Anda sudah ditambahkan ke dalam database kami!");
	return 0;
}


// struct untuk buku yang akan ditambahkan
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
/*
    jika user meng-input 3, maka console akan memberikan format seperti apa
    yang digunakan saat user melakukan input
*/
void input3(int userInput)
    {
	if (userInput==3){
		puts("Masukkan data buku yang ingin Anda tambahkan ke dalam database!");
		puts("Dengan format:");
		puts("Judul Buku");
		puts("Tahun Terbit");
		puts("Nama Penulis");
		puts("Jumlah Halaman");
		puts("Berat Buku");
		puts("Rating Buku");
		puts("ISBN");
		puts("Dipinjam(True)/Tidak Dipinjam(False)");
	}
}
/*
    setelah user medapatkan format input seperti apa,
    program akan menerima input dari user, dan menambahkan input user
    kedalam database.txt
*/
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
