#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

struct databarang
{
    string nama_barang, kategori, suplier;
    int harga_satuan, jumlah_barang, id_barang;
};

void tampilkan_data();
void tambah_data();
void sorting_data();
void hapus_data();

databarang barang[100];
int i,n;

int main (){

    int pilih;
    char ulang = 'Y';

    do{
    system("cls");
    cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl;
    cout << left << setw (7) <<setfill (' ') << " "<<setw(34)<< " >> PROGRAM DATA BARANG << "<<" " << endl;
    cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl;

    cout << left << setw (16) <<setfill ('=') << " "<<setw(25)<< " PILIHAN "<<" " << endl;
    cout << left << setw (4) <<setfill (' ') << " |"<<setw(36)<< " 1. Input Data Barang"<<"|" <<endl;
    cout << left << setw (4) <<setfill (' ') << " |"<<setw(36)<< " 2. Urutkan Data Barang"<<"|" <<endl;
    cout << left << setw (4) <<setfill (' ') << " |"<<setw(36)<< " 3. Tampilkan Data Barang"<<"|" <<endl;
    cout << left << setw (4) <<setfill (' ') << " |"<<setw(36)<< " 4. Keluar dari Program"<<"|" <<endl;
    cout << right <<" " <<setw (41)<<setfill ('=')<<" "<<endl;
    cout << left << setw (2) <<setfill (' ') << " "<<setw(23)<< "Silahkan pilih menu yang tersedia = ";
	cin >> pilih;

	if(pilih == 1){
		cout<<endl;
		tambah_data();
		}
    else if(pilih == 2){
		cout<<endl;
		sorting_data();
		}
    else if(pilih == 3){
		cout<<endl;
		tampilkan_data();
		}
    else if (pilih == 4){
        cout<<endl;
		cout<<"  Program Selesai"<<endl;
		cout<<endl;
		exit(0);
        }
    else {
        cout<<endl;
        cout << "  Input salah";
        cout<<endl;
    }
    cout<<endl;
    cout << "  Kembali Ke Menu (y/t) : "; cin >> ulang;
    } while (toupper(ulang)=='Y');
    cout<<endl;
	cout<<"  Program Selesai"<<endl;


    return 0;
}

void tambah_data() {

    system("cls");
    cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl;
    cout << left << setw (7) <<setfill (' ') << " "<<setw(34)<< " >> MENU DATA BARANG << "<<" " << endl;
    cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl;

    int milih;

    cout << left << setw (16) <<setfill ('=') << " "<<setw(25)<< " PILIHAN "<<" " << endl;
    cout << left << setw (4) <<setfill (' ') << " |"<<setw(36)<< " 1. Tambah Data Barang"<<"|" <<endl;
    cout << left << setw (4) <<setfill (' ') << " |"<<setw(36)<< " 2. Hapus Data Barang"<<"|" <<endl;
    cout << right <<" " <<setw (41)<<setfill ('=')<<" "<<endl;
    cout << left << setw (2) <<setfill (' ') << " "<<setw(23)<< "Silahkan pilih menu yang tersedia = ";
	cin >> milih;
    cout << endl;

        if (milih ==1 )
        {
            system("cls");
            cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl;
            cout << left << setw (7) <<setfill (' ') << " "<<setw(34)<< " >> TAMBAH DATA BARANG << "<<" " << endl;
            cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl;

            ofstream file("databarang.txt", ios::app);

            cout << " Jumlah data : ";
            cin >> n;

            cout << endl;

                for (i=0; i<n; i++)
                {
                    cout << "   Masukkan kode barang        : ";
                    cin >> barang[i].id_barang;

                    cin.ignore();
                    cout << "   Masukkan nama barang        : ";
                    getline(cin,barang[i].nama_barang);

                    cout << "   Masukkan kategori barang    : ";
                    getline(cin,barang[i].kategori);

                    cout << "   Masukkan harga barang       : ";
                    cin >> barang[i].harga_satuan;

                    cout << "   Masukkan jumlah barang      : ";
                    cin >> barang[i].jumlah_barang;

                    cin.ignore();
                    cout << "   Masukkan nama supplier      : ";
                    getline(cin,barang[i].suplier);


                    cout<<endl;

                }

                if (file.is_open())
                {
                    for (int i = 0; i < n; i++)
                    {
                        file << barang[i].id_barang << ";" << barang[i].nama_barang << ";" << barang[i].kategori << ";" << barang[i].harga_satuan << ";"
                             << barang[i].jumlah_barang << ";" << barang[i].suplier << endl;


                    }
                }
                file.close();
                        cout << "   Data berhasil ditambahkan" << endl;

        }

        else if (milih==2)
        {
            hapus_data();
        }
}

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

