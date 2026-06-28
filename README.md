*This activity has been created as part of the 42 curriculum by abrezden, oshevche*

# push_swap

## Description

`push_swap` is a 42 algorithm project that sorts a stack of integers using only a limited set of stack operations.

The program receives a list of unique integers, builds stack `a`, and generates the operations needed to sort it in ascending order. Stack `b` is used as a temporary stack during sorting.

Allowed operations:

| Operation           | Description                                             |
| ------------------- | ------------------------------------------------------- |
| `sa`, `sb`, `ss`    | Swap the top elements of stack `a`, stack `b`, or both. |
| `pa`, `pb`          | Push the top element from one stack to the other.       |
| `ra`, `rb`, `rr`    | Rotate stack `a`, stack `b`, or both upward.            |
| `rra`, `rrb`, `rrr` | Reverse rotate stack `a`, stack `b`, or both downward.  |

The project also supports runtime strategy selection and benchmark output.

## Instructions

### Compilation

```sh
make
```

This creates the executable:

```sh
./push_swap
```

Available Makefile rules:

```sh
make all
make clean
make fclean
make re
```

### Basic usage

```sh
./push_swap 2 1 3 6 5 8
```

The program prints one Push_swap operation per line.

If the input is already sorted, the program prints nothing:

```sh
./push_swap 0 1 2 3
```

If no arguments are provided, the program prints nothing:

```sh
./push_swap
```

Invalid input prints `Error` followed by a newline to standard error. Invalid input includes:

* non-numeric arguments;
* duplicate numbers;
* numbers outside the `int` range;
* malformed numbers.

The parser accepts both separate arguments and quoted space-separated arguments:

```sh
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

### Strategy flags

If no strategy flag is provided, adaptive mode is used.

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

Supported strategies:

| Flag         | Strategy                          | Complexity target   |
| ------------ | --------------------------------- | ------------------- |
| `--simple`   | Selection-style min extraction    | `O(n²)`             |
| `--medium`   | Chunk / bucket sorting            | `O(n√n)`            |
| `--complex`  | Binary radix sort                 | `O(n log n)`        |
| `--adaptive` | Disorder-based strategy selection | Depends on disorder |

Flags must be placed before the numbers. `--bench` can be combined with any strategy flag:

```sh
./push_swap --bench --adaptive 4 67 3 87 23
./push_swap --adaptive --bench 4 67 3 87 23
```

### Benchmark mode

Benchmark mode is enabled with `--bench`.

Sorting operations are printed to standard output. Benchmark information is printed to standard error.

```sh
./push_swap --bench --complex 4 67 3 87 23
```

To display only benchmark information:

```sh
./push_swap --bench --complex 4 67 3 87 23 >/dev/null
```

Benchmark output includes:

* disorder percentage;
* selected strategy;
* complexity class;
* total operation count;
* individual counts for all operations.

### Verification with checker

Bash / sh:

```sh
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

Zsh:

```sh
ARG="4 67 3 87 23"
./push_swap ${(z)ARG} | ./checker_linux ${(z)ARG}
```

Fish:

```fish
set ARG 4 67 3 87 23
./push_swap $ARG | ./checker_linux $ARG
```

Expected checker result:

```txt
OK
```

## Algorithm design

### Index compression

Before sorting, the input values are converted to sorted indexes.

Example:

```txt
Input:   40 -2 100 7
Indexes: 2   0  3 1
```

The smallest value receives index `0`, the next value receives index `1`, and so on.

This makes sorting independent from the original integer values and allows radix sort to work on compact non-negative indexes.

### Disorder metric

Adaptive mode uses a disorder metric before any move is generated.

The metric counts inversions: a pair `(i, j)` is disordered if `i < j` and `a[i] > a[j]`.

```txt
disorder = inversion_count / total_pair_count
```

Meaning:

* `0.00` means already sorted;
* `1.00` means reverse sorted;
* values between `0.00` and `1.00` mean partially sorted input.

