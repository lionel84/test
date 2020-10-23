// 待排数据使用shared_ptr传入 内部node使用shared_ptr
// 主要性能开销来自于node操作过程（旋转）中 shared_ptr的计数维护
#ifndef _RANK_TREE_V3_H_
#define _RANK_TREE_V3_H_

//#define RANK_TREE_DEBUG 

#ifdef RANK_TREE_DEBUG
#include "print_tree.h"
#endif
#include <memory>
#include <unordered_map>

namespace nm_rank_tree_v3 {

template<typename rank_data_value_t>
class KEY_COMP
{
    using comp_function_t = std::function<bool (const rank_data_value_t& l, const rank_data_value_t& r) >;
public:    
    KEY_COMP(comp_function_t comp, bool descending_order = true):_comp_function(comp), is_descending_order(descending_order) 
    {
    
    }
    bool operator()(const rank_data_value_t& a, const rank_data_value_t& b) const
    {
        bool result;
        result = _comp_function(a, b);
        if(is_descending_order){
            return !result;
        }
        return result;
    }
private:
    bool is_descending_order;
    comp_function_t _comp_function;
};

template <typename rank_data_key_t, typename rank_data_value_t, typename comp_t = std::less<rank_data_value_t>  > 
class rank_tree {
public:
    using rank_data_type = std::shared_ptr<rank_data_value_t>;
    using pointer = rank_data_type;
    using const_pointer = const rank_data_type;
    using reference = rank_data_type&;
    using const_reference = const rank_data_type&;
    using rank_t = int64_t;

public:
    // node类型
    struct node
    {
        public:
        using pointer_t = std::shared_ptr<node> ; 
        static const uint32_t red = 0;
        static const uint32_t black = 1;
        node():parent(nullptr), size(1), color(red) 
        {
            children[0] = nullptr;
            children[1] = nullptr;
        }
        
        pointer_t children[2];
        pointer_t parent;
        rank_t size;
        uint32_t color;
        rank_data_type value;
        void construct()
        {
            new(this) node;
        }

        static bool is_red(pointer_t n)
        {
            return n && n->color == red;
        }

        static bool is_black(pointer_t n)
        {
            return n && n->color == black;
        }

        static uint32_t dir(pointer_t p, pointer_t c)
        {
            return c == p->children[1];
        }

        static void update_size(pointer_t h)
        {
            rank_t size = 1;
            if (h->children[0])
            {
                size += h->children[0]->size;
            }
            if (h->children[1])
            {
                size += h->children[1]->size;
            }
            h->size = size;
        }

        static void update_size_to_root(pointer_t h)
        {
            while (h)
            {
                node::update_size(h);
                h = h->parent;
            }
        }

        static pointer_t rotate(pointer_t h, uint32_t dir)
        {
            uint32_t opp_dir = !dir;
            pointer_t x = h->children[opp_dir];
            h->children[opp_dir] = x->children[dir];
            x->children[dir] = h;
            std::swap(x->color, h->color);
            pointer_t parent = h->parent;
            if (parent)
            {
                uint32_t pdir = node::dir(parent, h);
                parent->children[pdir] = x;
            }
            x->parent = parent;
            h->parent = x;
            if (h->children[opp_dir])
            {
                h->children[opp_dir]->parent = h;
            }

            node::update_size(h);
            node::update_size(x);
            return x;
        }

        static pointer_t rotate_left(pointer_t h)
        {
            return node::rotate(h, 0);
        }

        static pointer_t rotate_right(pointer_t h)
        {
            return node::rotate(h, 1);
        }

        static void color_flip(pointer_t h)
        {
            h->color = !h->color;
            h->children[0]->color = !h->children[0]->color;
            h->children[1]->color = !h->children[1]->color;
        }

        static pointer_t spine(pointer_t h, uint32_t dir)
        {
            if (!h)
            {
                return h;
            }
            while (h->children[dir])
            {
                h = h->children[dir];
            }
            return h;
        }

