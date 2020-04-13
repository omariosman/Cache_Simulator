#include <Dispatcher.h>

Dispatcher::Dispatcher(DirectMap * p_directMap,char * filename)
{
std::cout << "constructor dispatcher" << std::endl;
    directMap = p_directMap;
    f = fopen (filename,"r");
    if ( f == NULL )
    {
        printf ("Invalide file name: %s\n",filename);
        exit(1);
    }
}
bool Dispatcher::dispatch ()
{
std::cout << "dispatch" << std::endl;
    if ( f != NULL)
    {
        uint64_t address;
        char skip[100];
        char mode;
        int r = fscanf(f, "%s %c %llx\n", skip, &mode,&address);

        while (r != EOF)
        {
            //Write your code here
	    directMap->access(address, mode);
            r = fscanf(f, "%s %c %llx\n", skip, &mode,&address);
        }
        return true;
    }
    else return false;
}
Dispatcher::~Dispatcher()
{
    if ( f != NULL) fclose (f);
}
