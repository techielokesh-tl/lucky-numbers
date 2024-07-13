#include <iostream>
#include <cstring>
#include "random_counter.h"

int main(int argc, char *argv[])
{
    // check if the correct number of arguments are provided
    if(argc != 2)
    {
        printUsage();
        return 1;
    }

    // determine the mode (normal or debug)
    bool debugMode = false;
    if(std::strcmp(argv[1], "debug") == 0)
    {
        debugMode = true;
    }
    else if(std::strcmp(argv[1], "normal") != 0)
    {
        printUsage();
        return 1;
    }

    // run the random counter
    runRandomCounter(debugMode);
    
    return 0;
}