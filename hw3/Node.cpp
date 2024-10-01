#include "Node.hpp"
#include <algorithm>
bool Node::loose_insert(std::size_t target){
    int idx;
    for(idx=0;idx<data_count;idx++){
        if(data[idx]>=target){
            break;
        }
    }
    if(child_count==0 && data_count<MAXIMUM+1){   
        data[data_count++]=target;
        //delete[] to_remove;
     
        std::sort(data,data+MAXIMUM+1);
        return true;  
    }else{
        bool b1=false;
        bool b2=false;
            if(subset[idx]!=NULL){
                if(subset[idx]!=NULL){
                    b1=subset[idx]->loose_insert(target);
                    if(subset[idx]->data_count>MAXIMUM){
                        fix_excess(idx);
                    }
                }
            }else if(subset[idx+1]!=NULL && !b1){
                if(!b1 && idx+1<child_count&&subset[idx+1]!=NULL){
                    b2=subset[idx+1]->loose_insert(target);
                    if(subset[idx+1]->data_count>MAXIMUM){
                        fix_excess(idx+1);
                    }
                }
            }
    
        return b1||b2;
    }
    return false;
}

void Node::fix_excess(std::size_t idx){
    Node* sub1=new Node(MINIMUM);
    Node* sub2=new Node(MINIMUM);

    Node* sub_tmp=subset[idx];
    std::size_t sub_data_count=subset[idx]->data_count;
    std::size_t sub_child_count=subset[idx]->child_count;
    std::size_t data_middle=sub_data_count/2;
    std::size_t child_middle=sub_child_count/2;

    std::size_t to_parent=subset[idx]->data[data_middle];

    int tmp_idx=0;
    for(int i=0;i<data_middle;i++){
        sub1->data[tmp_idx++]=subset[idx]->data[i];
        sub1->data_count++;
    }

    tmp_idx=0;
    for(int i=data_middle+1;i<sub_data_count;i++){
        sub2->data[tmp_idx++]=subset[idx]->data[i];
        sub2->data_count++;
    }

    tmp_idx=0;
    for(int i=0;i<child_middle;i++){
        sub1->subset[tmp_idx++]=subset[idx]->subset[i];
        sub1->child_count++;
    }

    tmp_idx=0;
    for(int i=child_middle;i<sub_child_count;i++){
        sub2->subset[tmp_idx++]=subset[idx]->subset[i];
        sub2->child_count++;
    }

    Node** new_subset=new Node*[MAXIMUM+2];
    for(int i=0;i<idx;i++){
        new_subset[i]=subset[i];
    }
    for(int i=idx;i<child_count;i++){
        if(i+2>=MAXIMUM+2){
            break;
        }
        new_subset[i+2]=subset[i+1];
    }
    new_subset[idx]=sub1;
    new_subset[idx+1]=sub2;

    subset=new_subset;
    child_count++;
    
    //delete sub_tmp;

    data[data_count++]=to_parent;
    std::sort(data,data+MAXIMUM+1);

    //delete[] data_tmp;

}

bool Node::loose_erase(std::size_t target){
    int idx;
    for(idx=0;idx<data_count;idx++){
        if(data[idx]>=target){
            break;
        }
    }

    if(child_count==0 && data[idx]!=target){    
        return false;
    }
    if(child_count==0 && data[idx]==target){
        data[idx]=10000;
        std::sort(data,data+MAXIMUM+1);
        data_count--;
        return true;
    }
    else if(child_count>0){
        if(data[idx]!=target){
            bool b1=false;
            for(int i=idx;i<child_count;i++){
                if(subset[i]==NULL){
                    break;
                }
                b1=subset[i]->loose_erase(target);
                if(b1){break;}
            }
            if(!b1 && idx-1>0 && subset[idx-1]!=NULL){
                b1=subset[idx-1]->loose_erase(target);
            }
            if(b1 && subset[idx]->data_count<MINIMUM){
                fix_shortage(idx);
            }
            
  
            return b1;
        }

        if(data[idx]==target){
            std::size_t biggest;
            subset[child_count-1]->remove_biggest(biggest);
            data[idx]=biggest;
            std::sort(data,data+MAXIMUM+1);
            if(subset[child_count-1]->data_count<MINIMUM){
                fix_shortage(child_count-1);
            }
            return true;
        }
    }
    return false;
}

