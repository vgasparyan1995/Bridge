#include "Generator.h"

using namespace local;

Generator::Generator(const long double min, const long double max)
    : min_value(min)
    , max_value(max)
    , m_gen(std::random_device()())
{}

Generator::~Generator()
{}

Uniform::Uniform(const long double min,
        const long double max)
    : Generator(min, max)
    , m_dist(0.0, 1.0)
{}

long double Uniform::generate() 
{
    return get_min() + (get_max() - get_min()) * m_dist(m_gen);
}

Normal::Normal(const long double min,
        const long double max,
        const long double mean,
        const long double variance)
    : Generator(min, max)
    , m_mean(mean)
    , m_variance(variance)
    , m_dist(mean, variance)
{}

long double Normal::generate() 
{
    long double result = 0.0;
    do
    {
        result = m_dist(m_gen);
    } while (result < get_min() || result > get_max());
    return result;
}

Poisson::Poisson(const long double min,
        const long double max,
        const long double lambda)
    : Generator(min, max)
    , m_lambda(lambda)
    , m_dist(lambda)
{}

long double Poisson::generate() 
{
    long double result = 0.0;
    do
    {
        result = m_dist(m_gen);
    } while (result > 2 * m_lambda);
    return get_min() + (get_max() - get_min()) * result / (2 * m_lambda);
}
