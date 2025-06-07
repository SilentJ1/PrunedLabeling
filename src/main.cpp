#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <sys/time.h>
#include "PrunedLabeling.h"

using namespace std;

const int numQueries = 1000000;

double getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.;
}

// returns (Adjacency List, (|V|, |E|))
pair<vector<vector<int> >, pair<int, int> > readGraph(string& filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        exit(1);
    }
    string line;
    int V, E;
    f >> V >> E;

    vector<vector<int> > G(V);

    for (int i = 0; i < V; i++) {
        int count;
        f >> count;
        f >> count;
        G[i].resize(count);
        for (int j = 0; j < count; j++) {
            f >> G[i][j];
        }
    }
    f.close();
    return make_pair(G, make_pair(V, E));
}

void fun(string g_file, string q_file){
    pair<vector<vector<int> >, pair<int, int> > G = readGraph(g_file);
    vector<vector<int> > adj = G.first;
    int V = G.second.first, E = G.second.second;
    double startTime, endTime;

    cout << "|V| = " << V << ", |E| = " << E << endl << endl; 
    cout << "Constructing Index ... " << flush;

    startTime = getTime();

    PrunedLabelingBase* rq = new RQPrunedPathLabeling(adj);

    endTime = getTime();

    cout << "DONE" << endl << endl;
    cout << "Indexing Time: " << (endTime - startTime)*1000 << " ms" << endl;
    cout<< "Index Size: " << (rq->indexSize()) / 1024 /1024 << " MB" << endl << endl;


    cout << "Querying times " << flush;
    ifstream f(q_file);
    if (!f.is_open()) {
        std::cerr << "Failed to open file: " << q_file << std::endl;
        exit(1);
    }

    vector<pair<int, int>> queries;
    string line;
    while (getline(f, line)) {
        istringstream iss(line);
        int s, t;
        if (iss >> s >> t) {
            queries.emplace_back(s, t);
        }
    }
    f.close();

    int positiveQuery = 0;
    startTime = getTime();
    for (const auto& query : queries) {
        int s = query.first;
        int t = query.second;
        if (rq->query(s, t)) {
            positiveQuery++;
        }
    }
    endTime = getTime();

    cout << "DONE" << endl << endl;
    cout << "Total Query Time " << (endTime - startTime)*1000 << " ms" << endl;
    cout << "#PositiveQuery: " << positiveQuery << endl;
}
int main() {
    string graph_file = "/home/xxx/workspace/data/graph_data/10go-uniprot.txt";
    string query_file = "/home/xxx/workspace/data/50query/10go-uniprot.txt-50";
    fun(graph_file, query_file);
    return 0;
}