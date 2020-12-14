#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<iomanip>
#include<string>
using namespace std;
	
struct kartuPelajar{
	string nisn,nama,alamat,lahir,tempat,kelamin;
	};
kartuPelajar data[99];
string dataCari[99];//dataCari dibuat agar mempermudah pengurutan atau pencarian berdasarkan jenisnya
int storeData(char namaFile[]){//store data yaitu berfungsi sebagai merestore data dalam penyimpanan sementara
	ifstream myfile;
	int i=0;
	myfile.open( namaFile );
	while (!myfile.eof())
	{
		getline(myfile,data[i].nisn);
		getline(myfile,data[i].nama);
		getline(myfile,data[i].tempat);
		getline(myfile,data[i].lahir);
		getline(myfile,data[i].kelamin);
		getline(myfile,data[i].alamat);
		
		i++;
	}
	return  i-1;
	
	}
int base(char file[99],string dataCari[99],kartuPelajar data[]){//base digunakan untuk menggolongkan pencarian ataupun pengurutan
	int jml = storeData(file);
	int select;
	string cari;
	bool check;
	cout<<"Berdasarkan?\n1. NISN\n2. NAMA\n3. TEMPAT LAHIR\n4. TANGGAL LAHIR\n5. KELAMIN\n6. ALAMAT\nPILIH : ";
	do{
	check = false;
	cin>>select;
	if (select > 6 or select < 1 )
	{
		cout<<"Salah Input\n Input Lagi : ";
		check = true;
	}
	}while(check);
		
	for (int i = 0; i <jml ; i++)
	{	
		
		switch (select)
		{
			case 1:
				dataCari[i]=data[i].nisn;
				break;
			case 2:
				dataCari[i]=data[i].nama;
				break;
			case 3:
				dataCari[i]=data[i].tempat;
				break;
			case 4:
				dataCari[i]=data[i].lahir;
				break;
			case 5:
				dataCari[i]=data[i].kelamin;
				break;
			case 6:
				dataCari[i]=data[i].alamat;
				break;		
			default:
			;
		}

	}	
	return select;
	}
void tukarStr(string *a,string *b){//untuk menukar variabel string
	string temp;
	temp = *a;
	*a=*b;
	*b=temp;
	}
void tukarSet(kartuPelajar data[],int i, int j){//untuk menukar 1 set data
	tukarStr(&data[i].nisn, &data[j].nisn);
	tukarStr(&data[i].nama, &data[j].nama);
	tukarStr(&data[i].tempat, &data[j].tempat);
	tukarStr(&data[i].lahir, &data[j].lahir);
	tukarStr(&data[i].kelamin, &data[j].kelamin);
	tukarStr(&data[i].alamat, &data[j].alamat);
	
	
	}
