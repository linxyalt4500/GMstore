#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("GMstore Core v0.5.0 (Otomatik Guncelleme Motoru)\n");
        printf("Kullanim: gmstore install <paket_adi>\n");
        return 1;
    }

    if (strcmp(argv[1], "install") == 0) {
        FILE *dosya = fopen("gmstore_depo.txt", "r");
        if (dosya == NULL) {
            printf("[HATA] Depo dosyasi bulunamadi!\n");
            return 1;
        }

        char paket_adi[50];
        char versiyon[20];
        int bulundu = 0;
        char indirme_komutu[300];
        char acma_komutu[300];

        while (fscanf(dosya, "%s %s", paket_adi, versiyon) == 2) {
            if (strcmp(argv[2], paket_adi) == 0) {
                bulundu = 1;
                printf("[INFO] '%s' (Surum: %s) depoda bulundu.\n", paket_adi, versiyon);
                
                sprintf(indirme_komutu, "wget -q -O %s.gmpak https://raw.githubusercontent.com/git/git/master/README.md", paket_adi);
                if (system(indirme_komutu) != 0) {
                    printf("[HATA] Indirme basarisiz oldu.\n");
                    break;
                }

                char klasor_adi[100];
                sprintf(klasor_adi, "%s_pkg", paket_adi);
                mkdir(klasor_adi, 0777);

                sprintf(acma_komutu, "cp %s.gmpak %s_pkg/ && echo 'PKG_OK' > %s_pkg/durum.log", paket_adi, paket_adi, paket_adi);
                if (system(acma_komutu) == 0) {
                    printf("[BASARILI] '%s' sisteme entegre edildi.\n", paket_adi);
                    printf("[INFO] Kurulum yolu: %s_pkg/\n", paket_adi);
                }
                break;
            }
        }

        fclose(dosya);

        if (bulundu == 0) {
            printf("[HATA] '%s' paketi depoda bulunamadi!\n", argv[2]);
        }
    } else {
        printf("[HATA] Bilinmeyen komut: %s\n", argv[1]);
    }
    return 0;
}