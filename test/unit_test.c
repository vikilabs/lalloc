#include <stdio.h>
#include "lalloc.h"
#include "test_util.h"

int main()
{
    lalloc_init();

    size_t local_mem = 0;
    int  *i = (int *)lalloc(sizeof(int));
    local_mem += sizeof(int);

    if(local_mem != GetDynMemoryUsage()){
       TEST_FAIL("alloc int"); 
    }else{
       TEST_PASS("alloc int"); 
    }

    char *j = (char *)lalloc(sizeof(char));
    
    local_mem += sizeof(char);
 
    if(local_mem != GetDynMemoryUsage()){
       TEST_FAIL("alloc char"); 
    }else{
       TEST_PASS("alloc char"); 
    }
   
    float *k = (float *)lalloc(sizeof(float));
    local_mem += sizeof(float);
 
    if(local_mem != GetDynMemoryUsage()){
       TEST_FAIL("alloc float"); 
    }else{
       TEST_PASS("alloc float"); 
    }
 
    LFREE(i);
    
    local_mem -= sizeof(int);

    if(local_mem != GetDynMemoryUsage()){
       TEST_FAIL("free int"); 
    }else{
       TEST_PASS("free int"); 
    }
 
    LFREE(j);
    
    local_mem -= sizeof(char);

    if(local_mem != GetDynMemoryUsage()){
       TEST_FAIL("free char"); 
    }else{
       TEST_PASS("free char"); 
    }
 
    LFREE(k);
    
    local_mem -= sizeof(float);

    if(local_mem != GetDynMemoryUsage()){
       TEST_FAIL("free float"); 
    }else{
       TEST_PASS("free float"); 
    }

    lalloc_destroy();
    return 0;
}
