/*
 * @Auth: Do not edit
 * @Date: 2020-08-04 15:29:00
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-08-04 15:29:30
 * @Description: 
 */
#include "base.h"
int64_t JumpConsHash(uint64_t&& ullKey, int32_t iNodeNum)
{
    int64_t iCurNode = -1, iNxtNode = 0;
    while ( iNxtNode < iNodeNum )
    {
        iCurNode = iNxtNode;
        ullKey = ullKey * 2862933555777941757ULL + 1;
        iNxtNode = (iCurNode + 1) * (double(1LL << 31) / double((ullKey >> 33) + 1));
    }
    return iCurNode;
}