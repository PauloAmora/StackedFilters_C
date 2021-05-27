#include <stdio.h>
#include <stdlib.h>

#include "codecpp.hpp"

int main()
{
   printf("\n == EXPERIMENT 1 - Use pre-built filter ======\n");
   sFilter filter = sfilter_new();
   int result = filter_LookupElement(filter, 0);
   printf("Elemento 0 encontrado? 1:sim, 0: nao = %d\n", result);
   result = filter_LookupElement(filter, 1);
   printf("Elemento 1 encontrado? 1:sim, 0: nao = %d\n", result);
   result = filter_LookupElement(filter, 2);
   printf("Elemento 2 encontrado? 1:sim, 0: nao = %d\n", result);
   result = filter_LookupElement(filter, 3);
   printf("Elemento 3 encontrado? 1:sim, 0: nao = %d\n", result);
   result = filter_LookupElement(filter, 4);
   printf("Elemento 4 encontrado? 1:sim, 0: nao = %d\n", result);
   result = filter_LookupElement(filter, 5);
   printf("Elemento 5 encontrado? 1:sim, 0: nao = %d\n", result);
   result = filter_LookupElement(filter, 6);
   printf("Elemento 6 encontrado? 1:sim, 0: nao = %d\n", result);
   result = filter_LookupElement(filter, 7);
   printf("Elemento 7 encontrado? 1:sim, 0: nao = %d\n", result);   
    result = filter_LookupElement(filter, 8);
   printf("Elemento 8 encontrado? 1:sim, 0: nao = %d\n", result);
   result = filter_LookupElement(filter, 9);
   printf("Elemento 9 encontrado? 1:sim, 0: nao = %d\n", result);
   result = filter_LookupElement(filter, 10);
   printf("Elemento 10 encontrado? 1:sim, 0: nao = %d\n", result);
   result = filter_LookupElement(filter, 11);
   printf("Elemento 11 encontrado? 1:sim, 0: nao = %d\n", result);
   result = filter_LookupElement(filter, 12);
   printf("Elemento 12 encontrado? 1:sim, 0: nao = %d\n", result);
   result = filter_LookupElement(filter, 13);
   printf("Elemento 13 encontrado? 1:sim, 0: nao = %d\n", result);
   result = filter_LookupElement(filter, 14);
   printf("Elemento 14 encontrado? 1:sim, 0: nao = %d\n", result);

   // printf("\n == EXPERIMENT 2 - Class Runstat ======\n");
   // pStat obj = Runstat_new();
   // Runstat_add(obj, 10.0);
   // Runstat_add(obj, 4.0);
   // Runstat_add(obj, 25.0);
   // Runstat_add(obj, 16.0);

   // printf(" Number of Elements processed = %zu \n", Runstat_size(obj));
   // printf(" Mean = %.5f \n", Runstat_mean(obj));
   // printf(" Sdev = %.5f \n", Runstat_sdev(obj));

   // Runstat_add(obj, -50.0);
   // Runstat_add(obj, 80.0);
   // printf(" Mean = %.5f \n", Runstat_mean(obj));
   // printf(" Sdev = %.5f \n", Runstat_sdev(obj));
   // // Delete C++ Object
   // Runstat_del(obj);
   return 0;
}
