#include <iostream>//ralat
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>


using namespace std;

struct datastnk {
    string nostnk;
    string nama;
    string jkendaraan;
    string alamat;

};

string replaceSpasi(string str);
string replaceUnderscore(string str);
void tambah_data();
void tampilkan_data();
void search_data();
void sorting_data();
void transaksi_data();

datastnk stnk[100];
string namafile;
int i, n;

int main() {

    int pilih;
    char ulang = 'Y';

    do {
        system("cls");
        cout << " ==================================" << endl;
        cout << "       TUGAS PROJEK ALGO 2023      " << endl;
        cout << " ==================================" << endl;
        cout << "       1. INPUT DATA               " << endl;
        cout << "       2. TAMPILKAN DATA           " << endl;
        cout << "       3. SEARCHING DATA           " << endl;
        cout << "       4. SORTING DATA             " << endl;
        cout << "       5. TRANSAKSI                " << endl;
        cout << "       6. KELUAR                   " << endl;
        cout << " ==================================" << endl;
        cout << " Silahkan pilih menu yang tersedia : ";
        cin >> pilih;

        if (pilih == 1) {
            cout << endl;
            tambah_data();
        } else if (pilih == 2) {
            cout << endl;
            tampilkan_data();
        } else if (pilih == 3) {
            cout << endl;
            search_data();
        } else if (pilih == 4) {
            cout << endl;
            sorting_data();
        } else if (pilih == 5) {
            cout << endl;
            transaksi_data();
        } else if (pilih == 6) {
            cout << endl;
            cout << "  Program Selesai" << endl;
            cout << endl;
            exit(0);
        } else {
            cout << endl;
            cout << "  Input salah";
            cout << endl;
        }
        cout << endl;
        cout << " Kembali Ke Menu (y/t) : ";
        cin >> ulang;
    } while (toupper(ulang) == 'Y');
    cout << endl;
    cout << "  Program Selesai" << endl;


    return 0;
}

string replaceSpasi(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            str[i] = '_';
        }
    }
    return str;
}

string replaceUnderscore(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '_') {
            str[i] = ' ';
        }
    }
    return str;
}

void tambah_data() {
    system("cls");
    cout << " ==================================" << endl;
    cout << "          TAMBAH DATA STNK         " << endl;
    cout << " ==================================" << endl;

    int banyakdata = 0;

    cout << " Nama file   : ";
    cin >> namafile;
    cout << " jumlah data : ";
    cin >> banyakdata;

    cout << endl;

    for (int i = 0; i < banyakdata; i++) {
        cout << " Masukkan no stnk         : ";
        cin >> stnk[i].nostnk;
        cin.ignore();
        cout << " Masukkan nama pemilik    : ";
        getline(cin, stnk[i].nama);
        cout << " Masukkan jenis kendaraan : ";
        getline(cin, stnk[i].jkendaraan);
        cout << " Masukkan alamat pemilik  : ";
        getline(cin, stnk[i].alamat);
        cout << endl;
    }

    for (int i = 0; i < banyakdata; i++) {
        stnk[i].nama = replaceSpasi(stnk[i].nama);
        stnk[i].jkendaraan = replaceSpasi(stnk[i].jkendaraan);
        stnk[i].alamat = replaceSpasi(stnk[i].alamat);
    }

    ofstream file(namafile, ios::app);
    if (file.is_open()) {
        for (int i = 0; i < banyakdata; i++) {
            file << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
        }
    }
    file.close();
    cout << " Data berhasil ditambahkan" << endl;
}

void tampilkan_data() {
    system("cls");
    cout << " ==================================" << endl;
    cout << "       TAMPILKAN DATA STNK         " << endl;
    cout << " ==================================" << endl;

    int count = 1;
    int i = 0;
    int jumlahdata = 0;

    cout << " Nama file   : ";
    cin >> namafile;

    ifstream file(namafile);

    if (!file) {
        cout << " Gagal membuka file." << endl;
        return;
    }

    while (!file.eof()) {
        file >> stnk[i].nostnk >> stnk[i].nama >> stnk[i].jkendaraan >> stnk[i].alamat;
        i++;
    }
    file.close();
    jumlahdata += i - 1;

    cout << endl;
    cout << " Data STNK :" << endl;
    cout << "   +" << setw(90) << setfill('-') << "+" << endl;
    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
        setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
        setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
        setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
        setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

    for (int i = 0; i < jumlahdata; i++) {
        cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
            setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
            setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
            setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
            setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
        cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
        count++;
    }
}

