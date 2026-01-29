## Hash functions

- Hash function maps a key to an index in the table.
- Goal: spread keys uniformly across `0..N-1`.

### Example: integer keys

```cpp
int H(int key) {
    return key % N;
}
// N = table size
```

### Example: string keys (polynomial rolling hash)

```cpp
int H(const string& key) {
    int sum = 0;
    for (int j = 0; j < (int)key.length(); j++) {
        sum = (C * sum + int(key[j])) % N; // int(key[j]) = ASCII value
    }
    return sum;
}
// C = constant (commonly a small prime)
```

- Ideally compute `index = H(key)` and access `Table[index]`.
- Collisions can occur when different keys map to the same index:

    `H(key1) = H(key2)` but `key1 != key2`

### Load factor

- `n` = number of stored keys, `N` = table size
- Load factor: `α = n / N`
- Larger `α` generally increases collisions and slows operations.

### Handling Collisions

- **Closed addressing (separate chaining)**: each index stores a collection of items.
    - Typical implementation: linked list (or vector) per slot.
    - Insert is often at the head for `O(1)` insertion.

    **Time per operation (chaining)**

    - **Worst case**: `O(n)` (all keys land in one chain)
    - **Average case**: `O(1 + α)` (expected chain length is about `α`)
    - **Best case**: `O(1)`

- **Open addressing**: each slot holds at most one key/value.
    - Requires `n <= N`.
    - On collision, probe for another slot (linear/quadratic/double hashing).
    - Deletion typically needs a tombstone marker (so searches don’t break early).

#### Linear probing

- Search sequentially (step size 1)

```cpp
for (int j = 0; j < N; j++) {
    look in slot (H(key) + j) % N
}
```

- **Time per operation (open addressing, linear probing)**
    - **Worst case**: `O(n)` (or `O(N)`) when a long cluster forms
    - **Average case**: ~`O(1)` when `α` is kept small
    - **Best case**: `O(1)`
- **Disadvantage**: primary clustering
    - Once a region gets crowded, it tends to keep growing.
    - Becomes noticeable as `α` approaches ~0.5 or higher.

#### Quadratic probing

- Search using squared offsets from the initial slot

```cpp
for (int j = 0; j < N; j++) {
    look in slot (H(key) + j*j) % N
}
```

#### Double hashing

- Use a second hash function to determine the step size
- Probe sequence uses multiples of the secondary hash

```cpp
for (int j = 0; j < N; j++) {
    look in slot (H(key) + j * H2(key)) % N
}
```

- Primary hash: `H(key)`
- Secondary hash: `H2(key)`