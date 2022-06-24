#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#define INF 999
using namespace std;


struct Node1 {
public:
    int ch;
    Node1* next;
};
class Queue {
public:

    Node1* front = NULL;
    Node1* rear = NULL;


    int Front() {
        if (front != NULL) {
            return front->ch;
        }
    }
    int Rear() {
        if (rear != NULL) {
            return rear->ch;
        }
    }

    bool isEmpty()
    {
        if (front == NULL)
            return true;
        return false;
    } //end

    bool isFull()
    {
        return false;
    } //end isFullQueue

    void enqueue(int word) {
        Node1* newNode = new Node1;
        newNode->ch = word;
        newNode->next = NULL;

        if (front == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = rear->next;
        }

    }

    void deleteQueue() {
        Node1* temp = new Node1;
        if (!isEmpty()) {
            temp = front;
            front = front->next;
            delete temp;
            if (front == NULL)
                rear = NULL;
        }
        else
            cout << "cannot remove from an empty queue" << endl;
    }
    Node1* concatenate(string word, int j) {

        for (int i = 0; i < j; i++)
            enqueue(word[i]);

        return front;
    }
};

class edges {
public:
    int to;
    int from;
    edges() {
        to = 0;
        from = 0;
    }
};

struct node {
public:
    //bool check;
    node* next;
    node* prev;
    int x;
    int in;
    int out;
};

class AdjList {
public:
    node* head = NULL;
    node* last = NULL;
    node* temp = NULL;
    node* current = NULL;
    node* tailCurrent = NULL;
    int value = 0;
    int in = 0;
    int out = 0;
    AdjList() {
        head = temp = NULL;
    }
    void insert(int a, int i, int n) {
        if (i != n) {
            n++;
            head = NULL;
        }
        if (head == NULL) {
            //i = x;
           /* node* temp = new node;
            temp->x = a;
            temp->next = NULL;
            head = temp;
            current = temp;*/
            head = new node;
            head->x = a;
            head->next = NULL;
            head->prev = NULL;
            //head->in = 0;
            //head->out = 0;
            //head->out++;
            current = head;
            return;
            //return head;
        }

        node* temp = new node;
        temp->x = a;
        temp->next = NULL;
        temp->prev = current;
        current->next = temp;
        current = temp;
        last = temp;
        //temp->check = true;
        //temp->in = 0;
        //temp->out = 0;
        //temp->in++;

            /*node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            node* newNode = new node;
            newNode->x = a;
            temp->next = newNode;
            newNode->next = NULL;
            newNode->prev = current;
            temp = newNode;
            newNode->in++;
            current = newNode;
            */
    }
 
  
    bool search(int a) {
        node* Current;
        bool found = false;
        Current = head;
        while (Current != NULL && !found) {
            if (Current->x == a)
                found = true;
            else
                Current = Current->next;
        }
        return found;
    }

    void display() {         //Head points to the node of the left col values e.g 3466
        temp = head;
        while (temp != nullptr) {
            cout << temp->x << "   ";
            temp = temp->next;
        }
    }
    node* returnList() {
        return head;
    }
    void begin() {
        current = head;
    };
    void end() {
        current = NULL;
    };

};


class graph {
public:
    AdjList* ver;
    AdjList* ver1;
    edges* edg;
   
    int n;
    int* sor = new int[5250];//5250
    int* des = new int[28985];//28985
    int* cln = new int[28985];
    int* markSor = new int[5250]{ 0 };//5250
    int* markSink = new int[28985]{ 0 };//28985
 
    graph(int N) {
        n = N;
        ver = new AdjList[n];
        ver1 = new AdjList[n];
        edg = new edges[28980];
        //ver = new list<int>[n];
    }

