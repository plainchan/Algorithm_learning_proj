#ifndef __CHECKSUM_H__
#define __CHECKSUM_H__



#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdlib.h>



uint8_t simpleChecksum(const uint8_t *buff,const size_t size)
{
    uint16_t check=0;
    for(int i=0;i<size;++i)
    {
        check+=buff[i];
    }

    return !(check>>8+check&0x00FF);

}

uint8_t checksum_8(const uint8_t *buff,const size_t size)
{
    uint16_t check=0;
    for(int i=0;i<size;++i)
    {
        check+=buff[i];
    }

    return !(check>>8+check&0x00FF);

}


#ifdef __cplusplus
}
#endif  /* C */




#endif
