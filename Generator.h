#pragma once

#include <random>

namespace local
{

class Generator
{
public:
    Generator(const long double min, const long double max);
    virtual long double generate() = 0;
    virtual ~Generator();

    inline void set_range(const long double min, const long double max)
    {
        min_value = min;
        max_value = max;
    }
    inline long double get_min() const
    {
        return min_value;
    }
    inline long double get_max() const
    {
        return max_value;
    }

private:
    long double min_value;
    long double max_value;
protected:
    std::mt19937 m_gen;
};

class Uniform : public Generator
{
public:
    Uniform(const long double min, const long double max);
    virtual long double generate() override;

private:
    std::uniform_real_distribution<> m_dist;
};

class Normal : public Generator
{
public:
    Normal(const long double min,
            const long double max,
            const long double mean,
            const long double variance);
    virtual long double generate() override;

private:
    const long double m_mean;
    const long double m_variance;
    std::normal_distribution<> m_dist;
};

class Poisson : public Generator
{
public:
    Poisson(const long double min,
            const long double max,
            const long double lambda);
    virtual long double generate() override;

private:
    const long double m_lambda;
    std::poisson_distribution<> m_dist;
};

} // namespace local
