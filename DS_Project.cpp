#include <iostream>
#include <fstream>
#include <string>
using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////// DYNAMIC ARRAY  ///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class dynamicClass
{
public:
    T* arr;
    int capacity;
    int current;
public:
    dynamicClass()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    void push_back(T data)
    {
        if (current == capacity)
        {
            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }

    void pop_back()
    {
        current--;
    }
    int size()
    {
        return current;
    }

    T& operator [](const int index)
    {
        if (index >= 0 && index <= current)
        {
            return arr[index];
        }
    }

    int returnIndex(T val)
    {
        for (int i = 0; i < this->current; i++)
        {
            if (this->arr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    bool search(int val)
    {
        for (int i = 0; i < this->current; i++)
        {
            if (val == this->arr[i])
            {
                return true;
            }
        }
        return false;
    }
    
};

dynamicClass <int>D1;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////// STACK /////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class X>
class node2
{
public:
    X Data;
    node2<X>* Next;

public:
    node2(X val)
    {
        this->Data = val;
        this->Next = NULL;
    }
};
template <class X>
class Stack
{
private:
    node2<X>* Top;

public:
    Stack()
    {
        this->Top = NULL;
    }
    bool isEmpty()
    {
        if (this->Top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Push(X val)
    {
        node2<X>* newNode = new node2<X>(val);
        newNode->Next = Top;
        this->Top = newNode;
    }
    void Pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack empty " << std::endl;
            return;
        }
        else
        {
            node2<X>* Temp = this->Top;
            this->Top = Top->Next;
            delete Temp;
        }
    }
    X Peak()
    {
        X T = '1';
        if (isEmpty())
        {
            return T;
        }
        else
        {
            T = this->Top->Data;
            return T;
        }
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////// QUEUE /////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class X>
class node
{
public:
    X data;
    node<X>* Next;
};
template <class X>
class Queue
{
public:
    node<X>* Front;
    node<X>* Rear;

public:
    Queue()
    {
        Front = NULL;
        Rear = NULL;
    }

    // CHECKS IF THE QUEUE IS EMPTY
    bool isEmpty()
    {
        if (Front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(X n)
    {
        node<X>* newNode = new node<X>;
        newNode->data = n;

        newNode->Next = NULL;
        if (Front == NULL && Rear == NULL)
        {
            Front = newNode;
            Rear = newNode;
        }
        else
        {
            Rear->Next = newNode;
            Rear = newNode;
        }
    }

    X pop()
    {
        if (isEmpty())
        {
            std::cout << "The queue is empty .Cannot be dequeued " << std::endl;
        }
        else
        {
            X temp;
            if (this->Front == this->Rear)
            {
                temp = Front->data;
                Front = NULL;
                Rear = NULL;
                return temp;
            }
            else
            {
                node<X>* T = Front;
                temp = Front->data;
                Front = Front->Next;
                delete T;
                return temp;
            }
        }
        return 0;
    }
    int size()
    {
        int s = 0;
        if (isEmpty())
        {
            std::cout << "The queue is empty " << std::endl;
            return s;
        }
        else
        {
            node<char>* T = Front;
            while (T != NULL)
            {
                T = T->Next;
                s = s + 1;
            }
            return s;
        }
    }

    void displayQueue()
    {
        if (this->Front == NULL)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            node<X>* temp = Front;
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->Next;
            }
        }
    }
};

class Node
{
public:
    int data;
    Node* Next;

public:
    ////////////////////////////////////////////////// DEFAULT CONSTRUCTOR ////////////////////////////////////////////////////////
    Node()
    {
        this->data = 0;
        this->Next = NULL;
    }

    ////////////////////////////////////////////////// PARAMETRIZED CONSTRUCTOR ///////////////////////////////////////////////////
    Node(int d)
    {
        this->data = d;
        this->Next = NULL;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// GRAPH IMPLEMENTATION //////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Graph
{
public:
    Node* G1;
    int totalVertices; // Total Vertices
    int totaledges;    // Total Edges
    int filled;

public:
    /////////////////////////////////////////////// Default Constructor ////////////////////////////////////////////////////////////
    Graph()
    {
        this->G1 = NULL;
        this->filled = 0;
        this->totalVertices = 0;
        this->totaledges = 0;
    }

    ////////////////////////////////////////////// PARAMETRIZED CONSTRUCTOR  ///////////////////////////////////////////////////////
    Graph(int Ver, int edg)
    {
        this->totalVertices = Ver;
        this->totaledges = edg;
        this->G1 = new Node[this->totalVertices];
        this->filled = 0;
    }

    int getVertices()
    {
        return this->filled;
    }

    int getEdges()
    {
        return this->totaledges;
    }

    ///////////////////////////////////////////////////// MAKE THE GRAPH  //////////////////////////////////////////////////////////
    void makeGraph(int Ver, int edg)
    {
        this->totalVertices = Ver;
        this->totaledges = edg;
        this->G1 = new Node[this->totalVertices];
        this->filled = 0;
    }

    ///////////////////////////////////////////////////// INSERT AN EDGE  //////////////////////////////////////////////////////////
    void insert(Node* Head, int val)
    {
        if (Head == NULL)
        {
            Head = new Node(val);
        }
        else
        {
            Node* Temp = Head;
            while (Temp->Next != NULL)
            {
                Temp = Temp->Next;
            }
            Temp->Next = new Node(val);
        }
    }

    //////////////////////////////////////////////////// DRAW DIRECTED GRAPH ////////////////////////////////////////////////////////
    void addEdgeDirected(int v1, int v2)
    {
        if (this->filled > 0)
        {
            if (this->G1[this->filled - 1].data != v1)
            {
                this->filled = this->filled + 1;
                this->G1[this->filled - 1].data = v1;
                insert(&this->G1[this->filled - 1], v2);
            }
            else
            {
                insert(&this->G1[this->filled - 1], v2);
            }
        }
        else
        {
            this->filled = this->filled + 1;
            this->G1[this->filled - 1].data = v1;
            insert(&this->G1[this->filled - 1], v2);
        }
    }

    //////////////////////////////////////////////////// DRAW UN-DIRECTED GRAPH /////////////////////////////////////////////////////
    void addEdgeUnDirected(int v1, int v2)
    {
        if (this->filled == 0)
        {
            D1.push_back(v1);
            D1.push_back(v2);

            int val1 = D1.returnIndex(v1);
            int val2 = D1.returnIndex(v2);

            this->filled = this->filled + 1;
            this->G1[this->filled - 1].data = v1;
            insert(&this->G1[this->filled - 1], v2);

            this->filled = this->filled + 1;
            this->G1[this->filled - 1].data = v2;
            insert(&this->G1[this->filled - 1], v1);
        }
        else
        {
            int val1 = D1.returnIndex(v1);
            if (val1 == -1)
            {
                D1.push_back(v1);
                this->filled = this->filled + 1;
                this->G1[this->filled - 1].data = v1;
                insert(&this->G1[this->filled - 1], v2);
            }
            else
            {
                if (!isPresent(&this->G1[val1], v2))
                {
                    insert(&this->G1[val1], v2);
                }
            }

            int val2 = D1.returnIndex(v2);
            if (val2 == -1)
            {
                D1.push_back(v2);
                this->filled = this->filled + 1;
                this->G1[this->filled - 1].data = v2;
                insert(&this->G1[this->filled - 1], v1);
            }
            else
            {
                if (!isPresent(&this->G1[val2], v1))
                {
                    insert(&this->G1[val2], v1);
                }
            }
        }
    }
    
    //////////////////////////////////// RETURNS A TOTAL NUMBER OF EDGES A PARTICULAR VERTEX HAVE ///////////////////////////////////
    int  getEdges(Node* Temp)
    {
        int len = 0;
        while (Temp != NULL)
        {
            len = len + 1;
            Temp = Temp->Next;
        }
        return len;
    }

    /////////////////////////////////////////////// DEPTH FIRST TRAVERSAL //////////////////////////////////////////////////////////
    dynamicClass<int>* DFS(int s)
    {
        dynamicClass<int>* visited = new dynamicClass<int>[this->totalVertices];
        int k = 0;

        Stack<int> S1;
        S1.Push(s);

        visited->push_back(s);

        while (!S1.isEmpty())
        {
            int v = S1.Peak();
            S1.Pop();
            std::cout << "Visited :" << v << std::endl;
            Node* Temp=NULL;
            for (int i = 0; i < this->filled; i++)
            {
                if (v == this->G1[i].data)
                {
                    Temp = this->G1[i].Next;
                    break;
                }
            }

            while (Temp != NULL)
            {
                bool check = false;
                int t2 = Temp->data;
                for (int j = 0; j < k; j++)
                {
                    if (visited->search(t2))
                    {
                        check = true;
                    }
                }
                if (check == false)
                {
                    visited->push_back(t2);
                    k = k + 1;
                    S1.Push(t2);
                }
                Temp = Temp->Next;
            }
        }
        return visited;
    }

    /////////////////////////////////////////////// BREATH FIRST TRAVERSAL //////////////////////////////////////////////////////////
    dynamicClass<int>* BFS(int s)
    {
        dynamicClass<int>* visited = new dynamicClass<int>;     // Dynamic Array Of Visited Elements
        Queue<int> Q1;                                        // Queue
        Q1.push(s);
        visited->push_back(s);

        while (!Q1.isEmpty())
        {
            int v = Q1.pop();
            //std::cout << "Visited : " << v << std::endl;
            Node* Temp = NULL;
            for (int i = 0; i < this->filled; i++)
            {
                if (v == this->G1[i].data)
                {
                    Temp = this->G1[i].Next;
                    break;
                }
            }
            while (Temp != NULL)
            {
                bool check = false;
                int t2 = Temp->data;
                if (visited->search(t2))
                {
                    check = true;
                }
                if (check == false)
                {
                    visited->push_back(t2);
                    Q1.push(t2);
                }
                Temp = Temp->Next;
            }

        }
        return visited;
    }

    //////////////////////////////////////// CHECK IF A PARTICULAR VERTEX HAS ALREADY AN A EDGE /////////////////////////////////////
    bool isPresent(Node* Head, int val)
    {
        Node* Temp = Head;
        while (Temp != NULL)
        {
            if (Temp->data == val)
            {
                return true;
            }
            Temp = Temp->Next;
        }
        return false;
    }
    
    /////////////////////////////////////////// PRINTS A GRAPH ADJENCY LIST ////////////////////////////////////////////////////////
    void printGraph()
    {
        Node* Temp;
        int count = 1;
        for (int i = 0; i < this->filled; i++)
        {
            Temp = &this->G1[i];
            while (Temp != NULL)
            {
                if (count == 1)
                {
                    std::cout << Temp->data << "  : ";
                }
                else
                {
                    std::cout << Temp->data << "->";
                }
                Temp = Temp->Next;
                count = count + 1;
            }
            std::cout << std::endl;
            count = 1;
        }
        cout << endl;
    }

    ///////////////////////////////////////////////// CHECK FOR SINK NODES /////////////////////////////////////////////////////////
    dynamicClass<int>* sinkNodes()
    {
        dynamicClass<int>* SINK = new dynamicClass<int>;
        Node* Temp;
        bool check = false;
        int count = 0;
        for (int i = 0; i < this->totalVertices; i++)
        {
            Temp = this->G1[i].Next;
            while (Temp != NULL)
            {
                for (int j = 0; j < this->totalVertices; j++)
                {
                    if (Temp->data == this->G1[j].data)
                    {
                        check = true;
                        break;
                    }
                }
                if (check == false)
                {
                    SINK->push_back(Temp->data);
                    std::cout << "Sink Node :" << Temp->data << std::endl;
                    count = count + 1;
                }
                check = false;
                Temp = Temp->Next;
            }
        }
        std::cout << "The number of sink nide are " << count << std::endl;;
        return SINK;
    }

    //////////////////////////////////////////////// Out-Degree Distribution  ///////////////////////////////////////////////////// 
    float outdegreeDistribution(int v)
    {
        float total = 0;
        for (int i = 0; i < this->filled; i++)
        {
            int edges = this->getEdges(this->G1[i].Next);
            if (edges == v)
            {
                total = total + 1;
            }
        }
        std::cout << "Answer :" << total / this->totalVertices << std::endl;
        return total / totalVertices;
    }

    //////////////////////////////////////////////// In-degree DistrIbution   /////////////////////////////////////////////////////
    float indegreeDistribution(int v)
    {
        int* indegree = new int[this->filled];
        Node* Temp = NULL;
        int count = 0;
        for (int i = 0; i < this->filled; i++)
        {
            for (int j = 0; j < this->filled; j++)
            {
                Temp = this->G1[j].Next;
                while (Temp != NULL)
                {
                    if (Temp->data == this->G1[i].data)
                    {
                        count = count + 1;
                    }
                    Temp = Temp->Next;
                }
            }
            indegree[i] = count;
            count = 0;
        }
        float total = 0;
        for (int k = 0; k < this->filled; k++)
        {
            if (indegree[k] == v)
            {
                total = total + 1;
            }
        }
        std::cout << "Total :" << total/this->totalVertices << std::endl;

        return total / this->totalVertices;
    }

    ///////////////////////////////////////////////// CHECK FOR SOURCE NODES ///////////////////////////////////////////////////////
    dynamicClass<int>* sourceNodes()
    {
        dynamicClass<int>* SOURCE = new dynamicClass<int>;
        Node* Temp;
        int count = 0;
        bool check = false;
        for (int i = 0; i < this->totalVertices; i++)
        {
            for (int j = 0; j < this->totalVertices; j++)
            {
                Temp = this->G1[j].Next;
                while (Temp != NULL)
                {
                    if (Temp->data == this->G1[i].data)
                    {
                        check = true;
                        break;
                    }
                    Temp = Temp->Next;
                }
                if (check == true)
                {
                    break;
                }
            }
            if (check == false)
            {
                SOURCE->push_back(G1[i].data);
                std::cout << "Source Node " << this->G1[i].data << std::endl;
                count = count + 1;
            }
            check = false;
        }
        std::cout << "The number of source nodes are " << count << std::endl;
        return SOURCE;
    }

    //////////////////////////////////////////////// CHECKS FOR ISOLATED NODES  ////////////////////////////////////////////////////
    void isolatedNodes()
    {
        dynamicClass<int>* SINK = sinkNodes();
        dynamicClass<int>* SOURCE = sourceNodes();
        if (SINK->current == 0 || SOURCE->current == 0)
        {
            std::cout << "No isolated Node" << std::endl;
        }
        else
        {
            std::cout << "The isolated nodes are " << std::endl;
            for (int i = 0; i < SINK->current; i++)
            {
                if (SOURCE->search(SINK->arr[i]))
                {
                    std::cout << SINK->arr[i] << "\t";
                }
            }
        }
    }

    ////////////////////////////////////////////////////// IN-ALGORITHM ////////////////////////////////////////////////////////////
    dynamicClass<int>* inAlgorithm(int s)
    {
        dynamicClass<int>* IN = new dynamicClass<int>;        // Let in be an array

        dynamicClass<int>* Temp;

        for (int i = 0; i < this->filled; i++)                     // for each vertex v in v
        {
            Temp = this->BFS(this->G1[i].data);

            bool check = Temp->search(s);                     // check if s in BFS

            if (check == true)
            {
                IN->push_back(this->G1[i].data);            // if s in bfs IN.add
            }
            delete Temp;
        }
        return IN;                                          // return in
    }

    //////////////////////////////////////////////////// OUT-ALGORITMN /////////////////////////////////////////////////////////////
    dynamicClass<int>* outAlgorithm(int s)
    {
        dynamicClass<int>* OUT;                            // let out be an array
        OUT = BFS(s);
        return OUT;                                        // return out
    }

    ///////////////////////////////////////////// STRONGLY CONNECTED COMPOENENT ////////////////////////////////////////////////////
    Node* StronglyConnectedComponent()
    {
        Node* SSC = new Node[this->filled + 1];
        int k = 0;
        bool move = false;
        for (int i = 0; i < this->filled; i++)
        {
            dynamicClass<int>* IN = this->inAlgorithm(this->G1[i].data);                // IN ARRAY

            dynamicClass<int>* OUT = this->outAlgorithm(this->G1[i].data);              // OUT ARRAY

            // TAKING INTERSECTION OF  THE IN AND OUT ARRAY
            for (int j = 0; j < OUT->current; j++)
            {
                if (IN->search(OUT->arr[j]))
                {
                    if (move == false)
                    {
                        SSC[k].data = OUT->arr[j];
                        move = true;
                    }
                    else
                    {
                        this->insert(&SSC[k], OUT->arr[j]);
                    }
                }
            }
            move = false;
            k = k + 1;
            delete[]IN;
            delete[]OUT;
        }
        SSC[k].data = -1;

        // TAKING UNIQUE OF THE MOST STRONGLY CONNECTED COMPONENTS
        Node* Temp;
        int max_index = 0;
        int max_value = 0;
        for (int i = 0; i < k; i++)
        {
            int x = this->getEdges(&SSC[i]);
            if (x > max_value)
            {
                max_value = x;
                max_index = i;
            }
        }

        std::cout << "---------------------------------------------------------------" << std::endl;
        std::cout << "The most strongly connected component is ";
        Temp = &SSC[max_index];
        while (Temp != NULL)
        {
            std::cout << Temp->data << ",";
            Temp = Temp->Next;
        }
        std::cout << " ----> Length :" << this->getEdges(&SSC[max_index]) << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;


        return SSC;
    }

    //////////////////////////////////////////////// SIZE DISTRIBUTION OF ALL SCC /////////////////////////////////////////////////
    void SizeDistributionOfAllSCC()
    {
        Node* SCC = this->StronglyConnectedComponent();
        std::cout << "The size distribution of all SCC's are :" << std::endl;
        for (int i = 0; SCC[i].data != -1; i++)
        {
            Node* Temp = &SCC[i];
            while (Temp != NULL)
            {
                std::cout << Temp->data << "->";
                Temp = Temp->Next;
            }
            std::cout << " ----> Length :" << this->getEdges(&SCC[i]) << std::endl;
        }
    }

    /////////////////////////////////////////////// WEEKLY CONNECTED COMPONENT  ////////////////////////////////////////////////////
    Node* WeeklyConnectedComponent()
    {
        Node* WCC = new Node[this->filled];
        int k = 0;

        dynamicClass<int>* Temp = new dynamicClass<int>;

        for (int i = 0; i < this->filled; i++)             // for each vertex v in V
        {
            Temp = this->BFS(this->G1[i].data);
            for (int j = 0; j < Temp->current; j++)
            {
                if (j == 0)
                {
                    WCC[k].data = Temp->arr[j];
                }
                else
                {
                    insert(&WCC[k], Temp->arr[j]);
                }
            }
            k = k + 1;
            delete[]Temp;
        }
        WCC[k].data = -1;

        // TAKING UNIQUE OF THE WEEKLY CONNECTED COMPONENTS
        int min_index = 100;
        int min_value = 100;
        for (int i = 0; i < k; i++)
        {
            int x = this->getEdges(&WCC[i]);
            if (x < min_value)
            {
                min_value = x;
                min_index = i;
            }
        }


        std::cout << "---------------------------------------------------------------" << std::endl;
        std::cout << "The most weekly connected component is ";
        Node* Temp2 = &WCC[min_index];
        while (Temp2 != NULL)
        {
            std::cout << Temp2->data << ",";
            Temp2 = Temp2->Next;
        }
        std::cout << " ----> Length :" << this->getEdges(&WCC[min_index]) << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;

        return WCC;
    }

    //////////////////////////////////////////////// SIZE DISTRIBUTION OF ALL WCC //////////////////////////////////////////////////
    void SizeDistributionOfAllWCC()
    {
        Node* WCC = this->WeeklyConnectedComponent();
        std::cout << "The size distribution of all WCC's are :" << std::endl;
        for (int i = 0; WCC[i].data != -1; i++)
        {
            Node* Temp = &WCC[i];
            while (Temp != NULL)
            {
                std::cout << Temp->data << "->";
                Temp = Temp->Next;
            }
            std::cout << " ----> Length :" << this->getEdges(&WCC[i]) << std::endl;
        }
    }

    ///////////////////////////////////////////////// FIND BRIDGE EDGES IN GRAPH ///////////////////////////////////////////////////
    void bridgeEdges()
    {
        dynamicClass<int>* T = this->BFS(this->G1[0].data);
        int total = T->current;
        delete T;

        int** Arr = new int* [this->filled];

        // allocating two dimensional array for saving bridge edges
        for (int k = 0; k < this->filled; k++)
        {
            Arr[k] = new int[2];
        }

        // initializing that array with -1
        for (int j = 0; j < this->filled; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                Arr[j][k] = 0;
            }
        }
        int row = 0;
        int column = 0;

        for (int i = 0; i < this->filled; i++)
        {
            Node* Temp = this->G1[i].Next;
            while (Temp != NULL)
            {
                int original = Temp->data;
                Temp->data = -1;
                std::cout << "Edge :" << this->G1[i].data << " , " << original << std::endl;

                T = BFS(this->G1[i].data);
                if (T->current <= total)
                {
                    Arr[row][column] = this->G1[i].data;
                    column=column+1;

                    Arr[row][column] = original;
                    row=row+1;
                }

                column = 0;
                delete[]T;
                Temp->data = original;
                Temp = Temp->Next;
            }
        }
        std::cout << "The bridge edges are :" << std::endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                std::cout << Arr[i][j] << ",";
            }
            std::cout << std::endl;
        }
    }

    ////////////////////////////////////////////////// CALCULATES SHORTEST PATH ////////////////////////////////////////////////////
    bool Shortest_Path_Find(int s, int dest, int pred[], int dist[])
    {
        dynamicClass<int>* visited = new dynamicClass<int>;     // Dynamic Array Of Visited Elements
        Queue<int> Q1;                                          // Queue
        Q1.push(s);
        visited->push_back(s);

        for (int i = 0; i < this->filled; i++)
        {
            dist[i] = INT_MAX;
            pred[i] = -1;
        }
        dist[s] = 0;

        int l1 = 0;
        int l2 = 0;

        while (!Q1.isEmpty())
        {
            int v = Q1.pop();
            //std::cout << "Visited : " << v << std::endl;
            Node* Temp = NULL;
            for (int i = 0; i < this->filled; i++)
            {
                if (v == this->G1[i].data)
                {
                    Temp = this->G1[i].Next;
                    break;
                }
            }
            while (Temp != NULL)
            {
                bool check = false;
                int t2 = Temp->data;
                if (visited->search(t2))
                {
                    check = true;
                }
                if (check == false)
                {
                    int Vertex = Temp->data;
                    visited->push_back(t2);

                    dist[l1] = dist[l2] + 1;
                    pred[l1] = l2;
                    l1 = l1 + 1;
                    l2 = l2 + 1;

                    if (Temp->data == dest)
                    {
                        return true;
                    }
                    Q1.push(t2);
                }
                Temp = Temp->Next;
            }

        }
        return visited;
    }

    void Give_Shortest_Path(int s, int dest)
    {
        Node* gggg = this->G1;
        int* pred = new int[this->totalVertices];
        int* dist = new int[this->totalVertices];
        if (Shortest_Path_Find(s, dest, pred, dist) == false)
        {
            cout << "Source Node not connected to the Destination" << endl;
            return;
        }
        dynamicClass<int> path;
        int crawl = dest;
        path.push_back(crawl);
        while (pred[crawl] != -1)
        {
            path.push_back(pred[crawl]);
            crawl = pred[crawl];
        }
        cout << "Shortest path length is : "<< dist[dest]<<std::endl;
        cout << "Shortest Path is :";
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }

    }
};
int main()
{

    //================================================= DATA LOADING ====================================================//
    int k = 0;
    Graph G1;              // Graph Object  directed graph
    Graph G2;
    int line = 0;          // Number of lines
    std::string col1;
    std::string col2;

    ifstream obj;
    ifstream obj1;
    obj.open("file3.txt");
    obj1.open("file3.txt");

    getline(obj1, col1);

    while (!obj1.eof())
    {
        /// This condition if for first two lines in the files as they are of no use so we have to neglect them
        if (line < 2)
        {
            std::getline(obj, col1);
        }
        else if (line == 2)
        {
            obj >> col1;
            obj >> col1;
            obj >> col1;   // nodes
            obj >> col2;
            obj >> col2;   // edges

            G1.makeGraph(std::stoi(col1), std::stoi(col2));
            G2.makeGraph(std::stoi(col1), std::stoi(col2));
        }
        else if (line == 3)
        {
            obj >> col1;
            obj >> col1;
            obj >> col1;
        }
        else if (line > 3)
        {
            obj >> col1;                                              // first number read
            obj >> col2;                                              // second number read
            G1.addEdgeDirected(std::stoi(col1), std::stoi(col2));   // add edge between two verticess
            G2.addEdgeUnDirected(std::stoi(col1), std::stoi(col2));
        }
        line = line + 1;
        getline(obj1, col1);
    }
    //=========================================== DATA LOADING =================================================== //

    cout << "===================================================================  " << endl;
    std::cout << "1) Display the number of nodes                                  " << std::endl;
    std::cout << "2) Display the number of edges                                  " << std::endl;
    std::cout << "3) Display the number of source nodes                           " << std::endl;
    std::cout << "4) Display the number of sink nodes                             " << std::endl;
    std::cout << "5) Display the number of isolated nodes                         " << std::endl;
    std::cout << "6) Display the number of bridge edges                           " << std::endl;
    std::cout << "8) Display the shortest length distribution                     " << std::endl;
    std::cout << "10)Display In degree distribution                               " << std::endl;
    std::cout << "11)Display Out degree distribution                              " << std::endl;
    std::cout << "12)Display the size of the largest strongly connected component " << std::endl;
    std::cout << "13)Display the size distribution of all SCC's                   " << std::endl;
    std::cout << "14)Display the size of the largest weekly connected component   " << std::endl;
    std::cout << "15)Display the size distribution of all WCC's                   " << std::endl;
    std::cout << "16)Print the Graph Directed                                     " << std::endl;
    std::cout << "17)Print the graph Undirected                                   " << std::endl;
    std::cout << "================================================================  " << std::endl;
    int choice = 0;

    int source = 0;
    int destination = 0;

    std::cout << "CHOICE :";
    std::cin >> choice;
    switch (choice)
    {
    case 1:

        std::cout<<"The total number of nodes are :"<<G1.getVertices()<<std::endl;
        break;

    case 2:

        std::cout << "The total number of edges  are :" << G1.getEdges() << std::endl;
        break;

    case 3:
        G1.sourceNodes();
        break;

    case 4:
        G1.sinkNodes();
        break;

    case 5:
        G1.isolatedNodes();
        break;

    case 6:
        G2.bridgeEdges();                          // undirected  graph
        break;

    case 8:
        std::cout << "Enter the source " << std::endl;
        std::cin >> source;

        std::cout << "Enter the destination " << std::endl;
        std::cin >> destination;

        std::cout << std::endl;
        G2.Give_Shortest_Path(source,destination);         // undirected graph 
        break;

    case 10:
        std::cout << "Enter the value for which you want to check indegree distribution " << std::endl;
        std::cin >> source;
        G1.indegreeDistribution(source);
        break;

    case 11:
        std::cout << "Enter the value for which you want to check their outdegree distribution " << std::endl;
        std::cin >> source;
        G1.outdegreeDistribution(source);
        break;


    case 12:
        G1.StronglyConnectedComponent();
        break;

    case 13:
        G1.SizeDistributionOfAllSCC();
        break;

    case 14:
        G2.WeeklyConnectedComponent();                 // undirected graph
        break;

    case 15:
        G2.SizeDistributionOfAllWCC();                // undirected graph
        break;

    case 16:
        G1.printGraph();
        break;
    case 17:

        G2.printGraph();
        break;
    }
}
