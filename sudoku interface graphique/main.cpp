//lien source  https://openclassrooms.com/courses/l-aleatoire-en-c-et-c-se-servir-de-rand-1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <time.h> //on inclu le fichier time.h qui contien la fonction time(time_t *v)
int tab0[4][4];int score=0,p,NbrJoueur,k;int case_interdite[4][4];
// k:represente le niveau et p: represente le sous niveau
SDL_Surface* ecran=NULL,*un=NULL,*deux=NULL,*trois=NULL,*num,*quatre=NULL,*lignes[2];
SDL_Event event;
void pause();
int hauteur=408,largeur=272,taillebloc=68;

void affiche_case(int x,int y,int val){
    SDL_Rect position;
    position.x=x;position.y=y;
    switch(val){
        case 0:
      num=SDL_LoadBMP("num.bmp");
      //SDL_SetColorKey(num, SDL_SRCCOLORKEY, SDL_MapRGB(num->format, 0, 0, 0));

      SDL_BlitSurface(num, NULL, ecran, &position);
        break;
    case 1:
      un=SDL_LoadBMP("un.bmp");
     // SDL_SetColorKey(un, SDL_SRCCOLORKEY, SDL_MapRGB(un->format, 0, 0, 0));

      SDL_BlitSurface(un, NULL, ecran, &position);
        break;
    case 2:
        deux= SDL_LoadBMP("deux.bmp");
     // SDL_SetColorKey(deux, SDL_SRCCOLORKEY, SDL_MapRGB(deux->format, 0, 0, 0));
      SDL_BlitSurface(deux, NULL, ecran, &position);
        break;
    case 3:
    trois= SDL_LoadBMP("trois.bmp");
     // SDL_SetColorKey(trois, SDL_SRCCOLORKEY, SDL_MapRGB(trois->format, 0, 0, 0));
      SDL_BlitSurface(trois, NULL, ecran, &position);
        break;
    case 4:
        quatre= SDL_LoadBMP("quatre.bmp");
       // SDL_SetColorKey(quatre, SDL_SRCCOLORKEY, SDL_MapRGB(trois->format, 0, 0, 0));
      SDL_BlitSurface(quatre, NULL, ecran, &position);
    break;
    }
    SDL_Rect position1;int i;
//les deux lignes pour sauvegarder et sortir
for (i = 1 ; i <= 2 ; i++)
lignes[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 272, 68, 32,
0, 0, 0, 0);

for (i = 1 ; i <=2  ; i++)
{
position1.x = 0; // Les lignes sont à gauche (abscisse de 0)
position1.y = 408-68*i; // La position verticale dépend du numérode la ligne
SDL_FillRect(lignes[i], NULL, SDL_MapRGB(ecran->format, 255-255*(i-1), 0, 250*(i-1)));
SDL_BlitSurface(lignes[i], NULL, ecran, &position1);
}

    return;
}
/*on reprend cette meme fonction avec des image differente pour pouvoir indiquer la
case selectionné*/
void case_select(int x,int y,int val){
    SDL_Rect position;
    position.x=x;position.y=y;
    switch(val){
        case 0:
      num=SDL_LoadBMP("nums.bmp");
      //SDL_SetColorKey(num, SDL_SRCCOLORKEY, SDL_MapRGB(num->format, 0, 0, 0));

      SDL_BlitSurface(num, NULL, ecran, &position);
        break;
    case 1:
      un=SDL_LoadBMP("uns.bmp");
      //SDL_SetColorKey(un, SDL_SRCCOLORKEY, SDL_MapRGB(un->format, 0, 0, 0));

      SDL_BlitSurface(un, NULL, ecran, &position);
        break;
    case 2:
        deux= SDL_LoadBMP("deuxs.bmp");
      //SDL_SetColorKey(deux, SDL_SRCCOLORKEY, SDL_MapRGB(deux->format, 0, 0, 0));
      SDL_BlitSurface(deux, NULL, ecran, &position);
        break;
    case 3:
    trois= SDL_LoadBMP("troiss.bmp");
      //SDL_SetColorKey(trois, SDL_SRCCOLORKEY, SDL_MapRGB(trois->format, 0, 0, 0));
      SDL_BlitSurface(trois, NULL, ecran, &position);
        break;
    case 4:
        quatre= SDL_LoadBMP("quatres.bmp");
        //SDL_SetColorKey(quatre, SDL_SRCCOLORKEY, SDL_MapRGB(trois->format, 0, 0, 0));
      SDL_BlitSurface(quatre, NULL, ecran, &position);
    break;
    }
    SDL_Rect position1;int i;
//les deux lignes pour sauvegarder et sortir
for (i = 1 ; i <= 2 ; i++)
lignes[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 272, 68, 32,
0, 0, 0, 0);

for (i = 1 ; i <=2  ; i++)
{
position1.x = 0; // Les lignes sont à gauche (abscisse de 0)
position1.y = 408-68*i; // La position verticale dépend du numérode la ligne
SDL_FillRect(lignes[i], NULL, SDL_MapRGB(ecran->format, 255-255*(i-1), 0, 255*(i-1)));
SDL_BlitSurface(lignes[i], NULL, ecran, &position1);
}

    return;
}


