#include <bits/stdc++.h>
using namespace std;


int main()	{
	//Deklarasi Variabel
	char sebelum = 'S'; //State Sebelumnya
	int M, N; //Jumlah Baris dan Kolom
	int x, y; //Posisi Sekarang
	cin >> M >> N;
	char Peta[M][N];
	for (int i=0; i<M; i++)	{
		for (int j=0; j<N; j++)	{
			cin >> Peta[i][j];
			if (Peta[i][j]=='S')	{
				x=i;
				y=j;
			}
		}
	}
	while (Peta[x][y]!='E')	{
		//Kiri
		if (y-1>=0 && sebelum!='R')	{
			if (Peta[x][y-1]!='X')	{
				y--;
				cout << 'L';
				sebelum = 'L';
				continue;
			}
		}
		//Kanan
		if (y+1<N && sebelum!='L')	{
			if (Peta[x][y+1]!='X')	{
				y++;
				cout << 'R';
				sebelum = 'R';
				continue;
			}
		}
		//Bawah
		if (x+1<M && sebelum!='U')	{
			if (Peta[x+1][y]!='X')	{
				x++;
				cout << 'D';
				sebelum = 'D';
				continue;
			}
		}
		//Atas
		if (x-1>=0 && sebelum!='D')	{
			if (Peta[x-1][y]!='X')	{
				x--;
				cout << 'U';
				sebelum = 'U';				
				continue;
			}
		}
	}
	cout << endl;
}