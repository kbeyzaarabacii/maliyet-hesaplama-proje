#include <stdio.h>

struct person   //kiþinin bilgilerini alabilmek için kullanýldý.
{
    char ad[30];
    int yas;
    float butce;
};

struct araba    //arac bilgilerini almak için kullanýldý. 
{
    float litre;
    float km;
};

//fonksiyonlarýn prototipleri

void araba(struct person p1);      
void bisiklet(struct person p1);
void taksi(struct person p1);
void otobus(struct person p1);



int main()      //ana fonksiyonumuz
{
    struct person p1;
    int secim;

    printf("\t\t\t      ULASIM MALIYETI HESAPLAMA UYGULAMAMIZA HOS GELDINIZ");
  
    printf("\n\n\nLutfen bilgilerinizi giriniz:\n");
    printf("--------------------------------------------------\n");

    printf("Ad soyad: ");
    scanf(" %[^\n]s", p1.ad);  // "%[^\n]s" ifadesini scanfte ad soyadý boþlukla alabilmek için kullanýldý.

    printf("Yas: ");
    scanf("%d", &p1.yas);

    printf("Gunluk butceniz (TL): ");  
    scanf("%f", &p1.butce);

    printf("\n\nBilgileriniz basariyla kaydedildi!\n");
    
    //kullanýcý bilgileri ekrana yazdýrýldý.
    printf("\nAd Soyad\t: %s\n", p1.ad);    
    printf("Yas     \t: %d\n", p1.yas);
    printf("Gunluk butce\t: %.2f TL\n", p1.butce);
   

    do    // '0' girilene kadar seçim yapýlabilmesi için oluþturuldu.
     {
        printf("\n\nLutfen kullanmak istediginiz araci seciniz:\n");
        printf("--------------------------------------------------\n");
        printf("  1 - Araba\n");
        printf("  2 - Bisiklet\n");
        printf("  3 - Otobus\n");
        printf("  4 - Taksi\n");
        printf("  0 - Cikis\n");
        printf("\nSeciminiz: ");
        scanf("%d", &secim);

       
        
        switch (secim)   // fonksiyonlar case'ler içerisine çaðýrýldý.
	   {
        case 1:
            if (p1.yas >= 18)   //kullanýcý 18 yaþýndan küçükse araç kullanamaz.
		{
                araba(p1); //struct person p1'den dolayý (p1)
            } else
		{
                printf("\n\n UYARI: Araba kullanabilecek yas araliginda degilsiniz! \n");
            }
            break;

        case 2:
            bisiklet(p1);
            break;

        case 3:
            otobus(p1);  
            break;

        case 4:
            taksi(p1);
            break;

        case 0:
            printf("\n\nTesekkur ederiz, cikis yapiliyor...\n");
            break;

        default:
            printf("\n\n Gecersiz secim. Lutfen tekrar deneyiniz. \n");
            break;
      }
    } while (secim != 0);  // seçim '0' ise çýkýþ yapýlýr.

    return 0;
}

void araba(struct person p1) 
{
    struct araba arac;   //arac bilgileri alýndý.
    float parkUcret, ucretF, ucretE, toplam = 0;   
    float karbonSalinimi = 0;
    int aracSecim, parkSayisi, yakitFiyat = 30;

    printf("\n----------------------------------------------------");
    printf("\n\tARABA MALIYET VE KARBON SALINIMI HESAPLAMA");
    printf("\n----------------------------------------------------\n");

    printf("Araciniz elektrikliyse -> 1\n");
    printf("Araciniz fosil yakitliysa -> 2\n");
    printf("Seciminiz: ");
    scanf("%d", &aracSecim);

    switch (aracSecim) 
    {
    case 1:
    	  printf("\n1 kilometre yol icin elektrik ucreti: 2.5 TL\n");
        printf("\nToplam kac kilometre yol aldiniz? ");
        scanf("%f", &arac.km);                  
        ucretE = 0.15 * 2.5 * arac.km;       //Elektrikli aracýn kilometreye baðlý ulaþým maliyeti. 0.15 -> 1 kilometre kw degeri
        karbonSalinimi = arac.km * 0.05;     // Elektrikli aracýn kilometreye baðlý karbon salýnýmý. 0.05-> Elektrikli araç karbon salýnýmý
        printf("\nElektrikli arac ortalama yol maliyeti: %.2f TL", ucretE);
        
        printf("\nOtopark giris ucreti: 150.75 TL");
        printf("\nOtoparka kac kez girdiniz? ");
        scanf("%d", &parkSayisi);
        printf("\n----------------------------------------------------");
        printf("\nElektrikli arac ortalama karbon salinimi: %.2f kg CO2", karbonSalinimi);
        
        parkUcret = parkSayisi * 150.75;      //Park ücreti hesaplama.
        toplam = ucretE + parkUcret;          //Toplam maliyet hesaplama.
        break;

    case 2:
    	  printf("\n1 litre fosil yakit ucreti: 30 TL\n");
        printf("\nToplam kac kilometre yol aldiniz? ");
        scanf("%f", &arac.km);
        printf("Aracinizin 1 kilometrede tukettigi yakit miktarini (litre) giriniz: ");
        scanf("%f", &arac.litre);
        ucretF = yakitFiyat * arac.km * arac.litre;            //Fosil yakýtlý aracýn kilometreye baðlý ulaþým maliyeti.
        karbonSalinimi = arac.km * arac.litre * 2.31;          //Fosil yakýtlý aracýn kilometreye baðlý karbon salýnýmý. 2.31 kg-> Fosil yakýtlý araç karbon salýnýmý
        printf("\nFosil yakitli arac ortalama yol maliyeti: %.2f TL", ucretF);
        
        printf("\nGunluk otopark giris ucreti: 150.75 TL");
        printf("\nOtoparka kac kez girdiniz? ");
        scanf("%d", &parkSayisi);
        printf("\n----------------------------------------------------");
        printf("\nFosil yakitli arac ortalama karbon salinimi: %.2f kg CO2", karbonSalinimi);
        
        parkUcret = parkSayisi * 150.75;      //Park ücreti hesaplama.
        toplam = ucretF + parkUcret;          //Toplam ücreti hesaplama.
        break;

        default:
        printf("\n Gecersiz secim. Lutfen tekrar deneyiniz. ");
        return;
    }

    printf("\nToplam arac kullanim maliyeti: %.2f TL", toplam);
    
    if (toplam > p1.butce)   //bütçeyi aþýyorsa uyarý verir.
      {
        printf("\n UYARI: Toplam maliyet %.2f TL, butcenizi asiyor! ", toplam);
        printf("\n----------------------------------------------------");
      } 
    else 
      {
        printf("\nButceniz asilmadi. Iyi yolculuklar!");
        
        printf("\n----------------------------------------------------");
      }
}

