#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class FileHandler
{
    FILE * fp;
    char name[100];
public:
    FileHandler(char *nm)
    {
        strcpy(name,nm);
        fp = fopen(nm, "r");
    }
    FileHandler(const FileHandler& FH)
    {
        strcpy(name,FH.name);
        fp = fopen(name, "r");
    }
    friend void printContent(FileHandler fh);
    friend void printVowelCount(FileHandler fh);

    ~FileHandler()
    {
        fclose(fp);
    }

};
void printContent(FileHandler fh)
{
    char line[100];//Let, each line-length <100
    while(!feof(fh.fp))
    {
        fgets(line, 100, fh.fp);   //read one line
        cout<<line<<endl; //print the line
    }

}
void printVowelCount(FileHandler fh)
{
    char ch;//Let, each line-length <100
    int vwlCnt=0;
    while(!feof(fh.fp))
    {
        ch=fgetc(fh.fp);
        if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            vwlCnt++;

    }
    cout<<vwlCnt<<endl;
}

int main()
{
    FileHandler file("input.txt");
    printContent(file);
    printVowelCount(file);

}
