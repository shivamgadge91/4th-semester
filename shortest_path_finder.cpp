#include <iostream>   
using namespace std;

#define MAX 10        // Maximum number of locations
#define INF 9999       // Represents no direct road

class Graph
{
    int cost[MAX][MAX]; // Stores distances between locations
    int n;              // Number of locations

public:
    // Constructor: Initializes the graph
    Graph(int vertices)
    {
        n = vertices;

        // Initially, no roads exist between different locations
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    cost[i][j] = 0;    // Distance to itself
                else
                    cost[i][j] = INF;  // No direct road
            }
        }
    }

    // Adds a road between two locations
    void addRoad(int u, int v, int distance)
    {
        cost[u][v] = distance; // Road from u to v
        cost[v][u] = distance; // Road from v to u
    }

    