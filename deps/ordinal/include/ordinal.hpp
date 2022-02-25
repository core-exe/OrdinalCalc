# pragma once
# include <string>
using namespace std;

class Ordinal{
    public:
    Ordinal(){}
    ~Ordinal(){}

    virtual bool is_zero();
    virtual bool has_fs();
    virtual bool is_successor();
    virtual Ordinal* operator[](int i);
    virtual Ordinal* predecessor();

    virtual string latex(bool final = false, bool textstyle = false);
    virtual string text(bool final = false);

    private:
    virtual Ordinal* get_fs(int i);
    virtual Ordinal* decrement();
};