int x_i(int x){
return x/68;
}
int i_x(int i){
return i*68;
}



int testligne(int a,int tableau[4][4],int i){
int k, flag=1;
for(k=0;k<4;k++){
    if(tableau[i][k]==a) flag=0;
}
return flag;}



int testcolonne(int chiffre,int tableau[4][4],int j){
int k, flag=1;
for(k=0;k<4;k++){
    if(tableau[k][j]==chiffre) flag=0;
}
return flag;}
int testbloc(int chiffre, int i,int j,int tableau[4][4]){
    int _i=i-i%2,_j=j-j%2;
    for(i=_i;i<(_i+2);i++){
            for(j=_j;j<(_j+2);j++){
                if(tableau[i][j]==chiffre) return 0;}
    }

return 1;
}


int test(int chiffre,int tableau[4][4],int i,int j){
   //ici on va definir la grande fonction test qui appelle toutes les autres
  if(testligne(chiffre,tableau,i)&&testcolonne(chiffre,tableau,j)&&testbloc(chiffre,i,j,tableau))
     return 1;
return 0;
}





int rand_ab(int a,int b){

	int nombre_aleatoire = 0;

		nombre_aleatoire = rand()%(b-a)+a;
		//un entier entre a et b,avec a inclu b exclu

	return nombre_aleatoire;
}
void saisir(){

SDL_Rect positionN;
     /* Chargement e l'image d'acueille */
    SDL_Surface* imageDeFond = SDL_LoadBMP("niveau.bmp");

    positionN.x = 0;
    positionN.y = 0;


//NIVEAU
int contin=1;
while(contin){
         /* On blitte par-dessus l'écran */
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionN);
    SDL_Flip(ecran);
    //pause();
        SDL_WaitEvent(&event);
        if(event.type==SDL_MOUSEBUTTONDOWN) {
  if(event.button.y/136==0){k=1;contin=0;}
  if(event.button.y/136==1){k=2;contin=0;}
  if(event.button.y/136==2){k=3;contin=0;}

}
else if(event.type==SDL_QUIT) contin=0;


}
imageDeFond = SDL_LoadBMP("sousniveau.bmp");

    positionN.x = 0;
    positionN.y = 0;


//SOUSNIVEAU
contin=1;
while(contin){
    /* On blitte par-dessus l'écran */
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionN);
    SDL_Flip(ecran);
    //pause();
        SDL_WaitEvent(&event);
        if(event.type==SDL_MOUSEBUTTONDOWN) {
  switch(event.button.y/136){
     case 0: p=1;contin=0;break;
     case 1: p=2;contin=0;
       break;
     case 2 : p=3;contin=0; break;
  }}
 else if(event.type==SDL_QUIT) contin=0;
}

return;
}
typedef struct joueur{
int score;
int niveau;
int sousNiveau;
}joueur;
joueur* T_joueur;

void sauvegarder(){
int contin3;SDL_Rect positionFond1;
FILE *flot;
//flot = fopen("Sudoku.txt","rb");

    //fclose(flot);
    T_joueur=(joueur*)malloc(sizeof(joueur));
    if(T_joueur!=NULL){
    T_joueur->score=score;
    T_joueur->sousNiveau=p;
    T_joueur->niveau=k;
    flot=fopen("Sudoku.txt","wb");
    fwrite(T_joueur,sizeof(joueur),1,flot);
    fclose(flot);
    free(T_joueur);
/* Chargement e l'image d'acueille */
    SDL_Surface* imageDeFond = SDL_LoadBMP("message3.bmp");

    positionFond1.x = 0;
    positionFond1.y = 0;

    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond1);
    SDL_Flip(ecran);
    contin3=1;
    while (contin3)
    {
        SDL_WaitEvent(&event);
        if(event.key.keysym.sym==SDLK_1){contin3=0;}
        SDL_Flip(ecran);
        }
        SDL_QUIT:


    return;}


