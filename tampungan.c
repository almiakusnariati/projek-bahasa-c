
//=========================================== LIBRARY ==============================================================================

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tampilan.c"
#include "tampilan_utama.c"
#include <time.h>

// ======================================== PROTOTYPE ==============================================================================================

void daftar();
void user();
void menu();
void gotoxy(int x, int y);
void login_user();
void menu_awal();
void plh(int x, int y);
void pilih_lagi(int x, int y);
void bg_menu_ars();
void kilat();
void menu_kilat();
void ekspres();
void menu_ekspres();
void reguler();
void menu_reguler();
void consoletitle();
int ukuran();
void loading();
char lanjut(int x, int y);
void biodata();
void memilih(int x, int y);
void struk();
void biodata_kilat();
void biodata_ekspres();
void biodata_reguler();
void bayar();
void bg(int color);
void color(int text, int background);
void textcolor(int color);
void gotoxy(int x, int y);
char *validasi_alm(char *tamp);
void admin();
void cetakBarang_reguler();
void cetakBarang_kilat();
void menu_admin();
void cetakBarang_ekspres();
void data_kamu();
void info();



//=================================== VARIABLE GLOBAL ========================================



char nohp[13] = {};
char usr[100], pass[100];
char nama[50];
char kelamin[5];
char buff1[100], buff2[100];
char menu_ars[100][100] = {"Bantal/guling kecil", "Bantal/guling sedang", "Bantal/guling besar", "Boneka mini", "Boneka sedang", "Boneka besar",
                           "Blouse/celana panjang", "Celana pendek", "Celana panjang jeans", "Celana pendek jeans", "Kemeja Lengan Panjang ",
                           "Kemeja Lengan Pendek ", "selimut kecil", "selimut sedang", "selimut besar", "handuk besar", "handuk kecil"};
int harga[100] = {5000, 7000, 10000, 7000, 10000, 20000, 5000, 5000, 7000,
                  5000, 3000, 15000, 23000, 30000, 20000, 15000, 10000};

int harga_kilat = 4000;
int harga_ekspres = 2000;
int milih_2;
int subtotal;
char pilih_3;
char pilih_1;
int pilih_2;
char pilih_antar_jemput;
int pilih_ars;
int jumlah = 0;
int sub = 0;
char hari[][7] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
char bulan[][10] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

int tambah_kilat = 2;
int tambah_ekspres = 4;
int tambah_reguler = 6;
char milih;
char hrg[100];
char tamp[100];
char tampchar[100];
int tampangka = 0;
char alamat[100];
char tampjk[100];
char jenkel[100];

int buff = 0;
int harga1[100] = {};
char nama_menu[100][100] = {};
int banyak_item[100] = {};



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loading()
{
    for (int a = 1, b = 1; a <= 100; a++)
    {
        gotoxy(45, 33);
        printf(" Loading  %d %%  ", a);
        Sleep(20);

        if (a % 2 == 0)
        {
            
            gotoxy(b + 30, 35);
            printf("%c", 219);
            Sleep(7);
            b++;
        }
    }
}

void bingkai(int x, int y, int tcolor, int bcolor, int panjang, int lebar)
{
    for (int z = 1; z <= panjang; z++)
    {
        for (int v = 1; v <= lebar - 1; v++)
        {
            if (z == 1 || v == 1 || z == panjang || v == lebar - 1)
            {
                gotoxy(x + v, y + z);
                color(tcolor, tcolor);
                printf("%c", 219);
            }
            else
            {
                gotoxy(x + v, y + z);
                color(bcolor, bcolor);
                printf(" ");
            }
        }
    }
}

