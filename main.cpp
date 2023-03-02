#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include "kereta.cpp"

using namespace std;

void save_database()
{
    system("clear");
    ofstream outFile;
    outFile.open("record_database.txt", ios::app);
    for (int c = 0; c < 10; c++)
    {
        for (int x = 0; x < 10; x++)
        {
            if (tiket[x][0] == "")
            {
                if (tiket[0][0] == "")
                {
                    outFile << "\nRiwayat Tiket tidak tersedia\n";
                }
                break;
            }

            for (int a = 0; a < 36; a++)
            {
                outFile << "= ";
            }
            outFile << endl;
            outFile << "\t\t\tkode                 :  " << tiket[x][0] << "\n";
            outFile << "\t\t\tkereta               :  " << tiket[x][1] << "\n";
            outFile << "\t\t\ttempat duduk         :  " << tiket[x][2] << "\n";
            outFile << "\t\t\tNama Lengkap         :  " << tiket[x][3] << "\n";
            outFile << "\t\t\tNIK                  :  " << tiket[x][4] << "\n";
            outFile << "\t\t\tKota Asal            :  " << tiket[x][5] << "\n";
            outFile << "\t\t\tKota tujuan          :  " << tiket[x][6] << "\n";
            outFile << "\t\t\tJadwal               :  " << tiket[x][7] << "\n";
            outFile << "\t\t\tharga tiket          :  " << tiket[x][8] << "\n";
            outFile << "\t\t\tstatus               :  " << tiket[x][9] << "\n";
            for (int d = 0; d < 36; d++)
            {
                outFile << "= ";
            }
            outFile << "\n\n";
        }
        outFile.close();
    }
}

void status_tiket()
{
    if (tiket[total][7] == "Tidak tersedia!!!")
    {
        tiket[total][9] = "Tidak berlaku";
    }
    else
    {
        tiket[total][9] = "Berlaku";
    }
}

void show_ticket()
{
    system("clear");
    for (int a = 0; a < 15; a++)
    {
        cout << "= ";
    }
    cout << " Riwayat Pemesanan Tiket ";
    for (int b = 0; b < 15; b++)
    {
        cout << " =";
    }
    cout << "\n\n\n";
    for (int i = 0; i < 10; i++)
    {
        if (tiket[i][0] == "")
        {
            if (tiket[0][0] == "")
            {
                cout << "\nRiwayat Tiket tidak tersedia\n";
            }
            break;
        }

        for (int a = 0; a < 18; a++)
        {
            cout << "= ";
        }
        cout << " Tiket ke- " << i + 1 << " ";
        for (int b = 0; b < 18; b++)
        {
            cout << " =";
        }
        cout << endl;
        cout << "\t\t\tkode                 :  " << tiket[i][0] << "\n";
        cout << "\t\t\tkereta               :  " << tiket[i][1] << "\n";
        cout << "\t\t\ttempat duduk         :  " << tiket[i][2] << "\n";
        cout << "\t\t\tNama Lengkap         :  " << tiket[i][3] << "\n";
        cout << "\t\t\tNIK                  :  " << tiket[i][4] << "\n";
        cout << "\t\t\tKota Asal            :  " << tiket[i][5] << "\n";
        cout << "\t\t\tKota tujuan          :  " << tiket[i][6] << "\n";
        cout << "\t\t\tJadwal               :  " << tiket[i][7] << "\n";
        cout << "\t\t\tharga tiket          :  " << tiket[i][8] << "\n";
        cout << "\t\t\tstatus               :  " << tiket[i][9] << "\n";
        for (int a = 0; a < 18; a++)
        {
            cout << "= ";
        }
        cout << " Tiket ke - " << i + 1 << " ";
        for (int b = 0; b < 18; b++)
        {
            cout << " =";
        }
        cout << "\n\n";
    }
}

void pesan()
{
    cout << "======================================\n";
    int randomku = (1 + (rand() % 100)) * 567;
    tiket[total][0] = to_string(randomku);
    getline(cin, nama_pemilik_tiket);
    cout << "~> Nama Lengkap : ";
    getline(cin, nama_pemilik_tiket);
    tiket[total][3] = nama_pemilik_tiket;
    cout << "~> NIK \t\t: ";
    getline(cin, nik);
    tiket[total][4] = nik;
    pilihanKota();
    pilihanKereta();
    pilihanKursi();
    harga_tiket();
    status_tiket();
    show_ticket();
}

void edit_tiket()
{
    show_ticket();
    string code;
    cout << "Masukan code tiket yang akan di edit : ";
    cin >> code;
    for (int cd = 0; cd < total; cd++)
    {
        if (tiket[cd][0] == code)
        {
            if (tiket[cd][0] != code)
            {
                cout << "\nTiket tidak ditemukan\n";
            }
            else
            {
                string status;
                cout << "Apakah anda ingin membatalkan tiket ? (Y/N) : ";
                cin >> status;
                if (status == "Y")
                {
                    tiket[cd][9] = "Tidak berlaku";
                    system("clear");
                    show_ticket();
                    cout << "\nAnda sukses membatalkan tiket!\n\n";
                    break;
                }
            }
        }
    }
}

