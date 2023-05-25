/*
    Le code Arduino ci-dessous est un exemple de mise en œuvre d'un algorithme
    pour calculer des frames.
    L'algorithme proposé effectue les opérations suivantes :
    Il déclare un tableau de nombres à virgule flottante appelé "vect" avec une taille de 3000.
    Il déclare un pointeur de pointeur de flottants appelé "sframe"
     qui sera utilisé pour stocker les segments du tableau "vect".
    Il définit une constante "tailleframe" avec une valeur de 256.
    Il initialise les valeurs du tableau "vect" avec une valeur d'exemple (i/2.0).
    Il calcule le nombre total de segments nécessaires en divisant la taille totale 
    du tableau "vect" par la taille de chaque segment.
    Il alloue dynamiquement la mémoire pour stocker les segments 
    dans le tableau "sframe" en fonction du nombre de segments calculé.
    Il segmente le tableau "vect" en parcourant chaque segment et en stockant 
    les valeurs correspondantes dans le tableau "sframe"
*/


#include<Arduino.h>

// C'est un exemple  pour vous donnez 

float vect[3000]; // Tableau d'origine

float **sframe; // les frames 
const int tailleframe(256);
int tailleTotale;
void setup() {
 sframe  = (float **)malloc(tailleframe* sizeof(float *));
 tailleTotale = sizeof(vect) / sizeof(vect[0]);
  // Initialisation des valeurs dans vect (exemple)
  for (int i = 0; i < tailleTotale; i++) {
    vect[i] = i/2.;
  }

  int nombreframe = tailleTotale / tailleframe;
  if( tailleTotale % tailleframe==0)
  {
  for (int i = 0; i < tailleframe;i++) {
             sframe[i] = (float *)malloc((nombreframe) * sizeof(float));
             }
  } else
  {
    nombreframe=nombreframe+1;
    for (int i = 0; i < tailleframe; i++) {
             sframe[i] = (float *)malloc((nombreframe) * sizeof(float));
             }
  }


  // Segmentation du tableau
  for (uint16_t i = 0; i < nombreframe; i++) {
    int startIndex = i * tailleframe;
    for (int j = 0; j < tailleframe; j++) {
      sframe[i][j] = vect[startIndex + j];
       Serial.print(sframe[i][j]);
      Serial.print(" ");
    }
  }
/*
  // Affichage des segments (exemple)
  for (uint16_t i = 0; i < nombreSegments; i++) {
    for (uint16_t j = 0; j < tailleSegment; j++) {
      Serial.print(svect[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }*/
}

void loop() {
  // Code supplémentaire du programme (si nécessaire)
}
