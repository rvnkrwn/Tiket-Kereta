#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

string kereta[6] = {"Brantas", "Singasari", "Mataram", "Bogowonto", "Kertanegara", "Gumarang"};
string nomor_tempat_duduk[10] = {"A1", "A2", "A3", "A4", "A5", "B1", "B2", "B3", "B4", "B5"};
string kota[6] = {"Jakarta", "Surabaya", "Bandung", "Semarang", "Yogyakarta", "Purwokerto"};

string tiket[100][10];
string nama_pemilik_tiket, nik;
int k_asal, k_tujuan;
int total = 0;

void pilihanKota()
{
    int pilihan = 0;

    do
    {
        cout << "~> Daftar Kota Asal : \n";
        for (int ka = 0; ka < 6; ka++)
        {
            cout << "\t" << ka + 1 << ". " << kota[ka] << endl;
        }
        cout << "\tKota Asal Anda (1-6) : ";
        cin >> pilihan;
        if (pilihan > 6 || pilihan < 1)
        {
            system("Color 04");
            cout << "\n\tKota anda tidak ada!!!\n";
        }
        else
        {
            tiket[total][5] = kota[pilihan - 1];
            system("Color 07");
        }
    } while (pilihan > 6 || pilihan < 1);
    do
    {
        cout << "~> Daftar Kota Tujuan : \n";
        for (int kt = 0; kt < 6; kt++)
        {
            cout << "\t" << kt + 1 << ". " << kota[kt] << endl;
        }
        cout << "\tKota Tujuan Anda (1-6) : ";
        cin >> pilihan;
        if (pilihan > 6 || pilihan < 1)
        {
            system("Color 04");
            cout << "\n\tKota anda tidak ada!!!\n";
        }
        else
        {
            tiket[total][6] = kota[pilihan - 1];
            system("Color 07");
        }
    } while (pilihan > 6 || pilihan < 1);
}

void pilihanKereta()
{
    int pilihan = 0;

    do
    {
        cout << "~> Daftar Kereta : \n";
        for (int i = 0; i < 6; i++)
        {
            cout << "\t" << i + 1 << ". " << kereta[i] << endl;
        }
        cout << "\tKereta pilihan Anda (1-6) : ";
        cin >> pilihan;
        if (pilihan > 6 || pilihan < 1)
        {
            system("Color 04");
            cout << "\n\tKereta anda tidak ada\n";
        }
        else
        {
            tiket[total][1] = kereta[pilihan - 1];
            system("Color 07");
        }
    } while (pilihan > 6 || pilihan < 1);
}

void pilihanKursi()
{
    int pilihan = 0;
    bool tersedia = true;
    do
    {
        cout << "~> Daftar Tempat Duduk : \n";
        for (int i = 0; i < 6; i++)
        {
            cout << "\t" << i + 1 << ". " << nomor_tempat_duduk[i] << endl;
        }
        cout << "\tTempat Duduk pilihan Anda (1-6) : ";
        cin >> pilihan;
        if (pilihan > 6 || pilihan < 1)
        {
            system("Color 04");
            cout << "\n\tTempat Duduk anda tidak ada\n";
        }
        else
        {
            tiket[total][2] = nomor_tempat_duduk[pilihan - 1];
            for (int i = 0; i < 10; i++)
            {
                if (tiket[total][2] != tiket[i][2])
                {
                    tersedia = true;
                }
            }
            system("Color 07");
        }
    } while (pilihan > 6 || pilihan < 1 || tersedia == false);
}

void harga_tiket()
{
    // string kota[] = {"Jakarta", "Surabaya", "Bandung", "Semarang", "Yogyakarta", "Purwokerto"};
    if (tiket[total][5] == "Jakarta" && tiket[total][6] == "Surabaya" || tiket[total][5] == "Surabaya" && tiket[total][6] == "Jakarta")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "700.000";
    }
    else if (tiket[total][5] == "Jakarta" && tiket[total][6] == "Bandung" || tiket[total][5] == "Bandung" && tiket[total][6] == "Jakarta")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "200.000";
    }
    else if (tiket[total][5] == "Jakarta" && tiket[total][6] == "Semarang" || tiket[total][5] == "Semarang" && tiket[total][6] == "Jakarta")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "500.000";
    }
    else if (tiket[total][5] == "Jakarta" && tiket[total][6] == "Yogyakarta" || tiket[total][5] == "Yogyakarta" && tiket[total][6] == "Jakarta")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "600.000";
    }
    else if (tiket[total][5] == "Jakarta" && tiket[total][6] == "Purwokerto" || tiket[total][5] == "Purwokerto" && tiket[total][6] == "Jakarta")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "550.000";
    }

    else if (tiket[total][5] == "Surabaya" && tiket[total][6] == "Bandung" || tiket[total][5] == "Bandung" && tiket[total][6] == "Surabaya")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "650.000";
    }
    else if (tiket[total][5] == "Surabaya" && tiket[total][6] == "Semarang" || tiket[total][5] == "Semarang" && tiket[total][6] == "Surabaya")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "200.000";
    }
    else if (tiket[total][5] == "Surabaya" && tiket[total][6] == "Yogyakarta" || tiket[total][5] == "Yogyakarta" && tiket[total][6] == "Surabaya")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "210.000";
    }
    else if (tiket[total][5] == "Surabaya" && tiket[total][6] == "Purwokerto" || tiket[total][5] == "Purwokerto" && tiket[total][6] == "Surabaya")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "400.000";
    }

    else if (tiket[total][5] == "Bandung" && tiket[total][6] == "Semarang" || tiket[total][5] == "Semarang" && tiket[total][6] == "Bandung")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "450.000";
    }
    else if (tiket[total][5] == "Bandung" && tiket[total][6] == "Yogyakarta" || tiket[total][5] == "Yogyakarta" && tiket[total][6] == "Bandung")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "650.000";
    }
    else if (tiket[total][5] == "Bandung" && tiket[total][6] == "Purwokerto" || tiket[total][5] == "Purwokerto" && tiket[total][6] == "Bandung")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "550.000";
    }

    else if (tiket[total][5] == "Semarang" && tiket[total][6] == "Yogyakarta" || tiket[total][5] == "Yogyakarta" && tiket[total][6] == "Semarang")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "180.000";
    }
    else if (tiket[total][5] == "Semarang" && tiket[total][6] == "Purwokerto" || tiket[total][5] == "Purwokerto" && tiket[total][6] == "Semarang")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "150.000";
    }

    else if (tiket[total][5] == "Purwokerto" && tiket[total][6] == "Yogyakarta" || tiket[total][5] == "Yogyakarta" && tiket[total][6] == "Purwokerto")
    {
        tiket[total][7] = "05.30-09.30";
        tiket[total][8] = "250.000";
    }
    else
    {
        tiket[total][7] = "Tidak tersedia";
        tiket[total][8] = "Tidak tersedia";
    }
}
