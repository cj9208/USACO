# Complete Search
## Principle
* Keep It Simple, Stupid
* Exploit the brute force, straight-forward, try-them-all method of finding the answer

## Common Algorithms
* DFS (use recursive way to program)
```C++
void DFS(int node, int adj[][]){
    if(visited[node]){ //deal with end case
        return;
    }
    visited[node] = true; //change state
    // do something here
    for(int i = 1; i <= V; i++){ //search for all adjacent nodes
        if(adj[node][i]){
            DFS(i, adj);
        }
    }
}
```
* BFS 
  * use a queue to record the nodes to be visited
  * can be used to find the shortest path
  * Need much space
  * eg : chapter 3.1 stamps
```C++
/*  need another cycle to go through all the connected component */
queue.push_back(source); //start from node source
while(!queue.empty()){
    t = queue.top(); //get first node in the queue
    queue.pop();
    visted[t] = true; //change state
    for(int i = 1; i <= V; i++){
        if(!visited[i] && adj[t][i]){
            queue.push_back(i);
        }
    }
}
```
* DFS + ID (run D depth first searches first, then BFS)


## Optimization
* remove unnecessary search (simple check)
* find efficient way to search
* bit operation(save space & accelerate judge procedure)
