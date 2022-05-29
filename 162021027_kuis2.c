/*
Nama / NRP : Ramdhan / Mahfuzh
Tanggal  : 27-05-2022
Program  : menyimpan data barang
*/
#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include <string.h>
#include <conio.h>

void buat();
void input();
void tampil();
void update();

int n,offset;
 char cari2[30];
char cari[40],nm[20];
FILE *data;

struct
 {
     char id[4];
     char namabarang[40];
     char jenis[30];
     char koderak[3];
     int stok;
 }brg[100];
          
int main()
{
    int p;
    do {
    
    menu :
    printf("====================\n");
    printf("menu kelola barang\n");
    printf("====================\n");
    printf("1. Buat File \n");
    printf("2. Tambahkan barang  \n");
    printf("3. Tampilkan barang\n");
    printf("4. Update Barang \n");
    printf("5. keluar\n");
    printf("masukan pilihan mu : ");
    scanf("%d",&p);
    switch (p)
    {
    case 1 :
        buat();
        break;
    case 2 :
        input();
        break;
    case 3 :
        tampil();
        break;
    case 4 :
    update();
    break;
     
     case 5 :
     system("cls");
     break;

    default:
        break;
    }
    } 
    while (p != 5);
          
return 0;
}


void buat()
{
system("cls");
        printf("masukan nama file (akhiri dengan .txt) : ");
        scanf("%s",&nm);
        if((data = fopen(nm,"wb"))==NULL)
        {
            puts("File tidak dapat dibuat");
        }
        printf("\ndata berhasil dibuat :)\n");
        printf("tekan tombol apapun");
        getch();
        system("cls");
        fclose(data);
}
void input()
{
    system("cls");
    data = fopen(nm,"a");
    printf("masukan banyaknya barang : ");
    scanf("%d",&n);
    brg[n];
    for(int i = 0; i < n; i++)
    {
    printf("masukan ID barang : ");
    scanf("%s",&brg[i].id);
    printf("masukan Nama barang : ");
    scanf("%s",&brg[i].namabarang);
    printf("masukan Jenis barang : ");
    scanf("%s",&brg[i].jenis);
    printf("masukan kode rak barang : ");
    scanf("%s",&brg[i].koderak);
    printf("masukan stok barang : ");
    scanf("%d",&brg[i].stok);
    printf("\n");
    }
    fprintf(data,"================================\n");
    fprintf(data,"           Informasi Barang     \n");
    fprintf(data,"================================\n");
    for(int i = 0; i < n; i++)
    {
    fprintf(data,"ID        :  %s \n",brg[i].id);
    fprintf(data,"NAMA      :  %s \n",brg[i].namabarang);
    fprintf(data,"JENIS     :  %s \n",brg[i].jenis);
    fprintf(data,"KODE RAK  :  %s \n",brg[i].koderak);
    fprintf(data,"STOK      :  %d \n",brg[i].stok);
    fprintf(data,"================================\n");
    }
    printf("data berhasil diinputkan :) \n");
    printf("tekan tombol apapun ");
    getch();
    fclose(data);
    system ("cls");
}
void tampil()
{
    system("cls");
    int p2;
    fread(&brg, sizeof(brg),1,data);
    data = fopen(nm, "rb");

    printf("================================\n");
    printf("           Informasi Barang     \n");
    printf("================================\n");
    for(int i = 0; i < n; i++){
    printf("ID        :  %s \n",brg[i].id);
    printf("NAMA      :  %s \n",brg[i].namabarang);
    printf("JENIS     :  %s \n",brg[i].jenis);
    printf("KODE RAK  :  %s \n",brg[i].koderak);
    printf("STOK      :  %d \n",brg[i].stok);
    printf("================================\n");
    }
    printf("cari barang berdasarkan : \n");
    printf("1. Nama\n");
    printf("2. Id\n");
    printf("3. lanjut\n");
    printf("pilih : ");
    scanf("%d",&p2);
    switch(p2)
    {
        case 1:
        
        printf("masukan pencarian nama = ");
        scanf("%s",cari);
        for (int i = 0; i < n; i++)
        {
            if((strstr(brg[i].namabarang,cari)!=0))
            {
        printf("================================\n");
        printf("ID        :  %s \n",brg[i].id);
        printf("NAMA      :  %s \n",brg[i].namabarang);
        printf("JENIS     :  %s \n",brg[i].jenis);
        printf("KODE RAK  :  %s \n",brg[i].koderak);
        printf("STOK      :  %d \n",brg[i].stok);
        printf("================================\n");
            }
        }
        printf("tekan tombol apapun ");
        getch();
        fclose(data);
        system("cls");
        break;

        case  2:
       
        printf("masukan pencarian ID = ");
        scanf("%s",&cari2);
        for (int i = 0; i < n; i++)
        {
            if((strstr(brg[i].id,cari2)!=0))
            {
        printf("ID        :  %s \n",brg[i].id);
        printf("NAMA      :  %s \n",brg[i].namabarang);
        printf("JENIS     :  %s \n",brg[i].jenis);
        printf("KODE RAK  :  %s \n",brg[i].koderak);
        printf("STOK      :  %d \n",brg[i].stok);
        printf("================================\n");
            }
        }
        printf("tekan tombol apapun ");
        getch();
        fclose(data);
        system("cls");
        break;
        case 3:
        fclose(data);
        system("cls");
        break;
    }

    
}
void update()
{
    system("cls");
    data = fopen(nm, "w+");

    for (int i = 0; i < n; i++)
    {
        printf("================================\n");
        printf("ID        :  %s \n",brg[i].id);
        printf("NAMA      :  %s \n",brg[i].namabarang);
        printf("JENIS     :  %s \n",brg[i].jenis);
        printf("KODE RAK  :  %s \n",brg[i].koderak);
        printf("STOK      :  %d \n",brg[i].stok);
        printf("================================\n");
    }

    fseek(data, offset, 0);
    for (int i = 0; i < n; i++)
    {
    printf("masukan ID barang : ");
    scanf("%s",&brg[i].id);
    printf("masukan Nama barang : ");
    scanf("%s",&brg[i].namabarang);
    printf("masukan Jenis barang : ");
    scanf("%s",&brg[i].jenis);
    printf("masukan kode rak barang : ");
    scanf("%s",&brg[i].koderak);
    printf("masukan stok barang : ");
    scanf("%d",&brg[i].stok); 
    printf("\n");
    }
    fwrite(&brg,sizeof(brg),1,data);
    fclose(data);
    printf("\ndata berhasil di update :) \n");
    printf("tekan tombol apapun");
    getch();
    system("cls");

}