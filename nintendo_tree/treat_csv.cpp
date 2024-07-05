#include <iostream>
#include <fstream>

void clean_csv(std::string csvFile, std::string newCSVFile)
{
    std::ifstream arquivo(csvFile);
    std::ofstream novo_arquivo(newCSVFile);

    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo de leitura!" << std::endl;
        return;
    }

    if (!novo_arquivo.is_open())
    {
        std::cerr << "Erro ao criar o arquivo de escrita!" << std::endl;
        return;
    }

    char caractere;

    bool coma_active = false;

    while (arquivo.get(caractere))
    {
        if (caractere == '"')
        {
            if (coma_active) coma_active = false;
            else coma_active = true;
        }

        if (coma_active)
        {
            if (caractere == '\n') novo_arquivo.put(',');
            else novo_arquivo.put(caractere);
        }
        else novo_arquivo.put(caractere);
    }

    arquivo.close();
    novo_arquivo.close();
}

int main()
{
    clean_csv("SNES.csv", "newSNES.csv");
}