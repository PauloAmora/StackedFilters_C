#include <stdio.h>
#include <stdlib.h>

#include "codecpp.hpp"

int main()
{
   printf("\n == EXPERIMENT 1 - Build Filter ======\n");

   //int positives[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
   int positives[2] = {2, 3};
   
   int negatives[20] = {1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307};

   double cdf[20];
   double sum = 0;
   for (int i = 0; i < 20; i++)
   {
      sum += 1. / 20;
      cdf[i] = (sum); 
   }

   sFilter filter = sfilter_new_parameters(10 * 2, positives, 2, negatives, 20, cdf, 20);
   
   
   int result = filter_LookupElement(filter, 2);
   printf("Elemento 2 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);
   result = filter_LookupElement(filter, 3);
   printf("Elemento 3 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);
   
   result = filter_LookupElement(filter, 500);
   printf("Elemento 500 encontrado? 1:sim, 0: nao = %d gabarito: 0?\n", result);
   result = filter_LookupElement(filter, 1000);
   printf("Elemento 1000 encontrado? 1:sim, 0: nao = %d gabarito: 0?\n", result);
   result = filter_LookupElement(filter, 1249);
   printf("Elemento 1249 encontrado? 1:sim, 0: nao = %d gabarito: 0\n", result);
   result = filter_LookupElement(filter, 1223);
   printf("Elemento 1223 encontrado? 1:sim, 0: nao = %d gabarito: 0\n", result);

   printf("\n == EXPERIMENT 2 - Insert element ======\n");
   result = filter_LookupElement(filter, 5927);
   printf("Elemento 5927 encontrado? 1:sim, 0: nao = %d gabarito: 0\n", result);

   filter_InsertElement(filter, 5927);
  
   filter_InsertElement(filter, 5);
  filter_InsertElement(filter, 7);
  filter_InsertElement(filter, 11);
  filter_InsertElement(filter, 13);
  filter_InsertElement(filter, 17);
  filter_InsertElement(filter, 19);
  filter_InsertElement(filter, 31);
  filter_InsertElement(filter, 61);
  filter_InsertElement(filter, 43);
  filter_InsertElement(filter, 53);
  

   result = filter_LookupElement(filter, 5927);
   printf("Elemento 5927 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);


result = filter_LookupElement(filter, 11);
   printf("Elemento 11 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);
result = filter_LookupElement(filter, 19);
   printf("Elemento 19 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);
result = filter_LookupElement(filter, 31);
   printf("Elemento 31 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);
result = filter_LookupElement(filter, 61);
   printf("Elemento 61 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);
result = filter_LookupElement(filter, 43);
   printf("Elemento 43 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);



   printf("\n == EXPERIMENT 3 - Delete element ======\n");
   result = filter_LookupElement(filter, 1337);
   printf("Elemento 1337 encontrado? 1:sim, 0: nao = %d gabarito: 0\n", result);

   filter_InsertElement(filter, 1337);

   result = filter_LookupElement(filter, 1337);
   printf("Elemento 1337 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);

   filter_DeleteElement(filter, 1337);

   result = filter_LookupElement(filter, 1337);
   printf("Elemento 1337 encontrado? 1:sim, 0: nao = %d gabarito: 0\n", result);


    printf("\n == EXPERIMENT 4 - Insert negative element ======\n");
   printf("\n == EXPERIMENT 4.1 - without delete ======\n");
   result = filter_LookupElement(filter, 1223);
   printf("Elemento 1223 encontrado? 1:sim, 0: nao = %d gabarito: 0\n", result);
filter_InsertElement(filter, 1223);
result = filter_LookupElement(filter, 1223);
   printf("Elemento 1223 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);

   return 0;
}
