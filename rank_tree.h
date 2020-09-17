#ifndef _RANK_TREE_H_
#define _RANK_TREE_H_
#include <utility>
#include <iostream>

#define RANK_TREE_DEBUG 

#ifdef RANK_TREE_DEBUG
#include "print_tree.h"
#endif

namespace nm_rank_tree{

template <typename key_t, typename value_t, typename comp_t = std::less<key_t> >
class rank_tree
{
public:
    typedef std::pair<key_t, value_t>   value_type;
    typedef value_type*                 pointer;
    typedef const value_type*           const_pointer;
    typedef value_type&                 reference;
    typedef const value_type&           const_reference;

    typedef int rank_t;

public:
    
    struct node
    {
        public:
        //typedef node* pointer_t;
        using pointer_t = node* ; //std::shared_ptr<node>;
        static const int red = 0;
        static const int black = 1;
        node():parent(nullptr), size(1), color(red) 
        {
            children[0] = nullptr;
            children[1] = nullptr;
        }
        
        pointer_t children[2];
        pointer_t parent;
        rank_t size;
        int color;
        value_type value;
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

        static int dir(pointer_t p, pointer_t c)
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

        static pointer_t rotate(pointer_t h, int dir)
        {
            int opp_dir = !dir;
            pointer_t x = h->children[opp_dir];
            h->children[opp_dir] = x->children[dir];
            x->children[dir] = h;
            std::swap(x->color, h->color);
            pointer_t parent = h->parent;
            if (parent)
            {
                int pdir = node::dir(parent, h);
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

        static pointer_t spine(pointer_t h, int dir)
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

        static pointer_t move_pointer(pointer_t h, int dir)
        {
            int opp_dir = !dir;
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


    //typedef std::allocator<node>  data_allocator;
    //typedef typename data_allocator::template rebind<node>::other node_allocator_t;
    //typedef typename node_allocator_t::pointer node_pointer_t;
    //typedef typename node_allocator_t::const_pointer const_node_pointer_t;
    using data_allocator = std::allocator<node>;
    using node_pointer_t = node* ; //std::shared_ptr<node>;
    using const_node_pointer_t = const node*; //std::shared_ptr<const node>;

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

    rank_tree(comp_t comp):m_root(nullptr), m_comp(comp)
    {

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

    iterator insert(const_reference v)
    {
        node_pointer_t p = __insert(v);
        return iterator(p);
    }

    void erase(iterator i)
    {
        return __erase(i.m_p);
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

    // TODO cache iterator begin.
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
        // invariant left < key <= right
        // left <= root <= right
        node_pointer_t n = m_root;
        node_pointer_t p = nullptr;
        while (n)
        {
            if (comp(n->value.first, k))
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
            if (comp(k, n->value.first))
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
        #ifdef RANK_TREE_DEBUG
        printf("begin insert %d\n", v.first);
        
        nm_print_tree::tree_print<node> tprint(
            [](node* n){return n->children[0];},
            [](node* n){return n->children[1];}, 
            [](node* n){return n->value.first;},
            [](node* n){return n->color == 0;});
        #endif
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
            int dir = !m_comp(v.first, h->value.first);
            p = h;
            h = h->children[dir];
        }
        int dir = !m_comp(v.first, p->value.first);
        #ifdef RANK_TREE_DEBUG
        tprint.print(m_root);
        #endif
        p->children[dir] = n;
        n->parent = p;
        #ifdef RANK_TREE_DEBUG
        tprint.print(m_root);
        #endif
        node_pointer_t saved_n = n;
        while (node::is_red(p))
        {
            node::update_size(p);
            node_pointer_t gp = p->parent;
            node::update_size(gp);
            int pdir = node::dir(gp, p);
            node_pointer_t u = gp->children[!pdir];
            if (!node::is_red(u))
            {
                if (node::dir(p, n) != pdir)
                {
                    p = node::rotate(p, pdir);
                    #ifdef RANK_TREE_DEBUG
                    tprint.print(m_root);
                    #endif
                }
                gp = node::rotate(gp, !pdir);
                
                if (!gp->parent)
                {
                    m_root = gp;
                }
                #ifdef RANK_TREE_DEBUG
                tprint.print(m_root);
                #endif
                break;
            }
            node::color_flip(gp);
            n = gp;
            p = n->parent;
            #ifdef RANK_TREE_DEBUG
            tprint.print(m_root);
            #endif
        }
        m_root->color = node::black;
        #ifdef RANK_TREE_DEBUG
        tprint.print(m_root);
        #endif
        node::update_size_to_root(p);
        return saved_n;
    }

    void __erase(node_pointer_t n)
    {
        #ifdef RANK_TREE_DEBUG
        printf("begin __erase %d\n", n->value);
        nm_print_tree::tree_print<node> tprint(
            [](node* n){return n->children[0];},
            [](node* n){return n->children[1];}, 
            [](node* n){return n->value.first;},
            [](node* n){return n->color == 0;});
        #endif
        //assert_retnone(m_root);
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

        #ifdef RANK_TREE_DEBUG
        tprint.print(m_root);
        #endif
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
            int dir = node::dir(p, n);
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
        #ifdef RANK_TREE_DEBUG
        tprint.print(m_root);
        #endif
    }


    pointer __root(){return m_root;}

    node_pointer_t __allocate_node()
    {
        //node_pointer_t n = m_alloc.allocate(1);
        node_pointer_t n = m_alloc.allocate(1); //std::make_shared<node>();
        n->construct();
        return n;
    }
    void __deallocate_node(node_pointer_t n)
    {
        n->~node();
        m_alloc.deallocate(n, sizeof(node));
    }

    void clear(node_pointer_t n)
    {
        if(n == nullptr)
        {
            return ;
        }
        else
        {
            clear(n->children[0]);
            clear(n->children[1]);
            __deallocate_node(n);
        }
    }
public:
    node_pointer_t m_root;
    data_allocator m_alloc;
    comp_t  m_comp;
};

}
#endif //_RANK_TREE_H_