#include <iostream>
#include <stdio.h>
#include <vector>
#include <locale.h>
#include <unordered_map>
#include <queue>

using namespace std;



template<typename Vertex>

class Graph
{
public:
    struct Edge
    {
        Vertex out, in;
        double distance;
        
    };
private:
   
    unordered_map<Vertex, vector<Edge>> data;

public:
    Graph(const vector<Vertex>& v)
    {
        for (auto& i : v)
        {
            add_vertex(i);
        }
    }
    bool has_vertex(const Vertex& v) const
    {
        for (auto& i : data)
        {
            if (v == i.first) return true;
        }
        return false;
    }
    void add_vertex(const Vertex& v)
    {
        if (has_vertex(v)) cout << "\nТакая вершина уже существует\n";
        else
            data.insert({ v, {} });
    }
    bool remove_edge(const Vertex& out, const Vertex& in)
    {
        if (!has_vertex(out) || !has_vertex(in)) return false;
        auto& edges = data.find(out)->second;
        auto it = edges.begin();
        while (it != edges.end()) {
            if (it->out == out and it->in == in)
            {
                it = edges.erase(it);
            }
            else ++it;
        }
        return true;
    }
    bool remove_vertex(const Vertex& v)
    {
        if (!has_vertex(v))
        {
            cout << "\nТакой вершины не существует\n";
            return false;
        }
        else
        {
           
            //просмотреть и удалить  все ребра которые входят в эту вершину
            for (auto& pair : data)
            {
                for (auto& edge : pair.second)
                {
                    if (edge.in == v)
                    {
                        cout<< "удаление";
                        remove_edge(edge.out, v);
                    }
                }
            }
            data.erase(v);
            return true;
        }
    }
    vector<Vertex> vertices() const//возвращаем список вершин
    {
        vector<Vertex> result;
        for (auto& i : data)
        {
            result.push_back(i.first);
        }
        return result;
    }
   
 
    void print_vertex()
    {

        cout << "Вершины" <<"\n";
        for (auto& i : data )
        {
            cout << i.first <<" ";
        }
        cout << endl;
    }

    void add_edge(const Vertex& out, const Vertex& in)
    {
        if (!has_vertex(out)) { add_vertex(out); }
        if (!has_vertex(in)) { add_vertex(in); }
        data.find(out)->second.push_back({ out, in,NULL });
    }
    void add_edge(const Vertex& out, const Vertex& in, const double& dis)
    {
        if (!has_vertex(out)) { add_vertex(out); }
        if (!has_vertex(in)) { add_vertex(in); }
        data.find(out)->second.push_back({ out, in,dis });
    }
    void add_edge(const Edge& edge)
    {
        if (!has_vertex(edge.out)) { add_vertex(edge.out); }
        if (!has_vertex(edge.in)) { add_vertex(edge.in); }
        data.find(edge.out)->second.push_back({edge.out, edge.in,edge.distance });
    }
    void print_graph()
    {
        cout << "Вершина --> (Куда, расстояние)" << "\n";
        for (auto& i : data)
        {
            cout << i.first << " --> ";// << i.second[0].in;
            for (auto& j : i.second)
            {
                if (j.distance!=0)
                {
                    cout << "(" << j.in << "," << j.distance << ")";
                }
                else
                {
                    cout << "(" << j.in << ",None)";
                }
            }
            cout << "\n";
        }
        cout << endl;
    }
  
