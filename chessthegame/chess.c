#include <stdio.h>
#include <stdlib.h>

// Tabuleiro
int tab[8][8];

void inicializarTabuleiro() {
  tab [0][0] = 1;   //black rook
  tab [0][1] = 2;   //black knight
  tab [0][2] = 3;   //black bishop
  tab [0][3] = 4;   //black queen
  tab [0][4] = 5;   //black king
  tab [0][5] = 3;   //black bishop
  tab [0][6] = 2;   //black knight
  tab [0][7] = 1;   //black rook
  for (int i = 0; i < 8; i++){
      tab[1][i] = 6;
  }

  tab [7][0] = 7;   //white rook
  tab [7][1] = 8;   //white knight
  tab [7][2] = 9;   //white bishop
  tab [7][3] = 10;  //white queen
  tab [7][4] = 11;  //white king
  tab [7][5] = 9;   //white bishop
  tab [7][6] = 8;   //white knight
  tab [7][7] = 7;   //white rook
  for (int i = 0; i < 8; i++){
      tab[6][i] = 12;
  }

  for (int i = 2; i < 6; i++){
    for(int d = 0; d < 8 ;d++)
      tab[i][d] = 0;
  }
}
void printTabuleiro (){
   for (int i = 0; i < 8; i++){
      for (int g = 0; g < 8; g++){
        switch (tab[i][g]){
          case 0:
              printf ("    |");
              break;
          case 1:
              printf (" bR |");
              break;
          case 2:
              printf (" bk |");
              break;
          case 3:
              printf (" bB |");
              break;
          case 4:
              printf (" bQ |");
              break;
          case 5:
              printf (" bK |");
              break;
          case 6:
              printf (" bP |");
              break;
          case 7:
              printf (" wR |");
              break;
          case 8:
              printf (" wk |");
              break;
          case 9:
              printf (" wB |");
              break;
          case 10:
              printf (" wQ |");
              break;
          case 11:
              printf (" wK |");
              break;
          case 12:
              printf (" wP |");
              break;
        }
      }
      printf ("    %i ", i);
      printf("\n\n");
   }
  printf (" 0     1    2    3    4    5    6    7 \n");
 }

