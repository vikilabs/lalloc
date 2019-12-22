## Threadsafe malloc wrapper 

 This library implements thread safe malloc with locks. It also tracks the total dyamic memory used by the executing program. 

APIs:

    1. void lalloc_init()           : Initialize the thread safe alloc module
    2. void lalloc_destroy()        : Destroy the thread safe alloc module
    3. void *lalloc(size_t size)    : Allocate threadsafe memory of size "size" and return the pointer to the memory. 
                                      ( Internally lalloc uses calloc ) 
    4. void lfree(void *mem)        : Frees memory threadsafe. 
    5. size_t GetDynMemoryUsage()   : Get the total dynamic memory used by the current program.





