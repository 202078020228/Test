//����ǿ ����2003
//��������⣺OLS��ϡ�
//��Ϊ���ڣ���һ���Ƕ��庯�����ڶ����ǵ��ò������Ϸ���
#include <stdio.h>
#define DEFAULT_EPS 1e-15
#include <cmath>
//������С���˺�������ʼ��
float LeastSquareLinearFit(double* x, double* y, const int num, double* a, double* b)
{
    int i = 0;
    double denominator = 0.0;
    double sum_xsquared = 0.0;
    double sum_y = 0.0;
    double sum_x = 0.0;
    double sum_xy = 0.0;
    double errorSquare = 0;
    //����ѭ����
    for (i = 0; i < num; ++i)
    {
        sum_xsquared += x[i] * x[i];
        sum_y += y[i];
        sum_x += x[i];
        sum_xy += x[i] * y[i];//��ѭ���������ϵ���õ����м���
    }


    denominator = (num * sum_xsquared - sum_x * sum_x);//����ϵ��aʱ�ķ�ĸ
    if (fabs(denominator) <=( DEFAULT_EPS))//�ж���ĸ��Ϊ0
    {
        return 1;
    }
    *a = (num * sum_xy - sum_x * sum_y) / denominator;//����һ����ϵ��a
    *b = (sum_xsquared * sum_y - sum_x * sum_xy) / denominator;//���㳣����b
    for (int i = 0; i < num; i++)
    {
        errorSquare = errorSquare + (y[i] - (*a * x[i] + *b)) * (y[i] - (*a * x[i] + *b)); //��С���˷�������
    }
    return errorSquare;
}

    
int main()
{
   double aa=0, bb=0;//��ʼ��aa,bb

   //������������
    double x[30] = { 2,4,6,8,10,12,14,15,17,18,20,22,24,26,29};
    double y[30] = { 4,9,13,15,21,24,28,31,34,35,39,43,47,51,57};
    printf("%f\n", LeastSquareLinearFit(x, y, 30, &aa, &bb));
    //���ú�����������������Ϻ���
    printf("y=%fx+%f\n", aa, bb);//�����Ϸ���
    return 0;
}

