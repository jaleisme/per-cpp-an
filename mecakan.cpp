#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Siswa{
	int pk;
	string nis;
	string nama;
	string jurusan;
};

int getOption();
int getDataSize(fstream &data);
void checkfile(fstream &data);
void addStudentData(fstream &data);
void viewStudentData(fstream &data);
void writeData(fstream &data, int position, Siswa &inputSiswa);
Siswa readData(fstream &data, int position);

int main(){
	fstream data;
	checkfile(data);
	int option = getOption();
	char is_continue;

	enum multi_option
	{
		CREATE = 1, READ, UPDATE, DELETE, FINISH
	};

	while(option != FINISH){
		
		switch(option){
			case CREATE:
				cout << "Tambah data siswa" << endl;
				addStudentData(data);
				break;
			case READ:
				cout << "Tampilkan data siswa" << endl;
				break;
			case UPDATE:
				cout << "Ubah data siswa" << endl;
				break;
			case DELETE:
				cout << "Hapus data siswa" <<endl;
				break;
			default:
				cout << "Opsi tidak tersedia" << endl;
				break;
		}
		checkpoint1 :
		cout<<"Lanjutkan?(y/n) : ";
		cin >> is_continue;
		
		if((is_continue == 'y') | (is_continue == 'Y')){

		}

		else if((is_continue == 'n') | (is_continue == 'N')){
			break;
		}

		else{
			goto checkpoint1;
		}

		option = getOption();
	}
	cout << "Goodbye." << endl;
	cin.get();
	return 0;
}

int getOption(){
	int input;
	system("cls");
	cout << " _________________________" 	<< endl;
	cout << "| Program CRUD data siswa |" 	<< endl;
	cout << "|_________________________|" 	<< endl;
	cout << "| 1. Tambah data siswa    |" 	<< endl;
	cout << "| 2. Tampilkan data siswa |" 	<< endl;
	cout << "| 3. Ubah data siswa      |" 	<< endl;
	cout << "| 4. Hapus data siswa     |" 	<< endl;
	cout << "| 5. Selesai              |" 	<< endl;
	cout << "|_________________________|" 	<< endl;
	cout << "Pilih [1-5]? : ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return input;
}

void checkfile(fstream &data){
	data.open("data.bin", ios::out | ios::in | ios::binary);
	// Check File if exists
	if(data.is_open()){
		cout<<"Data exists"<<endl;
	}
	else{
		cout<<"Data doesn't exist"<<endl;
		data.close();
		data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
	}
}

void addStudentData(fstream &data){

	Siswa inputSiswa, lastSiswa;

	int size = getDataSize(data);
	cout<<"Size file awal: "<<size<<endl;
	if(size == 0){
		inputSiswa.pk = 1;		
	}
	else{
		lastSiswa = readData(data,size);
		cout<<"Entry existed: "<<lastSiswa.pk<<endl;
		inputSiswa.pk = lastSiswa.pk+1;
	}
	cout<<"Nama: ";
	getline(cin, inputSiswa.nama);
	cout<<"Nis: ";
	getline(cin, inputSiswa.nis);
	cout<<"Jurusan: ";
	getline(cin, inputSiswa.jurusan);

	writeData(data,size+1,inputSiswa);
}

void writeData(fstream &data, int position, Siswa &inputSiswa){
	data.seekp((position-1)*sizeof(Siswa), ios::beg);
	data.write(reinterpret_cast<char*>(&inputSiswa), sizeof(Siswa));
}

int getDataSize(fstream &data){
	int start, end;
	data.seekg(0,ios::beg);
	start = data.tellg();
	data.seekg(0, ios::end);
	end = data.tellg();
	return (end-start)/sizeof(Siswa);
}

Siswa readData(fstream &data, int position){
	Siswa readSiswa;
	data.seekg((position-1)*sizeof(Siswa),ios::beg);
	data.read(reinterpret_cast<char*>(&readSiswa), sizeof(Siswa));
	return readSiswa;
}

void viewStudentData(fstream &data){}