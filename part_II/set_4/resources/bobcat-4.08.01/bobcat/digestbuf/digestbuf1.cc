#include "digestbuf.ih"

DigestBuf::DigestBuf(char const *type, size_t bufsize)
:
    d_pimpl(new DigestBufImp(bufsize))
{
    try
    {
        OpenSSL_add_all_digests();
        d_pimpl->md = EVP_get_digestbyname(type);

        if (!d_pimpl->md)
        {
            if (type == 0)
                type = "** unspecified digest type **";
    
            throw Exception{1} << "DigestBuf `" << type << "' not available";
        }
        d_pimpl->buffer = new char[bufsize];
        open();
    }
    catch (...)
    {
        delete d_pimpl;
        throw;
    }
}
