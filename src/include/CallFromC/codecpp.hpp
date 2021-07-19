#ifndef _CODECPP_
#define _CODECPP_

#ifdef __cplusplus
#define EXPORT_C extern "C"
#else
#define EXPORT_C
#endif

//============ C++ Only Header =================//
#ifdef __cplusplus
#include "StackedFilter.h"

class StackedFilterWrapper
{

  StackedFilter<CQFilterLayer, IntElement> *filter;

public:
  StackedFilterWrapper();
   StackedFilterWrapper(
                  const size_t total_size,
                   const int* pos,
                   const int pos_size,
                   const int* neg,
                   const int neg_size,
                   const double* cdf,
                   const int cdf_size
                   );
  bool Lookup(const int element);
  void InsertPositiveElement(const int element);
  void DeleteElement(const int element);
};
#endif 

typedef void *sFilter;

EXPORT_C sFilter sfilter_new();
EXPORT_C sFilter sfilter_new_parameters(size_t total_size, int* positives, int pos_size, int* negatives, int neg_size, double* cdf, int cdf_size);
EXPORT_C int filter_LookupElement(sFilter self, const int element);
EXPORT_C void filter_InsertElement(sFilter self, const int element);
EXPORT_C void filter_DeleteElement(sFilter self, const int element);


#endif
