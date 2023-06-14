class TPoint{ //клас "точка"
private:
    float x,y;
public:
    TPoint(float _x, float _y); //конструктор класу, що ініціалізує значення координат точки
    float getx();
    float gety();

};
class TLine{ //клас "пряма"
private:
    float a,b,c;
public:
    TLine(float _a, float _b, float _c); //конструктор класу, що ініціалізує значення коефіцієнтів прямої та відповідних методів
    void LineOutput(TLine array[], const int n);
    bool IsPointOnLine(TPoint m);
    void FindLine(TLine array[], const int n, TPoint m);
};
