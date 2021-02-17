#include<stdio.h>
#include<stdlib.h>
#include "achiev.h"
#include "generare.h"

int i;
int achiev_dist[35];
int achiev_elevatie[25];
int achiev_temp_min[250];
int achiev_viteza[11];
struct date date2;
int warn_puls,warn_dist;
int total_achiev=23,suma_achiev=0;

void display_total_achiev()
{
    printf("\nCongratulations, you have: %d/%d achievements",suma_achiev,total_achiev);
}

void warnings(struct date date2)
{

    if(date2.puls_mediu > 160)
        warn_puls=1;
        else warn_puls=0;
    if(date2.distanta > 22)
        warn_dist=1;
        else warn_dist=0;

}

void achievement_distanta(struct date date1)
{

    for(i = 5; i <= 35; i += 5){
        if(date1.distanta >= i)
            {achiev_dist[i] = 1;
            suma_achiev+=achiev_dist[i];
            }
            else achiev_dist[i]=0;}
}

void achievement_viteza_max(struct date date1)
{
    for(i = 10; i <= 25; i +=5){
        if(date1.viteza_maxima >= i)
            {achiev_viteza[i] = 1;
            suma_achiev+=achiev_viteza[i];
            }
            else achiev_viteza[i]=0;}
}

void achievement_elevatie(struct date date1)
{
    for(i = 50; i <= 250; i += 50){
        if(date1.elevatie > i)
            {achiev_elevatie[i] = 1;
            suma_achiev+=achiev_elevatie[i];
            }
            else achiev_elevatie[i]=0;}
}

void achievement_temp(struct date date1)
{
    for(i = 10; i >= 0; i -= 2){
        if(date1.temperatura < i)
            {achiev_temp_min[i] = 1;
            suma_achiev+=achiev_temp_min[i];
            }
            else achiev_temp_min[i]=0;}
}

void achievement_disp()
{
    int a=201,b=205,c=187,d=200,e=188,f=186; //╔ ═ ╗ ╚ ╝ ║
    int g=218,h=196,i=191; // ┌ ─ ┐
    int j=194; // ┬
    int k=179; // │
    int l=192,m=217,n=195,o=180; // └ ┘ ├ ┤
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("%c %c%c%c %c%c%c | | | %c%c%c \\   / %c%c%c %c\n",f,g,h,i,g,h,i,g,h,h,g,h,i,f);
    printf("%c %c%c%c %c   %c%c%c %c %c%c%c  \\ /  %c%c%c %c\n",f,n,h,o,k,n,h,o,k,n,h,h,l,h,i,f);
    printf("%c %c %c %c%c%c %c %c %c %c%c%c   V   %c%c%c %c\n",f,k,k,l,h,m,k,k,k,l,h,h,l,h,m,f);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,e);

    printf("Here are your achievements for the last run:\n");
    printf("\nDistance achievements:\n");
    for(i = 5; i <= 35; i+=5)
        if(achiev_dist[i] != 0)
            printf("Congratulations, you ran %d kilometers!\n",i);





    printf("\n\nSpeed achievements:\n");
    for(i = 10; i <= 25; i+=5)
        if(achiev_viteza[i] !=0 )
            printf("Congratulations, your speed was %d kilometers per hour!\n",i);



    printf("\n\nElevation achievements:\n");
    for(i = 50; i <= 250; i+=50)
        if(achiev_elevatie[i] != 0)
            printf("Congratulations, you climbed %d meters!\n",i);



    printf("\n\nTemperature achievements:\n");
    for(i = 10; i >= 0; i-=2)
        if(achiev_temp_min[i] != 0)
            printf("Congratulations, you ran under %d degrees Celsius!\n",i);


}

