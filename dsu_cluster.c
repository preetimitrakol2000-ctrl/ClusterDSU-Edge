#include "dsu_cluster.h"

void initialize_dsu(DSUNode* subset, int count) {
    for (int i = 0; i < count; i++) {
        subset[i].parent = i;
        subset[i].rank = 0;
    }
}

int find_root(DSUNode* subset, int node_id) {
    // Recursive Path Compression optimization step
    if (subset[node_id].parent != node_id) {
        subset[node_id].parent = find_root(subset, subset[node_id].parent);
    }
    return subset[node_id].parent;
}

int merge_subsets(DSUNode* subset, int node_u, int node_v) {
    int root_u = find_root(subset, node_u);
    int root_v = find_root(subset, node_v);

    if (root_u != root_v) {
        // Union by Rank optimization step
        if (subset[root_u].rank < subset[root_v].rank) {
            subset[root_u].parent = root_v;
        } else if (subset[root_u].rank > subset[root_v].rank) {
            subset[root_v].parent = root_u;
        } else {
            subset[root_v].parent = root_u;
            subset[root_u].rank++;
        }
        return 1; // Merge event occurred
    }
    return 0; // Already under the same cluster head
}
