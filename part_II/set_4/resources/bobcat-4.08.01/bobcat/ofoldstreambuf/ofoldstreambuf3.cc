#include "ofoldstreambuf.ih"

OFoldStreambuf::OFoldStreambuf(ostream &stream, size_t indent, 
                        size_t rightMargin,
                        TabsOrBlanks tob, TrailingBlanks tb)
:
    OFilterStreambuf(stream),
    d_rightMargin(rightMargin),
    d_indent(indent),
    d_reqIndent(false),
    d_wsLength(0),
    d_next(0),
    d_mode(INDENT),
    d_handleTrailingBlanks(tb == HANDLE_TRAILING_BLANKS)
{
    s_buffers.push_back(this);
    iniBlankTabs(tob);
}
