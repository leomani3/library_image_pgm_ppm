//ce programme ne fait absolument RIEN et n'existe qu'en tant qu'exemple
#include <stdio.h>
#include "image_ppm.h"

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille, nR, nG, nB;
  
  if (argc != 3) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);




//---------------------"préparations"------------------
   OCTET *ImgIn, *ImgOut; //tableau d'octet
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW); //lit une image en entrée et stock sa largeur et hauteur dans les variables passées en param
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);


//-------------------Pour écire une image--------------
//pgm = nuances de gris (0 = noir, 127 = gris, 255 = blanc)

//ImgOut[0]=0; //un pixel noir

// ppm = couleur. 1 pixel = niveau de rouge, niveau de Vert, niveau de bleu
ImgOut[0]=127;
ImgOut[1]=0;
ImgOut[2]=127;
//Les trois lignes au dessus font UN pixel magenta

//quand on a fini de remplir le tableau on créer l'image
   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}
