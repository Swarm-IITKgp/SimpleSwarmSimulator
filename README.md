# Swarm_Simulator

This is a simple swarm simulator for the purpose of testing the algorithms to be applied on the bots.

The fake_destination.cpp file contains the algorithm for the formation of a circle from a given number of bots.

Building:

1) Clone the repo. and cd into the cloned directory.
2) Run the following commands
   `make Start`
   `make Output`
   `make destination`
   `make fake_destinatio`
   `g++ -std=c++11 -pthread Simulator.cpp -o Simulator`
   `make test`
3) Run the Simulator
   `./Simulator test`
   (use the flag: --dest-screen to manually give the destination points)
   (use the flag: circle to run the circle formation algorithm)

To spawn the bots select the points by left-clicking on them.
To run the simulation right-click on the arena.
