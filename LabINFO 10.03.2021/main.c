#include <stdio.h>
void grafico(float s, float c, float t, float e, float a);

int main(void) {
  float importo;
  float cancelleria = 0;
  float telefono = 0;
  float elettr = 0;
  float altro = 0;
  float somma = 0;
  enum scelte {CANCELLERIA=1, TELEFONO, ELETTR, ALTRO, GRAFICO};
  int scelta;

  printf("Inserisci l'operazione desiderata.\n");
  printf("1. Registra spesa di cancelleria. \n2. Registra spesa di telefono. \n3. Registra spesa di elettricita'. \n4. Registra spesa di altro. \n5. Visualizza grafico dei costi sul totale. \nInserisci -1 per uscire dal programma.\n");
  scanf("%d", &scelta);
  while (scelta != -1){
    if (scelta <= 4 && scelta > 0){
        printf("Inserisci il costo di questa spesa.\n");
        scanf("%f", &importo);
        somma = somma + importo;
    }
    switch (scelta){
      case CANCELLERIA:
        cancelleria = cancelleria + importo;
        break;
      case TELEFONO:
        telefono = telefono + importo;
        break;
      case ELETTR:
        elettr = elettr + importo;
        break;
      case ALTRO:
        altro = altro + importo;
        break;
      case GRAFICO:
        grafico(somma, cancelleria, telefono, elettr, altro);
        break;
    }
    printf("Inserisci l'operazione desiderata.\n");
    printf("1. Registra spesa di cancelleria. \n2. Registra spesa di telefono. \n3. Registra spesa di elettricita'. \n4. Registra spesa di altro. \n5. Visualizza grafico dei costi sul totale. \nInserisci -1 per uscire dal programma.\n");
    scanf("%d", &scelta);
  }
  return 0;
}

void grafico(float s, float c, float t, float e, float a){
  float media;
  float perc1; //percentuale cancelleria
  float perc2; //percentuale telefono
  float perc3; //percentuale elettricità
  float perc4; //percentuale altro

  media = s/4;
  perc1 = (c/s)*100;
  perc2 = (t/s)*100;
  perc3 = (e/s)*100;
  perc4 = (a/s)*100;
  printf("\n==================================================\n");
  printf("%.2f - %.2f %.2f %.2f ", perc1, perc2, perc3, perc4);
  printf("\nC: ");
  for (int i = 0; i<perc1-1; i = i + 2){
    printf("+");
  }
  printf("\nT: ");
  for (int i = 0; i<perc2-1; i = i + 2){
    printf("+");
  }
  printf("\nE: ");
  for (int i = 0; i<perc3-1; i = i + 2){
    printf("+");
  }
  printf("\nA: ");
  for (int i = 0; i < perc4-1; i = i + 2){
    printf("+");
  }
  printf("\nC=Cancelleria, T=Telefono, E=Elettricita', A=Altro.\n");
  printf("\n==================================================\n");
  return;
}

