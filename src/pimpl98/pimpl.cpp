#include "pimpl.h"
#include <iostream>

using namespace std;

struct Pimpl::PimplImpl
{
    explicit PimplImpl(const string& name) : name_(name) { }
    string name_;
};

Pimpl::Pimpl(const string& name) : 
    impl_(new PimplImpl(name))
{
}

Pimpl::Pimpl(const Pimpl& other) : 
    impl_(new Pimpl::PimplImpl(*other.impl_)) // use PimplImpl copy constructor
{
}

Pimpl& Pimpl::operator=(const Pimpl& other)
{
    if (this != &other)
    {
        delete impl_;
        impl_ = 0; // needed in case the following line throws exception
        impl_ = new Pimpl::PimplImpl(*other.impl_); // use PimplImpl copy constructor
    }
    return *this;
}

Pimpl::~Pimpl()
{
    delete impl_;
}

void Pimpl::print() const
{
    cout << impl_->name_ << endl;
}