        static pointer_t move_pointer(pointer_t h, uint32_t dir)
        {
            uint32_t opp_dir = !dir;
            if (!h)
            {
                return h;
            }
            else if (h->children[dir])
            {
                return node::spine(h->children[dir], opp_dir);
            }
            else
            {
                while (h->parent)
                {
                    if (node::dir(h->parent, h) == opp_dir)
                    {
                        return h->parent;
                    }
                    h = h->parent;
                }
                return nullptr;
            }
        }
    };

    using data_allocator_t = std::allocator<node>;
    using node_pointer_t = std::shared_ptr<node> ; 

    using map_t = std::unordered_map<rank_data_key_t, node_pointer_t>;

    static node_pointer_t minimum(node_pointer_t h)
    {
        return node::spine(h, 0);
    }

    static node_pointer_t maximum(node_pointer_t h)
    {
        return node::spine(h, 1);
    }

    static node_pointer_t prev(node_pointer_t h)
    {
        return node::move_pointer(h, 0);
    }

    static node_pointer_t next(node_pointer_t h)
    {
        return node::move_pointer(h, 1);
    }
public:

    class iterator
    {
    public:
        iterator(node_pointer_t p):m_p(p){}
        iterator():m_p(nullptr){}
        iterator operator--()
        {
            m_p = prev(m_p);
            return *this;
        }
        iterator operator++()
        {
            m_p = next(m_p);
            return *this;
        }
        iterator operator--(int)
        {
            iterator tmp = *this;
            --*this;
            return tmp;
        }
        iterator operator++(int)
        {
            iterator tmp = *this;
            ++*this;
            return tmp;
        }
        reference operator*()
        {
            return m_p->value;
        }
        pointer operator->()
        {
            return pointer(&(m_p->value));
        }
        bool operator==(iterator other) const
        {
            return m_p == other.m_p;
        }
        bool operator !=(iterator other) const
        {
            return !(*this == other);
        }
    private:
        node_pointer_t m_p;
        friend class rank_tree;
    };

    rank_tree():m_root(nullptr), m_comp()
    {

    }

    rank_tree(comp_t comp): m_root(nullptr), m_comp(comp) {

    }

    rank_tree(const rank_tree& rbtree):m_root(nullptr), m_comp(rbtree.m_comp)
    {
    }

    ~rank_tree()
    {
        clear(m_root);
    }

    rank_tree& operator = (const rank_tree& o)
    {
        if(&o == this)
            return *this;
        clear(m_root);
        m_root = nullptr;
        m_comp = o.m_comp;
        return *this;
    }

    rank_t rank(iterator i) const
    {
        return __rank(i.m_p);
    }
    
    iterator    find_by_rank(rank_t r) const
    {
        node_pointer_t p = __find_by_rank(r);
        return iterator(p);
    }

    iterator find_by_key(rank_data_key_t key) const
    {
        auto p = m_data.find(key);
        return p != m_data.end()?iterator(p->second): iterator();
    }

    rank_t rank_by_key(rank_data_key_t key) const
    {
        iterator it = find_by_key(key);
        if(it.m_p){
            return rank(it);
        }
        return -1;
    }

    iterator insert(const_reference v)
    {
        auto it = m_data.find(v->key());
        if(it != m_data.end()){
            return it->second;
        }
        
        node_pointer_t p = __insert(v);
        if(p != nullptr){
            m_data.insert(std::make_pair(v->key(), p));
        }
        return iterator(p); 
    }

    void erase(iterator i)
    {
        if(i.m_p){
            const auto& it = m_data.find(i.m_p->value->key());
            if(it != m_data.end()){
                m_data.erase(it);
            }
            __erase(i.m_p);
        }
    }

    iterator lower_bound(const key_t& k)
    {
        return iterator(__lower_bound(k, m_comp));
    }

    iterator upper_bound(const key_t& k)
    {
        return iterator(__upper_bound(k, m_comp));
    }

