#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
using namespace std;

char letakkursi[25][25];
string jstudio,jfilm;//untuk dipakai di pencetakan tiket

int pilihhari(){
	int hari,stt1;//stt1 untuk pengecek
	do{//untuk perulangan hari
	system("cls");
	cout<<"Pilih hari?(Masukkan Angka)"<<"\n1.Senin"<<"\n2.Selasa"<<"\n3.Rabu"<<"\n4.Kamis"<<"\n5.Jumat"<<"\n6.Sabtu"<<"\n7.Minggu\n";
	cin>>hari;//harga hari senin-kamis normal ,jumat +5000,sabtu/minggu +10,000
	if (hari>0 and hari<8){
	system("cls");
		stt1=0;
			}
	else{
		cout<<"Yang anda masukkan salah silahkan tekan sembarang untuk ulangi lagi\n";
		getch( );
		stt1=1;

		}
	}while(stt1==1);
	return hari;
	}
int jadwalfilm(int hari){ //hari=2
	int film;
	int stt2;//pengecekan untuk perulangan film
	/* dibuat variabel film disini bermaksud film yang ditampilkan dapat diubah sesuai data*/
	string film1="Avengers";
	string film2="Mermet";
	string film3="Popon";
	string film4="Suparman";

		do{//untuk perulangan film
		system("cls");
	cout<<"Jadwal Film Hari ini";
	if (hari==1 || hari==5)
		{cout<<"\n1."<<film1<<"\n2."<<film2;
			cout<<"\nJadi nonton tidak! Pilih Film?";cin>>film;
		if (film==1 || film==2)
		{
			
		switch (film)
			{
			case 1:
				jfilm = film1;
				break;
			case 2:
				jfilm = film2;
				break;
			}
		}
			else
			{
			cout<<"Yang anda masukkan salah silahkan tekan sembarang untuk ulangi lagi\n";
			getch( );
			stt2=1;

			}
		
		}
	
	if (hari==2 || hari==6)
	
		{cout<<"\n1."<<film2<<"\n2."<<film3;
		cout<<"\nJadi nonton tidak! Pilih Film?";cin>>film;
		if (film==1 || film==2)
		{
			
			switch (film)
		{		
			case 1:
				jfilm = film2;
				break;
			case 2:
				jfilm = film3;
			break;
		}
		}
			else
			{
			cout<<"Yang anda masukkan salah silahkan tekan sembarang untuk ulangi lagi\n";
			getch( );
			stt2=1;

			}
		
		}
	
	if (hari ==3 || hari==7)
	
		{cout<<"\n1."<<film3<<"\n2."<<film4;
		cout<<"\nJadi nonton tidak! Pilih Film?";cin>>film;
		if (film==1 || film==2)
		{
			
			switch (film)
		{		
			case 1:
				jfilm = film3;
				break;
			case 2:
				jfilm = film4;
			break;
		}
		}
			else
			{
			cout<<"Yang anda masukkan salah silahkan tekan sembarang untuk ulangi lagi\n";
			getch( );
			stt2=1;

			}
		
		}
	
	if (hari == 4 )
		{
			cout<<"\n1."<<film4<<"\n2."<<film1;
		cout<<"\nJadi nonton tidak! Pilih Film?";cin>>film;
		if (film==1 || film==2)
		{
			
			switch (film)
		{		
			case 1:
				jfilm = film1;
				break;
			case 2:
				jfilm = film4;
			break;
		}
		}
			else
			{
			cout<<"Yang anda masukkan salah silahkan tekan sembarang untuk ulangi lagi\n";
			getch( );
			stt2=1;

			}
		
		}
		system("cls");
		}while(stt2==1);

return film;
}
int jadwalstudio(int p_studio){ //p_stdio=1
	int harga[3];
	int studio;
	string studio1="Reguler";//harga=Rp.35.000,00
	string studio2="4DXD";//harga=Rp.75.000,00
	string studio3="SphereX";//harga=Rp.50.000,00
	harga[0]=35000;
	harga[1]=75000;
	harga[2]=50000;
	ulang://hanya menunujukan penggunaan goto(goto dapat merusak data terstruktur)//untuk mengulang pemilihan studio
		system("cls");
	cout<<"Pilih Studio?(Masukkan angka)";
	if (p_studio>0 and p_studio<5){
	system("cls");
	ulang1://untuk pengulangan studio 
		system("cls");
	cout<<"Studio untuk film ini";
	if (p_studio==1)
		{cout<<"\n1."<<studio1<<"\n2."<<studio2;
			cout<<"\nJadi nonton tidak! Pilih Studio?";cin>>studio;
		if (studio==1 || studio==2)
		{
			
			if (studio==1)
			{
				studio = harga[0];
				jstudio = studio1;
			}
			else if (studio==2)
			{
				studio = harga[1];
				jstudio = studio2;
			}
		}
			else
			{
			cout<<"Yang anda masukkan salah silahkan tekan sembarang untuk ulangi lagi\n";
			getch( );
			goto ulang1;

			}
		
		}
	
	if (p_studio==2)
	
		{cout<<"\n1."<<studio2<<"\n2."<<studio3;
		cout<<"\nJadi nonton tidak! Pilih studio?";cin>>studio;
		if (studio==1 || studio==2)
		{
			
			if (studio==1)
			{
				studio = harga[1];
				jstudio = studio2;
			}
			else if (studio==2)
			{
				studio = harga[2];
				jstudio = studio3;
			}
		}
			else
			{
			cout<<"Yang anda masukkan salah silahkan tekan sembarang untuk ulangi lagi\n";
			getch( );
			goto ulang1;//hati hati dapat merusak kestrukturan data

			}
		
		}
		system("cls");
	}
	else
	
		{
			cout<<"Yang anda masukkan salah silahkan tekan sembarang untuk ulangi lagi\n";
		getch( );
		goto ulang;//hati hati dapat merusak kestrukturan data

		}
return studio;
}
int pilihkursi(){
	char a[25][25],d[25][25],lagi;
  int kolom=3, baris=3,i,b,jmltiket;
  do{//perulangan ketika tiket yang dibeli melebihi batas pembelian
	  lagi=0;
	 //pembuatan array kursi
  for ( i=1;i<=baris;i++){ //baris n
        for ( b=1;b<=kolom;b++){ //kolom
                a[i][b]='*';//digunakan untuk menampilkan kursi yang tersedia
                d[i][b]=' ';//digunakan untuk menampilkan kursi yang dipilih
            }
      }
    do{//perulangan untuk penambahan tiket
		lagi+=jmltiket;
    do{//perulangan jika yang diinput lebih dari batas
		  system("cls");
      cout<<"Berapa banyak tiket yang kamu beli(Maksimal Pembelian 5 tiket)?";cin>>jmltiket;
      lagi+=jmltiket;
		}while(jmltiket>5);
	//untuk menampilkan kursi dalam bentuk array 2 dimensi
    cout<<endl<<"Kursi Yang Tersedia Adalah: "<<endl<<endl;
    for ( i=1;i<=baris;i++){ //baris
        for ( b=1;b<=kolom;b++){ //kolom   
                cout<<"\t"<<"|"<<a[i][b]<<"|";
            }
            cout<<endl;
      }
		//untuk memilih kursi yang bakal dipilih
		for (int j = 0; j < jmltiket; j++)
		{
				cout<<"Pilih letak kursi";
				cout<<"\nKolom berapa?";cin>>i;
				cout<<"\nBaris berapa?";cin>>b;
				if (i>3 || b>3)//agar pemilihan kursi tidak lebih dari batas baris dan kolom
				{
					cout<<"Yang anda masukkan salah silahkan tekan sembarang";
					getch();
					j=0;
					system("cls");
					cout<<endl<<"Kursi Yang Tersedia Adalah: "<<endl<<endl;
							for ( i=1;i<=baris;i++){ //baris
								for ( b=1;b<=kolom;b++){ //kolom   
									cout<<"\t"<<"|"<<a[i][b]<<"|";
									}
								cout<<endl;
							}
				}
                a[i][b]=' ';//dibuat kosong karena kursi telah dipilih
                d[i][b]='*';//dibuat bintang karena kursi telah dipilih
                
         }
	cout<<endl<<"Kursi Yang Kamu Pilih: "<<endl<<endl;
    for ( i=1;i<=baris;i++){ //baris
        for (b=1;b<=kolom;b++){ //kolom   
                cout<<"\t"<<"|"<<d[i][b]<<"|";
            }
            cout<<endl;
    
      }
    if (lagi<=5)
	{
     cout<<"Mau beli tiket lagi?(Y/N)";cin>>lagi;
    }
    else{
		cout<<"Anda telah melebihi batas jumlah pembelian tiket\n(tekan sembarang untuk memilih kembali)";
		getch();
		lagi='x';
      }
     }while(lagi=='y');
	}while(lagi=='x');
	 for ( i=1;i<=baris;i++){ //baris
        for ( b=1;b<=kolom;b++){ //kolom
                	letakkursi[i][b]=d[i][b];
            }
      }
     return jmltiket;
	}
