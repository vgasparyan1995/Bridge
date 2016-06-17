#include <iostream>
#include <vector>

#include "RandomNumberGenerator.h"

void print_random_histogram(const int n)
{
    auto rng = local::random_generator::get_instance();
    const int min = rng->get_min();
    const int max = rng->get_max();
    std::vector<int> histogram(max - min + 1, 0);
    for (int i = 0; i < n; ++i) {
        ++histogram[(int)rng->generate() - min];
    }
    for (int i = 0; i < histogram.size(); ++i) {
        std::cout << min + i << ":\t" << histogram[i] << std::endl;
    }
}

int main()
{
    auto rng = local::random_generator::get_instance();
    rng->init_uniform(0, 10);
    std::cout << std::endl << std::endl << "Uniform Distribution" << std::endl << std::endl;
    print_random_histogram(10000);
    rng->init_normal(5, 3);
    std::cout << std::endl << std::endl << "Normal Distribution" << std::endl << std::endl;
    print_random_histogram(10000);
    rng->init_poisson(5);
    std::cout << std::endl << std::endl << "Poisson Distribution" << std::endl << std::endl;
    print_random_histogram(10000);
    rng->remove_instance();
}
