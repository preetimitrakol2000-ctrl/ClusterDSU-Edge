# ClusterDSU-Edge

An unsupervised geometric clustering subsystem written in pure C99 for power-restricted edge IoT environments. It implements a **Disjoint Set Union (DSU)** structure from scratch to partition distributed sensors into spatial proximity groups, identifying outlying nodes without using memory-heavy machine learning arrays.

## 🧮 Algorithmic & DSA Properties
* **Data Structure:** Disjoint Set Union (DSU) linear mapping array.
* **Optimizations:** Recursive Path Compression and Union by Rank.
* **Time Complexity:** Near-constant $O(\alpha(V))$ processing bounds per node evaluation using the Inverse Ackermann sequence.

## 📦 Compilation & Execution
```bash
gcc main.c dsu_cluster.c distance_matrix.c -o cluster_dsu -lm
./cluster_dsu
