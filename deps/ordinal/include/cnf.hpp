# pragma once
# include <vector>
# include <tuple>
# include "ordinal.hpp"
using namespace std;

class Integer;

class CantorNormalForm{
    public:
    vector<tuple<CantorNormalForm*, Integer>> terms;

    CantorNormalForm();
    CantorNormalForm(Integer _int);
    CantorNormalForm(vector<tuple<CantorNormalForm*, Integer>> _terms);

    bool is_zero();
    bool has_fs();
    bool is_successor();
    bool is_int();
    CantorNormalForm* operator[](int i);
    CantorNormalForm* predecessor();

    string latex(bool final = false, bool textstyle = false);
    string text(bool final = false); // TODO

    Integer* to_integer();

    private:
    CantorNormalForm* decrease_last();
    CantorNormalForm* get_fs(int i);
    CantorNormalForm* decrement();
    int length();
};

typedef CantorNormalForm CNF;
typedef tuple<CantorNormalForm*, Integer> cnf_term;
typedef vector<cnf_term> cnf_terms;