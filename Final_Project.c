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
*                                                                                  *
************************************************************************************
*/

//fungsi deklarasi
void program_kasir();
void listparfum();

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
printf("\t\t| 1.  |   Registrasi                                      |\n");
printf("\t\t| 2.  |   Login                                           |\n");
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
        printf("\t\t| 3.  |   Keluar                                          |\n");
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
    printf("\t\t+---------------------------------------------------------+\n");
    printf("\t\t Berapa banyak jenis parfum yang ingin di pesan: ");
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
//batas fungsi kasir

//fungsi list parfum
void list_parfum(){
    printf("\n\n\t\t|-------------------List Parfum---------------------|\n");
    printf("\t\t| No.  Perfume         Kode    | Price              |\n");
    printf("\t\t| 1. Giordani Gold      GG1    | Rp. 200.000        |\n");
    printf("\t\t| 2. Sakura Bloom       SB1    | Rp. 450.000        |\n");
    printf("\t\t| 3. Karachi Woman      kW1    | Rp. 100.000        |\n");
    printf("\t\t+---------------------------------------------------+\n");

}