/*���ٻ� 
����2003��
202004061301 
2023.03.06
ͨ����ʽֱ����ع鷽�̣��ڸô���������ͨ���ݶ��½�������ʧ��������Сֵ����һ�˴��룬������������̫����δ�ҵ�ԭ��
����matlab��ͬ���ķ���д��һ�飬��ֵ�����matlab��ͬ�����㷨д�ľ��ܺܺõ���ϣ�ͬʱ�ύ��matlab���ļ�����ʦ�ܹ�ָ��������� 


*/ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5/* �������ݵ��� */
double X[N] = {1, 2, 3, 4, 5};/* ����X��Y���飬�洢���ݵ� */
double Y[N] = {1.2, 2.5, 3.6, 4.8, 6.1};
int main()
{
    double sum_x = 0, sum_y = 0; /* X��Y�ĺ� */
    double sum_xy = 0, sum_x2 = 0; /* XY��X^2�ĺ� */
    double a, b; /* ���ֱ�ߵ�ϵ�� */
    for (int i = 0; i < N; i++)/* ����X��Y��XY��X^2�ĺ� */
    {
        sum_x += X[i];
        sum_y += Y[i];
        sum_xy += X[i] * Y[i];
        sum_x2 += X[i] * X[i];
    }
    b = (N * sum_xy - sum_x * sum_y) / (N * sum_x2 - pow(sum_x, 2));/* �������ֱ�ߵ�ϵ�� */
    a = (sum_y - b * sum_x) / N;
	printf("���ֱ�߷���Ϊ: y = %.2fx + %.2f", b, a);
    return 0;
}
/*
#include <iostream>
#include <stdio.h>
#include<math.h>
#define v 0.000001   //������ɽ���� 
int main()
{
    using namespace std;
    int i,j,k,m;
    int col;
    int number;
    double sum_x = 0;
    double sum_y = 0;
    double  x[100];         //��������
    double  y[100];
    double theta1;       //һ�����ϵ��
    double theta0;       //��ϵ�� 
    double e;            //���ϵ��
    double old_theta1;
    double old_theta0;
    printf("please input sample's number :"); //���������ĸ���
    cin>>number;
    printf("sample's number is %d\n\n",number);
    printf("please input sample'x :");       //����������x
    for(k=0;k<number;k++)
    {
        cin>>x[k];
    }
    printf("\n");
    printf("please input sample'y :");      //���������y
    for(m=0;m<number;m++)
    {
        cin>>y[m];
    }
    printf("\n");
    col = number;
    printf("\n\n");
    printf("the training sample is : %d \n",col);
    for(i=0;i<col-1;i++)
    {
        sum_x = sum_x + x[i];
        sum_y = sum_y + y[i];
    }
    theta1 = (double)sum_y/sum_x;//������ɽ�ĳ�ʼ��
    theta0 = y[3]-theta1*x[3];
    while(1)                     //�ݶ��½���ֱ���ҵ����Ž��˳�ѭ��
    {
       double temp1 = 0;
       double temp0 = 0;
       for(j=0;j<col-1;j++)//������ʧ�����ֱ�Գ�ϵ����һ����ϵ���ĵ���
       {
          temp1 = temp1 + ((theta0 + theta1*x[j])-y[j])*x[j];
          temp0 = temp0 + ((theta0 + theta1*x[j])-y[j])*1;
       }
	   temp1 = temp1 / col;
       temp0 = temp0 / col;
       old_theta1 = theta1;//��ǰһ����ϵ����һ����ϵ���洢�Ժ����Ƚ�
       old_theta0 = theta0;

       theta1 = theta1 - v*temp1;//����ÿ�������ĳ�ϵ����һ����ϵ��
       theta0 = theta0 - v*temp0;
       temp1 = 0;
       temp0 = 0;
       e = (pow((old_theta1-theta1),2) + pow((old_theta0 - theta0),2));
        if(e<0.000003);//�����½��ٶȵ�һ����ֵ
        {
            printf("the objective function is : \n");
            printf("f(x)= %f + %f*x",theta0,theta1);
            break;//����ѭ��
        }
    }
}
*/
