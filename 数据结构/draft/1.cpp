#include <iostream>
using namespace std;

const int M = 10000;
int n; //������
int s[M][M];//��¼���Ų��Զ�ά����
double m[M][M];//��¼����ֵ��ά����
double g[M][M];//��¼������֮��Ȩֵ�Ķ�ά����

void MinWeightTriangulation()
{
    for (int i = 1; i <= n; i++) //��ʼ��
    {
        m[i][i] = 0;
        s[i][i] = 0;
    }
    for (int r = 2; r <= n; r++)//rΪ�����ģ��r=2ʵ������������ rΪ��ǰ������������������ģ��  
    {
        for (int i = 1; i <= n - r + 1; i++)//n-r+1Ϊ���һ��r����ǰ�߽�  
        {
            int j = i + r - 1; //����ǰ�߽�Ϊr������Ϊr�����ĺ�߽�  
            m[i][j] = m[i + 1][j] + g[i - 1][i] + g[i][j] + g[i - 1][j];//k=i
            s[i][j] = i;
            for (int k = i + 1; k < j; k++) //ö��k=i+1��j�������
            {
                double u = m[i][k] + m[k + 1][j] + g[i - 1][k] + g[k][j] + g[i - 1][j];
                if (m[i][j] > u)
                {
                    m[i][j] = u;
                    s[i][j] = k;
                }
            }
        }
    }
}

void Traceback(int i, int j)  //�ݹ����������������ҡ�
{
    if (i == j)
        return;
    Traceback(i, s[i][j]);
    Traceback(s[i][j] + 1, j);
    cout << "�����ʷֶ��㣺V" << i - 1 << ",V" << j << ",V" << s[i][j] << endl;
}

int main()
{
    int i;
    int j;
    cout << "�����붥�����n��" << endl;
    cin >> n;
    n--;
    cout << "��������������������Ȩֵ��" << endl;
    for (i = 0; i <= n; ++i)
    {
        for (j = 0; j <= n; ++j)
        {
            cin >> g[i][j];
        }
    }
    MinWeightTriangulation();
    cout << "���������ʷֵ�Ȩֵ����:" << endl;
    cout << m[1][n] << endl;
    cout << "�����ʷֶ��㣺" << endl;
    Traceback(1, n);
    return 0;
}