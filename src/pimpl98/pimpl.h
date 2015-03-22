#include <string>

class Pimpl
{
public:
    explicit Pimpl(const std::string& name); // must be explicit to prevent implicit conversion from string
    Pimpl(const Pimpl &other); // copy constructor
    Pimpl& operator=(const Pimpl &other); // copy assignment operator
    ~Pimpl(); // not declared as virtual because it is not a base class intended for polymorphic behaviour
    
    void print() const;
    
private:
    struct PimplImpl;
    PimplImpl* impl_;
};