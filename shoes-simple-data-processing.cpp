/* All Right Reserved */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

// Prosedur Input
void inputNew(int kd, char seri[],char merk[],int size);
void inputSplitA(int kd, char seri[],char merk[],int size);
void inputSplitB(int kd, char seri[],char merk[],int size);
void inputMerge(int kd, char seri[],char merk[],int size);
void inputBegin(int kd, char seri[],char merk[],int size);
void inputLast(int kd, char seri[],char merk[],int size);

// Prosedur Searching
void inputSearch(int kd, char seri[],char merk[],int size);

// Prosedur Hapus Data
void deleteData(int kd, char seri[],char merk[],int size);
void deleteDataSplitA();
void deleteDataSplitB();
void deleteDataMerge();
void deleteDataPosisi(int kd, char seri[],char merk[],int size);

// Prosedur Sorting
void sortMinMax();

void average();
void showAll();
void showAll2();
void showSplitA();
void showSplitB();
void showMerge();

struct sepatu{
	int kode;
	char series[200];
	char merk[200];
	int sizes;
	sepatu*next;
};

sepatu *awal, *akhir, *baru, *splitA, *splitB, *merge, *awalSplitA, *awalSplitB, *akhirSplitA, *akhirSplitB, *awalMerge, *akhirMerge, *pnow;

