#ifndef __NODE_H__
#define __NODE_H__
#include <cstdlib>
#include <iostream>

class Node{
    private:
        std::size_t MINIMUM;
        std::size_t MAXIMUM;
        std::size_t* data;
        Node** subset;
        std::size_t data_count;
        std::size_t child_count;
    public:
        Node(std::size_t min=1){
            MINIMUM=min;
            MAXIMUM=2*MINIMUM;
            data=new std::size_t[MAXIMUM+1];
            for(int i=0;i<MAXIMUM+1;i++){
                data[i]=10000;
            }
            subset=new Node*[MAXIMUM+2];
            for(int i=0;i<MAXIMUM+2;i++){
                subset[i]=NULL;
            }
            data_count=0;
            child_count=0;
        };

        std::size_t*& get_Data(){return data;};
        Node**& get_Subset(){return subset;};
        std::size_t get_Data_Count()const{return data_count;}
        std::size_t get_Child_Count()const{return child_count;}

        void set_Data_Count(std::size_t cnt){data_count=cnt;};
        void set_Child_Count(std::size_t cnt){child_count=cnt;};
        void set_Subset(Node* entry,std::size_t idx){
            subset[idx]=entry;
        };
        void set_Data(std::size_t entry,std::size_t idx){
            data[idx]=entry;
        };
        void count(std::size_t target,int& total);

        bool loose_insert(std::size_t target);
        void fix_excess(std::size_t idx);

        bool loose_erase(std::size_t target);
        void fix_shortage(std::size_t idx);

        void remove_biggest(std::size_t& to_remove);

        void traversal();

};

#endif