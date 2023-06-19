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
    cout<<"������� ��������"<<endl;
    cin>>eps;
    cout<<"������� ��������� ����������� x0"<<endl;
    cin>>x[0];
    cout<<"������� ��������� ����������� y0"<<endl;
    cin>>x[1];
    err=1;
    n=0;
    while (err)
    {
        //�������
        F[0]=sin(x[1]-1)+x[0]-1.3;
        F[1]=x[1]-sin(x[0]+1)-0.8;
        //������� �����
        J[0][0]=1;J[0][1]=cos(x[1]-1);
        J[1][0]=-cos(x[0]+1);J[1][1]=1;
        //������������ ������� �����
        delta=(J[0][0]*J[1][1]-J[0][1]*J[1][0]);
        //�������� �������
        Jm[0][0]=J[1][1]/delta;
        Jm[1][1]=J[0][0]/delta;
        Jm[1][0]=-J[1][0]/delta;
        Jm[0][1]=-J[0][1]/delta;

        //�� ������� ������ �������
        x1[0]=x[0]-(Jm[0][0]*F[0]+Jm[0][1]*F[1]);
        x1[1]=x[1]-(Jm[1][0]*F[0]+Jm[1][1]*F[1]);
        //���� �� ��������� ����������� ��������
        err1=fabs(x1[0]-x[0])>eps;
        err2=fabs(x1[1]-x[1])>eps;
        err=err1||err2;
        //��������� �� ����� ����������� ����������� �����
        for (int i=0;i<2;i++)
        {
            x[i]=x1[i];
        }
        n++;//������� ����� ��������
        cout <<"�������� �"<<n<<": "<<"x = "<<x[0]<<"  y = "<<x[1]<<endl;
    }
    cout <<"�������� ������� � �������� ���������!"<<endl<<endl;
    cout <<"����� �������� ����� "<<n<<endl;
    cout <<"x = "<<x[0]<<"  y = "<<x[1]<<endl;
    return 0;
}