int main(){
	system("cls");
	int pil;
	int id, size;
	char seri[200], merk[200];

	menu:
	
	cout << endl;	
	
	cout<<"   ************************************************************************" << endl;
	cout<<"  |                        DATA SEPATU U-TAMA SHOES                        |" << endl;
	cout<<"  |------------------------------------------------------------------------|" << endl;
	cout<<"  | Menu Program:                                                          |" << endl;
	cout<<"  |                                                                        |" << endl;
	cout<<"  |    1. Input Data Sepatu                                                |" << endl;
	cout<<"  |    2. Cari Data Sepatu                                                 |" << endl;
	cout<<"  |    3. Delete Data Sepatu                                               |" << endl;
	cout<<"  |    4. Split Data Sepatu                                                |" << endl;
	cout<<"  |    5. Merge Data Sepatu                                                |" << endl;
	cout<<"  |    6. Sorting Data Sepatu                                              |" << endl;
	cout<<"  |    7. Lihat Data Sepatu                                                |" << endl;
	cout<<"  |                                                                        |" << endl;
	cout<<"  |    0. Exit                                                             |" << endl;
	cout<<"   ************************************************************************" << endl << endl;

	cout<<"  Pilih menu : "; cin>>pil;

	switch(pil){
		case 1:{
			system("cls");

			case1:
			int pil1;

            cout<<"  **************************************************" << endl;
			cout<<" |               INPUT DATA SEPATU                  |" << endl;
			cout<<"  --------------------------------------------------" << endl << endl;
			cout<<" Metode Input" << endl << endl;
			// cout<<"   1. Input data default" << endl;
			cout<<"   1. Input data di awal" << endl;
			cout<<"   2. Input data di akhir" << endl;
			cout<<"   3. Kembali" << endl << endl;

			cout << endl << " Pilih menu : "; cin>>pil1;

			switch(pil1){
				case 1:{
					system("cls");
					
					cout<<"  **************************************************" << endl;
                    cout<<" |             INPUT DATA SEPATU DIAWAL             |" << endl;
                    cout<<"  --------------------------------------------------" << endl << endl;
                    
					case2a:
					char pilihan;
					
					cout<<" Kode Sepatu  : "; cin >> id;
					cout<<" Series       : "; cin >> seri;
					cout<<" Merk Sepatu  : "; cin >> merk;
					cout<<" Ukuran       : "; cin >> size;
					
					cout << endl;
					
					inputBegin(id,seri,merk,size);

					cout << " Tambah data lagi (Y/N)? ";
					
					fflush(stdin);
					cin >> pilihan;

					if(pilihan == 'Y'|| pilihan == 'y'){
						cout << endl << " --------------------------------------------------" << endl << endl;
						goto case2a;
					}
					else{
						system("cls");
						goto case1;
					}
					
					break;
				}

				case 2:{
					system("cls");
					
					cout<<"  **************************************************" << endl;
                    cout<<" |            INPUT DATA SEPATU DIAKHIR             |" << endl;
                    cout<<"  --------------------------------------------------" << endl << endl;
					
					case3a:
					char pilihan;
					
					cout<<" Kode Sepatu  : "; cin >> id;
					cout<<" Series       : "; cin >> seri;
					cout<<" Merk Sepatu  : "; cin >> merk;
					cout<<" Ukuran       : "; cin >> size;
					
					cout << endl;
					
					inputLast(id,seri,merk,size);

					cout << " Tambah data lagi (Y/N)? ";
					
					fflush(stdin);
					cin >> pilihan;

					if(pilihan == 'Y'|| pilihan == 'y'){
						cout << endl << " --------------------------------------------------" << endl << endl;
						goto case3a;
					}
					else{
						system("cls");
						goto case1;
					}
					
					break;
				}

				case 3:{
					system("cls");
					goto menu;
					break;
				}
			}
			break;
		}

		case 2:{
			char pilihan;
			case2:

			inputSearch(id,seri,merk,size);

			cout << endl << endl << " Cari Series Sepatu Lagi? [Y/N] ";
			fflush(stdin);
			cin>>pilihan;
			cout<<"\n";

			if(pilihan == 'Y'||pilihan == 'y'){
				system("cls");
				goto case2;
			}
			else{
				system("cls");
				goto menu;
			}
			break;
		}

		case 3:{
			system("cls");
			case3:
			int pil3;
			char pilihan;

			cout<<"  **************************************************" << endl;
            cout<<" |              DELETE DATA SEPATU                  |" << endl;
            cout<<"  --------------------------------------------------" << endl << endl;

			deleteDataPosisi(id,seri,merk,size);
			
			cout << endl << " Kembali ke menu (Tekan Y)";

			fflush(stdin);

			cin >> pilihan;
			cout << endl;

			if(pilihan == 'Y' || pilihan == 'y'){
				system("cls");
				goto menu;
			}
			else{
				system("cls");
				goto menu;
			}

			break;
		}

		case 4:{
			case4:
			char pilihan;
			char splitSepatu;
			system("cls");

			cout << "  **************************************************" << endl;
		    cout << " |              SPLIT DATA SEPATU                   |" << endl;
		    cout << "  --------------------------------------------------" << endl;
						
			cout << endl;
			
			sepatu *pnow;
			pnow = awal;
			
        deleteDataSplitA();
        deleteDataSplitB();
        
				if(pnow != NULL){
					while(pnow != NULL){
            if (pnow->sizes < 25) {
              inputSplitA(pnow->kode, pnow->series, pnow->merk, pnow->sizes);
              pnow=pnow->next;
            }
            else {
              inputSplitB(pnow->kode, pnow->series, pnow->merk, pnow->sizes);
              pnow=pnow->next;
            }
					}
          showSplitA();
          
          cout << endl;
          
          showSplitB();
				}
				else if(pnow == NULL){
					cout << " Belum ada data." << endl;
				}	

			cout << endl;
			
			cout << endl << " Kembali ke menu utama (Tekan Y) ";
			fflush(stdin);

			cin >> pilihan;
			cout << endl;
			
			if(pilihan == 'Y' || pilihan == 'y') {
				system("cls"); // hapus
				goto menu; // case6
			} else {
				system("cls");
				goto menu;
			}		

			break;
		}

		case 5:{
			system("cls");

			cout<<"  **************************************************" << endl;
            cout<<" |                 MERGE DATA SEPATU                |" << endl;
            cout<<"  --------------------------------------------------" << endl << endl;

            case5:
			char pilihan;

			sepatu *pnow1, *pnow2;
			pnow1 = awalSplitA;
			pnow2 = awalSplitB;
			
			// sortMinMax();
      deleteDataMerge();

      if(pnow1 != NULL || pnow2 != NULL){
        if(pnow1 != NULL){
          while(pnow1 != NULL){
            inputMerge(pnow1->kode, pnow1->series, pnow1->merk, pnow1->sizes);
            pnow1=pnow1->next;
          }
        }
        if(pnow2 != NULL){
          while(pnow2 != NULL){
            inputMerge(pnow2->kode, pnow2->series, pnow2->merk, pnow2->sizes);
            pnow2=pnow2->next;
          }
        }
        showMerge();
      }
      else {
        cout << " Belum ada data." << endl;
      }	

      cout << endl << endl;
			
			cout << " Kembali ke menu utama (Tekan Y) ";
			fflush(stdin);

			cin >> pilihan;
			cout << endl;
			
			if(pilihan == 'Y' || pilihan == 'y') {
				system("cls"); // hapus
				goto menu; // case6
			} else {
				system("cls");
				goto menu;
			}			

			break;
		}

		case 6:{
			system("cls");

			cout<<"  **************************************************" << endl;
            cout<<" |            SORTING MIN MAX DATA SEPATU           |" << endl;
            cout<<"  --------------------------------------------------" << endl << endl;

			case6:
			char pilihan;
			
			sortMinMax();
			
			cout << " Kembali ke menu utama (Tekan Y) ";
			fflush(stdin);

			cin >> pilihan;
			cout << endl;
			
			if(pilihan == 'Y' || pilihan == 'y') {
				system("cls"); // hapus
				goto menu; // case6
			} else {
				system("cls");
				goto menu;
			}			

			break;
		}

		case 7:{
			char pilihan;
			system("cls");

			cout << endl << " Data Seluruh Sepatu: ";

			cout << endl << endl << endl << endl;
			
			showAll();

			cout << endl << endl << endl << " Kembali ke menu utama (Tekan Y) ";
			fflush(stdin);

			cin >> pilihan;
			cout << endl;

			if(pilihan == 'Y'||pilihan == 'y'){
				system("cls");
				goto menu;
			}
			else{
				system("cls");
				goto menu;
			}
			break;
		}

		default :{
			cout << endl << "  Menutup program... (Press any key)" << endl;
        	getch();
		}
	}
}