    rank_t size() const
    {
        return m_root ? m_root->size : 0;
    }

    iterator begin()
    {
        return iterator(minimum(m_root));
    }

    iterator last()
    {
        return iterator(maximum(m_root));
    }

    iterator end()
    {
        return iterator();
    }

private:

    node_pointer_t __lower_bound(const key_t& k, comp_t comp)
    {
        node_pointer_t n = m_root;
        node_pointer_t p = nullptr;
        while (n)
        {
            if(comp(n->value.second, k))
                // k > root, so root as left, turn right 
                n = n->children[1];
            else
            {
                // k <= root, so root as right, turn left, and cache root
                p = n;
                n = n->children[0]; 
            }
        }
        return p;
    }

    node_pointer_t __upper_bound(const key_t& k, comp_t comp)
    {
        // invariant left <= key < right
        node_pointer_t n = m_root;
        node_pointer_t p = nullptr;
        while (n)
        {
            if(comp(k, n->value))
            {
                p = n;
                n = n->children[0];
            }
            else
                n = n->children[1]; 
        }
        return p;
    }


    rank_t __rank(node_pointer_t n) const
    {
        // the reverse process of __find_by_rank.
        node_pointer_t left = n->children[0];
        rank_t r = left ? left->size : 0;
        node_pointer_t p = n->parent;
        while (p)
        {
            if (node::dir(p, n) == 1)
            {
                r++;    // parent in the left.
                node_pointer_t left = p->children[0];
                if (left)
                    r += left->size;    // left children of parent in the left.
            }
            n = p;
            p = n->parent; 
        }
        return r;
    }

    node_pointer_t __find_by_rank(rank_t r) const
    {
        // the reverse process of __rank.
        if (r >= size())
        {
            return nullptr;
        }
        node_pointer_t n = m_root;

        while (n)
        {
            node_pointer_t left = n->children[0];
            rank_t left_size = left ? left->size : 0;
            if (r < left_size)
            {
                n = left;
            }
            else if (r == left_size)
            {
                return n;
            }
            else
            {
                r -= left_size + 1;
                n = n->children[1];
            }
        }
        return nullptr;
    }

    node_pointer_t __insert(const_reference v)
    {
        //node_pointer_t n = std::make_shared<node>();
        node_pointer_t n = __allocate_node();
        n->value = v;
        if (!m_root)
        {
            m_root = n;
            m_root->color = node::black;
            return n;
        }
        node_pointer_t h = m_root;
        node_pointer_t p = nullptr;
        while (h)
        {
            uint32_t dir = !m_comp(*v, *h->value);
            p = h;
            h = h->children[dir];
        }
        uint32_t dir = !m_comp(*v, *p->value);

        p->children[dir] = n;
        n->parent = p;

        node_pointer_t saved_n = n;
        while (node::is_red(p))
        {
            node::update_size(p);
            node_pointer_t gp = p->parent;
            node::update_size(gp);
            uint32_t pdir = node::dir(gp, p);
            node_pointer_t u = gp->children[!pdir];
            if (!node::is_red(u))
            {
                if (node::dir(p, n) != pdir)
                {
                    p = node::rotate(p, pdir);
                }
                gp = node::rotate(gp, !pdir);
                
                if (!gp->parent)
                {
                    m_root = gp;
                }
                break;
            }
            node::color_flip(gp);
            n = gp;
            p = n->parent;
        }
        m_root->color = node::black;
        node::update_size_to_root(p);
        return saved_n;
    }