void bubbleSort(kartuPelajar data[],string dataCari[], int n){  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    for (j = 0; j < n-i-1; j++)  
        if (dataCari[j]> dataCari[j+1]){
			cout<<"Proses Sorting\n";
			for (int i = 0; i < n; i++)
			{
				cout<<dataCari[i]<<" | ";
			}
		   tukarStr(&dataCari[j],&dataCari[j+1]);
           tukarSet(data,j,j+1);
           cout<<endl<<endl;
	} 
}
void selectionSort(kartuPelajar data[],string dataCari[], int n) { 
	int i, j, min; 
	cout<<"Proses Sorting\n";
	for (i = 0; i < n-1; i++) 
	{ 
		min = i; 
		for (j = i+1; j < n; j++) 
		if (dataCari[j] < dataCari[min]) 
		min = j;
		
		for (int k = 0; k < n; k++)
			{
				cout<<dataCari[k]<<" | ";
			} 
		cout<<endl<<endl;	
		tukarStr(&dataCari[min],&dataCari[i]);
        tukarSet(data,min,i);
		
	} 
}
void insertionSort(kartuPelajar data[],string dataCari[], int n) {  
    int i, j; 
    string  x[7]; 
    cout<<"Proses Sorting\n";
    for (i = 1; i < n; i++) 
    {  
		
		for (int k = 0; k < n; k++)
			{
				cout<<dataCari[k]<<" | ";
			} 
		cout<<endl<<endl;	
        x[0] = dataCari[i];
        x[1] = data[i].nisn;
        x[2] = data[i].nama;
        x[3] = data[i].tempat;
        x[4] = data[i].lahir;
        x[5] = data[i].kelamin;
        x[6] = data[i].alamat;
          
        j = i - 1;  
  
        while (j >= 0 && dataCari[j] > x[0]) 
        {  
            dataCari[j + 1] = dataCari[j]; 
			data[j+1].nisn = data[j].nisn;
			data[j+1].nama = data[j].nama;
			data[j+1].tempat = data[j].tempat;
			data[j+1].lahir = data[j].lahir;	
			data[j+1].kelamin = data[j].kelamin;
			data[j+1].alamat = data[j].alamat;						
            j = j - 1;  
        }  
        dataCari[j+1] = x[0]; 
        data[j+1].nisn = x[1];
        data[j+1].nama = x[2];
        data[j+1].tempat = x[3]; 
        data[j+1].lahir = x[4];
        data[j+1].kelamin = x[5];  
        data[j+1].alamat = x[6]; 
    }  
} 
int shellSort(kartuPelajar data[],string dataCari[], int n) { 
	string x[7];
	cout<<"Proses Sorting\n";
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i += 1) 
        { 
			for (int k = 0; k < n; k++)
			{
				cout<<dataCari[k]<<" | ";
			} 
			cout<<endl<<endl;	
            x[0] = dataCari[i];
			x[1] = data[i].nisn;
			x[2] = data[i].nama;
			x[3] = data[i].tempat;
			x[4] = data[i].lahir;
			x[5] = data[i].kelamin;
			x[6] = data[i].alamat;
            int j;             
            for (j = i; j >= gap && dataCari[j - gap] > x[0]; j -= gap){  
                dataCari[j] = dataCari[j - gap]; 
				data[j].nisn = data[j - gap].nisn;
				data[j].nama = data[j - gap].nama;
				data[j].tempat = data[j - gap].tempat;
				data[j].lahir = data[j - gap].lahir;	
				data[j].kelamin = data[j - gap].kelamin;
				data[j].alamat = data[j - gap].alamat;
			}
            dataCari[j] = x[0]; 
			data[j].nisn = x[1];
			data[j].nama = x[2];
			data[j].tempat = x[3]; 
			data[j].lahir = x[4];
			data[j].kelamin = x[5];  
			data[j].alamat = x[6];
        } 
    } 
    return 0; 
}  
int partisi(kartuPelajar data[],string dataCari[],int l,int u){//digunakan pada quicksort
    string  v[7];
    int i,j;
	
    v[0] = dataCari[l];
	v[1] = data[l].nisn;
	v[2] = data[l].nama;
	v[3] = data[l].tempat;
	v[4] = data[l].lahir;
	v[5] = data[l].kelamin;
	v[6] = data[l].alamat;
    i=l;
    j=u+1;
    
    do
    {
        do
            i++;
            
        while(dataCari[i]<v[0]&&i<=u);
        
        do
            j--;
        while(v[0]<dataCari[j]);
        
        if(i<j)
        {
			
            tukarStr(&dataCari[i],&dataCari[j]);
            tukarSet(data,i,j);
        }
    }while(i<j);
    dataCari[l] = dataCari[j]; 
	data[l].nisn = data[j].nisn;
	data[l].nama = data[j].nama;
	data[l].tempat = data[j].tempat;
	data[l].lahir = data[j].lahir;	
	data[l].kelamin = data[j].kelamin;
	data[l].alamat = data[j].alamat;
	dataCari[j] = v[0]; 
	data[j].nisn = v[1];
	data[j].nama = v[2];
	data[j].tempat = v[3]; 
	data[j].lahir = v[4];
	data[j].kelamin = v[5];  
	data[j].alamat = v[6]; 
    
    return(j);
}
void quickSort(kartuPelajar data[],string dataCari[],int i,int j){
    int k;
    if(i<j)
    {  
        k=partisi(data,dataCari,i,j);
        quickSort(data,dataCari,i,k-1);
        quickSort(data,dataCari,k+1,j);
    }
}
void merge(string dataCari[], int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    string L[n1][7], R[n2][7]; 
  
    for (i = 0; i < n1; i++) 
        L[i][0] = dataCari[l + i];
        L[i][1] = data[i].nisn;
        L[i][2] = data[i].nama;
        L[i][3] = data[i].tempat;
        L[i][4] = data[i].lahir;
        L[i][5] = data[i].kelamin;
        L[i][6] = data[i].alamat; 
    for (j = 0; j < n2; j++)  
		R[j][0] = dataCari[i];
        R[j][1] = data[i].nisn;
        R[j][2] = data[i].nama;
        R[j][3] = data[i].tempat;
        R[j][4] = data[i].lahir;
        R[j][5] = data[i].kelamin;
        R[j][6] = data[i].alamat;
    i = 0; 
    j = 0;
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i][0] <= R[j][0]) { 
            dataCari[k] = L[i][0]; 
			data[k].nisn = L[i][1];
			data[k].nama = L[i][2];
			data[k].tempat = L[i][3]; 
			data[k].lahir = L[i][4];
			data[k].kelamin = L[i][5];  
			data[k].alamat = L[i][6];
            i++; 
        } 
        else {  
            dataCari[k] = R[j][0]; 
			data[k].nisn = R[j][1];
			data[k].nama = R[j][2];
			data[k].tempat = R[j][3]; 
			data[k].lahir = R[j][4];
			data[k].kelamin = R[j][5];  
			data[k].alamat = R[j][6];
            j++; 
        } 
        k++; 
    } 
  

    while (i < n1) { 
        dataCari[k] = L[i][0]; 
			data[k].nisn = L[i][1];
			data[k].nama = L[i][2];
			data[k].tempat = L[i][3]; 
			data[k].lahir = L[i][4];
			data[k].kelamin = L[i][5];  
			data[k].alamat = L[i][6];
        i++; 
        k++; 
    } 
  

    while (j < n2) { 
        dataCari[k] = R[j][0]; 
			data[k].nisn = R[j][1];
			data[k].nama = R[j][2];
			data[k].tempat = R[j][3]; 
			data[k].lahir = R[j][4];
			data[k].kelamin = R[j][5];  
			data[k].alamat = R[j][6];
        j++; 
        k++; 
    } 
} 
void mergeSort(string dataCari[], int l, int r){ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
 
        mergeSort(dataCari, l, m); 
        mergeSort(dataCari, m + 1, r); 
        merge(dataCari, l, m, r); 
        
    } 
} 
void binarySearch (string dataCari[99], int n, string cari){
	int atas,bawah,tengah;
	bool check;
	string ketemu;
	bubbleSort(data,dataCari,n);//sebelum binary search harus di urutkan terlebih dahulu
	bawah  = 0;
	atas   = n - 1;
	 
	while (bawah <= atas){
		tengah = (atas + bawah) / 2;
		size_t found = dataCari[tengah].find(cari); 
		if (found != string::npos) {
		ketemu = dataCari[tengah];
		check = true;
		break;
		}
		else if (cari < dataCari[tengah]) atas = tengah - 1;
		else if (cari > dataCari[tengah]) bawah= tengah + 1;
		}
	if (check){
		cout << "Ditemukan " << cari << " dalam data" << endl;
		for (int i = 0; i < n; i++)
		{
			size_t found = dataCari[i].find(ketemu); 
			if (found != string::npos) {
				cout<<"\tNISN\t\t: "<<data[i].nisn<<endl;
				cout<<"\tNama\t\t: "<<data[i].nama<<endl;
				cout<<"\tTempat Lahir\t: "<<data[i].tempat<<endl;
				cout<<"\tTanggal Lahir\t: "<<data[i].lahir<<endl;
				cout<<"\tJenis Kelamin\t: "<<data[i].kelamin<<endl;
				cout<<"\tAlamat\t\t: "<<data[i].alamat<<endl;
				cout<<endl;
			}
		}
		
		}
	else{
		cout <<" tidak ditemukan dalam data" << endl;
		}	
}
void sequentialSearch(string dataCari[],kartuPelajar data[],int jml,string cari){
	bool founds;
	int i;
	for (i = 0; i < jml; i++)
	{
			size_t found = dataCari[i].find(cari); 
			if (found != string::npos){ 
				founds = true;
				cout<<"\tNISN\t\t: "<<data[i].nisn<<endl;
				cout<<"\tNama\t\t: "<<data[i].nama<<endl;
				cout<<"\tTempat Lahir\t: "<<data[i].tempat<<endl;
				cout<<"\tTanggal Lahir\t: "<<data[i].lahir<<endl;
				cout<<"\tJenis Kelamin\t: "<<data[i].kelamin<<endl;
				cout<<"\tAlamat\t\t: "<<data[i].alamat<<endl;
				cout<<endl;
			}

	}
	if (!founds)
	{
		cout<<"Data tidak ditemukan\n";
	}
	}
