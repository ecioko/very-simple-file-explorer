#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <filesystem>

using namespace std;

string dosyaIsmi; /*createFile Fonksiyonunun ulaşabilmesi için global değişkenler*/
string dosyaIcerigi;

void createFile(){ /*Dosyanın oluşturulacağı fonksiyon*/

	/*Dosyalar, .exe dosyasının olduğu konuma oluşturulur.*/
	
	ofstream userFile(dosyaIsmi);
	userFile << dosyaIcerigi;
	cout<<"Dosya basarili bir sekilde olusturuldu!";
	userFile.close();
}

int main(){ /*İşlemlerin olacağı ana fonksiyon*/
	
	int islem;
	
	cout<<"Dosya ismi girin: (!! UZANTI ILE BIRLIKTE !!)"<<endl;
	cin>>dosyaIsmi;
	cout<<"Dosya ismi basarili!"<<endl<<"Dosyanin icerisindesiniz"<<endl<<endl;
	cout<<"Dosya icerigini giriniz:"<<endl;
	cin>>dosyaIcerigi;
	
	createFile();
	
	cout<<endl<<"Islem secin. (1-Dosya sil || 2-Dosyayi Ac)"<<endl<<"   :";
	cin>>islem;
	if(islem == 1){
		if(remove(dosyaIsmi.c_str()) != 0){
			perror("Dosya Silinemedi");
		}
		else{
			clog<<"Dosya silme islemi basarili!";
		}
	}
	else if(islem == 2){
		
		char buffer[MAX_PATH];
    	GetCurrentDirectory(MAX_PATH, buffer);  /* Dosya yolunu alır*/
    	string tamYol = string(buffer) + "\\" + dosyaIsmi;
    	
		string komut = "notepad " + tamYol;  /*Komut istemine girmesi için komut değeri*/
		int sonuc = system(komut.c_str());
		
		if(sonuc == 0){
			cout<<"Dosya Acildi.";
		}
		else{
			cout<<"Dosya Acilamadi.";
		}
	}

	return 0;
	
}
