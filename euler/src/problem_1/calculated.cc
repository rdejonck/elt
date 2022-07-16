#define MAXNUM 1000

long sum_multiples(int mult, int max)
{
    long first, last;

    first = mult;
    //last = max - 1;
    //while (last % mult != 0 && last > 0)
    //    --last;
    last = ((max - 1) / mult) * mult;

    return ((first + last) * (last / mult)) / 2;
}

long rjd_main()
{
    long sum;
    sum = sum_multiples(3, MAXNUM) + sum_multiples(5, MAXNUM) - sum_multiples(15, MAXNUM);
    return sum;
}
