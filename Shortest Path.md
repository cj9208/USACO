# Shortest Path

## Dijkstra Algorithm
* Objection : Find the shortest paths from source vertice to any other vertices

## Floyd-Warshall Algorithm
* Objection : Find the shortest paths between all pairs of vertices
* Complexity :
  * Time :
  * Space : 
* Pseudocode : 
Let dist(i,j) is "best" distance so far from vertex i to vertex j 
'''
For i = 1 to n do
    For j = 1 to n do
        dist(i,j) = weight(i,j) 

For k = 1 to n do	# k is the `intermediate' vertex
    For i = 1 to n do
        For j = 1 to n do
            if (dist(i,k) + dist(k,j) < dist(i,j)) then	# shorter path?
                dist(i,j) = dist(i,k) + dist(k,j)
'''
