#include "lib/parallel_sort.cpp"
#include <vector>
#include "lib/test_utils.cpp"


int main()
{
    int n = 5000000;
    int r = 5000;

    omp_set_nested(1);
    omp_set_dynamic(0);
    omp_set_num_threads(8);
    
    
    std::vector<int> arr(n);
    std::vector<int> result(n);

    for(int i=0;i<n;i++)
        arr[i] = rand() % r;
    
    result = parallel_sort(arr,r);

    std::cout<<check_ordered(result)<<std::endl;
    return 0;
}