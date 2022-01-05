#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/*
************************************************************************************
*                     TUGAS BESAR PEMROGRAMAN SEMESTER 1                           *
*    Nama Kelompok :                                                               *
*       1. I Nyoman Misericordias Dominicandra  [2105551037]                       *
*       2. Ni Kadek Juniawati                   [2105551041]                       *
*----------------------------------------------------------------------------------*
*   Tanggal : 14 Desember 2021                                                     *
*   Keterangan  : Membuat Registrasi dan Login                                     *
*   Tanggal : 21 Desember                                                          *
*   Keterangan : Melanjutkan Progress                                              *
*   Tanggal  : 30 Desember 2021                                                    *
*   Keterangan : REVISI                                                            *
*                                                                                  *
************************************************************************************
*/

//fungsi deklarasi
void program_kasir();
void list_parfum();
void tentang_kami();



int main(){




    //Variabel yang diperlukan login dan register
    char username[10], password[10], user[10], pass[10];
    int menu, userbenar, passbenar;
    FILE*file;


printf("\t\t+---------------------------------------------------------+\n");
printf("\t\t|                                                         |\n");
printf("\t\t|            Selamat Datang di Niko's Mart                |\n");
printf("\t\t|      Silahkan Pilih Menu Dibawah Untuk Mulai            |\n");
printf("\t\t|                                                         |\n");
printf("\t\t+---------------------------------------------------------+\n");
menu :
printf("\t\t+---------------------------------------------------------+\n");
printf("\t\t| No. |   Pilihan                                         |\n");
printf("\t\t+---------------------------------------------------------+\n");
printf("\t\t| 1.  |   Registrasi Petugas                              |\n");
printf("\t\t| 2.  |   Login Petugas                                   |\n");
printf("\t\t| 3.  |   Keluar                                          |\n");
printf("\t\t+---------------------------------------------------------+\n");
printf("\t\t Pilih Menu :");
scanf("%d", &menu);
printf("\t\t|                                                         |\n");
system("cls");

//Masuk ke switch case
switch(menu){
/************************************CASE 1 REGISTRASI***************************************/
case 1:
printf("\t\t+---------------------------------------------------------+\n");
printf("\t\t|            Silahkan Melakukan Registrasi                |\n");
printf("\t\t+---------------------------------------------------------+\n");

printf("\t\t Buat Username Baru : ");
scanf("%s", username);
file = fopen("username.txt", "w"); //----> 'w' artinya write : filenya bisa meyimpan data yang diinputkan user
fprintf(file, "%s", username);
fclose(file);

printf("\t\t Buat Password Baru : ");
scanf("%s", password);
file = fopen("password.txt", "w");
fprintf(file, "%s", password);
fclose(file);
system("cls");

printf("\t\t+---------------------------------------------------------+\n");
printf("\t\t|            Selamat! Akun Anda Sudah Disimpan            |\n");
printf("\t\t+---------------------------------------------------------+\n");
goto menu;
break;

/************************************CASE 2 LOGIN***************************************/
case 2 :
system("cls");
login:
printf("\t\t+---------------------------------------------------------+\n");
printf("\t\t|               Silahkan Melakukan Login                  |\n");
printf("\t\t+---------------------------------------------------------+\n");

printf("\t\t Masukkan Username : ");
file = fopen("username.txt", "r");    //---> 'r' artinya read [filenya dibaca saja]
fprintf(file, "%s", username);
fclose(file);
scanf("%s", user);

printf("\t\t Masukkan Password : ");
file = fopen("password.txt", "r");
fprintf(file, "%s", password);
fclose(file);
scanf("%s", pass);

//CEK LOGIN DISINI
passbenar = strcmp(pass, password);
userbenar = strcmp(user, username);

if(userbenar!=0 || passbenar!=0){
    printf("\t\t+---------------------------------------------------------+\n");
    printf("\t\t|                USERNAME/PASSWORD SALAH                  |\n");
    printf("\t\t+---------------------------------------------------------+\n");
    goto login;
}else {
    //jika berhasil login
    //VARIABEL
    int submenu;
    system("cls");
        submenu :
        printf("\t\t+---------------------------------------------------------+\n");
        printf("\t\t| No. |   Pilihan                                         |\n");
        printf("\t\t+---------------------------------------------------------+\n");
        printf("\t\t| 1.  |   Program Utama Kasir                             |\n");
        printf("\t\t| 2.  |   List Parfum                                     |\n");
        printf("\t\t| 3.  |   Tentang kami                                    |\n");
        printf("\t\t| 4.  |   Keluar                                          |\n");
        printf("\t\t+---------------------------------------------------------+\n");
        printf("\t\t Pilih Menu :");
        scanf("%d", &submenu);
        printf("\t\t|                                                         |\n");
        system("cls");

        switch (submenu){
            case 1:
                program_kasir();
                goto submenu;

            case 2:
                list_parfum();
                goto submenu;

            case 3:
                tentang_kami();
                goto submenu;

            case 4:
                return 0;

        }



}

/************************************CASE 3 KELUAR***************************************/
case 3 :
    printf("\t\t+---------------------------------------------------------+\n");
    printf("\t\t|                      TERIMAKASIH                        |\n");
    printf("\t\t+---------------------------------------------------------+\n");
    return 0;



}
}




