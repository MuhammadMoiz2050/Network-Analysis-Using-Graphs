# Network-Analysis-Using-Graphs
This Project utilizes strong Data Structures concepts to analyze the given dataset using Graphs.

In the following project the dataset that I have used is the General Relativity and Quantum Cosmology collaboration network Dataset. The dataset contains relationships of authors that co-authored in papers that were submitted to the General Relativity and Cosmology category. The edges represent that the author(source) co-authored with the other author(destination). Multiple edges for the same author say ‘I’ with a number of co-authors, say ‘J’ represents a sub-graph structure.
Dataset Pattern:

Unordered dataset pattern has been observed. For example, an author A has co-authored a paper of 5 different authors and similarly an author B has co-authored a paper of 12 different authors so we can conclude that no specific arithmetic sequence has been observed rather it is unordered.
Data Structure:

A graph data structure has been made for the data sets to establish a relationship between each node of data. This data structure uses an Adjacency List array that contains a linked list at each index of the array. Every node of the Adjacency list stores the source vertex data and the corresponding linked list stores all the nodes this node has a link to.
Following are the major data-structures used in the project:

1.	Arrays
2.	Linked List
3.	Queues



WHY ARRAYS?

Two dynamically allocated arrays are used to parse the data file and store the values. These arrays are further used to insert the data values into the linked list and the adjacency list. The Adjacency list is an array of pointers. I used each index of the array to store the head of the adjacency list for each node.
The main advantage of an array is that it yields direct memory access instead of traversing the whole data structure (e.g. in case of a linked list).
Whereas Dynamically allocated 2-D arrays are used in our Strongly Connected Component
 
(SCC) algorithm to store the unique values that we had obtained from the intersection of In and Out functions.


WHY LINKED-LIST?

Linked-List are used to create an adjacency list for our graph rather than adjacency matrix because the complexity of matrix is greater than adjacency list which indicates that it consumes more space.
WHY QUEUES?

I used the linked lists implementation of queues. I did not used any kind of STL in my project. Queues were mainly used in BFS traversal of graph. And BFS traversal is used in In and Out algorithm. So, we can say that, our SCC algorithm is mainly dependent on BFS and Queues.


Functions:

In-Out Degree:

This function calculates all the in and out degrees of each node and displays them.

BFS:

This algorithm traverses the graph from left to right and returns all the nodes that have a path with the source node (sent in the algorithm).
SCC:

This algorithm calculates the Strongly Connected Components of the graph and returns the largest SCC as well as a two-dimensional array of all the SCCs in the graph.
SCC uses the IN and Out functions, both of these return respective arrays. A “unique” algorithm runs on the intersection of IN and Out to get the SCCs to return all the distinct elements of the SCC.
 
WCC:
This algorithm calculates the Weakly Connected Components of the graph and returns the largest WCC as well as a two-dimensional array of all the WCCs in the graph.
A “unique” algorithm is used to return all the distinct elements of the WCC.

Both the SCC and WCC use the BFS algorithm, BFS mainly requires the Queue class.
