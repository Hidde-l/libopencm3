void ms_delay(unsigned int ms) {
    ms *= 4U;
    while (ms-- > 0U) {
        volatile unsigned int x = 400U;
        while (x-- > 0U) { __asm("nop"); }
    }
}
