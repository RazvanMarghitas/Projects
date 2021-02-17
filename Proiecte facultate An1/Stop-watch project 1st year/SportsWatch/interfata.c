#include <stdio.h>
#include <stdlib.h>
#include "interfata.h"
#include<string.h>
#include"generare.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


 int x[100][100],rows;

void menu_screen()
{
    int a=201,b=205,c=187,d=200,e=188,f=186; //╔ ═ ╗ ╚ ╝ ║
    int g=218,h=196,i=191; // ┌ ─ ┐
    int j=194; // ┬
    int k=179; // │
    int l=192,m=217,n=195,o=180; // └ ┘ ├ ┤
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("\t%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c     \\              /  %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c |     |  %c\n",f,g,h,h,h,h,h,i,g,h,h,h,h,h,i,g,h,h,h,h,h,i,g,h,h,h,h,h,i,h,h,h,j,h,h,h,g,h,h,h,h,h,i,h,h,h,j,h,h,h,g,h,h,h,h,h,i,f);
    printf("\t%c %c       %c     %c %c     %c %c     %c    %c         \\     \\      /   %c     %c    %c    %c       %c     %c  %c\n",f,k,k,k,k,k,k,k,k,k,k,k,k,k,k,f);
    printf("\t%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c     %c %c%c%c%c%c%c%c    %c          \\    /\\    /    %c%c%c%c%c%c%c    %c    %c       %c%c%c%c%c%c%c  %c\n",f,l,h,h,h,h,h,i,n,h,h,h,h,h,m,k,k,n,h,h,h,h,h,m,k,n,h,h,h,h,h,o,k,k,n,h,h,h,h,h,o,f);
    printf("\t%c       %c %c       %c     %c %c    \\     %c           \\  /  \\  /     %c     %c    %c    %c       %c     %c  %c\n",f,k,k,k,k,k,k,k,k,k,k,k,k,f);
    printf("\t%c %c%c%c%c%c%c%c %c       %c%c%c%c%c%c%c %c     \\    %c            \\/    \\/      %c     %c    %c    %c%c%c%c%c%c%c %c     %c  %c\n",f,l,h,h,h,h,h,m,k,l,h,h,h,h,h,m,k,k,k,k,k,l,h,h,h,h,h,m,k,k,f);
    printf("\t%c                                                                                                %c\n",f,f);
    printf("\t%c                                   S I M U L A T O R                                            %c\n",f,f);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,e);
    printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("\t\t\t\t\t\t%c 1.New Run %c\n",f,f);
    printf("\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c",d,b,b,b,b,b,b,b,b,b,b,b,e);
    printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("\t\t\t\t\t\t%c 2.History %c\n",f,f);
    printf("\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c",d,b,b,b,b,b,b,b,b,b,b,b,e);;
    printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("\t\t\t\t\t\t%c 3.Reset   %c\n",f,f);
    printf("\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c",d,b,b,b,b,b,b,b,b,b,b,b,e);
    printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("\t\t\t\t\t\t%c 4.Achievs %c\n",f,f);
    printf("\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c",d,b,b,b,b,b,b,b,b,b,b,b,e);
    printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("\t\t\t\t\t\t%c 5.LeaderB %c\n",f,f);
    printf("\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c",d,b,b,b,b,b,b,b,b,b,b,b,e);
    printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("\t\t\t\t\t\t%c 6.Quit!   %c\n",f,f);
    printf("\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c",d,b,b,b,b,b,b,b,b,b,b,b,e);
    printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("\t\t\t\t\t\t%c 7.Credits %c\n",f,f);
    printf("\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c",d,b,b,b,b,b,b,b,b,b,b,b,e);
}

void new_run()
{
    int a=201,b=205,c=187,d=200,e=188,f=186; //╔ ═ ╗ ╚ ╝ ║
    int g=218,h=196,i=191; // ┌ ─ ┐
    int j=194; // ┬
    int k=179; // │
    int l=192,m=217,n=195,o=180; // └ ┘ ├ ┤
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("%c | | %c%c%c \\  \\/  /   %c%c%c | | | | %c\n",f,g,h,h,g,h,i,f);
    printf("%c %c\\%c %c%c%c  \\ /\\ /    %c%c%c %c %c %c\\%c %c\n",f,k,k,n,h,h,n,h,m,k,k,k,k,f);
    printf("%c %c %c %c%c%c   V  V     %c \\ %c%c%c %c %c %c\n",f,k,k,l,h,h,k,l,h,m,k,k,f);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,e);
    printf("\n\nNEW RUN: Distance: %d km | Heart beat: %d bpm | Maximum Speed: %d km/h | Elevation: %d m | Temperature: %d *C\n",dis,hb,rpm,elev,temp);
}

