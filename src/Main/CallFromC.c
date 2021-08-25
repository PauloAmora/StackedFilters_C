#include <stdio.h>
#include <stdlib.h>

#include "codecpp.hpp"

int main()
{
   printf("\n == EXPERIMENT 2 - Build Filter ======\n");

   static int positives[1000]; 
   static int negatives[10000];

   int i = 0;

    for(i=0;i<1000;i++)
    {
          positives[i] = i+1;
       
    }
    int j = 0;
    for(j=0;j<10000;j++)
    {
          negatives[j] = j+i+1;
       
    } 



   static double cdf[1000];
   double sum = 0;
   for (int i = 0; i < 1000; i++)
   {
      sum += 1. / 1000;
      cdf[i] = (sum);
   }

   const size_t total_size = 1000*10;


        
    
   sFilter filter = sfilter_new_parameters(total_size, positives, (sizeof positives / sizeof positives[0]), negatives, (sizeof negatives / sizeof negatives[0]),cdf,(sizeof cdf / sizeof cdf[0]));
   int result = filter_LookupElement(filter, 19);
   printf("Elemento 19 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);


   // result = filter_LookupElement(filter, 67);
   // printf("Elemento 67 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);
   // result = filter_LookupElement(filter, 500);
   // printf("Elemento 500 encontrado? 1:sim, 0: nao = %d gabarito: 0?\n", result);
   // result = filter_LookupElement(filter, 1000);
   // printf("Elemento 1000 encontrado? 1:sim, 0: nao = %d gabarito: 0?\n", result);
   // result = filter_LookupElement(filter, 1249);
   // printf("Elemento 1249 encontrado? 1:sim, 0: nao = %d gabarito: 0\n", result);
   // result = filter_LookupElement(filter, 1223);
   // printf("Elemento 1223 encontrado? 1:sim, 0: nao = %d gabarito: 0\n", result);

   // printf("\n == EXPERIMENT 3 - Insert element ======\n");
   // result = filter_LookupElement(filter, 5927);
   // printf("Elemento 5927 encontrado? 1:sim, 0: nao = %d gabarito: 0\n", result);

   // filter_InsertElement(filter, 5927);
   // result = filter_LookupElement(filter, 5927);
   // printf("Elemento 5927 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);


   return 0;
}