//FUNGSI JALANKAN KASIR
void program_kasir(){
/* Program kasir */
    //deklarasi variabel yang dibutuhkan untuk menjalankan program kasir perfume
    int pilihan, pilih, jumlah, grandtotal=0, bayar=0;
    char konfirmasi;

system("cls");
    printf("\t\t+---------------------------------------------------------+\n");
    printf("\t\t|                  Selamat Datang                         |\n");
    printf("\t\t|            Silahkan Masukkan Transaksi                  |\n");
    printf("\t\t+---------------------------------------------------------+\n");
    printf("\t\t|                                                         |\n");
    up:
    printf("\t\t|-------------------NiKo Perfume Mart---------------------|\n");
    printf("\t\t| No.  Perfume           | Price                          |\n");
    printf("\t\t| 1. Giordani Gold       | Rp. 200.000                    |\n");
    printf("\t\t| 2. Sakura Bloom        | Rp. 450.000                    |\n");
    printf("\t\t| 3. Karachi Woman       | Rp. 100.000                    |\n");
    printf("\t\t| 4. Saint Laurent       | Rp. 820.000                    |\n");
    printf("\t\t| 5. Dior VIP            | Rp. 340.000                    |\n");
    printf("\t\t| 6. Hugo Boss           | Rp. 110.000                    |\n");
    printf("\t\t| 7. Innisfree           | Rp. 320.000                    |\n");
    printf("\t\t| 8. Zwitzal Baby        | Rp. 50.000                     |\n");
    printf("\t\t| 9. Love Bonito         | Rp. 125.000                    |\n");
    printf("\t\t| 10.The Body Shop       | Rp. 99.000                     |\n");
    printf("\t\t+---------------------------------------------------------+\n");

    printf("\t\t Berapa banyak jenis parfum yang di pesan: ");

        scanf("%d", &pilihan);
        for (int i=0; i<pilihan; i++){
        pilihan:
        printf("\n\t\t Pilih Parfum : "); scanf("%d", &pilih);

        switch(pilih){

            case 1 :
            printf("\t\t-----Detail Transaksi----\n");
            printf("\t\t Anda memilih parfum Giordani Gold dengan harga Rp.200.000\n");
            printf("\t\t Masukkan jumlah yang ingin di beli:"); scanf("%d", &jumlah);
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t Harga\t:Rp.%d\n,", jumlah*200000);
            grandtotal +=jumlah*200000;
            break;

            case 2 :
            printf("\t\t-----Detail Transaksi----\n");
            printf("\t\t Anda memilih parfum Sakura Bloom dengan harga Rp.450.000\n");
            printf("\t\t Masukkan jumlah yang ingin di beli:"); scanf("%d", &jumlah);
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t Harga\t:Rp.%d\n,", jumlah*450000);
            grandtotal +=jumlah*450000;
            break;

            case 3 :
            printf("\t\t-----Detail Transaksi----\n");
            printf("\t\t Anda memilih parfum Karachi Woman dengan harga Rp.100.000\n");
            printf("\t\t Masukkan jumlah yang ingin di beli:"); scanf("%d", &jumlah);
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t Harga\t:Rp.%d\n,", jumlah*100000);
            grandtotal +=jumlah*100000;
            break;

            case 4 :
            printf("\t\t-----Detail Transaksi----\n");
            printf("\t\t Anda memilih parfum Saint Laurent dengan harga Rp.820.000\n");
            printf("\t\t Masukkan jumlah yang ingin di beli:"); scanf("%d", &jumlah);
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t Harga\t:Rp.%d\n,", jumlah*820000);
            grandtotal +=jumlah*820000;
            break;

            case 5 :
            printf("\t\t-----Detail Transaksi----\n");
            printf("\t\t Anda memilih parfum Dior VIP dengan harga Rp.340.000\n");
            printf("\t\t Masukkan jumlah yang ingin di beli:"); scanf("%d", &jumlah);
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t Harga\t:Rp.%d\n,", jumlah*340000);
            grandtotal +=jumlah*340000;
            break;



            case 6  :
            printf("\t\t-----Detail Transaksi----\n");
            printf("\t\t Anda memilih parfum Hugo Boss dengan harga Rp.110.000\n");
            printf("\t\t Masukkan jumlah yang ingin di beli:"); scanf("%d", &jumlah);
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t Harga\t:Rp.%d\n,", jumlah*110000);
            grandtotal +=jumlah*110000;
            break;

            case 7 :
            printf("\t\t-----Detail Transaksi----\n");
            printf("\t\t Anda memilih parfum Innisfree dengan harga Rp.320.000\n");
            printf("\t\t Masukkan jumlah yang ingin di beli:"); scanf("%d", &jumlah);
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t Harga\t:Rp.%d\n,", jumlah*320000);
            grandtotal +=jumlah*320000;
            break;

            case 8 :
            printf("\t\t-----Detail Transaksi----\n");
            printf("\t\t Anda memilih parfum Zwitzal Baby dengan harga Rp.50.000\n");
            printf("\t\t Masukkan jumlah yang ingin di beli:"); scanf("%d", &jumlah);
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t Harga\t:Rp.%d\n,", jumlah*50000);
            grandtotal +=jumlah*50000;
            break;

            case 9 :
            printf("\t\t-----Detail Transaksi----\n");
            printf("\t\t Anda memilih parfum Love Bonito dengan harga Rp.125.000\n");
            printf("\t\t Masukkan jumlah yang ingin di beli:"); scanf("%d", &jumlah);
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t Harga\t:Rp.%d\n,", jumlah*125000);
            grandtotal +=jumlah*125000;
            break;

            case 10 :
            printf("\t\t-----Detail Transaksi----\n");
            printf("\t\t Anda memilih parfum The Body Shop dengan harga Rp.99.000\n");
            printf("\t\t Masukkan jumlah yang ingin di beli:"); scanf("%d", &jumlah);
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t Harga\t:Rp.%d\n,", jumlah*99000);
            grandtotal +=jumlah*99000;
            break;

            default:
                printf("\t\tParfum Tidak Ada Dalam List Kami\n");
                goto pilihan;
            }
        }
    printf("\n\t\t Total Harga : %d\n", grandtotal);

    repeat:
        if(bayar == 0 || bayar<grandtotal){
            printf("\t\t Nominal Pembayaran :"); scanf("%d",&bayar);

        }
        if(bayar != 0 && bayar >= grandtotal){
            printf("\t\t+---------------------------------------------------------+\n");
            printf("\t\t|         TERIMAKASIH SUDAH MEMBELI PRODUK KAMI           |\n");
            printf("\t\t+---------------------------------------------------------+\n");
            printf("\t\t|                      Detail Transaksi                   |\n");
            printf("\t\t|       Total Harga Parfum :                              |\n");
            printf("\t\t|       Nominal Bayar      : Rp.%d\n", bayar);
            printf("\t\t|       Kembalian          : Rp.%d\n", bayar - grandtotal);
            printf("\t\t+---------------------------------------------------------+\n");
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
//batas fungsi kasir

//fungsi list parfum
void list_parfum(){
    printf("\n\n\t\t|-------------------List Parfum---------------------|\n");
    printf("\t\t| No.  Perfume         Kode    | Price              |\n");
    printf("\t\t| 1. Giordani Gold      GG1    | Rp. 200.000        |\n");
    printf("\t\t| 2. Sakura Bloom       SB1    | Rp. 450.000        |\n");
    printf("\t\t| 3. Karachi Woman      kW1    | Rp. 100.000        |\n");
    printf("\t\t| 4. Saint Laurent      SL01   | Rp. 820.000        |\n");
    printf("\t\t| 5. Dior VIP           DVIP   | Rp. 340.000        |\n");
    printf("\t\t| 6. Hugo Boss          HB01   | Rp. 110.000        |\n");
    printf("\t\t| 7. Innisfree          INN1   | Rp. 320.000        |\n");
    printf("\t\t| 8. Zwitzal Baby       ZB01   | Rp. 50.000         |\n");
    printf("\t\t| 9. Love Bonito        LB01   | Rp. 125.000        |\n");
    printf("\t\t| 10.The Body Shop      TBS1   | Rp. 99.000         |\n");
    printf("\t\t+---------------------------------------------------+\n");

}

//fungsi tentang kami BY KOKO
void tentang_kami(){

printf("\n\n\t\t|-------------------Tentang Kami---------------------|\n");
    printf("\t\t|    Niko’s Perfume Mart adalah toko online parfume  |\n");
    printf("\t\t|    terbaik no. 1 di Indonesia. Kami menyediakan    |\n");
    printf("\t\t|    berbagai jenis dan merek parfume mulai dari     |\n");
    printf("\t\t|    yang termurah dan yang termahal. Toko kami      |\n");
    printf("\t\t|    memiliki beberapa keunggulan yaitu menyediakan  |\n");
    printf("\t\t|    parfume dengan harga termurah seIndonesia,      |\n");
    printf("\t\t|    parfume yang kami tawarkan pasti original,      |\n");
    printf("\t\t|    memberi garansi saat pengiriman                 |\n");
    printf("\t\t+---------------------------------------------------+\n");

    printf("\n\n\t\t|----------------------VISI-------------------------|\n");
    printf("\t\t\t\t|Maju,Maju,Jaya| \n");

    printf("\n\n\t\t|----------------------MISI-------------------------|\n");
    printf("\t\t|  1.Menyenangkan hati pelanggan dengan produk yang |\n");
    printf("\t\t|    kamin jual.                                    |\n");
    printf("\t\t|  2.Menjadi toko parfume terbesar.                 |\n");
    printf("\t\t|  3.Membanggakan bangsa dan negara.                |\n\n\n");
}
//batas fungsi tentang kami