/*T_joueur=(joueur*)malloc(sizeof(joueur));

if(T_joueur!=NULL){
  fread(T_joueur,sizeof(joueur),1,flot);
  fclose(flot);
  T_joueur[0].score=score;
  T_joueur[0].sousNiveau=p;
  T_joueur[0].niveau=k;


 flot=fopen("sudoku.txt","wb");

 fwrite(T_joueur,sizeof(joueur),1,flot);
 fclose(flot);
 free(T_joueur);

 return;}*/
else {
        SDL_Rect positionFond2;
/* Chargement e l'image d'acueille */
    SDL_Surface* imageDeFond = SDL_LoadBMP("message1.bmp");

    positionFond2.x = 0;
    positionFond2.y = 0;

    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond2);
    SDL_Flip(ecran);return;
    SDL_QUIT;}

return;
}
void charger(){
SDL_Rect positionFond1;int contin0;
FILE *flot = fopen("Sudoku.txt","rb");
if(flot!=NULL){
T_joueur=(joueur*)malloc(sizeof(joueur));
if(T_joueur!=NULL){
fread(T_joueur,sizeof(joueur),1,flot);
fclose(flot);

    score=T_joueur[0].score;
    p=T_joueur[0].sousNiveau;
    k=T_joueur[0].niveau;

}
else {
        contin0=1;
    while(contin0){
     /* Chargement e l'image d'acueille */
    SDL_Surface* imageDeFond = SDL_LoadBMP("message1.bmp");

    positionFond1.x = 0;
    positionFond1.y = 0;

    /* On blitte par-dessus l'écran */
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond1);
    SDL_Flip(ecran);
    SDL_WaitEvent(&event);
    if(event.type==SDL_QUIT) contin0=0;
    }}
}
else {
        contin0=1;
    while (contin0)
    {
     /* Chargement e l'image d'acueille */
    SDL_Surface* imageDeFond = SDL_LoadBMP("message2.bmp");

    positionFond1.x = 0;
    positionFond1.y = 0;

    /* On blitte par-dessus l'écran */
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond1);
    SDL_Flip(ecran);

        SDL_WaitEvent(&event);
        if(event.key.keysym.sym==SDLK_1){saisir();contin0=0;}}
}
free(T_joueur);
return;

}




void sortir(){
FILE *fp=fopen("scoreSudoku.txt","rb");
if(fp==NULL){
    fp=fopen("scoreSudoku.txt","wb");
    int T_score[10]={score,0,0,0,0,0,0,0,0,0};

    fwrite(T_score,sizeof(int),10,fp);
    fclose(fp);}
else{
    int T_score[10], a=8,placer=0;
    fread(T_score,sizeof(int),10,fp);
    fclose(fp);
    if(T_score[9]<score){
      while(a>=0&& !placer){
        if(T_score[a]<score){
            T_score[a+1]=T_score[a];
            a--;
            }
        else placer=1;
      }
      T_score[a+1]=score;
    }
    fp=fopen("scoreSudoku.txt","wb");
    fwrite(T_score,sizeof(int),10,fp);
    fclose(fp);
    }

    SDL_QUIT;
    return;
}

void afficher_score(){
    FILE *fp=fopen("scoreSudoku.txt","rb");

    if(fp!=NULL){
        int T_score[10],m;
    fread(T_score,sizeof(int),10,fp);
    for(m=0;m<10;m++){
        printf("le score du %deme est: %d\n",m+1,T_score[m]);
    }
    fclose(fp);
    k=4;//pour juste afficher les scores sans commencer le jeu
    }
    else printf("aucun score n'est eencore enregistre\n");
    return;
    }

