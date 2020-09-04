#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct user
{
        char name[50];
        char address[30];
        int reqnum;
        double balance;
};

int main()
{
        user newuser[50];
        int i = 0, choice = 0, pos = 0, n=0, dc_value = 0, forloop = 0, pc_value = 0, old_balance = 0, target = 0, balance_sent = 0;
        int num = 0;
        double put = 0, get = 0;
        bool isset = false;
        menu:         
        system("cls");
        cout<<" ____________________________________________________ "<<endl;
        cout<<"||                   ATM Nabskuy                    ||"<<endl;
        cout<<"||__________________________________________________||"<<endl;
        cout<<"||_______________| Menu Transaksi |_________________||"<<endl;
        cout<<"||                                                  ||"<<endl;
        cout<<"||   1. Pendaftaran Nasabah                         ||"<<endl;
        cout<<"||   2. Simpan Tunai                                ||"<<endl;
        cout<<"||   3. Tarik Tunai                                 ||"<<endl;
        cout<<"||   4. Cek Saldo                                   ||"<<endl;
        cout<<"||   5. Transfer Tunai                              ||"<<endl;        
        cout<<"||__________________________________________________||"<<endl;        
        cout<<"||   500. Keluar                                    ||"<<endl;        
        cout<<"||__________________________________________________||"<<endl;
        cout<<"  Pilihan Anda : ";cin>>choice;        

        //Menu Pendaftaran Nasabah
        if(choice == 1)
        {
                //Awal Menu Pendaftaran Nasabah
                system("cls");
                cout<<endl;
                menu_1 :
                cout<<" ____________________________________________________ "<<endl;
                cout<<"||______________ Pendaftaran Nasabah _______________||"<<endl;
                cout<<"||__________________________________________________||"<<endl;
                cout<<endl;
                
                //Input No. Rekening
                reqnum_input :
                cout<<" Masukkan Nomor Rekening Pilihan anda : ";cin>>num;

                for(i=0; i<=n; i++)
                {
                        if(num==(newuser[i].reqnum))
                        {
                                isset = true;
                                break;
                        }
                        else
                                isset = false;
                }

                if(isset)
                {
                        system("cls");
                        cout<<" NO. Rekening "<<num<<" sudah digunakan. Silahkan masukkan no lainnya"<<endl;
                        goto menu_1;
                }
                
                else
                {
                        newuser[n].reqnum = 0;
                        newuser[n].reqnum += num;

                        //Input Data Nasabah
                        data_completion :
                        cout<<" Masukkan Nama Anda       : ";cin>>newuser[n].name;
                        cout<<" Masukkan Alamat Anda     : ";cin>>newuser[n].address;
                        cout<<" Masukkan Saldo Awal Anda : Rp.";cin>>newuser[n].balance;

                        data_view :
                        system("cls");
                        cout<<" Silahkan cek kembali data anda :"<<endl;
                        cout<<endl;
                        cout<<" ____________________________________________________ "<<endl;
                        cout<<"||_______________ Data Nasabah Baru ________________||"<<endl;
                        cout<<"||__________________________________________________||"<<endl;
                        cout<<"||"<<endl;
                        cout<<"|| NO. Rekening Anda : "<<newuser[n].reqnum<<endl;
                        cout<<"|| Nama Anda         : "<<newuser[n].name<<endl;
                        cout<<"|| Alamat Anda       : "<<newuser[n].address<<endl;
                        cout<<"|| Saldo Awal Anda   : Rp."<<newuser[n].balance<<endl;
                        cout<<"||___________________________________________________"<<endl;

                        //Cek kebenaran data
                        data_check :
                        cout<<endl;
                        cout<<" Apakah data tersebut sesuai dengan identitas anda?"<<endl;
                        cout<<" 1. Ya"<<endl;
                        cout<<" 2. Tidak"<<endl;
                        cout<<" Pilihan anda : ";cin>>dc_value;
                        if(dc_value == 1)
                        {
                                //Tambah jumlah User
                                n += 1;
                                cout<<" Data berhasil disimpan!"<<endl;
                                cout<<" Tekan tombol apapun untuk kembali ke menu utama : ";cin>>forloop;
                                goto menu;
                        }

                        else if(dc_value == 2)
                        {
                                newuser[n].reqnum = 0;
                                newuser[n].name == "";
                                newuser[n].address == "";
                                newuser[n].balance = 0;
                                system("cls");
                                goto menu_1; 
                        }
                        else
                        {
                                goto menu;
                        }
                }
        }

        else if(choice == 2)
        {
                system("cls");
                menu_2 :
                cout<<endl;
                cout<<" ____________________________________________________ "<<endl;
                cout<<"||_________________ Simpan Tunai ___________________||"<<endl;
                cout<<"||__________________________________________________||"<<endl;
                cout<<endl;

                //Input No. Rekening
                reqnum_check_put :
                num = 0;
                cout<<" Masukkan nomor rekening anda : ";cin>>num;

                for(i=0; i<=n; i++)
                {
                        if(num==(newuser[i].reqnum))
                        {
                                pos = i;
                                isset = true;
                                break;
                        }
                        else
                                isset = false;
                }

                if (isset)
                {
                        system("cls");
                        cout<<" Silahkan cek kembali data anda :"<<endl;
                        cout<<" ____________________________________________________ "<<endl;
                        cout<<"||_________________ Data Nasabah ___________________||"<<endl;
                        cout<<"||__________________________________________________||"<<endl;
                        cout<<"||"<<endl;
                        cout<<"|| NO. Rekening Anda : "<<newuser[pos].reqnum;cout<<endl;
                        cout<<"|| Nama Anda         : "<<newuser[pos].name;cout<<endl;
                        cout<<"|| Saldo Anda        : Rp."<<newuser[pos].balance;cout<<endl;
                        cout<<"||___________________________________________________"<<endl;
                        cout<<endl;

                        cout<<" Apakah data tersebut sesuai?"<<endl;
                        cout<<" 1. Ya"<<endl;
                        cout<<" 2. Tidak"<<endl;
                        cout<<" Pilihan anda : ";cin>>pc_value;
                        if(pc_value == 1)
                        {
                                cout<<endl;
                                cout<<" Masukkan jumlah uang yang akan disimpan : Rp.";cin>>put;

                                old_balance = 0;
                                old_balance += newuser[pos].balance;
                                newuser[pos].balance += put;

                                system("cls");
                                cout<<" Silahkan cek kembali data anda :"<<endl;
                                cout<<" ____________________________________________________ "<<endl;
                                cout<<"||_________________ Data Nasabah ___________________||"<<endl;
                                cout<<"||__________________________________________________||"<<endl;
                                cout<<"||"<<endl;
                                cout<<"|| NO. Rekening anda     : "<<newuser[pos].reqnum<<endl;
                                cout<<"|| Nama anda             : "<<newuser[pos].name<<endl;
                                cout<<"|| Saldo anda sebelumnya : Rp."<<old_balance<<endl;
                                cout<<"|| Saldo yang disimpan   : Rp."<<put<<endl;
                                cout<<"|| Saldo akhir anda      : Rp."<<newuser[pos].balance<<endl;                                                      
                                cout<<"||___________________________________________________"<<endl;
                                cout<<endl;
                                cout<<" Data berhasil diperbaharui!"<<endl;
                                cout<<" Tekan tombol apapun untuk kembali ke menu utama : ";cin>>forloop;
                                put = 0;
                                goto menu;  
                        }
                        else if(pc_value == 2)
                        {
                                system("cls");
                                goto menu_2;
                        }
                        else
                        {
                                system("exit");
                        }
                }

                else
                {
                        system("cls");
                        cout<<" Akun tidak ditemukan. Silahkan cek kembali nomor rekening anda : "<<num<<endl;
                        goto menu_2;
                }

        }

        else if(choice == 3)
        {
                system("cls");
                menu_3 :
                cout<<endl;
                cout<<" ____________________________________________________ "<<endl;
                cout<<"||__________________ Tarik Tunai ___________________||"<<endl;
                cout<<"||__________________________________________________||"<<endl;
                cout<<endl;

                //Input No. Rekening
                reqnum_check_get :
                num = 0;
                cout<<" Masukkan nomor rekening anda : ";cin>>num;
                isset = false;
                for(i=0; i<=n; i++)
                {
                        if(num==(newuser[i].reqnum))
                        {
                                pos = i;
                                isset = true;
                                break;
                        }
                        else
                                isset = false;
                }
                if (isset)
                {
                        system("cls");
                        cout<<" Silahkan cek kembali data anda :"<<endl;
                        cout<<" ____________________________________________________ "<<endl;
                        cout<<"||_________________ Data Nasabah ___________________||"<<endl;
                        cout<<"||__________________________________________________||"<<endl;
                        cout<<"||"<<endl;
                        cout<<"|| NO. Rekening Anda : "<<newuser[pos].reqnum;cout<<endl;
                        cout<<"|| Nama Anda         : "<<newuser[pos].name;cout<<endl;
                        cout<<"|| Saldo Anda        : Rp."<<newuser[pos].balance;cout<<endl;
                        cout<<"||___________________________________________________"<<endl;
                        cout<<endl;

                        cout<<" Apakah data tersebut sesuai?"<<endl;
                        cout<<" 1. Ya"<<endl;
                        cout<<" 2. Tidak"<<endl;
                        cout<<" Pilihan anda : ";cin>>pc_value;
                        if(pc_value == 1)
                        {
                                cout<<endl;
                                cout<<" Masukkan jumlah uang yang akan diambil : Rp.";cin>>get;

                                old_balance = 0;
                                old_balance += newuser[pos].balance;
                                newuser[pos].balance -= get;

                                system("cls");
                                cout<<" Silahkan cek kembali data anda :"<<endl;
                                cout<<" ____________________________________________________ "<<endl;
                                cout<<"||_________________ Data Nasabah ___________________||"<<endl;
                                cout<<"||__________________________________________________||"<<endl;
                                cout<<"||"<<endl;
                                cout<<"|| NO. Rekening anda     : "<<newuser[pos].reqnum<<endl;
                                cout<<"|| Nama anda             : "<<newuser[pos].name<<endl;
                                cout<<"|| Saldo anda sebelumnya : Rp."<<old_balance<<endl;
                                cout<<"|| Saldo yang diambil    : Rp."<<get<<endl;
                                cout<<"|| Saldo akhir anda      : Rp."<<newuser[pos].balance<<endl;                                                      
                                cout<<"||___________________________________________________"<<endl;
                                cout<<endl;
                                cout<<" Data berhasil diperbaharui! Silahkan ambil uang anda."<<endl;
                                cout<<" Tekan tombol apapun untuk kembali ke menu utama : ";cin>>forloop;
                                get = 0;
                                goto menu;  
                        }
                        else if(pc_value == 2)
                        {
                                system("cls");
                                goto menu_3;
                        }
                        else
                        {
                                goto menu_3;
                        }
                }
                
                else
                {
                        system("cls");
                        cout<<" Akun tidak ditemukan. Silahkan cek kembali nomor rekening anda : "<<num<<endl;
                        goto menu_3;
                }
        }

        else if(choice == 4)
        {
                system("cls");
                menu_4 :
                cout<<endl;
                cout<<" ____________________________________________________ "<<endl;
                cout<<"||___________________ Cek Saldo ____________________||"<<endl;
                cout<<"||__________________________________________________||"<<endl;
                cout<<endl;

                //Input No. Rekening
                reqnum_check_datacheck :
                num = 0;
                cout<<" Masukkan nomor rekening anda : ";cin>>num;
                isset = false;
                for(i=0; i<=n; i++)
                {
                        if(num==(newuser[i].reqnum))
                        {
                                pos = i;
                                isset = true;
                                break;
                        }
                        else
                                isset = false;
                }
                if(isset)
                {
                        system("cls");
                        cout<<" Silahkan cek kembali data anda :"<<endl;
                        cout<<" ____________________________________________________ "<<endl;
                        cout<<"||_________________ Data Nasabah ___________________||"<<endl;
                        cout<<"||__________________________________________________||"<<endl;
                        cout<<"||"<<endl;
                        cout<<"|| NO. Rekening Anda : "<<newuser[pos].reqnum;cout<<endl;
                        cout<<"|| Nama Anda         : "<<newuser[pos].name;cout<<endl;
                        cout<<"|| Saldo Anda        : Rp."<<newuser[pos].balance;cout<<endl;
                        cout<<"||___________________________________________________"<<endl;
                        cout<<endl;
                        cout<<" Data berhasil Ditemukan!"<<endl;
                        cout<<" Tekan tombol apapun untuk kembali ke menu utama : ";cin>>forloop;
                        goto menu;
                }       

                else
                {
                        system("cls");
                        cout<<" Akun tidak ditemukan. Silahkan cek kembali nomor rekening anda : "<<num<<endl;
                        goto menu_4;
                }            
        }

        else if(choice == 5)
        {
                system("cls");
                menu_5 :
                cout<<endl;
                cout<<" ____________________________________________________ "<<endl;
                cout<<"||________________ Transfer Tunai __________________||"<<endl;
                cout<<"||__________________________________________________||"<<endl;
                cout<<endl;

                //Input No. Rekening
                reqnum_check_transfer_1 :
                num = 0;
                cout<<" Masukkan nomor rekening anda : ";cin>>num;
                isset = false;
                for(i=0; i<=n; i++)
                {
                        if(num==(newuser[i].reqnum))
                        {
                                pos = i;
                                isset = true;
                                break;
                        }
                        else
                                isset = false;
                }

                if(isset)
                {
                        system("cls");
                        cout<<" Silahkan cek kembali data anda :"<<endl;
                        cout<<" ____________________________________________________ "<<endl;
                        cout<<"||_________________ Data Nasabah ___________________||"<<endl;
                        cout<<"||__________________________________________________||"<<endl;
                        cout<<"||"<<endl;
                        cout<<"|| NO. Rekening Anda : "<<newuser[pos].reqnum;cout<<endl;
                        cout<<"|| Nama Anda         : "<<newuser[pos].name;cout<<endl;
                        cout<<"|| Saldo Anda        : Rp."<<newuser[pos].balance;cout<<endl;
                        cout<<"||___________________________________________________"<<endl;
                        cout<<endl;
                        cout<<" Data berhasil Ditemukan!"<<endl;
                        cout<<endl;

                        cout<<" Masukkan nominal tunai yang akan di transfer : Rp.";cin>>balance_sent;
                        cout<<endl;

                        reqnum_check_transfer_2 :
                        num = 0;
                        cout<<" Masukkan nomor rekening tujuan : ";cin>>num;
                        isset = false;
                        for(i=0; i<=n; i++)
                        {
                                if(num==(newuser[i].reqnum))
                                {
                                        target = i;
                                        isset = true;
                                        break;
                                }
                                else
                                        isset = false;
                        }
                        if(isset)
                        {
                                system("cls");
                                cout<<" Silahkan cek kembali data tujuan :"<<endl;
                                cout<<" ____________________________________________________ "<<endl;
                                cout<<"||_________________ Data Nasabah ___________________||"<<endl;
                                cout<<"||__________________________________________________||"<<endl;
                                cout<<"||"<<endl;
                                cout<<"|| NO. Rekening tujuan : "<<newuser[target].reqnum;cout<<endl;
                                cout<<"|| Nama Nasabah        : "<<newuser[target].name;cout<<endl;
                                cout<<"||___________________________________________________"<<endl;
                                cout<<endl;
                                cout<<" Data berhasil Ditemukan!"<<endl;
                                cout<<endl;
                                old_balance = 0;
                                old_balance += newuser[pos].balance;
                                newuser[pos].balance -= balance_sent;
                                newuser[target].balance += balance_sent;

                                cout<<" Tekan tombol apapun untuk kembali melanjutkan : ";cin>>forloop;

                                system("cls");
                                cout<<" Berikut bukti transaksi transfer anda :"<<endl;
                                cout<<" ____________________________________________________ "<<endl;
                                cout<<"||_______________ Bukti Transaksi __________________||"<<endl;
                                cout<<"||__________________________________________________||"<<endl;
                                cout<<"||                       | "<<endl;
                                cout<<"|| NO. Rekening Pengirim | "<<newuser[pos].reqnum<<endl;
                                cout<<"|| Nama Pengirim         | "<<newuser[pos].name<<endl;
                                cout<<"|| Saldo akhir           | Rp."<<newuser[pos].balance<<endl;                                                      
                                cout<<"||_______________________|___________________________"<<endl;
                                cout<<"|| Saldo yang ditransfer | Rp."<<balance_sent<<endl;                                
                                cout<<"||_______________________|___________________________"<<endl;                                
                                cout<<"|| NO. Rekening Penerima | "<<newuser[target].reqnum<<endl;
                                cout<<"|| Nama Nasabah          | "<<newuser[target].name<<endl;
                                cout<<"|| Saldo akhir penerima  | Rp."<<newuser[target].balance<<endl;
                                cout<<"||_______________________|___________________________"<<endl;
                                cout<<endl;
                                cout<<" Data berhasil diperbaharui!"<<endl;
                                cout<<" Tekan tombol apapun untuk kembali ke menu utama : ";cin>>forloop;
                                balance_sent = 0;
                                goto menu;          
                        }        
                        else
                        {
                                system("cls");
                                cout<<" Akun yang anda maksud tidak ditemukan.\n Silahkan cek kembali nomor rekening tujuan : "<<num<<endl;
                                goto reqnum_check_transfer_2;
                        }                  
                }
                else
                {
                        system("cls");
                        cout<<" Akun anda tidak ditemukan. Silahkan cek kembali nomor rekening anda : "<<num<<endl;
                        goto menu_5;
                }  
        }

        else if(choice == 500)
        {
                system("cls");
                system("exit");
        }

        else{
                goto menu;
        }
}