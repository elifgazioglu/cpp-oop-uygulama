//Bolum: Bilgisayar Muhendisligi
//Dersin Adi: Nesneye Yonelik Programlama 
//Dersin Kodu: BM-104 
//Akademik Donem: 2021-2022 Bahar Donemi

#include<iostream>
#include "BM104_210707014_Proje1.h"
#include <cstdlib>
#include <ctime>

bool DizideMevcutMu(int tahmin, int* arr, int n) {//tahmin edilen sayinin dizide olup olmadigini kontrol eden fonksiyon.
    for (int i=0; i<n; i++) {
        if (arr[i] == tahmin) {
            return true;
        }
    }

    return false;
}

void Oyun::guess(){
	int tahminSayisi;

           this->mevcutTahminSayisi += 1;

           cout << "Bir rakam tahmin et: ";
           cin >> tahminSayisi;

           if (DizideMevcutMu(tahminSayisi, tahminArr, mevcutTahminSayisi - 1)) {//kullanıcının aynı sayıyı tahmin edip etmedigini kontrol eden if burada
               cout << "Ayni rakami tahmin edemezsin." << endl <<endl;
               this->mevcutTahminSayisi -= 1;
               maxTahmin -= 1;
               return;
           }

           this->pushGuessArr(tahminSayisi);

           if (DizideMevcutMu(tahminSayisi, this->arr, this->n)) {//Sayilarin rastgele uretildigi dizide, girdigimiz tahminin olup olmadigini if ile kontrol ediyor
               this->bulunanTahminler += 1;
               this->pushGuessArrFlag(1);
           } else {
               this->pushGuessArrFlag(0);
               cout << tahminSayisi << " bulunamadi" << endl <<endl;
           }
}

void Oyun::ArrYaz(){//kullanici her tahminde bulundugunda x'leri ve dogru tahmin ettigi sayilari sonuna denk gelecek sekilde(kaydirma) yazdiran fonksiyon.
            for (int i=0; i < n - bulunanTahminler; i++) {
                cout << "x" << " ";
            }

            for (int i=0; i < mevcutTahminSayisi; i++) {
                if (guessArrFlag[i]) {
                    cout << tahminArr[i] << " ";
                }
            }

            cout << endl;
       
}

void Oyun::pushGuessArr(int tahminSayisi){//tahminlerin oldugu array'de sona dogru iten(kaydiran) foksiyon.
	this->tahminArr[this->mevcutTahminSayisi - 1] = tahminSayisi;
}

void Oyun::pushGuessArrFlag(int flag){//tahminlerin dogruluk degerlerini tutan array'de sona dogru iten(kaydiran) fonksiyon
	this->guessArrFlag[this->mevcutTahminSayisi - 1] = flag;
}

void Oyun::DiziyiRandomDegerlerleDoldur(int n) { //random degerlerin benzersiz olup olmadigini kontrol ederek diziye aktardigim fonksiyon.
          for (int i=0; i<n; i++) {
              int isUnique = 1;
              do {
                  int randomSayi = ArasindaRandomSayiOlustur(this->minSayi, this->maxSayi);
                  if (!DizideMevcutMu(randomSayi, arr, i)) {
                     isUnique = 1;
                     arr[i] = randomSayi;
                  } else {
                      isUnique = 0;
                  }
              } while(!isUnique);
          }
      }
      
int Oyun::ArasindaRandomSayiOlustur(int minSayi, int maxSayi) { //rand fonksiyonu ile random sayilar olusturan fonksiyon.
           return minSayi + rand() % (( maxSayi + 1 ) - minSayi);
      }
      
Oyun::Oyun(int n, int minSayi, int maxSayi) {//Bu bizim constructer'imiz
         this->n = n;
         this->minSayi = minSayi;
         this->maxSayi = maxSayi;
         mevcutTahminSayisi = 0;
         bulunanTahminler = 0;
     }
      
void Oyun::oyunOyna() {//public'te tanimlanmasi gereken, private'taki fonksiyonlara �a��rdigimiz fonksiyon.
        DiziyiRandomDegerlerleDoldur(n);
        maxTahmin = n*2;

        while(mevcutTahminSayisi < maxTahmin && n != bulunanTahminler) {
            this->guess();
            this->ArrYaz();
        }

        if (n == bulunanTahminler) {
            cout << "Tebrikler. Kazandin!" << endl;
        } else {
           cout << "Uzgunum. Kaybettin:(" << endl;
        }
     }
