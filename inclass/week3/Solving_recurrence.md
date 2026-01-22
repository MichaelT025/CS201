## Solving Recurrences

### Master Method

For recurrences of the form:

$$
T(n) = aT\left(\frac{n}{b}\right) + f(n)
$$

Let:

$$
c = \log_b(a)
$$

Case 1 (polynomially smaller):

$$
f(n) = O\left(n^{c - \varepsilon}\right)\ \text{for some}\ \varepsilon > 0
\quad \Rightarrow \quad
T(n) = \Theta\left(n^c\right)
$$

Case 2 (same order):

$$
f(n) = \Theta\left(n^c \log^k n\right)\ \text{for some}\ k \ge 0
\quad \Rightarrow \quad
T(n) = \Theta\left(n^c \log^{k+1} n\right)
$$

Case 3 (polynomially larger):

$$
f(n) = \Omega\left(n^{c + \varepsilon}\right)\ \text{for some}\ \varepsilon > 0
\ \text{and}\ a f\left(\frac{n}{b}\right) \le d f(n)\ \text{for some}\ d < 1
\quad \Rightarrow \quad
T(n) = \Theta\left(f(n)\right)
$$

### Quick Examples

$$
T(n) = 2T\left(\frac{n}{2}\right) + n \quad \Rightarrow \quad c = 1,\ f(n) = n \quad \text{(Case 2)} \quad \Rightarrow \quad T(n) = \Theta(n \log n)
$$

$$
T(n) = 4T\left(\frac{n}{2}\right) + n \quad \Rightarrow \quad c = 2,\ f(n) = n \quad \text{(Case 1)} \quad \Rightarrow \quad T(n) = \Theta(n^2)
$$

$$
T(n) = 3T\left(\frac{n}{2}\right) + n^2 \quad \Rightarrow \quad c = \log_2 3,\ f(n) = n^2 \quad \text{(Case 3)} \quad \Rightarrow \quad T(n) = \Theta(n^2)
$$

### Recursion Tree Method

Draw a tree where each node represents the cost of a subproblem.

Steps:

1. Root = cost at top level $f(n)$
2. Each node branches into $a$ children (one per recursive call)
3. Subproblem size shrinks by factor $b$ at each level
4. Sum the cost at each level, then sum across all levels

For $T(n) = aT(n/b) + f(n)$:

$$
\text{Number of levels} = \log_b n + 1
$$

$$
\text{Nodes at level } i = a^i
$$

$$
\text{Subproblem size at level } i = \frac{n}{b^i}
$$

$$
\text{Cost at level } i = a^i \cdot f\left(\frac{n}{b^i}\right)
$$

$$
T(n) = \sum_{i=0}^{\log_b n} a^i \cdot f\left(\frac{n}{b^i}\right)
$$

**Example:** $T(n) = 2T(n/2) + n$

| Level      | Nodes | Size | Cost per node | Level cost |
| ---------- | ----- | ---- | ------------- | ---------- |
| 0          | 1     | n    | n             | n          |
| 1          | 2     | n/2  | n/2           | n          |
| 2          | 4     | n/4  | n/4           | n          |
| ...        | ...   | ...  | ...           | n          |
| $\log_2 n$ | n     | 1    | 1             | n          |

$$
T(n) = n \cdot (\log_2 n + 1) = \Theta(n \log n)
$$

### Substitution (Iteration) Method

Expand the recurrence by repeatedly substituting smaller values until a pattern emerges.

**Example:** $T(n) = 2T(n/2) + n$ with $T(1) = 1$

$$
T(n) = 2T\left(\frac{n}{2}\right) + n
$$

Substitute $T(n/2) = 2T(n/4) + n/2$:

$$
T(n) = 2\left[2T\left(\frac{n}{4}\right) + \frac{n}{2}\right] + n = 4T\left(\frac{n}{4}\right) + n + n
$$

Substitute again:

$$
T(n) = 4\left[2T\left(\frac{n}{8}\right) + \frac{n}{4}\right] + 2n = 8T\left(\frac{n}{8}\right) + n + n + n
$$

**Pattern after $k$ substitutions:**

$$
T(n) = 2^k T\left(\frac{n}{2^k}\right) + kn
$$

The recursion bottoms out when $\frac{n}{2^k} = 1$, i.e., $k = \log_2 n$:

$$
T(n) = 2^{\log_2 n} \cdot T(1) + n \log_2 n = n \cdot 1 + n \log_2 n = \Theta(n \log n)
$$

**Example 2:** $T(n) = T(n-1) + n$ with $T(1) = 1$

$$
T(n) = T(n-1) + n
$$

$$
= T(n-2) + (n-1) + n
$$

$$
= T(n-3) + (n-2) + (n-1) + n
$$

$$
\vdots
$$

$$
= T(1) + 2 + 3 + \cdots + n = 1 + \sum_{i=2}^{n} i = \frac{n(n+1)}{2} = \Theta(n^2)
$$

### Other Methods

- **Akra–Bazzi**: for irregular subproblem sizes (e.g., $T(n) = T(n/3) + T(2n/3) + n$)