#include<stdio.h>
int main() {
int array_a[5]={0,3,6,10,1};
int i, cari, flag=0;
printf("Masukkan data yang ingin dicari : ");
scanf("%i",&cari);
for (i=0;i<5;i++) {
if (array_a[i]==cari) {
flag=1;
break;
}
}
if (flag==1) printf("data yang anda cari ditemukan pada index ke-%i",i);
else printf("data yang anda cari tidak ditemukan");
}
