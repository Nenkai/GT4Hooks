#include "..\GameStructs\Adhoc.h"
#include "..\GameFunctions\Adhoc.h"

void ADHOC_MakeRef(HObject* target, HObject* source)
{
    HObject* tmp = source;
    if (target != &source)
    { 
        if (source) 
            RefCounter_ref((RefCounter*)source); 
    
        if (target->RefPointer.Counter) 
            RefCounter_unref((RefCounter*)target->RefPointer.Counter); 
    
        target->RefPointer.Counter = (RefCounter*)tmp; 
    }
}