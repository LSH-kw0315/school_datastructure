#ifndef __EVALUATOR__H__
#define __EVALUATOR__H__
#include "Deque_r.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
class Evaluator{
    private:
        Deque<string> deque;
        
    public:
        
        string read_expression();
        /*
        표준 입력으로 infix 식을 입력 받고 유저가 제공한 식을 문자열로 반환한다. 
        입력 조건: 입력 시에 연산자는 모두 이항 연산자, 피연산자는 숫자 혹은 미지수, 괄호는 있을 수도 있고 없을 수도 있다.
                   (입력 받는 식은 모두 형식에 맞는 infix식이라고 가정한다.)
        출력 조건: infix 식을 문자열로 반환한다.

        */
        string convert_to_postfix(string s);
        /*
        인자로 넘어온 infix 식 문자열을 postfix로 변환하여 반환한다.
        입력 조건: read_expression 함수의 입력 조건을 만족하는 infix 식이 인자로 넘어온다고 가정한다.
        출력 조건: postfix 식을 문자열로 반환한다. 이 때, 연산자와 연산자, 피연산자와 피연산자, 연산자와 피연산자 사이에는 공백이 존재해야한다.

        
        */
        double evaluate_postfix(string s);
        /*
        인자로 넘어온 postfix 식 문자열을 이용해 계산을 한다. 이 때, 미지수가 식에 있다면 미지수에 어떤 값을 대입할 지 입력받아서 물어봐야한다.
        입력 조건 : convert_to_postfix의 출력에 맞는 postfix 식이 인자로 넘어온다고 가정한다.
        출력 조건 : 계산 결과를 출력한다.

        에러 발생 시 -10000을 반환한다.
        */
};

string Evaluator::read_expression(){
    string input;
    cout<<"please input a infix expression(if you want to stop, input exit):";
    cin>>input;
    string output;
    if (input.compare("exit")==0)
        exit(0);   
    
    for(int i=0;i<input.length();i++){
        char peeked=input.at(i);
        if(isdigit(peeked)){
                //정수 혹은 실수일때
                string storenum;
                storenum.append(1,peeked);
                int jump=0;
                for(int j=i+1;j<input.length();j++){
                    if(isdigit(input.at(j)) || input.at(j)=='.'){
                        storenum.append(1,input.at(j));
                        jump++;
                    }else
                        break;
                }
                stringstream forstring(storenum);
                int test=0;
                forstring>>test;
                if(!forstring.fail()){
                    deque.rear_push(storenum);
                }
                i+=jump;
            
        }else if(peeked=='.'){
            //
            int jump=0;
            string storedouble;
            storedouble.append(1,'0');
            storedouble.append(1,'.');
            for(int j=i+1;j<input.length();j++){
                if(isdigit(input.at(j))){
                    storedouble.append(1,input.at(j));
                    jump++;
                }else
                    break;
            }
            stringstream forstring(storedouble);
            double test=0.0;
            forstring>>test;
            if(!forstring.fail()){
                deque.rear_push(storedouble);
            }
            i+=jump;
        }else if(isalpha(peeked)){
            //미지수인 경우
            string storechar;
            storechar.append(1,peeked);
            deque.rear_push(storechar);
        }else if(strchr("+-/*()",peeked)!=NULL){
            //연산자인 경우
            string storechar;
            storechar.append(1,peeked);
            deque.rear_push(storechar);
        }else{
            continue;
        }
    }
    int size=deque.size();
    for(int i=0;i<size;i++){
        output.append(deque.front_pop());
    }
    //deque.empty();
    return output;

}