    void createGraph(string path) {
        edges e;
        ifstream myFile;
        myFile.open(path);
        string line = "";
        string info = "";
        int vertex = 0;
        bool check = false;
 
        int i = -1;
        int j = 0;
        int n = 0;
        int m = 0;
        int j1 = -1;
        int k = 0;
      
        getline(myFile, line);
        getline(myFile, line);
        getline(myFile, line);
        getline(myFile, line);
        line = "";
        while (getline(myFile, line) && j1 != 28988) {
            stringstream ss(line);
            getline(ss, info, '\t');
            while (stoi(info) != vertex) {
                i++;
                m++;
                //x++;
                vertex = stoi(info);
                sor[i] = stoi(info);
               

                ver[i].value = sor[i];

                
            }

            getline(ss, info, '\n');
            des[j] = stoi(info);

            //cln[k] = des[j];

            n = i;


            ver[i].insert(des[j], i, n);
            edg[k].from = sor[i];
            edg[k].to = des[j];
            //checking source nodes
            //for (int m = 0; m < i; m++) {
            //    ver[i].search(des[j]);
            //    if (ver[i].search(des[j]) == true) {
            //        //ver[i].insertDegree(des[j]);
            //        ver[i].current->in++;
            //    }
            //}

            //ver[0];
            //ver[sor[i]].insert(des[j],i, n);
            //i++; 
            k++;
            n = i;
            j++;
            j1++;
        }

        /*int check = 0;
        while (sor[i] != check) {
            i++;
            check = sor[i];
            ver[m].insert(sor[i], des[j1], i, n);
        }
        ver[m].insert(sor[i], des[j1], i, n);*/
        myFile.close();
        /* for (int i = 0; i < 5250; i++)
             return sor[i];
         for (int j = 0; j < 28985; j++)
             return des[j];*/
    }


    void createGraph1(bool undirected,string path) {
        edges e;
        ifstream myFile;
        myFile.open(path);
        string line = "";
        string info = "";
        int vertex = 0;
        bool check = false;

        int i = -1;
        int j = 0;
        int n = 0;
        int m = 0;
        int j1 = -1;
        int k = 0;


        while (getline(myFile, line) && j1 != 28988) {
            stringstream ss(line);
            getline(ss, info, '\t');
            while (stoi(info) != vertex) {
                i++;
                m++;
                //x++;
                vertex = stoi(info);
                sor[i] = stoi(info);
                //cln[k] = sor[i];

                ver1[i].value = sor[i];


            }

            getline(ss, info, '\n');
            des[j] = stoi(info);

           

            n = i;


            ver1[i].insert(des[j], i, n);
            edg[k].from = sor[i];
            edg[k].to = des[j];
            if (check == true) {
                {
                   
                    for (int d = 0; d < 5242; d++) {
                        if (ver1[d].value == des[j])
                            ver1[d].insert(sor[i], i, n);
                    }//for an undirected graph
                }
            }

            k++;
            n = i;
            j++;
            j1++;
        }


        myFile.close();



    }


