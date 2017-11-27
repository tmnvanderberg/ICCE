#include "strings.ih"

void Strings::add(string const &next)
{
    string *tmp = storageArea();    // enlarge if no more room for 'next'

    new (&tmp[d_size]) string(next);

    if (tmp != d_str)               // destroy old memory if new storageArea 
    {                               // was allocated
        destroy();                  // destroy the old string * array
        d_str = tmp;
    }

    ++d_size;
}
