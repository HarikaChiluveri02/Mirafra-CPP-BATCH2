#include<cstring>
#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
class File
{
int fd;

public:
//Constructor:Acuire resource
File(const char* path)
{
fd=open(path,O_RDWR|O_CREAT|O_TRUNC,0644);
cout<<fd<<endl;
}

void writeintofile(const char* data)
{
if(fd>=0)
write(fd,data,strlen(data));
lseek(fd,0,SEEK_SET);
}

void readfromfile() {
    char arr[100];
    ssize_t bytesRead = read(fd, arr, 99); // Read up to 99 bytes
	cout<<bytesRead<<endl;
    if (bytesRead >= 0) {
        arr[bytesRead] = '\0'; // Properly null-terminate at the correct position
        cout << "Content in file: " << arr << endl;
    }
}


//Destructor :Relaese resource
~File()
{
if(fd>=0)
{
close(fd);
}
}

};

int main()
{
File f("file.txt");
cout<<"Doing some work...."<<endl;
f.writeintofile("Training DAY1");
cout<<"Reading from the file"<<endl;
f.readfromfile();
return 0;
}
