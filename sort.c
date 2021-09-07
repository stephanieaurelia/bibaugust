#include "main.h"

void merge(Buku daftarBuku[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    Buku leftArr[leftSize];
    Buku rightArr[rightSize];

    for(int i = 0; i < leftSize; i++)
    {
        leftArr[i] = daftarBuku[i + left];
    }
    for(int i = 0; i < rightSize; i++)
    {
        rightArr[i] = daftarBuku[i + mid + 1];
    }

    int idx = left;
    int idxL = 0;
    int idxR = 0;

    while(idxL < leftSize && idxR < rightSize)
    {
        if(strcmp(leftArr[idxL].judul, rightArr[idxR].judul) < 0)
        {
            daftarBuku[idx] = leftArr[idxL];
            idx++;
            idxL++;
        }
        else
        {
            daftarBuku[idx] = rightArr[idxR];
            idx++;
            idxR++;
        }
    }

    while(idxL < leftSize)
    {
        daftarBuku[idx] = leftArr[idxL];
        idx++;
        idxL++;
    }

    while(idxR < rightSize)
    {
        daftarBuku[idx] = rightArr[idxR];
        idx++;
        idxR++;
    }

}

void split(Buku daftarBuku[], int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    split(daftarBuku, left, mid);
    split(daftarBuku, mid + 1, right);

    merge(daftarBuku, left, mid, right);
}

void sort(Buku *daftarBuku, int jumlahBuku)
{
    split(daftarBuku, 0, jumlahBuku - 1);
}