    bool remove_edge(const Vertex& out, const Vertex& in, const double & dis)
    {
        if (!has_vertex(out) || !has_vertex(in)) return false;
        auto& edges = data.find(out)->second;
        auto it = edges.begin();
        while (it != edges.end()) {
            if (it->out && out && it->in == in && it->distance == dis)
            {
                it = edges.erase(it);
            }
            else ++it;
        }
        return true;
    }
    bool remove_edge(const Edge& edge)
    {
        if (!has_edge(edge)) return false;
        auto& edges = data.find(edge.out)->second;
        auto it = edges.begin();
        while (it != edges.end()) {
            if (it->out == edge.out and it->in == edge.in and it->distance ==edge.distance)
            {
                it = edges.erase(it);
            }
            else ++it;
        }
        return true;
    }
    bool has_edge(const Vertex& out, const Vertex& in) const
    {
      
        for (auto& j : data.find(out)->second)
        {
            if (j.out == out && j.in == in)  return true;
        }
        
        return false;
    }
    bool has_edge(const Edge& edge)
    {
        for (auto& j : data.find(edge.out)->second)
        {
            if (j.out == edge.out && j.in == edge.in && j.distance ==edge.distance)  return true;
        }

        return false;
    }
    vector<Edge> edges(const Vertex& out) const
    {
        if (!has_vertex(out))
        {
            throw logic_error("Нет такой вершины");
        }
        
        return(data.find(out)->second);
    }
    size_t order() const
    {
        return data.size();
    }//порядок
    size_t degree(const Vertex& v) const
    {
        if (!has_vertex(v)) throw invalid_argument("Нет такой вершины!");
        return edges(v).size();
    }//степень
    vector<Vertex>  walk(const Vertex& start_vertex)const 
    {
        vector<Vertex> used;
        used.push_back(start_vertex); // массив использованных
        queue<int> q;
        q.push(start_vertex);
        while (!q.empty()) {
            auto ver = q.front();
            vector<Edge> g = edges(ver);
            q.pop();
            for (int i = 0; i < g.size(); i++) {
                Vertex v = g[i].in;
                bool found = std::find(used.begin(), used.end(), v) != used.end();
                if (!found)
                {
                    used.push_back(v);
                    q.push(v);
                    
                }
            }
        }
        cout << endl;
        for (auto& i : used)
        {
            cout << i<<"\n";
        }
        return used;
    }
    void Algoritm_of_Belman_ford(const Vertex& out, const Vertex& in) const
    {
        if (!has_vertex(out) || !has_vertex(in))throw std::invalid_argument("Вершина не найдена!");
        std::unordered_map<Vertex, double> distance;
        std::unordered_map<Vertex, Edge> ancestors;
        vector<Vertex> path;
        for (auto& item : data)
        {
            distance[item.first] = 100000000000;
            distance[out] = 0;
        }
        
        for (size_t i = 0; i < order() - 1; i++)
        {
            for (const auto& pair : data)
            {
                for (const auto& edge : pair.second)
                {
                    if (distance[edge.out] + edge.distance < distance[edge.in])
                    {
                        distance[edge.in] = distance[edge.out] + edge.distance;
                        ancestors[edge.in] = edge;
                        
                    }
                }
            }
           
        }
        //проверка на отрциательный цикл
        for (auto j : data)
        {
            for (auto& i : j.second)
            {
                if (distance[i.out] + i.distance < distance[i.in])
                {
                    throw logic_error("Ну вы конеечно даааа, отрицательный путь нельзя делать!");
                }
            }
        }
        Vertex current = in;
        while (current != out)
        {
            path.push_back(current);
            current = ancestors[current].out;
        }
        path.push_back(out);
        std::reverse(path.begin(), path.end());
        for (auto& i : path)
        {
            cout << i;
        }   
        cout <<"\nРастояние - "<< distance[in] << "\n";
    }
    void trampoint()
    {
        vector<Vertex> result;
        
        double maximum_of_average_distances = 0;
        
        for (const auto& pair : data)
        {
            double temp = 0;
            int size_vector = pair.second.size();
            for (const auto& edge : pair.second)
            {
                temp += edge.distance;
            }
            temp /= size_vector;
            if (temp >= maximum_of_average_distances) 
            {
                
                if (temp == maximum_of_average_distances)
                {
                    result.push_back(pair.first);
                    
                }
                else 
                {
                    result.clear();
                    result.push_back(pair.first);
                }
                maximum_of_average_distances = temp;
            }
        }
        cout << "Максимальное среднее удаление наблюдается у пунктов --> \n";
        for (auto& i : result)
        {
            cout << i << " ";
        }
    }
};
