#include <stdio.h>
#include "area.h"

//Übergebenes, quadratisches Array mit in der Funktion vorgegebenem Zeichen füllen
void initArea(int len, char (*area)[len])
{
    //Zeichen, mit dem das Array gefüllt wird, potentiell auskommentieren
    //printf("Zeichen, mit dem das gesamte Array gefuellt werden soll:\n");
    //char zeichen = 'a';
    //scanf("%c", &zeichen);
    //printf("%c\n", zeichen);
    // Zeilen durchlaufen
  for (int i = 0; i < len; i++)
  {
      //Spalten durchlaufen
      for (int j = 0; j < len; j++)
      {
          //Mit  Leerzeichen füllen
          area[i][j] = ' ';
      }
  }
}

void showArea(int len, char (*area)[len])
{
   //Erste Zeile

    printf("%c", '+');
    for (int i = 0; i < len; i++)
    {
        printf("%c",'-');
    }
    printf("%c\n", '+');
    //Umrandung der Mitte und Inhalt des Spielfelds anzeigen
    for(int i = 0; i < len; i++)
    {
        printf("%c",'|');
        for (int j = 0; j < len; j++)
        {
           printf("%c",area [i][j]);
        }
        printf("%c\n",'|');
    }
    //letzte Zeile
     printf("%c",'+');
    for (int i = 0; i < len; i++)
    {
        printf("%c",'-');
    }
    printf("%c\n",'+');
}
