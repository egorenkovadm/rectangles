#include <iostream>
#include <string>

struct Point {
    int x, y;
    Point(int x, int y): x(x), y(y) { }
    Point minx(Point const &rha) const {
        return Point(rha.x < x ? rha.x : x, y);
    }
    Point miny(Point const &rha) const {
        return Point(x, rha.y < y ? rha.y : y);
    }
    Point maxx( Point const &rha ) const {
        return Point(rha.x > x ? rha.x : x, y);
    }
    Point maxy( Point const &rha ) const {
        return Point(x, rha.y > y ? rha.y : y);
    }
    void print () const {
        std::cout << '(' << x << ',' << y << ')';
    } };


class Rectangle{
public:
    Point Angle;
    Rectangle(Point const & Angle): Angle(Angle){ }
    Rectangle(): Rectangle(Point(0, 0)) { };

    Rectangle operator + (Rectangle const &rha) const {
        Point newPoint = Angle.maxx(rha.Angle);
        return newPoint.maxy(rha.Angle);
    }

    Rectangle operator * (Rectangle const &rha) const {
        Point newPoint = Angle.minx(rha.Angle);
        return newPoint.miny(rha.Angle);
    }



    void print() const {
        Angle.print();
    }
};

Rectangle count (Rectangle r1, Rectangle r2, char op){
    Rectangle r3;
    if (op == '+') {
        r3 = r1 + r2;}
    if (op == '*'){
         r3 = r1 * r2;
    }
    return r3;
}

Rectangle read(int & num, std::string expression){
    int x, y;
    x = 0;
    y = 0;
    num++;
    while (expression[num] != ','){
        x = x * 10 + expression[num] - '0';
        num++;
    }
    num++;
    while (expression[num] != ')'){
        y = y * 10 + expression[num] - '0';
        num++;
    }
    //x = expression[num+1] - '0';
    //y = expression[num+3] - '0';
    Rectangle r1 = Rectangle(Point(x,y));
    num = num + 2;
    //r1.print();
    //std::cout<<expression[num];
    return r1;
}

int main() {
    std :: string expression;
    std::getline(std::cin, expression);
    int length = expression.size();
    int num = 0;
    Rectangle r1, r2, r3;
    char op1, op2, op3;
    r1 = read(num, expression);
    op2 = expression[num];
    num = num + 2;
    while (num < length){
        op1 = op2;
        //std::cout<<op1;
        r2 = read(num, expression);
        if (num <= length){
            op2 = expression[num];
            num = num + 2;
            //std::cout<<op2;
            while (op2 == '*'){
                r3 = read(num, expression);
                op3 = op2;
                op2 = expression[num];
                num = num + 2;
                //std::cout<<op2;
                /*r2.print();
                r3.print();
                std::cout<<op1;*/
                r2 = count(r2, r3, op3);
                /*r2.print();
                std::cout<<'\n';*/
            }
        }
        r1 = count(r1, r2, op1);
    }
    r1.print();

    return 0;
}