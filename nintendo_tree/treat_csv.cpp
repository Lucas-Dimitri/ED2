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
    bool comma_active = false;

    while (arquivo.get(caractere))
    {   
        if (caractere == '"') comma_active = !comma_active;

        if (comma_active)
        {
            if (caractere == '\n') novo_arquivo.put(',');
            else novo_arquivo.put(caractere);
        }
        else novo_arquivo.put(caractere);
    }
    arquivo.close();
    novo_arquivo.close();
}

void clean_csv_second_part(std::string csvFile, std::string newCSVFile)
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
    bool comma_active = false;
    char last_char = '\n';

    while (arquivo.get(caractere))
    {
        if ((last_char == '\n' || last_char == ',') && (!comma_active) && (caractere != '"'))
        {
            novo_arquivo.put('"');
            comma_active = true;
        }

        if (caractere == ',' && comma_active && caractere != '"')
        {
            novo_arquivo.put('"');
            comma_active = false;
        }
        last_char = caractere;
    }

    arquivo.close();
    novo_arquivo.close();
}

int main()
{
    clean_csv("C:\\Users\\lucas\\OneDrive\\Documents\\faculdade\\terceiro semestre\\ED2\\nintendo_tree\\SNES.csv", "newSNES.csv");
    //clean_csv_second_part("C:\\Users\\lucas\\OneDrive\\Documents\\faculdade\\terceiro semestre\\ED2\\nintendo_tree\\output\\newSNES.csv", "test.csv");
}