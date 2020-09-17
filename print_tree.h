#ifndef _PRINT_TREE_H_
#define _PRINT_TREE_H_
#include <string.h>
#include <stdio.h>
#include <memory>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
namespace nm_print_tree
{
    struct NodePosInfo{
        int w ;
        int dep;
        int value;
        bool is_red;
        NodePosInfo(int w_, int dep_, int value_, int is_red_):
        w(w_),
        dep(dep_),
        value(value_),
        is_red(is_red_)
        {
        }
        shared_ptr<NodePosInfo> left;
        shared_ptr<NodePosInfo> right;
    };
    using node_pos_ptr = shared_ptr<NodePosInfo>;
    template<class NODE_TYPE>
    class tree_print{
        using node_ptr = NODE_TYPE*; // std::shared_ptr<NODE_TYPE>;
        using get_node_ptr_func_type = function<node_ptr (node_ptr)>;
        using get_node_key_func_type = function<int (node_ptr)>;
        using get_node_color_func_type = function<int (node_ptr)>;
        public:
        tree_print(
            get_node_ptr_func_type get_left, 
            get_node_ptr_func_type get_right, 
            get_node_key_func_type get_key_value, 
            get_node_color_func_type get_color = nullptr)
        :_get_left_ptr(get_left), _get_right_ptr(get_right), _get_key_value(get_key_value), _get_color_is_red(get_color){

        }
        private:
            get_node_ptr_func_type      _get_left_ptr;
            get_node_ptr_func_type      _get_right_ptr;
            get_node_key_func_type            _get_key_value;
            get_node_color_func_type           _get_color_is_red;
            map<int, vector<node_pos_ptr> > db_; //存储每一层的指针
            map<int, int > db1_; // 存储每一层最后一个
        
        public:
        void print(node_ptr n){
            // 转储到db_
            translate(n);
            // 依据db_进行打印
            for(const auto& it: db_){
                unsigned int idx = 0;
                for(const auto& v: it.second){
                    for(int i = idx+1; i< v->w; i++){
                        printf(" ");
                    }
                    if(v->is_red && _get_color_is_red)
                        printf("\033[31m%d\033[0m", v->value);
                    else
                    {
                        printf("%d", v->value);
                    }
                    
                    idx = v->w;
                    char s_value[128];
                    snprintf(s_value, sizeof(s_value), "%d", v->value);
                    idx += strlen(s_value) -1;
                }
                printf("\n");
                idx = 0;
                for(const auto& v: it.second){
                    if(v->left){
                        for(int i = idx+1; i< v->left->w + 1; i++){
                            printf(" ");
                        }
                        printf("/");
                        idx = v->left->w + 1;
                    }
                    if(v->right){
                        for(int i = idx+1; i< v->right->w - 1 ; i++){
                            printf(" ");
                        }
                        printf("\\");
                        idx = v->right->w - 1;
                    }
                }
                printf("\n");
            }
            db_.clear();
            db1_.clear();
        }
        private:
        void translate(node_ptr n){
            db_.clear();
            db1_.clear();
            loop(n, 0);
        }
        node_pos_ptr loop(node_ptr n, int dep){
            if(!n)return nullptr;
            node_pos_ptr pos = make_shared<NodePosInfo>(0, dep, _get_key_value(n), _get_color_is_red?_get_color_is_red(n):0);
            
            // 先处理子节点，然后根据子节点的位置确定当前节点位置
            pos->left = loop(_get_left_ptr(n), dep + 1);
            pos->right = loop(_get_right_ptr(n), dep + 1);
            if(pos->left && pos->right){
                pos->w = (pos->left->w + pos->right->w)/2;
            }else if(_get_left_ptr(n)){
                pos->w = pos->left->w +2;
            }else if(_get_right_ptr(n)){
                pos->w = pos->right->w -2;
            }
            if(pos->w < 0){
                // 如果当前节点位置小于0 整体右移
                for(auto& it : db_){
                    for(auto& v: it.second){
                        v->w += pos->w;
                    }
                }
                for(auto& it: db1_){
                    it.second += pos->w;
                }
                pos->w = 0;
            }
            
            if(pos->w < db1_[dep]+4){
                // 如果当前节点位置不合理(当前节点位置已经被占用,则当前节点及所有子节点右移)
                tree_pos_move(pos, db1_[dep]+4-pos->w);
            }
            // 更新当前层的最大占用
            db1_[dep] = max(pos->w, db1_[dep]);
            // 存储当前节点
            db_[dep].push_back(pos);
            return pos;
        };    
        void tree_pos_move(node_pos_ptr& node, int r){
            if(!node)return;
            node->w += r;
            // 更新当前层的最大占用
            db1_[node->dep] = max(db1_[node->dep], node->w);
            if(node->left)tree_pos_move(node->left, r);
            if(node->right)tree_pos_move(node->right, r);
        }
    };
}

#endif //_PRINT_TREE_H_