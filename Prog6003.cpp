/* 3. Let s and t be 2 vertices of an undirected graph G(V, E). A particle sits at vertex s, and wants to reach vertex t. In first hop it expends 1 unit energy, in second hop 2 units, in 3rd hop 4 units. In general in i-th hop, the particle expends 2^i units of energy. Write a program for the particle to reach t from s, after expending minimum possible energy.*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;

typedef pair<int, pair<int, int> > State; // {current_energy, {node, hops}}

int min_energy_to_reach(const vector<vector<int> >& G, int s, int t) {
    // Priority queue to store {current_energy, {vertex, hops}} -> starts from s with 0 energy and 0 hops
    priority_queue<State, vector<State>, greater<State> > pq;
    pq.push(make_pair(0, make_pair(s, 0))); // Start from s with 0 energy and 0 hops

    // Map to track the minimum energy to reach a node with a certain number of hops
    map<int, map<int, int> > visited; // visited[node][hops] = min_energy

    while (!pq.empty()) {
        State state = pq.top();
        int current_energy = state.first;
        int node = state.second.first;
        int hops = state.second.second;
        pq.pop();

        // If we've reached the target, return the energy used
        if (node == t) {
            return current_energy;
        }

        // If this state is already visited with fewer hops or less energy, skip it
        if (visited[node].count(hops) && visited[node][hops] <= current_energy) {
            continue;
        }

        // Mark this state as visited
        visited[node][hops] = current_energy;

        // Explore all neighbors of the current node
        for (size_t i = 0; i < G[node].size(); ++i) {
            int neighbor = G[node][i];
            int new_hops = hops + 1;
            int energy_cost = current_energy + (1 << new_hops); // 2^new_hops
            pq.push(make_pair(energy_cost, make_pair(neighbor, new_hops)));
        }
    }

    // If we exhaust the queue and don't find a path to t, return -1 (unreachable)
    return -1;
}

int main() {
    // Example graph as an adjacency list
    vector<vector<int> > G;
    G.push_back(vector<int>(1, 1)); // Neighbors of node 0: {1}
    G[0].push_back(2); // Adding neighbor 2 to node 0
    G.push_back(vector<int>(1, 3)); // Neighbors of node 1: {3}
    G.push_back(vector<int>(1, 0)); // Neighbors of node 2: {0}
    G.push_back(vector<int>(1, 2)); // Neighbors of node 3: {2}

    int s = 0;  // Starting node
    int t = 3;  // Target node

    int result = min_energy_to_reach(G, s, t);
    
    if (result != -1) {
        cout << "Minimum energy to reach node " << t << " from node " << s << " is: " << result << endl;
    } else {
        cout << "Node " << t << " is unreachable from node " << s << endl;
    }

    return 0;
}

