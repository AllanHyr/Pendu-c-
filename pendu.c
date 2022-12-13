#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE_MAX 1000

char pseudo[8];
char caractUsed[30];
char devine[TAILLE_MAX] = "";
char devineBon[20];
char alphabet[25];
int tenta;
int demandePseudo();
int demandeLettre();
int nombreligne;
int caract;
int lchaine;
int longChaine();
int test;
int alphaok;
int caractTest;
int alphaInit();
int alphaTest();
int testCaract();
int caractUse();
int initMot();
int randMot();
int pendu();
int triTop();
int newScore();
int printCaractUse();
int printTop();
int initDevine();
int classTop();
int win;
int winbis;
int score;
int j;
struct top	{
	char pseudoTop[8];
	int scoreTop;
};
struct top ten[TAILLE_MAX];




int main()	{
	srand(time(NULL));
	alphaInit();
	demandePseudo();
	score = 0;
	tenta = 0;
	winbis = 1;
	while(tenta < 8)	{
		if(winbis == 1)	{
			winbis = 0;
			initDevine();
			randMot();
			longChaine();
			initMot();
			win = lchaine;
			j = 0;
		}
		pendu();
		printf("%s\n",devineBon);
		demandeLettre();
		alphaTest();	
		if(alphaok == 1)	{
			test = 0;
			caractUse();
			testCaract();
		if(test == lchaine)
			tenta++;
		if(tenta == 8)	{
			printf("perdu\n");
			pendu();
		}
		if(win == 0)	{
			score = score + 100;
			printf("bravo\n");
			winbis = 1;
		}
		printCaractUse();
		}
		else	{
			printf("error\n");
		}				
		}
	newScore();
	classTop();
	triTop();
	printTop();
}
int demandePseudo()	{
/** demande le pseudo au joueur */
	int i = 0;
	char reste;
	printf("Pseudo ?\n");
	reste = getchar();
	while(reste != '\n')	{
		if(i < 7)	{
			pseudo[i] = reste;
			i++;
	    }
	    reste = getchar();
	}
	pseudo[i] = '\0';
	printf("Votre pseudo = %s\n",pseudo);
}
int demandeLettre()	{
/** Demande une lettre et vide le buffer dans reste */
	int reste;
	int i;
		printf("%d lettres\n",lchaine);
		printf("Lettre ?\n");
		caract = getchar();
		while(reste != '\n')	{
			reste = getchar();
		}
}

