# Shortest Path

## Dijkstra Algorithm
* Objection : Find the shortest paths from source vertex to any other vertices
* Complexity :
 * Time : O(V^2)
 * Space : requires the adjacency matrix form of the graph
* Ideas : greedy + BFS
* Pseudocode :
 * distance(j) is distance from source vertex to vertex j
 * parent(j) is the vertex that precedes vertex j in any shortest path
```
For all nodes i
distance(i) = infinity         	# not reachable yet
  visited(i) = False
  parent(i) = nil	# no path to vertex yet 

distance(source) = 0	# source -> source is start of all paths
parent(source) = nil
while (nodesvisited < graphsize)
  find unvisited vertex with min distance to source; call it vertex i
  assert (distance(i) != infinity, "Graph is not connected") 

visited(i) = True	# mark vertex i as visited 

# update distances of neighbors of i
For all neighbors j of vertex i
  if distance(i) + weight(i,j) < distance(j) then
  distance(j) = distance(i) + weight(i,j)
  parent(j) = i
```

## Floyd-Warshall Algorithm
* Objection : Find the shortest paths between all pairs of vertices
* Complexity :
  * Time : O(V^3)
  * Space : requires the adjacency matrix form of the graph
* Pseudocode : 
 * dist(i,j) is "best" distance so far from vertex i to vertex j 
 * The magic point is that it only need one iteration
```
For i = 1 to n do
    For j = 1 to n do
        dist(i,j) = weight(i,j) 

For k = 1 to n do	# k is the `intermediate' vertex
    For i = 1 to n do
        For j = 1 to n do
            if (dist(i,k) + dist(k,j) < dist(i,j)) then	# shorter path?
                dist(i,j) = dist(i,k) + dist(k,j)
```

## Shortest Path Faster Algorithm (SPFA)
