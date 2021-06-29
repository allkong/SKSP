#pragma warning (disable: 4996)

#include "Project1.h"

void class_list()
{
    int nCount;

    printf("몇 개의 정보를 입력하시겠습니까?\n");
    printf("강의명, 요일, 교시, 교수, 강의실을 차례로 입력하세요.\n");
    scanf("%d\n", &nCount);

    int i;

    struct stClass* Data = malloc(sizeof(struct stClass));

    for (i = 0; i < nCount; i++)
    {
        char szRead[MAX_PATH];
        fgets(szRead, MAX_PATH, stdin);      fflush(stdin);
        szRead[strlen(szRead) - 1] = '\0';

        char* ptr = strtok(szRead, ",");

        int index = 0;
        while (ptr != NULL)
        {
            if (index == eName)         strcpy(Data[i].szName, ptr);
            if (index == eDay)         strcpy(Data[i].szDay, ptr);
            if (index == eTime)         Data[i].nTime = atoi(ptr);
            if (index == eProfessor)   strcpy(Data[i].szProfes, ptr);
            if (index == eRoom)         strcpy(Data[i].szRoom, ptr);

            ptr = strtok(NULL, ",");
            index++;
        }
    }

    for (i = 0; i < nCount; i++)
    {
        printf("=================== 수업 %d ===================\n", i + 1);
        printf("강의명 : %s\n", Data[i].szName);
        printf("요일 : %s\n", Data[i].szDay);
        printf("교시 : %d교시\n", Data[i].nTime);
        printf("담당교수 : %s\n", Data[i].szProfes);
        printf("강의실 : %s\n", Data[i].szRoom);
    }
    printf("===============================================\n\n");
    main();
}

int menu()
{
    int n;
    printf(" ** 알고 싶은 정보를 선택하세요 **\n");
    printf("1. 학정 운영시간\n");
    printf("2. 학식 운영시간\n");
    printf("3. 학식 메뉴\n");
    printf("4. 돌아가기\n");
    printf("\n선택해주세요: ");
    scanf_s("%d", &n);
    return n;
}

void print(int n)
{
    char time1[2][20] = { "11:00", "10:00" };
    char time2[2][20] = { "8시간", "8시간" };
    char* mn[] = { "계란라면", "새우튀김우동", "돈까스쟁반국수", "돈까스정식", "돼지고기김치찌개", "새우튀김알밥", "함박카레동", "옛날떡볶이" };
    
    while (1)
    {
        if (n == 1)
        {
            printf("**학정 운영시간**\n");
            printf("여는 시간: %s\n", time1[0]);
            printf("운영 시간: %s\n", time2[0]);
            printf("================================================\n");
        }
        else if (n == 2)
        {
            printf("**학식 운영시간**\n");
            printf("여는 시간: %s\n", time1[1]);
            printf("운영 시간: %s\n", time2[1]);
            printf("================================================\n");
        }
        else if (n == 3)
        {
            printf("**학식 메뉴**\n");
            int i = 0;
            for (int i = 0; i < sizeof(mn) / sizeof(char*); i++)
                printf("%s\n", mn[i]);
            printf("================================================\n");
        }
        else if (n == 4)
            printf("================================================\n");
            main();
    }
}

