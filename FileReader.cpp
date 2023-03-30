#include <iostream>
#include <vector>
using namespace std;
class ReadFiles
{
    // class that read files
public:
    vector<vector<string>> content;
    vector<string> row;
    string word;
    string strLine;
    string filePath;
    ReadFiles(string filePath)
    {
        this->filePath = filePath;
    }

    void FileReader()
    {
        ifstream fileStream(filePath);
        if (fileStream.is_open())
        {
            while (getline(fileStream, strLine))
            {
                cout << strLine << '\n';
            }
            fileStream.close();
        }
        else
        {
            cout << "file is clossed!" << '\n';
        }
    }

    vector<vector<string>> CVSReader()
    {
        ifstream fileStream(filePath);
        if (fileStream.is_open())
        {
            while (getline(fileStream, strLine))
            {
                row.clear();
                stringstream strWord(strLine);
                while (getline(strWord, word, ','))
                {
                    row.push_back(word);
                }
                content.push_back(row);
            }
            cout << "File is Opened!";
            cout << '\n';
        }
        else
        {
            cerr << "File Did Not Open!";
        }
        return content;
    }

    void printContent()
    {
        for (int i = 0; i < content.size(); i++)
        {
            for (int j = 0; j < content[i].size(); j++)
            {
                cout << content[i][j] << "  ";
            }
            cout << '\n';
        }
    }
};

int main()
{
    ReadFiles raedFiles = ReadFiles("c:\\Path....");
    
    return 0;
}
