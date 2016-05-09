#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int rMtrx[50][50];
int gMtrx[50][50];
int bMtrx[50][50];
int lineNum=2500;

void t2(){
    int rUser=0;
    int gUser=0;
    int bUser=0;

    cout<<"Adjon meg egy R szinkodot: ";
    cin>>rUser;
    cout<<"Adjon meg egy G szinkodot: ";
    cin>>gUser;
    cout<<"Adjon meg egy B szinkodot: ";
    cin>>bUser;

    bool found=false;
    for(int i=0;i<50;i++){ // y
        for(int c=0;c<50;c++){ // x
            if(rMtrx[i][c]==rUser && gMtrx[i][c]==gUser && bMtrx[i][c]==bUser){
                found=true;
            }
        }
    }

    if(found){
        cout<<"Megtalalhato benne."<<endl;
    }else{
        cout<<"Nem talalhato meg benne."<<endl;
    }
}
void t3(){
    int rSeek=rMtrx[35][8];
    int gSeek=gMtrx[35][8];
    int bSeek=bMtrx[35][8];

    int rowSum=0;
    int colSum=0;
    for(int i=0;i<50;i++){
        if(rMtrx[35][i]==rSeek && gMtrx[35][i]==gSeek && bMtrx[35][i]==bSeek){
            rowSum++;
        }
        if(rMtrx[i][8]==rSeek && gMtrx[i][8]==gSeek && bMtrx[i][8]==bSeek){
            colSum++;
        }
    }
    cout<<"Sorban: "<<rowSum<<" Oszlopban: "<<colSum<<endl;
}
void t4(){
    int maxR=0;
    int maxG=0;
    int maxB=0;

    for(int i=0;i<50;i++){ // y
        for(int c=0;c<50;c++){ // x
            if(rMtrx[i][c]==255 && gMtrx[i][c]==0 && bMtrx[i][c]==0){ // R
                maxR++;
            }else if(rMtrx[i][c]==0 && gMtrx[i][c]==255 && bMtrx[i][c]==0){ // G
                maxG++;
            }else if(rMtrx[i][c]==0 && gMtrx[i][c]==0 && bMtrx[i][c]==255){ // B
                maxB++;
            }
        }
    }

    cout<<"Legtobbszor a ";
    if(maxR>maxG && maxR>maxB){
        cout<<"piros";
    }else if(maxG>maxR && maxG>maxB){
        cout<<"zold";
    }else{
        cout<<"kek";
    }
    cout<<" fordul elo."<<endl;
}
void t56(){
    for(int i=0;i<50;i++){
        for(int c=0;c<3;c++){
            rMtrx[c][i]=0;
            gMtrx[c][i]=0;
            bMtrx[c][i]=0;

            rMtrx[i][c]=0;
            gMtrx[i][c]=0;
            bMtrx[i][c]=0;
        }

        for(int c=49;c>46;c--){
            rMtrx[c][i]=0;
            gMtrx[c][i]=0;
            bMtrx[c][i]=0;

            rMtrx[i][c]=0;
            gMtrx[i][c]=0;
            bMtrx[i][c]=0;
        }
    }

    ofstream fileOutput("keretes.txt");
    for(int i=0;i<50;i++){
        for(int c=0;c<50;c++){
            fileOutput<<rMtrx[i][c]<<" ";
            fileOutput<<gMtrx[i][c]<<" ";
            fileOutput<<bMtrx[i][c]<<" ";
            fileOutput<<"\n";
        }
        //fileOutput<<"\n";
    }
    fileOutput.close();
}

void t7(){

}

int main(){
    ifstream fileInput("kep.txt");

    if(fileInput.is_open()){
        for(int i=0;i<50;i++){ // y
            for(int c=0;c<50;c++){ // x
                fileInput>>rMtrx[i][c];
                fileInput>>gMtrx[i][c];
                fileInput>>bMtrx[i][c];
            }
        }
    }
    fileInput.close();

    cout<<"1. Feladat"<<endl;
    cout<<"Fajl beolvasva."<<endl;
    cout<<endl;
    cout<<"2. Feladat"<<endl;
    //t2();
    cout<<endl;
    cout<<"3. Feladat"<<endl;
    t3();
    cout<<endl;
    cout<<"4. Feladat"<<endl;
    t4();
    cout<<endl;
    cout<<"5. Feladat"<<endl;
    t5();
    cout<<endl;
    cout<<"6. Feladat"<<endl;
    cout<<"Fajl elmentve."<<endl;
    cout<<endl;
    cout<<"7. Feladat"<<endl;
    t7();
    cout<<endl;

    return 0;
}
