# Lucky Numbers
(a fun project idea by Mr Neal M Gafter)

This project produces a web page in `html` format displaying each day's lucky numbers.
One section of the output lists today's 20 most lucky numbers from 1 to 50, 
one section the 20 luckiest numbers from 1 to 100,
and the last section lists the 20 luckiest numbers from 1 to 200.

Lucky numbers are identified as follows:
1. Initially, a random sample of 1,000,000 (a million) integers from 1 to 200 are used to increment 200 corresponding counters.
2. On the first day, the numbers that have the highest counts are considered the luckiest.
3. On each following day, each counter is scaled down by multiplying by 999 and dividing by 1000.
4. Then, another random sample of 1,000 numbers from 1 to 200 are produced and used to increment the corresponding counters.
5. The new, modified counters are used to produce the new lists of lucky numbers for the day.

This process is intended to produce lists of lucky numbers that change slowly from day to day.

The counters are kept in a file that is read at the beginning of the day's processing, and rewritten after the day's processing.
We keep the last 20 versions of the file so we can recover in case something goes wrong.

# How to compile
if you're using gcc, or g++, you can use:
``` gcc -o main main.cpp random_counter.cpp -lstdc++ ```

# Usage
run the program by using the following commands:
    ``` ./main normal``` or .```/main debug```
