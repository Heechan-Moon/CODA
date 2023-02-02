# CODA: COunting of Directed HypergrAphlets

These are source codes or the paper under review.

- *CODA* are the algorithms for counting directed hypergraphlets which have two versions.
  - *CODA-E* is a brute-force accurate algorithm.
  - *CODA-A* is an approximate algorithm based on weighted sampling.
- As a baseline, we also propose approximate algorithms *Uniform sampling* and *A2A sampling*.
- *CODA-A* has advantage of time, memory and also accuracy over baselines and *CODA-E*.


## 11 Real-world directed hypergraphs
- For _metabolic_ and _bitcoin_ data, we remove hyperarcs whose tail and head have nonempty intersection. 
- For others, we preprocess each dataset into a directed hypergraph.
- Statistics and reference for each dataset are as follows.

## Running Codes
- Command "bash run.sh".


## Outputs
1. (txt) the count of each directed hypergraphlet whose line is composed of ({index of a directed hypergraphlet},{counts})
2. (csv) time taken for reading and counting 

