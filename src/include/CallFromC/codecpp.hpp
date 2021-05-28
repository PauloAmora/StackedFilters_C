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

  StackedFilter<BloomFilterLayer, IntElement> *filter;

public:
  StackedFilterWrapper();
   StackedFilterWrapper(
                   const size_t total_size,
                   const std::vector<IntElement> &positives,
                   const std::vector<IntElement> &negatives,
                   const std::vector<double> &cdf
                   );
  bool Lookup(const int element);
  void InsertPositive(const int element);
};
#endif 

typedef void *sFilter;

EXPORT_C sFilter sfilter_new();
EXPORT_C sFilter sfilter_new_parameters(const size_t total_size, int* positives, int* negatives, double* cdf);
EXPORT_C int filter_LookupElement(sFilter self, const int element);
EXPORT_C void filter_InsertElement(sFilter self, const int element);


#endif
