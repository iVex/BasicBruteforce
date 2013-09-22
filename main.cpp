#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void BruteForce(int LongMin, int LongMax, string mdp);

unsigned long nbMDP = 0;

int main()
{
    int LgMin = 0;
    int LgMax = 0;
    string mdp;
    unsigned long t_start = 0;
    unsigned long t_end = 0;
    printf("****************************\n");
    printf("*  Fonction de BruteForce  *\n");
    printf("*        By: iVex          *\n");
    printf("****************************\n\n");
    printf("\nLongueur minimal du pass: ");
    scanf("%i", &LgMin);
    printf("\nLongueur maximal du pass: ");
    scanf("%i", &LgMax);
    cout << "\nMot de passe: ";
    cin >> mdp;

    if(LgMin == 0 || LgMax == 0)
    {
        cout << "Le nombre 0 ne peut pas etre une valeur !" << endl;
    }
    else if(LgMin == LgMax)
    {
        cout << "Veuillez mettre deux valeurs différentes s'il vous plaît" << endl;
    }
    else
    {
        t_start = clock();
        BruteForce(LgMin, LgMax, mdp);
        t_end = clock();

        printf("\n nb de mdp : %i \n", nbMDP);
        printf("Terminer en : %i secondes.\n", (t_end - t_start)/1000);
        cout << "Votre mot de passe est : \n" << mdp << endl;
        system("PAUSE");
    }
    return 0;
}

void BruteForce(int LongMin, int LongMax, string mdp)
{
 const char ALL[106] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz1234567890<>,?;.:/!§*µù%$£¤¨+=})]à@ç^\\_`è|-[({'#\"é~&";
 int Lg = LongMin - 1;
 int i, x, y;

 char* Buff = (char*) malloc(Lg); // Creer le Buff de Lg octet
 while(Lg != LongMax && Buff != mdp)
 {
     realloc(Buff, Lg); // Augmente la taille du buff
     int Nchar[Lg];
     for(i=0; i<=Lg; i++)
     {
         Buff[i] = ALL[0]; // Remplie le Buff du premier char
         Nchar[i] = 0; // Initialise le tableau de int a 0
     }
     while(Nchar[0] != 105)
     {
          for(x=0; x<=105; x++)
          {
                  Buff[Lg] = ALL[x];
                  Nchar[Lg] = x;
                  printf("%s \n", Buff);
                  nbMDP++;
          }
          for(y=Lg; y>=0; y--)
          {
              if((Nchar[y] == 105)&&(Nchar[0]!= 105))
              {
                  Nchar[y] = 0;
                  Nchar[y-1]++;
              }
              Buff[y] = ALL[Nchar[y]];
          }
    }
    Lg++;
 }
 free(Buff);// Libere la memoire
}
