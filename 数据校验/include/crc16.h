#ifndef __CRC_16_H__
#define __CRC_16_H__

#include <stdint.h>
#include <stdlib.h>

#define  CRC_POLY_16  0xA001


uint8_t crc16_table[256];






/**
 * NAME：  CRC-16/IBM             校验算法模型名称。 
 * WIDTH： 16                     CRC校验宽度，即CRC比特数。 
 * POLY：  0x8005                 生成项的简写，以16进制表示。
 * INIT：  0                      算法开始时计算（crc）的初始化预置值，十六进制表示。 
 * REFIN：                        要校验的数据，每个字节是否按位反转，True或False。 
 * REFOUT：                       在计算后之后，异或输出之前，整个数据是否按位反转，True或False。 
 * XOROUT：                       计算结果，与此参数异或后，得到输出最终的CRC值。
 */
uint16_t crc16(uint8_t *bytes,uint16_t length)
{
    uint16_t crc=0;
    while(length--)
    {
        crc^=*bytes++;
        for(int i=0;i<8;++i)
        {
            if(crc&0x0001)
                crc = crc>>1^CRC_POLY_16;
            else
                crc>>=1;

        }
    }
    return crc;
}

uint16_t update_crc16(uint8_t *bytes,uint16_t length)
{



}



void creat_crc16_table(uint8_t *table)
{
    for(int i=0;i<256;++i)
    {
        for(int j=0;j<8;++j)
        {
            
        }
    }
}

#endif