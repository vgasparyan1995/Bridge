#include "RandomNumberGenerator.h"

using namespace local;

random_generator* random_generator::s_instance = nullptr;

void random_generator::init_uniform(const long double min, const long double max)
{
    init<Uniform>(min, max);
}

void random_generator::init_normal(const long double mean, const long double variance)
{
    init<Normal>(get_min(), get_max(), mean, variance);
}

void random_generator::init_poisson(const long double lambda)
{
    init<Poisson>(get_min(), get_max(), lambda);
}

long double random_generator::generate()
{
    if (m_generator != nullptr) {
        return m_generator->generate();
    }
    return 0.0;
}

void random_generator::generator_remover(long double& min, long double& max)
{
    if (m_generator != nullptr) {
        min = get_min();
        max = get_max();
        delete m_generator;
    }
}

template <typename T, typename ... Args>
void random_generator::init(Args ... args)
{
    long double min = 0.0;
    long double max = 1.0;
    generator_remover(min, max);
    m_generator = new T(args...);
}

random_generator* random_generator::get_instance()
{
    if (s_instance == nullptr) {
        s_instance = new random_generator();
    }
    return s_instance;
}

void random_generator::remove_instance()
{
    delete s_instance;
    s_instance = nullptr;
}

random_generator::random_generator()
    : m_generator(nullptr)
{}

random_generator::~random_generator()
{
    delete m_generator;
    m_generator = nullptr;
}
