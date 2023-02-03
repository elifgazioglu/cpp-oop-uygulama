#include "BM104_210707014_Proje1.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
    int n, minSayi, maxSayi;

    srand (time(NULL));

    cout << "Dizideki rakam sayisini girin: ";
    cin >> n;

    cout << "Alt siniri girin: ";
    cin >> minSayi;

    cout << "Ust siniri girin: ";
    cin >> maxSayi;

    Oyun oyun(n, minSayi, maxSayi);

    oyun.oyunOyna();

    return 0;
}
