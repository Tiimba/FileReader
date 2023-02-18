#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


class FileTeste{
	public:
		string filePath;

		FileTeste(string x){
			filePath = x;
		}	

		void writeFile(string text){
			ofstream MyFile(filePath);
		        MyFile << text;
	    		MyFile.close();
		}
		
		void appendFile(string text){
			ofstream MyFile(filePath, ios_base::app);
			MyFile << endl  << text;
			MyFile.close();
		}

		void readFile(){
		        string linha;
		        ifstream MyReadFile(filePath);
		        while(getline(MyReadFile, linha)){
		                cout << linha << endl;
		        }
			cout << endl;
		        MyReadFile.close();
		}
};

void readFile(string filePath){
	string linha;
	ifstream MyReadFile(filePath);
	while(getline(MyReadFile, linha)){
		cout << linha;
	}
	MyReadFile.close();
}

int main(int argc, char* argv[]){
	if (strcmp(argv[1], "-help") == 0 || strcmp(argv[1], "-h") == 0){
		cout << "Usage:\n\t ./file mode file-name \"Input Data\"\n\nExamples: \n\tAPPEND:\t./file append tryout.txt \"Lorem ipsum dolor sit amet.\"\n\tWRITE:\t../file write tryout.txt \"Lorem ipsum dolor sit amet.\"\n\tREAD:\t./file read tryout.txt" << endl;
		return 0;
	}
	if (argc < 3){
		cout << "Please inform the mode, file and the input, if apppend or write mode.\nExample: ./file mode file-name \"Input Data\"";
		return 0;
	
	}
	FileTeste testeObj(argv[2]);
	int equalEscrita = strcmp(argv[1], "write");
	int equalLeitura = strcmp(argv[1], "read");
	int equalAppend = strcmp(argv[1], "append"); 

	if (equalEscrita == 0) {
		if (argc == 4){
			testeObj.writeFile(argv[3]);

		}else{
			cout << "Pendente informar o texto que sera escrito" << endl;

		}
	}else if(equalLeitura == 0){
		testeObj.readFile();
			

	}else if(equalAppend == 0){
		if (argc == 4){
                        testeObj.appendFile(argv[3]);

                }else{
                        cout << "Pendente informar o texto que sera escrito" << endl;
                }
	}

	else{
		cout << "O modo " <<  argv[1] << " não existe favor escolher entre leitura ou escrita" << endl;
	}
	return 0;
}
