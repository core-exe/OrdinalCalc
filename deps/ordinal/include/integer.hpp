# pragma once
# include "ordinal.hpp"

class Integer: public Ordinal{
    public:
    int value;

    Integer(int _value = 0);
    ~Integer(){}

    bool is_zero();
    bool has_fs();
    bool is_successor();
    Integer* predecessor();

    string latex(bool final = true, bool textstyle = false);
    string text(bool final = true);

    private:
    Integer* decrement();
};