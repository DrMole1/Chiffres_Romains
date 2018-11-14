// Programme : RomainToEntier
// BUT : Ce programme convertit un chiffre romain en sa valeur d�cimale enti�re, ou l'inverse.
// ENTREE : Un nombre romain en chaine de caract�res OU un entier d�cimal.
// SORTIE : Un entier d�cimal OU un nombre romain en chaine de caract�res.
// PRINCIPE :
// 1) L'utilisateur d�cide quel sous programme il veut utiliser avec un menu (en C, cela renverra dans un sous programme).
// 2) On v�rifie la cha�ne saisie par l'utilisateur pour qu'il n'y ait pas d'erreur ensuite OU on regarde s'il saisit une valeur enti�re correcte.
// 3) On ajoute ou soustrait progressivement notre valeur OU chaine de caract�re par r�-affectation en fonction de notre chaine de caract�res.
// 4) La valeur doit �tre comprise entre 1 et 3999 et la chaine ne doit pas d�passer les 21 caract�res.

// mise en place des biblioth�ques (macros)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //pour g�rer les concat�nations

// d�claration des constantes
#define M1 900
#define M2 950
#define M3 990
#define M4 995
#define M5 999
#define D1 400
#define D2 450
#define D3 490
#define D4 495
#define D5 499
#define C1 90
#define C2 95
#define C3 99
#define L1 40
#define L2 45
#define L3 49
#define X1 9
#define V1 4
#define MIN 1
#define MAX 3999
#define M 1000
#define D 500
#define C 100
#define L 50
#define X 10
#define V 5
#define I 1
#define MAXCAR 21

//prototypes des fonctions
int DecToRomain();
int RomainToDec();

int main()
{
    //initialisation des variables
    int nMenu=0;

    //d�roulement du menu
    printf("Programme des chiffres romains\n");
    printf("Tapez 1 : chiffre decimal -> chiffre romain\n");
    printf("Tapez 2 : chiffre romain -> chiffre decimal\n");
    printf("Tapez un autre chiffre pour fermer le programme\n");
    printf("Attention, les valeurs sont comprises entre 1 et 3999 !\n");
    scanf("%d", &nMenu);

    //redirection vers le sous-programme correspondant
    if (nMenu==1)
    {
        DecToRomain();
    }
    else if (nMenu==2)
    {
        RomainToDec();
    }

    return 0;
}


// Je n'ai pas pu impl�menter cette fonction sans erreur :
// Elle renvoyait tout le temps 0, surement une maladresse algorithmique sur les bool�ens ...
/*//IMPLEMENTATION
//FONCTION
//=============================================================
//BUT : V�rifie si les caract�res saisies sont des caract�res de chiffres romains
//ENTREES : Un caract�re
//SORTIE : Un bool�en (donc soit 0 soit 1)
//=============================================================
int checkRom(char cRom[MAXCAR])
{
    int nCpt = 0, nVerif=1; //d�claration d'une variable locale
    do
    {
        if ((cRom[nCpt] != 'M') || ((cRom[nCpt] != 'D') || (cRom[nCpt] != 'C') || (cRom[nCpt] != 'L') || (cRom[nCpt] != 'X') || (cRom[nCpt] != 'V') || (cRom[nCpt] != 'I')))
        {
            nVerif = 0;
        }
        nCpt++;
    } while ((nCpt <= strlen(cRom)) || (nVerif==1));

    return nVerif;
}*/




