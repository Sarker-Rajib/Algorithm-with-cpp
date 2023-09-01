/* Problem Statement:
You have just opened a dish cable business and you want to connect your dish lines in your area.
In your area there are N buldings and E roads.
The roads are two way obviously.
In each road there is a cost of connecting the cables.
You want to connect all buldings in such a way that there is connection from any building to another,
not necessary to be directly.
As you are a businessman, you want the total cost to be minimum.
Can you tell the minimum total cost to do the work?

Note: There can be multiple road from one building to another.
If it is not possible to connect all the building, print -1.

Input Format
First line will contain N and E.
Next E lines will contain A, B and W which means there is a connection in between A and B
where the cost for connecting the cable is W.
Constraints

1 <= N, E <= 10^5
1 <= A, B <= N
1 <= W <= 10^9
Output Format

Output the minimum cost.
Sample Input 0
5 7
1 2 10
1 3 5
3 2 4
2 4 1
3 4 2
4 5 3
1 5 2
Sample Output 0

8
Sample Input 1

3 2
1 2 10
2 1 2
Sample Output 1

-1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge
{
public:
    int u, v, w;

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

const int MAX_N = 1e5 + 5;

int parent[MAX_N];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

bool unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        parent[x] = y;
        return true;
    }
    return false;
}

int main()
{
    int N, E;
    cin >> N >> E;

    vector<Edge> edges;

    for (int i = 0; i < E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back(Edge(a, b, w));
    }

    // Sort the edges in non-decreasing order of weight
    sort(edges.begin(), edges.end());

    // Initialize the parent array for union-find
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    int minCost = 0;
    int connectedComponents = 0;

    for (Edge edge : edges)
    {
        if (unite(edge.u, edge.v))
        {
            minCost += edge.w;
            connectedComponents++;
        }
        if (connectedComponents == N - 1)
        {
            break;
        }
    }

    if (connectedComponents == N - 1)
    {
        cout << minCost << endl;
    }
    else
    {
        cout << "-1" << endl; // It's not possible to connect all buildings
    }

    return 0;
}
