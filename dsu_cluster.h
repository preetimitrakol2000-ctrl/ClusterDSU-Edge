#ifndef DSU_CLUSTER_H
#define DSU_CLUSTER_H

typedef struct {
    int parent;
    int rank;
} DSUNode;

void initialize_dsu(DSUNode* subset, int count);
int find_root(DSUNode* subset, int node_id);
int merge_subsets(DSUNode* subset, int node_u, int node_v);

#endif
