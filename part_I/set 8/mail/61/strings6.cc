#include "strings.ih"

Strings::Strings(Strings &&tmp)
:
    d_size(tmp.d_size),
    d_str(tmp.d_str)
{
    tmp.d_str = nullptr;
}
