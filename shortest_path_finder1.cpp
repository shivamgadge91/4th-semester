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

    // Finds the shortest path using Dijkstra's algorithm
    void shortestPath(int source, int destination)
    {
        int dist[MAX];       // Shortest known distance from source
        int visited[MAX];    // Marks locations already processed
        int parent[MAX];     // Stores previous location in the path

        // Initialize all locations
        for (int i = 0; i < n; i++)
        {
            dist[i] = INF;     // Initially, distance is unknown
            visited[i] = 0;    // No location is visited
            parent[i] = -1;    // No previous location
        }

        dist[source] = 0;      // Distance from source to itself is zero

        // Process each location
        for (int count = 0; count < n; count++)
        {
            int u = -1;
            int minDist = INF;

            // Find the unvisited location with minimum distance
            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && dist[i] < minDist)
                {
                    minDist = dist[i];
                    u = i;
                }
            }

            // Stop if no reachable location remains
            if (u == -1)
                break;

            visited[u] = 1; // Mark the selected location as visited

            // Check all roads from the selected location
            for (int v = 0; v < n; v++)
            {
                // Update distance if a shorter route is found
                if (!visited[v] && cost[u][v] != INF &&
                    dist[u] + cost[u][v] < dist[v])
                {
                    dist[v] = dist[u] + cost[u][v];
                    parent[v] = u; // Store the previous location
                }
            }
        }

        // Check whether the destination can be reached
        if (dist[destination] == INF)
        {
            cout << "No path exists.\n";
            return;
        }

        int path[MAX]; // Stores the shortest path in reverse order
        int length = 0;
        int current = destination;

        // Trace the path backwards using the parent array
        while (current != -1)
        {
            path[length++] = current;
            current = parent[current];
        }

        // Display the path in the correct order
        cout << "Shortest Path: ";
        for (int i = length - 1; i >= 0; i--)
        {
            cout << path[i];

            if (i > 0)
                cout << " -> ";
        }

        // Display the total shortest distance
        cout << "\nTotal Distance: "
             << dist[destination] << endl;
    }
};

int main()
{
    // Create a graph containing four locations
    Graph g(4);

    // Add roads and their distances
    g.addRoad(0, 1, 10);
    g.addRoad(0, 2, 3);
    g.addRoad(2, 1, 2);
    g.addRoad(1, 3, 4);

    int source, destination;

    // Take source and destination from the user
    cout << "Locations are numbered 0 to 3.\n";
    cout << "Enter source location: ";
    cin >> source;

    cout << "Enter destination location: ";
    cin >> destination;

    // Validate the entered location numbers
    if (source < 0 || source >= 4 ||
        destination < 0 || destination >= 4)
    {
        cout << "Invalid location number.\n";
        return 0;
    }

    // Find and display the shortest path
    g.shortestPath(source, destination);

    return 0; 
}

/*PS D:\Piyush Hase> cd "d:\Piyush Hase\" ; if ($?) { g++ shortest_path_finder.cpp -o shortest_path_finder } ; if ($?) { .\shortest_path_finder }
Locations are numbered 0 to 3.
Enter source location: 0
Enter destination location: 3
Shortest Path: 0 -> 2 -> 1 -> 3
Total Distance: 9

PS D:\Piyush Hase> cd "d:\Piyush Hase\" ; if ($?) { g++ shortest_path_finder.cpp -o shortest_path_finder } ; if ($?) { .\shortest_path_finder }
Locations are numbered 0 to 3.
Enter source location: 1
Enter destination location: 2
Shortest Path: 1 -> 2
Total Distance: 2*/