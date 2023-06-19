#include <iostream>
#include <math.h>
#include <locale>

using namespace std;

double eps,J[2][2],Jm[2][2],x[2],x1[2],F[2],delta;
bool  err,err1,err2;
int n;

int main()
{
    setlocale(LC_ALL, "russian");
    cout<<"¬ведите точность"<<endl;
    cin>>eps;
    cout<<"¬ведите начальное приближение x0"<<endl;
    cin>>x[0];
    cout<<"¬ведите начальное приближение y0"<<endl;
    cin>>x[1];
    err=1;
    n=0;
    while (err)
    {
        //система
        F[0]=sin(x[1]-1)+x[0]-1.3;
        F[1]=x[1]-sin(x[0]+1)-0.8;
        //матрица якоби
        J[0][0]=1;J[0][1]=cos(x[1]-1);
        J[1][0]=-cos(x[0]+1);J[1][1]=1;
        //определитель матрицы якоби
        delta=(J[0][0]*J[1][1]-J[0][1]*J[1][0]);
        //ќбратна€ матрица
        Jm[0][0]=J[1][1]/delta;
        Jm[1][1]=J[0][0]/delta;
        Jm[1][0]=-J[1][0]/delta;
        Jm[0][1]=-J[0][1]/delta;

        //по формуле метода Ќьютона
        x1[0]=x[0]-(Jm[0][0]*F[0]+Jm[0][1]*F[1]);
        x1[1]=x[1]-(Jm[1][0]*F[0]+Jm[1][1]*F[1]);
        //пока не достигнем необходимой точности
        err1=fabs(x1[0]-x[0])>eps;
        err2=fabs(x1[1]-x[1])>eps;
        err=err1||err2;
        //принимаем за новое приближение вычисленное ранее
        for (int i=0;i<2;i++)
        {
            x[i]=x1[i];
        }
        n++;//счЄтчик числа итераций
        cout <<"»тераци€ є"<<n<<": "<<"x = "<<x[0]<<"  y = "<<x[1]<<endl;
    }
    cout <<"ѕолучено решение с заданной точностью!"<<endl<<endl;
    cout <<"„исло итераций равно "<<n<<endl;
    cout <<"x = "<<x[0]<<"  y = "<<x[1]<<endl;
    return 0;
}