void dissat()
{
    struct category list;
    char ans;
    int n;

    while (1)
    {
        printf("학생인가요 교수인가요? (학생:s / 교수: p /종료: 'q'): ");
        scanf(" %c", &ans);

        if (ans == 'q')
        {
            printf("================================================\n");
            main();
        }

        if (ans == 's')
        {
            while (1)
            {
                printf("-------------\n");
                printf("   1. 수업   \n   2. 서버   \n   3. 행사   \n   4. 전공   \n   5. 돌아가기   \n");
                printf("-------------\n");
                printf("번호를 선택하시오: ");
                scanf("%d", &n);
                printf("\n");

                if (n == 1)
                {
                    getchar();
                    printf("수업에 관한 불만사항을 입력하시오: ");
                    gets_s(list.class, 100);

                }
                else if (n == 2)
                {
                    getchar();
                    printf("서버에 관한 불만사항을 입력하시오: ");
                    gets_s(list.site, 100);

                }
                else if (n == 3)
                {
                    getchar();
                    printf("행사에 관한 불만사항을 입력하시오: ");
                    gets_s(list.event, 100);

                }
                else if (n == 4)
                {
                    getchar();
                    printf("전공에 관한 불만사항을 입력하시오: ");
                    gets_s(list.major, 100);

                }
                else if (n == 5)
                {
                    break;
                }
            }
        }

        if (ans == 'p')
        {
            while (1)
            {
                printf("-------------\n");
                printf("   1. 수업   \n   2. 서버   \n   3. 행사   \n   4. 전공   \n   5. 돌아가기   \n");
                printf("-------------\n");
                printf("번호를 선택하시오: ");
                scanf("%d", &n);

                if (n == 1)
                {
                    printf("%s", list.class);
                    printf("\n");
                }
                else if (n == 2)
                {
                    printf("%s", list.site);
                    printf("\n");
                }
                else if (n == 3)
                {
                    printf("%s", list.event);
                    printf("\n");
                }
                else if (n == 4)
                {
                    printf("%s", list.major);
                    printf("\n");
                }
                else if (n == 5)
                {
                    break;
                }
            }
        }
    }
    printf("===============================================\n\n");
}

