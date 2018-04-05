#include<iostream>
using namespace std;

void atas(int tinggi, bool padat)	{
	//Baris Paling Atas
	for (int j=0; j<=2*tinggi; j++)	{
		cout << "*";
	}
	cout << endl;
	//Baris ke-2 sampai tengah
	for (int i=tinggi-1; i>0; i--){
        for (int j=tinggi; i<j; j--)
        {
            cout << " ";
        }
        for (int j=0; j<=2*i; j++)
        {
        	if (!padat)	{
		    	if (j==0 || j == 2*i)	{
		    		cout << "*";
		    	} else {
		        	cout << " ";
		        }
		    } else	{
		    	cout << "*";
		    }
        }
        cout << endl;
    }
}

void bawah(int tinggi, bool padat)	{
	//Baris setelah tengah sampai sebelum paling bawah
    for (int i=0; i<tinggi-1; i++)
    {
        for (int j=0; j<(tinggi-(i+1)); j++)
        {
            cout << " ";
        }
        for (int j=0; j<=2*i+2; j++)
        {
        	if (!padat)	{
		    	if (j==0 || j==2*i+2)	{
		    		cout << "*";
		    	} else {
		        	cout << " ";
		        }
		    } else	{
		    	cout << "*";
		    }
        }
        cout << endl;
    }
    //Baris paling bawah
    for (int j=0; j<=2*tinggi; j++)	{
    	cout << "*";
    }
    cout << endl;
}

void tengah(int tinggi)	{
	for (int i=0; i<(2*tinggi+1)/2; i++)	{
    	cout << " ";
    }
    cout << "*" << endl;
}

int main()
{
	//Deklarasi Variabel
	int tinggi;
	string keterangan;
	//Input User
	cin >> tinggi;
    cin >> keterangan;
    //Validasi
    while (!(keterangan == "PENUH" || keterangan == "KOSONG"))	{
    	cout << "Masukan harus 'PENUH' atau 'KOSONG'" << endl;
    	cin >> keterangan;
    }
    //Bagian Atas
    atas(tinggi, keterangan=="KOSONG");
    //Bagian Tengah
    tengah(tinggi);
    //Bagian Bawah
    bawah(tinggi, keterangan=="PENUH");
}