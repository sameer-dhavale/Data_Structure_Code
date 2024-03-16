#include <iostream>
using namespace std;

class Graph
{
public:
    int n, e, v1, v2, cost;
    int costMatrix[20][20];
    void create();
    void display();
    void prims();
    Graph()
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                costMatrix[i][j] = 0;
            }
        }
    }
};

void Graph::create()
{
    cout << "Enter Number of Vertices: ";
    cin >> n;
    cout << "Enter Number of Edges: ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter an edge (vertex1 vertex2 cost): ";
        cin >> v1 >> v2 >> cost;
        costMatrix[v1][v2] = cost;
        costMatrix[v2][v1] = cost;
    }
}

void Graph::display()
{
    cout << "The cost matrix is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            cout << costMatrix[i][j] << " ";
        }
    }
    cout << endl;
}

void Graph::prims()
{
    int visited[20];
    int min, src, dest, total = 0;
    int edges = 0;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (costMatrix[i][j] == 0)
                costMatrix[i][j] = 9999;
        }
    }

    cout << "Enter the source vertex: ";
    cin >> src;

    visited[src] = 1;
    while (edges < n - 1)
    {
        min = 9999;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i] == 1 && visited[j] == 0)
                {
                    if (costMatrix[i][j] != -1 && min > costMatrix[i][j])
                    {
                        min = costMatrix[i][j];
                        src = i;
                        dest = j;
                    }
                }
            }
        }
        visited[dest] = 1;
        total = total + min;
        cout << "Edge = " << src << " --- " << dest << " cost " << min << endl;
        edges++;
    }
    cout << "Total cost of minimum spanning tree is " << total << endl;
}

int main()
{
    Graph gph;
    int choice;
    do
    {
        cout << "Welcome To Graph" << endl;
        cout << "1 - Create/Read Graph" << endl;
        cout << "2 - Display Graph / Read" << endl;
        cout << "3 - Prims Method" << endl;
        cout << "4 - Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            gph.create();
            cout << endl;
            break;

        case 2:
            gph.display();
            cout << endl;
            break;

        case 3:
            gph.prims();
            break;
        }
    } while (choice != 4);
    return 0;
}
