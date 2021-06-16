#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include "xadrez.h"


//=======================================================================================
//main principal
int main() {
  char tab[8][8];
  int inix, iniy, finx, finy, sair = 0, aux;

  setlocale(LC_ALL,"Portuguese");
  inicializaTabuleiro(tab);
  do {
    aux = menu();
    if (aux == 1) {                //peças brancas
      exibeTabuleiro(tab);
      printf("\n JOGADOR >> 1 <<");
      printf("\n QUAL PEÇA QUER MEXER: ");
      printf("\n QUAL A LINHA INICIAL(ONDE A PEÇA ESTÁ): ");
      scanf("%d", &inix);
      printf("\n QUAL A COLUNA INICIAL(ONDE A PEÇA ESTÁ): ");
      scanf("%d", &iniy);
      printf("\n QUAL A LINHA FINAL: ");
      scanf("%d", &finx);
      printf("\n QUAL A COLUNA FINAL: ");
      scanf("%d", &finy);
      system("cls");
      mover(inix, iniy ,finx, finy, tab);
    } else
        if (aux == 2) {                         //peças pretas
          exibeTabuleiro(tab);
          printf("\n JOGADOR >> 2 <<");
          printf("\n QUAL PEÇA QUER MEXER: ");
          printf("\n QUAL A LINHA INICIAL(ONDE A PEÇA ESTÁ): ");
          scanf("%d", &inix);
          printf("\n QUAL A COLUNA INICIAL(ONDE A PEÇA ESTÁ): ");
          scanf("%d", &iniy);
          printf("\n QUAL A LINHA FINAL(ONDE A PEÇA VAI FICAR): ");
          scanf("%d", &finx);
          printf("\n QUAL A COLUNA FINAL(ONDE A PEÇA VAI FICAR): ");
          scanf("%d", &finy);
          system("cls");
          mover(inix, iniy, finx, finy, tab);

        } else
            if (aux == 3) {                  //acabar o jogo
              printf("\t ===================================\n");
              printf("\t |    OBRIGADO POR JOGAR !!!! =)   |\n");
              printf("\t ===================================");
              printf("\n\n\n");
              sair = 1;
            }

  }while(sair == 0);



  printf("\n\n\n\n");
  return 0;
}
//=======================================================================================

int mover(int x, int y,int i, int j,char tab[8][8]) {
  int l = x, c = y;                                       // l= linha e c= coluna

switch (tab[l][c]) {

    case 'p' :  printf("PEÃO BRANCO\n");
                peao(x, y, i, j, tab);
                exibeTabuleiro(tab);
                printf("\n");
                break;
    case 't' :  printf("TORRE BRANCA\n");
                torre(x, y, i, j, tab);
                exibeTabuleiro(tab);
                printf("\n");
                break;
    case 'c' :  printf("CAVALO BRANCO\n");
                cavalo(x, y, i, j, tab);
                exibeTabuleiro(tab);
                printf("\n");
                break;
    case 'b' :  printf("BISPO BRANCO\n");
                bispo(x, y, i, j, tab);
                exibeTabuleiro(tab);
                printf("\n");
                break;
    case 'd' :  printf("DAMA BRANCA\n");
                dama(x, y, i, j, tab);
                exibeTabuleiro(tab);
                printf("\n");
                break;
    case 'r' :  printf("REI BRANCO\n");
                rei(x, y, i, j, tab);
                exibeTabuleiro(tab);
                printf("\n");
                break;
    case 'P' :  printf("PEÃO PRETO\n");
                peaoPreto(x, y, i, j, tab);
                exibeTabuleiro(tab);
                printf("\n");
                break;
    case 'T' :  printf("TORRE PRETA\n");
                torrePreta(x, y, i, j, tab);
                exibeTabuleiro(tab);
                printf("\n");
                break;
    case 'C' :  printf("CAVALO PRETO\n");
                cavaloPreto(x, y, i, j, tab);
                exibeTabuleiro(tab);
                printf("\n");
                break;
    case 'B' :  printf("BISPO PRETO\n");
                bispoPreto(x, y, i, j, tab);
                exibeTabuleiro(tab);
                printf("\n");
                break;
    case 'D' :  printf("DAMA PRETA\n");
                damaPreta(x, y, i, j, tab);
                exibeTabuleiro(tab);
                printf("\n");
                break;
    case 'R' :  printf("REI PRETO\n");
                reiPreto(x, y, i, j, tab);
                exibeTabuleiro(tab);
                printf("\n");
                break;
  }
}

