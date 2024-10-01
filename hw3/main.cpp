#include "Node.hpp"
#include "Bag.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <string>
int main(){
    Bag bag;
    std::cout<<"insert x : insert an integer x in the bag."<<std::endl;
    std::cout<<"erase_one x : erase an integer x in the bag."<<std::endl;
    std::cout<<"count x : find an integer x in the bag."<<std::endl;
    std::cout<<"quit : terminate this program."<<std::endl;
    while(true){
        std::string input;
        std::cout<<"please input command: ";
        getline(std::cin,input);
        std::stringstream ss1(input);
        std::string cmd;
        std::string integer;
        ss1>>cmd;
        ss1>>integer;
        
        std::stringstream ss2(integer);
        int num=-1;
        ss2>>num;
        bool change=ss2.fail();
        


        if(cmd.compare("quit")==0){
            std::cout<<"task over."<<std::endl;
            break;
        }
        if(change || num<0){
            continue;
        }

        if(cmd.compare("insert")==0){
            std::cout<<"before insert :"<<std::endl;
            bag.show_contents();
            bag.insert(num);
            std::cout<<"after insert :"<<std::endl;
            bag.show_contents();

        }else if(cmd.compare("erase_one")==0){
            std::cout<<"before erase :"<<std::endl;
            bag.show_contents();
            bag.erase_one(num);
            std::cout<<"after erase :"<<std::endl;
            bag.show_contents();

        }else if(cmd.compare("count")==0){
            std::cout<<"before count :"<<std::endl;
            bag.show_contents();
            int total=bag.count(num);
            if(total>0){
                std::cout<<"there is "<<total<<" target in the bag."<<std::endl;
            }else{
                std::cout<<"there is no target in the bag."<<std::endl;
            }
            std::cout<<"after count:"<<std::endl;
            bag.show_contents();
        }
    }
    return 0;
}
