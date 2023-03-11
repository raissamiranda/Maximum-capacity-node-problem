# Maximum capacity node problem
This project finds the best path between two cities that maximizes the possible amount of suplies to be carried. The problem can be modeled as a graph with the vertices representing the cities and the edges representing the roads between them. The weight of the edges refers to the maximum load that his road supports. The solution uses Dijkstra's algorithm modified for the maximum capacity.

## Usage
The first line has 3 values that indicate, respectively, the number of cities, the number of highways connecting the cities and the number of queries to be carried out. A query consists of two values u and v, indicating that we want to know what is the largest payload that can be sent from u to v. You can assume that there is always a way. The output file will be generate with one value for each query with the maximum weight for this path.

## Example
### input
'''
9 14 1
1 2 2500
2 3 4000
1 4 3000
2 5 3000
5 2 1500
3 6 1200
4 5 1000
5 6 1500
4 7 1600
5 8 2000
8 5 3000
6 9 1700
7 8 1000
8 9 1500
1 9
'''


## Execution
To install the program, it is necessary to acess the diretory where the program is stored
> cd -directory-

Now, it's necessary to compile and execute the program using the commands:
> g++ max_capacity.cpp

> ./a.out -input_file.txt-