int totalharga(int hari,int studio,int jmltiket){
	int harga;
	if (hari<5)
	{
		harga = studio*jmltiket;
	}
	else if (hari==5)
	{
		harga = (studio+5000)*jmltiket;
	}
	else
	{
		harga = (studio+10000)*jmltiket;
	}
	return harga;
	}
void cetaktiket(int film,int studio,int jmltiket,int hari){
	system("cls");
	cout<<"+"<<setfill('-')<<setw(60)<<"+\n";
	cout<<"|"<<setfill(' ')<<setw(34)<<"E-Ticket Movies"<<setw(26)<<"|\n";
	cout<<"|"<<setfill(' ')<<setw(60)<<"|\n";//enter
	cout<<"|"<<setfill(' ')<<"Judul yang kamu pilih: "<<setw(20)<<jfilm<<setw(17)<<"|\n";
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0 ; j <= 3; j++)
		{
			if (letakkursi[i][j] == '*')
			{
	cout<<"|"<<setfill(' ')<<"Kursi yang kamu pesan adalah:"<<"Kolom("<<i<<")"<<"Baris("<<j<<")"<<setw(15)<<"|\n";
			}
		}
	}
	cout<<"|"<<setfill(' ')<<"Studio yang kamu pilih: "<<setw(17)<<jstudio<<setw(19)<<"|\n";
	cout<<"|"<<setfill('-')<<setw(60)<<"|\n";
	cout<<"|"<<setfill(' ')<<"CODE BOOKING : "<<jfilm[0]<<jfilm[2]<<jstudio[2]<<jstudio[3]<<film<<jmltiket<<'0'<<"JG"<<hari<<setw(35)<<"|\n";
	cout<<"+"<<setfill('-')<<setw(60)<<"+\n";
	getchar();
	
}

int main(){
	char acc;	
	cout<<"\t\t\t+-----------------------------------------------------------------------+\n";
	cout<<"\t\t\t|\t\t\t\tE-Ticket Movies\t\t\t\t|\n";
	cout<<"\t\t\t|\t\tprogram ini bertujuan mempermudah pembelian tiket\t|\n";
	cout<<"\t\t\t+-----------------------------------------------------------------------+";
	getch();
	do{
	int hari = pilihhari();
	int film = jadwalfilm(hari);	
	int studio = jadwalstudio(film);//studi untuk harga
	int jmltiket = pilihkursi();//jmltiket untuk harga
	int harga = totalharga(hari,studio,jmltiket);
	system("cls");
	cout<<"\t\t\t+-----------------------------------------------------------------------+\n";
	cout<<"\t\t\t|\t\t\t\tE-Ticket Movies\t\t\t\t|\n";
	cout<<"\t\t\t|\t\t\t\tTotal harga anda: "<<harga<<"\t\t\t|\n";
	cout<<"\t\t\t+-----------------------------------------------------------------------+";
	getch();
	cetaktiket(film,studio,jmltiket,hari);
	cout<<"\nPesan ulang? (Y/N)";cin>>acc;
}while(acc=='y');
	}