void search_data() {
    bool found = false;

    system("cls");
    cout << " ==================================" << endl;
    cout << "           CARI DATA STNK          " << endl;
    cout << " ==================================" << endl;

    int milih, milih1, i = 0, banyakdata = 0;
    string stnkk, namaa, jeniss, alamatt;
    cout << " Nama file : ";
    cin >> namafile;
    cout << endl;

    ifstream file(namafile);
    if (!file) {
        cout << " Gagal membuka file." << endl;
        return;
    }

    if (file.is_open()) {
        while (!file.eof()) {
            file >> stnk[i].nostnk >> stnk[i].nama >> stnk[i].jkendaraan >> stnk[i].alamat;
            i++;
        }
        file.close();
        banyakdata += i - 1;

        cout << " ========== PILIH METODE ==========" << endl;
        cout << " |    1. Metode Sequensial        |" << endl;
        cout << " |    2. Metode binary            |" << endl;
        cout << " ==================================" << endl;
        cout << " Silahkan pilih metode    : ";
        cin >> milih;
        cout << endl;

        if (milih == 1) {
            system("cls");
            cout << " ==================================" << endl;
            cout << "           CARI DATA STNK          " << endl;
            cout << " ==================================" << endl<<endl;

            cout << " ===== PILIH SEARCHING DENGAN =====" << endl;
            cout << " |  1. No Stnk                    |" << endl;
            cout << " |  2. Nama Pemilik               |" << endl;
            cout << " |  3. Jenis Kendaraan            |" << endl;
            cout << " |  4. Alamat Pemilik             |" << endl;
            cout << " ==================================" << endl;
            cout << " Silahkan pilih menu    : ";
            cin >> milih1;
            cout << endl;

            if (milih1 == 1) {

                cout << " Masukkan no STNK : ";
                cin >> stnkk;
                cout << endl;

                for (i = 0; i < banyakdata; i++) {
                    if (stnk[i].nostnk == stnkk) {
                        cout << " Data Ditemukan" << endl;
                        cout << " No Stnk           : " << stnk[i].nostnk << endl;
                        cout << " Nama Pemilik      : " << replaceUnderscore(stnk[i].nama) << endl;
                        cout << " Jenis Kendaraan   : " << replaceUnderscore(stnk[i].jkendaraan) << endl;
                        cout << " Alamat Pemilik    : " << replaceUnderscore(stnk[i].alamat) << endl;
                        found = true;
                        cout << endl;
                        cout << " Data berhasil dicari" << endl;
                        break;
                    }
                }
                if (!found) {
                    cout << " Data tidak ditemukan." << endl;
                }
            } else if (milih1 == 2) {

                cout << " Masukkan Nama Pemilik : ";
                cin.ignore();
                getline(cin, namaa);
                cout << endl;

                for (int i = 0; i < banyakdata; i++) {
                    if (replaceSpasi(stnk[i].nama) == replaceSpasi(namaa)) {
                        cout << " Data Ditemukan" << endl;
                        cout << " No Stnk           : " << stnk[i].nostnk << endl;
                        cout << " Nama Pemilik      : " << replaceUnderscore(stnk[i].nama) << endl;
                        cout << " Jenis Kendaraan   : " << replaceUnderscore(stnk[i].jkendaraan) << endl;
                        cout << " Alamat Pemilik    : " << replaceUnderscore(stnk[i].alamat) << endl;
                        cout << endl;
                        found = true;
                        cout << endl;
                        cout << " Data berhasil dicari" << endl;
                        break;
                    }
                }


                if (!found) {
                    cout << " Data tidak ditemukan." << endl;
                }
            } else if (milih1 == 3) {

                cout << " Masukkan Jenis Kendaraan : ";
                cin.ignore();
                getline(cin, jeniss);
                cout << endl;

                for (int i = 0; i < banyakdata; i++) {
                    if (replaceSpasi(stnk[i].jkendaraan) == replaceSpasi(jeniss)) {
                        cout << " Data Ditemukan" << endl;
                        cout << " No Stnk           : " << stnk[i].nostnk << endl;
                        cout << " Nama Pemilik      : " << replaceUnderscore(stnk[i].nama) << endl;
                        cout << " Jenis Kendaraan   : " << replaceUnderscore(stnk[i].jkendaraan) << endl;
                        cout << " Alamat Pemilik    : " << replaceUnderscore(stnk[i].alamat) << endl;
                        cout << endl;
                        found = true;
                        cout << endl;
                        cout << " Data berhasil dicari" << endl;
                        break;
                    }
                }


                if (!found) {
                    cout << " Data tidak ditemukan." << endl;
                }
            } else if (milih1 == 4) {

                cout << " Masukkan Alamat Pemilik: ";
                cin.ignore();
                getline(cin, alamatt);
                cout << endl;

                for (int i = 0; i < banyakdata; i++) {
                    if (replaceSpasi(stnk[i].alamat) == replaceSpasi(alamatt)) {
                        cout << " Data Ditemukan" << endl;
                        cout << " No Stnk           : " << stnk[i].nostnk << endl;
                        cout << " Nama Pemilik      : " << replaceUnderscore(stnk[i].nama) << endl;
                        cout << " Jenis Kendaraan   : " << replaceUnderscore(stnk[i].jkendaraan) << endl;
                        cout << " Alamat Pemilik    : " << replaceUnderscore(stnk[i].alamat) << endl;
                        cout << endl;
                        found = true;
                        cout << endl;
                        cout << " Data berhasil dicari" << endl;
                        break;
                    }
                }


                if (!found) {
                    cout << " Data tidak ditemukan." << endl;
                }
            } else {
                cout << endl;
                cout << " Nomor yang anda masukkan salah" << endl;
            }

        } else if (milih == 2) {
            system("cls");
            cout << " ==================================" << endl;
            cout << "           CARI DATA STNK          " << endl;
            cout << " ==================================" << endl << endl;

            cout << " ===== PILIH SEARCHING DENGAN =====" << endl;
            cout << " |  1. No Stnk                    |" << endl;
            cout << " |  2. Nama Pemilik               |" << endl;
            cout << " |  3. Jenis Kendaraan            |" << endl;
            cout << " |  4. Alamat Pemilik             |" << endl;
            cout << " ==================================" << endl;
            cout << " Silahkan pilih menu    : ";
            cin >> milih1;
            cout << endl;

            if (milih1 == 1) {
                for (int i = 0; i < banyakdata - 1; i++) {
                    int min = i;
                    for (int j = i + 1; j < banyakdata; j++) {
                        if (stnk[j].nostnk < stnk[min].nostnk) {
                            min = j;
                        }
                    }
                    datastnk temp = stnk[i];
                    stnk[i] = stnk[min];
                    stnk[min] = temp;
                }

                //string stnkk;
                cout << " Masukkan No STNK : ";
                cin >> stnkk;
                int low = 0, high = banyakdata - 1, mid;
                bool found = false;
                while (low <= high) {
                    mid = (low + high) / 2;
                    if (stnk[mid].nostnk == stnkk) {
                        found = true;
                        break;
                    } else if (stnk[mid].nostnk < stnkk) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (found) {
                    cout << endl;
                    cout << " Data Ditemukan" << endl;
                    cout << " No Stnk           : " << stnk[mid].nostnk << endl;
                    cout << " Nama Pemilik      : " << replaceUnderscore(stnk[mid].nama) << endl;
                    cout << " Jenis Kendaraan   : " << replaceUnderscore(stnk[mid].jkendaraan) << endl;
                    cout << " Alamat Pemilik    : " << replaceUnderscore(stnk[mid].alamat) << endl;
                    cout << endl;
                } else {
                    cout << " Data tidak ditemukan" << endl;
                }
            }

            if (milih1 == 2) {
                for (int i = 0; i < banyakdata - 1; i++) {
                    int min = i;
                    for (int j = i + 1; j < banyakdata; j++) {
                        if (replaceSpasi(stnk[j].nama) < replaceSpasi(stnk[min].nama)) {
                            min = j;
                        }
                    }
                    datastnk temp = stnk[i];
                    stnk[i] = stnk[min];
                    stnk[min] = temp;
                }

                cout << " Masukkan Nama Pemilik : ";
                cin.ignore();
                getline(cin, namaa);
                int low = 0, high = banyakdata - 1, mid;
                bool found = false;
                while (low <= high) {
                    mid = (low + high) / 2;
                    if (replaceSpasi(stnk[mid].nama) == replaceSpasi(namaa)) {
                        found = true;
                        break;
                    } else if (replaceSpasi(stnk[mid].nama) < replaceSpasi(namaa)) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (found) {
                    cout << endl;
                    cout << " Data Ditemukan" << endl;
                    cout << " No Stnk           : " << stnk[mid].nostnk << endl;
                    cout << " Nama Pemilik      : " << replaceUnderscore(stnk[mid].nama) << endl;
                    cout << " Jenis Kendaraan   : " << replaceUnderscore(stnk[mid].jkendaraan) << endl;
                    cout << " Alamat Pemilik    : " << replaceUnderscore(stnk[mid].alamat) << endl;
                    cout << endl;
                } else {
                    cout << " Data tidak ditemukan" << endl;
                }
            }

            if (milih1 == 3) {
                for (int i = 0; i < banyakdata - 1; i++) {
                    int min = i;
                    for (int j = i + 1; j < banyakdata; j++) {
                        if (replaceSpasi(stnk[j].jkendaraan) < replaceSpasi(stnk[min].jkendaraan)) {
                            min = j;
                        }
                    }
                    datastnk temp = stnk[i];
                    stnk[i] = stnk[min];
                    stnk[min] = temp;
                }

                cout << " Masukkan Jenis Kendaraan : ";
                cin.ignore();
                getline(cin, jeniss);
                int low = 0, high = banyakdata - 1, mid;
                bool found = false;
                while (low <= high) {
                    mid = (low + high) / 2;
                    if (replaceSpasi(stnk[mid].jkendaraan) == replaceSpasi(jeniss)) {
                        found = true;
                        break;
                    } else if (replaceSpasi(stnk[mid].jkendaraan) < replaceSpasi(jeniss)) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (found) {
                    cout << endl;
                    cout << " Data Ditemukan" << endl;
                    cout << " No Stnk           : " << stnk[mid].nostnk << endl;
                    cout << " Nama Pemilik      : " << replaceUnderscore(stnk[mid].nama) << endl;
                    cout << " Jenis Kendaraan   : " << replaceUnderscore(stnk[mid].jkendaraan) << endl;
                    cout << " Alamat Pemilik    : " << replaceUnderscore(stnk[mid].alamat) << endl;
                    cout << endl;
                } else {
                    cout << " Data tidak ditemukan" << endl;
                }
            }

            if (milih1 == 4) {
                for (int i = 0; i < banyakdata - 1; i++) {
                    int min = i;
                    for (int j = i + 1; j < banyakdata; j++) {
                        if (replaceSpasi(stnk[j].alamat) < replaceSpasi(stnk[min].alamat)) {
                            min = j;
                        }
                    }
                    datastnk temp = stnk[i];
                    stnk[i] = stnk[min];
                    stnk[min] = temp;
                }

                cout << " Masukkan Alamat Pemilik : ";
                cin.ignore();
                getline(cin, alamatt);
                int low = 0, high = banyakdata - 1, mid;
                bool found = false;
                while (low <= high) {
                    mid = (low + high) / 2;
                    if (replaceSpasi(stnk[mid].alamat) == replaceSpasi(alamatt)) {
                        found = true;
                        break;
                    } else if (replaceSpasi(stnk[mid].alamat) < replaceSpasi(alamatt)) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (found) {
                    cout << endl;
                    cout << " Data Ditemukan" << endl;
                    cout << " No Stnk           : " << stnk[mid].nostnk << endl;
                    cout << " Nama Pemilik      : " << replaceUnderscore(stnk[mid].nama) << endl;
                    cout << " Jenis Kendaraan   : " << replaceUnderscore(stnk[mid].jkendaraan) << endl;
                    cout << " Alamat Pemilik    : " << replaceUnderscore(stnk[mid].alamat) << endl;
                    cout << endl;
                } else {
                    cout << " Data tidak ditemukan" << endl;
                }
            }
        }

    } else {
        cout << " Gagal membuka file" << endl;
    }

    cout << endl;
}

void sorting_data() {
    system("cls");
    cout << " ==================================" << endl;
    cout << "          SORTING DATA STNK        " << endl;
    cout << " ==================================" << endl;

    int count = 1, milih2, milih3, i = 0, banyakdata = 0;

    cout << " Nama file : ";
    cin >> namafile;
    cout << endl;

    ifstream file(namafile);
    if (!file) {
        cout << " Gagal membuka file." << endl;
        return;
    }
    if (file.is_open()) {
        while (!file.eof()) {
            file >> stnk[i].nostnk >> stnk[i].nama >> stnk[i].jkendaraan >> stnk[i].alamat;
            i++;
        }
        file.close();
        banyakdata += i - 1;

        cout << " ========== PILIH METODE ==========" << endl;
        cout << " |   1. Metode Bubble Sort        |" << endl;
        cout << " |   2. Metode Selection Sort     |" << endl;
        cout << " |   3. Metode Insertion Sort     |" << endl;
        cout << " |   4. Metode Shell Sort         |" << endl;
        cout << " ==================================" << endl;
        cout << " Silahkan pilih menu    : ";
        cin >> milih2;
        cout << endl;

        if (milih2 == 1) //BUBBLE
        {
            system("cls");
            cout << " ==================================" << endl;
            cout << "        SORTING DATA STNK          " << endl;
            cout << " ==================================" << endl << endl;

            cout << " ====== PILIH SORTING DENGAN ======" << endl;
            cout << " |  1. No Stnk                    |" << endl;
            cout << " |  2. Nama Pemilik               |" << endl;
            cout << " |  3. Jenis Kendaraan            |" << endl;
            cout << " |  4. Alamat Pemilik             |" << endl;
            cout << " ==================================" << endl;
            cout << " Silahkan pilih menu    : ";
            cin >> milih3;
            cout << endl;

            if (milih3 == 1) //BUBBLE 1
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;


                for (int i = 0; i < banyakdata - 1; i++) {
                    for (int j = 0; j < banyakdata - i - 1; j++) {
                        if (stnk[j].nostnk > stnk[j + 1].nostnk) {
                            datastnk temp = stnk[j];
                            stnk[j] = stnk[j + 1];
                            stnk[j + 1] = temp;
                        }
                    }
                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan no stnk :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 == 2) //bubble 2
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;


                for (int i = 0; i < banyakdata - 1; i++) {
                    for (int j = 0; j < banyakdata - i - 1; j++) {
                        if (stnk[j].nama > stnk[j + 1].nama) {
                            datastnk temp = stnk[j];
                            stnk[j] = stnk[j + 1];
                            stnk[j + 1] = temp;
                        }
                    }
                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan nama pemilik :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 == 3) //bubble 3
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;


                for (int i = 0; i < banyakdata - 1; i++) {
                    for (int j = 0; j < banyakdata - i - 1; j++) {
                        if (stnk[j].jkendaraan > stnk[j + 1].jkendaraan) {
                            datastnk temp = stnk[j];
                            stnk[j] = stnk[j + 1];
                            stnk[j + 1] = temp;
                        }
                    }
                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan jenis kendaraan :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 == 4) //bubble 4
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;


                for (int i = 0; i < banyakdata - 1; i++) {
                    for (int j = 0; j < banyakdata - i - 1; j++) {
                        if (stnk[j].alamat > stnk[j + 1].alamat) {
                            datastnk temp = stnk[j];
                            stnk[j] = stnk[j + 1];
                            stnk[j + 1] = temp;
                        }
                    }
                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan jenis kendaraan :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 > 4) {
                cout << " Nomor yang anda pilih tidak ada" << endl;
            }

        } else if (milih2 == 2) //SELECTION
        {
            system("cls");
            cout << " ==================================" << endl;
            cout << "        SORTING DATA STNK          " << endl;
            cout << " ==================================" << endl << endl;

            cout << " ====== PILIH SORTING DENGAN ======" << endl;
            cout << " |  1. No Stnk                    |" << endl;
            cout << " |  2. Nama Pemilik               |" << endl;
            cout << " |  3. Jenis Kendaraan            |" << endl;
            cout << " |  4. Alamat Pemilik             |" << endl;
            cout << " ==================================" << endl;
            cout << " Silahkan pilih menu    : ";
            cin >> milih3;
            cout << endl;

            if (milih3 == 1) //selection 1
            {

                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;

                int current;
                for (current = 0; current < banyakdata; current++) {
                    for (int j = current + 1; j < banyakdata; j++) {
                        if (stnk[current].nostnk > stnk[j].nostnk) {
                            datastnk temp = stnk[current];
                            stnk[current] = stnk[j];
                            stnk[j] = temp;
                        }
                    }
                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan no stnk :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }

            } else if (milih3 == 2) //selection 2
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;

                int current;
                for (current = 0; current < banyakdata; current++) {
                    for (int j = current + 1; j < banyakdata; j++) {
                        if (replaceUnderscore(stnk[current].nama) > replaceUnderscore(stnk[j].nama)) {
                            datastnk temp = stnk[current];
                            stnk[current] = stnk[j];
                            stnk[j] = temp;
                        }
                    }
                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan nama pemilik :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 == 3) //selection 3
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;

                int current;
                for (current = 0; current < banyakdata; current++) {
                    for (int j = current + 1; j < banyakdata; j++) {
                        if (replaceUnderscore(stnk[current].jkendaraan) > replaceUnderscore(stnk[j].jkendaraan)) {
                            datastnk temp = stnk[current];
                            stnk[current] = stnk[j];
                            stnk[j] = temp;
                        }
                    }
                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan jenis kendaraan :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 == 4) //selection 4
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;

                int current;
                for (current = 0; current < banyakdata; current++) {
                    for (int j = current + 1; j < banyakdata; j++) {
                        if (replaceUnderscore(stnk[current].alamat) > replaceUnderscore(stnk[j].alamat)) {
                            datastnk temp = stnk[current];
                            stnk[current] = stnk[j];
                            stnk[j] = temp;
                        }
                    }
                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan alamat pemilik :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 > 4) {
                cout << " Nomor yang anda pilih tidak ada" << endl;
            }
        } else if (milih2 == 3) //INSERTION
        {
            system("cls");
            cout << " ==================================" << endl;
            cout << "        SORTING DATA STNK          " << endl;
            cout << " ==================================" << endl << endl;

            cout << " ====== PILIH SORTING DENGAN ======" << endl;
            cout << " |  1. No Stnk                    |" << endl;
            cout << " |  2. Nama Pemilik               |" << endl;
            cout << " |  3. Jenis Kendaraan            |" << endl;
            cout << " |  4. Alamat Pemilik             |" << endl;
            cout << " ==================================" << endl;
            cout << " Silahkan pilih menu    : ";
            cin >> milih3;
            cout << endl;

            if (milih3 == 1) //insertion 1
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;

                int i, j, k;
                for (i = 1; i < banyakdata; i++) {
                    datastnk temp = stnk[i];
                    j = i - 1;
                    while ((temp.nostnk < stnk[j].nostnk) && (j >= 0)) {
                        stnk[j + 1] = stnk[j];
                        j = j - 1;
                    }
                    stnk[j + 1] = temp;

                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan no stnk :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }

            } else if (milih3 == 2) //insertion 2
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;

                int i, j, k;
                for (i = 1; i < banyakdata; i++) {
                    datastnk temp = stnk[i];
                    j = i - 1;
                    while ((replaceUnderscore(temp.nama) < replaceUnderscore(stnk[j].nama)) && (j >= 0)) {
                        stnk[j + 1] = stnk[j];
                        j = j - 1;
                    }
                    stnk[j + 1] = temp;

                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan nama pemilik :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 == 3) //insertion 3
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;

                int i, j, k;
                for (i = 1; i < banyakdata; i++) {
                    datastnk temp = stnk[i];
                    j = i - 1;
                    while ((replaceUnderscore(temp.jkendaraan) < replaceUnderscore(stnk[j].jkendaraan)) && (j >= 0)) {
                        stnk[j + 1] = stnk[j];
                        j = j - 1;
                    }
                    stnk[j + 1] = temp;

                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan jenis kendaraan :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 == 4) //insertion 4
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;

                int i, j, k;
                for (i = 1; i < banyakdata; i++) {
                    datastnk temp = stnk[i];
                    j = i - 1;
                    while ((replaceUnderscore(temp.alamat) < replaceUnderscore(stnk[j].alamat)) && (j >= 0)) {
                        stnk[j + 1] = stnk[j];
                        j = j - 1;
                    }
                    stnk[j + 1] = temp;

                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan alamat pemilik :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 > 4) {
                cout << " Nomor yang anda pilih tidak ada" << endl;
            }
        } else if (milih2 == 4) //SHELL
        {
            system("cls");
            cout << " ==================================" << endl;
            cout << "        SORTING DATA STNK          " << endl;
            cout << " ==================================" << endl << endl;

            cout << " ====== PILIH SORTING DENGAN ======" << endl;
            cout << " |  1. No Stnk                    |" << endl;
            cout << " |  2. Nama Pemilik               |" << endl;
            cout << " |  3. Jenis Kendaraan            |" << endl;
            cout << " |  4. Alamat Pemilik             |" << endl;
            cout << " ==================================" << endl;
            cout << " Silahkan pilih menu    : ";
            cin >> milih3;
            cout << endl;

            if (milih3 == 1) //shell 1
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;

                int gap = banyakdata / 2;
                while (gap > 0) {
                    for (int i = gap; i < banyakdata; i++) {
                        datastnk temp = stnk[i];
                        int j = i;
                        while (j >= gap && stnk[j - gap].nostnk > temp.nostnk) {
                            stnk[j] = stnk[j - gap];
                            j -= gap;
                        }
                        stnk[j] = temp;
                    }
                    gap /= 2;
                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan no stnk :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 == 2) //shell 2
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;

                int gap = banyakdata / 2;
                while (gap > 0) {
                    for (int i = gap; i < banyakdata; i++) {
                        datastnk temp = stnk[i];
                        int j = i;
                        while (j >= gap && replaceSpasi(stnk[j - gap].nama) > replaceSpasi(temp.nama)) {
                            stnk[j] = stnk[j - gap];
                            j -= gap;
                        }
                        stnk[j] = temp;
                    }
                    gap /= 2;
                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan nama pemilik :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 == 3) //shell 3
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;

                int gap = banyakdata / 2;
                while (gap > 0) {
                    for (int i = gap; i < banyakdata; i++) {
                        datastnk temp = stnk[i];
                        int j = i;
                        while (j >= gap && replaceSpasi(stnk[j - gap].jkendaraan) > replaceSpasi(temp.jkendaraan)) {
                            stnk[j] = stnk[j - gap];
                            j -= gap;
                        }
                        stnk[j] = temp;
                    }
                    gap /= 2;
                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan jenis kendaraan :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 == 4) //shell 4
            {
                string namafilesort;

                cout << " Silahkan masukan nama file sort : ";
                cin >> namafilesort;

                int gap = banyakdata / 2;
                while (gap > 0) {
                    for (int i = gap; i < banyakdata; i++) {
                        datastnk temp = stnk[i];
                        int j = i;
                        while (j >= gap && replaceSpasi(stnk[j - gap].alamat) > replaceSpasi(temp.alamat)) {
                            stnk[j] = stnk[j - gap];
                            j -= gap;
                        }
                        stnk[j] = temp;
                    }
                    gap /= 2;
                }

                ofstream ofssort(namafilesort);
                for (int i = 0; i < banyakdata; i++) {
                    ofssort << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                }
                ofssort.close();

                cout << " Data STNK berdasarkan alamat pemilik :" << endl;
                cout << "   +" << setw(90) << setfill('-') << "+" << endl;
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
                    setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
                    setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
                    setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
                    setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
                cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

                for (int i = 0; i < banyakdata; i++) {
                    cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                        setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                        setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                        setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                        setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
                    cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
                    count++;
                }
            } else if (milih3 > 4) {
                cout << " Nomor yang anda pilih tidak ada" << endl;
            }

        } else {
            cout << " Nomor yang anda pilih tidak ada" << endl;
        }


    }


}

void transaksi_data() {
    system("cls");
    cout << " ==================================" << endl;
    cout << "        TRANSAKSI DATA STNK        " << endl;
    cout << " ==================================" << endl<<endl;

    int milih4;

    cout << " ===== PILIH METODE TRANSAKSI =====" << endl;
    cout << " |   1. Merging                   |" << endl;
    cout << " |   2. Updating                  |" << endl;
    cout << " |   3. Splitting                 |" << endl;
    cout << " ==================================" << endl;
    cout << " Silahkan pilih menu    : ";
    cin >> milih4;
    cout << endl;

    if (milih4 == 1) {
        int i = 0, j = 0, banyakdata1 = 0, banyakdata2 = 0, count = 1;
        string file1, file2, file3;

        system("cls");
        cout << " ==================================" << endl;
        cout << "          MERGE DATA STNK          " << endl;
        cout << " ==================================" << endl << endl;
        cout << " Nama File pertama: ";
        cin >> file1;

        ifstream ifs1(file1);
        if (!ifs1) {
        cout << " Gagal membuka file." << endl;
        return;
        }
        while (!ifs1.eof()) {
            ifs1 >> stnk[i].nostnk >> stnk[i].nama >> stnk[i].jkendaraan >> stnk[i].alamat;
            i++;
        }
        ifs1.close();

        banyakdata1 += i - 1;

        cout << " Data STNK :" << endl;
        cout << "   +" << setw(90) << setfill('-') << "+" << endl;
        cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
            setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
            setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
            setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
            setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
        cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

        for (int i = 0; i < banyakdata1; i++) {
            cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                setw(3) << setfill(' ') << "|" << setw(12) << stnk[i].nostnk <<
                setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnk[i].nama) <<
                setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnk[i].jkendaraan) <<
                setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnk[i].alamat) << "|" << endl;
            cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
            count++;
        }

        cout << " Nama File kedua : ";
        cin >> file2;

        datastnk stnkdua[100];

        ifstream ifs2(file2);

        if (!ifs2) {
        cout << " Gagal membuka file." << endl;
        return;
        }

        while (!ifs2.eof()) {
            ifs2 >> stnkdua[j].nostnk >> stnkdua[j].nama >> stnkdua[j].jkendaraan >> stnkdua[j].alamat;
            j++;
        }
        ifs2.close();
        banyakdata2 += j - 1;

        cout << " Data STNK :" << endl;
        cout << "   +" << setw(90) << setfill('-') << "+" << endl;
        cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO" <<
            setw(3) << setfill(' ') << "|" << setw(12) << "NO STNK" <<
            setw(6) << setfill(' ') << "|" << setw(17) << "NAMA PEMILIK" <<
            setw(3) << setfill(' ') << "|" << setw(18) << "JENIS KENDARAAN" <<
            setw(5) << setfill(' ') << "|" << setw(19) << "ALAMAT PEMILIK" << "|" << endl;
        cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;

        count = 1;
        for (int j = 0; j < banyakdata2; j++) {
            cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count <<
                setw(3) << setfill(' ') << "|" << setw(12) << stnkdua[j].nostnk <<
                setw(6) << setfill(' ') << "|" << setw(17) << replaceUnderscore(stnkdua[j].nama) <<
                setw(3) << setfill(' ') << "|" << setw(18) << replaceUnderscore(stnkdua[j].jkendaraan) <<
                setw(5) << setfill(' ') << "|" << setw(19) << replaceUnderscore(stnkdua[j].alamat) << "|" << endl;
            cout << right << "   +" << setw(90) << setfill('-') << "+" << endl;
            count++;
        }

        cout << " Masukkan nama file hasil merge : ";
        cin >> file3;

        ofstream ofs(file3);
        if (ofs.is_open()) {
            for (int i = 0; i < banyakdata1; i++) {
                ofs << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
            }
            for (int j = 0; j < banyakdata2; j++) {
                ofs << stnkdua[j].nostnk << " " << stnkdua[j].nama << " " << stnkdua[j].jkendaraan << " " << stnkdua[j].alamat << endl;
            }
            ofs.close();

        }

        cout << " Data berhasil disimpan di file " << endl;
    } else if (milih4 == 2) //UPDATING
    {
        system("cls");
        cout << " ==================================" << endl;
        cout << "          UPDATE DATA STNK         " << endl;
        cout << " ==================================" << endl << endl;

        cout << " Nama file   : ";
        cin >> namafile;

        ifstream file(namafile);

        if (!file) {
        cout << " Gagal membuka file." << endl;
        return;
        }

        int banyakdata = 0;

        if (file.is_open()) {
            while (!file.eof()) {
                file >> stnk[i].nostnk >> stnk[i].nama >> stnk[i].jkendaraan >> stnk[i].alamat;
                i++;
            }
            file.close();
            banyakdata += i - 1;

            string no, no_edit, nama_edit, jkendaraan_edit, alamat_edit;
            bool found = false;

            cout << endl;

            cout << " Masukkan no stnk (untuk mencari data) : ";
            cin >> no;
            cout << " Masukkan no stnk yang baru            : ";
            cin >> no_edit;
            cin.ignore();

            cout << " Masukkan nama pemilik yang baru       : ";
            //cin.ignore();
            getline(cin, nama_edit);

            cout << " Masukkan jenis kendaraan yang baru    : ";
            //cin.ignore();
            getline(cin, jkendaraan_edit);

            cout << " Masukkan alamat pemilik yang baru     : ";
            //cin.ignore();
            getline(cin, alamat_edit);

            for (int i = 0; i < banyakdata; i++) {
                if (stnk[i].nostnk == no) {
                    stnk[i].nostnk = replaceSpasi(no_edit);
                    stnk[i].nama = replaceSpasi(nama_edit);
                    stnk[i].jkendaraan = replaceSpasi(jkendaraan_edit);
                    stnk[i].alamat = replaceSpasi(alamat_edit);

                    found = true;
                    break;
                }
            }

            if (found) {
                cout << endl;
                cout << " Masukkan Nama File Hasil Updating : ";
                string fileUpdate;
                cin >> fileUpdate;

                ofstream file_out(fileUpdate);
                if (file_out.is_open()) {
                    for (int i = 0; i < banyakdata; i++) {
                        file_out << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
                    }
                    file_out.close();
                    cout << " Data berhasil diubah" << endl;
                } else {
                    cout << " Tidak dapat membuka file untuk penulisan" << endl;
                }
            } else {
                cout << " Tidak ditemukan" << endl;
            }
        }
    } else if (milih4 == 3) {
    int i = 0, banyakData = 0, atas;
    string file1, file2;

    system("cls");
    cout << " ==================================" << endl;
    cout << "          SPLITTING DATA STNK          " << endl;
    cout << " ==================================" << endl << endl;

    cout << " Masukkan Nama File : ";
    cin >> namafile;

    ifstream file(namafile);

    if (!file) {
        cout << " Gagal membuka file." << endl;
        return;
    }

    if (file.is_open()) {
        while (!file.eof()) {
            file >> stnk[i].nostnk >> stnk[i].nama >> stnk[i].jkendaraan >> stnk[i].alamat;
            i++;
        }
        file.close();
        banyakData += i - 1;

        if (banyakData > 2) {
            atas = banyakData / 2;
            //bawah = banyakData - atas;

            cout << " Masukkan Nama File hasil splitting pertama : ";
            cin >> file1;

            ofstream ofs(file1);
            for (i = 0; i < atas; i++) {
                ofs << stnk[i].nostnk << " " << stnk[i].nama << " " << stnk[i].jkendaraan << " " << stnk[i].alamat << endl;
            }
            ofs.close();

            cout << " Masukkan Nama File hasil splitting kedua : ";
            cin >> file2;

            ofstream ofs1(file2);
            for (atas; atas < banyakData; atas++) {
                ofs1 << stnk[atas].nostnk << " " << stnk[atas].nama << " " << stnk[atas].jkendaraan << " " << stnk[atas].alamat << endl;
            }
            ofs1.close();

            cout << " Splitting berhasil." << endl;
        } else if (banyakData < 2) {
            cout << " Data tidak bisa di split karena hanya terdapat 1 data" << endl;
        }
    }
}
 else if (milih4 > 4) {
        cout << " Nomor yang anda pilih tidak ada" << endl;
    }



}

