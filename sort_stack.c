void sort_stack(t_stack **a, t_stack **b)
{
    int size;

    size = stack_size(*a);

    if (size <= 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    else if (size <= 100)
        bucket_sort(a, b);
    else
        bucket_sort_500(a, b);
}