int longChaine()	{
/** calcul la longueur du mot */
	int i = 0;
	lchaine = 0;
	while(devine[i] != '\0')	{
		lchaine++;
		i++;
	}
}
int testCaract()	{
/** test tout les caractères du mot si == ou pas */
	int i = 0;
	while(devine[i] != '\0')	{
		if((devine[i] == caract)&&(caractTest == 0))	{
			score = score + 10;
			win--;
			devineBon[i] = caract;
			printf("Bien !\n");
		}
		else	{
		test++;
		}
		i++;
	}
	j++;
}
int caractUse()	{
/** Test le caract a déjà été utilisé */
	int i = 0;
	caractTest = 0;
	while(i < j)	{
		if(caract == caractUsed[i])	{
			caractTest = 1;
			test = test -1;
		}	
		i++;
	}
/** Si caract déjà use fait rien sinon place dans le tableau de caract use (emplacement j)*/
	if(caractTest == 1)
		j--;
	if(caractTest == 0)
		caractUsed[j] = caract;
}
int initMot()	{
/** Met un tiret pour chaque lettre dans le mot */
	int i;
	for(i = 0; i < lchaine; i++)	{
		devineBon[i] = '_';
	}
}
int alphaInit()	{
/** Tableau qui stock les lettres de l'alphabet */
	int i;
	int alpha = 97;
	for(i = 0; i < 26; i++)	{
		alphabet[i] = alpha;
		alpha++;
	}
}
int alphaTest()	{
/** Tableau qui test si les lettres sont dans l'alphabet */
	int i;
	alphaok = 0;
	for(i = 0; i < 26; i++)	{
		if(alphabet[i] == caract)
			alphaok = 1;
	}
}
int pendu()	{
/** Affichage du pendu */
	if(tenta == 1)	{
		printf("                        |        \n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
	}
	if(tenta == 2)	{
		printf("                         _______\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
	}
	if(tenta == 3) {
		printf("                         _______\n" );
		printf("                        |       |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
	}
  if(tenta == 4)	{
		printf("                         _______\n" );
		printf("                        |       |\n" );
		printf("                        |       _\n" );
		printf("                        |      / \\\n" );
		printf("                        |      \\_/\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
	}
  if(tenta == 5)	{
		printf("                         _______\n" );
		printf("                        |       |\n" );
		printf("                        |       _\n" );
		printf("                        |      / \\\n" );
		printf("                        |      \\_/\n" );
		printf("                        |      _|_\n" );
		printf("                        |     /| |  \n" );
		printf("                        |    / |_|   \n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
	}
  if(tenta == 6)	{
	  	printf("                         _______\n" );
		printf("                        |       |\n" );
		printf("                        |       _\n" );
		printf("                        |      / \\\n" );
		printf("                        |      \\_/\n" );
		printf("                        |      _|_\n" );
		printf("                        |     /| |\\\n" );
		printf("                        |    / |_| \\\n" );
		printf("                        |\n" );
		printf("                        |\n" );
		printf("                        |\n" );
	}
  if(tenta == 7)	{
		printf("                         _______\n" );
		printf("                        |       |\n" );
		printf("                        |       _\n" );
		printf("                        |      / \\\n" );
		printf("                        |      \\_/\n" );
		printf("                        |      _|_\n" );
		printf("                        |     /| |\\\n" );
		printf("                        |    / |_| \\\n" );
		printf("                        |       ^\n" );
		printf("                        |      /   \n" );
		printf("                        |     /     \n" );
	} 
  if(tenta == 8)	{
		printf("                         _______\n" );
		printf("                        |       |\n" );
		printf("                        |       _\n" );
		printf("                        |      / \\\n" );
		printf("                        |      \\_/\n" );
		printf("                        |      _|_\n" );
		printf("                        |     /| |\\\n" );
		printf("                        |    / |_| \\\n" );
		printf("                        |       ^\n" );
		printf("                        |      / \\\n" );
		printf("                        |     /   \\\n" );
	}
}
int randMot()	{
/** Ouvre le fichier en mode lecture "r" rand si == indice mot le fou dans devine*/
	int y,x;
	int i = 0;
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = "";
    fichier = fopen("words.txt", "r");
    y = rand() %835;
    if (fichier != NULL)	{
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)	{
            if(i == y)	{
				//printf("i = %d\n",i);
				x = 0;
				while((chaine[x] != '\0')&&(chaine[x] != '\n'))	{
					devine[x] = chaine[x];
					x++;
				}
			}
            i++;
    }
    printf("Mot = %s\n",devine);
    fclose(fichier);
	}
}
int printTop()	{
/** Print la struct top ten 1 a 10*/
	int i = 0;
		while((ten[i].scoreTop > 0)&&(i < 10))	{
			printf("%s %d\n",ten[i].pseudoTop,ten[i].scoreTop);
			i++;
		}	
}		
int newScore()	{
/** Inscrit le score dans le fichier top.txt en mode ouverture "a" pour écrire a la fin du fichier*/
	FILE* fichier = NULL;
    fichier = fopen("top.txt", "a");
    if (fichier != NULL)	{
    fprintf(fichier,"%s=%d\n",pseudo,score);
    fclose(fichier);
	}
}
int initDevine()	{
/** test tout les caract du mot devine et si pas égale "/0" met un "/0"*/
	int i = 0;
	while(devine[i] != '\0')	{
		devineBon[i] = '\0';
		devine[i] = '\0';
		i++;
	}
}
int printCaractUse()	{
/** Affiche le tableau caract use */
	int i = 0;
	printf("Déja use =");
	while(i < j)	{
		printf(" %c,",caractUsed[i]);	
		i++;
	}
	printf("\n");
}
int classTop()	{
/** Ouvre le fichier top.txt en mode lecture "r" */
	nombreligne = 0;	//indice pour ballader dans struct
	int x;		//indice pour ballader dans chaine
	int y;		//indice pour ballader dans nombre
	int reste;
	char chaine[TAILLE_MAX] = "";
	char nombre[10];
    FILE* fichier = NULL;
    fichier = fopen("top.txt", "r");
    if (fichier != NULL)	{
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)	{			// Temps qu'il arrive a lire une ligne place la ligne dans chaine
			x = 0;
			reste = chaine[x];
			while(reste != '=')	{						// Place chaine dans reste temps qu'il est pas au signe "="
				ten[nombreligne].pseudoTop[x] = reste;		//Place reste dans ma structure
				x++;
				reste = chaine[x];
			}
			x++;					//Incrémente de 1 x pour skip "="
			reste = chaine[x];
			y = 0;
			while(reste != '\n')	{		//Fou le reste dans tableau nombre
				nombre[y] = reste;
				y++;
				x++;
				reste = chaine[x];
			}
			nombre[y] = '\0';		//Met un "/0" a la fin de nombre
			ten[nombreligne].scoreTop = atoi(nombre);		// convertis nombre en entier + place dans struct
			nombreligne++;
		}
    fclose(fichier);	
	}
}
int triTop()	{
/** Tri par selection de ma struct */
	int y;	//mémorise emplacement score le plus haut
	int q;	//Me ballader dans chaine
	int i;	//Me ballader dans struct 2
	int x = 0;	//indice pour me ballader dans ma struct
	int reste,car;
	char chaine[TAILLE_MAX];
	while(x < nombreligne-1)	{	//Temps que j'arrive pas a la dernière entrer dans mon tableau
		i = x;
		y = x;
		reste = ten[x].scoreTop;	//Reste prend en mémoire le score
		q = 0;
		car = ten[x].pseudoTop[q];
		while(car != '\0')	{		//Stock pseudo lié au score
			chaine[q] = car;
			q++;
			car = ten[x].pseudoTop[q];
		}
		chaine[q] = '\0';
		while(i < nombreligne)	{		
			if(reste < ten[i+1].scoreTop)	{	//compare emplacement 1 avec 2/ 2 avec 3/ ....
				reste = ten[i+1].scoreTop;			//Stock score dans reste si plus grand
				y = i+1;	//Mémorise emplacement du plus grand
				q = 0;
				car = ten[y].pseudoTop[q];
				while(car != '\0')	{	//Stock pseudo lié au score
					chaine[q] = car;
					q++;
					car = ten[y].pseudoTop[q];
				}
				chaine[q] = '\0';
			}
			i++;
		}
		q = 0;
		while(ten[x].pseudoTop[q] != '\0')	{		//Stock dans l'emplacement du plus grand l'emplacement actuel
			ten[y].pseudoTop[q] = ten[x].pseudoTop[q];
			q++;
			}
		ten[y].pseudoTop[q] = '\0';
		q = 0;
		while(chaine[q] != '\0')	{	//Remplace l'emplacement actuel par le plus grand stocker dans chaine et reste
			ten[x].pseudoTop[q] = chaine[q];
			q++;
			}
		ten[x].pseudoTop[q] = '\0';
		ten[y].scoreTop = ten[x].scoreTop;
		ten[x].scoreTop = reste;
		x++;
		}
}
