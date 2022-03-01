// Optimal implementation(Quick Union + Union By Rank + Path Compression)

class UnionFind {
    vector<int> root, rank;
    int nComponents;
    
    public:
    UnionFind(int n) {
        for(int i = 0; i < n; i++) {
            root.push_back(i);
            rank.push_back(1);
        }
        nComponents = n;
    }
    
    int find(int x) {
        if(root[x] == x) return x;
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x, int y) {
        int rx = find(x), ry = find(y);
        if(rx != ry) {
            if(rank[rx] > rank[ry]) root[ry] = rx;
            else if(rank[rx] < rank[ry]) root[rx] = ry;
            else {
                root[ry] = rx;
                rank[rx]++;
            }
            nComponents--;
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    
    int getComponentCount() {
        return nComponents;
    }
};