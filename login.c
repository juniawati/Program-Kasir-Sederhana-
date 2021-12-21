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

int main(){

    //Variabel yang diperlukan
    char username[10], password[10], user[10], pass[10];
    int menu, userbenar, passbenar;
    FILE*file;


printf("\t\t+---------------------------------------------------------+\n");
printf("\t\t|                                                         |\n");
printf("\t\t|        Selamat Datang di Program Kasir NiKo             |\n");
printf("\t\t|    Silahkan Pilih Menu Dibawah Untuk Mulai Program      |\n");
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
    printf("\t\t+---------------------------------------------------------+\n");
    printf("\t\t|                    LOGIN BERHASIL                       |\n");
    printf("\t\t|             Silahkan Lakukan Transaksi Disini           |\n");
    printf("\t\t+---------------------------------------------------------+\n");
    printf("\t\t|                                                         |\n");
    printf("\t\t|                      CREDIT TO :                        |\n");
    printf("\t\t|               M I S E R I C O R D I A S                 |\n");
    printf("\t\t|                          &                              |\n");
    printf("\t\t|                  J U N I A W A T I                      |\n");
    printf("\t\t|                                                         |\n");
    printf("\t\t|                                                         |\n");
    printf("\t\t|                   T H A N K Y O U                       |\n");
    printf("\t\t|                                                         |\n");
    printf("\t\t+---------------------------------------------------------+\n");


    goto menu;
}

/************************************CASE 3 KELUAR***************************************/
case 3 :
    printf("\t\t+---------------------------------------------------------+\n");
    printf("\t\t|                      TERIMAKASIH                        |\n");
    printf("\t\t+---------------------------------------------------------+\n");
    return 0;


}
}

