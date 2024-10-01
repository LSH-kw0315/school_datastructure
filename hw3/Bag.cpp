#include "Bag.hpp"
Bag::Bag(){
    MINIMUM=1;
    MAXIMUM=2*MINIMUM;
    root=new Node(MINIMUM);
}
Bag::Bag(std::size_t min){
    MINIMUM=min;
    MAXIMUM=2*MINIMUM;
    root=new Node(min);
}

int Bag::count(std::size_t target){
    int total=0;
    root->count(target,total);
    return total;
}

bool Bag::insert(std::size_t target){
    if(!loose_insert(target)){
        return false;
    }
    int data_count=root->get_Data_Count();
    if(data_count>MAXIMUM){
        fix_excess();
    }
    return true;
}
void Bag::fix_excess(){
        Node* tmp=root;
        Node* new_root=new Node(MINIMUM);
        new_root->set_Subset(tmp,0);
        new_root->set_Child_Count(1);
        root=new_root;
        root->fix_excess(0);
        delete tmp;
}
bool Bag::loose_insert(std::size_t target){
    return root->loose_insert(target);
}

bool Bag::erase_one(std::size_t target){
    if(!loose_erase(target)){
        return false;
    }
    int root_data_count=root->get_Data_Count();
    int root_child_count=root->get_Child_Count();
    if(root_data_count==0 && root_child_count==1){
        fix_shortage();
    }
    return true;
}
void Bag::fix_shortage(){
        Node** root_subset=root->get_Subset();
        Node* to_remove=root;
        root=root_subset[0];
        delete to_remove;
}
bool Bag::loose_erase(std::size_t target){
    return root->loose_erase(target);
}

void Bag::show_contents(){
    print(root,0,0,0);
}

void Bag::print(Node* cur,int depth,int parent_printed,int root_printed){
    if(cur!=NULL){
        Node** subset=cur->get_Subset();
        std::size_t* data=cur->get_Data();
        int child_count=cur->get_Child_Count();
        for(int i=child_count-1;i>=0;i--){
            print(subset[i],depth+1,parent_printed,root_printed);
            if(this->root==cur && root_printed<cur->get_Data_Count()){
                std::cout<<""<<std::setw(4*depth)<<data[root_printed++]<<std::endl;
            }else if(this->root!=cur && parent_printed<cur->get_Data_Count()){
                std::cout<<std::setw(4*depth)<<""<<data[parent_printed++]<<std::endl;
            }
            
        }
        if(child_count<=0){
            for(int i=0;i<cur->get_Data_Count();i++){
                std::cout<<std::setw(4*depth)<<""<<data[i]<<std::endl;
            }
        }
    }
}