void inputData(char file[99]){
	ofstream myfile;
	int jml;
	

	cout<<"\t******INPUT KARTU PELAJAR******\n";

	
	
	cout<<"Mau input berapa data : ";cin>>jml;
	kartuPelajar input[jml];
	cin.ignore();
	for (int i = 0; i <jml; i++)
	{
		
		cout<<"\tNISN\t\t\t\t: ";getline(cin,input[i].nisn);
		cout<<"\tNama\t\t\t\t: ";getline(cin,input[i].nama);
		cout<<"\tTempat Lahir\t\t\t: ";getline(cin,input[i].tempat);
		cout<<"\tTanggal Lahir(dd-mm-yyyy)\t: ";getline(cin,input[i].lahir);
		cout<<"\tJenis Kelamin(P/L)\t\t: ";getline(cin,input[i].kelamin);
		cout<<"\tAlamat\t\t\t\t: ";getline(cin,input[i].alamat);
		cout<<endl;
		
	}
	myfile.open( file , ios::app);
	if (!myfile.fail())
	{
		 for (int i = 0; i <jml; i++)
		 {
			 myfile<<input[i].nisn<<" \n"<<input[i].nama<<" \n"<<input[i].tempat<<" \n"<<input[i].lahir<<" \n"<<input[i].kelamin<<" \n"<<input[i].alamat<<endl;
		 }
	}
	else
	{
		cout<<"file tidak ditemukan ";
	}
	
	}
