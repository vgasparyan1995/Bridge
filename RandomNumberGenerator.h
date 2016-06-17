#pragma once

#include "Generator.h"

namespace local
{

class random_generator
{
public:
    void init_uniform(const long double min, const long double max);
    void init_normal(const long double mean, const long double variance);
    void init_poisson(const long double lambda);
    long double generate();

    inline void set_range(const long double min, const long double max)
    {
        if (m_generator != nullptr) {
            m_generator->set_range(min, max);
        }
    }
    inline long double get_min() const
    {
        if (m_generator != nullptr) {
            return m_generator->get_min();
        }
    }
    inline long double get_max() const
    {
        if (m_generator != nullptr) {
            return m_generator->get_max();
        }
    }

private:
    void generator_remover(long double& min, long double& max);
    template <typename T, typename ... Args>
    void init(Args ... args);

private:
    Generator* m_generator;

public:
    static random_generator* get_instance();
    static void remove_instance();

private:
    static random_generator* s_instance;
    
    random_generator();
    ~random_generator();
    random_generator(const random_generator&) = delete;
    random_generator& operator=(const random_generator&) = delete;
    random_generator(random_generator&&) = delete;
    random_generator& operator=(random_generator&&) = delete;
};

} // namespace local
