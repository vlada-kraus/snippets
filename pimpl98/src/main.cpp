#include "pimpl.h"

int main()
{
    Pimpl p("johny");
    Pimpl q = p; // copy constructor
    Pimpl r("dan");
    r = q; // copy assignment operator
    p.print();
    q.print();
    r.print();
}