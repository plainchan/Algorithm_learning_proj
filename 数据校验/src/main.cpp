#include "utility.h"
#include "checksum.h"
#include "crc8.h"
#include "crc16.h"
using namespace std;

int main()
{
    uint16_t crc16_ibm_table[256];

    uint8_t *buff = generateRandomBuff(10000); 
    creat_crc16_table(crc16_ibm_table);
    
    printf("crc = 0x%x\n",crc16(buff,10000));
    printf("crc table = 0x%x\n",crc16_lookup(crc16_ibm_table,buff,10000));
  
    // print(buff,100);
    
    free(buff);
}