#include <iostream>
#include <fstream>
using namespace std;

void button(char letter,int times);

int main(int argc,char **argv){

    if(argc!=2){
        cout << "Usage: ./flip <file to decode>\n";
        return 1;
    }

    ifstream file(argv[1]);

    if(!file.is_open()){
        cout << "Failed to open " << argv[1] << endl;
        return 1;
    }

    file.seekg(0,ios::end);
    int fileSize = file.tellg();
    file.seekg(0,ios::beg);

    char *text = new char[fileSize];

    if(text==nullptr){
        cout << "Failed to allocate memory\n";
        return 1;
    }

    file.read(text,fileSize);
    file.close();

    int i,times=1;
    char val = text[0];
   
    for(i=1;i<fileSize;i++){
        if(text[i]!=val){
            button(text[i-1],times);
            times = 1;
            val = text[i];
        }
        else{
            times++;
        }
    }

    cout << endl;
    delete text;
    
    return 0;
}