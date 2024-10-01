#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string compress(string data){
    string compressed="";
    int count=1;
    for (int i=0;i<data.length();i++){
        if(i+1<data.length()&&data[i]==data[i+1]){
            count++;
        }
		else{
            compressed+=data[i];
            compressed+=to_string(count);
            count=1;
        }
    }
    return compressed;
}
string decompress(string data){
    string decompressed="";
    for (int i=0;i<data.length();i+=2){
        char character=data[i];
        int count=data[i+1]-'0';
        decompressed.append(count, character);
    }
    return decompressed;
}
string readFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()){
        cout<<"Could not open the file "<<filename<<endl;
        return "";
    }
    string content((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
    file.close();
    return content;
}
void writeFile(string filename,string content){
    ofstream file(filename);
    if (!file.is_open()){
        cout<<"Could not open the file "<<filename<<endl;
        return;
    }
    file<<content;
    file.close();
}
int main(){
    string inputFile="input.txt";
    string compressedFile="compressed.rle";
    string decompressedFile="decompressed.txt";
    string data=readFile(inputFile);
    if(data==""){
        cout<<"Error: Input file is empty or could not be read!"<<endl;
        return 1;
    }
	string compressedData=compress(data);
	    while(true){
	    	start:
		    cout<<"Choose 1,2,3: "<<endl;
		    cout<<"1.Compress Data"<<endl;
		    cout<<"2.Decompress data"<<endl;
		    cout<<"3.exit"<<endl;
		    int sel;
	        cin>>sel;
	        switch(sel){
		    	case 1:{					
		    		writeFile(compressedFile,compressedData);
		    		cout<<"Compressed data saved to "<<compressedFile<<endl;
		    		break;
	            }
	            case 2:{
					string decompressedData=decompress(compressedData);
		    		writeFile(decompressedFile,decompressedData);
		    		cout<<"Decompressed data saved to "<<decompressedFile<<endl;    
		    		break;
	            }
				case 3:{
					cout<<"Program terminated successfully"<<endl;
					return 0;
					break;
				}
				default:{
					cout<<"Please enter 1,2,3 nothing else..."<<endl;
					goto start;
			}
			}
			int s;
			cout<<"1.continue"<<endl;
			cout<<"Any other key to exit"<<endl;
			cin>>s;
			if(s==1){
				goto start;
			}
			else{
				break;
			}
			
	}
	return 0;
}