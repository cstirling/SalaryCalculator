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

    puts("##########本程序适用于上海地区的个税和五险一金计算##########");

    printf("\n请输入每个月税前薪资，单位为千元（例如2表示2千）： ");
    scanf("%lf",&inputShuiQian);
    inputShuiQian *= 1000;
    if(inputShuiQian < gongJiJinLowerBound)
    {
        printf("\n请检查输入，上海最低工资为%.2f元\n", gongJiJinLowerBound);
        return 0;
    }

    printf("\n请输入每个月房补，单位为千元（例如2表示2千）： ");
    scanf("%lf",&inputFangBu);
    inputFangBu *= 1000;

    printf("\n请输入一年额外收入（签字费等），单位为千元（例如2表示2千）： ");
    scanf("%lf",&inputEWai);
    inputEWai *= 1000;

    printf("\n请输入公积金比率，单位为百分号（例如12表示12%）： ");
    scanf("%lf",&gongJiJinRate);
    gongJiJinRate /= 100;

    printf("\n请输入实际月份数量（包含年终），单位为月（例如16表示16个月工资）： ");
    scanf("%lf",&inputYueShu);

    printf("\n请输入每年专项抵税额度，单位为千元（例如租房专项18表示18千）： ");
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

    puts("\n##########整年的开销细节##########\n");

    printf("交税：                    %.2f\n", tax);
    printf("交五险一金（细节如下）：  %.2f\n", outShebao + outGongJiJin);
    printf("--交养老保险：            %.2f\n", outShebao * yangLaoRate / sheBaoRate);
    printf("--交医疗保险：            %.2f\n", outShebao * yiBaoRate / sheBaoRate);
    printf("--交失业保险：            %.2f\n", outShebao * shiYeRate / sheBaoRate);
    printf("--交公积金：              %.2f\n\n", outGongJiJin);
    printf("综合税和五险一金，总开销：%.2f\n\n", tax + outShebao + outGongJiJin);

    puts("\n##########整年的到手薪资细节##########\n");
    printf("到手工资收入：            %.2f\n", rest);
    printf("可用公积金：              %.2f\n\n", outGongJiJin * 2);
    printf("综合工资和公积金，总收入：%.2f\n\n", rest + outGongJiJin * 2);

    system("pause");
}
