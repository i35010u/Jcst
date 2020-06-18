#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main(int argc, char **argv) {
    CHAR c[MAX_PATH];
    DWORD result = GetCurrentDirectoryA(MAX_PATH, c);
    std::string direy(c);
    std::string wgetDir(direy);
    wgetDir+="\\wget.exe";
    std::string cmd = wgetDir+" https://54zsjun.github.io/Jcst.github.io/update.txt";
    system(cmd.c_str());
}