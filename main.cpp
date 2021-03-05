
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void lzw(vector<string> &dicionario)
{
    string teste = "bananabanabofana";
    string result;
    string p;
    string c;
    for (int i = 0; i < teste.size(); i++)
    {
        c = "";
        c.push_back(teste.at(i));
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
                result = result + " " +  to_string(index);
            }
            p = c;
        }
    }
    std::vector<string>::iterator it = find(dicionario.begin(), dicionario.end(), p);
    if (it != dicionario.end())
    {
        int index = it - dicionario.begin();
        result = result + " " +  to_string(index);
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

int main()
{

    vector<string> dicionario;
    asc2Add(dicionario);
    lzw(dicionario);

    return 0;
}