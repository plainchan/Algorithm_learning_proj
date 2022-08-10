#ifndef __UTILITY_H__
#define __UTILITY_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>












/**
 * @brief 生成动态数组
 * 
 * @param len 
 * @return uint8_t* 
 */
uint8_t* generateRandomBuff(uint32_t len)
{
	srand(time(NULL));
	uint8_t *buff =(uint8_t *)malloc(len);
	for(int i =0;i<len;++i)
		buff[i]=rand()%256;
	return buff;
}

void print(uint8_t *bytes,uint32_t len)
{
	for(int i =0;i<len;++i)
		printf("%.2x ",bytes[i]);
	printf("\n");
}











#ifdef __cplusplus
}
#endif  /* C */

#endif