#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Syslog mekanizmas�n� nedir? Ne i�in kullan�l�r?
//Ba�l� liste veri yap�s�n� kullanarak bu g�nl�kler nas�l tutulabilir?
// Hangi ba�l� liste ile tutulabilir?
//Se�ti�iniz ba�l� liste t�r�n� tercih etme sebebinizin, Syslog kay�tlar�yla ilgisi nedir?

typedef struct SyslogKaydi {
    char zamanDamgasi[30];
    char mesaj[256];
    struct SyslogKaydi* sonraki;
} SyslogKaydi;

// Buras� ba�l� listenin ba�lad��� k�s�m
SyslogKaydi* baslangic = NULL;

// Yeni syslog kayd�n�n eklendi�i fonksiyon
void syslogKaydiEkle(char* zamanDamgasi, char* mesaj) {
    SyslogKaydi* yeniKayit = (SyslogKaydi*)malloc(sizeof(SyslogKaydi));
    strcpy(yeniKayit->zamanDamgasi, zamanDamgasi);
    strcpy(yeniKayit->mesaj, mesaj);
    yeniKayit->sonraki = baslangic;
    baslangic = yeniKayit;
}

// Syslog kay�tlar�n� listeleme fonksiyonu
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


