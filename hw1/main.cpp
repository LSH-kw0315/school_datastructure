#include "Dnode_r.h"
#include "listtoolkit2_r.h"
#include "Deque_r.h"
#include "Evaluator_r.h"
#include <iostream>

int main(void){
    Evaluator ev;
    while(true){
        string infixexp=ev.read_expression();
        cout<<infixexp<<endl;
        string postfixexp=ev.convert_to_postfix(infixexp);
        cout<<postfixexp<<endl;
        double res=ev.evaluate_postfix(postfixexp);
        cout<<res<<endl;
    }
    return 0;
}