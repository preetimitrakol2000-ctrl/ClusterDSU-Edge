#include <stdio.h>
#include "dsu_cluster.h"

extern double calculate_euclidean_distance(double x1, double y1, double x2, double y2);

int main() {
    printf("📡 Activating ClusterDSU-Edge Spatial Grouping Kernel...\n\n");

    int total_sensors = 4;
    DSUNode telemetry_subsets[4];
    initialize_dsu(telemetry_subsets, total_sensors);

    // Mock 2D coordinates for physical nodes: Sensor 0, 1, and 2 are tightly packed
    double locations[4][2] = {{1.1, 1.2}, {1.3, 1.1}, {1.2, 1.4}, {9.5, 9.8}};

    double range_limit = 1.0;
    printf("📥 Evaluating Proximal Links (Max Range Threshold = %.1f meters):\n", range_limit);

    for (int i = 0; i < total_sensors; i++) {
        for (int j = i + 1; j < total_sensors; j++) {
            if (calculate_euclidean_distance(locations[i][0], locations[i][1], locations[j][0], locations[j][1]) <= range_limit) {
                if (merge_subsets(telemetry_subsets, i, j)) {
                    printf("   🔗 Associated Node [%d] <---> Node [%d] inside a mutual cluster.\n", i, j);
                }
            }
        }
    }

    printf("\n🔮 Cluster Component Verification:\n");
    if (find_root(telemetry_subsets, 0) == find_root(telemetry_subsets, 2)) {
        printf("   ✅ Node 0 and Node 2 are successfully linked in the same operations pool.\n");
    }
    if (find_root(telemetry_subsets, 0) != find_root(telemetry_subsets, 3)) {
        printf("   🚨 Node 3 categorized as isolated anomaly out-of-bounds component.\n");
    }

    return 0;
}
