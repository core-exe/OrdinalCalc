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

    string latex(bool final = true, bool textstyle = false);
    string text(bool final = true); // TODO

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

cnf_term w_exp(CantorNormalForm* exp, Integer coef = Integer(1));
cnf_term w_exp(Integer exp, Integer coef = Integer(1));
cnf_term w_exp(cnf_term exp, Integer coef = Integer(1));

cnf_term cnf_term_int(Integer integer);
cnf_term cnf_term_int(int integer);