void hw()
{
    int year1, mon1, day1, year2, mon2, day2;
    int hour1, min1, hour2, min2;
    int i;
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char a;
    char subject[100];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    while (1)
    {
        printf("과제를 등록하시겠습니까? (예:y / 아니요:n): ");
        scanf(" %c", &a);

        if (a == 'n')
        {
            printf("================================================\n");
            main();
        }

        if (a == 'y')
        {
            printf("과목명을 입력하세요: ");
            scanf("%s", subject);
            printf("과제 제출기한 날짜를 입력하세요: "); // 0000년 00월 00일 띄어쓰기 해서 숫자만 입력
            scanf("%d %d %d", &year1, &mon1, &day1);
            printf("과제 제출기한 시간을 입력하세요: "); // 00시 00분 띄어쓰기 해서 숫자만 입력
            scanf("%d %d", &hour1, &min1);

            printf("---------------------------------------------\n");
            printf("오늘: %d/%02d/%02d %02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
            printf("과목명: %s\n", subject);

            if (year1 == tm.tm_year + 1900)
            {
                if (mon1 < tm.tm_mon + 1)
                {
                    printf("기한이 지났습니다\n");
                }
                else if (mon1 == tm.tm_mon + 1)
                {
                    if (day1 < tm.tm_mday)
                        printf("기한이 지났습니다\n");
                    else if (day1 == tm.tm_mday)
                    {
                        if (hour1 < tm.tm_hour)
                            printf("제출 시간이 지났습니다\n");
                        else if (hour1 == tm.tm_hour)
                        {
                            if (min1 < tm.tm_min)
                                printf("제출 시간이 지났습니다\n");
                            else if (min1 == tm.tm_min)
                                printf("제출 시간입니다\n");
                            else
                            {
                                min2 = min1 - tm.tm_min;
                                printf("00:%02d 남았습니다\n", min2);
                            }
                        }
                        else // if (hour1 > tm.tm_hour)
                        {
                            if (min1 < tm.tm_min)
                            {
                                hour2 = hour1 - tm.tm_hour - 1;
                                min2 = 60 - tm.tm_min + min1;
                                printf("오늘이 제출일입니다\n");
                                printf("%02d:%02d 남았습니다\n", hour2, min2);
                            }
                            else if (min1 == tm.tm_min)
                            {
                                hour2 = hour1 - tm.tm_hour;
                                printf("오늘이 제출일입니다\n");
                                printf("%02d:00 남았습니다\n", hour2);
                            }
                            else // if (min1 > tm.tm_min)
                            {
                                hour2 = hour1 - tm.tm_hour;
                                min2 = min1 - tm.tm_min;
                                printf("오늘이 제출일입니다\n");
                                printf("%02d:%02d 남았습니다\n", hour2, min2);
                            }
                        }
                    }
                    else // if (day1 > tm.tm_mday)
                    {
                        day2 = day1 - tm.tm_mday;
                        printf("%d일 남았습니다\n", day2);
                    }
                }
                else // if (mon1 > tm.tm_mon + 1)
                {
                    if (day1 < tm.tm_mday)
                    {
                        i = tm.tm_mon + 1;
                        mon2 = mon1 - tm.tm_mon - 1 - 1;
                        day2 = days[i - 1] - tm.tm_mday + day1;
                        if (mon2 == 0)
                            printf("%d일 남았습니다\n", day2);
                        else
                            printf("%d달 %d일 남았습니다\n", mon2, day2);
                    }
                    else if (day1 == tm.tm_mday)
                    {
                        mon2 = mon1 - tm.tm_mon - 1;
                        printf("%d달 남았습니다\n", mon2);
                    }
                    else // if (day1 > tm.tm_mday)
                    {
                        mon2 = mon1 - tm.tm_mon - 1;
                        day2 = day1 - tm.tm_mday;
                        printf("%d달 %d일 남았습니다\n", mon2, day2);
                    }
                }
            }
            else if (year1 > tm.tm_year + 1900)
            {
                if (year1 - tm.tm_year - 1900 == 1) // 입력한 년도와 현재의 년도가 1년 차이
                {
                    if (mon1 < tm.tm_mon + 1)
                    {
                        if (day1 < tm.tm_mday)
                        {
                            i = tm.tm_mon + 1;
                            mon2 = 12 - tm.tm_mon - 1 + mon1 - 1;
                            day2 = days[i - 1] - tm.tm_mday + day1;
                            printf("%d달 %d일 남았습니다\n", mon2, day2);
                        }
                        else if (day1 == tm.tm_mday)
                        {
                            mon2 = 12 - tm.tm_mon - 1 + mon1;
                            printf("%d달 남았습니다\n", mon2);
                        }
                        else // if (day1 > tm.tm_mday)
                        {
                            mon2 = 12 - tm.tm_mon - 1 + mon1;
                            day2 = day1 - tm.tm_mday;
                            printf("%d달 %d일 남았습니다\n", mon2, day2);
                        }
                    }
                    else if (mon1 == tm.tm_mon + 1)
                    {
                        if (day1 < tm.tm_mday)
                        {
                            i = tm.tm_mon + 1;
                            mon2 = 11; // 12 - tm.tm_mon + mon2 = 11
                            day2 = days[i - 1] - tm.tm_mday + day1;
                            printf("%d달 %d일 남았습니다\n", mon2, day2);
                        }
                        else if (day1 == tm.tm_mday)
                        {
                            year2 = 1;
                            printf("%d년 남았습니다\n", year2);
                        }
                        else // if (day1 > tm.tm_mday)
                        {
                            year2 = 1;
                            day2 = day1 - tm.tm_mday;
                            printf("%d년 %d일 남았습니다\n", year2, day2);
                        }
                    }
                    else // if (mon1 > tm.tm_mday)
                    {
                        if (day1 < tm.tm_mday)
                        {
                            i = tm.tm_mon + 1;
                            year2 = 1;
                            mon2 = mon1 - tm.tm_mon - 1 - 1;
                            day2 = days[i - 1] - tm.tm_mday + day1;
                            if (mon2 == 0)
                                printf("%d년 %d일 남았습니다\n", year2, day2);
                            else
                                printf("%d년 %d달 %d일 남았습니다\n", year2, mon2, day2);
                        }
                        else if (day1 == tm.tm_mday)
                        {
                            year2 = 1;
                            mon2 = mon1 - tm.tm_mon - 1;
                            printf("%d년 %d달 남았습니다\n", year2, mon2);
                        }
                        else // if (day1 > tm.tm_mday)
                        {
                            year2 = 1;
                            mon2 = mon1 - tm.tm_mon - 1;
                            day2 = day1 - tm.tm_mday;
                            printf("%d년 %d달 %d일 남았습니다\n", year2, mon2, day2);
                        }
                    }
                }
                else // if (year1 - tm.tm_year - 1900 != 1)
                {
                    if (mon1 < tm.tm_mon + 1)
                    {
                        if (day1 < tm.tm_mday)
                        {
                            i = tm.tm_mon + 1;
                            year2 = year1 - tm.tm_year - 1900 - 1;
                            mon2 = 12 - tm.tm_mon - 1 + mon1 - 1;
                            day2 = days[i - 1] - tm.tm_mday + day1;
                            printf("%d년 %d달 %d일 남았습니다\n", year2, mon2, day2);
                        }
                        else if (day1 == tm.tm_mday)
                        {
                            year2 = year1 - tm.tm_year - 1900 - 1;
                            mon2 = 12 - tm.tm_mon - 1 + mon1;
                            printf("%d년 %d달 남았습니다\n", year2, mon2);
                        }
                        else // if (day1 > tm.tm_mday)
                        {
                            year2 = year1 - tm.tm_year - 1900 - 1;
                            mon2 = 12 - tm.tm_mon - 1 + mon1;
                            day2 = day1 - tm.tm_mday;
                            printf("%d년 %d달 %d일 남았습니다\n", year2, mon2, day2);
                        }
                    }
                    else if (mon1 == tm.tm_mon + 1)
                    {
                        if (day1 < tm.tm_mday)
                        {
                            i = tm.tm_mon + 1;
                            year2 = year1 - tm.tm_year - 1900 - 1;
                            mon2 = 11; // 12 - tm.tm_mon + mon2 = 11
                            day2 = days[i - 1] - tm.tm_mday + day1;
                            printf("%d년 %d달 %d일 남았습니다\n", year2, mon2, day2);
                        }
                        else if (day1 == tm.tm_mday)
                        {
                            year2 = year1 - tm.tm_year - 1900;
                            printf("%d년 남았습니다\n", year2);
                        }
                        else // if (day1 > tm.tm_mday)
                        {
                            year2 = year1 - tm.tm_year - 1900;
                            mon2 = mon1 - tm.tm_mon - 1;
                            day2 = day1 - tm.tm_mday;
                            if (mon2 == 0)
                                printf("%d년 %d일 남았습니다\n", year2, day2);
                            else
                                printf("%d년 %d달 %d일 남았습니다\n", year2, mon2, day2);
                        }
                    }
                    else // if (mon1 > tm.tm_mon + 1)
                    {
                        if (day1 < tm.tm_mday)
                        {
                            i = tm.tm_mon + 1;
                            year2 = year1 - tm.tm_year - 1900 - 1;
                            mon2 = mon1 - tm.tm_mon - 1 - 1;
                            day2 = days[i - 1] - tm.tm_mday + day1;
                            if (mon2 == 0)
                                printf("%d년 %d일 남았습니다\n", year2, day2);
                            else
                                printf("%d년 %d달 %d일 남았습니다\n", year2, mon2, day2);
                        }
                        else if (day1 == tm.tm_mday)
                        {
                            year2 = year1 - tm.tm_year - 1900;
                            mon2 = mon1 - tm.tm_mon - 1;
                            printf("%d년 %d달 남았습니다\n", year2, mon2);
                        }
                        else // if (day1 > tm.tm_mday)
                        {
                            year2 = year1 - tm.tm_year - 1900;
                            day2 = day1 - tm.tm_mday;
                            printf("%d년 %d일 남았습니다\n", year2, day2);
                        }
                    }
                }
            }
        }
        printf("---------------------------------------------\n");
    }
}

void co()
{
    struct Counseling list = { 0 };

    char a;
    int n;

    while (1)
    {
        printf("학생인가요 교수인가요? (학생:s / 교수: p / 종료:q): ");
        scanf(" %c", &a);

        if (a == 'q')
            main();

        if (a == 's')
        {
            while (1)
            {
                printf("-------------------\n");
                printf("1. 상담 내용 작성  \n");
                printf("2.  피드백 확인    \n");
                printf("-------------------\n");
                printf("번호를 선택하시오: ");
                scanf("%d", &n);

                if (n == 1)
                {
                    printf("\n학번을 입력하시오: ");
                    scanf("%d", &list.number);

                    printf("이름을 입력하시오: ");
                    scanf("%s", list.name);

                    getchar();
                    printf("상담 내용을 입력하시오: ");
                    gets_s(list.consult_content, 100);
                    printf("\n");
                    break;
                }
                if (n == 2)
                {
                    printf("\n");
                    printf("%s", list.feedback);
                    printf("\n\n");
                    break;
                }
            }
        }
        if (a == 'p')
        {
            printf("\n* %d %s 학생이 상담 요청을 하였습니다. *\n", list.number, list.name);
            printf("\n------상담 요청 내용--------\n\n");
            printf("%s", list.consult_content);
            printf("\n");
            getchar();
            printf("\n--------피드백 작성---------\n\n");
            gets_s(list.feedback, 100);
            printf("\n");
        }
    }
}