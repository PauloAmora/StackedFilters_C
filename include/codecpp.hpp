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
   StackedFilterWrapper(const size_t total_size,
                   const std::vector<IntElement> &positives,
                   const std::vector<IntElement> &negatives,
                   const std::vector<double> &cdf
                   );
  bool Lookup(const int element);
};
#endif //-- End of __cplusplus definition //

// ========== C-interface for std::string container
typedef void *sFilter;

EXPORT_C sFilter sfilter_new();
//EXPORT_C hString string_new1 (const char* text);
//EXPORT_C hString string_copy (hString self);
EXPORT_C int filter_LookupElement(sFilter self, const int element);
//EXPORT_C void    string_add  (hString self, const char* text);
//EXPORT_C void    string_disp (hString, const char* name);

//============ C-interface for class Runstat ============//

// Opaque pointer type alias for C-lang
//typedef void *pStat;

//EXPORT_C pStat   Runstat_new();
//EXPORT_C void    Runstat_del (pStat self);
//EXPORT_C void    Runstat_add (pStat self, double x);
//EXPORT_C double  Runstat_mean(pStat self);
//EXPORT_C double  Runstat_sdev(pStat self);
//EXPORT_C size_t  Runstat_size(pStat self);

#endif
