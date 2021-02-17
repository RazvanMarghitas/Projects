#include "generare.h"
#include <stdlib.h>
#include <stdio.h>
#include "interfata.h"
#include "achiev.h"
#include <time.h>

int dis,hb,rpm,elev,temp;
int i;
extern struct om om1[10];
extern struct date date1[5];
extern struct date date2;





void gen_prieteni(struct om om1[])
{

    for(i=0;i<10;i++)
    {
        om1[i].distmax=rand()%98+7;
        om1[i].puls_med_sapt=rand()%80+100;
        om1[i].vit_max=rand()%15+10;
        om1[i].elev_max=rand()%200+50;
        om1[i].temp_med=rand()%27+5;
    }
}

void gen_istoric(struct date date1[])
{
    FILE *f1;
    f1=fopen("istoric.txt","r+");
    srand((time(NULL)));
    for (i=0;i<6;i++)
    {
     date1[i].distanta=rand()%20+1;
     date1[i].puls_mediu=rand()%80+100;
     date1[i].viteza_maxima=rand()%15+10;
     date1[i].elevatie=rand()%250;
     date1[i].temperatura=rand()%32;
    }
    for(i=0;i<6;i++)
        fprintf(f1,"%d,%d,%d,%d,%d\n",date1[i].distanta,date1[i].puls_mediu,date1[i].viteza_maxima,date1[i].elevatie,date1[i].temperatura);
    fclose(f1);
}


void gen_noua(struct date date2)
{

    FILE *f1;
    srand(time(NULL));
     date2.distanta=(rand()%31)+1;
     date2.puls_mediu=(rand()%81)+100;
     date2.viteza_maxima=(rand()%16)+10;
     date2.elevatie=rand()%250;
     date2.temperatura=rand()%32;
     f1=fopen("istoric.txt","a");
     fprintf(f1,"%d,%d,%d,%d,%d\n",date2.distanta,date2.puls_mediu,date2.viteza_maxima,date2.elevatie,date2.temperatura);
     fclose(f1);
    dis=date2.distanta;
    hb=date2.puls_mediu;
    rpm=date2.viteza_maxima;
    elev=date2.elevatie;
    temp=date2.temperatura;
    warnings(date2);
    achievement_distanta(date2);
    achievement_viteza_max(date2);
    achievement_elevatie(date2);
    achievement_temp(date2);
}

void bubbleSortdist(struct om om1[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (om1[j].distmax < om1[j+1].distmax)
              swap(&om1[j], &om1[j+1]);
}
/*
void bubbleSortvit(struct om om1[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (om1[j].vit_max > om1[j+1].vit_max)
              swap(&om1[j], &om1[j+1]);
}

void bubbleSortelev(struct om om1[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (om1[j].elev_max > om1[j+1].elev_max)
              swap(&om1[j], &om1[j+1]);
}
*/
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void afisaredistmax(struct om om1[])
{
    int i;
    bubbleSortdist(om1,10);
    for(i=0;i<10;i++)
    printf("\t\t\t\t %d.Distance: %d km/sapt | Elevation: %d m | Speed: %d km/h\n",i+1,om1[i].distmax,om1[i].elev_max,om1[i].vit_max);
}
/*
void afisarevitmax(struct om om1[])
{
    int i;
    bubbleSortvit(om1,10);
    for(i=0;i<10;i++)
    printf("\t\t\t\t %d.Distance: %d km | Elevation: %d m | Speed: %d km/h\n",i+1,om1[i].distmax,om1[i].elev_max,om1[i].vit_max);
}

void afisareelevmax(struct om om1[])
{
    int i;
    bubbleSortelev(om1,10);
    for(i=0;i<10;i++)
    printf("\t\t\t\t %d.Distance: %d km | Elevation: %d m | Speed: %d km/h\n",i+1,om1[i].distmax,om1[i].elev_max,om1[i].vit_max);
}
*/
