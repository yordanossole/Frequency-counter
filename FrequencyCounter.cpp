#include <iostream>
#include <fstream>

using namespace std;

fstream file;

void writeToFile(string fName, string name[])
{
    file.open(fName, ios::out);

    if(file.is_open())
    {
        for(int i=0; i<5; i++)
        {
            file << name[i] << " ";
        }

        file.close();
    }
}

void copyFromFile(string fName, string *temp)
{
    file.open(fName, ios::in);

    if(file.is_open())
    {
        for(int i=0; i<5; i++)
        {
            file >> temp[i];
        }
        file.close();
    }
}

void appendToFile(string fName, string *temp)
{
    file.open(fName, ios::app);

    if(file.is_open())
    {
        for(int i=0; i<5; i++)
        {
            file << temp[i] << " ";
        }
        file.close();
    }
}
void frequencyCounter(string *temp)
{
    for (int x=0; x<10; x++){
        bool counted = false;

        for(int y=0; y<x; y++)
        {
            if(temp[x] == temp[y])
            {
                counted = true;
                break;
            }
        }

       if(!counted)
       {
            int counter = 0;
            for (int y=0; y<10; y++)
            {
                if (temp[x] == temp[y])
                {
                    counter++;
                }
            }
        cout << "\nThe frequency of " << temp[x] << " is " << counter ;
       }
    }
}

int main()
{
    string name[5] = {"Abel", "Yordanos" ,"Lema" , "Alazar", "Abebe"};
    string name2[5] = {"Yordanos", "Solomon", "Lema" , "Lema", "Lema"};
    string temp[5];

    writeToFile("names.txt", name);
    writeToFile("names2.txt", name2);
    copyFromFile("names2.txt", temp);
    appendToFile("names.txt", temp);
    copyFromFile("names.txt", temp);
//Display the content in temp[]

    for(int i=0; i<10; i++)
    {
        cout << temp[i] << " ";
    }
    frequencyCounter(temp);
}
