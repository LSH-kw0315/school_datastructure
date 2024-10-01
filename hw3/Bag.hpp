#ifndef __BAG_H__
#define __BAG_H__
#include <cstdlib>
#include <iomanip>
#include "Node.hpp"
class Bag{
    private:
        std::size_t MINIMUM;
        std::size_t MAXIMUM;
        Node* root;
        bool loose_insert(std::size_t target);
        bool loose_erase(std::size_t target);
        void fix_excess();
        void fix_shortage();
        void print(Node* cur,int depth,int parent_printed,int root_printed);
    
    public:
        Bag();
        Bag(std::size_t min);
        int count(std::size_t target);
        bool insert(std::size_t target);
        bool erase_one(std::size_t target);
        void show_contents();
         
};

#endif