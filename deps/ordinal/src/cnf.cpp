# include <vector>
# include <tuple>
# include <string>
# include <iostream>
# include "ordinal.hpp"
# include "integer.hpp"
# include "cnf.hpp"
using namespace std;

CantorNormalForm ZERO_CNF = CantorNormalForm();

CantorNormalForm::CantorNormalForm(){
    terms = vector<tuple<CantorNormalForm*, Integer>>();
}

CantorNormalForm::CantorNormalForm(Integer _int){
    terms = vector<tuple<CantorNormalForm*, Integer>>();
    if(!_int.is_zero())
        terms.push_back(tuple<CantorNormalForm*, Integer>(&ZERO_CNF, _int));
}

CantorNormalForm::CantorNormalForm(vector<tuple<CantorNormalForm*, Integer>> _terms){
    terms = _terms;
}

bool CantorNormalForm::is_zero(){
    return terms.size() == 0;
}

bool CantorNormalForm::has_fs(){
    return !is_zero() && !std::get<0>(terms[terms.size()-1])->is_zero();
}

bool CantorNormalForm::is_successor(){
    return !is_zero() && std::get<0>(terms[terms.size()-1])->is_zero();
}

bool CantorNormalForm::is_int(){
    return is_zero() || (terms.size() == 1 && std::get<0>(terms[0])->is_zero());
}

CantorNormalForm* CantorNormalForm::operator[](int i){
    if(has_fs()){
        return get_fs(i);
    } else {
        throw "Error: Trying to get the fundamental sequence of a successor ordinal.";
    }
}

CantorNormalForm* CantorNormalForm::predecessor(){
    if(this->is_successor()){
        return this->decrement();
    } else {
        throw "Error: Trying to get the predecessor of a limit ordinal.";
    }
}

string CantorNormalForm::latex(bool final, bool textstyle){
    string s = string("");
    if(is_zero())
        s = string("0");
    vector<string> str_for_term = vector<string>();
    for(int i=0; i<terms.size(); i++){
        Integer coef = get<1>(terms[i]);
        CNF* exp = get<0>(terms[i]);
        if(exp->is_zero())
            str_for_term.push_back(coef.latex(false, textstyle));
        else if(exp->is_int() && get<1>(exp->terms[0]).value == 1) {
            if(coef.value == 1)
                str_for_term.push_back(string("\\omega"));
            else
                str_for_term.push_back(string("\\omega")+coef.latex(false, textstyle));
        } else if(coef.value == 1)
            str_for_term.push_back(string("\\omega^{")
            +exp->latex(false, textstyle)
            +string("}"));
        else
            str_for_term.push_back(string("\\omega^{")
            +exp->latex(false, textstyle)
            +string("}")
            +coef.latex(false, textstyle));
    }
    for(int i=0; i<terms.size(); i++){
        if(i==0)
            s = str_for_term[i];
        else
            s = s + string("+") + str_for_term[i];
    }
    if(final){
        if(textstyle){
            s = string("$") + s + string("$");
        } else {
            s = string("$$") + s + string("$$");
        }
    }
    return s;
}

string CantorNormalForm::text(bool final){
    if(is_zero())
        return string("0");
    string s = string("");
    vector<string> str_for_term = vector<string>();
    for(int i=0; i<terms.size(); i++){
        Integer coef = get<1>(terms[i]);
        CNF* exp = get<0>(terms[i]);
        if(exp->is_zero())
            str_for_term.push_back(coef.text(false));
        else if(exp->is_int() && get<1>(exp->terms[0]).value == 1) {
            if(coef.value == 1)
                str_for_term.push_back(string("w"));
            else
                str_for_term.push_back(string("w*")+coef.text(false));
        } else if(coef.value == 1)
            str_for_term.push_back(string("w^")+exp->text(false));
        else
            str_for_term.push_back(string("w^")
            +exp->text(true)
            +string("*")
            +coef.text(false));
    }
    for(int i=0; i<terms.size(); i++){
        if(i==0)
            s = str_for_term[i];
        else
            s = s + string("+") + str_for_term[i];
    }
    if(!final && (terms.size()>1 || terms.size()==1 && !is_int() && get<1>(terms[0]).value>1)) {
        s = string("(") + s + string(")");
    }
    return s;
}

Integer* CantorNormalForm::to_integer(){
    if(is_zero())
        return new Integer(0);
    if(terms.size() == 1 && std::get<0>(terms[0])->is_zero())
        return &std::get<1>(terms[0]);
    throw "Error: This CNF ordinal is not equal to natural numbers.";
}

CantorNormalForm* CantorNormalForm::decrease_last(){
    Integer* last_coef = std::get<1>(terms[terms.size()-1]).predecessor();
    cnf_terms new_terms = cnf_terms(terms);
    new_terms.pop_back();
    if(!last_coef->is_zero())
        new_terms.push_back(tuple<CantorNormalForm*, Integer>(get<0>(terms[terms.size()-1]), *last_coef));
    return new CantorNormalForm(new_terms);
}

CantorNormalForm* CantorNormalForm::get_fs(int i){
    CNF* new_cnf = decrease_last();
    if(get<0>(terms[terms.size()-1])->has_fs()) {
        new_cnf->terms.push_back(cnf_term(
            (*(get<0>(terms[terms.size()-1])))[i],
            Integer(1)
            ));
    } else if(i != 0) {
        new_cnf->terms.push_back(cnf_term(
            get<0>(terms[terms.size()-1])->predecessor(),
            Integer(i)
        ));
    }
    return new_cnf;
}

CantorNormalForm* CantorNormalForm::decrement(){
    return decrease_last();
}

cnf_term w_exp(CantorNormalForm* exp, Integer coef){
    return cnf_term(exp, coef);
}

cnf_term w_exp(Integer exp, Integer coef){
    return cnf_term(new CNF(exp), coef);
}

cnf_term w_exp(cnf_term exp, Integer coef){
    return cnf_term(new CNF(cnf_terms({exp})), coef);
}

cnf_term cnf_term_int(Integer integer){
    return cnf_term(new CNF(), integer);
}

cnf_term cnf_term_int(int integer){
    return cnf_term(new CNF(), Integer(integer));
}