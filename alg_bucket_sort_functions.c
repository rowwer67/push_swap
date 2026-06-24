int stack_size(t_stack *s)
{
    int n = 0;

    while (s)
    {
        n++;
        s = s->next;
    }
    return (n);
}


int find_max_pos(t_stack *b)
{
    int pos;
    int max_pos;
    int max_idx;

    pos = 0;
    max_pos = 0;
    max_idx = b->index;

    while (b)
    {
        if (b->index > max_idx)
        {
            max_idx = b->index;
            max_pos = pos;
        }
        pos++;
        b = b->next;
    }
    return (max_pos);
}


void move_max_to_top_b(t_stack **b)
{
    int pos;
    int size;

    pos = find_max_pos(*b);
    size = stack_size(*b);

    if (pos <= size / 2)
    {
        while (pos--)
            rb(b);
    }
    else
    {
        pos = size - pos;
        while (pos--)
            rrb(b);
    }
}


int get_chunk_size(int size)
{
    if (size <= 100)
        return (size / 5);
    return (size / 11);
}


