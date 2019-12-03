
#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp
/*! \class MiddleEarth
    \brief A class for grid traversals
  
    This is a class that will allow us to experiment with 
    the topological sort method. It contains a number of cities
    contained in the grid.

*/
class MiddleEarth {
private:
    int num_city_names, xsize, ysize;
    vector<float> xpos, ypos;
    vector<string> cities;
    float *distances;
    map<string, int> indices;

public:
    /*! \brief The public constructor for middle Earth
        \param xsize this will determine the x size of the middle earth grid
        \param ysize this will determine the y size of the middle earth grid
        \param numcities determines how many cities will be generated
        \seed is used to generate a random number in the constructor

        This constructor will create string vector that will store a set
        amout of random cities. A random set of x and y coordinates are 
        generated from the xsize and ysize parameters. An array of floats is 
        created and a distance is assigned between every city. 
                
    */
    MiddleEarth (int xsize, int ysize, int numcities, int seed);
    /*! @brief The public destructor of Middle Earth aka Sauron
        The only thing that this destructor will remove is the distances
        array
    */
    ~MiddleEarth();
    /*!@brief A simple print method for the class
      This print method will use standard out. It will output the number of
      cities possible and how many we will generate. It will also output the distances
    */
    void print();
    /*!@brief prints a tab-separated table of the distances
      This will output the distance table(all the distances between all the
      cities. This can be loaded into Excel of similar).
    */
    void printTable();
    /*!@brief Will search the table and return the distance between two cities
       @param city1 the first of two cities
       @param city2 the second of two cities
       @return The distance as a float between the two cities
      The distance is returned by finding the value in the distance table
    
    */ 
    float getDistance (string city1, string city2);
    vector<string> getItinerary(unsigned int length);
};

#endif