void tampilkan_data() {
    system("cls");
    cout << right << " " << setw(41) << setfill('-') << " " << endl;
    cout << left << setw(9) << setfill(' ') << " " << setw(34) << " >> DATA BARANG << " << " " << endl;
    cout << right << " " << setw(41) << setfill('-') << " " << endl;

    ifstream file("databarang.txt");

    if (file.is_open()) {
        cout << "  Data Barang:" << endl;
        cout << "   +" << setw(95) << setfill('-') << "+" << endl;
        cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO"
             << setw(3) << setfill(' ') << "|" << setw(12) << "ID Barang"
             << setw(6) << setfill(' ') << "|" << setw(15) << "Nama Barang"
             << setw(3) << setfill(' ') << "|" << setw(10) << "Kategori"
             << setw(3) << setfill(' ') << "|" << setw(10) << "Harga"
             << setw(3) << setfill(' ') << "|" << setw(10) << "Jumlah"
             << setw(3) << setfill(' ') << "|" << setw(10) << "Supplier" << "|" << endl;
        cout << right << "   +" << setw(95) << setfill('-') << "+" << endl;

        int count = 1;
        int i = 0;
        string line;

        while (getline(file, line)) {
            stringstream ss(line);
            ss >> barang[i].id_barang;
            ss.ignore();
            getline(ss, barang[i].nama_barang, ';');
            getline(ss, barang[i].kategori, ';');
            ss >> barang[i].harga_satuan;
            ss.ignore();
            ss >> barang[i].jumlah_barang;
            ss.ignore();
            getline(ss, barang[i].suplier, ';');
            ss.ignore();

            if (!barang[i].nama_barang.empty() && barang[i].id_barang != -1) {
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << count
                     << setw(3) << setfill(' ') << "|" << setw(12) << barang[i].id_barang
                     << setw(6) << setfill(' ') << "|" << setw(15) << barang[i].nama_barang
                     << setw(3) << setfill(' ') << "|" << setw(10) << barang[i].kategori
                     << setw(3) << setfill(' ') << "|" << setw(10) << barang[i].harga_satuan
                     << setw(3) << setfill(' ') << "|" << setw(10) << barang[i].jumlah_barang
                     << setw(3) << setfill(' ') << "|" << setw(10) << barang[i].suplier << "|" << endl;
                cout << right << "   +" << setw(95) << setfill('-') << "+" << endl;

                count++;
            }
            i++;
        }
    } else {
        cout << "   Tidak dapat membuka file" << endl;
    }
    file.close();
}

void sorting_data() {
    system("cls");
    cout << right << " " << setw(41) << setfill('-') << " " << endl;
    cout << left << setw(9) << setfill(' ') << " " << setw(34) << " >> URUTKAN DATA BARANG << " << " " << endl;
    cout << right << " " << setw(41) << setfill('-') << " " << endl;

    ifstream file("databarang.txt");

    if (file.is_open()) {
        int jumlah_data = 0;
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

        //menggunakan bubble
        for (int i = 0; i < jumlah_data - 1; i++) {
            for (int j = 0; j < jumlah_data - i - 1; j++) {
                if (barang[j].jumlah_barang < barang[j + 1].jumlah_barang) {
                    databarang temp = barang[j];
                    barang[j] = barang[j + 1];
                    barang[j + 1] = temp;
                }
            }
        }

        cout << "  Data Barang (Diurutkan berdasarkan total barang dari yang tertinggi):" << endl;
        cout << "   +" << setw(95) << setfill('-') << "+" << endl;
        cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << "NO"
             << setw(3) << setfill(' ') << "|" << setw(12) << "ID Barang"
             << setw(6) << setfill(' ') << "|" << setw(15) << "Nama Barang"
             << setw(3) << setfill(' ') << "|" << setw(10) << "Kategori"
             << setw(3) << setfill(' ') << "|" << setw(10) << "Harga"
             << setw(3) << setfill(' ') << "|" << setw(10) << "Jumlah"
             << setw(3) << setfill(' ') << "|" << setw(10) << "Supplier" << "|" << endl;
        cout << right << "   +" << setw(95) << setfill('-') << "+" << endl;

        for (int i = 0; i < jumlah_data; i++) {
            if (!barang[i].nama_barang.empty() && barang[i].id_barang != -1) {
                cout << left << setw(6) << setfill(' ') << "   |" << setw(4) << i + 1
                     << setw(3) << setfill(' ') << "|" << setw(12) << barang[i].id_barang
                     << setw(6) << setfill(' ') << "|" << setw(15) << barang[i].nama_barang
                     << setw(3) << setfill(' ') << "|" << setw(10) << barang[i].kategori
                     << setw(3) << setfill(' ') << "|" << setw(10) << barang[i].harga_satuan
                     << setw(3) << setfill(' ') << "|" << setw(10) << barang[i].jumlah_barang
                     << setw(3) << setfill(' ') << "|" << setw(10) << barang[i].suplier << "|" << endl;
                cout << right << "   +" << setw(95) << setfill('-') << "+" << endl;
            }
        }
                cout << endl;
        } else {
                cout << "   Tidak dapat membuka file" << endl;
        }

}