//menu principal
int menu () {
  int opc;                    //OPÇÃO DO MENU
  printf("\n\n");
	printf ("============ MENU =========");
	printf ("\n\t1 - MOVER AS PEÇAS BRANCAS"); //JOGADOR 1
	printf ("\n\t2 - MOVER AS PEÇAS PRETAS");   // JOGADOR 2
	printf ("\n\t3 - ACABAR O JOGO");
	printf ("\n\n");

	scanf("%d", &opc);

  system("cls");

	return opc;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
void exibeTabuleiro(char tab[8][8]){
		int i,j;
	printf("     0   1   2   3   4   5   6   7  \n");
	for(i = 0 ;i <= 7 ; i++){
		printf("  %d|",i);// inicia a barra da coluna
		for( j = 0; j <= 7; j++){
			printf(" %c |",tab[i][j]);// exibe na tela as peças presentes na posição
		}
		if(i<7)
		  printf("\n"); //pula a linha
		}
//----------------------------------------------------------


}
//=========================================================================================
void inicializaTabuleiro(char tab[8][8]){
	int i,j;

  for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			if(i>1 && i<6)// povoamento dos campos vazios (Que estarão entre os peões pretos e brancos por isto entre 1 e 6)
			 tab[i][j]=' ';

//brancas
	tab[1][0] = 'p';      // p = PEÕES BRANCOS
	tab[1][1] = 'p';      // t =  TORRES BRANCAS
	tab[1][2] = 'p';      // c = CAVALOS BRANCOS
	tab[1][3] = 'p';      // b = BISPOS BRANCOS
	tab[1][4] = 'p';      // d =  DAMA OU RAINHA BRANCA    
    tab[1][5] = 'p';      // r = REI BRANCO
	tab[1][6] = 'p';
	tab[1][7] = 'p';
    tab[0][0] = 't';
    tab[0][1] = 'c';
    tab[0][2] = 'b';
    tab[0][3] = 'd';
    tab[0][4] = 'r';
    tab[0][5] = 'b';
    tab[0][6] = 'c';
    tab[0][7] = 't';
  //pretas
  tab[6][0] = 'P';               // P = PEÕES PRETOS
  tab[6][1] = 'P';               // T = TORRES PRETAS 
  tab[6][2] = 'P';                // C = CAVALOS PRETOS
  tab[6][3] = 'P';                 // B = BBISPOS PRETOS
  tab[6][4] = 'P';                 // D = DAMA OU RAINHA PRETA
  tab[6][5] = 'P';                  // R = REI PRETO     
  tab[6][6] = 'P';
  tab[6][7] = 'P';
  tab[7][0] = 'T';
  tab[7][1] = 'C';
  tab[7][2] = 'B';
  tab[7][3] = 'D';
  tab[7][4] = 'R';
  tab[7][5] = 'B';
  tab[7][6] = 'C';
  tab[7][7] = 'T';

}
//===================PEÇAS BRANCAS=============================================================

// x = linha inicial
// y = coluna inicial
// i = linha final
// j = coluna final

//PEAO BRANCO
int peao(int x,int y,int i,int j, char tab[8][8]) {
	int l, c;     //l = LINHA c = COLUNA
  if ( (x < 0) || (x > 7) || (y < 0) || (y > 7) ) {//verifica se linha e coluna são válidos
    return printf("POSIÇÂO NÃO VÁLIDA !!!!!\n\n");
  }
	for (l = x+1 ,c = j ; l <= i; l++) { //verifica se a posição esta livre
	  if(tab[l][c] != ' ') {                 // diferente de vazio
	    return printf("POSIÇÂO JÁ ESTÁ OCULPADA !!!\n\n");
	  }
	}
  //move a peça
	tab[i][j] = 'p';
	tab[x][y] = ' ';
}

//================================================================================
//TORRE
int torre(int x,int y,int i,int j, char tab[8][8]) {
  int l, c;

  if ( (x < 0) || (x > 7) || (y < 0) || (y > 7) ) {//verifica se linha e coluna são validos
    return printf("POSIÇÂO NÃO VALIDA !!!!!\n\n");
  }

  if ( x == i ) {
    if (y < j) {
     for ( l = x, c = y+1; c <= j; c++ ){
       if ( tab[l][c] != ' ') {
         return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
       }
     }
    }else
       if (y > j) {
         for ( l = x, c = y-1; c >= j; c-- ){
           if ( tab[l][c] != ' ') {
             return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
           }
         }
       }

  tab[i][j] = 't';
  tab[x][y] = ' ';
  } else
      if ( y == j ) {
        if ( x < i) {
          for ( l = x+1, c = y; l <= i; l++ ) {
            if ( tab[l][c] != ' ') {
              exibeTabuleiro(tab);
              return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
            }
          }
      } else
          if ( x > i ) {
            for ( l = x, c = y+1; c <= j; c++ ){
              if ( tab[l][c] != ' ') {
                exibeTabuleiro(tab);
                return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
              }
            }
          }
      tab[i][j] = 't';
      tab[x][y] = ' ';
     }
}

//===============================================================================
//CAVALO

int cavalo(int x,int y,int i,int j, char tab[8][8]) {
  int posin, posfi;

  posin = x + y;
  posfi = i + j;

  if ( (x < 0) || (x > 7) || (y < 0) || (y > 7) ) {//verifica se linha e coluna são validos
    return printf("POSIÇÂO NÃO VALIDA !!!!!\n\n");
  }

  if ((posin % 2 == 0) && (posfi % 2 != 0)) {
    if (tab[i][j] != ' ')
      printf("POSIÇÃO INVALIDA\n ");
    else
      tab[i][j] = 'c';
      tab[x][y] = ' ';
  }else
     if ((posin % 2 != 0 ) && (posfi % 2 == 0 )){
       if (tab[i][j] != ' ')
         printf("POSIÇÃO INVALIDA\n ");
       else
         tab[i][j] = 'c';
         tab[x][y] = ' ';
    }
}

//================================================================================
//BISPO

int bispo(int x,int y,int i,int j, char tab[8][8]) {
  int l, c;

  if ( (x < 0) || (x > 7) || (y < 0) || (y > 7) ) {//verifica se linha e coluna são validos
    return printf("POSIÇÂO NÃO VALIDA !!!!!\n\n");
  }

  if ((x < i) && (y > j)) {
    for (l = x+1, c = y-1; c >= j; l++, c--)
      if (tab[l][c] != ' ')
        return printf("NÃO DA PARA MOVER!!\n");

    tab[i][j] = 'b';
    tab[x][y] = ' ';
  }else
     if ((x < i) && (y < j)) {
        for (l = x+1, c = y+1; c <= j; l++, c++)
          if (tab[l][c] != ' ')
           return printf("NÃO DA PARA MOVER!!\n");

      tab[i][j] = 'b';
      tab[x][y] = ' ';
     }else
        if ((x > i) && (y > j)) {
          for (l = x-1, c = y-1; c >= j; l--, c--)
            if (tab[l][c] != ' ')
              return printf("NÃO DA PARA MOVER!!\n");

        tab[i][j] = 'b';
        tab[x][y] = ' ';
       }else
        if ((x > i) && (y < j)) {
          for (l = x-1, c = y+1; c <= j; l--, c++)
            if (tab[l][c] != ' ')
              return printf("NÃO DA PARA MOVER!!\n");

        tab[i][j] = 'b';
        tab[x][y] = ' ';
        }
}
//=====================================================================================
//DAMA
int dama(int x,int y,int i,int j, char tab[8][8]) {
  int l, c;

  if ( (x < 0) || (x > 7) || (y < 0) || (y > 7) ) {//verifica se linha e coluna são validos
    return printf("POSIÇÂO NÃO VALIDA !!!!!\n\n");
  }

  if ( x == i ) {
    if (y < j) {
     for ( l = x, c = y+1; c <= j; c++ ){
       if ( tab[l][c] != ' ') {
         return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
       }
     }
    }else
       if (y > j) {
         for ( l = x, c = y-1; c >= j; c-- ){
           if ( tab[l][c] != ' ') {
             return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
           }
         }
       }

  tab[i][j] = 'd';
  tab[x][y] = ' ';
  } else
      if ( y == j ) {
        if ( x < i) {
          for ( l = x+1, c = y; l <= i; l++ ) {
            if ( tab[l][c] != ' ') {
              exibeTabuleiro(tab);
              return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
            }
          }
      } else
          if ( x > i ) {
            for ( l = x, c = y+1; c <= j; c++ ){
              if ( tab[l][c] != ' ') {
                exibeTabuleiro(tab);
                return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
              }
            }
          }
      tab[i][j] = 'd';
      tab[x][y] = ' ';
     }else
        if ((x < i) && (y > j)) {
          for (l = x+1, c = y-1; c >= j; l++, c--)
            if (tab[l][c] != ' ')
              return printf("NÃO DA PARA MOVER!!\n");

          tab[i][j] = 'd';
          tab[x][y] = ' ';
        }else
           if ((x < i) && (y < j)) {
              for (l = x+1, c = y+1; c <= j; l++, c++)
                if (tab[l][c] != ' ')
                 return printf("NÃO DA PARA MOVER!!\n");

            tab[i][j] = 'd';
            tab[x][y] = ' ';
           }else
              if ((x > i) && (y > j)) {
                for (l = x-1, c = y-1; c >= j; l--, c--)
                  if (tab[l][c] != ' ')
                    return printf("NÃO DA PARA MOVER!!\n");

              tab[i][j] = 'd';
              tab[x][y] = ' ';
             }else
              if ((x > i) && (y < j)) {
                for (l = x-1, c = y+1; c <= j; l--, c++)
                  if (tab[l][c] != ' ')
                    return printf("NÃO DA PARA MOVER!!\n");

              tab[i][j] = 'd';
              tab[x][y] = ' ';
              }
}
//=============================================================================
//REI
int rei(int x,int y,int i,int j, char tab[8][8]) {
  int l, c;

  if ( (x < 0) || (x > 7) || (y < 0) || (y > 7) ) {//verifica se linha e coluna são validos
    return printf("POSIÇÂO NÃO VALIDA !!!!!\n\n");
  }

  if ( x == i ) {
    if (y < j) {
     for ( l = x, c = y+1; c <= j; c++ ){
       if ( tab[l][c] != ' ') {
         return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
       }
     }
    }else
       if (y > j) {
         for ( l = x, c = y-1; c >= j; c-- ){
           if ( tab[l][c] != ' ') {
             return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
           }
         }
       }

  tab[i][j] = 'r';
  tab[x][y] = ' ';
  } else
      if ( y == j ) {
        if ( x < i) {
          for ( l = x+1, c = y; l <= i; l++ ) {
            if ( tab[l][c] != ' ') {
              exibeTabuleiro(tab);
              return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
            }
          }
      } else
          if ( x > i ) {
            for ( l = x, c = y+1; c <= j; c++ ){
              if ( tab[l][c] != ' ') {
                exibeTabuleiro(tab);
                return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
              }
            }
          }
      tab[i][j] = 'r';
      tab[x][y] = ' ';
     }else
        if ((x < i) && (y > j)) {
          for (l = x+1, c = y-1; c >= j; l++, c--)
            if (tab[l][c] != ' ')
              return printf("NÃO DA PARA MOVER!!\n");

          tab[i][j] = 'r';
          tab[x][y] = ' ';
        }else
           if ((x < i) && (y < j)) {
              for (l = x+1, c = y+1; c <= j; l++, c++)
                if (tab[l][c] != ' ')
                 return printf("NÃO DA PARA MOVER!!\n");

            tab[i][j] = 'r';
            tab[x][y] = ' ';
           }else
              if ((x > i) && (y > j)) {
                for (l = x-1, c = y-1; c >= j; l--, c--)
                  if (tab[l][c] != ' ')
                    return printf("NÃO DA PARA MOVER!!\n");

              tab[i][j] = 'r';
              tab[x][y] = ' ';
             }else
              if ((x > i) && (y < j)) {
                for (l = x-1, c = y+1; c <= j; l--, c++)
                  if (tab[l][c] != ' ')
                    return printf("NÃO DA PARA MOVER!!\n");

              tab[i][j] = 'r';
              tab[x][y] = ' ';
              }
              
}
//===========================================================================
//PEAO PRETO
int peaoPreto(int x,int y,int i,int j, char tab[8][8]) {
	int l, c;
  if ( (x < 0) || (x > 7) || (y < 0) || (y > 7) ) {//verifica se linha e coluna são validos
    return printf("POSIÇÂO NÃO VALIDA !!!!!\n\n");
  }
	for (l = x-1 ,c = j ; l >= i; l--) { //verifica se a posição esta livre
	  if(tab[l][c] != ' ') {
	    return printf("POSIÇÂO JÁ ESTÁ OCULPADA !!!\n\n");
	  }
	}
  //move a peça
	tab[i][j] = 'P';
	tab[x][y] = ' ';
}
//==================================================================================
//TORRE PRETA

int torrePreta(int x,int y,int i,int j, char tab[8][8]) {
int l, c;

  if ( (x < 0) || (x > 7) || (y < 0) || (y > 7) ) {//verifica se linha e coluna são validos
    return printf("POSIÇÂO NÃO VALIDA !!!!!\n\n");
  }

  if ( x == i ) {
    if (y < j) {
     for ( l = x, c = y+1; c <= j; c++ ){
       if ( tab[l][c] != ' ') {
         return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
       }
     }
    }else
       if (y > j) {
         for ( l = x, c = y-1; c >= j; c-- ){
           if ( tab[l][c] != ' ') {
             return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
           }
         }
       }

  tab[i][j] = 'T';
  tab[x][y] = ' ';
  } else
      if ( y == j ) {
        if ( x < i) {
          for ( l = x+1, c = y; l <= i; l++ ) {
            if ( tab[l][c] != ' ') {
              exibeTabuleiro(tab);
              return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
            }
          }
      } else
          if ( x > i ) {
            for ( l = x, c = y+1; c <= j; c++ ){
              if ( tab[l][c] != ' ') {
                exibeTabuleiro(tab);
                return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
              }
            }
          }
      tab[i][j] = 'T';
      tab[x][y] = ' ';
     }
}
//=============================================================================
//CAVALO PRETO

int cavaloPreto(int x,int y,int i,int j, char tab[8][8]) {
  int posin, posfi;

  posin = x + y;
  posfi = i + j;

  if ( (x < 0) || (x > 7) || (y < 0) || (y > 7) ) {//verifica se linha e coluna são validos
    return printf("POSIÇÂO NÃO VALIDA !!!!!\n\n");
  }

  if ((posin % 2 == 0) && (posfi % 2 != 0)) {
    if (tab[i][j] != ' ')
      printf("POSIÇÃO INVALIDA\n ");
    else
      tab[i][j] = 'C';
      tab[x][y] = ' ';
  }else
     if ((posin % 2 != 0 ) && (posfi % 2 == 0 )){
       if (tab[i][j] != ' ')
         printf("POSIÇÃO INVALIDA\n ");
       else
         tab[i][j] = 'C';
         tab[x][y] = ' ';
    }
}
//===============================================================================
//BISPO PRETO
int bispoPreto(int x,int y,int i,int j, char tab[8][8]) {
  int l, c;

  if ( (x < 0) || (x > 7) || (y < 0) || (y > 7) ) {//verifica se linha e coluna são validos
    return printf("POSIÇÂO NÃO VALIDA !!!!!\n\n");
  }

  if ((x < i) && (y > j)) {
    for (l = x+1, c = y-1; c >= j; l++, c--)
      if (tab[l][c] != ' ')
        return printf("NÃO DA PARA MOVER!!\n");

    tab[i][j] = 'B';
    tab[x][y] = ' ';
  }else
     if ((x < i) && (y < j)) {
        for (l = x+1, c = y+1; c <= j; l++, c++)
          if (tab[l][c] != ' ')
           return printf("NÃO DA PARA MOVER!!\n");

      tab[i][j] = 'B';
      tab[x][y] = ' ';
     }else
        if ((x > i) && (y > j)) {
          for (l = x-1, c = y-1; c >= j; l--, c--)
            if (tab[l][c] != ' ')
              return printf("NÃO DA PARA MOVER!!\n");

        tab[i][j] = 'B';
        tab[x][y] = ' ';
       }else
        if ((x > i) && (y < j)) {
          for (l = x-1, c = y+1; c <= j; l--, c++)
            if (tab[l][c] != ' ')
              return printf("NÃO DA PARA MOVER!!\n");

        tab[i][j] = 'B';
        tab[x][y] = ' ';
        }
}
//======================================================================================
//DAMA PRETA
int damaPreta(int x,int y,int i,int j, char tab[8][8]) {
  int l, c;

  if ( (x < 0) || (x > 7) || (y < 0) || (y > 7) ) {//verifica se linha e coluna são validos
    return printf("POSIÇÂO NÃO VALIDA !!!!!\n\n");
  }

  if ( x == i ) {
    if (y < j) {
     for ( l = x, c = y+1; c <= j; c++ ){
       if ( tab[l][c] != ' ') {
         return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
       }
     }
    }else
       if (y > j) {
         for ( l = x, c = y-1; c >= j; c-- ){
           if ( tab[l][c] != ' ') {
             return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
           }
         }
       }

  tab[i][j] = 'D';
  tab[x][y] = ' ';
  } else
      if ( y == j ) {
        if ( x < i) {
          for ( l = x+1, c = y; l <= i; l++ ) {
            if ( tab[l][c] != ' ') {
              exibeTabuleiro(tab);
              return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
            }
          }
      } else
          if ( x > i ) {
            for ( l = x, c = y+1; c <= j; c++ ){
              if ( tab[l][c] != ' ') {
                exibeTabuleiro(tab);
                return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
              }
            }
          }
      tab[i][j] = 'D';
      tab[x][y] = ' ';
     }else
        if ((x < i) && (y > j)) {
          for (l = x+1, c = y-1; c >= j; l++, c--)
            if (tab[l][c] != ' ')
              return printf("NÃO DA PARA MOVER!!\n");

          tab[i][j] = 'D';
          tab[x][y] = ' ';
        }else
           if ((x < i) && (y < j)) {
              for (l = x+1, c = y+1; c <= j; l++, c++)
                if (tab[l][c] != ' ')
                 return printf("NÃO DA PARA MOVER!!\n");

            tab[i][j] = 'D';
            tab[x][y] = ' ';
           }else
              if ((x > i) && (y > j)) {
                for (l = x-1, c = y-1; c >= j; l--, c--)
                  if (tab[l][c] != ' ')
                    return printf("NÃO DA PARA MOVER!!\n");

              tab[i][j] = 'D';
              tab[x][y] = ' ';
             }else
              if ((x > i) && (y < j)) {
                for (l = x-1, c = y+1; c <= j; l--, c++)
                  if (tab[l][c] != ' ')
                    return printf("NÃO DA PARA MOVER!!\n");

              tab[i][j] = 'D';
              tab[x][y] = ' ';
              }
}
//=======================================================================================
//REI PRETO
int reiPreto(int x,int y,int i,int j, char tab[8][8]) {
  int l, c;

  if ( (x < 0) || (x > 7) || (y < 0) || (y > 7) ) {//verifica se linha e coluna são validos
    return printf("POSIÇÂO NÃO VALIDA !!!!!\n\n");
  }

  if ( x == i ) {
    if (y < j) {
     for ( l = x, c = y+1; c <= j; c++ ){
       if ( tab[l][c] != ' ') {
         return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
       }
     }
    }else
       if (y > j) {
         for ( l = x, c = y-1; c >= j; c-- ){
           if ( tab[l][c] != ' ') {
             return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
           }
         }
       }

  tab[i][j] = 'R';
  tab[x][y] = ' ';
  } else
      if ( y == j ) {
        if ( x < i) {
          for ( l = x+1, c = y; l <= i; l++ ) {
            if ( tab[l][c] != ' ') {
              exibeTabuleiro(tab);
              return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
            }
          }
      } else
          if ( x > i ) {
            for ( l = x, c = y+1; c <= j; c++ ){
              if ( tab[l][c] != ' ') {
                exibeTabuleiro(tab);
                return printf("POSIÇÃO JÁ ESTÁ OCULPADA !!!!\n\n");
              }
            }
          }
      tab[i][j] = 'R';
      tab[x][y] = ' ';
     }else
        if ((x < i) && (y > j)) {
          for (l = x+1, c = y-1; c >= j; l++, c--)
            if (tab[l][c] != ' ')
              return printf("NÃO DA PARA MOVER!!\n");

          tab[i][j] = 'R';
          tab[x][y] = ' ';
        }else
           if ((x < i) && (y < j)) {
              for (l = x+1, c = y+1; c <= j; l++, c++)
                if (tab[l][c] != ' ')
                 return printf("NÃO DA PARA MOVER!!\n");

            tab[i][j] = 'R';
            tab[x][y] = ' ';
           }else
              if ((x > i) && (y > j)) {
                for (l = x-1, c = y-1; c >= j; l--, c--)
                  if (tab[l][c] != ' ')
                    return printf("NÃO DA PARA MOVER!!\n");

              tab[i][j] = 'R';
              tab[x][y] = ' ';
             }else
              if ((x > i) && (y < j)) {
                for (l = x-1, c = y+1; c <= j; l--, c++)
                  if (tab[l][c] != ' ')
                    return printf("NÃO DA PARA MOVER!!\n");

              tab[i][j] = 'R';
              tab[x][y] = ' ';
              }
}
