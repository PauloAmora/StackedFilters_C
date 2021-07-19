#include <stdio.h>
#include <stdlib.h>

#include "codecpp.hpp"

int main()
{
   printf("\n == EXPERIMENT 2 - Build Filter ======\n");

   int positives[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
   int negatives[20] = {1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307};

   double cdf[20];
   double sum = 0;
   for (int i = 0; i < 20; i++)
   {
      sum += 1. / 20;
      cdf[i] = (sum);
   }

   sFilter filter = sfilter_new_parameters(2 * 20, positives, negatives, cdf);
   int result = filter_LookupElement(filter, 19);
   printf("Elemento 19 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);
   result = filter_LookupElement(filter, 67);
   printf("Elemento 67 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);
   result = filter_LookupElement(filter, 500);
   printf("Elemento 500 encontrado? 1:sim, 0: nao = %d gabarito: 0?\n", result);
   result = filter_LookupElement(filter, 1000);
   printf("Elemento 1000 encontrado? 1:sim, 0: nao = %d gabarito: 0?\n", result);
   result = filter_LookupElement(filter, 1249);
   printf("Elemento 1249 encontrado? 1:sim, 0: nao = %d gabarito: 0\n", result);
   result = filter_LookupElement(filter, 1223);
   printf("Elemento 1223 encontrado? 1:sim, 0: nao = %d gabarito: 0\n", result);

   printf("\n == EXPERIMENT 3 - Insert element ======\n");
   result = filter_LookupElement(filter, 5927);
   printf("Elemento 5927 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);

   filter_InsertElement(filter, 5927);
   result = filter_LookupElement(filter, 5927);
   printf("Elemento 5927 encontrado? 1:sim, 0: nao = %d gabarito: 1\n", result);

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
