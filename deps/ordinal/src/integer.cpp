# include "string"
# include "ordinal.hpp"
# include "integer.hpp"
using namespace std;

Integer::Integer(int _value){
    value = _value;
}

bool Integer::is_zero(){
    return value == 0;
}

bool Integer::has_fs(){
    return false;
}

bool Integer::is_successor(){
    return value != 0;
}

Integer* Integer::predecessor(){
    if(value == 0)
        throw "Error: Trying to get the predecessor of zero.";
    else
        return decrement();
}

string Integer::latex(bool final, bool textstyle){
    char str[64];
    sprintf(str, "%d", value);
    if(final){
        if(textstyle)
            sprintf(str, "$%s$", str);
        else
            sprintf(str, "$$%s$$", str);
    }
    return string(str);
}

string Integer::text(bool final){
    char str[64];
    sprintf(str, "%d", value);
    return string(str);
}

Integer* Integer::decrement(){
    return new Integer(value - 1);
}