/*EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
*Modul            : 2
*Percobaan        : -
*Hari dan Tanggal : -
*Nama (NIM)       : -
*Asisten (NIM)    : Nur Sekti Waskitha Jati (18318023)
*Nama File        : M02_18318023.c
*Deskripsi        : Mencari tahu kode string
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main(){
    FILE* myfile;
    char filename[N], s1[N], s2[N], s3[N], s4[N], temp[N], temp2;
    int ec, i, j, ns1, ns2, ns3, iter, ntemp;

    //pembacaan input file
    printf("Masukkan nama file : ");
    scanf("%s", &filename);
    myfile = fopen(filename, "r");
    fgets(s1, sizeof(s1), myfile);
    fgets(s2, sizeof(s2), myfile);
    fgets(s3, sizeof(s3), myfile);
    fgets(s4, sizeof(s4), myfile);

    strtok(s1, "\r");
    strtok(s2, "\r");
    strtok(s3, "\r");
    ec = atoi(s4);

    //penghapusan junk code dan ppenyisipan missing code
    ns1 = strlen(s1);
    ns2 = strlen(s2);
    ns3 = strlen(s3);

    i = 0; j = 0;
    while(i<ns2){
        if(s1[j]==s2[i]){
            if(i==0){
                iter = j;
            }
            i++; j++;
        } else{
            j++;
        }
    }

    i = 0;
    while(j<ns1){
        temp[i] = s1[j];
        i++; j++;
    }
    temp[i] = '\n';
    strtok(temp, "\n");

    i = 0;
    while(i<ns3){
        s1[iter] = s3[i];
        iter++; i++;
    }

    ntemp = strlen(temp);
    i = 0;
    while(i<ntemp){
        s1[iter] = temp[i];
        iter++; i++;
    }

    //penggeseran karakter oleh encryption constant
    strtok(s1, "\n");
    ns1 = strlen(s1);
    i = 0;
    while(i<ns1){
        s1[i] = (s1[i]-96+ec)%26 + 96;
        if(s1[i]==96){
            s1[i] = 'z';
        }
        i++;
    }
    printf("Kode untuk membuka koper : %s", s1);
}