void delete_ticket()
{
    show_ticket();
    string code;
    cout << "Masukan code tiket yang akan di hapus : ";
    cin >> code;
    for (int cd = 0; cd < total; cd++)
    {
        if (tiket[cd][0] == code)
        {
            if (tiket[cd][0] != code)
            {
                cout << "\nTiket tidak ditemukan\n";
            }
            else
            {
                string status;
                cout << "Apakah anda ingin menghapus tiket ini ? (Y/N) : ";
                cin >> status;
                if (status == "Y")
                {
                    for (int dc = 0; dc <= cd; dc++)
                    {
                        tiket[cd][dc].erase();
                        for (int w = cd; w < total; w++)
                        {
                            tiket[cd][0] = tiket[cd + 1][0];
                            tiket[cd][1] = tiket[cd + 1][1];
                            tiket[cd][2] = tiket[cd + 1][2];
                            tiket[cd][3] = tiket[cd + 1][3];
                            tiket[cd][4] = tiket[cd + 1][4];
                            tiket[cd][5] = tiket[cd + 1][5];
                            tiket[cd][6] = tiket[cd + 1][6];
                            tiket[cd][7] = tiket[cd + 1][7];
                            tiket[cd][8] = tiket[cd + 1][8];
                            tiket[cd][9] = tiket[cd + 1][9];
                        }
                        for (int i = 0; i < 9; i++)
                        {
                            tiket[total - 1][i].erase();
                        }
                    }

                    system("clear");
                    show_ticket();

                    cout << "\nAnda sukses menghapus tiket!\n\n";
                }
            }
        }
    }
}

void report_ticket_sell()
{
    system("clear");
    int Brantas = 0, Singasari = 0, Mataram = 0, Bogowonto = 0, Kertanegara = 0, Gumarang = 0;
    for (int i = 0; i < total; i++)
    {
        if (tiket[i][1] == "Brantas")
        {
            Brantas++;
        }
        else if (tiket[i][1] == "Singasari")
        {
            Singasari++;
        }
        else if (tiket[i][1] == "Mataram")
        {
            Mataram++;
        }
        else if (tiket[i][1] == "Bogowonto")
        {
            Bogowonto++;
        }
        else if (tiket[i][1] == "Kertanegara")
        {
            Kertanegara++;
        }
        else if (tiket[i][1] == "Gumarang")
        {
            Gumarang++;
        }
    }

    cout << "=================================\n";
    cout << "|+|     Laporan Pembelian     |+|\n";
    cout << "|+|       Tiket Kereta        |+|\n";
    cout << "=================================\n";
    cout << "|+| Nama Kereta |+|   Total   |+|\n";
    cout << "=================================\n";
    cout << "|+|   Brantas   |+|     " << Brantas << "     |+|\n";
    cout << "=================================\n";
    cout << "|+|  Singasari  |+|     " << Singasari << "     |+|\n";
    cout << "=================================\n";
    cout << "|+|   Mataram   |+|     " << Mataram << "     |+|\n";
    cout << "=================================\n";
    cout << "|+|  Bogowonto  |+|     " << Bogowonto << "     |+|\n";
    cout << "=================================\n";
    cout << "|+| Kertanegara |+|     " << Kertanegara << "     |+|\n";
    cout << "=================================\n";
    cout << "|+|  Gumarang   |+|     " << Gumarang << "     |+|\n";
    cout << "=================================\n";
    cout << "|+|  SUB TOTAL  |+|     " << Brantas + Singasari + Mataram + Bogowonto + Kertanegara + Gumarang << "     |+|\n";
    cout << "=================================\n";
}

void report_income()
{
    system("clear");
    int Brantas = 0, Singasari = 0, Mataram = 0, Bogowonto = 0, Kertanegara = 0, Gumarang = 0;
    for (int i = 0; i < total; i++)
    {
        if (tiket[i][1] == "Brantas")
        {
            Brantas += stoi(tiket[i][8]);
        }
        else if (tiket[i][1] == "Singasari")
        {
            Singasari += stoi(tiket[i][8]);
        }
        else if (tiket[i][1] == "Mataram")
        {
            Mataram += stoi(tiket[i][8]);
        }
        else if (tiket[i][1] == "Bogowonto")
        {
            Bogowonto += stoi(tiket[i][8]);
        }
        else if (tiket[i][1] == "Kertanegara")
        {
            Kertanegara += stoi(tiket[i][8]);
        }
        else if (tiket[i][1] == "Gumarang")
        {
            Gumarang += stoi(tiket[i][8]);
        }
    }
    cout << "=====================================\n";
    cout << "|+|     Laporan Pendapatan    \n";
    cout << "|+|       Tiket Kereta        \n";
    cout << "=====================================\n";
    cout << "|+| Nama Kereta |+|\tTotal\n";
    cout << "=====================================\n";
    cout << "|+|   Brantas   |+|\t" << Brantas << "\n";
    cout << "=====================================\n";
    cout << "|+|  Singasari  |+|\t" << Singasari << "\n";
    cout << "=====================================\n";
    cout << "|+|   Mataram   |+|\t" << Mataram << "\n";
    cout << "=====================================\n";
    cout << "|+|  Bogowonto  |+|\t" << Bogowonto << "\n";
    cout << "=====================================\n";
    cout << "|+| Kertanegara |+|\t" << Kertanegara << "\n";
    cout << "=====================================\n";
    cout << "|+|  Gumarang   |+|\t" << Gumarang << "\n";
    cout << "=====================================\n";
    cout << "|+|  SUB TOTAL  |+|\t" << Brantas + Singasari + Mataram + Bogowonto + Kertanegara + Gumarang << "\n";
    cout << "=====================================\n";
}