void bisiklet(struct person p1)
 {
    float toplam = 30;  

    printf("\n----------------------------------------------------");
    printf("\n\tBISIKLET MALIYET VE KARBON SALINIMI");
    printf("\n----------------------------------------------------\n");
    printf("\nBisiklet kiralama ucreti: 30 TL\n");
    printf("Gunluk kiralama ucreti: %.2f TL", toplam);
    printf("\nBisiklet kullaniminda ortalama karbon salinimi: 0.00 kg CO2 (sifir emisyon)");
    

    if (toplam > p1.butce)
      {
        printf("\n UYARI: Toplam maliyet %.2f TL, butcenizi asiyor! ", toplam);
        printf("\n----------------------------------------------------");
      } 
    else 
      {
        printf("\nButceniz asilmadi. Keyifli surusler!");
        printf("\n----------------------------------------------------");
      }
}

void taksi(struct person p1)
 {
    int acilisUcret = 30, kmUcret = 20, binis;
    float km, toplam = 0, karbonSalinimi;

    printf("\n----------------------------------------------------");
    printf("\n\tTAKSI MALIYET VE KARBON SALINIMI");
    printf("\n----------------------------------------------------\n");

    printf("Taksimetre acilis ucreti: 30 TL\n");
    printf("Kilometre basi ucret: 20 TL\n");
    printf("Kac kez taksi kullandiniz? ");
    scanf("%d", &binis);
    printf("Toplam kac kilometre yol aldiniz? ");
    scanf("%f", &km);
    toplam = (acilisUcret * binis) + (km * kmUcret);    //Toplam maliyeti hesaplama.
    karbonSalinimi = km * 2.31;                         //Taksi ortalama karbon salýnýmý hesaplama.   2.31-> fosil yakýtlý taksi ortalama karbon salýnýmý
    printf("\n----------------------------------------------------"); 
    printf("\nToplam maliyetiniz: %.2f TL", toplam);
    printf("\nTaksi ortalama karbon salinimi: %.2f kg CO2", karbonSalinimi);
   

    if (toplam > p1.butce) 
      {
        printf("\n UYARI: Toplam maliyet %.2f TL, butcenizi asiyor! ", toplam);
        printf("\n----------------------------------------------------");
      }
     else
      {
        printf("\nButceniz asilmadi. Iyi yolculuklar!");
        printf("\n----------------------------------------------------");
      }
}

void otobus(struct person p1) 
{
    int kartSecim, kartKullanim;
    float toplam, karbonSalinimi;

    printf("\n----------------------------------------------------");
    printf("\n\tOTOBUS MALIYET VE KARBON SALINIMI");
    printf("\n----------------------------------------------------\n");

    printf("Ogrenci karti ucreti: 10 TL\n");
    printf("Tam kart ucreti: 20 TL\n");
    printf("\nOgrenci karti icin -> 1\nTam kart icin -> 2\nSeciminiz: ");
    scanf("%d", &kartSecim);

    switch (kartSecim)
     {
    case 1:
        printf("\nKullanim sayisini giriniz: ");
        scanf("%d", &kartKullanim);
        toplam = kartKullanim * 10;
        break;

    case 2:
        printf("\nKullanim sayisini giriniz: ");
        scanf("%d", &kartKullanim);
        toplam = kartKullanim * 20;
        break;

    default:
        printf("\n Gecersiz secim. Lutfen tekrar deneyiniz. ");
        return;
     }

    karbonSalinimi = kartKullanim * 0.1;   //Otobüs karbon salýnýmý hesaplama.  0.1 -> kiþi baþýna düþen ortalama karbon salýnýmý.
    printf("\nOtobus kullanim maliyeti: %.2f TL", toplam);
    printf("\nOtobus karbon salinimi: %.2f kg CO2", karbonSalinimi);
   

    if (toplam > p1.butce) 
     {
        printf("\n UYARI: Toplam maliyet %.2f TL, butcenizi asiyor! ", toplam);
        printf("\n----------------------------------------------------");
     }
     else 
     {
        printf("\nButceniz asilmadi. Iyi yolculuklar!");
        printf("\n----------------------------------------------------");
     }
}


