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

## How to compile

if you're using gcc, or g++, you can use:
``` gcc -o main main.cpp random_counter.cpp -lstdc++ ```

## Usage

run the program by using the following commands:

  `./main --init --state statefile.csv`

This initializes a new state file, of the given filename, that will contain the state of the simulation.  The `--state` option is required.

  `./main --update --state statefile.csv`

This reads the statefile of the given filename, updates the counters as described in steps 3 and 4 above, sorts them by the values in the counter, and then rewrites the statefile with the updated counters.
Due to the sorting, numbers with higher counts will appear earlier in the statefile than numbers with lower counts.
When two numbers have the same counter value, they are placed in an arbitrary order relative to one another in the statefile.
The `--state` option is required.

  `./main --genhtml --state statefile.csv --n 50 --output lucky50.html`

This command reads the statefile (whose name is given by the `--state` option) and then writes an html file (whose name is given by the `--output` option) containing the top 20 luckiest numbers between 1 and 50 (the number specified by the `--n` option) in a form suitable for a page on a website.
The `--state`, `--n`, and `--output` options are all required, but they may appear in any order.
The value of `--n` may be anything between 1 and 200, inclusive.

The `./main` command requires its first argument be one of `--init`, `--update`, or `--genhtml`. If it is missing or anything else, or some required argument is missing, a help message summarizing the usage is printed and the program exits with error status 1.

## State File

The *state file* is a CSV (comma-separated values) file with two columns. The first column is the number. There should be a row for every number from 1 to 100, but they need not appear in order. The second column is the *count* of the number of times that number has been incremented.  The first row in the state file contains column names for convenience ("Number" and "Count"), and can be discarded when we are looking for just the data.

## Q and A

#### Why are the counts multiplied by 999 and then divided by 1000 at the beginning of each day's processing?

Our intent is to keep the total count around a million. By performing this scaling, we decrease the counts by about one thousand, so that when we increment some counters again, the total count is again near one million. This way we won't have to worry about the counters ever overflowing. Think of it as the luck wearing out over time.

#### Why do we maintain a state file instead of calculating from scratch each day?

The idea is that lucky numbers don't change that quickly.
They don't go from lucky to unlucky from one day to the next, but rather they change slowly from one day to another.
The lucky numbers from one day to the next might only change slightly, with the least of the lucky numbers being replaced by an upcoming lucky number.
The lucky numbers battle for position as if in a tournament.
Our daily update models the change from day to day.

## Scripts

Eventually, we will implement some shell scripts to be used in a cron job to update a website daily and perform backups of the state file.