void inputNew(int kd, char seri[], char merk[], int size){
	baru = new sepatu;
	baru->kode = kd;
	strcpy(baru->series, seri);
	strcpy(baru->merk, merk);
	baru->sizes  =size;
	baru->next = NULL;

	if(awal == NULL){
		awal = baru;
		akhir = baru;
		// baru->next = NULL;
	}
	else{
		baru->next = awal;
		awal = baru;
	}
}

void inputSplitA(int kd, char seri[], char merk[], int size){
	splitA = new sepatu;
	splitA->kode = kd;
	strcpy(splitA->series, seri);
	strcpy(splitA->merk, merk);
	splitA->sizes  =size;
	splitA->next = NULL;

	if(awalSplitA == NULL){
		awalSplitA = splitA;
		akhirSplitA = splitA;
		// splitA->next = NULL;
	}
	else{
		splitA->next = awalSplitA;
		awalSplitA = splitA;
	}
}

void inputSplitB(int kd, char seri[], char merk[], int size){
	splitB = new sepatu;
	splitB->kode = kd;
	strcpy(splitB->series, seri);
	strcpy(splitB->merk, merk);
	splitB->sizes  =size;
	splitB->next = NULL;

	if(awalSplitB == NULL){
		awalSplitB = splitB;
		akhirSplitB = splitB;
		// splitB->next = NULL;
	}
	else{
		splitB->next = awalSplitB;
		awalSplitB = splitB;
	}
}

void inputMerge(int kd, char seri[], char merk[], int size){
	merge = new sepatu;
	merge->kode = kd;
	strcpy(merge->series, seri);
	strcpy(merge->merk, merk);
	merge->sizes  =size;
	merge->next = NULL;

	if(awalMerge == NULL){
		awalMerge = merge;
		akhirMerge = merge;
		// merge->next = NULL;
	}
	else{
		merge->next = awalMerge;
		awalMerge = merge;
	}
}