void outputData(char file[99],int jml){
	if (jml == 0)
	{
		cout<<"Sorry datanya kosong\n";
	}
	else
	{
		cout<<"\t******DATA KARTU PELAJAR******\n\n";
		for (int i = 0; i < jml ; i++)
		{
			cout<<"\tNISN\t\t: "<<data[i].nisn<<endl;
			cout<<"\tNama\t\t: "<<data[i].nama<<endl;
			cout<<"\tTempat Lahir\t: "<<data[i].tempat<<endl;
			cout<<"\tTanggal Lahir\t: "<<data[i].lahir<<endl;
			cout<<"\tJenis Kelamin\t: "<<data[i].kelamin<<endl;
			cout<<"\tAlamat\t\t: "<<data[i].alamat<<endl;
			cout<<endl;
		}
	cout<<"TOTAL DATA : "<<jml<<endl;
	}	
	}
void outputDataDesc(char file[99],int jml){
	if (jml == 0)
	{
		cout<<"Sorry datanya kosong\n";
	}
	else
	{
		cout<<"\t******DATA KARTU PELAJAR******\n\n";
		for (int i = jml; i >= 0 ; i--)
		{
			cout<<"\tNISN\t\t: "<<data[i].nisn<<endl;
			cout<<"\tNama\t\t: "<<data[i].nama<<endl;
			cout<<"\tTempat Lahir\t: "<<data[i].tempat<<endl;
			cout<<"\tTanggal Lahir\t: "<<data[i].lahir<<endl;
			cout<<"\tJenis Kelamin\t: "<<data[i].kelamin<<endl;
			cout<<"\tAlamat\t\t: "<<data[i].alamat<<endl;
			cout<<endl;
		}
	cout<<"TOTAL DATA : "<<jml<<endl;
	}	
	}
