//Bolum: Bilgisayar Muhendisligi
//Dersin Adi: Nesneye Yonelik Programlama 
//Dersin Kodu: BM-104 
//Akademik Donem: 2021-2022 Bahar Donemi


#ifndef BM104_210707014_PROJE1_H
#define BM104_210707014_PROJE1_H
#include<iostream>
using namespace std;
class Oyun {
   private:
   	   int arr[20];//1.uye degisken
       int n;//2.uye degisken
	   int maxTahmin;//3.uye degisken
	   int minSayi;//4.uye degisken
	   int maxSayi;//5.uye degisken
	   int mevcutTahminSayisi, bulunanTahminler, tahminArr[20] /*butun tahminlerin yazildigi array*/, guessArrFlag[20] /*tahminlerin do�ru olup olmad���n� 1 0 �eklinde tutan array*/;
		

       void guess();

       void ArrYaz();

       void pushGuessArr(int tahminSayisi);

       void pushGuessArrFlag(int flag);

       void DiziyiRandomDegerlerleDoldur(int n);

       int ArasindaRandomSayiOlustur(int minSayi, int maxSayi);

   public:
     Oyun(int n, int minSayi, int maxSayi);
     void oyunOyna();
};


#endif