//IMPLEMENTATION
//FONCTION
//=============================================================
//BUT : Convertir un nombre d�cimal entier en un nombre romain
//ENTREES : Un nombre d�cimal entier
//SORTIE : Un nombre romain
//=============================================================
int DecToRomain()
{
    //d�claration des variables
    char cRom[MAXCAR];
    int nValeur=0, nCpt=0;

    //initialisation de la cha�ne de caract�res
    for (nCpt=0 ; nCpt<=MAXCAR-1 ; nCpt++)
    {
        cRom[nCpt] = "";
    }
    cRom[21]="";  //petit probl�me, le dernier caract�re ne s'initialise pas correctement (m�me avec nCpt<=MAXCAR), je le fais donc � la main

    //boucle de saisie : l'utilisateur ne pourra pas �crire une valeur invalide !
    do
    {
        printf("Veuillez saisir un entier decimal : \n");
        scanf("%d", &nValeur);
        if ((nValeur < MIN) || (nValeur > MAX))
        {
            printf("Votre valeur doit etre comprise entre 1 et 3999");
        }
    } while ((nValeur < MIN) || (nValeur > MAX));



    //traitement des milliers
    // on utilise une boucle TANT QUE car nous ne sommes pas oblig� de passer ici (si valeur = 766 et 766 < 1000)
    while (nValeur >= M)
    {
        strcat (cRom, "M"); // on concat�ne la chaine
        nValeur -= M; // on soustrait la valeur saisie par son repr�sentant en chiffre romain
    }

	// traitement des soustractions avant les milliers
	if (nValeur >= M5)
    {
        strcat (cRom, "IM");
        nValeur -= M5;
    }
    else if (nValeur >= M4)
    {
        strcat (cRom, "VM");
        nValeur -= M4;
    }
    else if (nValeur >= M3)
    {
        strcat (cRom, "XM");
        nValeur -= M3;
    }
    else if (nValeur >= M2)
    {
        strcat (cRom, "LM");
        nValeur -= M2;
    }
    else if (nValeur >= M1)
    {
        strcat (cRom, "CM");
        nValeur -= M1;
    }



    //traitement de 500
    if (nValeur >= D)
    {
        strcat (cRom, "D");
        nValeur -= D;
    }

	// traitement des soustractions avant les 500
	if (nValeur >= D5)
    {
        strcat (cRom, "ID");
        nValeur -= D5;
    }
    else if (nValeur >= D4)
    {
        strcat (cRom, "VD");
        nValeur -= D4;
    }
    else if (nValeur >= D3)
    {
        strcat (cRom, "XD");
        nValeur -= D3;
    }
    else if (nValeur >= D2)
    {
        strcat (cRom, "LD");
        nValeur -= D2;
    }
    else if (nValeur >= D1)
    {
        strcat (cRom, "CD");
        nValeur -= D1;
    }



    //traitement des centaines
    while (nValeur >= C)
    {
        strcat (cRom, "C");
        nValeur -= C;
    }

	// traitement des soustractions avant les centaines
    if (nValeur >= C3)
    {
        strcat (cRom, "IC");
        nValeur -= C3;
    }
    else if (nValeur >= C2)
    {
        strcat (cRom, "VC");
        nValeur -= C2;
    }
    else if (nValeur >= C1)
    {
        strcat (cRom, "XC");
        nValeur -= C1;
    }



    //traitement de 50
    if (nValeur >= L)
    {
        strcat (cRom, "L");
        nValeur -= L;
    }

	// traitement des soustractions avant les 50
	if (nValeur >= L3)
    {
        strcat (cRom, "IL");
        nValeur -= L3;
    }
    else if (nValeur >= L2)
    {
        strcat (cRom, "VL");
        nValeur -= L2;
    }
    else if (nValeur >= L1)
    {
        strcat (cRom, "XL");
        nValeur -= L1;
    }



    // traitement des dizaines
	while (nValeur >= X)
    {
        strcat (cRom, "X");
        nValeur -= X;
    }

	// traitement des soustractions avant les dizaines
	if (nValeur >= X1)
		{
            strcat (cRom, "IX");
            nValeur -= X1;
		}


	// traitement pour le 5
	if (nValeur >= V)
		{
		    strcat (cRom, "V");
            nValeur -= V;
		}

	// traitement de la soustraction avant le 5
	if (nValeur >= V1)
		{
		    strcat (cRom, "IV");
            nValeur -= V1;
		}



	// traitement des unit�s
	while (nValeur >= I)
		{
		    strcat (cRom, "I");
            nValeur -= I;
		}


	// affichage
	printf("Le chiffre romain de votre valeur est : %s", cRom);
	return 0;
}




