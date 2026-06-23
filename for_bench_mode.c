typedef struct s_bench
{
    size_t sa;
    size_t sb;
    size_t ss;
    size_t pa;
    size_t pb;
    size_t ra;
    size_t rb;
    size_t rr;
    size_t rra;
    size_t rrb;
    size_t rrr;
} t_bench;


//operations should increase structures variable
void op_ra(t_stack *a, t_bench *b)
{
    rotate(a);
    if (b)
        b->ra++;
    write(1, "ra\n", 3);
}

// output in stderr - but in our printf
dprintf(2, "Disorder: %.2f%%\n", disorder);
dprintf(2, "Strategy: %s (%s)\n",
        strategy_name,
        complexity);
dprintf(2, "Operations: %zu\n", total);

//strategy choose
if (size <= 5)
    strategy = "Small Sort";
else
    strategy = "Turk Sort";

//dont forget!!!!
if (bench_mode)
    print_benchmark_to_stderr(&bench);