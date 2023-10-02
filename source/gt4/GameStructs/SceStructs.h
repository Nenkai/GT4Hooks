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

typedef struct
{
	unsigned char Resv2,Sec,Min,Hour;
	unsigned char Day,Month;
	unsigned short Year;
} sceMcStDateTime;

typedef struct
{
	sceMcStDateTime _Create;
	sceMcStDateTime _Modify;
	unsigned int FileSizeByte;
	unsigned short AttrFile;
	unsigned short Reserve1;
	unsigned int Reserve2;
	unsigned int PdaAplNo;
	unsigned char EntryName[32];
} sceMcTblGetDir __attribute__((aligned (64)));