int checkSpot (int lin1, int col1, int corJogador){
  if (corJogador == 0){
    if (tab[lin1][col1] >= 7 && tab[lin1][col1] <= 12){
    }
    else {
      return 1;
    }
  }
  else if (corJogador == 1){
    if (tab[lin1][col1] >= 1 && tab[lin1][col1] <= 6){
    }
    else {
      return 1;
    }
  }
return 0;
}
int movePieces (int piece, int lin1, int col1, int lin2, int col2) {
//Moving in line (Rooks and Queens)
  if (piece == 1 || piece == 7 || piece == 4 || piece == 10){
//Move in Row
    if ((lin1 == lin2) && (col1 != col2)) {
      if (col1 < col2) {
         for (int a = col1 + 1; a < col2; a++ ) {
             if (tab[lin2][a] == 0){
             }
             else {
               return 1;
             }

          }

      }
      else if (col2 < col1) {
          for (int a = col2 + 1; a < col1; a++ ) {
             if (tab[lin2][a] == 0){
             }
             else {
               return 1;
         }
       }
    }
}
//Move in Collum
   else if ((col1 == col2) && (lin1 != lin2)) {
       if (lin1 < lin2){
         for (int a = lin1 + 1; a < lin2; a++ ) {
            if (tab[a][col2] == 0){
            }
            else {
              return 1;
            }
         }
      }
      else if (lin2 < lin1){
         for (int a = lin2 + 1; a < lin1; a++ ) {
           if (tab[a][col2] == 0){
           }
           else {
             return 1;
          }
        }
      }
    }
}
//Moving in diagonals (Bishops and Queens)
  if (piece == 3 || piece == 9 || piece == 4 || piece == 10){
      if (lin1 < lin2 && col1 < col2){
         for ( int a = lin1 + 1, b = col1 + 1; a < lin2 && b < col2; a++, b++){
           if (tab[a][b] == 0){
           }
           else {
              return 1;
           }
         }
      }
      if (lin2 < lin1 && col1 < col2){
         for ( int a = lin1 - 1, b = col1 + 1; a > lin2 && b < col2; a--, b++){
           if (tab[a][b] == 0){
           }
           else {
              return 1;
           }
         }
      }
      if (lin2 < lin1 && col2 < col1){
         for ( int a = lin1 - 1, b = col1 - 1; a > lin2 && b > col2; a--, b--){
           if (tab[a][b] == 0){
           }
           else {
             printf ("%i %i \n", a, b);
             return 1;
           }
         }
      }
      if (lin1 < lin2 && col2 < col1){
         for ( int a = lin1 + 1, b = col1 - 1; a < lin2 && b > col2; a++, b--){
           if (tab[a][b] == 0){
          }
          else {
             return 1;
          }
         }
      }
   }
//Moving King
  if (piece == 5 || piece == 11){
     if ((lin2 == lin1 + 1 && col2 == col1 +1) || (lin2 == lin1 && col2 == col1 + 1) || (lin2 == lin1 -1 && col2 == col1 + 1) || (lin2 == lin1 - 1 && col2 == col1) || (lin2 == lin1 -1 && col2 == col1 -1) || (lin2 == lin1 && col2 == col1 -1) || (lin2 == lin1 +1 && col2 == col1 -1) || (lin2 == lin1 + 1 && col2 == col1)){
     }
     else {
       return 1;
     }
  }
//Moving Knights
  if (piece == 2 || piece == 8){
    if ((lin2 == lin1 + 1 && col2 == col1 + 2) || (lin2 == lin1 + 2 && col2 == col1 + 1) || (lin2 == lin1 + 2 && col2 == col1 - 1) || (lin2 == lin1 + 1 && col2 == col1 -2) || (lin2 == lin1 -1 && col2 == col1 -2) || (lin2 == lin1 -2 && col2 == col1 -1) || (lin2 == lin1 -2 && col2 == col1 + 1) || (lin2 == lin1 - 1 && col2 == col1 + 2)){
    }
    else {
       return 1;
    }
  }
//Moving Pawns
  if (piece == 6){
    if (lin1 == 1){
       if ((lin2 == lin1 + 1 || lin2 == lin1 + 2) && col2 == col1){
       }
       else if (lin2 == lin1 - 1 && (col2 == col1 + 1 || col2 == col1 - 1)){
       }
       else {
          return 1;
       }
    }
    else {
      if (lin2 == lin1 + 1 && col2 == col1){
      }
      else if (lin2 == lin1 - 1 && (col2 == col1 + 1 || col2 == col1 - 1)){
      }
      else {
         return 1;
      }
    }
  }
  if (piece == 12){
    if (lin1 == 6){
       if ((lin2 == lin1 - 1 || lin2 == lin1 - 2) && col2 == col1){
       }
       else if (lin2 == lin1 - 1 && (col2 == col1 + 1 || col2 == col1 - 1)){
       }
       else {
          return 1;
       }
    }
    else {
      if (lin2 == lin1 - 1 && col2 == col1){
      }
      else if (lin2 == lin1 - 1 && (col2 == col1 + 1 || col2 == col1 - 1)){
      }
      else {
         return 1;
      }
    }
  }
return 0;
}
//Capture
int capturing(int piece, int lin2, int col2){
   //Capturing with black
   if (piece >= 1 && piece <= 6){
      if ((tab[lin2][col2] >= 7 && tab [lin2][col2] <= 12) || tab[lin2][col2] == 0){
      }
      else {
         return 1;
      }
   }
   //Capture with white
   if ( piece >= 7 && piece <= 12){
      if ((tab[lin2][col2] >= 1 && tab [lin2][col2] <= 6) || tab[lin2][col2] == 0){
      }
      else {
         return 1;
      }
   }
return 0;
}
int main() {
 int jogo = 1;
 int lin1, col1, lin2, col2;
 int corJogador = 0; //0---Branco
 inicializarTabuleiro();
   while (jogo == 1){
     printTabuleiro();
     printf ("Jogador %i: \n", corJogador);
     printf ("Coordenadas da peça que quer mover:");
     scanf ("%i %i", &lin1, &col1);
        while (checkSpot (lin1, col1, corJogador)){
           printf ("As coordenadas que introduziu não são válidas, por favor introduza novas coordenadas");
           scanf ("%i %i", &lin1, &col1);
        }
     printf ("Coordenadas para onde quer mover a peça:");
     scanf ("%i %i", &lin2, &col2);
        while (movePieces (tab[lin1][col1], lin1, col1, lin2, col2)) {
          printf ("As coordenadas que introduziu não são válidas, por favor introduza novas coordenadas");
          scanf ("%i %i", &lin2, &col2);
        }
        while (capturing(tab[lin1][col1], lin2, col2)){
          printf ("As coordenadas que introduziu não são válidas, por favor introduza novas coordenadas");
          scanf ("%i %i", &lin2, &col2);
        }
     tab[lin2][col2] = tab[lin1][col1];
     tab[lin1][col1] = 0;
     if (corJogador == 0){
       corJogador = 1;
     }
     else {
       corJogador = 0;
     }
   }
 }
