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

    string latex(bool final = false, bool textstyle = false);
    string text(bool final = false);

    private:
    Ordinal decrement();
};