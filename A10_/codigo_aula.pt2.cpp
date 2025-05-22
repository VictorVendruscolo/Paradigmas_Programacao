#include<iostream>
#include<string>
using namespace std;

class DFrac{  //manteremos sempre a fração reduzida
    int num;
    unsigned den;

        unsigned mmc(DFrac other) const{
            unsigned n1,n2,div,mmc;

            n1  = den;
            n2  = other.den;
            mmc = 1;
            div = 2;

            while(n1>1 || n2>1){
                if(!(n1 % div) || !(n2 % div)){
                    if(!(n1 % div))
                        n1 = n1/div;
                    if(!(n2 % div))
                        n2 = n2/div;
                    mmc = mmc * div;
                }
                else
                    div++;
            }
            return mmc;
        }

        unsigned mdc(DFrac other) const{
            //tem que ajustar o mdc para fazer a simplificação
            unsigned n1,n2,div,mdc;

            n1  = den;
            n2  = other.den;
            mdc = 1;
            div = 2;

            while(n1>1 || n2>1){
                if(!(n1 % div) || !(n2 % div)){
                    if(!(n1 % div)&&!(n2 % div))
                        mdc = mdc * div;
                    if(!(n1 % div))
                        n1 = n1/div;
                    if(!(n2 % div))
                        n2 = n2/div;
                }
                else
                    div++;
            }
            return mdc;
        }


    public:
        DFrac(int num=0,unsigned den=1):
            num(num),
            den(den)
        {}

        int getNum(){
            return num;
        }
        unsigned getDen(){
            return den;
        }

        // operadores de atribuição
        // =, +=, -=, *=, /=
    
        DFrac operator +(const DFrac &other) const{
            unsigned mmc = this->mmc(other);

            return DFrac(mmc/den*num + mmc/other.den*other.num ,mmc);
        }
        DFrac operator -(const DFrac &other) const{
            unsigned mmc = this->mmc(other);
            return DFrac(mmc/den*num - mmc/other.den*other.num, mmc);
        }
        DFrac operator *(const DFrac &other) const{
            return DFrac(num * other.num, den * other.den);
        }
        DFrac operator /(const DFrac &other) const{
            return DFrac(num * other.den, den * other.num);
        }
        Dfrac operator ++(){ //pré fixado
            num+=den;
            return *this;
        }
        Dfrac operator ++(int){ //pós fixado
            int oldNum = num;
            num+=den;
            return Dfrac(oldNum,den);
        }

        // operadores de comparação
        // <, >, <=, >=, ==, !=

        bool operator < (const DFrac &other) const{            
            unsigned mmc = this->mmc(other);

            return ((int)(mmc/den)*num - (int)(mmc/other.den)*other.num) < 0;
        
        }
        bool operator > (const DFrac &other) const{
            unsigned mmc = this->mmc(other);
            return (mmc/den*num - mmc/other.den*other.num) > 0;
        }
        bool operator <= (const DFrac &other) const{
            unsigned mmc = this->mmc(other);
            return (mmc/den*num - mmc/other.den*other.num) <= 0;
        }
        bool operator >= (const DFrac &other) const{
            unsigned mmc = this->mmc(other);
            return ((int)(mmc/den)*num - (int)(mmc/other.den)*other.num) >= 0;
        }
        bool operator == (const DFrac &other) const{
            unsigned mmc = this->mmc(other);
            return (mmc/den*num - mmc/other.den*other.num) == 0;
        }
        bool operator != (const DFrac &other) const{
            return !(*this == other);
        }


};
int main(){
    //tarefa: implementar os operadores binários -, *, /, >, <= e >=

    DFrac f1,f2(1,2),f3(1,3);
    bool b;

    f1 = f2 + f3;
    b  = f2 < f3;
    f1 = f2 - f3;
    f1 = f2 * f3;
    f1 = f2 / f3;
    b  = f2 > f3;
    b  = f2 <= f3;
    b  = f2 >= f3;
    b  = f2 == f3;
    b  = f2 != f3;

    cout<<f1.getNum()<<'/'<<f1.getDen();

    return 0;
}