void inputBegin(int kd, char seri[], char merk[], int size){
	baru = new sepatu;
	baru->kode = kd;
	strcpy(baru->series, seri);
	strcpy(baru->merk,merk);
	baru->sizes = size;

	if(awal == NULL){
		awal = baru;
		akhir = baru;
		baru->next = NULL;
	}
	else{
		baru->next = awal;
		awal = baru;
	}
}

void inputLast(int kd, char seri[],char merk[],int size){
	baru = new sepatu;
	baru->kode = kd;
	strcpy(baru->series, seri);
	strcpy(baru->merk,merk);
	baru->sizes = size;
	baru->next = NULL;

	if(awal==NULL){
		awal=baru;
		akhir=baru;

	}
	else{
		akhir->next=baru;
		akhir=baru;

	}
}

void inputSearch(int kd, char seri[], char merk[], int size){
	system("cls");
	sepatu *pnow;
	pnow = awal;
	
	char inputSearch[200];
	
	cout<<"  **************************************************" << endl;
    cout<<" |               Cari DATA SEPATU                   |" << endl;
    cout<<"  --------------------------------------------------" << endl << endl;
	
	cout<<" Masukan series yang akan Cari: ";
	cin>>inputSearch;

	cout << endl << endl;
	
  cout << " Hasil Pencarian: " << endl;
  cout << " --------------------------" << endl << endl;

  if (pnow == NULL) {
    cout<<"Tidak Ada Data Sepatu";
  }

	while(pnow != NULL){
    if(strcmp(pnow->series, inputSearch) == 0){

      cout<<" Kode Sepatu  : " << pnow->kode << endl;
      cout<<" Series       : " << pnow->series << endl;
      cout<<" Merk Sepatu  : " << pnow->merk << endl;
      cout<<" Ukuran       : " << pnow->sizes << endl;

      cout << endl;
    }
		pnow=pnow->next;
	}

}

void deleteDataSplitA(){
	sepatu *pnow;
	awalSplitA;
	while(awalSplitA != NULL){
    pnow = awalSplitA;
      awalSplitA = awalSplitA->next;
      delete pnow;
		// cout<<" List Kosong !\n";
	}
}

void deleteDataSplitB(){
	sepatu *pnow;
	awalSplitB;
	while(awalSplitB != NULL){
    pnow = awalSplitB;
      awalSplitB = awalSplitB->next;
      delete pnow;
		// cout<<" List Kosong !\n";
	}
}

void deleteDataMerge(){
	sepatu *pnow;
	awalMerge;
	while(awalMerge != NULL){
    pnow = awalMerge;
      awalMerge = awalMerge->next;
      delete pnow;
		// cout<<" List Kosong !\n";
	}
}

void deleteData(int kd, char seri[], char merk[], int size){
	sepatu *pnow;
	if(awal==NULL){
		cout<<" Belum ada data" << endl;
	}
	else{
 	pnow = awal;
  	awal = awal->next;
  	delete pnow;
	}
}

void deleteDataPosisi(int kd,char seri[], char merk[], int size){
	int bdata,posisi,poshapus;
		sepatu *bantu;

		if(awal != NULL){
			cout<<" Masukan Posisi yang akan dihapus : ";
			cin>>posisi;
			bdata=1;
			bantu=awal;

			while(bantu->next != NULL){
				bantu=bantu->next;
				bdata++;
			}
			if((posisi<1)||(posisi>bdata)){
				cout<<" Belum ada data." << endl;
			}
			else{
				bantu=awal;
				poshapus=1;

				while(poshapus<(posisi-1)){
					bantu=bantu->next;
					poshapus++;
				}
				pnow=bantu->next;
				bantu->next=pnow->next;
				delete pnow;
				cout<< endl <<" Berhasil " << endl;
			}
		}
		else{
			cout<<" Belum ada data" << endl;
		}
}

