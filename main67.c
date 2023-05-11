                   //KUYRUKLARIN BA�LANTILI L�STE UYGULAMASINI G�STEREN PROGRAM//

#include <stdio.h>
#include <stdlib.h>

// D���m yap�s� tan�mlanm��t�r.
struct Dugum {
    int veri;
    struct Dugum* sonraki;
};

// Ba� ve son d���m pointerlar� tan�mlanm�� ve NULL'a e�itlenmi�tir.
struct Dugum* bas = NULL;
struct Dugum* son = NULL;

// Kuyru�a veri ekleyen fonksiyon tan�mlanm��t�r.
void ekle(int veri) {
    // Yeni bir d���m olu�turulur ve malloc fonksiyonu ile haf�zada alan ayr�l�r.
    struct Dugum* dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    // Yeni d���m�n veri alan�na parametre olarak gelen veri atan�r.
    dugum->veri = veri;
    // Yeni d���m�n sonraki pointer� NULL'a e�itlenir.
    dugum->sonraki = NULL;

    // Kuyruk bo� ise, ba� ve son pointerlar� yeni d���me e�itlenir.
    if (bas == NULL) {
        bas = dugum;
        son = dugum;
    } else {
        // Kuyruk dolu ise, son d���m�n sonraki pointer� yeni d���me e�itlenir.
        son->sonraki = dugum;
        // Son pointer� yeni d���me e�itlenir.
        son = son->sonraki;
    }
    // Eklendi mesaj� yazd�r�l�r.
    printf("%d Eklendi.\n", veri);
}

// Kuyruktan veri ��karan fonksiyon tan�mlanm��t�r.
void sil() {
    // Kuyruk bo� ise, hata mesaj� yazd�r�l�r.
    if (bas == NULL) {
        printf("Kuyruk Bos!\n");
    } else {
        // Kuyruk dolu ise, ilk d���m ge�ici bir pointer ile tutulur.
        struct Dugum* gecici = bas;
        // Ba� pointer� ikinci d���me e�itlenir.
        bas = bas->sonraki;
        // �lk d���m�n bellek alan� serbest b�rak�l�r.
        free(gecici);
        // Silindi mesaj� yazd�r�l�r
        printf("Silme Islemi Basarili!\n");
    }
}

// Kuyruktaki verileri g�steren fonksiyon tan�mlanm��t�r.
void goruntule() {
    // Kuyruk bo� ise, hata mesaj� yazd�r�l�r.
    if (bas == NULL) {
        printf("Kuyruk bo�!\n");
    } else {
        // Kuyruk dolu ise, ilk d���m ge�ici bir pointer ile tutulur.
        struct Dugum* gecici = bas;
        // Kuyruk yazd�r�l�yor
        printf("Kuyruk: ");
        while (gecici != NULL) {
            printf("%d ", gecici->veri);
            gecici = gecici->sonraki;
        }
        printf("\n");
    }
}


int main() {
    int secim, veri;  //De�i�kenlerin tan�mland��� sat�r.
/* Kullan�c�n�n ��k�� yapana kadar kuyruk i�lemlerini yapabilece�i bir d�ng� olu�turulur */
    do { //Do-while d�ng�s� ba�lang�c�, d�ng�deki i�lemler en az bir kez �al��t�r�l�r.
        printf("1 - Ekle\n");
        printf("2 - Sil\n");
        printf("3 - Goruntule\n");
        printf("4 - Cikis\n");
        printf("Secim: ");
        scanf("%d", &secim);

        switch (secim) { //Switch-case yap�s� ba�lang�c�, kullan�c�n�n se�imine g�re i�lem yapmak i�in kullan�l�r.
            case 1:  // E�er kullan�c� 1'i se�erse bu blok �al���r.
                printf("Eklenecek veri: "); //Kullan�c�dan kuyru�a eklemek istedi�i verinin istendi�i sat�r.
                scanf("%d", &veri);  // Kullan�c�n�n eklemek istedi�i veriyi okuyan sat�r.
                ekle(veri); //Kuyru�a veri eklemek i�in ekle fonksiyonunu �a��r�r.
                break;  //case 1 blo�undan ��karak switch-case yap�s�n� terk eder.
            case 2://E�er kullan�c� 2'yi se�erse bu blok �al���r
                sil();  //Kuyruktan eleman silmek i�in sil fonksiyonunu �a��r�r.
                break;//case 2 blo�undan ��karak switch-case yap�s�n� terk eder.
            case 3: // E�er kullan�c� 3'� se�erse bu blok �al���r.
                goruntule(); // Kuyru�u g�r�nt�lemek i�in goruntule fonksiyonunu �a��r�r.
                break; //case 3 blo�undan ��karak switch-case yap�s�n� terk eder.
            case 4: //E�er kullan�c� 4'� se�erse bu blok �al���r.
                printf("Program Sonlandirildi.\n");
                break; //case 4 blo�undan ��karak switch-case yap�s�n� terk eder.
            default:
                printf("Gecersiz Secim!\n"); // Kullan�c�n�n se�imi ge�ersiz ise, bir hata mesaj� ekrana yazd�r�l�r.
        }
    } while (secim != 4);

    return 0; //Program� normal bir �ekilde sonland�r�r.
}
