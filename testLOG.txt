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
    cout << left << setw (1) << setfill (' ') << " "<< setw(34) << "  >> PROGRAM MANAGEMENT SERVICE MOTOR <<"<<" " << endl;
    cout << right <<" " <<setw (41) << setfill ('-') << " " << endl;

    cout << left << setw (16) << setfill ('=') << " "<< setw(25) << " PILIHAN "<< "" << endl;
    cout << left << setw (4) << setfill (' ') << " |"<< setw(36) << " 0. Login"<< "|" << endl;

    if (data<1){
        cout << left << setw (4) << setfill (' ') << " |"<< setw(36) << " 1. Input Data" << "|" <<endl;
    }
    else {
        cout << left << setw (4) << setfill (' ') << " |"<< setw(36) << " 1. Tambah Data" << "|" <<endl;

    }
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
    int cari1;
    int milih;

    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl;
    cout << left << setw (2) <<setfill (' ') << " "<<setw(34)<< " >> PROGRAM PENCARIAN DATA SERVICE << "<<" " << endl;
    cout << " " <<setw (41) <<setfill ('-')<< " "<<endl<<endl;

    cout << "   Pencarian Data Service "<<endl;
    cout << "   MENU-------------------"<<endl;
    cout << "   1. berdasar nama"<<endl;
    cout << "   2. berdasar harga"<<endl;
    cout << "   ingin berdasar apa? : ";
    cin>>milih;

    if(milih==1){
    system ("cls");
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
    }
    else if (milih ==2){
            system ("cls");

        cout << "   Menurut harga kendaraan = ";
    cin.ignore();
    cin >> cari1;
    cout<<endl;

    for (int i=0; i <= data; i++){
        while (cari1 == srv[i].harga[i])
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

    */
}











