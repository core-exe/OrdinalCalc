# include <ordmath.hpp>
# include <iostream>
using namespace std;

void test_cnf(CNF cnf){
    cout << "Display:" << endl;
    cout << "LaTeX, textstyle = true: " << cnf.latex(true, true) << endl;
    cout << "LaTeX, textstyle = false: " << cnf.latex(true, false) << endl;
    cout << "plain text: " << cnf.text(true) << endl;
    cout << endl;
    cout << "Arithmatic:" << endl;
    cout << "Is zero: " << cnf.is_zero() << endl;
    bool is_successor = cnf.is_successor(), has_fs = cnf.has_fs();
    cout << "Is successor: " << is_successor << endl;
    if(is_successor)
        cout << "Predecessor: " << cnf.predecessor()->text() << endl;
    cout << "Has fundamental sequence: " << has_fs << endl;
    if(has_fs)
    {
        cout << "Fundamental sequence index " << 1 << " : " << cnf[1]->text() << endl;
        cout << "Fundamental sequence index " << 2 << " : " << cnf[2]->text() << endl;
        cout << "Fundamental sequence index " << 3 << " : " << cnf[3]->text() << endl;
    }
    cout << endl << endl;
}

int main(){
    // test integers
    Integer i0 = Integer(0), i2 = Integer(2);
    
    // display
    cout << "test Integer display:" << endl;
    cout << Integer(2).latex(true, true) << endl;
    cout << Integer(2).latex(true, false) << endl;
    cout << Integer(2).latex(false, false) << endl;
    cout << Integer(2).text(true) << endl << endl;

    // property
    cout << "test Integer display:" << endl;
    cout << i0.is_zero() << " " << i2.is_zero() << endl;
    cout << i0.is_successor() << " " << i2.is_successor() << endl;
    cout << i0.has_fs() << " " << i2.has_fs() << endl;
    cout << i2.predecessor()->latex(true, false) << endl << endl;

    // test cnf
    // 0, 2, w, w^w, w^w + 1, w^w + w^2*2
    CNF c0 = CNF(0),
    c1 = CNF(i2),
    c2 = CNF({w_exp(Integer(1))}),
    c3 = CNF({w_exp(w_exp(Integer(1)))}),
    c4 = CNF({w_exp(w_exp(Integer(1))), cnf_term_int(1)}),
    c5 = CNF({w_exp(w_exp(Integer(1))), w_exp(Integer(2), Integer(2))});

    test_cnf(c0);
    test_cnf(c1);
    test_cnf(c2);
    test_cnf(c3);
    test_cnf(c4);
    test_cnf(c5);
    return 0;
}