# push_swap

> **42 Kocaeli** — A sorting algorithm project using two stacks and a limited set of operations.

---

## About

**push_swap** sorts a stack of integers using two stacks (`a` and `b`) and a restricted set of operations, printing the sequence of moves to standard output. The goal is to sort with as few operations as possible.

---

## Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the top 2 elements of stack **a** |
| `sb` | Swap the top 2 elements of stack **b** |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of stack **b** to top of stack **a** |
| `pb` | Push top of stack **a** to top of stack **b** |
| `ra` | Rotate stack **a** upward (first element becomes last) |
| `rb` | Rotate stack **b** upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack **a** (last element becomes first) |
| `rrb` | Reverse rotate stack **b** |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Usage

```bash
make
./push_swap [numbers]
```

### Examples

```bash
./push_swap 5 4 3 2 1
./push_swap "5 4 3 2 1"
./push_swap 42 7 -3 100 0
```

If the input is already sorted or only 1 number is given, the program outputs nothing.

---

## Error Handling

The program writes `Error\n` to stderr and exits with status `1` if:
- A non-integer argument is given
- A number exceeds `INT_MAX` or is below `INT_MIN`
- Duplicate values are present

---

## Algorithms

The program selects an algorithm adaptively based on input size and disorder level:

| Strategy | Trigger | Complexity |
|----------|---------|------------|
| **Simple** (selection sort) | `--simple` flag or small disorder | O(n²) |
| **Chunk sort** | `--medium` flag or medium disorder | O(n √n) |
| **Radix sort** (LSD, index-based) | `--complex` flag or high disorder | O(n log n) |
| **Adaptive** *(default)* | Auto-selects based on disorder metric | varies |

### Size shortcuts
- **2 elements** → single swap if needed
- **3 elements** → direct 3-element sort (≤ 2 operations)
- **≤ 5 elements** → sort\_5 using push to b + sort\_3 + push back

---

## Optional Flags

These flags can be placed **before** the list of numbers:

```bash
./push_swap --simple  5 4 3 2 1    # Force simple sort
./push_swap --medium  5 4 3 2 1    # Force chunk sort
./push_swap --complex 5 4 3 2 1    # Force radix sort
./push_swap --adaptive 5 4 3 2 1   # Force adaptive (default)
./push_swap --bench   5 4 3 2 1    # Print benchmark info to stderr
```

---

## Benchmark Output (--bench)

```
[bench] disorder: 87.50%
[bench] strategy: Adaptive (O(n log n))
[bench] total_ops: 1032
[bench] sa:12
[bench] pa:256 pb:256
[bench] ra:178 rb:145
[bench] rra:87 rrb:98
```

---

## Performance Targets

| Input size | Target (pass) | Target (full score) |
|-----------|--------------|---------------------|
| 3 numbers | ≤ 3 ops | ≤ 3 ops |
| 5 numbers | ≤ 12 ops | ≤ 12 ops |
| 100 numbers | ≤ 1500 ops | ≤ 700 ops |
| 500 numbers | ≤ 11500 ops | ≤ 5500 ops |

---

## File Structure

```
.
├── Makefile
├── push_swap.h          # Header: types, prototypes
├── main.c               # Entry point, argument handling
├── parsing.c            # Flag parsing, ft_strncmp
├── counter.c            # init_stack, counter_init, free_stack
├── lnklst.c             # Linked list: new_node, add_back, lst_size
├── utils1.c             # isnumber, ft_atol, is_sorted, has_duplicate
├── index.c              # assign_index (coordinate compression)
├── adaptive.c           # adaptive_sort, sort_3
├── algorithm.c          # compute_disorder, simple_sort
├── chunk.c              # chunk_sort
├── radix.c              # radix_sort (LSD bit-by-bit)
├── sort_small.c         # sort_5
├── simple_short.c       # find_min, get_pos
├── swap_a.c             # sa
├── swap_b.c             # sb, ss
├── push_a.c             # pa
├── push_b.c             # pb
├── rotate_a.c           # ra
├── rotate_b.c           # rb
├── rotate_both.c        # rr, rrr
├── reverse_rotate_a.c   # rra
├── reverse_rotate_b.c   # rrb
├── bench.c              # Output helpers: put_str, put_nbr, put_double_percent
├── write.c              # Benchmark printing functions
├── ft_split.c           # ft_split
└── ft_calloc.c          # ft_calloc
```

---

## Build

```bash
make        # Build push_swap
make clean  # Remove object files
make fclean # Remove objects + binary
make re     # Full rebuild
```

---

## Author

**aberdal** — aberdal@student.42kocaeli.com.tr