typedef struct s_tab{
    int tab[4][4];
}s_tab;
s_tab ini_tab(int n){

s_tab tableau;
int i,j,k,p ;
int T0[16]={1,2,3,4,3,4,1,2,2,3,4,1,4,1,2,3};
p=0;
for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      tableau.tab[i][j]=T0[p];
      p++;
    }
}
for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      case_interdite[i][j]=1;
    }
}
 k=0;
while(k<n){
        i=rand_ab(0,4);
        j=rand_ab(0,4);
    if(tableau.tab[i][j]!=0){
    tableau.tab[i][j]=0;
    case_interdite[i][j]=0;
    k++;
    }
}
return tableau;
}



int inserer(int i,int j,int tab1[4][4],int chiffre){
    int k;
if(test(chiffre,tab1,i,j)==1){
   tab1[i][j]=chiffre;
   k=1;
   }
   else{
    printf("mauvais choix");
    k=0;
    }
return k;

}




void afficher(int tableau[4][4]){
    //fonction affichant le tableau
int i,j;
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
//printf("le tableau est:\n");
for(i=0;i<4;i++){
    for(j=0;j<4;j++){
        affiche_case(i_x(j),i_x(i),tableau[i][j]);

    }
    //printf("\n");
}
return;
}
void commencer(int k){
int i,j; s_tab T;
if(k==1)
        T=ini_tab(6);
else if(k==2) T=ini_tab(9);
    else T=ini_tab(11);

for(i=0;i<4;i++)
{
for( j=0;j<4;j++)
    {
tab0[i][j]=T.tab[i][j];
    }

}

return ;
}



