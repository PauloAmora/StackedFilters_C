#include "codecpp.hpp"

#include <iostream>


//----------- Implementation of class RunningStatics -----------//

StackedFilterWrapper::StackedFilterWrapper()
{
    static constexpr int kBitsPerElement = 10;
    static constexpr int kNumPositives = 10;
    static constexpr int kNumNegatives = 15;
    int num_elements = kNumPositives + kNumNegatives;
    //std::vector<IntElement> ints = generate_ints();
    std::uniform_int_distribution<long> distribution(0, 20);
    std::vector<IntElement> int_vec(num_elements);
    for (uint64 i = 0; i < num_elements; i++)
    {
        int_vec[i] = i;
    }
    std::shuffle(int_vec.begin(), int_vec.end(), std::minstd_rand());
     for (uint64 i = 0; i < num_elements; i++)
    {
        std::cout << *(int_vec[i].get_value()) << " ";
    }
    
    std::vector<IntElement> positives(int_vec.begin(), int_vec.begin() + kNumPositives);
    std::vector<IntElement> negatives(int_vec.begin() + kNumPositives, int_vec.end());
    //std::vector<double> cdf = uniform_cdf(kNumNegatives);
    std::vector<double> cdf;
    double sum = 0;
    for (uint64_t i = 1; i <= kNumNegatives; i++)
    {
        sum += 1. / kNumNegatives;
        cdf.push_back(sum);
    }


    filter = new StackedFilter<BloomFilterLayer, IntElement>(kBitsPerElement * positives.size(), positives, negatives, cdf);
}

 StackedFilterWrapper::StackedFilterWrapper(
                   const size_t total_size,
                   const std::vector<IntElement> &positives,
                   const std::vector<IntElement> &negatives,
                   const std::vector<double> &cdf)
 {
     filter = new StackedFilter<BloomFilterLayer, IntElement>(total_size, positives, negatives, cdf);
 }

bool StackedFilterWrapper::Lookup(int x)
{
    return filter->LookupElement(x);
}

std::vector<IntElement> generate_ints(uint64 num_elements)
{
}

std::vector<double> uniform_cdf(uint64_t num_elements)
{
}

//---------- C-Interface for class Runstat ---------------------//

sFilter sfilter_new()
{
    return new (std::nothrow) StackedFilterWrapper();
}

int filter_LookupElement(sFilter self, const int element)
{
    auto p = reinterpret_cast<StackedFilterWrapper *>(self);
    if (p->Lookup(element))
    {
        return 1;
    }
    return 0;
}
