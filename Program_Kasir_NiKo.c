//include library

#include <stdio.h>
#include <stdlib.h>

//program utama kasir

int main(void){
    //deklarasi variabel yang dibutuhkan untuk menjalankan program kasir perfume
    int pilihan, pilih, jumlah, grandtotal=0, bayar=0;
    char konfirmasi;

    up:
        printf("\t\t ----NiKo Perfume Mart---\n");
        printf("\t\t No.  Perfume           | Price  \n");
        printf("\t\t 1. Giordani Gold       | Rp. 200.000\n");
        printf("\t\t 2. Sakura Bloom        | Rp. 450.000\n");
        printf("\t\t 3. Karachi Woman       | Rp. 100.000\n");


        printf("\t\t-------------------------------------\n");
        printf("\t\t Berapa banyak parfum yang ingin di pesan: ");
        scanf("%d", &pilihan);
        for (int i=0; i<pilihan; i++){
        pilihan:
        printf("\n\t\t Pilih Parfum : "); scanf("%d", &pilih);

        switch(pilih){

            case 1 :
            printf("\t\t-----Detail Transaksi----\n");
            printf("\t\t Anda memilih parfum Giordani Gold dengan harga Rp.200.000\n");
            printf("\t\tMasukkan jumlah yang ingin di beli:"); scanf("%d", &jumlah);
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t Harga\t:Rp.%d\n,", jumlah*200000);
            grandtotal +=jumlah*200000;
            break;

            case 2 :
            printf("\t\t-----Detail Transaksi----\n");
            printf("\t\t Anda memilih parfum Sakura Bloom dengan harga Rp.450.000\n");
            printf("\t\tMasukkan jumlah yang ingin di beli:"); scanf("%d", &jumlah);
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t Harga\t:Rp.%d\n,", jumlah*450000);
            grandtotal +=jumlah*450000;
            break;

            case 3 :
            printf("\t\t-----Detail Transaksi----\n");
            printf("\t\t Anda memilih parfum Karachi Woman dengan harga Rp.100.000\n");
            printf("\t\tMasukkan jumlah yang ingin di beli:"); scanf("%d", &jumlah);
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t Harga\t:Rp.%d\n,", jumlah*100000);
            grandtotal +=jumlah*100000;
            break;

            default:
                printf("\t\tParfum Tidak Ada Dalam List Kami\n");
                goto pilihan;
            }
        }
    printf("\t\t Total Harga : %d\n", grandtotal);

    repeat:
        if(bayar == 0 || bayar<grandtotal){
            printf("\t\tNominal Pembayaran :"); scanf("%d",&bayar);

        }
        if(bayar != 0 && bayar >= grandtotal){
            printf("\t\t Tunai : Rp.%d\n", bayar);
            printf("\t\t Kembali : Rp.%d\n", bayar - grandtotal);
        }else if (bayar!= 0 == bayar < grandtotal){
            printf("\t\tUang Anda Kurang Rp.%d\n", grandtotal-bayar);
            goto repeat;
        }


//KONFIRMASI UNTUK KELUAR PROGRAM
printf("\t\t Apakah anda ingin mengakhiri program? [Y/T] ");
scanf("%s", &konfirmasi);

switch(konfirmasi){
    case 'Y':
    case 'y':
        return 0;
        break;
    case 'n':
    case 'N':
       pilihan = pilih=jumlah = grandtotal=bayar=0;
       system("cls");
       goto up;
       break;

}

}