void Sudoku(){
int n_c,n_e,s_g,i,j,d,chiffre,h,nbr_reussi,S_sousNiveau,x,nbr_echec,flag0,boucler;

SDL_Rect positionFond;
     /* Chargement e l'image d'acueille */
    SDL_Surface* imageDeFond = SDL_LoadBMP("menu.bmp");

    positionFond.x = 0;
    positionFond.y = 0;



/*do{printf("taper 0 pour comencer une nouvelle partie\n taper 1 pour charger un jeu enregistrer\n taper 2 pour afficher les 10 meilleurs scores :");
scanf("%d",&choix);}while(choix!=0&&choix!=1&&choix!=2);*/
int continuer=1,v;
while(continuer){
        SDL_WaitEvent(&event);
     if(event.type==SDL_MOUSEBUTTONUP)   {v=event.button.y/136;
          switch(v){
            case 0: saisir();continuer=0;break;
            case 1: charger();continuer=0;
            break;
     //case 2 : afficher_score();continuer=0;Sudoku();;continuer=0 break;
          } }
      else if (event.type==SDL_QUIT){continuer=0;break;}
/* On blitte par-dessus l'écran */
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    //pause();
}

while(k<4){
    //if(p==1){printf("\n debut du niveau %d\n",k);}
if(k==1) n_c=6;
if(k==2) n_c=9;
if(k==3) n_c=11;
while(p<4){
        commencer(k);afficher(tab0);
        if(p==1){ n_e=18; s_g=3;}
        if(p==2){n_e=12; s_g=5;}
        if(p==3){n_e=6;s_g=11;}
    nbr_echec=nbr_reussi=0; S_sousNiveau=0;boucler=1;flag0=0;
    while(nbr_echec<n_e&&nbr_reussi<n_c&&boucler){
        //printf("choisir une case non pre-remplie \n");

          continuer=1;
        while(continuer){
            do{
                    continuer=1;
           while(continuer){ SDL_WaitEvent(&event);


        if(event.type==SDL_MOUSEBUTTONDOWN) {
        i=event.button.y/68;
        j=event.button.x/68;
        d=event.button.y/68;continuer=0;
        if(d==4 ) {sauvegarder();sortir();boucler=0;flag0=0;p=4;k=4;}
        else if(d==5){sortir();boucler=0;flag0=0;p=4;}}
        else if(event.type==SDL_QUIT) continuer=0;
            SDL_Flip(ecran);}

        }while(case_interdite[i][j]!=0&&boucler);
            //afficher(tab0);

        if(i<4) case_select(i_x(j),i_x(i),tab0[i][j]);
           //cette fonction est comme afficher_case(...);l'unique difference sera les images


    continuer=1;
        while(continuer){
        SDL_WaitEvent(&event);
    if(event.type==SDL_KEYDOWN) {
        if(event.key.keysym.sym==SDLK_1){ chiffre=1;continuer=0;}
        else if(event.key.keysym.sym==SDLK_2) {chiffre=2;continuer=0;}
        else if(event.key.keysym.sym==SDLK_3) {chiffre=3;continuer=0;}
        else if(event.key.keysym.sym==SDLK_4) {chiffre=4;continuer=0;}

        }
        else if(event.type==SDL_QUIT) continuer=0;
        else if(event.type==SDL_MOUSEBUTTONUP){
            d=event.button.y/68;
        if(d==4) {sauvegarder();sortir();boucler=0;flag0=0;p=4;k=4;continuer=0;}
        else if(d==5){sortir();boucler=0;flag0=0;p=4;continuer=0;}


        }
           //SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
            SDL_Flip(ecran);//mise a jour u tableau
        }
        if(tab0[i][j]==0) h=1;
        if(inserer(i,j,tab0,chiffre)&&h){score+=s_g;S_sousNiveau+=s_g; nbr_reussi++;}
        else if(!inserer(i,j,tab0,chiffre)) nbr_echec++;
        afficher(tab0);
        SDL_Flip(ecran);

    }
        /*printf("taper 0 pour continuer \n 1 pour recomencer\n 2 pour sauvegarder et sortir \n 3 pour sortir sans sauvegarder\n ");
        scanf("%d",&choix);
        switch(choix)
        { case 0:break;
           case 1:
            score-=S_sousNiveau;flag0=1;boucler=0;break;
            case 2: sauvegarder();sortir();boucler=0;flag0=0;p=4;k=4;break;
            case 3: sortir();boucler=0;flag0=0;p=4;break;
        }*/


if(nbr_reussi==n_c){
         continuer=1;
    while(continuer){
   SDL_Surface* imageDeFond = SDL_LoadBMP("message0.bmp");
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    SDL_WaitEvent(&event);
    if(event.type==SDL_KEYDOWN){
    if(event.key.keysym.sym==SDLK_1) continuer=0;}
    }
    //printf("!!!felicitation\n le sous niveau %d du niveau %d est reussi \n",p,k);
    p=p+1;flag0=1;
    //if(p<4) printf("\ndebut du sous niveau %d\n",p);*/
    }
else if(nbr_echec==n_e){
    /*printf("tapez 1 si vous voulez sauvegarder 0 si non ");
    scanf("%d",&x);*/
    /* Chargement e l'image d'acueille */
    SDL_Surface* imageDeFond = SDL_LoadBMP("echec.bmp");
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

    positionFond.x = 0;
    positionFond.y = 0;

    /* On blitte par-dessus l'écran */

    continuer=1;x=0;
    while(continuer){
        SDL_WaitEvent(&event);
        if(event.type==SDL_KEYDOWN) {
        if(event.key.keysym.sym==SDLK_1) {x=1;continuer=0;}
        if(event.key.keysym.sym==SDLK_2) {x=2;continuer=0;}}
        else if(event.type==SDL_QUIT) continuer=0;


    if(x==1){sauvegarder();sortir();p=4;k=4;}
    else {sortir();p=4;k=4;}
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);//mise a jour u tableau
    }
    continuer=1;
    while(continuer){
   SDL_Surface* imageDeFond = SDL_LoadBMP("fin.bmp");
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    SDL_WaitEvent(&event);
    if(event.type==SDL_QUIT) continuer=0;
    }
    }
    //SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
           SDL_Flip(ecran);

if(p==4&&flag0!=0){
    k++;p=1;
    }
}}
if(k<4){
continuer=1;
    while(continuer){
   SDL_Surface* imageDeFond = SDL_LoadBMP("messageN.bmp");
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    SDL_WaitEvent(&event);
    if(event.type==SDL_KEYDOWN){
    if(event.key.keysym.sym==SDLK_1) continuer=0;}
    }}
return;
}}

int main(int argc, char *argv[])
{ srand(time(NULL));
SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(272, 408, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); /* Double Buffering */
    if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("SUDOKU POUR ENFANT", NULL);

Sudoku();
//SDL_Surface* imageDeFond = SDL_LoadBMP("fin.bmp");


SDL_FreeSurface(un);
SDL_FreeSurface(num);
SDL_FreeSurface(deux);
SDL_FreeSurface(trois);
SDL_FreeSurface(quatre);
    SDL_Quit();
printf("\nHello world!\n");
return 0;}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
