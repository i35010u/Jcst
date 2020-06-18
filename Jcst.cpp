#include <iostream>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
string type, command, inputcharacter,color;
void code(){
    cout << "Jcst>";
    cin >> command;
    if (command == "input" || command == "INPUT") { //input指令
        cout << "data:";
        cin >> inputcharacter;
        code();
    }
    else if(command =="color" || command =="COLOR"){
        cout << "The first is background,the second is Foreground.\n";
        cout << "0 = black       8 = gray\n";
        cout << "1 = blue        9 = light blue\n";
        cout << "2 = green       A = light green\n";
        cout << "3 = aqua        B = light aqua\n";
        cout << "4 = red         C = light red\n";
        cout << "5 = purple      D = light purple\n";
        cout << "6 = yellow      E = light yellow\n";
        cout << "7 = write       F = bright write\n";
        cout << "color:";
        cin >> color;
        system(("color " + color).c_str());   
        code();
    }
    else if(command =="cmd" || command =="CMD"){
        system("%windir%\\system32\\cmd.exe");
        code();
    }
    else if (command == "help" || command == "HELP") {
        cout << "   help:Get help\n";
        cout << "       leave:Exit Jcst\n";
        cout << "   update:Download newest Jcst\n";
        cout << "       output:Output characters\n";
        cout << "   input:Input characters\n";
        cout << "       print:Print characters\n";
        cout << "   calculator:Mini calculator\n";
        cout << "       loop:Loop print characters\n";
        cout << "   time:Print now Beijing time\n";
        cout << "       info:Show info\n";
        cout << "   color:Colorful pages\n";
        cout << "       cmd:Windows cmd\n";
        cout << "   lcmd:Loop Windows cmd\n";
        cout << "       notepad:Windows notepad\n";
        cout << "   shutdown:Shutdown this computer\n";
        cout << "       winver:Windows ver\n";
        cout << "   readset:Read color set\n";
        cout << "       delset:Delete color set\n";
        cout << "   saveset:Save color set\n";
        code();
    }
    else if (command == "print" || command == "PRINT") { //print指令
        cout << "print:";
        cin >> inputcharacter;
        cout << inputcharacter << endl;
        code();
    }
    else if (command == "leave" || command == "LEAVE") { //leave指令
        cout << "Are you sure to leave Jcst?(y/n)";
        cin >> command;
        if (type == "y") {
            return; 
        }
        else {
        code();
        }
    }
    else if (command == "output" || command == "OUTPUT") { //output指令
        cout << "data>" << inputcharacter << endl;
        code();
    }
    else if(command == "loop" || command == "LOOP") { //loop指令
        int a;
        cout << "frequency:";
        cin >> a;
        cout << "data:";
        cin >> inputcharacter;
        for( int i = 0; i < a; i++ ){
            cout << inputcharacter << endl;
        }
        code();
    } 
    else if (command == "calculator" || command == "CALCULATOR") { //四则运算指令
        system("calc");
        code();
    }
    else if (command == "notepad" || command == "NOTEPAD") { //四则运算指令
        system("notepad");
        code();
    }
    else if(command=="shutdown"||command=="SHUTDOWN"){
        system("shutdown -s");
        code();
    }
    else if(command=="winver"||command=="WINVER"){
        system("winver");
        code();
    }
    else if (command == "update" || command == "UPDATE"){ //Update指令,更新时需更改else if，修改github版本参数，并上传至蓝奏云
        CHAR c[MAX_PATH];
        DWORD result = GetCurrentDirectoryA(MAX_PATH, c);
        std::string direy(c);
        std::string wgetDir(direy);
        wgetDir+="\\wget.exe";
        std::string cmd = wgetDir+" https://54zsjun.github.io/Jcst.github.io/update.txt";
        system(cmd.c_str());
        ifstream readFile("update.txt");
        int ret;
        readFile >> ret;
        readFile.close();
        if (ret == -1) {
            cout << "Error! The update failed! Because the version list cannot be obtained on the authentication server!\n";
            Sleep(5 * 1000);
            system("start https://zsjun.lanzous.com/b0de1y5zi");
            system("del .wget-hsts");
            system("del update.txt");
            return;
        }
        else if (ret > 1) {
            cout << "Updated versionavailable for upgrades, please go to https://zsjun.lanzous.com/b0de1y5zi download!\n";
            Sleep(5 * 1000);
            system("start https://zsjun.lanzous.com/b0de1y5zi");
            system("del update.txt");
            system("del .wget-hsts");
            return;
        }
        else if (ret == 1) {
            cout << "Congratulations! You've upgraded to the latest version!\n";
            system("del update.txt");
            system("del .wget-hsts");
            code();
        }
        else {
            cout << "Error!We can't get a version list because your version is coming from a future version, so we don't support it.\n";
            system("del update.txt");
            system("del .wget-hsts");
            code();
        }
    }
    else if(command == "time" || command == "TIME"){
        time_t now = time(0);  
        char* dt = ctime(&now);
        cout << dt;
        code();
    }
    else if (command == "info" || command=="INFO") {
        cout<< "Jcst Programm Ver.1.0.\nThis ver. is SET/UPDATE Update!\nBy.ZSJun.\n";
        code();
    }
    else if(command == "saveset"||command =="SAVESET"){
        ofstream mcfile; //创建对象
        mcfile.open("set.txt"); //创建文件
        mcfile << color;  //写入内容
        mcfile.close(); //关闭
        code();
    }
    else if(command=="readset"||command=="READSET"){
        ifstream readFile("set.txt");
        readFile >> command;
        readFile.close();
        system(("color " + command).c_str());
        code();
    }
    else if(command =="delset"||command=="DELSET"){
        system("del set.txt");
        code();
    }
    else{
        cout << "Erorr!Unknow command!\n";
        code();
    }
}

int main(int argc, char **argv){ //主函数
    CHAR c[MAX_PATH];
    DWORD result = GetCurrentDirectoryA(MAX_PATH, c);
    std::string direy(c);
    std::string wgetDir(direy);
    wgetDir+="\\wget.exe";
    std::string cmd = wgetDir+" https://54zsjun.github.io/Jcst.github.io/update.txt";
    system(cmd.c_str());
    ifstream readFile("update.txt");
    int ret;
    readFile >> ret;
    readFile.close();
    if (ret > 1) {
        cout << "Updated versionavailable for upgrades, please go to https://zsjun.lanzous.com/b0de1y5zi download!\n";
        Sleep(5 * 1000);
        system("start https://zsjun.lanzous.com/b0de1y5zi");
        system("del update.txt");
        system("del .wget-hsts");
    }
    system("del upgrade.txt");
    system("del .wget-hsts");
    system("cls");
    cout << "------------------------------------------------\n"; //开始大屏
    cout << "| Jcst Program                         Ver.1.0 |\n";
    cout << "| Now support:input,output,print,calculator!   |\n";
    cout << "| Now support:loop,time,update,color,cmd!      |\n";
    cout << "| Now support:notepad,shutdown,winver,readset! |\n";
    cout << "| Now support:saveset,delset!                  |\n";
    cout << "| Enter 'help' to get help!                    |\n";
    cout << "| Jcst QQ group chat:838496401                 |\n";
    cout << "| By.ZSJun                           2020-6-15 |\n";
    cout << "------------------------------------------------\n";
    code();
}