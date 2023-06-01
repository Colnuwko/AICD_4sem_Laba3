#include "Header.h"



void main()
{
    setlocale(LC_ALL, "Russian");
    // ,буковки
    /*Graph<char> graph({'a','b','c','d'});
    graph.print_vertex();    
    graph.add_vertex('a');
    graph.print_graph();
    graph.add_edge('a','c', 1);
    graph.add_edge('c', 'b', -3);
    graph.add_edge('b', 'a', -2);
   
    graph.add_edge('c', 'd', 222);
    graph.print_vertex();
    graph.print_graph();
    graph.print_graph();  
    graph.walk('a');
    graph.trampoint();
    cout << "\nМинимальное расстояние от а до д = ";
    graph.Algoritm_of_Belman_ford('a','d');
    graph.print_vertex();
  
    graph.remove_vertex('a');
    
    graph.print_vertex();
    graph.print_graph();*/

    // цифирки
    Graph<int> graph({1,4,6,3,2,5});
    graph.print_vertex();
    graph.add_vertex(1);
    graph.add_vertex(3);
    graph.add_vertex(7);
    //graph.add_vertex();
    graph.print_graph();
    graph.add_edge(1, 2, 1);
    graph.add_edge(1, 6, 1);
    graph.add_edge(2, 3, 1);
    graph.add_edge(2, 4, 3);
    graph.add_edge(2, 5, 4);
    graph.add_edge(3, 4, 10);
    //graph.remove_edge(3, 2);
    //graph.remove_edge(1,4,5);
    graph.add_edge(4, 5, 6);
    graph.add_edge(5, 3, 10);
    graph.add_edge(5, 1, 13);
    graph.add_edge(5, 6, 8);
    graph.add_edge(6, 2, 4);
    graph.add_edge(7, 3, 10);
    graph.add_edge(7, 1, 13);
    graph.add_edge(7, 6, 8);
    graph.add_edge(3, 1);
    graph.print_graph();
    graph.walk(1);
    graph.trampoint();
    cout << "\nМинимальное расстояние от 1 до 4 = ";
    //graph.Algoritm_of_Belman_ford(1, 4);

     if (!graph.has_edge(2, 3)) cout << "p,,";
   if (!graph.has_edge(1, 4)) cout << "p,,";
   if (graph.has_edge(2, 7)) cout << "p,,";
   if (graph.has_edge(3, 2)) cout << "p,,";
       

};