void find_ticket()
{
    system("clear");
    show_ticket();
    string cari_nik;
    cout << "\nMasukan nik untuk mencari tiket : ";
    cin >> cari_nik;
    for (int ct = 0; ct < total; ct++)
    {
        if (tiket[ct][4] == cari_nik)
        {
            system("clear");
            if (tiket[ct][4] == cari_nik)
            {
                cout << "=======================================================\n";
                cout << "|+|\tkode                 :  " << tiket[ct][0] << "\n";
                cout << "|+|\tkereta               :  " << tiket[ct][1] << "\n";
                cout << "|+|\ttempat duduk         :  " << tiket[ct][2] << "\n";
                cout << "|+|\tNama Lengkap         :  " << tiket[ct][3] << "\n";
                cout << "|+|\tNIK                  :  " << tiket[ct][4] << "\n";
                cout << "|+|\tKota Asal            :  " << tiket[ct][5] << "\n";
                cout << "|+|\tKota tujuan          :  " << tiket[ct][6] << "\n";
                cout << "|+|\tJadwal               :  " << tiket[ct][7] << "\n";
                cout << "|+|\tharga tiket          :  " << tiket[ct][8] << "\n";
                cout << "|+|\tstatus               :  " << tiket[ct][9] << "\n";
                cout << "=======================================================\n\n";
            }
        }
    }
}

int main()
{
    int pilihan;
    char lagi;
    do
    {
        system("clear");
        cout << "\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n";
        cout << "|+|\t\t\t\t\t\t\t|+|\n";
        cout << "|+|\t\t\t\x1b[1m\x1b[4mSelamat Datang\x1b[0m\t\t\t|+|\n";
        cout << "|+|\t\t\t      \x1b[1mDi\x1b[0m\t\t\t|+|\n";
        cout << "|+|\t\t\t \x1b[1mLoket Kereta\x1b[0m\t\t\t|+|\n";
        cout << "|+|\t\t\t  \x1b[1m\x1b[3mPurwokerto\x1b[0m\t\t\t|+|\n";
        cout << "|+|\t\t\t\t\t\t\t|+|\n";
        cout << " +++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n\n";
        cout << setw(38);
        cout << "Daftar Menu :\n\n";
        cout << "1. Pesan Tiket Sekarang\n";
        cout << "2. Pembatalan Tiket\n";
        cout << "3. Riwayat Tiket\n";
        cout << "4. Hapus Tiket\n";
        cout << "5. Laporan Pembelian Tiket\n";
        cout << "6. Laporan Pendapatan Pembelian Tiket\n";
        cout << "7. Cari Tiket\n";
        cout << "0. Keluar\n";
        cout << "\nMasukkan Pilihan Anda : \x1b[4m";
        cin >> pilihan;
        cout << "\x1b[0m";
        switch (pilihan)
        {
        case 1:
            pesan();
            total++;
            break;
        case 2:
            edit_tiket();
            break;
        case 3:
            show_ticket();
            break;
        case 4:
            delete_ticket();
            break;
        case 5:
            report_ticket_sell();
            break;
        case 6:
            report_income();
            break;
        case 7:
            find_ticket();
            break;
        case 0:
            exit;
            break;

        default:
            cout << "\n\tMenu yang anda pilih tidak tersedia!!!\n";
            cout << "\tKembali ke Menu? (Y/N) : ";
            cin >> lagi;
            if (lagi == 'N')
            {
                cout << "\n\tAnda Yakin? (Y/N) : ";
                char yakin;
                cin >> yakin;
                if (yakin == 'Y')
                {
                    exit;
                }
                else
                {
                    lagi = 'Y';
                }
            }
            break;
        }
        cout << "Kembali ke menu utama? (Y/N) : ";
        cin >> lagi;
        if (lagi == 'N')
        {
            save_database();
        }
    } while (lagi == 'Y');
    return 0;
}