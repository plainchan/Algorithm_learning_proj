#include "utility.h"
#include "checksum.h"
#include "crc8.h"
#include "crc16.h"
using namespace std;

int main()
{
    uint8_t crc8_table[256];

    // uint8_t *buff = generateRandomBuff(10); 
    
    creat_crc8_table(crc8_table);
    
    // printf("crc = 0x%x\n",crc16(buff,10));
    // printf("crc table = 0x%x\n",crc16_lookup(crc16_ibm_table,buff,10000));
    
    print(crc8_table,256);
    // print(buff,10);
    // free(buff);
}