// K-MEANS  K�MELEME ALGOR�TMASI //
   // K-means algoritmas�n� kullanarak m��terileri belirli �zelliklere dayal� olarak k�melere ay�rmak i�in tasarlanm��t�r
//Amac�: Kodun amac�, m��teri verilerini analiz etmek ve benzer �zelliklere sahip m��terileri gruplara ay�rmakt�r.
 //K-means algoritmas� kullan�larak, m��terilerin belirli �zelliklere g�re grupland�r�lmas�
  //ve her bir m��terinin hangi k�mede oldu�unu belirlemek ama�lanmaktad�r.                     

#include <stdio.h>
#include <stdlib.h>

// M��teri say�s� ve �zellik say�s�
#define NUM_MUSTERILER 10
#define NUM_OZELLIKLER 2

// M��teri �zellik verileri
float musteri_verileri[NUM_MUSTERILER][NUM_OZELLIKLER] = {
    {1.2, 3.5},   // M��teri 1'in �zellikleri
    {2.0, 4.1},   // M��teri 2'nin �zellikleri
    {1.5, 3.9},   // M��teri 3'�n �zellikleri
    {5.0, 6.2},   // M��teri 4'�n �zellikleri
    {4.5, 5.8},   // M��teri 5'in �zellikleri
    {4.0, 6.5},   // M��teri 6'n�n �zellikleri
    {8.2, 9.1},   // M��teri 7'nin �zellikleri
    {7.5, 8.7},   // M��teri 8'in �zellikleri
    {8.0, 9.3},   // M��teri 9'un �zellikleri
    {7.2, 8.9}    // M��teri 10'un �zellikleri
};

// K�me say�s� ve merkezleri
#define NUM_KUMELER 2
float kume_merkezleri[NUM_KUMELER][NUM_OZELLIKLER] = {
    {1.0, 3.0},   // K�me 1'in merkezi
    {8.0, 9.0}    // K�me 2'nin merkezi
};

// M��terilerin k�melerine atanmas�
int musteri_kumeleri[NUM_MUSTERILER];

void musteri_kumelerine_atama() {
    int i = 0;
    while (i < NUM_MUSTERILER) {
        float min_mesafe = 9999999;    // En k���k mesafe de�eri
        int en_yakin_kume = 0;         // En yak�n k�menin indeksi
        
        int j = 0;
        while (j < NUM_KUMELER) {
            float mesafe = 0;          // M��teri ile k�me merkezi aras�ndaki mesafe
            
            int k = 0;
            while (k < NUM_OZELLIKLER) {
                float fark = musteri_verileri[i][k] - kume_merkezleri[j][k];   // �zellik de�erlerinin fark�
                mesafe += fark * fark;   // �klidyen mesafe hesaplama form�l�
                k++;
            }
            
            if (mesafe < min_mesafe) {
                min_mesafe = mesafe;     // En k���k mesafeyi g�ncelle
                en_yakin_kume = j;       // En yak�n k�menin indeksini g�ncelle
            }
            
            j++;
        }
         musteri_kumeleri[i] = en_yakin_kume;   // M��teriyi en yak�n k�meye ata
        i++;
    }
}

int main() {
    // M��terileri k�melerine ata
    musteri_kumelerine_atama();
    
    // M��teri k�me bilgilerini ekrana yazd�r
    printf("Musteri Kume Bilgileri:\n");
    int i = 0;
    while (i < NUM_MUSTERILER) {
        printf("Musteri %d: Kume %d\n", i+1, musteri_kumeleri[i]+1);
        i++;
    }
    
    return 0;
} 
