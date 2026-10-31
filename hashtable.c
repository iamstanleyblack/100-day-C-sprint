/*
a hash table is  a data structure which offers a fast implementation
of the associative array API. A hash table consists of an array of 'buckets'
each of which stores a key-value pair. In order to locate an integer which is
used as the pair's index in the array of buckets. When we want to retrieve a key-value pair,
we supply the key to the same hashing function, receive its indes, and use the index to find it in the array
Array indexing has algorithmic complexity 0(1), making hash tables fast at storing and retrieving data
Our hash table will map string keys to string values, but the principlals given here are applicable to hash tables which map arbitrary key types to arbitrary value types. Only ASCII strings will be supported, as supporting unicode is non-trivial and out of scope of this tutorial

Associative arrays are a collection of unordered key-value pairs. Duplicate keys re not permitted.
the supported operations are: search(a, k) which returns the value v associated with the key k from the associative array a or NULL if the key does not exist
insert(a, k, v) stores the pair k:v in the associative array a
delete(a, k) deletes teh k:v pair associated with k or do nothing if k does not exist

Associative array : an abtract dsata structure which implements the API described above, also called a map, symbol table, or dictionary
hash table: a fast implementation of the associative array API which makes use of a hash funciton, also called a hash map, map, hash or dictionary

*/