void Node::fix_shortage(std::size_t idx){

    if(idx+1<child_count&&subset[idx+1]!=NULL && subset[idx+1]->data_count>MINIMUM){
        std::size_t parent_data=data[idx];
        subset[idx]->data[subset[idx]->data_count++]=parent_data;
        
        std::size_t sub_data=subset[idx+1]->data[0];
        subset[idx+1]->data[0]=10000;
        subset[idx+1]->data_count--;
        std::sort(subset[idx+1]->data,subset[idx+1]->data+MAXIMUM+1);
        data[idx]=sub_data;

        if(subset[idx+1]->child_count>0){
            subset[idx]->subset[subset[idx]->child_count++]=subset[idx+1]->subset[0];
            Node** new_sub=new Node*[MAXIMUM+2];
            for(int i=0;i<subset[idx+1]->child_count-1;i++){
                new_sub[i]=subset[idx+1]->subset[i+1];
            }
            subset[idx+1]->subset=new_sub;
            subset[idx+1]->child_count--;
        }
        return;
    }
    if(idx-1>=0 && idx-1<child_count&&subset[idx-1]!=NULL && subset[idx-1]->data_count>MINIMUM){
        std::size_t parent_data=data[idx-1];
        subset[idx]->data[subset[idx]->data_count++]=parent_data;
        std::sort(subset[idx]->data,subset[idx]->data+MAXIMUM+1);
        //delete[] sub_idx_tmp_data;
        
        std::size_t sub_data=subset[idx-1]->data[--(subset[idx-1]->data_count)];
        subset[idx-1]->data[subset[idx-1]->data_count]=10000;
        data[idx-1]=sub_data;

        if(subset[idx-1]->child_count>0){
            Node** sub_idx_tmp_child=subset[idx]->subset;
            Node** sub_idx_new_child=new Node*[MAXIMUM+2];
            Node* sub_child=subset[idx-1]->subset[--(subset[idx-1]->child_count)];
            for(int i=0;i<subset[idx]->child_count;i++){
                if(i+1>=MAXIMUM+2){
                    break;
                }
                sub_idx_new_child[i+1]=subset[idx]->subset[i];
            }
            sub_idx_new_child[0]=sub_child;
            subset[idx]->subset=sub_idx_new_child;
            subset[idx-1]->subset[subset[idx-1]->child_count]=NULL;
            //delete[] sub_idx_tmp_child;
        }
        return;

    }
    if(idx-1>=0 && idx-1<child_count&&subset[idx-1]!=NULL && subset[idx-1]->data_count==MINIMUM){
        std::size_t parent_data=data[idx-1];
        subset[idx-1]->data[subset[idx-1]->data_count++]=parent_data;
        data[idx-1]=10000;
        data_count--;
        std::sort(data,data+MAXIMUM+1);
        std::size_t sub_data_count=subset[idx-1]->data_count;
        std::size_t sub_child_count=subset[idx-1]->child_count;
        for(int i=0;i<subset[idx]->data_count;i++){
            subset[idx-1]->data[sub_data_count+i]=subset[idx]->data[i];
        }
        subset[idx-1]->data_count+=subset[idx]->data_count;
        for(int i=0;i<subset[idx]->child_count;i++){
            subset[idx-1]->subset[sub_child_count+i]=subset[idx]->subset[i];
        }
        subset[idx-1]->child_count+=subset[idx]->child_count;

        //delete subset[idx];
        subset[idx]=NULL;
        for(int i=idx;i<child_count;i++){
            if(i>=MAXIMUM+1){
                break;
            }
            subset[i]=subset[i+1];
        }
        child_count--;
        return;
    }
    if(idx+1<child_count && subset[idx+1]!=NULL && subset[idx+1]->data_count==MINIMUM){
        std::size_t parent_data=data[idx];
        subset[idx]->data[subset[idx]->data_count++]=parent_data;
        data[idx]=10000;
        data_count--;
        std::sort(data,data+MAXIMUM+1);
        std::size_t sub_data_count=subset[idx]->data_count;
        std::size_t sub_child_count=subset[idx]->child_count;
        for(int i=0;i<subset[idx+1]->data_count;i++){
            subset[idx]->data[sub_data_count+i]=subset[idx+1]->data[i];
        }
        subset[idx]->data_count+=subset[idx+1]->data_count;
        for(int i=0;i<subset[idx+1]->child_count;i++){
            subset[idx]->subset[sub_child_count+i]=subset[idx+1]->subset[i];
        }
        subset[idx]->child_count+=subset[idx+1]->child_count;

        //delete subset[idx+1];
        subset[idx+1]=NULL;
        for(int i=idx+1;i<child_count;i++){
            if(i+1>=MAXIMUM+2){
                break;
            }
            subset[i]=subset[i+1];
        }
        child_count--;
        return;
    }
    return;

}

void Node::remove_biggest(std::size_t& to_remove){
    if(child_count==0){
        to_remove=data[--data_count];
        data[data_count]=10000;
    }else{
        subset[child_count-1]->remove_biggest(to_remove);
        if(subset[child_count-1]->data_count<MINIMUM){
            fix_shortage(child_count-1);
        }
    }
}

void Node::count(std::size_t target,int& total){
    int idx=0;
    bool init=false;
    for(int i=0;i<data_count;i++){
        if(data[i]==target){
            total++;
        }
        if(data[i]>=target && !init){
            idx=i;
            init=true;
        }
    }
    for(int i=idx;i<child_count;i++){
        subset[i]->count(target,total);
    }
    if(idx-1>0 && subset[idx-1]!=NULL){
        subset[idx-1]->count(target,total);
    }

}
