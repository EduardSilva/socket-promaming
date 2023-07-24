#include <string>
    using std::string;

struct dataMensage
{
    char data [1024];
    char data_extesion[5];
    char type = 'M';

};

struct controlMensage
{
    char data [5];
    char type  = 'C';
};

struct TextMensage
{
    char data [1024];
    char type = 'T';
};