    void InOutDegree() {
        int inDeg = 0;
        int outDeg = 0;
        for (int i = 0; i < 5242; i++) {
            inDeg = 0;
            outDeg = 0;
            int m = ver[i].value;
            for (int j = 0; j < 28980; j++) {
                if (edg[j].from == m)
                    outDeg++;
                if (edg[j].to == m)
                    inDeg++;

            }
            ver[i].in = inDeg;
            ver[i].out = outDeg;

            cout << " For Vertex: " << ver[i].value << " In-degree: " << ver[i].in << " Out-degree: " << ver[i].out << endl;
        }

    }
    void NODES(string path)
    {
        ifstream myFile;
        myFile.open(path);

        int d;
        string found;
        string nod = "Nodes:", edg = "Edges:";
        while (!myFile.eof()) {
            myFile >> found;
            if (found == nod)
            {
                myFile >> found;
                d = stoi(found);
                break;
            }
        }
        cout << "number of nodes: " << d << endl;
    }
    void EDGES(string path)
    {
        ifstream myFile;
        myFile.open(path);

        int d;
        string found;
        string edg = "Edges:";
        while (!myFile.eof()) {
            myFile >> found;
            if (found == edg)
            {
                myFile >> found;
                d = stoi(found);
                break;
            }
        }
        cout << "number of Edges: " << d << endl;
    }
    void OutDegree() {
        int inDeg = 0;
        int outDeg = 0;
        for (int i = 0; i < 5242; i++) {
            inDeg = 0;
            outDeg = 0;
            int m = ver[i].value;
            for (int j = 0; j < 28980; j++) {
                if (edg[j].from == m)
                    outDeg++;
                if (edg[j].to == m)
                    inDeg++;

            }
            ver[i].in = inDeg;
            ver[i].out = outDeg;

            cout << " For Vertex: " << ver[i].value << " In-degree: " << ver[i].in << endl;
        }
    }
    void InDegree() {
        int inDeg = 0;
        int outDeg = 0;
        for (int i = 0; i < 5242; i++) {
            inDeg = 0;
            outDeg = 0;
            int m = ver[i].value;
            for (int j = 0; j < 28980; j++) {
                if (edg[j].from == m)
                    outDeg++;
                if (edg[j].to == m)
                    inDeg++;

            }
            ver[i].in = inDeg;
            ver[i].out = outDeg;

            cout << " For Vertex: " << ver[i].value << " Out-degree: " << ver[i].out << endl;
        }
    }
    void source() {
        //bool check = false;
        //for (int i = 0; i < 3; i++) { //5250
        //    for (int j = 0; j < 3; j++) { //28985
        //        if (sor[i] == des[j]) {
        //            check = true;
        //            break;
        //        } 
        //    }
        //    if (check == false) {
        //        markSor[i] = sor[i];
        //    }
        //    check = false;
        //}
        //cout << "The Source nodes are: " << endl;
        //for (int i = 0; i < 3; i++) { //5250
        //    cout << markSor[i] << endl;
        //}
        int m = 0;
        for (int i = 0; i < 5242; i++) {
            if (ver[i].in == 0) {
                m = ver[i].value;
                cout << "The Source nodes are: " << m << "   " << endl;
            }
            else {
                m = -1;
            }
        }
        if (m == -1)
            cout << "There are no source nodes in the given data set." << endl;
    }
    void sink() {
        //    bool check = false;
        //    for (int i = 0; i < 3; i++) { //28985
        //        for (int j = 0; j < 3; j++) { //5250
        //           /* if (des[i] != sor[j]) {
        //                markSink[i] = des[i];
        //            }*/
        //             if (des[i] == sor[j]) {
        //                 check = true;
        //                 break;
        //             }
        //            //else {
        //            //    markSink[i] = 1;
        //            //    //break;
        //            //}
        //        }
        //        if (check == false) {
        //            markSink[i] = des[i];
        //        }
        //        check = false;
        //        //cout << markSink[i] << endl;
        //       /* if(check == false)
        //            markSink[i] = des[i];
        //        check = false;*/
        //    }
        //    cout << "The Sink nodes are: " << endl;
        //    for (int i = 0; i < 3; i++) { //28985
        //        cout << markSink[i] << endl;
        //    }
        //}

        int m = 0;
        for (int i = 0; i < 5242; i++) {
            if (ver[i].out == 0) {
                m = ver[i].value;
                cout << "The sink nodes are: " << m << "   " << endl;
            }
            else {
                m = -1;
            }
        }
        if (m == -1)
            cout << "There are no sink nodes in the given data set." << endl;
    }
    void isolated() {
        int m = 0;
        for (int i = 0; i < 5242; i++) {
            if (ver[i].in == 0 && ver[i].out == 0) {
                int m = ver[i].value;
                cout << "The isolated vertices are: " << m << endl;
            }
            else {
                m = -1;
            }
        }
        if (m == -1)
            cout << "There are no isolated vertices in the given data set." << endl;
    }
    void printGraph() {
        //for (int i = 0; i < 28985; i++)
        int count = 0;
        for (int i = 0; i < 5242; i++) {
            //cout <<"Vertex: "<<sor[i]<<"  "<<"Edges: ";
            cout << "Vertex: " << ver[i].value << "  " << "Edges: ";
            ver[i].display();
            count++;
            //ver[sor[i]].display();
            cout << endl;
            //cout << "count: " << count << endl;
        }
        cout << endl;
    }

