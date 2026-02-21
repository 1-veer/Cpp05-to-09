#pragma once 
#include <iostream>
#include <vector>



class Span 
{
    private :
        unsigned int N;
        std::vector<int>span;

    public :
        Span();
        Span(unsigned int N);
        Span(const Span &);
        Span& operator=(const Span &);
        ~Span();

        void addNumber(int number);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        // add member for : range of iterators // std::vector::insert
        template<typename It_type>
        void addRangeOfIterators(It_type begin, It_type end)
        {
            unsigned int dist = std::distance(begin, end);
            if (dist + span.size() > N) 
                throw std::out_of_range("Not Enough Space!");
            span.insert(span.end(), begin, end);
        }

        
};