//Derek Johnson dej3tc
// 12/2/19

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
/**
 * A node class. This will contain a list of other Verteces that this one
   points towards 
 */
class Vertex
{
  public:
  string name; /**< The string value of the class */
  int indegree; /**< The number of prerequisit classes /Number of edges*/
  vector<Vertex*> adjacencies; /**< All the vertices this one points toward*/
  /**
  An empty constructor
  This constructor takes in no parameters
  */
  Vertex(); 
  /**
  A constructor for Vertex
  @param s the class name 
  */
  Vertex(string s);
};
/**
  The Class to store information for the whole graph.
  This class will contain the methods for ordering and will 
  also hold the list of Vertex in the graph
 */
class Graph
{
  public:
  vector<Vertex*> vertexList; /**< The list of Vertex in the graph*/
  /**
  A constructor
  This constructor is empty
  @todo make a copy constructor
  */
  Graph();
  /**
  Sorts the Verteces using the topsort algorhythm
  Topological Sorting is a linear ordering of vertices such that for every 
  directed edge uv, u comes before v in the ordering. This is not possible
  if the graph is cyclic
  */
  void topsort();
  /**
  Inserts an edge using two Verteces
  @param one the Vertex pointing to the other
  @param two the Vertex being pointed to
  @todo handle the case when one and two are equal
  */
  void insertEdge(Vertex* one, Vertex* two); 
  /**
  Prints the Graph
  Goes through every Vertex in the graph, prints its value and indegree
  and then does this for every node that Vertex points to
  */
  void printGraph();
};
Vertex::Vertex(){
}
Vertex::Vertex(string s){
  name = s;
}

Graph::Graph(){
    
}

void Graph::insertEdge(Vertex* a, Vertex* b){
  bool foundA;
  bool foundB;
  for(int i=0; i < vertexList.size(); i++){
    if (vertexList[i]->name == a->name){
      foundA = true;
      a = vertexList[i];
    }
    if (vertexList[i]->name == b->name){
      foundB = true;
      b = vertexList[i];
    }
    if(foundA && foundB) break;    
  }
  if(!foundA){
    vertexList.push_back(a);
  }
  a->adjacencies.push_back(b);
  b->indegree++;
  if(!foundB) vertexList.push_back(b);
}


void Graph::topsort(){
  queue <Vertex*> myqueue;
  Vertex* v, w;
  for(int i=0; i <vertexList.size(); i++){
    if(vertexList[i]->indegree == 0)
      myqueue.push(vertexList[i]);
  }
  while (!myqueue.empty()){
    v = myqueue.front();
    myqueue.pop();
    cout << v->name << " ";
    for(int j=0; j<v->adjacencies.size(); j++){
      if(--(v->adjacencies[j]->indegree) == 0)
        myqueue.push(v->adjacencies[j]);
    }
  }
}

void Graph::printGraph(){
  for(int i =0; i < vertexList.size(); i++){
    cout << vertexList[i]->name << " (" << vertexList[i]->indegree
      << ") ";
    for(int j=0; j < vertexList[i]->adjacencies.size(); j++){
      cout << " -> " << vertexList[i]->adjacencies[j]->name
       <<" ("<< vertexList[i]->adjacencies[j]->indegree << ") ";
    }
    cout << endl;
  }
}

int main (int argc, char **argv) {
     // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in two strings
    string s1, s2;
    /*!
      @var Graph myGraph 
      This Graph will hold the Vectors and Edges that are read in
      from the input file
    */
    Graph myGraph;
    while(!file.eof()) {
      file >> s1;
      file >> s2;
      if(s1 == "0" && s2 =="0")
        break;
      Vertex* v1 = new Vertex(s1);
      Vertex* v2 = new Vertex(s2);
      myGraph.insertEdge(v1, v2);
    }
//    myGraph.printGraph();
    myGraph.topsort();
    // close the file before exiting
    file.close();
 
}
