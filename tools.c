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