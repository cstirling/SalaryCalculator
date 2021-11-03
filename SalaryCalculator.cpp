#include<bits/stdc++.h>
using namespace std;

double yangLaoRate = 0.08;
double yiBaoRate = 0.02;
double shiYeRate = 0.005;
double gongJiJinRate = 12;
double sheBaoRate = yangLaoRate + yiBaoRate + shiYeRate;

double shebaoUpperBound = 31014;
double shebaoLowerBound = 5975;
double gongJiJinUpperBound = 31014;
double gongJiJinLowerBound = 2480;

int main()
{
    double inputShuiQian;
    double inputYueShu = 12;
    double inputFangBu = 1;
    double inputEWai = 1;
    double inputZhuanXiang = 18;

    puts("##########�������������Ϻ������ĸ�˰������һ�����##########");

    printf("\n������ÿ����˰ǰн�ʣ���λΪǧԪ������2��ʾ2ǧ���� ");
    scanf("%lf",&inputShuiQian);
    inputShuiQian *= 1000;
    if(inputShuiQian < gongJiJinLowerBound)
    {
        printf("\n�������룬�Ϻ���͹���Ϊ%.2fԪ\n", gongJiJinLowerBound);
        return 0;
    }

    printf("\n������ÿ���·�������λΪǧԪ������2��ʾ2ǧ���� ");
    scanf("%lf",&inputFangBu);
    inputFangBu *= 1000;

    printf("\n������һ��������루ǩ�ַѵȣ�����λΪǧԪ������2��ʾ2ǧ���� ");
    scanf("%lf",&inputEWai);
    inputEWai *= 1000;

    printf("\n�����빫������ʣ���λΪ�ٷֺţ�����12��ʾ12%���� ");
    scanf("%lf",&gongJiJinRate);
    gongJiJinRate /= 100;

    printf("\n������ʵ���·��������������գ�����λΪ�£�����16��ʾ16���¹��ʣ��� ");
    scanf("%lf",&inputYueShu);

    printf("\n������ÿ��ר���˰��ȣ���λΪǧԪ�������ⷿר��18��ʾ18ǧ���� ");
    scanf("%lf",&inputZhuanXiang);
    inputZhuanXiang *= 1000;

    double rest = inputShuiQian * inputYueShu;
    double sheBaoBenchmark = max(shebaoLowerBound, min(inputShuiQian, shebaoUpperBound));
    double gongJiJinBenchmark = max(gongJiJinLowerBound, min(inputShuiQian, gongJiJinUpperBound));
    double outShebao = sheBaoBenchmark * sheBaoRate * 12;
    double outGongJiJin = gongJiJinBenchmark * gongJiJinRate * 12;

    rest += inputFangBu * 12 + inputEWai;
    rest -= outShebao + outGongJiJin;

    double tax = 0;
    if(rest > 60000)
    {
        double taxJianmian = 60000 + inputZhuanXiang;
        rest -= taxJianmian;
        if(rest <= 36000) tax = rest * 0.03;
        else if(rest <= 144000) tax = rest * 0.1 - 2520;
        else if(rest <= 300000) tax = rest * 0.2 - 16920;
        else if(rest <= 420000) tax = rest * 0.25 - 31920;
        else if(rest <= 660000) tax = rest * 0.3 - 52920;
        else if(rest <= 96000) tax = rest * 0.35 - 85920;
        else tax = rest * 0.45 - 181920;
        rest -= tax - taxJianmian;
    }

    puts("\n##########����Ŀ���ϸ��##########\n");

    printf("��˰��                    %.2f\n", tax);
    printf("������һ��ϸ�����£���  %.2f\n", outShebao + outGongJiJin);
    printf("--�����ϱ��գ�            %.2f\n", outShebao * yangLaoRate / sheBaoRate);
    printf("--��ҽ�Ʊ��գ�            %.2f\n", outShebao * yiBaoRate / sheBaoRate);
    printf("--��ʧҵ���գ�            %.2f\n", outShebao * shiYeRate / sheBaoRate);
    printf("--��������              %.2f\n\n", outGongJiJin);
    printf("�ۺ�˰������һ���ܿ�����%.2f\n\n", tax + outShebao + outGongJiJin);

    puts("\n##########����ĵ���н��ϸ��##########\n");
    printf("���ֹ������룺            %.2f\n", rest);
    printf("���ù�����              %.2f\n\n", outGongJiJin * 2);
    printf("�ۺϹ��ʺ͹����������룺%.2f\n\n", rest + outGongJiJin * 2);

    system("pause");
}
