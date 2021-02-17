#ifndef GENERARE_H_INCLUDED
#define GENERARE_H_INCLUDED
#include <stdlib.h>

extern int dis,hb,rpm,elev,temp;
//intra in main
extern struct date
{
    int distanta;
    int puls_mediu;
    int viteza_maxima;
    int elevatie;
    int temperatura;
};


extern struct om
{
    int distmax;
    int puls_med_sapt;
    int vit_max;
    int elev_max;
    int temp_med;
};

extern void gen_prieteni();
extern void gen_noua();
extern void gen_istoric();
extern void afisaredistmax();
extern void afisarevitmax();
extern void afisareelevmax();


#endif // GENERARE_H_INCLUDED
