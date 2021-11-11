#include <stdio.h>

int compute_total_salary();         // 연 급여 계산
int compute_tax(int amount);         // 최종 세금 계산
// 세금 내역서 출력
void display_tax_returns(int total_salry, int tax_target, int tax);

int salary;  // 월 급여를 전역 변수로 선언

int main()
{
    int exemption = 10000000;                    // 세금 공제액
    int total_salary, tax_target, tax;            // 연 급여, 세금 부과 대상액, 최종 세금

    printf("월 급여는? "); scanf("%d", &salary);    // 월 급여 입력

    total_salary = compute_total_salary();        // 연 급여 계산
    tax_target = total_salary - exemption;        // 세금 부과 대상액 계산
    tax = compute_tax(tax_target);                    // 세금 부과 대상액으로부터 최종 세금 계산

    // 앞에서 구한 정보를 이용해 세금 내역서 출력하기
    display_tax_returns(total_salary, tax_target, tax);

    return 0;
}

// 월 급여와 연 보너스율을 이용해 연 급여를 계산하는 함수
int compute_total_salary()
{
    int bonus_rate = 300;     // 연 보너스는 월급의 300%임을 의미

    return (salary * 12) + (int)(salary * bonus_rate * 0.01);
}

// 최종 세금 부과 대상액 amount로부터 최종 세금을 계산하는 함수
int compute_tax(int amount)
{
    int tax_rate;         // 세금 과세율

    if (salary >= 5000000)
        tax_rate = 5;     // 과세율이 5%임을 의미
    else if (salary >= 2500000)
       tax_rate = 3;
    else
       tax_rate = 2;

       return (int)(amount * tax_rate * 0.01);
}

// 전달된 세금 관련 정보를 이용해 세금 내역서 출력하기
void display_tax_returns(int total_salary, int tax_target, int tax)
{
    printf("\n   >>> 세금 내역서 <<< \n");
    printf("--------------------------------\n");
    printf("연 급여        : %8d원 \n", total_salary);
    printf("세금 부과 대상액 : %8d원 \n", tax_target) ;
    printf("최종 세금 부과액 : %8d원 \n", tax);
}