#include "Header.h"



void main()
{
    setlocale(LC_ALL, "Rus");
    Graph<int> graph({ 1,4,6,3,2,5 });

    graph.add_vertex(1);
    graph.add_vertex(3);
    graph.add_vertex(7);
    //graph.add_vertex(7);
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
    //graph.add_edge(3, 1);
    graph.print_vertex();
    graph.print_graph();
    if (!graph.has_edge(2, 3)) cout << "p,,";
    if (!graph.has_edge(1, 4)) cout << "p,,";
    if (graph.has_edge(2, 7)) cout << "p,,";
    if (graph.has_edge(3, 2)) cout << "p,,";
    auto i = graph.edges(1);
    graph.walk(1);
    /*cout << "(" << 1 << "--->  ";
    for (auto& j : i)
    {
        cout << j.in;
    }
    cout << ")";*/
    graph.trampoint();
    cout << "\nМинимальное расстояние от 1 до 4 = ";
    graph.Algoritm_of_Belman_ford(1, 4);
   
        // построить Graph

        //graph.print_adjacency_matrix();

};
//void print_adjacency_matrix()
 //{
 //    for (int i = 0; i < adjlist.size(); i++)
 //    {
 //        cout << i << " ---> ";// вершину и список смежных с ней
 //        for (int v : adjlist[i]) {
 //            cout << v << " ";
 //        }
 //        cout << endl;
 //    }
 //}
    //bool contain_vertex(int number_of_vertex)
    //{
    //    for (auto& i : vertex)
    //    {
    //        if (i == number_of_vertex) return true;
    //    }
    //    return false;
    //}
    //void add_vertex(const Vertex& v)
    //{
    //    if (!contain_vertex(v))vertex.push_back(v);
    //}