//IMPLEMENTATION
//FONCTION
//=============================================================
//BUT : Convertir un nombre romain entier en un nombre d�cimal
//ENTREES : Un nombre romain
//SORTIE : Un nombre d�cimal entier
//=============================================================
int RomainToDec()
{
    //d�claration des variables
    char cRom[MAXCAR];
    int nValeur=0, nCpt=0;

    //initialisation de la cha�ne de caract�res
    for (nCpt=0 ; nCpt<=MAXCAR-1 ; nCpt++)
    {
        cRom[nCpt] = "";
    }
    cRom[21]="";  //petit probl�me, le dernier caract�re ne s'initialise pas correctement (m�me avec nCpt<=MAXCAR), je le fais donc � la main

    // boucle de saisie : l'utilisateur ne pourra pas �crire une valeur invalide !
	do
    {
		printf("Veuillez saisir un chiffre romain : ");
		scanf("%s", &cRom);
	}while ((strlen(cRom) > MAXCAR) || (strlen(cRom) < MIN));
	//la longueur maximale que peut avoir un chiffre romain < 3999 est de 21 caract�res




	// boucle du traitement principal
	for (nCpt=0 ; nCpt <= strlen(cRom) ; nCpt++)
    {
        // traitement du M
        // J'ai d�cid� de ne pas faire que des IF ELSE pour a�rer au maximum le code, en d�pit d'une meilleure optimisation
		if (cRom[nCpt] == 'M')
        {
            nValeur += M;  //on r�affecte la valeur par le montant voulue (d�clar� dans les constantes)
        }


		// traitement du D
		if (cRom[nCpt] == 'D')
        {
            nValeur += D;
        }


        // traitement du C
		if (cRom[nCpt]=='C')
        {
            if (cRom[nCpt+MIN]=='M')
            {
                nValeur += M1;
				nCpt++;
            }
            else if (cRom[nCpt+MIN]=='D')
            {
                nValeur += D1;
				nCpt++;
            }
            else
            {
                nValeur += C;
            }
        }


        // traitement du L
		if (cRom[nCpt]=='L')
        {
            if (cRom[nCpt+MIN]=='M')
            {
                nValeur += M2;
				nCpt++;
            }
            else if (cRom[nCpt+MIN]=='D')
            {
                nValeur += D2;
				nCpt++;
            }
            else
            {
                nValeur += L;
            }
        }



        // traitement du X
		if (cRom[nCpt]=='X')
        {
            if (cRom[nCpt+MIN]=='M')
            {
                nValeur += M3;
				nCpt++;
            }
            else if (cRom[nCpt+MIN]=='D')
            {
                nValeur += D3;
				nCpt++;
            }
            else if (cRom[nCpt+MIN]=='C')
            {
                nValeur += C1;
				nCpt++;
            }
            else if (cRom[nCpt+MIN]=='L')
            {
                nValeur += L1;
				nCpt++;
            }
            else
            {
                nValeur += X;
            }
        }


        // traitement du V
        if (cRom[nCpt]=='V')
        {
            if (cRom[nCpt+MIN]=='M')
            {
                nValeur += M4;
                nCpt++;
            }
            else if (cRom[nCpt+MIN]=='D')
            {
                nValeur += D4;
                nCpt++;
            }
            else if (cRom[nCpt+MIN]=='C')
            {
                nValeur += C2;
                nCpt++;
            }
            else if (cRom[nCpt+MIN]=='L')
            {
                nValeur += L2;
                nCpt++;
            }
            else
            {
                nValeur += V;
            }
        }



        // traitement du I
        if (cRom[nCpt]=='I')
        {
            if (cRom[nCpt+MIN]=='M')
            {
                nValeur += M5;
                nCpt++;
            }
            else if (cRom[nCpt+MIN]=='D')
            {
                nValeur += D5;
                nCpt++;
            }
            else if (cRom[nCpt+MIN]=='C')
            {
                nValeur += C3;
                nCpt++;
            }
            else if (cRom[nCpt+MIN]=='L')
            {
                nValeur += L3;
                nCpt++;
            }
            else if (cRom[nCpt+MIN]=='X')
            {
                nValeur += X1;
                nCpt++;
            }
            else if (cRom[nCpt+MIN]=='V')
            {
                nValeur += V1;
                nCpt++;
            }
            else
            {
                nValeur += I;
            }
        }
    }

    //affichage de la valeur
    if (nValeur == 0) //si le joueur saisit autre chose que des caract�res romains
    {
        printf("Vous n'avez pas saisit un chiffre romain !");
    }
    else
    {
        printf("Votre valeur correspondant a votre chiffre romain est : %d", nValeur);
    }


    return 0;

}


