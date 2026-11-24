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
    printf("4. Cikis\n");
    printf("Seciminiz (1-4): ");
}

int main() {
    int secim;
    
    while(1) {
        ana_menu();
        scanf("%d", &secim);
        
        switch(secim) {
            case 1:
                printf("\n--- Depodaki Uygulamalar ---\n");
                system("cat gmstore_depo.txt");
                break;
            case 2:
                printf("\nYuklenecek paket adini girin: \n");
                // Burada system() ile gmstore motorunu cagiracagiz
                printf("[BILGI] Bu ozellik GMstore Motoru ile baglanacak.\n");
                break;
            case 3:
                printf("\n[INFO] Sistem guncel. GM OS v0.5.0\n");
                break;
            case 4:
                printf("\nGM OS kapatiliyor...\n");
                return 0;
            default:
                printf("\nGecersiz secim. Tekrar deneyin.\n");
        }
    }
    return 0;
}