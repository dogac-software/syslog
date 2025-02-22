#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Syslog mekanizmasýný nedir? Ne için kullanýlýr?
//Baðlý liste veri yapýsýný kullanarak bu günlükler nasýl tutulabilir?
// Hangi baðlý liste ile tutulabilir?
//Seçtiðiniz baðlý liste türünü tercih etme sebebinizin, Syslog kayýtlarýyla ilgisi nedir?

typedef struct SyslogKaydi {
    char zamanDamgasi[30];
    char mesaj[256];
    struct SyslogKaydi* sonraki;
} SyslogKaydi;

// Burasý baðlý listenin baþladýðý kýsým
SyslogKaydi* baslangic = NULL;

// Yeni syslog kaydýnýn eklendiði fonksiyon
void syslogKaydiEkle(char* zamanDamgasi, char* mesaj) {
    SyslogKaydi* yeniKayit = (SyslogKaydi*)malloc(sizeof(SyslogKaydi));
    strcpy(yeniKayit->zamanDamgasi, zamanDamgasi);
    strcpy(yeniKayit->mesaj, mesaj);
    yeniKayit->sonraki = baslangic;
    baslangic = yeniKayit;
}

// Syslog kayýtlarýný listeleme fonksiyonu
void syslogKayitlariniListele() {
    SyslogKaydi* suanki = baslangic;
    while (suanki != NULL) {
        printf("Zaman Damgasi: %s, Mesaj: %s\n", suanki->zamanDamgasi, suanki->mesaj);
        suanki = suanki->sonraki;
    }
}

int main() {
    // Ornek 
    syslogKaydiEkle("2023-10-27 10:00:00", "Sistem baslatildi.");
    syslogKaydiEkle("2023-10-27 10:05:00", "Kullanici girisi basarili.");
    syslogKaydiEkle("2023-10-27 10:10:00", "Hata: Dosya bulunamadi.");

    
    syslogKayitlariniListele();

    return 0;
}


