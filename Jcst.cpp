#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
using namespace std;
string type, command, inputcharacter;
void main1(){
    cout << "Jcst>";
    cin >> command;
    if (command == "input") { //input指令
        cout << "Jcst>input>data:";
        cin >> inputcharacter;
        main1();
    }
    else if (command == "help") {
        cout << "Jcst>help>help:Get help\nJcst>help>leave:Exit Jcst\nJcst>help>output:Output characters\nJcst>help>input:Input characters\nJcst>help>print:Print characters\nJcst>help>calculator:Mini calculator\nJcst>help>loop:Loop print characters\nJcst>help>time:Print now Beijing time\nJcst>help>info:Jcst information\n";
        main1();
    } 
    else if (command == "print") { //print指令
        cout << "Jcst>print:";
        cin >> inputcharacter;
        cout << "Jcst>print>" << inputcharacter << endl;
        main1();
    }
    else if (command == "leave") { //leave指令
        cout << "Jcst>leave>Are you sure to leave Jcst?(y/n)";
        cin >> type;
        if (type == "y") {
            return;
        }
        else {
        main1();
        }
    }
    else if(command == "time") { //time指令
        time_t now = time(0);
        char* dt = ctime(&now); 
        cout << "Beijing time:" << dt;    
        main1();
    } 
    else if (command == "output") { //output指令
        cout << "Jcst>output>" << inputcharacter << endl;
        main1();
    }
    else if(command == "loop") { //loop指令
        int a;
        cout << "Jcst>loop>frequency:";
        cin >> a;
        cout << "Jcst>loop>data:";
        cin >> inputcharacter;
        for( int i = 0; i < a; i++ ){
            cout << "Jcst>loop>" << inputcharacter << endl;
        }
        main1();
    } 
    else if (command == "calculator") { //四则运算指令
        double a;
        double b;
        cout << "Jcst>calculator>a=:";
        cin >> a;
        cout << "Jcst>calculator>select operator:+ - * /(1/2/3/4)\n" << "Jcst>calculator>select operator:";
        cin >> inputcharacter;
        cout << "Jcst>calculator>b=:";
        cin >> b;
        if(inputcharacter == "1") {
            cout << "Jcst>calculator>" << a + b << endl;
        }
        else if(inputcharacter == "2") {
            cout << "Jcst>calculator>" << a - b << endl;
        }
        else if(inputcharacter == "3") {
            cout << "Jcst>calculator>" << a * b << endl;
        }
        else if(inputcharacter == "4") {
            cout << "Jcst>calculator>" << a / b << endl;
        }
        main1();
    }
    else if (command == "info") { //info指令
        cout << "Jcst>info>Jcst Programm Ver.20524.\nJcst>info>This version is ...\nJcst>info>By.ZSJun\n";
        main1();
    }
    else if (command == "EasterEggs"){
        cout << "Congratulations on finding the Easter Eggs!\nYou can add my QQ:2941961571,remarks:Jcst!";
    }
    else {
        cout << "Jcst>Erorr!Unknow command!\n";
        main1();
    }
}
int main(){
    system("del upgrade.txt");
    system("cls");
    cout << "------------------------------------------------\n"; //开始大屏
    cout << "| Jcst Program                       Ver.20523 |\n";
    cout << "| Now support:input,output,print,calculator!   |\n";
    cout << "| Now support:loop,time!                       |\n";
    cout << "| Enter 'help' to get help!                    |\n";
    cout << "| Case sensitive!                              |\n";
    cout << "| By.ZSJun                           2020-5-23 |\n";
    cout << "------------------------------------------------\n";
    main1();
}