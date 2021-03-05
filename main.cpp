#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void lzw(vector<string> &dicionario, string str)
{
    string result;
    string p;
    string c;
    for (int i = 0; i < str.size(); i++)
    {
        c = "";
        c.push_back(str.at(i));
        string pc = p + c;
        std::vector<string>::iterator it = find(dicionario.begin(), dicionario.end(), pc);
        if (it != dicionario.end())
        {
            p = pc;
        }
        else
        {
            dicionario.push_back(pc);
            std::vector<string>::iterator it = find(dicionario.begin(), dicionario.end(), p);
            if (it != dicionario.end())
            {
                int index = it - dicionario.begin();
                result = result + " " + to_string(index);
            }
            p = c;
        }
    }
    std::vector<string>::iterator it = find(dicionario.begin(), dicionario.end(), p);
    if (it != dicionario.end())
    {
        int index = it - dicionario.begin();
        result = result + " " + to_string(index);
    }
    cout << result << endl;
}
void asc2Add(vector<string> &vet)
{
    for (int i = 0; i < 256; i++)
    {
        string aux(1, (char)i);
        vet.push_back(aux);
    }
}

string LeituraArquivo(ifstream &arq)
{
    string str;
    if (arq.is_open())
    {
        getline(arq, str);
    }
    return str;
}

int main(int argc, char *argv[])
{
    ifstream arq;
    string str;
    vector<string> dicionario;
    arq.open(argv[1], ios::in);
    str = LeituraArquivo(arq);
    asc2Add(dicionario);
    lzw(dicionario, str);

    return 0;
}