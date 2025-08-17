/*
This feels like a graph problem.
If we want, let's say a/c. We know a/b and b/c, we make a/b * b/c, we have a/c.
So it is somewhat like finding a path from a to c.

We need to quickly know if a variable is defined in the list of variables. Hash
map?

We will have to give this a little bit of though.

Ok, graph problem. We need to find a path from a to c.
How do we define each node?
How do we define each edge?
Ok, maybe each node is a variable.
    There's an edge from a to b if (a/b) is defined.
    If so, there's also an edge from b to a. We just invert the result.
    So, for example, a / c -> "is there a path from a to c?"
                     a / b -> "is there a path from a to b?"
    This gives us classic BFS / DFS, with value accumulation.
    I need a quick refresher on this.
    This also give's place to Union-Find. We can quickly say if there's a path
from a to c. But how do we calculate these values then? How do we explore the
graph? Do we construct this graph? Do we make a one pass through the equations
array and build the graph? I think so. We could store the graph as an Adjacency
List.
*/

class Solution {
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>
        graph;
    void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        for (int i = 0; i < equations.size(); i++) {
            vector<string> equation = equations[i];
            string first_var = equation[0];
            string second_var = equation[1];

            double value = values[i];
            graph[first_var].emplace_back(second_var, value);
            graph[second_var].emplace_back(first_var, (1.0 / value));
        }
    }

    double bfs(string start, string end) {
        if (graph.find(start) == graph.end() ||
            graph.find(end) == graph.end()) {
            return -1.0;
        }

        if (start == end) {
            return 1.0;
        }

        std::deque<std::pair<std::string, double>> to_visit;
        to_visit.push_back({start, 1.0});

        std::unordered_set<std::string> visited;
        visited.insert(start);

        while (!to_visit.empty()) {
            std::pair<std::string, double> current = to_visit.front();
            to_visit.pop_front();

            std::string curr_node = current.first;
            double curr_value = current.second;

            for (const auto& neighbor_pair : graph[curr_node]) {
                const std::string& neighbor_node = neighbor_pair.first;
                double neighbor_value = neighbor_pair.second;

                if (visited.find(neighbor_node) == visited.end()) {
                    visited.insert(neighbor_node);
                    double new_value = curr_value * neighbor_value;

                    if (neighbor_node == end) {
                        return new_value;
                    }
                    to_visit.push_back({neighbor_node, new_value});
                }
            }
        }
        return -1.0;
    }

    double dfs(const std::string& start, const std::string& end, double current_value, std::unordered_set<std::string>& visited) {
        if (start == end) {
            return current_value;
        }

        visited.insert(start);

        for (const auto& neighbor_pair : graph[start]) {
            const std::string& neighbor_node = neighbor_pair.first;
            double neighbor_value = neighbor_pair.second;

            if (visited.find(neighbor_node) == visited.end()) {
                double result = dfs(neighbor_node, end, current_value * neighbor_value, visited);
                if (result != -1.0) {
                    return result;
                }
            }
        }
        return -1.0;
    }



public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        buildGraph(equations, values);
        std::vector<double> result;
        for (const auto& query : queries) {
            std::string start = query[0];
            std::string end = query[1];

            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                result.push_back(-1.0);
            } else {
                std::unordered_set<std::string> visited;
                result.push_back(dfs(start, end, 1.0, visited));
            }
        }
        return result;
    }
};
