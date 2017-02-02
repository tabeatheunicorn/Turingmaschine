#include<stdio.h>
#include<stdlib.h>

#include"ameise.h"
#include"area.h"

//Globaler Strukturtyp Ameise, der den Status der Ameise enthält. X und Y bezeichenen die Position der Ameise auf dem Feld, Blick bezeichnet die Blickrichtung.
struct Ameise
{
  int x;
  int y;
  int blick ;
};
//Simulation des nächsten Laufschritts der Ameise. Funktionsergebnis ist wahr(1), wenn die Ameise noch auf dem Raster ist.
int nextStep(struct Ameise *, int len, char (*) [len]);


int main()
{
    printf("Gib nachfolgend zunaechst die Groesse des Feldes und anschliessend die Anzahl der Schritte ein.\n");

    //Variablen für Länge, Anzahl Schritte, die tatsächlichen Schritte, Wahrheitswert aufFeld
    int len, schritte, zaehler = 0, aufFeld = 1;
    scanf("%d", &len);
    scanf("%d", &schritte);
    printf("Rastergroesse: %d\n Schritte: %d \n", len, schritte);

    //Erstellen des Bewegungsfeldes der Ameise
    char spielfeld [len][len];
    initArea(len, spielfeld);

    //Erzeuge eine Ameise, die in der Mitte des Spielfelds sitzt und nach Unten schaut
    struct Ameise ameise = {len/2, len/2, 3};

    //Bewegung der Ameise, solange sie auf dem Feld ist und noch Schritte übrig hat.
    while( (zaehler <= schritte)  && (aufFeld ==1) )
    {
        aufFeld = nextStep(&ameise, len, spielfeld );
        zaehler++;
    }

    //Spielfeld am Ende anzeigen
    showArea(len, spielfeld);
    printf("Es wurden %d Schritte gebraucht.\n", zaehler);
    return 0;

}

int nextStep(struct Ameise * ameise, int len, char (*feld)[len])
{
    //Einfärben des Feldes
    if(feld[(*ameise).x][(*ameise).y]=='#')
    {
        feld[(*ameise).x][(*ameise).y] = ' ';
        (*ameise).blick = ((*ameise).blick -1 +4) % 4; //+4, da sonst modulo rechnung verfälscht wird
    }
    else
    {
        feld[(*ameise).x][(*ameise).y] = '#';
        (*ameise).blick = ((*ameise).blick + 1) % 4 ;
    }
    //Bewegen der Ameise
        switch ((*ameise).blick) //Bewegung in Blickrichtung
        {
        case 0: //Oben
            (*ameise).y-= 1;
            break;
        case 1: //Rechts
            (*ameise).x-= 1;
            break;
        case 2: //Unten
            (*ameise).y+= 1;
            break;
        case 3: //Links
            (*ameise).x += 1;
            break;
        }
    //Ermittelung, ob Ameise noch auf Feld ist. 1 ist wahr
    if((*ameise).x < 0 || (*ameise).y < 0 ||(*ameise).x >= len || (*ameise).y >= len)
    {
        return 0;
    }
    else
    {
        return 1;
    }



}


