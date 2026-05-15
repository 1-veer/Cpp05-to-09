#include "Span.hpp"
#include <climits>
#include <algorithm>

Span::Span() : N(0), span() {}

Span::Span(unsigned int N) : N(N) { span.reserve(N); }

Span::Span(const Span &other) : N(other.N), span(other.span) {}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        N = other.N;
        span = other.span;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (span.size() >= N)
        throw std::out_of_range("FULL!");
    span.push_back(number);
}

unsigned int Span::shortestSpan()
{
    if (span.size() < 2)
        throw std::out_of_range("Not Enough Elements!");

    std::vector<int> sortedSpan(span); 
    std::sort(sortedSpan.begin(), sortedSpan.end());

    unsigned int minSpan = UINT_MAX; 
    for (size_t i = 1; i < sortedSpan.size(); ++i)
    {
        unsigned int currentSpan = sortedSpan[i] - sortedSpan[i - 1];
        if (currentSpan < minSpan)
            minSpan = currentSpan;
    }
    return minSpan;
}

unsigned int Span::longestSpan()
{
    if (span.size() < 2)
        throw std::out_of_range("Not Enough Elements!");

    int minElement = *std::min_element(span.begin(), span.end()); // cuz it a pointer to the nbr and we have to dereference it
    int maxElement = *std::max_element(span.begin(), span.end());

    return maxElement - minElement;
}




