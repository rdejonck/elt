#include <iostream>

extern long rjd_main();

#define CPUID_RDTSC_ASM \
    asm volatile ("CPUID\n\t" \
                  "RDTSC\n\t" \
                  "mov %%edx, %0\n\t" \
                  "mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::"%rax", "%rbx", "%rcx", "%rdx");

#define RDTSCP_ASM \
    asm volatile ("RDTSCP\n\t" \
                  "mov %%edx, %0\n\t" \
                  "mov %%eax, %1\n\t" \
                  "CPUID\n\t": "=r" (cycles_high1), "=r" (cycles_low1)::"%rax", "%rbx", "%rcx", "%rdx");

int main()
{
    long answer;
    unsigned cycles_low, cycles_high, cycles_low1, cycles_high1;
    uint64_t start, end;

    CPUID_RDTSC_ASM;
    RDTSCP_ASM;
    CPUID_RDTSC_ASM;
    RDTSCP_ASM;

    CPUID_RDTSC_ASM;
    answer = rjd_main();
    RDTSCP_ASM;

    start = ( ((uint64_t) cycles_high << 32) | cycles_low);
    end = ( ((uint64_t) cycles_high1 << 32) | cycles_low1);

    std::cout << answer << "   " << end - start << std::endl;

    return 0;
}
