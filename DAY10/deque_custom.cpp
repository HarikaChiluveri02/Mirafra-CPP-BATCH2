#include <iostream>
using namespace std;

class Deque
{
static const int TABLE_SIZE=4;
static const int BLOCK_SIZE=4;

int** block_table;
int start_offset,end_offset,current_size,start_block,end_block;

public:
Deque()
{
block_table= new int*[BLOCK_SIZE];
for(int i=0;i<TABLE_SIZE;i++)
{
block_table[i]=NULL;
}
start_block = end_block = TABLE_SIZE/2 ;  //Emty block are avaible at front and back easy for middle insertion
block_table[start_block]=new int[BLOCK_SIZE];
start_offset=0;
end_offset=0;
current_size=0;
}

void realloc()
{
int newtablesize=(TABLE_SIZE*2);
int **newblocktable=new int*[newtablesize];
for(int i=0;i<newtablesize;i++)
{
newblocktable[i]=NULL;
}
int newstart=(newtablesize-((end_block-start_block)+1))/2 ;

for(int i=start_block,j=newstart;i<=end_block;i++,j++)
{
newblocktable[j]=blocktable[i];
}
delete[] blocktable;


}
void push_back(int value)
{
if(end_offset==BLOCK_SIZE)
{

if(end_block+1 > TABLE_SIZE)
realloc();

end_block++;
block_table[end_block]=new int[BLOCK_SIZE];
end_offset=0;
}
block_table[end_block][end_offset++]=value;
current_size++;
}

void push_front(int value)
{
if(start_offset > 0)
{
start_offset--;
}
else
{

if(start_blok-1 < 0)
realloc();

start_block--;
block_table[start_block]=new int[BLOCK_SIZE];
start_offset=BLOCK_SIZE-1;

}
block_table[start_block][start_offset]=value;
current_size++;
}

int operator[](int index)
{
int total_offset=start_offset+index;
int block = start_block +(total_offset/BLOCK_SIZE);
int offset = total_offset % BLOCK_SIZE;
return block_table[block][offset];
}

int size()const
{
return current_size;
}

~Deque()
{
for(int i=0;i<BLOCK_SIZE;i++)
{
delete[] block_table[i];
}
delete[] block_table;
}
};
int main() {
    Deque obj;
obj.push_back(100);
obj.push_back(99);
obj.push_front(10);
obj.push_front(20);

/*cout<<obj[0]<<endl;
cout<<obj[1]<<endl;
cout<<obj[2]<<endl;
cout<<obj[3]<<endl;*/

for(int i=0;i<obj.size();i++)
cout<<obj[i]<<" ";
cout<<endl;
    return 0;
}



