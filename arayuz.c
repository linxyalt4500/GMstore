#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ana_menu() {
    printf("\n====================================\n");
    printf("         GM OS - GMstore            \n");
    printf("====================================\n");
    printf("1. Uygulamalari Goruntule (Depo)\n");
    printf("2. Uygulama Yukle\n");
    printf("3. Sistem Guncellemelerini Kontrol Et\n");
    printf("4. GM Browser (Tarayici)\n");
    printf("5. Cikis\n");
    printf("Seciminiz (1-5): ");
}

int main() {
    int secim;
    
    while(1) {
        ana_menu();
        // Kullanıcının girdiği sayıyı oku
        if (scanf("%d", &secim) != 1) {
            while(getchar() != '\n'); // Hatalı girişte buffer temizle
            continue;
        }
        
        switch(secim) {
            case 1:
                printf("\n--- Depodaki Uygulamalar ---\n");
                system("cat gmstore_depo.txt");
                break;
            case 2:
                printf("\nYuklenecek paket adini girin: \n");
                printf("[BILGI] Bu ozellik GMstore Motoru ile baglanacak.\n");
                break;
            case 3:
                printf("\n[INFO] Sistem guncel. GM OS v0.5.0\n");
                break;
            case 4:
                printf("\n--- GM Browser Baslatiliyor ---\n");
                printf("General Mobile web sitesine baglaniliyor...\n");
                // Arka planda sistemin tarayıcısını veya bir metin tarayıcısını çağırıyoruz
                system("wget -qO- https://www.generalmobile.com | head -n 20");
                printf("\n[INFO] Sayfa yuklendi (Önizleme).\n");
                break;
            case 5:
                printf("\nGM OS kapatiliyor...\n");
                return 0;
            default:
                printf("\nGecersiz secim. Tekrar deneyin.\n");
        }
    }
    return 0;
}