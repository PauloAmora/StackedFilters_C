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


    filter = new StackedFilter<CQFilterLayer, IntElement>(kBitsPerElement * positives.size(), positives, negatives, cdf);
}

 StackedFilterWrapper::StackedFilterWrapper(
                   const size_t total_size,
                   const int* pos,
                   const int* neg,
                   const double* cdf)
 {
     std::vector<int> pos_int_vec(pos, pos + sizeof(pos) / sizeof pos[0]);
     std::vector<int> neg_int_vec(neg, neg + sizeof(neg) / sizeof neg[0]);
     std::vector<double> cdf_dob_vec(cdf, cdf + sizeof(cdf) / sizeof cdf[0]);

     std::vector<IntElement> pos_ele_vec(pos_int_vec.begin(), pos_int_vec.end());
     std::vector<IntElement> neg_ele_vec(neg_int_vec.begin(), neg_int_vec.end());

     
     filter = new StackedFilter<CQFilterLayer, IntElement>(total_size, pos_ele_vec, neg_ele_vec, cdf_dob_vec);
 }

bool StackedFilterWrapper::Lookup(int x)
{
    return filter->LookupElement(x);
}

void StackedFilterWrapper::InsertPositiveElement(int x){
    return filter->InsertPositiveElement(x);

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

sFilter sfilter_new_parameters(size_t total_size, int* pos, int* neg, double* cdf){
    return new (std::nothrow) StackedFilterWrapper(total_size, pos, neg, cdf);
}

void filter_InsertElement(sFilter self, const int element){
    auto p = reinterpret_cast<StackedFilterWrapper *>(self);
    p->InsertPositiveElement(element);
}
