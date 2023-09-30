#pragma once

struct sce_stat 
{
    unsigned int    st_mode;      
                                  
    unsigned int    st_attr;      
    unsigned int    st_size;      
    unsigned char   st_ctime[8];  
    unsigned char   st_atime[8];  
    unsigned char   st_mtime[8];  
    unsigned int    st_hisize;    
    unsigned int    st_private[6];
};