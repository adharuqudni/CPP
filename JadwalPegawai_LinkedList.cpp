#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef int typeinfo;
typedef struct typenode *typeptr;
struct typenode{
		typeinfo info;
		typeptr next;
	};
	
typeptr kepala;
void buatlistbaru();
void sisipdepan(typeinfo IB);
void sisiptengah(typeinfo IB);
void sisipbelakang(typeinfo IB);
void cetaklist();
void cetaktengah(typeinfo IB);

int main(){
	buatlistbaru();
	sisipdepan(1311);
	sisipbelakang(5454);
	sisiptengah(2635);
	sisiptengah(3464);
	sisiptengah(4744);
	
	cout<<"Jadwal Karyawan "<<endl;
	cout<<"Selama 1 bulan \n\n";
	cout<<"\t\t\t0:00 - 07:59\t\t8:00 - 15:59\t\t16:00 - 23:59\n";
	cetaklist();
	
	
	return 0;
				
}

void buatlistbaru(){
	kepala = (typenode *) malloc(sizeof(typenode));
	kepala->next = kepala;
	kepala->info = 8;
}

void sisipbelakang(typeinfo IB){
	 typeptr NB, bantu;
	 NB=(typenode *) malloc(sizeof(typenode));
	 NB->info=IB;
	
	 bantu=kepala;
		while (bantu->next != kepala)
		{
			bantu=bantu->next;
		}
	 NB->next=kepala;
	bantu->next = NB;
}

void sisipdepan(typeinfo IB)
{
	typeptr NB,bantu;
	NB=(typenode *) malloc(sizeof(typenode));
	NB->info=IB;
	bantu = kepala;
	NB->next=bantu->next;
	kepala->next= NB; 
}

void sisiptengah(typeinfo IB)
{ 
	  typeptr NB, bantu;
	  NB=(typenode *) malloc(sizeof(typenode));
	  NB->info=IB;
	  bantu=kepala;
	  while(bantu->next->info<IB)
		bantu=bantu->next;
	  NB->next=bantu->next;
	  bantu->next=NB;
}

void cetaklist()
{ typeptr bantu;
  bantu=kepala->next;
  string hari[7] = {"Senin","Selasa","Rabu","Kamis","Jumat","Sabtu","Minggu"};
  int haricount = 0,i=1;
  while (kepala->info <= 953)
     { 
		if (haricount ==6)
			{	
				cout<<hari[haricount];
				haricount = 0;
			}
			else
			{
				cout<<hari[haricount];
				haricount++;
			} 
		cout<<"\t"<<i<<"  "<<"MARET";
		i++;	
		do{
			
			if (bantu == kepala)
			{
				cout<<"";
			}
			else{
				printf("\t%d\t\t",bantu->info);
				kepala->info += 8;
			}
		bantu=bantu->next; 
		}while ((kepala->info%32 > 0) && kepala->info <= 953 );
			kepala->info += 8;
			cout<<endl;
	}
}
