## Hash Table

#### Collision resolution

1. Seperate Chaining
Each bucket is independent, and has some sort of list of entries with the same index. The time for hash table operations is the time to find the bucket (which is constant) plus the time for the list operation.

2. Open Addressing
All entry records are stored in the bucket array itself. When a new entry has to be inserted, the buckets are examined, starting with the hashed-to slot and proceeding in some probe sequence, until an unoccupied slot is found. When searching for an entry, the buckets are scanned in the same sequence, until either the target record is found, or an unused array slot is found, which indicates that there is no such key in the table.

Well-known methods: Linear probing, Quadratic probing, Double hashing

When a hash table is full, we can resize the table to reduce the collisions.


## Oriented Object Programming

#### OOP Features

## Operating System

#### Process and Thread