### Simple strategy: selection-style min extraction — `O(n²)`

The simple strategy repeatedly finds the smallest element in stack `a`, rotates it to the top, and pushes it to stack `b`.

After all elements are moved to `b`, they are pushed back to `a`.

This is simple and predictable, but it can require many scans and rotations. Its operation complexity is `O(n²)`.

### Medium strategy: chunk / bucket sorting — `O(n√n)`

The medium strategy divides the indexed values into chunks.

Elements from the current chunk are pushed from stack `a` to stack `b`. Then the maximum values are moved back from `b` to `a` in sorted order.

Using chunks reduces repeated full-stack extraction and works well for medium-sized or moderately disordered inputs.

Its target operation complexity is `O(n√n)`.

### Complex strategy: binary radix sort — `O(n log n)`

The complex strategy uses LSD binary radix sort on compressed indexes.

For each bit:

1. check the top element of stack `a`;
2. rotate it with `ra` if the bit is `1`;
3. push it to `b` with `pb` if the bit is `0`;
4. push all elements from `b` back to `a`.

Each pass processes all elements once, and the number of passes depends on the number of bits needed for the largest index.

Its target operation complexity is `O(n log n)`.

### Adaptive strategy

Adaptive mode chooses the internal strategy based on disorder:

| Disorder range            | Selected strategy      | Complexity target |
| ------------------------- | ---------------------- | ----------------- |
| `< 0.20`                  | Simple strategy        | `O(n²)`           |
| `0.20 <= disorder < 0.50` | Medium chunk strategy  | `O(n√n)`          |
| `>= 0.50`                 | Complex radix strategy | `O(n log n)`      |

Rationale:

* low disorder means the input is close to sorted, so a simple method is enough;
* medium disorder benefits from chunk-based grouping;
* high disorder is handled by radix sort because it is stable and predictable for large or random inputs.

Space usage is linear. The program stores the two linked-list stacks, benchmark counters, and temporary data for index compression.

## Project structure

```txt
Makefile                     Build rules
push_swap.h                  Shared declarations and structures
main__.c                     Program entry point
parsing.c                    Argument parsing and flag handling
split_args.c                 Splitting quoted arguments
stack_utils.c                Stack helpers and cleanup
disorder.c                   Disorder metric and adaptive choice
bench.c                      Benchmark output and counters
op_push.c                    pa / pb
op_swap.c                    sa / sb / ss
op_rotate.c                  ra / rb / rr
op_reverse_rotate.c          rra / rrb / rrr
alg_simple_sort.c            Simple strategy and small sort
alg_bucket_sort.c            Medium chunk strategy
alg_bucket_sort_functions.c  Bucket helper functions
alg_radix_sort.c             Complex radix strategy
alg_radix_sort_index.c       Index compression helpers
libft/                       Local helper functions
```

## Learner contributions

### abrezden

* Project structure and Makefile setup.
* Stack data structure and stack utility functions.
* Push_swap operation implementation.
* Simple sorting strategy and small-input sorting.
* Benchmark counter integration into operation functions.
* Disorder metric and adaptive strategy selection.

### oshevche

* Argument parsing, strategy flags, and benchmark flag handling.
* Duplicate checks and integer range validation.
* Chunk / bucket sorting implementation.
* Radix sorting and index compression.
* README documentation and checklist review.
* Error handling and cleanup flow.

Both learners understand and can explain the full codebase, including parsing, memory management, operations, benchmark mode, and all sorting strategies.

## Resources

* 42 push_swap subject.
* 42 Norm / Norminette rules.
* C manual pages.
* Big-O notation references.
* Sorting algorithm references: selection sort, bucket sorting, radix sort.
* Local testing with the official 42 checker.

### AI usage

AI assistance was used for README structure, explanation of algorithm complexity.

AI was not used as a final source of truth. All code, tests, benchmark output, and algorithm behavior were reviewed and verified by us.