    int* BFS(AdjList a) {
        int count = 0;
        int i = 0;
        node* temp = NULL;
        //int startNode = a->x;  //a points to head, the value of x for the head node is assigned to the int here
        int startNode = a.value;
        bool visited[28985] = { false };//28985
        //int reachable[28980] = { 0 };
        int* reachable = new int[28980];
        Queue queue;
        visited[startNode] = true;
        queue.enqueue(startNode);
        while (!queue.isEmpty()) {
            int currVertex;
            currVertex = queue.Front();
            //cout << "visited " << currVertex << " " << endl;
            //cout << count++ << endl;
            reachable[i] = currVertex;
            queue.deleteQueue();
            //node* temp = ver[currVertex].returnList(); //Returns the head of the linked list, I need the index of the adjacency list
            for (int i = 0; i < 5242; i++) {
                if (currVertex == ver[i].value)
                    temp = ver[i].returnList();
            }
            //AdjList temp = ver[currVertex];
            while (temp != NULL) {
                int adjVertex = temp->x;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.enqueue(adjVertex);
                }
                temp = temp->next;
            }
            i++;
        }
        //for(int i=0;i<28980;i++)
        return reachable;
    }

    bool found_value(int value, int te[]) {
        for (int i = 0; i < 5242; i++) {
            if (value == te[i]) {
                return true;
            }
        }
        return false;
    }

    int* in(AdjList a) {
        int* in = new int[5242];
        for (int i = 0; i < 5242; i++) {
            if (found_value(a.value, BFS(ver[i])) == true) {
                in[i] = ver[i].value;
                cout << in[i] << endl;
            }
        }
        return in;
    }

    int* Out(AdjList a) {
        int* out = new int[5242];
        int* temp = BFS(a);
        //temp = BFS(a);
        //cout << temp[1] << endl;
        for (int i = 0; i < 5242; i++) {  // BFS gives 4158 values
            out[i] = temp[i];
            cout << out[i] << endl;
        }
        return out;
    }

    int* intersection(AdjList a, AdjList b) {
        int* inArr = in(a);
        int* outArr = Out(b);
        int* common = new int[5242]{ -999 };
        int i = 0;
        int j = 0;
        int k = 0;
        for (int i = 0; i < 5242; i++) {
            for (int j = 0; j < 5242; j++) {
                if (inArr[i] == outArr[j]) {
                    common[k] = inArr[i];
                    k++;
                }
            }
        }
        /*while (i < 5242 && j < 5242) {
            if (inArr[i] < outArr[j])
                i++;
            else if (outArr[j] < inArr[i])
                j++;
            else {
                common[k] = inArr[i];
                k++;
            }
        }    */
        return common;
    }

    /*int** unique(int**scc) {
        int m = 0;
        int n = 0;
        int k = 0;
        int** unique = new int[10000];
        while (m != 5242 && n != 5242) {
            for (int i = 0; i < 5242; i++) {
                for (int j = 0; j < 5242; j++) {
                    if (i != m && j != n) {
                        if (scc[m][n] != scc[i][j])
                            unique[k] = scc[m][n];
                    }
                }
            }
            m++;
            n++;
            k++;
        }
        for (int i = 0; i < 10000;i++)
        cout << unique[i] << endl;
        return unique;
    }*/


    int** SCC(AdjList a) {
        //int(*SCC) [5242] = new (int[5242][5242]);
        //auto* SCC = new int[5242][5242];
        int** SCC = new int* [5242];
        for (int i = 0; i < 5242; i++) {
            SCC[i] = new int[5242];
        }
        int** SCC1 = new int* [5242];
        for (int i = 0; i < 5242; i++) {
            SCC[i] = new int[5242];
        }
        /* for (int m = 0; m < 5242; m++) {
             int *temp = intersection((ver[m]), (ver[m]));*/
        for (int i = 0; i < 5242; i++) {
            int* temp = intersection((ver[i]), (ver[i]));
            for (int j = 0; j < 5242; j++) {
                SCC[i][j] = temp[j];
            }
        }
        cout << SCC << endl;
        //Checking the unique rows
        for (int i = 0; i < 5242; i++) {
            int flag = 0;
            for (int j = 0; j < i; j++) {
                flag = 1;
                for (int k = 0; k < 5242; k++) {
                    if (SCC[i][k] != SCC[j][k])
                        flag = 0;

                    if (flag == 1)
                        break;
                }
            }

            if (flag == 0) {
                for (int j = 0; j < 5242; j++) {
                    SCC1[i][j] = SCC[i][j];
                    cout << SCC1[i][j] << endl;
                }
            }
        }
        //Largest SCC 
        int count = 0;
        int temp = 0;
        int* largest = new int[5242]{ -999 };
        for (int i = 0; i < 5242; i++) {
            for (int j = 0; j < 5242; j++) {
                while (SCC1[i][j] != -999) {
                    temp++;
                    if (count < temp) {
                        count = temp;
                        largest[j] = *SCC1[j];
                    }
                }
            }
        }
        cout << "Largest SCC: " << endl;
        for (int i = 0; i < 5242; i++) {
            cout << largest[i] << "   ";
        }
        return SCC1;
    }

    int** WCC(AdjList a) {
        int** WCC = new int* [5242];
        for (int i = 0; i < 5242; i++) {
            WCC[i] = new int[5242];
        }
        int** WCC1 = new int* [5242];
        for (int i = 0; i < 5242; i++) {
            WCC[i] = new int[5242];
        }
        for (int i = 0; i < 5242; i++) {
            int* temp = BFS(ver[i]);
            for (int j = 0; j < 5242; j++) {
                WCC[i][j] = temp[j];
                //WCC[i] = temp[i];
                cout << WCC[i] << endl;
            }
        }

        //checking unique rows
        for (int i = 0; i < 5242; i++) {
            int flag = 0;
            for (int j = 0; j < i; j++) {
                flag = 1;
                for (int k = 0; k < 5242; k++) {
                    if (WCC[i][k] != WCC[j][k])
                        flag = 0;

                    if (flag == 1)
                        break;
                }
            }

            if (flag == 0) {
                for (int j = 0; j < 5242; j++) {
                    WCC1[i][j] = WCC[i][j];
                    cout << WCC1[i][j] << endl;
                }
            }
        }


        //Largest WCC 
        int count = 0;
        int temp = 0;
        int* largest = new int[5242]{ -999 };
        for (int i = 0; i < 5242; i++) {
            for (int j = 0; j < 5242; j++) {
                while (WCC1[i][j] != -999) {
                    temp++;
                    if (count < temp) {
                        count = temp;
                        largest[j] = *WCC1[j];
                    }
                }
            }
        }
        cout << "Largest WCC: "<< endl;
        for (int i = 0; i < 5242; i++) {
            cout<<largest[i]<< "   ";
        }
        return WCC1;
    }

    int Extractmin(int dist[5250], bool visited[5250])
    {
        int minvalue = INF;
        int minnode = 0;
        for (int i = 0; i < n; i++) //5242
        {
            if (dist[i] < minvalue && !visited[i])
            {
                minvalue = dist[i];
                minnode = i;
            }
        }
        return minnode;
    }


    void shortestPath(AdjList src)
    {
        int x = 5242; //5242
        int dist[5242], parent[5242], cost[5242][5242];
        bool visited[5242] = { false };
        //cout << n << endl;
        for (int i = 0; i < 5242; i++)
        {
            parent[i] = i;
            dist[i] = INF;
        }
        dist[0] = 0;
        Queue obj;

        for (int i = 0, j = 0; i < 5242; i++)
        {
            //int min = obj.deleteQueue();
            int min = Extractmin(dist, visited);
            visited[min] = true;

            /*while (!obj.isEmpty())
            {
                if (visited[j] == false)
                {
                    visited[j] = true;
                    int val = dist[j] + 1;
                    obj.enqueue(val);
                    j++;
                }
            }*/
            for (int i = 0; i < 5242; i++)
            {
                if (cost[min][i] != INF && dist[i] > (dist[min] + cost[min][i]))
                {
                    dist[i] = dist[min] + cost[min][i];
                    parent[i] = min;
                }
            }
            cout << "Node:\t\t\tCost:\t\t\tPath:" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << i << "\t\t\t" << dist[i] << "\t\t\t" << " ";
                cout << i << " ";
                int parnode = parent[i];
                while (parnode != src.value)
                {
                    cout << "<--" << parnode << " ";
                    parnode = parent[parnode];
                }
                cout << endl;
            }
            /*for (int i = 0; i < n; i++)
            {
                if (cost[min][i] != INF && dist[i] > (dist[min] + cost[min][i]))
                {
                    dist[i] = dist[min] + cost[min][i];
                    parent[i] = min;
                }
            }*/
        }
    }

    /*void display(int parent[5250], int dist[5250], AdjList src)
    {
        cout << "Node:\t\t\tCost:\t\t\tPath:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << "\t\t\t" << dist[i] << "\t\t\t" << " ";
            cout << i << " ";
            int parnode = parent[i];
            while (parnode != src)
            {
                cout << "<--" << parnode << " ";
                parnode = parent[parnode];
            }
            cout << endl;
        }
    }*/

    void bridgeEdge(AdjList a) {
        
        int* check = BFS(a);
        int* temp = new int[5242]{ -999 };
        int count = 0;
        int** SCC = new int* [5242]{ 0 };
        for (int i = 0; i < 5242; i++) {
            SCC[i] = new int[5242]{ 0 };
        }
        for (int i = 0; i < 5242; i++) {
            for (int j = 0; j < 5242; j++) {
                temp[j] = *BFS(ver[i]);
                
            }
            if (sizeof temp < 5242) {
                count++;
            }
        }
        cout << "no. of bridge edges: " << count << endl;
    }
};