char *mini2(char *tamp2)
{
    char inp;
    char tamp[100] = {};
    int index = 0;
    while ((inp = getch()) != 13 || index < 1)
    {
        if (index < 2 && ((inp >= '1' && inp <= '9') && index < 2) || inp == '0' && index != 0 && index < 2)
        {
            printf("%c", inp);
            tamp[index] = inp;
            index++;
        }
        else if (inp == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    strcpy(tamp2, tamp);
    return tamp2;
}

char *valhrg(int x, int y)
{
    char input;
    char tamp[100] = {};
    int index = 0;
    while ((input = getch()) != 13 || index < 3)
    {
        if (index < 10 && (input >= '1' && input <= '9' || input == '0' && index != 0))
        {
            gotoxy(x + index, y);
            printf("%c", input);
            tamp[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    return strcpy(hrg, tamp);
}

void plh_ars(int x, int y)
{
    char input;
    char tamp[100] = {};
    int index = 0;
    while ((input = getch()) != 13 || index < 1)
    {
        if (index < 2 && (input >= '1' && input <= '9' && index == 0 || tamp[0] == '1' && input >= '0' && input <= '7' && index != 0))
        {
            gotoxy(x + index, y);
            printf("%c", input);
            tamp[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    pilih_3 = atoi(tamp);
}

char lanjut(int x, int y)
{
    char input;
    char tmp;
    int index = 0;
    while ((input = getch()) != 13 || index < 1)
    {
        if (index < 1 && (input == 'y' || input == 'n'))
        {
            gotoxy(x + index, y);
            printf("%c", input);
            tmp = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            tmp = '\0';
        }
    }
    return tmp;
}

void plh(int x, int y)
{
    char input;
    char tamp[100] = {};
    int index = 0;
    while ((input = getch()) != 13 || index < 1)
    {
        if (index < 1 && (input >= '1' && input <= '3'))
        {
            gotoxy(x + index, y);
            printf("%c", input);
            tamp[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    pilih_1 = atoi(tamp);
}

void memilih(int x, int y)
{
    char input;
    char tamp[100] = {};
    int index = 0;
    while ((input = getch()) != 13 || index < 1)
    {
        if (index < 1 && (input >= '1' && input <= '2'))
        {
            gotoxy(x + index, y);
            printf("%c", input);
            tamp[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    pilih_antar_jemput = atoi(tamp);
}

void pilih_lagi(int x, int y)
{
    char input;
    char tamp[100] = {};
    int index = 0;
    while ((input = getch()) != 13 || index < 1)
    {
        if (index < 1 && (input >= '1' && input <= '4'))
        {
            gotoxy(x + index, y);
            printf("%c", input);
            tamp[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    pilih_2 = atoi(tamp);
}

void pilih_lagi2(int x, int y)
{
    char input;
    char tamp[100] = {};
    int index = 0;
    while ((input = getch()) != 13 || index < 1)
    {
        if (index < 1 && (input >= '1' && input <= '5'))
        {
            gotoxy(x + index, y);
            printf("%c", input);
            tamp[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    pilih_2 = atoi(tamp);
}

void validasi_user()
{
    char inputan;
    char data1[30] = {};
    int index = 0;
    while ((inputan = getch()) != 13 || index < 3 || data1[index - 1] == ' ' || data1[index - 1] == '-' || data1[index - 1] == '\'')
    {
        if (index < 10 && (inputan >= 'a' && inputan <= 'z' || inputan == ' ' && index != 0 && data1[index - 1] != ' ' || inputan == '-' && index != 0 && data1[index - 1] != '-' || inputan == '\'' && index != 0 && data1[index - 1] != '\'' || (inputan >= '0' && inputan <= '9') && index != 0))
        {
            printf("%c", inputan);
            data1[index] = inputan;
            index++;
        }
        else if (inputan == 8 && index != 0)
        {
            printf("\b \b");
            index -= 1;
            data1[index] = ' ';
        }
    }
    for (int a = 0; a < index; a++)
    {
        strcpy(usr, data1);
    }
}

void validasi_pass()
{
    char inputan;
    char data1[30] = {};
    int index = 0;
    while ((inputan = getch()) != 13 || index < 3 || data1[index - 1] == ' ' || data1[index - 1] == '-' || data1[index - 1] == '\'')
    {
        if (index < 15 && (inputan >= 'a' && inputan <= 'z' || inputan >= 'A' && inputan <= 'Z' || inputan == ' ' && index != 0 && data1[index - 1] != ' ' || inputan == '-' && index != 0 && data1[index - 1] != '-' || inputan == '\'' && index != 0 && data1[index - 1] != '\'' || inputan >= '0' && inputan <= '9'))
        {
            printf("%c", inputan);
            data1[index] = inputan;
            index++;
        }
        else if (inputan == 8 && index != 0)
        {
            printf("\b \b");
            index -= 1;
            data1[index] = ' ';
        }
    }
    strcpy(pass, data1);
}
void validasi_nohp()
{
    char inputan1;
    char data1[30] = {};
    char data2[30] = {};
    int index = 0;

    while ((inputan1 = getch()) != 13 || index < 9)
    {
        if (inputan1 >= '0' && inputan1 <= '9' && index < 11 && (inputan1 != data1[index - 1] || inputan1 != data1[index - 2] || inputan1 != data1[index - 3]))
        {
            if (index >= 1 || (index == 0 && inputan1 != '4' && index == 0 && inputan1 != '6' && index == 0 && inputan1 != '0'))
            {
                printf("%c", inputan1);
                data1[index] = inputan1;
                index++;
            }
            else if (index >= 4)
            {
                printf("%c", inputan1);
                data1[index] = inputan1;
                index++;
            }
        }
        else if (inputan1 == 8 && index != 0)
        {
            printf("\b \b");
            index -= 1;
            data1[index] = ' ';
        }
        for (int a = 0; a < index; a++)
        {
            data2[a] = data1[a];
        }
        strcpy(nohp, data2);
    }
}

char *valnama(char *nama)
{
    char input;
    int index = 0;
    while ((input = getch()) != 13 || index < 3 || nama[index - 1] == ' ')
    {
        if (index < 30 && (input >= 'A' && input <= 'Z' && index == 0 ||
                           input >= 'A' && input <= 'Z' && nama[index - 1] == ' ' ||
                           input == ' ' && index != 0 && nama[index - 1] != ' ' ||
                           (input >= 'a' && input <= 'z') && (input != nama[index - 1] || input != nama[index - 2]) &&
                               index != 0 && nama[index - 1] != ' '))
        {
            printf("%c", input);
            nama[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            nama[index] = '\0';
        }
    }
}
char *jk(char *jenis_kel)
{
    char input;
    int index = 0;
    while ((input = getch()) != 13 || index < 1)
    {
        if (index < 1 && (input == 'P' || input == 'p' || input == 'l' || input == 'L'))
        {
            printf("%c", input);
            jenis_kel[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            kelamin[index] = '\0';
        }
    }
    return jenis_kel;
}
char *validasi_alm(char *tamp)
{
    int index = 0;
    int space = 0;
    int titik = 0;
    int miring = 0;
    char inp;
    while ((inp = getch()) != 13 || index < 4 || tamp[index - 1] == ' ')
    {
        if (inp >= 'a' && inp <= 'z' && index != 0 && (inp != tamp[index - 1] || inp != tamp[index - 2]) && index < 19 ||
            inp >= 'A' && inp <= 'Z' && (index == 0 || tamp[index - 1] == ' ') && index < 19 ||
            inp == ' ' && index != 0 && inp != tamp[index - 1] && space < 1 ||
            inp == '.' && titik < 1 || inp == '\'' && miring < 1)
        {
            printf("%c", inp);
            tamp[index] = inp;
            index++;
            if (inp == ' ')
            {
                space++;
            }
            if (inp == '.')
            {
                titik++;
            }
            if (inp == '\'')
            {
                miring++;
            }
        }
        else if (inp == 8 && index != 0)
        {
            if (tamp[index - 1] == ' ')
            {
                space--;
            }
            if (inp == '.')
            {
                titik--;
            }
            if (inp == '\'')
            {
                miring--;
            }
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    return tamp;
}

void menu()
{
    bg(8);
    system("cls");
    tampilan_awalars();
    system("cls");
    bg(15);
    tampilan2();
    bingkai(10, 16, 8, 7, 5, 27);
    gotoxy(20, 19);
    color(0, 7);
    printf("1.USER");
    bingkai(45, 16, 8, 7, 5, 27);
    gotoxy(53, 19);
    color(0, 7);
    printf("2.ADMIN");
    bingkai(78, 16, 8, 7, 5, 27);
    gotoxy(87, 19);
    color(0, 7);
    printf("3.Keluar");
    bingkai(45, 25, 8, 7, 5, 27);
    gotoxy(53, 28);
    color(0, 7);
    printf("PILIH   : ");
    plh(63, 28);

    if (pilih_1 == 1)
    {
        user();
    }
    else if (pilih_1 == 2)
    {
        admin();
    }
    else if (pilih_1 == 3)
    {
        exit(0);
    }
}

void user()
{
    bg(7);
    system("cls");
    tampilan4();
    bingkai(12, 6, 8, 7, 5, 27);
    gotoxy(20, 9);
    color(0, 7);
    printf("1.LOGIN");
    bingkai(74, 6, 8, 7, 5, 27);
    gotoxy(81, 9);
    color(0, 7);
    printf("2.DAFTAR");
    bingkai(12, 30, 8, 7, 5, 27);
    gotoxy(19, 33);
    color(0, 7);
    printf("3.INFO");
    bingkai(74, 30, 8, 7, 5, 27);
    gotoxy(81, 33);
    color(0, 7);
    printf("4.KEMBALI");
    bingkai(47, 17, 8, 7, 5, 27);
    gotoxy(54, 20);
    color(0, 7);
    printf("PILIH : ");
    pilih_lagi(62, 20);
    if (pilih_2 == 1)
    {
        login_user();
    }
    else if (pilih_2 == 2)
    {
        daftar();
    }
    else if (pilih_2 == 3)
    {
        info();
    }
    else if (pilih_2 == 4)
    {
        menu();
    }
}

void daftar()
{
    char nama[100] = {};
    bg(7);
    system("cls");
    // tampilan2();
    bingkai(18, 8, 8, 15, 22, 75);
    bingkai(19, 9, 15, 7, 19, 73);
    bingkai(20, 10, 8, 7, 18, 71);

    color(0, 7);
    gotoxy(35, 14);
    printf("NAMA                : ");
    gotoxy(35, 16);
    printf("ALAMAT              : ");
    gotoxy(35, 18);
    printf("NO.HP               : +628");
    gotoxy(35, 20);
    printf("USERNAME            : ");
    gotoxy(35, 22);
    printf("PASSWORD            : ");
    gotoxy(35, 24);
    printf("JENIS KELAMIN       : ");

    gotoxy(57, 14);
    valnama(nama);
    gotoxy(57, 16);
    strcpy(alamat, validasi_alm(tamp));
    gotoxy(61, 18);
    validasi_nohp();
    gotoxy(57, 20);
    validasi_user();
    gotoxy(57, 22);
    validasi_pass();
    gotoxy(57, 24);
    strcpy(tampjk, jk(jenkel));

    gotoxy(38, 26);
    printf("AKUN ANDA SUDAH TERDAFTAR ");
    Sleep(2000);

    FILE *data;
    data = fopen("nama_lengkap.txt", "a");
    fprintf(data, "%s\n", nama);
    fclose(data);
    data = fopen("alamat.txt", "a");
    fprintf(data, "%s\n", alamat);
    fclose(data);
    data = fopen("hp.txt", "a");
    fprintf(data, "%s\n", nohp);
    data = fopen("username.txt", "a");
    fprintf(data, "%s\n", usr);
    fclose(data);
    data = fopen("password.txt", "a");
    fprintf(data, "%s\n", pass);
    fclose(data);
    loading();
    login_user();
}
void login_user()
{
    bg(15);
    system("cls");
    bool ditemukan = false;
    tampilan1();
    bingkai(38, 15, 8, 7, 5, 38);
    gotoxy(41, 18);
    color(0, 7);
    printf("USERNAME   :  ");
    bingkai(38, 22, 8, 7, 5, 38);
    gotoxy(41, 25);
    color(0, 7);
    printf("PASSWOARD  :  ");
    gotoxy(54, 18);
    printf("");
    validasi_user();
    printf("");
    gotoxy(54, 25);
    validasi_pass();

    FILE *data;
    data = fopen("username.txt", "r");
    while (fscanf(data, "%s", buff1) != EOF)
    {
        if (strcmp(buff1, usr) == 0)
        {
            // ditemukan = true;
            break;
        }
    }
    fclose(data);
    data = fopen("password.txt", "r");
    while (fscanf(data, "%s", buff2) != EOF)
    {
        if (strcmp(buff2, pass) == 0)
        {
            ditemukan = true;
            break;
        }
    }
    // fscanf(data, "%s", buff2);
    fclose(data);

    if ((strcmp(usr, buff1) == 0 && strcmp(pass, buff2) == 0))
    {
        gotoxy(40, 35);
        color(0, 7);
        printf("Berhasil Login");
        loading();
        menu_awal();
    }
    else
    {
        gotoxy(40, 35);
        printf("GAGAL LOGIN");
        Sleep(1000);
        login_user();
    }
}
void menu_awal()
{
    bg(0);
    system("cls");
    tampilan3();
    bingkai(6, 18, 8, 7, 5, 27);
    gotoxy(14, 21);
    color(0, 7);
    printf("1.KILAT(2 HARI)");
    bingkai(42, 18, 8, 7, 5, 27);
    gotoxy(47, 21);
    color(0, 7);
    printf("2.EXPRESS(5 HARI)");
    bingkai(78, 18, 8, 7, 5, 27);
    gotoxy(83, 21);
    color(0, 7);
    printf("3.REGULER(6 HARI)");
    bingkai(42, 32, 8, 7, 5, 27);
    gotoxy(49, 35);
    color(0, 7);
    printf("PILIH   : ");
    plh(60, 35);

    if (pilih_1 == 1)
    {
        kilat();
    }
    else if (pilih_1 == 2)
    {
        ekspres();
    }
    else if (pilih_1 == 3)
    {
        reguler();
    }
}

void bg_menu_ars()
{
    bg(7);
    system("cls");
    bingkai(2, 5, 8, 7, 32, 8);
    bingkai(8, 5, 8, 7, 32, 50);
    bingkai(56, 5, 8, 7, 32, 30);
    bingkai(2, 5, 8, 7, 5, 84);
    bingkai(8, 5, 8, 7, 5, 50);
    bingkai(2, 32, 8, 7, 6, 84);
    bingkai(90, 17, 8, 7, 5, 27); // pilih

    gotoxy(18, 8);
    color(0, 7);
    printf(" LAYANAN LOUNDRY PER ITEM");
    gotoxy(4, 8);
    color(0, 7);
    printf(" NO ");
    gotoxy(63, 8);
    color(0, 7);
    printf(" HARGA PER ITEM ");
}
void kilat()
{
    bg_menu_ars();
    for (int a = 0; a < 17; a++)
    {
        gotoxy(5, 12 + a);
        color(0, 7);
        printf("%d", a + 1);
        gotoxy(15, 12 + a);
        color(0, 7);
        printf("%s", menu_ars[a]);
        gotoxy(62, 12 + a);
        color(0, 7);
        printf("RP.%d", harga[a] + harga_kilat);
    }
    menu_kilat();
}

void menu_kilat()
{
    char tampchar[100];
    int local = 0;
    gotoxy(100, 20);
    printf("Pilih :   ");
    plh_ars(110, 20);

    for (int a = 0; a < 17; a++)
    {
        if (a == (pilih_3 - 1))
        {
            gotoxy(8, 35);
            color(0, 7);
            printf("banyak item %s : ", menu_ars[a]);
            strcpy(tampchar, mini2(tamp));
            tampangka = atoi(tampchar);
            sub += ((harga[a] + harga_kilat) * tampangka);
            fflush(stdin);
            gotoxy(8, 36);
            color(0, 7);
            printf("ingin menambah loundry lagi ?  y / n ?  ");

            milih = lanjut(47, 36);
            gotoxy(47, 36);
            printf("                           ");
            gotoxy(8, 35);
            printf("                                            ");
            gotoxy(110, 20);
            printf("    ");

            harga1[buff] = harga[a] + harga_kilat;
            strcpy(nama_menu[buff], menu_ars[a]);
            banyak_item[buff] = tampangka;

            char buff_1[100][100], buff_2[100][100];
            int arr[100] = {};
            int indek = 0, sama = 0;

            FILE *cek;
            cek = fopen("./kilat.txt", "r");
            while (fscanf(cek, "%[^#]#%[^\n]\n", buff_1[indek], buff_2[indek]) != EOF)
            {
                arr[indek] = atoi(buff_2[indek]);
                indek++;
            }
            fclose(cek);

            arr[local] += banyak_item[local];

            FILE *a;
            a = fopen("./kilat.txt", "w");
            for (int x = 0; x < indek; x++)
            {
                fprintf(a, "%s#%d\n", buff_1[x], arr[x]);
            }
            fclose(a);
            local = 0;
            buff++;

            if (milih == 'y')
            {

                gotoxy(27, 28);
                printf("          ");

                menu_kilat();
            }
            else if (milih == 'n')
            {
                biodata_kilat();
            }
            break;
        }
        local++;
    }
}

void ekspres()
{
    bg_menu_ars();
    for (int a = 0; a < 17; a++)
    {
        gotoxy(5, 12 + a);
        color(0, 7);
        printf("%d", a + 1);
        gotoxy(15, 12 + a);
        color(0, 7);
        printf("%s", menu_ars[a]);
        gotoxy(62, 12 + a);
        color(0, 7);
        printf("RP.%d", harga[a] + harga_ekspres);
    }

    menu_ekspres();
}

void menu_ekspres()
{
    char tampchar[100];
    int local = 0;
    gotoxy(100, 20);
    printf("Pilih :   ");
    plh_ars(110, 20);

    for (int a = 0; a < 17; a++)
    {
        if (a == (pilih_3 - 1))
        {

            gotoxy(8, 35);
            color(0, 7);
            printf("banyak item %s : ", menu_ars[a]);
            strcpy(tampchar, mini2(tamp));
            tampangka = atoi(tampchar);
            sub += ((harga[a] + harga_ekspres) * tampangka);
            fflush(stdin);
            gotoxy(8, 36);
            color(0, 7);
            printf("ingin menambah loundry lagi ?  y / n ?  ");

            milih = lanjut(47, 36);
            gotoxy(47, 36);
            printf("                           ");
            gotoxy(8, 35);
            printf("                                            ");
            gotoxy(110, 20);
            printf("    ");

            harga1[buff] = harga[a];
            strcpy(nama_menu[buff], menu_ars[a]);
            banyak_item[buff] = tampangka;

            char buff_1[100][100], buff_2[100][100];
            int arr[100] = {};
            int indek = 0, sama = 0;

            FILE *cek;
            cek = fopen("./ekspres.txt", "r");
            while (fscanf(cek, "%[^#]#%[^\n]\n", buff_1[indek], buff_2[indek]) != EOF)
            {
                arr[indek] = atoi(buff_2[indek]);
                indek++;
            }
            fclose(cek);

            arr[local] += banyak_item[local];

            FILE *a;
            a = fopen("./ekspres.txt", "w");
            for (int x = 0; x < indek; x++)
            {
                fprintf(a, "%s#%d\n", buff_1[x], arr[x]);
            }
            fclose(a);
            local = 0;
            buff++;

            if (milih == 'y')
            {
                gotoxy(27, 28);
                printf("         ");

                menu_ekspres();
            }
            else if (milih == 'n')
            {
                biodata_ekspres();
            }
            break;
        }
        local++;
    }
}

void reguler()
{
    bg_menu_ars();
    for (int a = 0; a < 17; a++)
    {
        gotoxy(5, 12 + a);
        color(0, 7);
        printf("%d", a + 1);
        gotoxy(15, 12 + a);
        color(0, 7);
        printf("%s", menu_ars[a]);
        gotoxy(62, 12 + a);
        color(0, 7);
        printf("RP.%d", harga[a]);
    }
    menu_reguler();
}

void menu_reguler()
{
    char tampchar[100];
    int local = 0;
    gotoxy(100, 20);
    printf("Pilih :   ");
    plh_ars(110, 20);

    for (int a = 0; a <= 17; a++)
    {
        if (a == (pilih_3 - 1))
        {

            gotoxy(8, 35);
            color(0, 7);
            printf("banyak item %s : ", menu_ars[a]);
            strcpy(tampchar, mini2(tamp));
            tampangka = atoi(tampchar);
            sub += ((harga[a]) * tampangka);
            fflush(stdin);
            gotoxy(8, 36);
            color(0, 7);
            printf("ingin menambah loundry lagi ?  y / n ?  ");

            milih = lanjut(47, 36);
            gotoxy(47, 36);
            printf("                           ");
            gotoxy(8, 35);
            printf("                                            ");
            gotoxy(110, 20);
            printf("    ");

            harga1[buff] = harga[a];
            strcpy(nama_menu[buff], menu_ars[a]);
            banyak_item[buff] = tampangka;

            char buff_1[100][100], buff_2[100][100];
            int arr[100] = {};
            int indek = 0, sama = 0;

            FILE *cek;
            cek = fopen("./reguler.txt", "r");
            while (fscanf(cek, "%[^#]#%[^\n]\n", buff_1[indek], buff_2[indek]) != EOF)
            {
                arr[indek] = atoi(buff_2[indek]);
                indek++;
            }
            fclose(cek);

            arr[local] += banyak_item[local];

            FILE *a;
            a = fopen("./reguler.txt", "w");
            for (int x = 0; x < indek; x++)
            {
                fprintf(a, "%s#%d\n", buff_1[x], arr[x]);
            }
            fclose(a);
            local = 0;
            buff++;

            if (milih == 'y')
            {
                gotoxy(27, 28);
                printf("       ");

                menu_reguler();
            }
            else if (milih == 'n')
            {
                biodata_reguler();
            }
            break;
        }
    }
}

void biodata()
{
    bg(7);
    system("cls");
    char nama[100] = {};

    bingkai(18, 8, 8, 15, 40, 75);
    bingkai(19, 9, 15, 7, 38, 73);
    bingkai(20, 10, 8, 7, 36, 71);

    color(0, 7);
    gotoxy(35, 14);
    printf("NAMA                : ");
    gotoxy(35, 16);
    printf("ALAMAT              : ");
    gotoxy(35, 18);
    printf("NO.HP               : +628");
    gotoxy(35, 20);
    printf("JENIS KELAMIN       : ");

    gotoxy(57, 14);
    valnama(nama);
    gotoxy(57, 16);
    strcpy(alamat, validasi_alm(tamp));
    gotoxy(61, 18);
    validasi_nohp();
    gotoxy(57, 20);
    strcpy(tampjk, jk(jenkel));

    FILE *fptr;
    fptr = fopen("data.txt", "a");
    fprintf(fptr, "%s#%s#%s#%s\n", nama, nohp, alamat, tampjk);
    fclose(fptr);
}

void biodata_kilat()
{
    biodata();
    gotoxy(35, 27);
    printf("pilih layanan yang ingin anda pakai ");
    gotoxy(35, 28);
    printf("1.ANTAR ALAMAT(NAMBAH BIAYA SEBESAR RP.7.000)");
    gotoxy(35, 29);
    printf("2.JEMPUT ");
    gotoxy(35, 30);
    printf("pilih : ");
    memilih(44, 30);
    if (pilih_antar_jemput == 1)
    {

        sub += 7000;
        gotoxy(35, 32);
        printf("BIAYA BERTAMBAH SEBESAR RP.7000");
        time_t sekarang = time(NULL);
        struct tm waktu = *localtime(&sekarang);
        gotoxy(32, 35);
        printf("LAYANAN YANG ANDA PILIH LAYANANA LOUNDRY KILAT ");
        gotoxy(27, 37);
        printf("anda ngeloudry hari %s, %d %s %d || %02d.%02d WIB", hari[waktu.tm_wday], waktu.tm_mday, bulan[waktu.tm_mon], 1900 + waktu.tm_year, waktu.tm_hour, waktu.tm_min);
        gotoxy(28, 38);
        printf("loundry anda akan di antar hari %s, %d %s %d ", hari[waktu.tm_wday + tambah_kilat], tambah_kilat + waktu.tm_mday, bulan[waktu.tm_mon]);
        gotoxy(30, 43);
        Sleep(2000);

        struk();
    }
    else if (pilih_antar_jemput == 2)
    {
        sub = sub;
        gotoxy(33, 32);
        time_t sekarang = time(NULL);
        struct tm waktu = *localtime(&sekarang);
        printf("LAYANAN YANG ANDA PILIH LAYANAN LOUNDRY KILAT ");
        gotoxy(26, 37);
        printf("anda ngeloudry hari %s, %d %s %d || %02d.%02d WIB", hari[waktu.tm_wday], waktu.tm_mday, bulan[waktu.tm_mon], 1900 + waktu.tm_year, waktu.tm_hour, waktu.tm_min);
        gotoxy(26, 38);
        printf("loundry bisa di jemput hari %s, %d %s %d ", hari[waktu.tm_wday + tambah_kilat], tambah_kilat + waktu.tm_mday, bulan[waktu.tm_mon]);
        gotoxy(30, 43);
        Sleep(3000);
        struk();
    }
}

void biodata_ekspres()
{
    biodata();
    gotoxy(35, 27);
    printf("pilih layanan yang ingin anda pakai ");
    gotoxy(35, 28);
    printf("1.ANTAR ALAMAT(NAMBAH BIAYA SEBESAR RP.7.000)");
    gotoxy(35, 29);
    printf("2.JEMPUT ");
    gotoxy(35, 30);
    printf("pilih : ");
    memilih(44, 30);

    if (pilih_antar_jemput == 1)
    {
        sub += 7000;
        gotoxy(33, 32);
        printf("BIAYA BERTAMBAH SEBESAR RP.7000");
        time_t sekarang = time(NULL);
        struct tm waktu = *localtime(&sekarang);
        gotoxy(32, 35);
        printf("LAYANAN YANG ANDA PILIH LAYANAN LOUNDRY EKSPRES ");
        gotoxy(27, 37);
        printf("anda ngeloudry hari %s, %d %s %d || %02d.%02d WIB", hari[waktu.tm_wday], waktu.tm_mday, bulan[waktu.tm_mon], 1900 + waktu.tm_year, waktu.tm_hour, waktu.tm_min);
        gotoxy(28, 38);
        printf("loundry anda akan di antar hari %s, %d %s %d ", hari[waktu.tm_wday + tambah_ekspres], tambah_ekspres + waktu.tm_mday, bulan[waktu.tm_mon]);
        gotoxy(30, 43);
        Sleep(3000);
        struk();
    }
    else if (pilih_antar_jemput == 2)
    {
        sub = sub;
        gotoxy(34, 32);
        time_t sekarang = time(NULL);
        struct tm waktu = *localtime(&sekarang);
        printf("LAYANAN YANG ANDA PILIH LAYANAN LOUNDRY EKSPRESS ");
        gotoxy(32, 35);
        printf("anda ngeloudry hari %s, %d %s %d || %02d.%02d WIB", hari[waktu.tm_wday], waktu.tm_mday, bulan[waktu.tm_mon], 1900 + waktu.tm_year, waktu.tm_hour, waktu.tm_min);
        gotoxy(32, 37);
        printf("loundry bisa di jemput hari %s, %d %s %d ", hari[waktu.tm_wday + tambah_ekspres], tambah_ekspres + waktu.tm_mday, bulan[waktu.tm_mon]);

        Sleep(3000);
        struk();
    }
}

void biodata_reguler()
{
    biodata();
    gotoxy(35, 27);
    printf("pilih layanan yang ingin anda pakai ");
    gotoxy(35, 28);
    printf("1.ANTAR ALAMAT(NAMBAH BIAYA SEBESAR RP.7.000)");
    gotoxy(35, 29);
    printf("2.JEMPUT ");
    gotoxy(35, 30);
    printf("pilih : ");
    memilih(44, 30);
    if (pilih_antar_jemput == 1)
    {
        sub += 7000;
        gotoxy(35, 32);
        printf("BIAYA BERTAMBAH SEBESAR RP.7000");
        time_t sekarang = time(NULL);
        struct tm waktu = *localtime(&sekarang);
        gotoxy(32, 35);
        printf("LAYANAN YANG ANDA PILIH LAYANAN LOUNDRY REGULER ");
        gotoxy(27, 37);
        printf("anda ngeloudry hari %s, %d %s %d || %02d.%02d WIB", hari[waktu.tm_wday], waktu.tm_mday, bulan[waktu.tm_mon], 1900 + waktu.tm_year, waktu.tm_hour, waktu.tm_min);
        gotoxy(28, 38);
        printf("loundry anda akan di antar hari %s, %d %s %d ", hari[waktu.tm_wday + tambah_reguler], tambah_reguler + waktu.tm_mday, bulan[waktu.tm_mon]);
        gotoxy(30, 43);
        Sleep(3000);
        struk();
    }
    else if (pilih_antar_jemput == 2)
    {
        sub = sub;
        gotoxy(35, 32);
        time_t sekarang = time(NULL);
        struct tm waktu = *localtime(&sekarang);
        printf("LAYANAN YANG ANDA PILIH LAYANAN LOUNDRY REGULER");
        gotoxy(32, 35);
        printf("anda ngeloudry hari %s, %d %s %d || %02d.%02d WIB", hari[waktu.tm_wday], waktu.tm_mday, bulan[waktu.tm_mon], 1900 + waktu.tm_year, waktu.tm_hour, waktu.tm_min);
        gotoxy(26, 37);
        printf("loundry bisa di jemput hari %s, %d %s %d ", hari[waktu.tm_wday + tambah_reguler], tambah_reguler + waktu.tm_mday, bulan[waktu.tm_mon]);
        gotoxy(30, 43);

        Sleep(3000);
        struk();
    }
}

void struk()
{
    bg(7);
    system("cls");
    bingkai(3, 5, 8, 7, 40, 64);
    bingkai(2, 4, 8, 15, 42, 66);
    bingkai(69, 23, 8, 7, 5, 38);
    bingkai(69, 29, 8, 7, 5, 38);
    color(0, 15);
    gotoxy(8, 8);
    printf("JENIS ");
    gotoxy(45, 8);
    printf("HARGA ");
    gotoxy(56, 8);
    printf("JUMLAH ");
    color(8, 8);
    gotoxy(5, 10);
    printf("============================================================");

    for (int x = 0; x < buff; x++)
    {

        color(0, 15);
        gotoxy(8, 12 + x);
        printf("%s", nama_menu[x]);
        gotoxy(45, 12 + x);
        printf("%d", harga1[x]);
        gotoxy(57, 12 + x);
        printf("%d", banyak_item[x]);
    }
    gotoxy(73, 26);
    color(0, 7);
    printf("TOTAL BAYAR : RP.%d", sub);
    bayar();
}
void bayar()
{
    int uang = 0;
    gotoxy(72, 32);
    color(0, 7);
    printf("Input uang  : RP.");
    uang = atoi(valhrg(89, 32));
    if (uang > sub)
    {

        bingkai(69, 35, 8, 7, 5, 45);
        color(0, 7);
        gotoxy(75, 38);
        printf("KEMBALIAN   : RP.%d ", uang - sub);
    }
    else if (uang == sub)
    {
        bingkai(69, 35, 8, 7, 5, 45);
        color(0, 7);
        gotoxy(75, 38);
        printf("UANG ANDA PAS ");
    }
    else if (uang < sub)
    {
        color(0, 7);
        gotoxy(89, 32);
        printf("uang anda kurang ");
        Sleep(100);
        color(0, 7);
        gotoxy(89, 32);
        printf("                   ");
        bayar();
    }
    gotoxy(75, 42);
    printf("Tekan Anykey untuk kembali ");
    getch();
    menu();
}

void cetakBarang_kilat()
{
    system("cls");
    bg(7);
    char buff_1[100][100], buff_2[100][100];
    int indek = 0, sama = 0;
    bingkai(8, 8, 8, 15, 27, 55);
    bingkai(55, 8, 8, 15, 27, 40);

    color(0, 15);
    gotoxy(26, 11);
    printf("JENIS MENU ");
    gotoxy(66, 11);
    printf("BANYAK ITEM ");
    gotoxy(9, 13);
    color(8, 8);
    printf("======================================================================================");

    FILE *simpan;
    simpan = fopen("./kilat.txt", "r");
    while (fscanf(simpan, "%[^#]#%[^\n]\n", buff_1[indek], buff_2[indek]) != EOF)
    {
        gotoxy(20, 15 + indek);
        color(0, 15);
        printf("%s ", buff_1[indek]);
        gotoxy(62, 15 + indek);
        color(0, 15);
        printf("%s", buff_2[indek]);
        indek++;
    }
    fclose(simpan);
    color(0, 7);
    gotoxy(35, 37);
    printf("Tekan Anykey untuk kembali ");
    getch();
    menu_admin();
}
void cetakBarang_ekspres()
{
    system("cls");
    bg(7);
    char buff_1[100][100], buff_2[100][100];
    int indek = 0, sama = 0;
    bingkai(8, 8, 8, 15, 27, 55);
    bingkai(55, 8, 8, 15, 27, 40);

    color(0, 15);
    gotoxy(26, 11);
    printf("JENIS MENU ");
    gotoxy(66, 11);
    printf("BANYAK ITEM ");
    gotoxy(9, 13);
    color(8, 8);
    printf("=====================================================================================");

    FILE *simpan;
    simpan = fopen("./ekspres.txt", "r");
    while (fscanf(simpan, "%[^#]#%[^\n]\n", buff_1[indek], buff_2[indek]) != EOF)
    {
        gotoxy(20, 15 + indek);
        color(0, 15);
        printf("%s ", buff_1[indek]);
        gotoxy(62, 15 + indek);
        color(0, 15);
        printf("%s", buff_2[indek]);
        indek++;
    }
    fclose(simpan);
    color(0, 7);
    gotoxy(35, 37);
    printf("Tekan Anykey untuk kembali ");
    getch();
    menu_admin();
}
void cetakBarang_reguler()
{
    bg(7);
    system("cls");
    char buff_1[100][100], buff_2[100][100];
    int indek = 0, sama = 0;

    bingkai(8, 8, 8, 15, 27, 55);
    bingkai(55, 8, 8, 15, 27, 40);

    color(0, 15);
    gotoxy(26, 11);
    printf("JENIS MENU ");
    gotoxy(66, 11);
    printf("BANYAK ITEM ");
    gotoxy(9, 13);
    color(8, 8);
    printf("======================================================================================");
    FILE *simpan;
    simpan = fopen("./reguler.txt", "r");
    while (fscanf(simpan, "%[^#]#%[^\n]\n", buff_1[indek], buff_2[indek]) != EOF)
    {
        gotoxy(20, 15 + indek);
        color(0, 15);
        printf("%s ", buff_1[indek]);
        gotoxy(62, 15 + indek);
        color(0, 15);
        printf("%s", buff_2[indek]);
        indek++;
    }
    fclose(simpan);
    color(0, 7);
    gotoxy(35, 37);
    printf("Tekan Anykey untuk kembali ");
    getch();
    menu_admin();
}

void data_kamu()
{
    system("cls");
    bg(7);
    bingkai(2, 2, 8, 15, 50, 105);
    color(0, 15);
    gotoxy(16, 5);
    printf("NAMA ");
    gotoxy(40, 5);
    printf("NO HP ");
    gotoxy(63, 5);
    printf("ALAMAT");
    gotoxy(86, 5);
    printf("JK");
    color(8, 8);
    gotoxy(4, 7);
    printf("===========================================================================================================");
    char nama[100][100], nohp[100][100], alamat[100][100], stok[100][100];
    char daftar[100];
    int index = 0;
    int a;
    FILE *data;
    data = fopen("data.txt", "r");
    while (fscanf(data, "%[^#]#%[^#]#%[^#]#%[^\n]\n", nama[index], nohp[index], alamat[index], stok[index]) != EOF)
    {
        gotoxy(15, 12 + index);
        color(0, 15);
        printf("%s", nama[index]);
        gotoxy(35, 12 + index);
        color(0, 15);
        printf("+628%s", nohp[index]);
        gotoxy(60, 12 + index);
        color(0, 15);
        printf("%s", alamat[index]);
        gotoxy(87, 12 + index);
        color(0, 15);
        printf("%s", stok[index]);
        index++;
    }
    fclose(data);
    gotoxy(35, 45);
    printf("Tekan Anykey untuk kembali ");
    getch();
    menu_admin();
}

void admin()
{
    system("cls");
    char user[100];
    bg(15);
    tampilan1();
    gotoxy(44, 5);
    color(0, 7);
    bingkai(40, 18, 8, 7, 5, 35);
    gotoxy(47, 21);
    color(0, 7);
    printf("kode  akses : ");
    int a = 0, b = 0;
    gotoxy(60, 21);
    user[a] = getch();
    while (user[a] != 13)
    {
        if (user[a] == 8)
        {
            a--;
            if (a < 0)
            {
                a = 0;
            }
            gotoxy(60 + a, 21);
            printf(" ");
        }
        else
        {
            printf("*");
            a++;
        }

        if (a > 5)
        {
            a = 5;
            gotoxy(65, 21);
            printf(" ");
        }
        gotoxy(60 + a, 21);
        user[a] = getch();
    }
    user[a] = '\0';

    if ((strlen(user) <= 9) && (strcmp(user, "12100") == 0))
    {
        loading();
        system("cls");
        menu_admin();
    }
    else
    {
        for (int x = 0; x < 2; x++)
        {
            gotoxy(50, 30);
            printf("KODE AKSES SALAH !!!");
            Sleep(200);
            gotoxy(50, 30);
            printf("                     ");
            Sleep(200);
        }
        system("cls");
        admin();
    }
}
void menu_admin()
{
    bg(7);

    system("cls");
    tampilan_adm();
    bingkai(2, 0, 15, 7, 7, 47);
    bingkai(3, 1, 8, 7, 5, 45);
    gotoxy(9, 4);
    color(0, 7);
    printf("1.Lihat data pelanggan");
    bingkai(2, 7, 15, 7, 7, 47);
    bingkai(3, 8, 8, 7, 5, 45);
    gotoxy(10, 11);
    color(0, 7);
    printf("2.Lihat data ekspres");
    bingkai(2, 14, 15, 7, 7, 47);
    bingkai(3, 15, 8, 7, 5, 45);
    color(0, 7);
    gotoxy(10, 18);
    printf("3.lihat data loundry kilat");
    bingkai(2, 21, 15, 7, 7, 47);
    bingkai(3, 22, 8, 7, 5, 45);
    color(0, 7);
    gotoxy(10, 25);
    printf("4.lihat data loundry reguler");
    bingkai(2, 28, 15, 7, 7, 47);
    bingkai(3, 29, 8, 7, 5, 45);
    color(0, 7);
    gotoxy(10, 32);
    printf("5.kembali");
    bingkai(2, 35, 15, 7, 7, 47);
    bingkai(3, 36, 8, 7, 5, 45);
    color(0, 7);
    gotoxy(10, 39);
    printf("pilih  : ");
    pilih_lagi2(19, 39);
    if (pilih_2 == 1)
    {
        data_kamu();
    }
    else if (pilih_2 == 2)
    {
        system("cls");
        cetakBarang_ekspres();
    }
    else if (pilih_2 == 3)
    {
        system("cls");
        cetakBarang_kilat();
    }
    else if (pilih_2 == 4)
    {
        system("cls");
        cetakBarang_reguler();
    }
    else if (pilih_2 == 5)
    {
        menu();
    }
    gotoxy(75, 70);
    printf("Tekan Anykey untuk kembali ");
    getch();
    menu();
}

void info()
{
    bg(7);
    system("cls");
    bingkai(18, 8, 8, 15, 40, 80);
    bingkai(19, 9, 15, 7, 38, 78);
    bingkai(20, 10, 8, 7, 36, 76);
    color(0, 7);
    gotoxy(28, 15);
    printf("Ars loundry adalah aplikasi memudahkan anda yang sibuk ");
    gotoxy(28, 16);
    printf("atau malas nyuci ,Sampai pakaian kotor menumpuk di rumah ");
    gotoxy(28, 17);
    printf("padahal bisa jadi sarang bakteri dan penyakit ");
    gotoxy(28, 18);
    printf("Masukkan pakaian kotor mu sekarang ke lundryan kami ");
    gotoxy(28, 19);
    printf("Dijamin pakaian bersih  dan wangi  ");
    gotoxy(28, 20);
    printf("Tersedia Layanan loundry kilat pakaian siap 2 hari ");
    gotoxy(28, 21);
    printf("Tersedia Layanan loundry ekspres pakaian siap 4 hari ");
    gotoxy(28, 22);
    printf("Tersedia Layanan loundry reguler pakaian siap 6 hari ");
    gotoxy(28, 23);
    printf("Pakaian anda bisa di antar langsung ke alamat anda ");
    gotoxy(28, 24);
    printf("ALAMAT LOUNDRY ARS ");
    gotoxy(28, 25);
    printf("Jl. Dakota No. 8A, Kelurahan Sukaraja, Kecamatan Cicendo");
    gotoxy(28, 26);
    printf("Kota Bandung, Jawa Barat.");
    gotoxy(28, 30);
    printf("DATA PEMILIK LOUNDRY ARS ");
    gotoxy(28, 32);
    printf("NAMA                 : AISYAH ROMAITO SIREGAR ");
    gotoxy(28, 33);
    printf("UMUR                 : 25 Tahun");
    gotoxy(28, 34);
    printf("Perguruan Tinggi     : Universitas Nasional Pasim Bandung      ");
    gotoxy(28, 35);
    printf("Alamat               : Padang bujur ,medan ,sumatra utara ");
    gotoxy(28, 36);
    printf("TELEPON              : +6281234567890");

    gotoxy(75, 43);
    printf("Tekan Anykey untuk kembali ");
    getch();
    user();
}

int ukuran()
{
    system("mode con cols=130 lines= 42");
    return 0;
}
void consoletitle()
{
    SetConsoleTitle("LOUNDRY ARS");
}
void main()
{
    ukuran();
    consoletitle();
    menu();
   

    getch();
}