bool checker(char check){//fungsi yang memiliki return boolean digunakan untuk pengecekan perulangan
	if (check == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
	
	}
void searchingData(char file[99],string dataCari[99],kartuPelajar data[],int jml){
	int swit;
	bool search = false;
	string cari;
	do{
	system("cls");
	cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\t\t\t@\t\tMencari Data Siswa\t\t\t  @";
	cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";
	cout<<"Ada 2 Metode\n1. Sequential\n2. Binary\nPILIH : ";cin>>swit;//swit digunakan untuk memilih metode mana yang ingin kita pakai
	if (swit == 1 )
	{
		search = true;
	}
	else if (swit == 2)
	{
	}
	else
	{
		cout<<"salah input\n";
		swit = 3;
		getch();
	}
	}while(swit == 3);
	int select = base(file,dataCari,data);
	cin.ignore();
	switch (select)
		{
			case 1:
				cout<<"Masukkan NISN yang ingin di cari : ";getline(cin,cari);
				break;
			case 2:
				cout<<"Masukkan Nama yang ingin di cari : ";getline(cin,cari);
				break;
			case 3:
				cout<<"Masukkan Tempat yang ingin di cari : ";getline(cin,cari);
				break;
			case 4:
				cout<<"Masukkan Tanggal Lahir yang ingin di cari(dd-mm-yyyy) : ";getline(cin,cari);
				break;
			case 5:
				cout<<"Masukkan Kelamin yang ingin di cari : ";getline(cin,cari);
				break;
			case 6:
				cout<<"Masukkan Alamat yang ingin di cari : ";getline(cin,cari);
				break;			
			default:
			;
		}
	if (search)
	{
		sequentialSearch(dataCari,data,jml,cari);
	}
	else
	{
		binarySearch(dataCari,jml,cari);
	}
	
	}
void sortingData(char file[99],string dataCari[99],kartuPelajar data[],int jml){
	int	swit;
	bool check;
	do{
	do{
	check = false;
	system("cls");
	cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\t\t\t@\t\tMengurutkan Data Siswa\t\t\t  @";
	cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";
	cout<<"Ada 5 Metode"<<"\n1. Selection Sort"<<"\n2. Bubble Sort"<<"\n3. Quick Sort"<<"\n4. Insertion Sort"<<"\n5. Shell Sort"<<"\n6. Merge Sort"<<"\nPILIH : ";cin>>swit;
	if (swit > 6)
	{
		cout<<"Salah input";
		getch();
		check = true;
	}
    }while(check);
	base(file,dataCari,data);
	switch (swit)
	{
		case 1:
			selectionSort(data,dataCari, jml);
			break;
		case 2:
			bubbleSort(data,dataCari, jml);
			break;
		case 3:
			quickSort(data,dataCari, 0, jml-1);
			break;
		case 4:
			insertionSort(data,dataCari,jml);
			break;
		case 5:
			shellSort(data,dataCari, jml);
			break;
		case 6:
			mergeSort(dataCari,0,jml);
			break;	
		default:
			cout<<"Salah input";
			getch();
			check = true;
	}
	}while(check);
	
	}
int main(){
	ofstream omyfile;
	ifstream imyfile;
	bool daftar;
	char pilih;
	int swit,jml,output;
	
	do
	{
		char file[99];
		do{
		system("cls");
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	    cout<<"\t\t\t@\t\t\tKartu Pelajar\t\t\t  @";
	    cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";
		daftar = false;
		cout<<"Sudah punya File Data?(y/n)";cin>>pilih;cin.ignore();//menentukan dulu file mana yang akan kita proses
		if (pilih == 'n'){
			cout<<"\tMembuat File Baru Dengan Nama : ";cin.getline(file,sizeof(file));
			omyfile.open( file );//untuk membikin file baru dengan nama "file"
			omyfile.close();
			break;
			}
		else
		{	
			cout<<"\tMasukkan Nama File : ";cin.getline(file,sizeof(file));
			imyfile.open( file );
			if (imyfile.fail()){//pengecekan apakah file tersebut ada atau tidak
				cout<<"File tidak ditemukan silahkan ulangi\n";
				getch();
				daftar = true;}
			imyfile.close();
		}
		}while(daftar);
		do
		{
		system("cls");
		jml = storeData(file);//refresh data sementara semisal sudah terjadi pengurutan
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout<<"\t\t\t@\t\t\tKartu Pelajar\t\t\t  @";
		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout<<"@@@@@@@@@@@@@@@@\n@@ MENU UTAMA @@\n@@@@@@@@@@@@@@@@\n1. INPUT DATA"<<"\n2. SHOW DATA"<<"\n3. SEARCHING DATA"<<"\n4. SORTING DATA"<<"\n5. KELUAR\n"<<"PILIH : ";cin>>swit;
		switch (swit)
		{
			case 1:
				inputData(file);
				break;
			case 2:
				outputData(file,jml);
				break;
			case 3:
				do
				{
				searchingData(file,dataCari,data,jml);
				cout<<"Apakah ingin mengulagi Menu Searching(y/n)? ";cin>>pilih;	
				} while (checker(pilih));
				
				break;
			case 4:
				do{
				sortingData(file,dataCari,data,jml);
				cout<<"\nMau ditampilkan secara : 1.Ascending 2. Descending : ";cin>>output;
				if (output == 1)
				{
					outputData(file,jml);
				}
				else
				{
					outputDataDesc(file,jml);
				}
				cout<<"Apakah ingin mengulagi Menu Sorting(y/n)? ";cin>>pilih;	
				}while (checker(pilih));
				break;
			case 5:
				break;
			default:
			cout<<"Salah input\n";
		}
		cout<<"Apakah ingin mengulagi Menu Utama(y/n)? ";cin>>pilih;
		} while (checker(pilih));
	cout<<"Apakah ingin mengulagi Memilih File (y/n)? ";cin>>pilih;
	} while (checker(pilih));
	}
