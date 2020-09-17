/*
 * @Auth: lionelzhang
 * @Date: 2020-09-08 15:26:28
 * @LastEditors: lionelzhang
 * @LastEditTime: 2020-09-08 16:09:15
 * @Description: 
 */
#include <vector>
namespace nm_bt{
    enum BT_NODE_TYPE
    {
        btInvalid = 0,

        btSelector,
        btSequencer,
        btParallel,
        btNot,
        btDebug,
        btRollback,
        btRandom,
        btRepeat,

        btUserDefine,

        btTotal = 1024
    };
    struct Node
    {
        int32_t id;
        BT_NODE_TYPE type;
        std::vector<int32_t > param;
        std::vector<Node*> child;
        int32_t cost;
        int32_t grain;
    };
    int32_t calc_grain(Node* node){
        if(!node)return 0;
        int32_t real_grain = node->grain - node->cost;
        switch (node->type)
        {
        case btSelector:
            {
                bool bFind = false;
                int32_t max_child_grain = -0x7fffffff;
                for(auto child: node->child){
                    int32_t child_grain = calc_grain(child);
                    if(child_grain > max_child_grain){
                        max_child_grain = child_grain;
                        bFind = true;
                    }
                }
                if(bFind){
                    real_grain += max_child_grain;
                }
            }  
            break;
        case btSequencer:
        {
            for(auto child: node->child){
                real_grain += calc_grain(child);
            }
            break;
        }
        default:
            break;
        }
        return real_grain;
    }
}