string Evaluator::convert_to_postfix(string s){
    string output;

    //deque에 식을 분리하여 집어넣는다.
    for(int i=0;i<s.length();i++){
        char peeked=s.at(i);
        if(isdigit(peeked)){
           
            //정수이거나 실수일 때
            string storenum;
            storenum.append(1,peeked);
            int jump=0;
            for(int j=i+1;j<s.length();j++){
                if(isdigit(s.at(j))||s.at(j)=='.'){
                    storenum.append(1,s.at(j));
                    jump++;
                }else
                    break;
            }
            int test=0;
            stringstream ss(storenum);
            ss>>test;
            if(!ss.fail()){
                output.append(storenum);
                output.append(1,' ');
            }
            i+=jump;
        }else if(peeked=='.'){
            //정수부가 0인 실수인 경우
            int jump=0;
            string storedouble;
            storedouble.append("0.");
            for(int j=i+1;j<s.length();j++){
                if(isdigit(s.at(j))){
                    storedouble.append(1,s.at(j));
                    jump++;
                }else
                    break;
            }
            double test=0.0;
            stringstream ss(storedouble);
            ss>>test;
            if(!ss.fail()){
                output.append(storedouble);
                output.append(1,' ');
            }
            i+=jump;
        }else if(isalpha(peeked)){
            //미지수
            stringstream forstring;
            string storechar;
            storechar.append(1,peeked);
            output.append(storechar);
            output.append(1,' ');
        }else if(strchr("+-/*()",peeked)!=NULL){
            //연산자
            string storechar;
            storechar.append(1,peeked);
            if(peeked==')' && !(deque.isempty())){
                string op=deque.rear_pop();
                deque.rear_pop();
                output.append(op);
                output.append(1,' ');
            }else if(!(deque.isempty()) && deque.rear().compare("(")!=0){
                string op;
                string cmp=deque.rear();
                switch(peeked){
                    case '+':
                        op=deque.rear_pop();
                        output.append(op);
                        output.append(1,' ');
                        break;
                    case '-': 
                        op=deque.rear_pop();
                        output.append(op);
                        output.append(1,' ');
                        break;
                    case '*':
                        if(cmp.compare("*")==0||cmp.compare("/")==0){ 
                            op=deque.rear_pop();
                            output.append(op);
                            output.append(1,' ');
                        }
                        break;
                    case '/':
                        if(cmp.compare("*")==0||cmp.compare("/")==0){ 
                            op=deque.rear_pop();
                            output.append(op);
                            output.append(1,' ');
                        }
                        break;
                    default:
                        break;
                }
                deque.rear_push(storechar);
            }else{
                deque.rear_push(storechar);
            }
        }else{
            continue;
        }
    }
    while(!deque.isempty()){
        output.append(deque.rear_pop());
        output.append(1,' ');
    }
    //deque.empty();
    return output;
}

double Evaluator::evaluate_postfix(string s){
    double result=0;
    for(int i=0;i<s.length();i++){
        char peeked=s.at(i);
        if(isdigit(peeked)){
            //숫자일때
            string storenum;
            storenum.append(1,peeked);
            int jump=0;
            for(int j=i+1;j<s.length();j++){
                if(isdigit(s.at(j))||s.at(j)=='.'){
                    storenum.append(1,s.at(j));
                    jump++;
                }else
                     break;
            }
            double test=0;
            stringstream ss(storenum);
            ss>>test;
            if(!ss.fail()){
                deque.rear_push(storenum);
            }
            i+=jump;
        }else if(peeked=='.'){
            //정수부가 0인 실수인 경우
            int jump=0;
            string storedouble;
            storedouble.append("0.");
            for(int j=i+1;j<s.length();j++){
                if(isdigit(s.at(j))){
                    storedouble.append(1,s.at(j));
                    jump++;
                }else
                    break;
            }
            double test=0.0;
            stringstream ss(storedouble);
            ss>>test;
            if(!ss.fail()){
                deque.rear_push(storedouble);
            }
            i+=jump;
        }else if(isalpha(peeked)){
            //미지수인 경우
            string storechar;
            string realnumber;
            storechar.append(1,peeked);
            while(1){
                cout<<"please assign the value to "<<storechar<<":";
                cin>>realnumber;
                stringstream ss(realnumber);
                double test=0.0;
                ss>>test;
                if(!ss.fail()){
                    realnumber=to_string(test);
                    cin.clear();
                    break;
                }
            }
            deque.rear_push(realnumber);
        }else if(strchr("+-/*",peeked)!=NULL){
            //연산자인 경우
            string operand1;
            string operand2;
            operand1=deque.rear_pop();
            operand2=deque.rear_pop();
            double num1=0.0;
            double num2=0.0;
            double total=0.0;
            stringstream ssNum1(operand1);
            stringstream ssNum2(operand2);
            ssNum1>>num1;
            ssNum2>>num2;
            switch(peeked){
                case '+':
                    total=num2+num1;
                    break;
                case '-':
                    total=num2-num1;
                    break;
                case '*':
                    total=num2*num1;
                    break;
                case '/':
                    if(num1!=0){
                        total=num2/num1;
                    }
                    break;
            }
            string totalStr=to_string(total);
            deque.rear_push(totalStr);
        }else{
            continue;
        }
    }
    if(!deque.isempty()){
        string strRes=deque.rear_pop();
        stringstream ss(strRes);
        double res=0.0;
        ss>>res;
        //deque.empty();
        if(!ss.fail()){
            return res;
        }else{
            return -10000;
        }
    }else{
        return -10000;
    }
}

#endif