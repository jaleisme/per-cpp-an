#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main()
{
       //stream untuk membaca file
       ifstream myfile;
       char sv_text;

       //membuka file yang telah ada
       myfile.open("TEST.txt");

       cout<<"OPERASI FILE 2"<<endl;
       cout<<"--------------"<<endl;

       //fail() -> untuk memeriksa suatu pada kesalahan operasi file
       if(!myfile.fail())
       {
              cout<<"Isi dari File -> ";
              //ulang selama program belum mencapai akhir konten dari file
              while (!myfile.eof())
              {
                     myfile.get(sv_text);
                     cout<<sv_text;
              }
              myfile.close(); //menutup file
       }else{
              cout<<"File tidak ditemukan"<<endl;
       }
      
       _getche();
       return EXIT_SUCCESS;
}