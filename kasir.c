#include <stdio.h>
#include <stdlib.h>


int main(void){

    int menu, pilih, jumlah, grandtotal = 0, bayar = 0;
    char konfirmasi;

    up:
    printf("\t\t                                                   \n");
    printf("\t\t+================ NiKo Perfume Mart  ================+\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t| No.   Perfum     | Price                           |\n");
    printf("\t\t| 1. Giordani Gold | Rp. 200.0000                    |\n");
    printf("\t\t| 2. Sakura Bloom  | Rp. 450.0000                    |\n");
    printf("\t\t| 3. Karachi Woman | Rp. 100.0000                    |\n");

    printf("\t\t+====================================================+\n");
    printf("\t\tBerapa banyak parfum yang ingin di pesan : "); scanf("%d", &menu);

    for (int i = 0; i < menu; i++){

       menu:
       printf("\n\t\tPilih Parfume : "); scanf("%d", &pilih);


       switch(pilih){

        case 1:
            printf("\t\t+================  DETAIL TRANSAKSI  ================+\n");
            printf("\t\t|                                                    |\n");
            printf("\t\t|Anda memilih perfume 'Giordani Gold'                |\n");
            printf("\t\t|-->Dengan harga : Rp. 200.000/botol'                |\n");
            printf("\t\t| Masukan jumlah yang ingin dibeli: "); scanf("%d", &jumlah);
            printf("\t\t|____________________________________________________|\n");
            printf("\t\t|                                                    |\n");
            printf("\t\t|              Harga\t: Rp.%d\n", jumlah * 200000 );
            printf("\t\t|                                                    |\n");
            printf("\t\t|____________________________________________________|\n");
            grandtotal += jumlah * 200000;
            break;
        case 2:
            printf("\t\t+================  DETAIL TRANSAKSI  ================+\n");
            printf("\t\t|                                                    |\n");
            printf("\t\t|Anda memilih perfume 'Sakura Bloom'                 |\n");
            printf("\t\t|-->Dengan harga : Rp. 450.000/botol'                |\n");
            printf("\t\t| Masukan jumlah yang ingin dibeli: "); scanf("%d", &jumlah);
            printf("\t\t|____________________________________________________|\n");
            printf("\t\t|                                                    |\n");
            printf("\t\t|              Harga\t: Rp.%d\n", jumlah * 450000 );
            printf("\t\t|                                                    |\n");
            printf("\t\t|____________________________________________________|\n");
            grandtotal += jumlah * 450000;
            break;
        case 3:
            printf("\t\t+================  DETAIL TRANSAKSI  ================+\n");
            printf("\t\t|                                                    |\n");
            printf("\t\t|Anda memilih perfume 'Giordani Gold'                |\n");
            printf("\t\t|-->Dengan harga : Rp. 100.000/botol'                |\n");
            printf("\t\t| Masukan jumlah yang ingin dibeli: "); scanf("%d", &jumlah);
            printf("\t\t|____________________________________________________|\n");
            printf("\t\t|                                                    |\n");
            printf("\t\t|              Harga\t: Rp.%d\n", jumlah * 100000 );
            printf("\t\t|                                                    |\n");
            printf("\t\t|____________________________________________________|\n");
            grandtotal += jumlah * 100000;
            break;
        default:
            printf("\t\t+====================================================+\n");
            printf("\t\t|                                                    |\n");
            printf("\t\t|         PARFUM TIDAK ADA DALAM LIST KAMI           |\n");
            printf("\t\t|                                                    |\n");
            printf("\t\t+====================================================+\n");
            goto menu;
       }
    }

    printf("\t\t+====================================================+\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|Total harga : %d\n", grandtotal);
    printf("\t\t|                                                    |\n");
    printf("\t\t+====================================================+\n");

    repet:
    if(bayar == 0 || bayar < grandtotal){

        printf("\t\tNominal pembayaran : "); scanf("%d", &bayar);
    }

    printf("\t\t+====================================================+\n");
    if(bayar != 0 && bayar >= grandtotal){
        printf("\t\t  Tunai : Rp.%d\n", bayar);
        printf("\t\t  Kembali : Rp.%d\n", bayar - grandtotal);
    }else if(bayar != 0 && bayar < grandtotal){
        printf("\t\tUang anda kurang Rp.%d!\n", grandtotal - bayar);
        goto repet;
    }
    printf("\t\t+====================================================+\n");


    printf("\t\tApakah anda ingin mengakhiri program ? [Y/N] : "); scanf("%s", &konfirmasi);

    switch(konfirmasi){
        case 'y':
        case 'Y':
            return 0;
            break;
        case 'n':
        case 'N':
            menu = pilih = jumlah = grandtotal = bayar = 0;
            system("cls");
            goto up;
            break;

    }

}
