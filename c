

















































#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <conio.h>

using namespace std;

struct service
{
    string nama[20];
    int harga[20];
};

bool login();
void masukdata();
void keluardata();
void pencarian();
void sorting();

int batas, data;
const string uname = "Mohamad Risqi Aditiya";
const string pword = "123220021";
bool berhasil = false;

service srv[20];

int main (){

    int pilih;
    char ulang = 'Y';

    do{
    system("cls");
    cout << " " << setw (41) << setfill ('-')<< " "<< endl;
    cout << left << setw (1) << setfill (' ') << " "<< setw(34) << " >> PROGRAM MANAGEMENT SERVICE MOTOR << "<<" " << endl;
    cout << right <<" " <<setw (41) << setfill ('-') << " " << endl;

    cout << left << setw (16) << setfill ('=') << " "<< setw(25) << " PILIHAN "<< " " << endl;
    cout << left << setw (4) << setfill (' ') << " |"<< setw(36) << " 0. Login"<< "|" << endl;
    cout << left << setw (4) << setfill (' ') << " |"<< setw(36) << " 1. Input Data dan Tambah Data" << "|" <<endl;
    cout << left << setw (4) << setfill (' ') << " |"<< setw(36) << " 2. Output Data" << "|" << endl;
    cout << left << setw (4) << setfill (' ') << " |"<< setw(36) << " 3. Pencarian Data" << "|" << endl;
    cout << left << setw (4) << setfill (' ') << " |"<< setw(36) << " 4. Sorting Data"<< "|" << endl;
    cout << left << setw (4) << setfill (' ') << " |"<< setw(36) << " 5. Keluar dari Program" << "|" << endl;
    cout << right <<" " <<setw (41)<< setfill ('=') << " " << endl;
    cout << left << setw (2) <<setfill (' ') << " "<< setw(23) << "Silahkan pilih menu yang tersedia = ";
	cin >> pilih;

    if(pilih == 0){
		cout<<endl;
        berhasil = login();
    }
	else if(pilih == 1){
		cout<<endl;
		if (!berhasil) {
            cout << "   Anda harus login terlebih dahulu!\n";
        } else {
            masukdata();
        }
    }
    else if(pilih == 2){
		cout<<endl;
		if (!berhasil) {
            cout << "   Anda harus login terlebih dahulu!\n";
        } else {
            keluardata();
        }
    }
    else if(pilih == 3){
		cout<<endl;
		if (!berhasil) {
            cout << "   Anda harus login terlebih dahulu!\n";
        } else {
            pencarian();
        }
    }
    else if(pilih == 4){
		cout<<endl;
		if (!berhasil) {
            cout << "   Anda harus login terlebih dahulu!\n";
        } else {
            sorting();
        }
    }
    else if (pilih == 5){
        cout<<endl;
		cout<<"  Program Selesai"<<endl;
		exit(0);
        }
    else if (pilih > 5){
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

bool login ()
{
    system ("cls");
    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl;
    cout << left << setw (7) <<setfill (' ') << " "<<setw(34)<< " >> PROGRAM LOGIN SERVICE << "<<" " << endl;
    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl<<endl;

    string username, password;
    do {
    cout << "   Masukkan username dan password untuk login" << endl << endl;
    cout << "   Username : ";
    cin.ignore();
    getline(cin,username);
    cout << "   Password : ";
    cin >> password;

        if (username == uname && password == pword){
            cout << endl;
            cout << "   login berhasil"<<endl;
            cout << "   Anda akan diarahkan ke menu utama";
            berhasil = true;
            getch();
            main ();
            exit(0);

        }else {
            cout << endl;
            char coba = 'Y';
            do{
                cout << "   Input salah, silahkan coba lagi"<<endl<<endl;
                cout << "   Ingin mencoba lagi? (y/t) : "; cin >> coba;
                if (coba == 'y' || coba =='Y'){
                    login();
                }
                else {
                    cout<<endl;
                    cout<<"   Login gagal"<<endl;
                    cout << "   Anda akan diarahkan ke menu utama";
                    getch();
                    main();
                    exit(0);
                    break;
                }


            } while (toupper(coba)=='Y');
            cout<<endl;
            cout<<"   Program Selesai"<<endl;
            break;
        }

    } while (username != uname || password != pword);

    return 0;

}

void masukdata()
{
    system ("cls");
    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl;
    cout << left << setw (3) <<setfill (' ') << " "<<setw(34)<< " >> PROGRAM INPUT DAN TAMBAH DATA << "<<" " << endl;
    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl<<endl;
    cout << "   Input banyak data = ";
    cin >> batas;
    cout << endl;

    data=data+batas;
    for(int i=data-batas; i<data; i++)
    {
        cout << "   Input Data Service ke - " << i + 1 << endl;
       // cin.ignore();
        cin.ignore();
        cout << "   Nama Kendaraan    : ";
        getline(cin, srv[i].nama[i]);

        cout << "   Harga Service     : ";
        cin >> srv[i].harga[i];

        cout<<endl;
        cout << " " <<setw (41) <<setfill ('/')<< " "<<endl<<endl;
		}

}

void keluardata()
{
    system ("cls");
    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl;
    cout << left << setw (3) <<setfill (' ') << " "<<setw(34)<< " >> PROGRAM OUTPUT DATA SERVICE << "<<" " << endl;
    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl<<endl;

    for (int i = 0; i < data; i++)
    {
    cout << "   Data Service ke - " << i + 1 << endl;
    cout << "   Nama Kendaraan    : " << srv[i].nama[i] << endl;
    cout << "   Harga Service     : " << srv[i].harga[i] << endl;


    cout << endl;
    }
}

void pencarian()
{
    system ("cls");
    bool ketemu = false;
    string cari;

    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl;
    cout << left << setw (2) <<setfill (' ') << " "<<setw(34)<< " >> PROGRAM PENCARIAN DATA SERVICE << "<<" " << endl;
    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl<<endl;

    cout << "   Pencarian Data Service "<<endl;
    cout << "   Menurut nama kendaraan = ";
    cin.ignore();
    getline(cin, cari);
    cout<<endl;

    for (int i=0; i <= data; i++){
        while (cari == srv[i].nama[i])
        {
            cout << "   Data Service Ditemukan pada index ke - " << i << endl;
            cout << "   Nama Kendaraan    : " << srv[i].nama[i] << endl;
            cout << "   Harga Service     : " << srv[i].harga[i] << endl;
            ketemu = true;
            cout<<endl;
            break;
        }

    }
    if(!ketemu){
        cout  << "   Data tidak ditemukan"<<endl;
        cout  << "   Data Anda tidak ada di Array atau Anda salah menginputkan Pencarian."<<endl;
    }

    /*
    //SEQ BELUM URUT NON SENTINEL
    #include <iostream>
    using namespace std;
    int main() {
    int X[10] = {20, 50, 10, 30, 90, 60, 70, 80, 40, 100};
    bool found;
    int i, nilaiCari;
    cout << "nilai yang dicari = "; cin >> nilaiCari;
    found = false;
    i = 0;
    while((i < 10) & (!found))
    {
    if(X[i] == nilaiCari)
    found = true;
    else
    i = i + 1;
    }
    if(found)
    cout << nilaiCari << " ditemukan pada index array ke-" << i <<endl;
    else
    cout << nilaiCari << " tidak ada dalam Array tersebut" << endl;
    }

    //SEQ URUT NON SENTINEL
    #include <iostream>
    using namespace std;
    int main()
    {
    int X[10]={10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i, nilaiCari;
    bool found;
    cout << "Nilai yang dicari = "; cin >> nilaiCari;
    found = false;
    i = 0;
    while((i < 10) & (!found) & (nilaiCari >= X[i]))
    {
    if(X[i] == nilaiCari) found = true;
    else i = i+1;
    }
    if(found)
    cout << nilaiCari << " ditemukan dalam Array pada index ke-" << i << endl;
    else
    cout << "tidak ada " << nilaiCari << " dalam Array" << endl;
    }


    //SEQ BELUM URUT SENTINEL
    #include <iostream>
    using namespace std;
    int main()
    {
    int X[11] = {20, 50, 10, 30, 90, 60, 70, 80, 40, 100};
    int i, nilaiCari;
    cout << "Nilai yang dicari = "; cin >> nilaiCari;
    X[10] = nilaiCari;
    i=0;
    while(X[i] != nilaiCari)
    i = i + 1;
    if(i > 9)
    cout << "tidak ada " << nilaiCari << " dalam Array" << endl;
    else
    cout << nilaiCari << " ditemukan dalam Array pada index ke-" << i << endl;
    }

    //SEQ URUT SENTINEL
    #include <iostream>
    using namespace std;
    int main()
    {
    int X[11]={10,20,30,40,50,60,70,80,90,100};
    int i, nilaiCari;
    bool found;
    cout << "Nilai yang dicari = "; cin >> nilaiCari;
    X[10] = nilaiCari;
    found = false;
    i = 0;
    while((!found) & (X[i] <= nilaiCari))
    {
    if(X[i] == nilaiCari) found = true;
    else i = i + 1;
        }
    if(i == 10)
    cout << "tidak ada " << nilaiCari << " dalam Array" << endl;
    else {
    if (found)
    cout << nilaiCari << " ditemukan dalam Array pada index ke-" << i <<endl;
    else
    cout << "tidak ada " << nilaiCari << " dalam Array" << endl;
    }
    }

    //BINARY
    #include <iostream>
    using namespace std;
    int main()
    {
    int X[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i, nilaiCari, j, k;
    bool found;
    cout << "nilai yang dicari = "; cin >> nilaiCari;
    found = false;
    i = 0;
    j = 10;
    while((!found) & (i <= j))
    {
    k = (i + j) / 2;
    if(nilaiCari == X[k])
    found = true;
    else
    {
    if(nilaiCari < X[k])
    j = k - 1; // i tetap
    else
    i = k + 1; // j tetap
    }
    }
    if(found)
    cout << nilaiCari << " ditemukan dalam Array pada index ke-" << k << endl;
    else
    cout << "tidak ada " << nilaiCari << " dalam Array" << endl;
    }


    */

}

void sorting() {

    system ("cls");
    //SORTING SELECTION
    int tempHarga;
    string tempNama;
    for(int i = 0; i < data; i++) {
        for(int j = i+1; j < data; j++) {
            if(srv[i].harga[i] > srv[j].harga[j]) {
                tempHarga = srv[i].harga[i];
                srv[i].harga[i] = srv[j].harga[j];
                srv[j].harga[j] = tempHarga;

                tempNama = srv[i].nama[i];
                srv[i].nama[i] = srv[j].nama[j];
                srv[j].nama[j] = tempNama;
            }
        }
    }
    cout << " " << setw (41) << setfill ('-') << " " << endl;
    cout << left << setw (3) << setfill (' ') << " "<< setw(34) << " >> PROGRAM SORTING DATA SERVICE << "<<" " << endl;
    cout << " " << setw (41) << setfill ('-') << " " << endl << endl;

    cout << right <<"   +" << setw (55) << setfill ('-') << "+" << endl;
    cout << left << setw (6) <<setfill (' ') << "   |" << setw(4) << "NO" <<
    setw (6) << setfill (' ') << "|" << setw(18) << "Nama Kendaraan" <<
    setw (6) << setfill (' ') << "|" << setw(18) << "Harga Service" << "|" << endl;
    cout << right << "   +" << setw (55) << setfill ('-') << "+" << endl;

    for (int i = 0; i < data; i++){
    cout << left << setw (7) <<setfill (' ') << "   |" << setw(3) << i+1 <<
    setw (8) << setfill (' ') << "|"<< setw(16) << srv[i].nama[i] <<
    setw (9) << setfill (' ') << "|"<< setw(15) << srv[i].harga[i]<< "|" << endl;
    }
    cout << right <<"   +" <<setw (55)<<setfill ('-')<<"+"<<endl;

    cout << "   Data berhasil diurutkan berdasarkan harga termurah ke harga termahal.\n";

    //SORTING BUBLE
    /*    int temp, i, j;
    for(i=0; i<size-1; i++) {
        for(j=0; j<size-1-i; j++) {
            if(array[j] > array[j+1]) {//////
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            }
        }
    }

    //SORTING INSERTION
        int i, j, k;
        int Temp;
        for(i=1; i<size; i++) {
            Temp = array[i];
            j = i - 1;

            while((Temp > array[j]) & (j >= 0))
            {
                array[j+1] = array[j];
                j = j - 1;
                array[j+1] = Temp;
            }
            cout<< "perubahan data : "<<endl;
            for(k=0;k<size;k++)
            cout << array[k]<< " ";
            cout << endl;
        }

    //SORTING QUICK
    void quick_sort(int array[], int first, int last)
    {
    int temp, low, high, list_separator;

    low = first;
    high = last;
    list_separator = array[(first + last) / 2];

    do {
        while(array[low] < list_separator)
            low++;
        while(array[high] > list_separator)
            high--;
        if(low <= high)
        {
            temp = array[low];
            array[low++] = array[high];
            array[high--] = temp;
        }
    } while(low <= high);

    if(first < high) quick_sort(array, first, high);
    if(low < last) quick_sort(array, low, last);
    }

    int main()
    {
    int first = 0;
    int last = data_size - 1;
    int values[data_size], i;

    // data yang belum diurutkan diambil dari hasil random
    cout << "data yang belum urut : " << endl;
    for(i = 0; i < data_size; i++)
    {
        values[i] = rand() % 100;
        cout <<values[i] << " ";
    }
    cout << endl;

    quick_sort(values, first, last);
    // data yang sudah diurutkan
    cout << "data yang sudah diurutkan : " << endl;
        for(i = 0; i < data_size; i++)
        cout << values[i] << " ";
    getchar();
    }

    //SORTING SHELL
    int shell_sort(int []);
    int main()
    {
    int arr[size], i;
    cout << "Enter the elements to be sorted : " << endl;
        for(i = 0; i < size; i++)
        {
            cin>> arr[i];
        }
    shell_sort(arr);
    cout << "The array after sorting is : " << endl;
        for(i = 0; i < size; i++)
    cout << arr[i] << endl;
}

// fungsi shell sort
int shell_sort(int array[])
{
    int i = 0, j = 0, k = 0, mid = 0;

    for(k = size/2; k > 0; k /= 2)
    {
        for(j = k; j < size; j++)
        {
            for(i = j-k; i >= 0; i -= k)
        {
            if(array[i + k] >= array[i])//penentu
            break;

            else
            {
                mid = array[i];
                array[i] = array[i + k];
                array[i + k] = mid;
            }
        }
        }
    }
    return 0;
}

    //RESERVASI COY
    #include <iostream>
    using namespace std;

    int main() {
    int kamar[100] = {}; // menyimpan status kamar (nomor kamar atau 0 jika kosong)
    int nomor_kamar, pilihan_menu;
    bool keluar = false;

    while (!keluar) {
        cout << "Menu:" << endl;
        cout << "1. Input nomor kamar" << endl;
        cout << "2. Tampilkan status kamar" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan_menu;
        cout << endl;

        switch (pilihan_menu) {
            case 1:
                cout << "Masukkan nomor kamar (1-100): ";
                cin >> nomor_kamar;
                if (nomor_kamar < 1 || nomor_kamar > 100) {
                    cout << "Nomor kamar tidak valid" << endl;
                    break;
                }
                if (kamar[nomor_kamar - 1] != 0) {
                    cout << "Kamar ini sudah dipesan" << endl;
                } else {
                    kamar[nomor_kamar - 1] = nomor_kamar;
                    int row = (nomor_kamar - 1) / 10 + 1; // menentukan baris kamar
                    int col = (nomor_kamar - 1) % 10 + 1; // menentukan kolom kamar
                    cout << "Kamar " << nomor_kamar << " berhasil dipesan" << endl;
                    // mengubah status kamar pada tampilan
                    cout << "  ";
                    for (int i = 1; i <= 10; i++) {
                        cout << (row == 1 ? i : (row - 1) * 10 + i) << " ";
                    }
                    cout << endl;
                    for (int i = 1; i <= 10; i++) {
                        int k = (row - 1) * 10 + i;
                        cout << (k < 10 ? " " : "") << (kamar[k - 1] != 0 ? "XX" : to_string(k)) << " ";
                    }
                    cout << endl;
                }
                break;
            case 2:
                // menampilkan status kamar pada tampilan
                cout << "  ";
                for (int i = 1; i <= 10; i++) {
                    //cout << i << "  ";
                }
                cout << endl;
                for (int i = 1; i <= 10; i++) {
                    //cout << (i < 10 ? " " : "") << i * 10 << " ";
                    for (int j = 1; j <= 10; j++) {
                        int k = (i - 1) * 10 + j;
                        cout << (kamar[k - 1] != 0 ? "XX" : (k < 10 ? " " : "") + to_string(k)) << " ";
                    }
                    cout << endl;
                }
                break;
            case 3:
                keluar = true;
                cout << "Terima kasih telah menggunakan program ini" << endl;
                break;
            default:
                cout << "Menu tidak valid" << endl;
                break;
        }
        cout << endl;
    }

    return 0;
}


    //REKURSIF
    #include <iostream>
    using namespace std;
    float S(int n);

    int main()
{
    cout << "\nS(3)";
    cout << " = " << S(3) << endl;
}

float S(int n) {

    float p, q, x, hasil=0;
    p = 2 * n;
    q = 3 * n + 1;

    if(n == 0) {
        return hasil;
    } else {
        cout << p << "/" << q;
        if (n == 1) {
            cout << " = ";
        } else {
            cout << " + ";
        }
        x = p/q;
        hasil = x + S(n-1);
        return hasil;
    }
}

    //REKURSIF BINTANG
#include <iostream>
#include <iomanip>
using namespace std;

void segitiga(int x, int a, int b);

int main() {

    int x, a=1, b=1;

      x sebagai penentu banyaknya tinggi segitiga
      a sebagai penentu baris
    //  b sebagai penentu kolom

    char ulang = 'Y';

    do{
    system("cls");
    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl;
    cout << left << setw (3) <<setfill (' ') << " "<<setw(34)<< " >> PROGRAM SEGITIGA REKURSIF << "<<" " << endl;
    cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl;
    cout << setw (28) <<setfill (' ')<<"Masukkan tinggi segitiga: "; cin >> x;
    cout<<endl;

    segitiga(x, a, b);

    cout<<endl;
    cout << "  Coba lagi? (y/t) : "; cin >> ulang;
    }while(toupper(ulang)=='Y');
    cout<<endl;
    cout<< "  Terimakasih"<<endl;


    return 0;
}

void segitiga(int x, int a, int b) {

    if (a <= x) {
        if (b <= a) {
            cout<<" ";
            cout << " *";
            segitiga(x, a, b+1);
        } else {
            cout << endl;
            segitiga(x, a+1, 1);
        }
    }
}
    //MATRIKS
    void Penjumlahan()
{

    if (baris != baris1 && kolom != kolom1)
    {
        cout << "   Matrik tidak dapat dijumlahkan"<<endl;
        cout << "   Pastikan baris dan kolom matriks A dan B sama"<<endl<<endl;
        cout << "   Silahkan input matrik dengan benar";
        cout << endl;
    }
    else
    {
        cout << "   Hasil penjumlahan : \n" << endl;
        for (int i = 0; i < baris; i++)
        {
            for (int j = 0; j < kolom1; j++)
            {
                C[i][j] = A[i][j] + B[i][j];
                cout << "    " << C[i][j] << " ";
            }
        cout << endl<<endl;
        }
    }
}

void Pengurangan()
{
    if (baris != baris1 && kolom != kolom1)
    {
        cout << "   Matrik tidak dapat dikurangkan"<<endl;
        cout << "   Pastikan baris dan kolom matriks A dan B sama"<<endl<<endl;
        cout << "   Silahkan input matrik dengan benar";
        cout << endl;
    }
    else
    {
        cout << "   Hasil pengurangan : \n" << endl;
        for (int i = 0; i < baris; i++)
        {
            for (int j = 0; j < kolom1; j++)
            {
                C[i][j] = A[i][j] - B[i][j];
                cout << "    " << C[i][j] << " ";
            }
        cout << endl<<endl;
        }
    }
}

void Perkalian()
{
    if (kolom != baris1)
    {
        cout << "   Matrik tidak dapat dikalikan"<<endl;
        cout << "   Pastikan kolom matrik A dan baris matrik B sama"<<endl<<endl;
        cout << "   Silahkan input matrik dengan benar";
        cout << endl;
    }
    else
    {
        for (int i = 0; i < baris; i++)
        {
            for (int j = 0; j < kolom1; j++)
            {
                for (int k = 0; k < baris1; k++)
                {
                    jumlah += A[i][k] * B[k][j];
                }
                hasil[i][j] = jumlah;
                jumlah = 0;
            }
        }
        cout << "   Hasil perkalian : \n\n";
            for (int i = 0; i < baris; i++)
            {
                for (int j = 0; j < kolom1; j++)
                {
                    cout << "    " << hasil[i][j] << " ";
                }
            cout << endl<<endl;
            }
    }
}

void Transpose()
{

    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            transpose[j][i] = A[i][j];
        }
    }
    cout << "   Transpose matrik A : \n" << endl;
    for (int i = 0; i < kolom; i++)
    {
        for (int j = 0; j < baris; j++)
        {
            cout << "    " << transpose[i][j] << " ";
        }
    cout << endl<< endl;
    }

    cout << endl;

    for (int i = 0; i < baris1; i++)
    {
        for (int j = 0; j < kolom1; j++)
        {
            transpose[j][i] = B[i][j];
        }
    }
    cout << "   Transpose matrik B : \n" << endl;
    for (int i = 0; i < kolom1; i++)
    {
        for (int j = 0; j < baris1; j++)
        {
            cout << "    " << transpose[i][j] << " ";
        }
    cout << endl<< endl;
    }
  cout << endl;
}


    //TERBAIK
    int terbaik, minimal;
        string punya, punya1;
        terbaik = mhs[0].nilai[0];
        for(int i = 0; i < batas; i++)
        {
            if(mhs[i].nilai[i] > terbaik)
            {
                terbaik = mhs[i].nilai[i];
                punya = mhs[i].nama[i];
            }
            else if (mhs[i].nilai[i] < minimal)
            {
                minimal = mhs[i].nilai[i];
                punya1 = mhs[i].nama[i];
            }
        }

        cout  << "   Nilai terbesar adalah : " << terbaik << endl;
        cout  << "   Yang dimiliki oleh    : " << punya << endl<<endl;
        cout << " " <<setw (41) <<setfill ('/')<< " "<<endl << endl;

    //FAKTORIAL
    //faktorial 2
int faktorial (int n)
{
    if (n == 0 || n ==1 ){
        return 1;
    }else {

        return (n*faktorial (n-1));
    }
}



    //STRUCT 2
    //announcement
//program dapat menyimpan data sebelumnya dan tidak akan hilang
//dapat meng-input lagi dan data sebelumnya masih ada
//tampilan output juga akan menampilkan data yang sebelumnya di input
//terimakasih >_<

#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

struct komponen
{
    int No;
    string Nama[20];
    string Skor[20];
};

struct mahasiswa
{
    char NoMhs[10];
    string Nama[20];
    string MTKul[20];
    komponen BanyakKomponen;
};

void masukdata();
void keluardata();

mahasiswa mhs[20];
int banyak,data;

int main (){

    int pilih;
    char ulang = 'Y';

    do{
    system("cls");
    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl;
    cout << left << setw (3) <<setfill (' ') << " "<<setw(34)<< " >> PROGRAM DATA MAHASISWA << "<<" " << endl;
    cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl;

    cout << left << setw (16) <<setfill ('=') << " "<<setw(25)<< " PILIHAN "<<" " << endl;
    cout << left << setw (4) <<setfill (' ') << " |"<<setw(36)<< " 1. Input Data dan Komponen"<<"|" <<endl;
    cout << left << setw (4) <<setfill (' ') << " |"<<setw(36)<< " 2. Output Data dan Komponen"<<"|" <<endl;
    cout << left << setw (4) <<setfill (' ') << " |"<<setw(36)<< " 3. Keluar dari Program"<<"|" <<endl;
    cout << right <<" " <<setw (41)<<setfill ('=')<<" "<<endl;
    cout << left << setw (2) <<setfill (' ') << " "<<setw(23)<< "Silahkan pilih menu yang tersedia = ";
	cin >> pilih;

	if(pilih == 1){
		cout<<endl;
		masukdata();
		}
	else if(pilih == 2){
		cout<<endl;
		keluardata();
		}
    else if (pilih == 3){
        cout<<endl;
		cout<<"  Program Pendataan Selesai"<<endl;
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
	cout<<"  Program Pendataan Selesai";


    return 0;
}

void masukdata()
{
    system ("cls");
    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl;
    cout << left << setw (3) <<setfill (' ') << " "<<setw(34)<< " >> PROGRAM INPUT DATA MAHASISWA << "<<" " << endl;
    cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl;
    cout << "   Input banyak mahasiswa = ";
    cin >> banyak;
    cout << endl;

    data=data+banyak;
    for (int i=data-banyak; i < data; i++)
    {
        cout << "   Input Data Mahasiswa ke - " << i+1 << endl;
        cin.ignore();
        cout << "   Nomer Mahasiswa : ";
        cin >> mhs[i].NoMhs;
        cin.ignore();

        cout << "   Nama Mahasiswa  : ";
        getline(cin, mhs[i].Nama[i]);

        cout << "   Mata Kuliah     : ";
        getline(cin, mhs[i].MTKul[i]);
        cout << endl;

        cout << "   Input Banyak Komponen : ";
        cin >> mhs[i].BanyakKomponen.No;

        for (int j=0; j < mhs[i].BanyakKomponen.No; j++)
        {
            cin.ignore();
            cout << "   Nama Komponen : ";
            getline(cin, mhs[i].BanyakKomponen.Nama[j]);

            cout << "   Skor          : ";
            cin >> mhs[i].BanyakKomponen.Skor[j];
            cout<<endl;
        }
        cout << " " <<setw (41) <<setfill ('/')<< " "<<endl<<endl;
    }
}

void keluardata()
{
    system ("cls");
    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl;
    cout << left << setw (3) <<setfill (' ') << " "<<setw(34)<< " >> PROGRAM OUTPUT DATA MAHASISWA << "<<" " << endl;
    cout << right <<" " <<setw (41)<<setfill ('-')<<" "<<endl<<endl;

    for (int i = 0; i < data; i++)
    {
    cout << "   Data Mahasiswa ke - " << i + 1 << endl;
    cout << "   Nomor Mahasiswa    : " << mhs[i].NoMhs << endl;
    cout << "   Nama               : " << mhs[i].Nama[i] << endl;
    cout << "   Mata Kuliah        : " << mhs[i].MTKul[i] << endl;
    cout << endl;

    cout << "   +" <<setw (41) <<setfill ('-')<< "+"<<endl;
    cout << left << setw (6) <<setfill (' ') << "   |"<<setw(4)<< "NO" <<
    setw (6) <<setfill (' ') << "|"<<setw(18)<< "Nama Komponen" <<
    setw (4) <<setfill (' ') << "|"<<setw(6)<< "Skor"<<"|"<<endl;
    cout << right <<"   +" <<setw (41)<<setfill ('-')<<"+"<<endl;

    for (int j = 0; j < mhs[i].BanyakKomponen.No; j++){
    cout << left << setw (7) <<setfill (' ') << "   |"<<setw(3)<< j+1 <<
    setw (10) <<setfill (' ') << "|"<<setw(14)<< mhs[i].BanyakKomponen.Nama[j] <<
    setw (5) <<setfill (' ') << "|"<<setw(5)<< mhs[i].BanyakKomponen.Skor[j]<<"|"<<endl;
    }
    cout << right <<"   +" <<setw (41)<<setfill ('-')<<"+"<<endl<<endl;

  }
}



    */
}