/*pointer
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl;
    cout << left << setw (9) <<setfill (' ') << " "<<setw(34)<< " >> PROGRAM POINTER << "<<" " << endl;
    cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl<<endl;

    int a;
    int *pointera = &a;
    int *pointerb = pointera;

    cout << "   Input a : ";
    cin >> a;

    int c = a + 30;

    cout << "   Nilai a : " << *pointera << " (Memory Address : " << pointera << ")" << endl;
    cout << "   Nilai b : " << *pointerb << " (Memory Address : " << pointerb << ")" << endl;
    cout << "   Nilai c : " <<     c     << " (Memory Address : " <<    &c    << ")" << endl;
    cout << endl;

    cout << "   b + 10 " << endl;
    cout << "   Nilai a : " << *pointera + 10 << " (Memory Address : " << pointera << ")" << endl;
    cout << "   Nilai b : " << *pointerb + 10 << " (Memory Address : " << pointerb << ")" << endl;

  return 0;
}
*/

/*delete
void hapus_data() {
    system("cls");
    cout << right << " " << setw(41) << setfill('-') << " " << endl;
    cout << left << setw(7) << setfill(' ') << " " << setw(34) << " >> HAPUS DATA PENJUALAN << " << " " << endl;
    cout << right << " " << setw(41) << setfill('-') << " " << endl;

    ifstream file("databarang.txt");
    int jumlah_data = 0;

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            ss >> barang[jumlah_data].id_barang;
            ss.ignore();
            getline(ss, barang[jumlah_data].nama_barang, ';');
            getline(ss, barang[jumlah_data].kategori, ';');
            ss >> barang[jumlah_data].harga_satuan;
            ss.ignore();
            ss >> barang[jumlah_data].jumlah_barang;
            ss.ignore();
            getline(ss, barang[jumlah_data].suplier, ';');
            ss.ignore();

            jumlah_data++;
        }

        file.close();

        int id_barang_hapus;
        bool found = false;

        cout << "   Masukkan ID barang yang akan dihapus : ";
        cin >> id_barang_hapus;

        for (int i = 0; i < jumlah_data; i++) {
            if (barang[i].id_barang == id_barang_hapus) {
                for (int j = i; j < jumlah_data - 1; j++) {
                    barang[j] = barang[j + 1];
                }
                jumlah_data--;
                found = true;
                break;
            }
        }

        if (found) {
            ofstream file_out("databarang.txt");
            if (file_out.is_open()) {
                for (int i = 0; i < jumlah_data; i++) {
                    file_out << barang[i].id_barang << ";" << barang[i].nama_barang << ";" << barang[i].kategori << ";" << barang[i].harga_satuan << ";"
                             << barang[i].jumlah_barang << ";" << barang[i].suplier << endl;
                }
                file_out.close();
                cout << "   Data berhasil dihapus" << endl;
            } else {
                cout << "   Tidak dapat membuka file untuk penulisan" << endl;
            }
        } else {
            cout << "   ID barang tidak ditemukan" << endl;
        }
    } else {
        cout << "   Tidak dapat membuka file" << endl;
    }
}
*/
