#include<iostream>
#include<thread>
#include<fstream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
using namespace std;
void handleClient(int clientSocket){
    char buffer[1024]={0};
    read(clientSocket,buffer,1024);
    ifstream file("index.html");
    if (file){
        string response="HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
        string content((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
        response+=content;
        send(clientSocket,response.c_str(),response.size(),0);
    }
	else{
        string notFound="HTTP/1.1 404 Not Found\r\n\r\n";
        send(clientSocket,notFound.c_str(),notFound.size(),0);
    }
    close(clientSocket);
}
int main() {
    int serverSocket,clientSocket;
    struct sockaddr_in address;
    int addrlen=sizeof(address);
    serverSocket=socket(AF_INET,SOCK_STREAM,0);
    address.sin_family=AF_INET;
    address.sin_addr.s_addr=INADDR_ANY;
    address.sin_port=htons(8080);
    bind(serverSocket,(struct sockaddr*)&address,sizeof(address));
    listen(serverSocket,3);
    cout<<"Listening on port 8080...\n";
    while (true){
        clientSocket=accept(serverSocket,(struct sockaddr*)&address,(socklen_t*)&addrlen);
        cout<<"Client connected...\n";
        thread clientThread(handleClient,clientSocket);
        clientThread.detach();
    }
    return 0;
}