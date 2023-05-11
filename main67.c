                   //KUYRUKLARIN BAÐLANTILI LÝSTE UYGULAMASINI GÖSTEREN PROGRAM//

#include <stdio.h>
#include <stdlib.h>

// Düðüm yapýsý tanýmlanmýþtýr.
struct Dugum {
    int veri;
    struct Dugum* sonraki;
};

// Baþ ve son düðüm pointerlarý tanýmlanmýþ ve NULL'a eþitlenmiþtir.
struct Dugum* bas = NULL;
struct Dugum* son = NULL;

// Kuyruða veri ekleyen fonksiyon tanýmlanmýþtýr.
void ekle(int veri) {
    // Yeni bir düðüm oluþturulur ve malloc fonksiyonu ile hafýzada alan ayrýlýr.
    struct Dugum* dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    // Yeni düðümün veri alanýna parametre olarak gelen veri atanýr.
    dugum->veri = veri;
    // Yeni düðümün sonraki pointerý NULL'a eþitlenir.
    dugum->sonraki = NULL;

    // Kuyruk boþ ise, baþ ve son pointerlarý yeni düðüme eþitlenir.
    if (bas == NULL) {
        bas = dugum;
        son = dugum;
    } else {
        // Kuyruk dolu ise, son düðümün sonraki pointerý yeni düðüme eþitlenir.
        son->sonraki = dugum;
        // Son pointerý yeni düðüme eþitlenir.
        son = son->sonraki;
    }
    // Eklendi mesajý yazdýrýlýr.
    printf("%d Eklendi.\n", veri);
}

// Kuyruktan veri çýkaran fonksiyon tanýmlanmýþtýr.
void sil() {
    // Kuyruk boþ ise, hata mesajý yazdýrýlýr.
    if (bas == NULL) {
        printf("Kuyruk Bos!\n");
    } else {
        // Kuyruk dolu ise, ilk düðüm geçici bir pointer ile tutulur.
        struct Dugum* gecici = bas;
        // Baþ pointerý ikinci düðüme eþitlenir.
        bas = bas->sonraki;
        // Ýlk düðümün bellek alaný serbest býrakýlýr.
        free(gecici);
        // Silindi mesajý yazdýrýlýr
        printf("Silme Islemi Basarili!\n");
    }
}

// Kuyruktaki verileri gösteren fonksiyon tanýmlanmýþtýr.
void goruntule() {
    // Kuyruk boþ ise, hata mesajý yazdýrýlýr.
    if (bas == NULL) {
        printf("Kuyruk boþ!\n");
    } else {
        // Kuyruk dolu ise, ilk düðüm geçici bir pointer ile tutulur.
        struct Dugum* gecici = bas;
        // Kuyruk yazdýrýlýyor
        printf("Kuyruk: ");
        while (gecici != NULL) {
            printf("%d ", gecici->veri);
            gecici = gecici->sonraki;
        }
        printf("\n");
    }
}


int main() {
    int secim, veri;  //Deðiþkenlerin tanýmlandýðý satýr.
/* Kullanýcýnýn çýkýþ yapana kadar kuyruk iþlemlerini yapabileceði bir döngü oluþturulur */
    do { //Do-while döngüsü baþlangýcý, döngüdeki iþlemler en az bir kez çalýþtýrýlýr.
        printf("1 - Ekle\n");
        printf("2 - Sil\n");
        printf("3 - Goruntule\n");
        printf("4 - Cikis\n");
        printf("Secim: ");
        scanf("%d", &secim);

        switch (secim) { //Switch-case yapýsý baþlangýcý, kullanýcýnýn seçimine göre iþlem yapmak için kullanýlýr.
            case 1:  // Eðer kullanýcý 1'i seçerse bu blok çalýþýr.
                printf("Eklenecek veri: "); //Kullanýcýdan kuyruða eklemek istediði verinin istendiði satýr.
                scanf("%d", &veri);  // Kullanýcýnýn eklemek istediði veriyi okuyan satýr.
                ekle(veri); //Kuyruða veri eklemek için ekle fonksiyonunu çaðýrýr.
                break;  //case 1 bloðundan çýkarak switch-case yapýsýný terk eder.
            case 2://Eðer kullanýcý 2'yi seçerse bu blok çalýþýr
                sil();  //Kuyruktan eleman silmek için sil fonksiyonunu çaðýrýr.
                break;//case 2 bloðundan çýkarak switch-case yapýsýný terk eder.
            case 3: // Eðer kullanýcý 3'ü seçerse bu blok çalýþýr.
                goruntule(); // Kuyruðu görüntülemek için goruntule fonksiyonunu çaðýrýr.
                break; //case 3 bloðundan çýkarak switch-case yapýsýný terk eder.
            case 4: //Eðer kullanýcý 4'ü seçerse bu blok çalýþýr.
                printf("Program Sonlandirildi.\n");
                break; //case 4 bloðundan çýkarak switch-case yapýsýný terk eder.
            default:
                printf("Gecersiz Secim!\n"); // Kullanýcýnýn seçimi geçersiz ise, bir hata mesajý ekrana yazdýrýlýr.
        }
    } while (secim != 4);

    return 0; //Programý normal bir þekilde sonlandýrýr.
}
