long rjd_main()
{
    long sum = 0;

    for(long num = 3; num < 1000; ++num)
    {
        if ( (num % 3 == 0) || (num % 5 == 0) )
            sum += num;
    }
    return sum;
}
