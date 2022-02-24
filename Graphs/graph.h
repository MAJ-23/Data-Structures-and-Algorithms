#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>
#include <sstream>

using namespace std;

//edits to this are likely not needed
template <class T>
struct Vertex {
  T label; // unique int for a vertex
  vector<T> adj_list;
  int indegree = 0; // Part 2: number of nodes pointing in
  int top_num = 0; // Part 2: topological sorting number
  Vertex(T l) : label(l) {top_num = 0;} //Part 1
  // You may include default constructor optionally.
};

// optional, but probably helpful
// template <class T>
// ostream& operator<<(ostream &o, Vertex<T> v){};

// std::priority_queue may take takes three template parameters: <Type, ContainerType, Functor>
// syntax for custom compare functor follows
// Refer the instructions PDF last section for more information

template<class T>
class VertexCompare
{
public:
  bool operator()(Vertex<T> v1, Vertex<T> v2){
    //todo - implement here
    return v1.top_num > v2.top_num;
  }
};

template <class T>
class Graph {
private:
  //c++ stl hash table
  std::unordered_map< T, Vertex<T> > node_set;

  // alternatively:
  //c++ balanced binary tree (probably red-black but may be compiler dependent)
  // std::map<T, Vertex<T> > node_set;
  //  using this may negatively impact your runtime

  //Use other data fields if needed
public:
  Graph() {};  //No modification needed to default constructor. Can be used optionally if needed.
  ~Graph() {}; //No modification needed to destructor. Can be used optionally if needed.

  // build a graph - refer the instructions PDF for more information.
  void buildGraph(istream &input){
    node_set.clear();//make sure its empty
    string adj_line;

    while(getline(input, adj_line)){
      stringstream sso(adj_line);
      T curr_label;
      sso >> curr_label;
      T root_label;
      root_label = curr_label;
      Vertex<T> node(root_label);//create the vertex with the label in data

      while(sso >> curr_label){
        node.adj_list.push_back(curr_label);
      }//we now have a fully done vertex
      node_set.insert(make_pair(root_label, node));
    }
  }

  // display the graph into o - refer the instructions PDF for more information.
  void displayGraph(ostream& o){
    for (auto &v : node_set){
      o << v.second.label << ':';
      for(unsigned int i = 0; i < v.second.adj_list.size(); i++){
        o << v.second.adj_list.at(i) << ' ';
      }
      o << std::endl;
    }
  }

  //return the vertex at label, else throw any exception  - refer the instructions PDF for more information.
  Vertex<T> at(T label){
    return node_set.at(label);
  }

  //return the graph size (number of verticies)
  int size(void){
    return node_set.size();
  }

  // topological sort
  // return true if successful, false on failure (cycle)
  bool topological_sort(void){
    queue< T > q;
    int counter = 0;

    while(!q.empty()){//make empty 
      q.pop();
    }

    for(auto &v : node_set){//v is a pair 
      if(v.second.indegree == 0){
        q.push(v.first);
      }
    }

    while(!q.empty()){
      T lab = q.front();
      q.pop();
      Vertex<T> & v = node_set.at(lab);

      v.top_num = ++counter;//Assign next number
      

      for(auto &w : v.adj_list){//w is a label
        if(--node_set.at(w).indegree == 0){
          q.push(node_set.at(w).label);
        }
      }
    }
    // for (const auto & pair : node_set){
    //   std::cout << "Node: " << pair.first << ", Topnum: " << pair.second.top_num << std::endl;
    // }
    if(counter != size())
      return false;

    return true;
  }; // Part 2

  // find indegree
  void compute_indegree(void){
    //visit every node
    //at each node go through their adj_list 
    //every node they have an edge to, do indegree++ for that node
    
    for (auto &node : node_set){//visit every node
      for(auto &adj_node : node.second.adj_list){//at each node go through their adj_list
        node_set.at(adj_node).indegree++; //indegree++;
      }
    }
  } // Part 2


  // print topological sort into o
  //  if addNewline is true insert newline into stream
  void print_top_sort(ostream& o, bool addNewline=true)
  { 
    // compute_indegree();
    // vector<T> order(size());

    // for(auto &v : node_set){
    //   order[v.second.top_num] = v.second.label;
    // }

    // for(unsigned int i = 0; i <= order.size(); ++i){
    //   o << order[i] << " ";
    // }

    //priq
    // std::priority_queue<Vertex<T>, vector<Vertex<T> >, [T](Vertex<T> v1, Vertex<T> v2){return v1.top_num > v2.top_num;} > pq;
    auto comp<T> = [](Vertex<T> v1, Vertex<T> v2) { return v1.top_num > v2.top_num; }
    std::priority_queue<Vertex<T>, vector<Vertex<T> >, comp<T>> pq;

    for(auto &v : node_set){
      pq.push(v.second);
    }

    while (!pq.empty()){
      o << pq.top().label << " ";
      pq.pop();
    }


    if(addNewline){o << '\n';};
  }; // Part 2
 };

#endif
