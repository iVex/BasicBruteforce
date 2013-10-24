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
    printf("*  Basic Bruteforce system *\n");
    printf("*        By: iVex          *\n");
    printf("****************************\n\n");
    printf("\nMinimal Length of the pass: ");
    scanf("%i", &LgMin);
    printf("\nMaximal Length of the pass: ");
    scanf("%i", &LgMax);
    cout << "\nPassword: ";
    cin >> mdp;

    if(LgMin == 0 || LgMax == 0)
    {
        cout << "0 can be use for a length !" << endl;
    }
    else if(LgMin == LgMax)
    {
        cout << "Please, give 2 values" << endl;
    }
    else
    {
        t_start = clock();
        BruteForce(LgMin, LgMax, mdp);
        t_end = clock();

        printf("\n Numbers of try : %i \n", nbMDP);
        printf("Finish in : %i seconds.\n", (t_end - t_start)/1000);
        cout << "You're password is : \n" << mdp << endl;
        system("PAUSE");
    }
    return 0;
}

void BruteForce(int LongMin, int LongMax, string mdp)
{
 const char ALL[106] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz1234567890<>,?;.:/!з*╡∙%$гди+=})]р@ч^\\_`ш|-[({'#\"щ~&";
 int Lg = LongMin - 1;
 int i, x, y;

 char* Buff = (char*) malloc(Lg); // Create the buff of Lg octet
 while(Lg != LongMax && Buff != mdp)
 {
     realloc(Buff, Lg); // Increase the buff size
     int Nchar[Lg];
     for(i=0; i<=Lg; i++)
     {
         Buff[i] = ALL[0]; // Fill the buff of first char
         Nchar[i] = 0;
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
