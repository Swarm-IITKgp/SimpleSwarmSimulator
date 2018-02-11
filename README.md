# Swarm_Simulator

This is a simple swarm simulator for the purpose of testing the algorithms to be applied on the bots.

The circle.cpp file contains the algorithm for the formation of a circle from a given number of bots.

Building:

1) Clone the repository and cd into the cloned directory.
2) Run the following commands (Need to do it only once)
   `make Start`
   `make Output`
   `g++ -std=c++11 -pthread Simulator.cpp -o Simulator`
3) Make the algorithms: For each algorithm, run `make <algorithm_name>`.
   To make test: run `make test`
   To make test2: run `make test2`
   To make circle: run `make circle`
   To make the manual destination input: run `make destination`
3) Run the Simulator
   `./Simulator <algorithm_name>`
   (use the flag: `--dest-screen` to manually give the destination points)
   (use the flag: `circle` to run the circle formation algorithm)

To spawn the bots select the points by left-clicking on them.
To run the simulation right-click on the arena.
