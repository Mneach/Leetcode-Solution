class Union {
private:
    vector<int> representative;
    vector<int> componentSize;
    int components;

public:
    Union(int n) : components(n), representative(n + 1), componentSize(n + 1, 1) {
        for (int i = 0; i <= n; ++i) {
            representative[i] = i;
        }
    }

    int findRepresentative(int x) {
        if (representative[x] != x) {
            representative[x] = findRepresentative(representative[x]);
        }
        return representative[x];
    }

    int performUnion(int x, int y) {
        int rootX = findRepresentative(x);
        int rootY = findRepresentative(y);

        if (rootX == rootY) {
            return 0;
        }

        if (componentSize[rootX] > componentSize[rootY]) {
            componentSize[rootX] += componentSize[rootY];
            representative[rootY] = rootX;
        } else {
            componentSize[rootY] += componentSize[rootX];
            representative[rootX] = rootY;
        }

        components--;
        return 1;
    }

    bool isConnected() const {
        return components == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Union Alice(n), Bob(n);
        int edgesRequired = 0;

        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                edgesRequired += (Alice.performUnion(edge[1], edge[2]) | Bob.performUnion(edge[1], edge[2]));
            }
        }

        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                edgesRequired += Alice.performUnion(edge[1], edge[2]);
            } else if (edge[0] == 2) {
                edgesRequired += Bob.performUnion(edge[1], edge[2]);
            }
        }

        if (Alice.isConnected() && Bob.isConnected()) {
            return edges.size() - edgesRequired;
        }

        return -1;
    }
};