void istoric() //istoric
{
    int a=201,b=205,c=187,d=200,e=188,f=186; //╔ ═ ╗ ╚ ╝ ║
    int g=218,h=196,i=191; // ┌ ─ ┐
    int j=194; // ┬
    int k=179; // │
    int l=192,m=217,n=195,o=180; // └ ┘ ├ ┤
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("%c | | | %c%c%c %c%c%c %c%c%c %c%c%c \\ / %c\n",f,g,h,i,h,j,h,g,h,i,g,h,i,f);
    printf("%c %c%c%c %c %c%c%c  %c  %c %c %c%c%c  V  %c\n",f,n,h,o,k,l,h,i,k,k,k,n,h,m,f);
    printf("%c %c %c %c %c%c%c  %c  %c%c%c %c \\  %c  %c\n",f,k,k,k,l,h,m,k,l,h,m,k,k,f);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,e);
    getting_matrix();
    print_matrix();
}

void getting_matrix()
{
    FILE *fp;
    int y,z;
    char linie[100],*token;
    fp = fopen("istoric.txt","r");
    y=0;
    while(!feof(fp))
    {
        fscanf(fp, "%s",linie);
        token=strtok(linie,",");
        z=0;
        while(token!=NULL)
        {
            x[y][z]=atoi(token);
            token=strtok(NULL,",");
            z++;
        }
        y++;
    }
    rows=y;
    fclose(fp);
}

void print_matrix()
{
    int i,j;
    for(i=0;i<rows;i++)
    {
            printf("%d.Distance: %d km | Heart beat: %d bpm | Maximum Speed: %d km/h | Elevation: %d m | Temperature: %d *C \n",i+1,x[i][0],x[i][1],x[i][2],x[i][3],x[i][4]);
    }
}



void high_score()
{
    int a=201,b=205,c=187,d=200,e=188,f=186; //╔ ═ ╗ ╚ ╝ ║
    int g=218,h=196,i=191; // ┌ ─ ┐
    int j=194; // ┬
    int k=179; // │
    int l=192,m=217,n=195,o=180; // └ ┘ ├ ┤
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("%c | | | %c%c%c | |   %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c\n",f,g,h,i,g,h,i,g,h,i,g,h,i,g,h,i,g,h,h,g,h,i,f);
    printf("%c %c%c%c %c %c%c%c %c%c%c   %c%c%c %c   %c %c %c%c%c %c%c%c %c%c%c %c\n",f,n,h,o,k,k,g,i,n,h,o,l,h,i,k,k,k,n,h,m,n,h,h,l,h,i,f);
    printf("%c %c %c %c %c%c%c %c %c   %c%c%c %c%c%c %c%c%c %c \\ %c%c%c %c%c%c %c\n",f,k,k,k,l,h,m,k,k,l,h,m,l,h,m,l,h,m,k,l,h,h,l,h,m,f);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,e);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("%c a.Distmax %c\n",f,f);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",d,b,b,b,b,b,b,b,b,b,b,b,e);
  /*  printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("%c b.Vit.Max %c\n",f,f);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",d,b,b,b,b,b,b,b,b,b,b,b,e);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("%c c.ElevMax %c\n",f,f);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",d,b,b,b,b,b,b,b,b,b,b,b,e);*/
}

