#pragma once
#include <vector>
#include <utility>

// Base Class
class PrunedLabelingBase {
public:
    virtual ~PrunedLabelingBase(){};
    virtual void createIndex(std::vector<std::vector<int> >&) = 0;
    virtual bool query(int, int) = 0;
    virtual long long indexSize() = 0;
};

// Pruned Landmark Labeling
class RQPrunedLandmarkLabeling : public PrunedLabelingBase {
private:
    std::vector<std::vector<int> > G, rG;
    long long V;
    std::vector<std::vector<int> > reachTo, reachFrom;
    std::vector<int> convTable;
    bool compressedQuery(int, int);

public:
    RQPrunedLandmarkLabeling();
    RQPrunedLandmarkLabeling(std::vector<std::vector<int> >);
    virtual ~RQPrunedLandmarkLabeling();
    virtual void createIndex(std::vector<std::vector<int> >&);
    virtual bool query(int, int);
    long long indexSize();
};

// Pruned Path Labeling
class RQPrunedPathLabeling : public PrunedLabelingBase {
private:
    std::vector<std::vector<int> > G, rG;
    long long V;
    std::vector<std::vector<std::pair<unsigned short, int> > > reachToPath, reachFromPath;
    std::vector<std::vector<int> > reachTo, reachFrom;
    std::vector<int> convTable;
    bool compressedQuery(int, int);
    void getOptimalPath(std::vector<bool>&, std::vector<int>*);

public:
    RQPrunedPathLabeling();
    RQPrunedPathLabeling(std::vector<std::vector<int> >);
    virtual ~RQPrunedPathLabeling();
    virtual void createIndex(std::vector<std::vector<int> >&);
    virtual bool query(int, int);
    long long indexSize();
};