    void __erase(node_pointer_t n)
    {
        if (n->children[0] && n->children[1])
        {
            node_pointer_t successor = next(n);
            node_pointer_t c = NULL;

            if (successor == n->children[1])
            {
                n->children[1] = successor->children[1];    // n child1 set
                c = n->children[1];
                if (c)
                {
                    c->parent = n;                          // n child1 fix
                }
                successor->children[1] = n;                 // successor child1 set && n parent fix.
                successor->parent = n->parent;              // successor parent set
                n->parent = successor;                      // n parent set && successor child1 fix.
                if (successor->parent)
                {
                    successor->parent->children[node::dir(successor->parent, n)] = successor;// successor parent fix.
                }
                // n child1 done, n parent done, successor child1 done, successor parent done.
            }
            else
            {
                std::swap(n->parent, successor->parent);    // n parent set && successor parent set.
                if (n->parent)
                {
                    n->parent->children[node::dir(n->parent, successor)] = n; // n parent fix.
                }
                if (successor->parent)
                {
                    successor->parent->children[node::dir(successor->parent, n)] = successor;// successor parent fix.
                }
                std::swap(n->children[1], successor->children[1]);// n child1 set && successor set.
                c = n->children[1];
                if (c)
                {
                    c->parent = n;                               // n child1 fix.
                }
                c = successor->children[1];
                if (c)
                {
                    c->parent = successor;                      // successor child1 fix.
                }
                // n child1 done, n parent done, successor child1 done, successor parent done.
            }
            std::swap(n->children[0], successor->children[0]);  // n child0 set && successor child0 set.
            c = n->children[0];
            if (c)
            {
                c->parent = n;                                  // n child0 fix.
            }
            c = successor->children[0];
            if (c)
            {
                c->parent = successor;                          // successor fix.
            }
            std::swap(n->color, successor->color);
            std::swap(n->size, successor->size);
            if (!successor->parent)
            {
                m_root = successor;
            }
        }

        node_pointer_t c = NULL;
        node_pointer_t p = n->parent;
        c = n->children[0]?n->children[0]: n->children[1];
        node_pointer_t saved_n = n;
        if (c)
        {
            c->parent = p;
            if (node::is_red(c))
            {
                c->color = node::black;
                goto finished;
            }
        }

        if (!p || node::is_red(n))
        {
            goto finished;
        }

        n->size = 0;

        for (;!node::is_red(n) && p; n = p, p = n->parent){
            node::update_size(p);
            uint32_t dir = node::dir(p, n);
            node_pointer_t sibling = p->children[!dir];
            if (node::is_red(sibling))
            {
                p = node::rotate(p, dir);
                if (!p->parent)
                {
                    m_root = p;
                }
                p = n->parent;
                dir = node::dir(p, n);
                sibling = p->children[!dir];
            }
            if(node::is_red(sibling->children[dir]) && !node::is_red(sibling->children[!dir]))
            {
                sibling = node::rotate(sibling, !dir);
            }
            if (node::is_red(sibling->children[!dir]))
            {
                sibling->children[!dir]->color = node::black;
                p = node::rotate(p, dir);
                if (!p->parent)
                {
                    m_root = p;
                }
                break;
            }
            sibling->color = node::red;
        }
        if (node::is_red(n))
        {
            n->color = node::black;
        }
finished:
        node_pointer_t saved_p = saved_n->parent;
        if (saved_p)
        {
            saved_p->children[node::dir(saved_p, saved_n)] = c;
        }
        else
        {
            m_root = c;
        }

        if (m_root)
        {
            m_root->color = node::black;
        }
        node::update_size_to_root(p);
        __deallocate_node(saved_n);
    }


    pointer __root(){return m_root;}

    node_pointer_t __allocate_node()
    {
        node_pointer_t n = std::make_shared<node>();
        //node_pointer_t n = m_alloc.allocate(1);
        //n->construct();
        return n;
    }
    void __deallocate_node(node_pointer_t n)
    {
        //n->~node();
        //m_alloc.deallocate(n, 1);
    }

    void clear(node_pointer_t n)
    {
        if(n == nullptr)
        {
            return ;
        }
        else
        {
            //clear(n->children[0]);
            //clear(n->children[1]);
            //__deallocate_node(n);
        }
    }
public:
    node_pointer_t m_root;
    data_allocator_t m_alloc;
    comp_t  m_comp;
    map_t m_data;
};
void test(int count = 100000);
}
#endif //_RANK_TREE_H_