void distmax()
{
    int a=201,b=205,c=187,d=200,e=188,f=186; //╔ ═ ╗ ╚ ╝ ║
    int g=218,h=196,i=191; // ┌ ─ ┐
    int j=194; // ┬
    int k=179; // │
    int l=192,m=217,n=195,o=180; // └ ┘ ├ ┤
    printf("\n\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("\t\t\t\t\t%c TOP10 By maximum distance %c\n",f,f);
    printf("\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,e);
}

/*void vitmax()
{
    int a=201,b=205,c=187,d=200,e=188,f=186; //╔ ═ ╗ ╚ ╝ ║
    int g=218,h=196,i=191; // ┌ ─ ┐
    int j=194; // ┬
    int k=179; // │
    int l=192,m=217,n=195,o=180; // └ ┘ ├ ┤
    printf("\n\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("\t\t\t\t\t%c TOP10 By maximum speed %c\n",f,f);
    printf("\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,e);
}

void elevmax()
{
    int a=201,b=205,c=187,d=200,e=188,f=186; //╔ ═ ╗ ╚ ╝ ║
    int g=218,h=196,i=191; // ┌ ─ ┐
    int j=194; // ┬
    int k=179; // │
    int l=192,m=217,n=195,o=180; // └ ┘ ├ ┤
    printf("\n\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("\t\t\t\t\t%c TOP10 By maximum elevation %c\n",f,f);
    printf("\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,e);
}*/

void credits()
{
    int a=201,b=205,c=187,d=200,e=188,f=186; //╔ ═ ╗ ╚ ╝ ║
    int g=218,h=196,i=191; // ┌ ─ ┐
    int j=194; // ┬
    int k=179; // │
    int l=192,m=217,n=195,o=180; // └ ┘ ├ ┤
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",a,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,c);
    printf("%c %c%c%c %c%c%c %c%c%c |\\  | %c%c%c %c%c%c %c\n",f,g,h,i,g,h,i,g,h,h,h,j,h,g,h,i,f);
    printf("%c %c   %c%c%c %c%c%c %c ) %c  %c  %c%c%c %c\n",f,k,n,h,m,n,h,h,k,k,k,l,h,i,f);
    printf("%c %c%c%c %c \\ %c%c%c %c/  %c  %c  %c%c%c %c\n",f,l,h,m,k,l,h,h,k,k,k,l,h,m,f);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,e);
    printf("The awesome team that created it:\n\nKonievic Robert\nLozba Iustin\nMarghitas Razvan-Nicolae\n\nThank you all for listening to us!\n\n\nPS: The thanks were from us not Teodora!\n\n\nAtleast this time!");
}

void exitscr()
{
    int a=201,b=205,c=187,d=200,e=188,f=186; //╔ ═ ╗ ╚ ╝ ║
    int g=218,h=196,i=191; // ┌ ─ ┐
    int j=194; // ┬
    int k=179; // │
    int l=192,m=217,n=195,o=180; // └ ┘ ├ ┤
    int p=193; //┴
    printf("\t\t\t    %c%c%c%c%c%c%c\n",g,h,h,j,h,h,i);
    printf("\t\t\t    %c  %c  %c\n",k,k,k);
    printf("\t\t\t    %c%c%c%c%c%c%c\n",n,h,h,p,h,h,o);
    printf("\t\t\t    %c     %c\n",k,k);
    printf("\t\t\t    %c     %c\n",k,k);
    printf("\t\t\t    %c     %c\n",k,k);
    printf("\t\t\t    %c     %c\n",k,k);
    printf("\t\t\t    %c     %c\n",k,k);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",g,h,h,h,p,h,h,h,h,h,p,h,h,h,i);
    printf("\t\t\t%c             %c\n",k,k);
    printf("\t\t\t%c    Have     %c\n",k,k);
    printf("\t\t\t%c   a nice    %c\n",k,k);
    printf("\t\t\t%c    day!     %c\n",k,k);
    printf("\t\t\t%c   *    *    %c\n",k,k);
    printf("\t\t\t%c             %c\n",k,k);
    printf("\t\t\t%c  %c%c%c%c%c%c%c%c   %c\n",k,l,h,h,h,h,h,h,m,k);
    printf("\t\t\t%c             %c\n",k,k);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",l,h,h,h,j,h,h,h,h,h,j,h,h,h,m);
    printf("\t\t\t    %c     %c\n",k,k);
    printf("\t\t\t    %c  %c  %c\n",k,k,k);
    printf("\t\t\t    %c     %c\n",k,k);
    printf("\t\t\t    %c  %c  %c\n",k,k,k);
    printf("\t\t\t    %c     %c\n",k,k);
    printf("\t\t\t    %c  %c  %c\n",k,k,k);
    printf("\t\t\t    %c     %c\n",k,k);
    printf("\t\t\t    %c%c%c%c%c%c%c\n",l,h,h,h,h,h,m);
}
