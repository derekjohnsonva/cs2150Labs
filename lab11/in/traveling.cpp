// Derek Johnson dej3tc
// 12/3/19
// traveling.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"
/*!@brief Finds the total distance traveled
  @param me a reverence to the MiddleEarth object being used
  @param start the starting point of the journey
  @param dests the places the journey needs to travel through

  This method uses the middleEarth method getDistance to find the total distance
  between every city.
*/
float computeDistance (MiddleEarth &me, string start, vector<string> dests);
/*!@brief outputs the cities in order
  @param start The starting point of the journey
  @param dests the places the journey goes through

  Will output the start, all the cities in the vector dests, and then the 
  start again, signifying that this is a loop
*/
void printRoute (string start, vector<string> dests);
/*!@param argc the number of arguments supplied
  @param argv An argument vector of the command line arguments
  @return an integer 0 upon exit success

  The main method will generate a new MiddleEarth object from the parameters
  and then will find the shortest path through a random set of cities

  The command line arguments are as follows
  int xsize of the world
  int ysize of the world
  int number of cities to generate in the world
  int seed controls the random generation of the world
  int length is the number of cities to make our route
*/
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    sort(dests.begin()+1,dests.end());
    string start = dests[0];
    dests.erase(dests.begin());
    float minDist = computeDistance(me, start, dests);
    vector<string> minPath = dests;
    do{
      if(minDist > computeDistance(me, start, dests)){
        minPath = dests;
        minDist = computeDistance(me, start, dests);
      }
    } while ( next_permutation(dests.begin()+1, dests.end()));
    cout << minDist << endl;
    printRoute(start, minPath);
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
  float total;
  total = me.getDistance(start, dests.front());
  for(int i =0; i < dests.size()-1;i++){
    total += me.getDistance(dests[i],dests[i+1]);
  } 
  total += me.getDistance(dests.back(),start);
  return total;
}


// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
  cout << start << " ";
  for(int i=0; i<dests.size(); i++){
    cout << "-> " << dests[i] << " ";
  }
  cout << "-> " << start;
  cout << endl;
}
