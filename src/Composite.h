#ifndef __COMPOSITE_H__
#define __COMPOSITE_H__


using namespace std;

class Base {

    public:
        /* Constructors */
        Base() {}
        
        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
};


class Op: public Base {
    private:
        double value;
    public:
        Op(double v) {
            value = v;
        }
        
        double evaluate() {
            return value;
        }
        
};

class Mult: public Base {
    protected:
        Base* left;
        Base* right;
    
    public:
        Mult(Base* l, Base* r) {
            left = l;
            right = r;
        }
        
        double evaluate() {
            return (*left).evaluate() * (*right).evaluate();
        }
};

class Sub: public Base {
    protected:
        Base* left;
        Base* right;
           
    public:
        Sub(Base* l, Base* r) {
            left = l;
            right = r;
        }
        
        double evaluate() {
            return (*left).evaluate() - (*right).evaluate(); 
        }
};

class Add: public Base {
    protected:
        Base* left;
        Base* right;
        
    public:
        Add(Base* l, Base* r) {
            left = l;
            right = r;
        }
        
        double evaluate() {
            return(*left).evaluate() + (*right).evaluate();
        }
};


class Sqr: public Base {
    protected:
        Base* op;
     //   Base* right;
    public:
        Sqr(Base* l) {
            op = l;
        }
            double evaluate() {
                return (*op).evaluate() * (*op).evaluate(); 
        }
};
#endif // __COMPOSITE_H__