/*int main() {
    AdjList a;
    AdjList* aa;
    edges e;
    bool undirected = true;
    //a.insert(1);
    graph g(5250);
    graph ug(5242);

    g.createGraph();
    //ug.createGraph1(undirected);
    //ug.printGraph();
    g.InOutDegree();
    //g.printGraph();
    g.source();
    g.sink();
    g.isolated();

    //a=g.ver[0];
    //aa->head;
    //aa = new AdjList;
    //aa = g.ver;   //aa points to the adjacency list created by the graph constructor function
    a = g.ver[0];
    //g.BFS(aa->head);
    //g.BFS(a);
    //g.in(a);
    //g.Out(a);
    //g.SCC(a);
    //g.WCC(a);
    return 0;
}*/

int main()
{
    cout << "                                             Cool menu 2.0" << endl;
    cout << endl;
    int select;
    cout << "Please select the desired data-set for a network analysis: " << endl;
    cout << " 1) General Relativity and Quantum Cosmology" << "\n 2) Astro Physics collaboration network Dataset Description" << "\n 3) Amazon product co-purchasing network and ground-truth communities Dataset Description" << endl;
    cout << "Select data: ";
    cin >> select;

    string path;
    if (select == 1)
        path = "ca-GrQc.txt";
    if (select == 2)
        path = "ca-AstroPh.txt";
    if (select == 3)
        path = "com-amazon.ungraph.txt";

    graph g(5250);
    AdjList a;
    bool undirected = true;
    //g.createGraph1(undirected, path);
    g.createGraph(path);
    a = g.ver[0];
    int option;

    do {
        cout << " 1. Display the number of nodes" << "\n 2. Display the number of edges" << "\n 3. Display the number of source nodes" << "\n 4. Display the number of sink nodes" << "\n 5. Display the number of isolated nodes" << "\n 6. Display the shortest path length distribution" << "\n 7. Display the in-degree distribution in the form of a table" << "\n 8. Display the out-degree distribution in the form of a table" << "9. Display the size of the largest strongly connected component (SCC) & the size distribution of all SCCs " << "\n 10. Display the size of the largest weakly connected component (WCC) & Display the size distribution of all WCCs" << "\n 11.Display the shortest path length distribution  " << "\n 12. Display the no. of bridge edges." << "\n 13. Exit" << "\n select one of the options: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            g.NODES(path);
            break;
        }
        case 2:
        {
            g.EDGES(path);
            break;
        }
        case 3:
        {
            g.InOutDegree();
            g.source();
            break;
        }
        case 4:
        {
            g.InOutDegree();
            g.sink();
            break;
        }
        case 5:
        {
            g.isolated();
            break;
        }
        case 6:
        {
            break;
        }
        case 7:
        {
            //g.InOutDegree();
            g.InDegree();
            break;
        }
        case 8:
        {
           //g.InOutDegree();
            g.OutDegree();
            break;
        }
        case 9:
        {
            g.SCC(a);
            break;
        }
        case 10:
        {
            g.WCC(a);
            break;
        }
        case 11:
        {
            g.shortestPath(a);
            break;
        }
        case 12:
        {
            g.bridgeEdge(a);
            break;
        }
        case 13:
        {
            break;
        }

        }
        cout << endl << "***********************************************************************************" << endl << endl;
    } while (option != 13);
    /* AdjList a;
     AdjList* aa;
     edges e;
     bool undirected = true;
     graph g(5250);
     graph ug(5242);

     g.createGraph();

     a = g.ver[0];

     g.WCC(a);
     return 0;*/
}