# include <string>
# include "ordinal.hpp"
using namespace std;

bool Ordinal::is_zero(){
    return false;
}

bool Ordinal::has_fs(){
    return false;
}

bool Ordinal::is_successor(){
    return false;
}

Ordinal* Ordinal::operator[](int i){
    if(this->has_fs()){
        return this->get_fs(i);
    } else {
        throw "Error: Trying to get the fundamental sequence of a successor ordinal.";
    }
}

Ordinal* Ordinal::predecessor(){
    if(this->is_successor()){
        return this->decrement();
    } else {
        throw "Error: Trying to get the predecessor of a limit ordinal.";
    }
}

string Ordinal::latex(bool final, bool textstyle){
    return string("");
}

string Ordinal::text(bool final){
    return string("");
}

Ordinal* Ordinal::get_fs(int i){
    return new Ordinal();
}

Ordinal* Ordinal::decrement(){
    return new Ordinal();
}