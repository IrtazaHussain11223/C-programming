#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;
int main(int argc,char* argv[])
{
char* name=argv[1];
if(argc != 2) {
cerr << "usage: " << argv[0] << " <filename>" << endl;
return 1;
}
pid_t child=fork();
if(child==0)
{
execlp("cat","cat",name,NULL);
exit(0);
}
else
{
wait(NULL);
pid_t child2=fork();
{
if(child2==0)
{
execlp("wc","wc",name,NULL);
exit(0);

}
else
{
wait(NULL);

}
}
}
}
