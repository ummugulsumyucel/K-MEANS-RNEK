// K-MEANS  KÜMELEME ALGORÝTMASI //
   // K-means algoritmasýný kullanarak müþterileri belirli özelliklere dayalý olarak kümelere ayýrmak için tasarlanmýþtýr
//Amacý: Kodun amacý, müþteri verilerini analiz etmek ve benzer özelliklere sahip müþterileri gruplara ayýrmaktýr.
 //K-means algoritmasý kullanýlarak, müþterilerin belirli özelliklere göre gruplandýrýlmasý
  //ve her bir müþterinin hangi kümede olduðunu belirlemek amaçlanmaktadýr.                     

#include <stdio.h>
#include <stdlib.h>

// Müþteri sayýsý ve özellik sayýsý
#define NUM_MUSTERILER 10
#define NUM_OZELLIKLER 2

// Müþteri özellik verileri
float musteri_verileri[NUM_MUSTERILER][NUM_OZELLIKLER] = {
    {1.2, 3.5},   // Müþteri 1'in özellikleri
    {2.0, 4.1},   // Müþteri 2'nin özellikleri
    {1.5, 3.9},   // Müþteri 3'ün özellikleri
    {5.0, 6.2},   // Müþteri 4'ün özellikleri
    {4.5, 5.8},   // Müþteri 5'in özellikleri
    {4.0, 6.5},   // Müþteri 6'nýn özellikleri
    {8.2, 9.1},   // Müþteri 7'nin özellikleri
    {7.5, 8.7},   // Müþteri 8'in özellikleri
    {8.0, 9.3},   // Müþteri 9'un özellikleri
    {7.2, 8.9}    // Müþteri 10'un özellikleri
};

// Küme sayýsý ve merkezleri
#define NUM_KUMELER 2
float kume_merkezleri[NUM_KUMELER][NUM_OZELLIKLER] = {
    {1.0, 3.0},   // Küme 1'in merkezi
    {8.0, 9.0}    // Küme 2'nin merkezi
};

// Müþterilerin kümelerine atanmasý
int musteri_kumeleri[NUM_MUSTERILER];

void musteri_kumelerine_atama() {
    int i = 0;
    while (i < NUM_MUSTERILER) {
        float min_mesafe = 9999999;    // En küçük mesafe deðeri
        int en_yakin_kume = 0;         // En yakýn kümenin indeksi
        
        int j = 0;
        while (j < NUM_KUMELER) {
            float mesafe = 0;          // Müþteri ile küme merkezi arasýndaki mesafe
            
            int k = 0;
            while (k < NUM_OZELLIKLER) {
                float fark = musteri_verileri[i][k] - kume_merkezleri[j][k];   // Özellik deðerlerinin farký
                mesafe += fark * fark;   // Öklidyen mesafe hesaplama formülü
                k++;
            }
            
            if (mesafe < min_mesafe) {
                min_mesafe = mesafe;     // En küçük mesafeyi güncelle
                en_yakin_kume = j;       // En yakýn kümenin indeksini güncelle
            }
            
            j++;
        }
         musteri_kumeleri[i] = en_yakin_kume;   // Müþteriyi en yakýn kümeye ata
        i++;
    }
}

int main() {
    // Müþterileri kümelerine ata
    musteri_kumelerine_atama();
    
    // Müþteri küme bilgilerini ekrana yazdýr
    printf("Musteri Kume Bilgileri:\n");
    int i = 0;
    while (i < NUM_MUSTERILER) {
        printf("Musteri %d: Kume %d\n", i+1, musteri_kumeleri[i]+1);
        i++;
    }
    
    return 0;
} 
