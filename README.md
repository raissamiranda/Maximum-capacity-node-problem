# Maximum capacity node problem
This project finds the best path between two cities that maximizes the possible amount of suplies to be carried. The problem can be modeled as a graph with the vertices representing the cities and the edges representing the roads between them. The weight of the edges refers to the maximum load that his road supports. The solution uses Dijkstra's algorithm modified for the maximum capacity.

## Usage
The first line has 3 values that indicate, respectively, the number of cities, the number of highways connecting the cities and the number of queries to be carried out. A query consists of two values u and v, indicating that we want to know what is the largest payload that can be sent from u to v. You can assume that there is always a way. The next lines describe a highway with 3 values: departure city, arrival city and its maximum weight supported. The output file will be generate with one value for each query with the maximum weight for this path.

## Example
### input
```
4 10 4
1 2 9000
2 1 9000
1 3 1000
3 1 1000
2 3 8000
3 2 8000
2 4 7000
4 2 7000
3 4 4000
4 3 4000
1 4
2 1
3 1
4 3
``` 
### output
```
7000
9000
8000
7000
```

## Execution
To install the program, it is necessary to acess the diretory where the program is stored
``` 
cd -directory-
```

Now, it's necessary to compile and execute the program using the commands:
```
g++ max_capacity.cpp
./a.out -input_file.txt-
```