void sortMinMax(){
	sepatu *pnow;
	int kd,kd1;
	char seri[200], nm1[200];
	char merk[200], jrs1[200];
	int size, size1 = 0;

	pnow=awal;
	while(pnow != NULL){
		if (size < pnow->sizes){
			kd = pnow->kode;
			strcpy(seri, pnow->series);
			strcpy(merk, pnow->merk);
			size = pnow->sizes;
		}
		if( size > pnow->sizes){
			kd1 = pnow->kode;
			strcpy(nm1, pnow->series);
			strcpy(jrs1, pnow->merk);
			size1 = pnow->sizes;
		}
		pnow=pnow->next;
	}

	cout << " Data Maksimum Ukuran Sepatu" << endl << endl;
	cout << " KODE\t\tSERIES\t\tMERK\t\tSIZE       " << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "   " << kd << "\t\t" << seri << "\t\t" << merk << "\t\t" << size << endl;
		
	cout << endl << endl << endl;

	cout << " Data Minimum Ukuran Sepatu" << endl << endl;
	cout << " KODE\t\tSERIES\t\tMERK\t\tSIZE       " << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "   " << kd1 << "\t\t" << nm1 << "\t\t" << jrs1 << "\t\t" << size1 << endl;
	
	cout << endl << endl;
}

void average(){
	sepatu *pnow;
	pnow = awal;
	float average1=0;
	float bagi1=0;

	while(pnow !=NULL){
		average1=average1 + pnow->sizes;
		bagi1=bagi1+1;
		pnow=pnow->next;
	}
	average1 = average1/bagi1;
	cout << " average-average Ukuran Sepatu : " << average1;
}

void showAll2(){
	sepatu *pnow;
	pnow = awal;
	int idx=0;
	cout<<"ID\t Series \t Merk \t Ukuran\n";
	while(pnow != NULL){
		idx++;
		cout<<pnow->kode<<"\t"<<pnow->series<<"\t"<<pnow->merk<<"\t"<<pnow->sizes;
		pnow=pnow->next;
	}
	cout<<"\n";
	cout<<"Jumlah Data Sepatu : "<<idx;
}

void showAll(){
	sepatu *pnow;
	pnow = awal;

	cout << " KODE        SERIES\t\tMERK\t\tSIZE       " << endl;
	cout << "------------------------------------------------------" << endl;
	
	while(pnow != NULL){
		cout << " " << pnow->kode << "           " << pnow->series << "\t\t" << pnow->merk << "\t\t" << pnow->sizes << endl;
		pnow=pnow->next;
	}
}

void showSplitA(){
	sepatu *pnow;
	pnow = awalSplitA;

	cout << " Sepatu Anak-Anak (Size < 25) " << endl << endl;
	cout << " KODE        SERIES\t\tMERK\t\tSIZE       " << endl;
	cout << "------------------------------------------------------" << endl;
	
	while(pnow != NULL){
		cout << " " << pnow->kode << "           " << pnow->series << "\t\t" << pnow->merk << "\t\t" << pnow->sizes << endl;
		pnow=pnow->next;
	}
	// cout << "------------------------------------------------------" << endl;
}

void showSplitB(){
	sepatu *pnow;
	pnow = awalSplitB;

	cout << " Sepatu Dewasa (Size >= 25) " << endl << endl;
	cout << " KODE        SERIES\t\tMERK\t\tSIZE       " << endl;
	cout << "------------------------------------------------------" << endl;
	
	while(pnow != NULL){
		cout << " " << pnow->kode << "           " << pnow->series << "\t\t" << pnow->merk << "\t\t" << pnow->sizes << endl;
		pnow=pnow->next;
	// cout << "------------------------------------------------------" << endl;
	}
}

void showMerge(){
	sepatu *pnow;
	pnow = awalMerge;

	cout << " Gabungan Sepatu Anak-Anak dan Sepatu Dewasa " << endl << endl;
	cout << " KODE        SERIES\t\tMERK\t\tSIZE       " << endl;
	cout << "------------------------------------------------------" << endl;
	
	while(pnow != NULL){
		cout << " " << pnow->kode << "           " << pnow->series << "\t\t" << pnow->merk << "\t\t" << pnow->sizes << endl;
		pnow=pnow->next;
	// cout << "------------------------------------------------------" << endl;
	}
}
