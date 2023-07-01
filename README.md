# CODA: COunting of Directed HypergrAphlets

These are source codes or the paper under review.

- **CODA** are algorithms for counting directed hypergraphlets which have two versions.
  - **CODA-E** is a brute-force accurate algorithm.
  - **CODA-A** is an approximate algorithm based on weighted sampling.
- As baselines, we also propose approximate algorithms **D-MoCHy** and **A2A sampling**.
  - **D-MoCHy** is a direct extension of MoCHy-A+, the most advanced algorithm presented in "Hypergraph Motifs: Concepts, Algorithms, and Discoveries (Geon Lee, VLDB'20)" in that both methods involve uniformly sampling a pair of incident hyperedges using a projected graph.
  - **A2A sampling** is an approximate algorithm that samples a single hyperarc $e$ from $E$ uniformly at random first, and then another incident hyperarc $e^′ ∈ N_e$ uniformly at random.
- **CODA-A** has the advantage of time, memory, and accuracy over baselines and **CODA-E**.


## 11 Real-world directed hypergraphs
- Statistics and references for each dataset are as follows.
- |V| and |E| are the number of nodes and hyperarcs, respectively.
- We provide processed data with *.txt* files.

|datas | \|V\| | \|E\| | reference |
|---|---:|---:|---|
| metabolic_iAF1260b | 1668 | 2064 |https://drive.google.com/file/d/1z7XwXo5ohTudUTjyS4KfQbqwze24Ry-o/view|
| metabolic_iJO1366 | 1805  | 2233 |https://drive.google.com/file/d/1z7XwXo5ohTudUTjyS4KfQbqwze24Ry-o/view|
| email_enron | 110 | 1447 |https://andrewmellor.co.uk/data/ah-enron|
| email_eu | 986  | 34485 |http://snap.stanford.edu/data/|
|citation_data_science | 46646| 38144 |https://www.aminer.org/citation|
|citation_software | 94886 | 115617 |https://www.aminer.org/citation|
| qna_math | 34635  |  83425 |https://archive.org/details/stackexchange|
| qna_server | 163508  | 238838 |https://archive.org/details/stackexchange|
| bitcoin_2014 | 1697625  | 1164119 |https://drive.google.com/drive/folders/1B2NCxU_T7Sl_tYVaXDn55GY3-iYGVAbJ|
| bitcoin_2015 | 1961886  | 1237599 |https://drive.google.com/drive/folders/1B2NCxU_T7Sl_tYVaXDn55GY3-iYGVAbJ|
| bitcoin_2016 | 2009978  | 1293604 |https://drive.google.com/drive/folders/1B2NCxU_T7Sl_tYVaXDn55GY3-iYGVAbJ|

## Running Codes
- Command "bash src/run.sh".
  - *datas* is the list of data that are counted.
  - *version* is the list of counting algorithms.
  - *fs* is the list of fractions *q* where the number of samples becomes *n=q|E|*.
  - *try* is the number of iterations in counting. 
```
<example>
datas="citation_data_science citation_software email_enron email_eu metabolic_iAF1260b metabolic_iJO1366 qna_math qna_server bitcoin_2014 bitcoin_2015 bitcoin_2016"
versions="CODAE CODAA A2A Uniform" 
fs="10"
try=3
```


## Outputs
1. (txt) the count of each directed hypergraphlet whose line is composed of ({index of a directed hypergraphlet},{counts})
2. (csv) time taken for reading and counting 


## (Additional Contents)
- We provide a code implemented with C++ for obtaining triad census.
- command "bash triad/run.sh".

