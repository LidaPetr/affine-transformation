#include <iostream>

using namespace std;

// Task1 : Define an affine transformation
class AffineTrans
{
    private:
        double m00, m01, m10, m11;
        double dx, dy;
    public:
        void setm00(double num);
        void setm01(double num);
        void setm10(double num);
        void setm11(double num);
        void setdx(double num);
        void setdy(double num);
        double getm00( void );
        double getm01( void );
        double getm10( void );
        double getm11( void );
        double getdx( void );
        double getdy( void );

        AffineTrans(double M[2][2], double d[2]);
};

AffineTrans::AffineTrans( double M[2][2], double d[2]){

    cout << "Affine Transformation is being created" << endl;
    // initialize the parameters
    setm00(M[0][0]);
    setm01(M[0][1]);
    setm10(M[1][0]);
    setm11(M[1][1]);
    setdx(d[0]);
    setdy(d[1]);
};

void AffineTrans::setm00(double num){
    m00 = num;
}
void AffineTrans::setm01(double num){
    m01 = num;
}
void AffineTrans::setm10(double num){
    m10 = num;
}
void AffineTrans::setm11(double num){
    m11 = num;
}
void AffineTrans::setdx(double num){
    dx = num;
}
void AffineTrans::setdy(double num){
    dy = num;
}
double AffineTrans::getm00(){
    return m00;
}
double AffineTrans::getm01(){
    return m01;
}
double AffineTrans::getm10(){
    return m10;
}
double AffineTrans::getm11(){
    return m11;
}
double AffineTrans::getdx(){
    return dx;
}
double AffineTrans::getdy(){
    return dy;
}

// Task2 : Implement a transformation function
void transf(double* x, double* y, AffineTrans tran){

    double tx = *x;
    double ty = *y;

    *x = tx * tran.getm00() + ty * tran.getm01() + tran.getdx();
    *y = tx * tran.getm10() + ty * tran.getm11() + tran.getdy();

};

// Task3 : Inverse transformations
void inv_transf(double* x, double* y, AffineTrans tran){
    double m00,m01,m10,m11,dx,dy;
    m00 = tran.getm00();
    m01 = tran.getm01();
    m10 = tran.getm10();
    m11 = tran.getm11();
    dx = tran.getdx();
    dy = tran.getdy();

    double denom = m00 * m11 - m01 * m10;

    if (denom != 0){
    // calculate the inverse values
        double im00,im01,im10,im11,idx,idy;
        im00 = m11 / denom;
        im01 = -m01 / denom;
        im10 = -m10 / denom;
        im11 = m00 / denom;
        idx = - dx * im00 - dy * im01;
        idy = - dx * im10 - dy * im11;

        double tx = *x;
        double ty = *y;

        *x = tx * im00 + ty * im01 + idx;
        *y = tx * im10 + ty * im11 + idy;
    }
    else {
        cout << "Cannot calculate the inverse" << endl;
    }

};

// Task4 : Combine transformations
AffineTrans comb_transf(AffineTrans atran, AffineTrans btran){
    double am00, am01, am10, am11, adx, ady;
    double bm00, bm01, bm10, bm11, bdx, bdy;
    double cM[2][2];
    double cd[2];

    am00 = atran.getm00();
    am01 = atran.getm01();
    am10 = atran.getm10();
    am11 = atran.getm11();
    adx = atran.getdx();
    ady = atran.getdy();

    bm00 = btran.getm00();
    bm01 = btran.getm01();
    bm10 = btran.getm10();
    bm11 = btran.getm11();
    bdx = btran.getdx();
    bdy = btran.getdy();

    cM[0][0] = am00 * bm00 + am01 * bm10;
    cM[0][1] = am00 * bm01 + am01 * bm11;
    cM[1][0] = am10 * bm00 + am11 * bm10;
    cM[1][1] = am10 * bm01 + am11 * bm11;
    cd[0] = adx + am00 * bdx + am01 * bdy;
    cd[1] = ady + am10 * bdx + am11 * bdy;

    AffineTrans ctran(cM, cd);

    return ctran;
};


// example
int main()
{
    double M[2][2] = {{2,-3},{1,1}};
    double d[2] = {1,-4};

    AffineTrans examp(M, d);

    AffineTrans examp1(M, d);
    examp1.setm00(0.2);
    examp1.setm10(-0.2);
    examp1.setm01(0.6);
    examp1.setm11(0.4);
    examp1.setdx(2.2);
    examp1.setdy(1.8);

    AffineTrans comb = comb_transf(examp, examp1);


    double x = 1;
    double y = 0;
    cout << "Initial values:" << endl;
    cout << x << " " << y << endl;

    transf(&x, &y, examp);
    cout << "Transformation:" << endl;
    cout << x << " " << y << endl;

    inv_transf(&x, &y, examp);
    cout << "Inverse Transformation:" << endl;
    cout << x << " " << y << endl;

    transf(&x, &y, comb);
    cout << "Combined Transformation:" << endl;
    cout << x << " " << y << endl;

    return 0;
}
