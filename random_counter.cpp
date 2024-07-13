#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "random_counter.h"
#include <utility>

void printUsage()
{
    std::cout << "Usage: main [normal|debug]" << std::endl;
}

void runRandomCounter(bool debugMode)
{
    const int range = 200;
    const int iterations = 5000; // can be changed later
    int counts[range] = {0};

    // Seeding the random number generator using srand();
    std::srand(std::time(0)); // i looked over stackoverflow for this

    /* a loop to generate random numbers and increment the corresponding array slot */
    for(int i = 0; i < iterations; ++i)
    {
        // generates a random number between 1 and range
        int random_number = std::rand() % range + 1;
        // increment the corresponding slot
        counts[random_number - 1]++;

        if(debugMode)
        {
            std::cout << "Iteration " << i + 1 << ": Generated number " << random_number << std::endl;
        }
    }

    // create a vector of pairs to sort results
    std::vector<std::pair<int, int>>sortedCounts;
    for(int i = 0; i < range; ++i)
    {
        sortedCounts.push_back(std::make_pair( i + 1, counts[i]));
    }

    /* sort the vector by counts in descending order */
    // took help from chatGPT for this part, i couldn't figure it out myself
    std::sort(sortedCounts.begin(), sortedCounts.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b)
        {
            return b.second < a.second;
        }
    );

    // outputting the sorted results
    for(const auto& pair : sortedCounts)
    {
        std::cout << "Number " << pair.first << " was generated " << pair.second << "times." << std::endl;
    }
}