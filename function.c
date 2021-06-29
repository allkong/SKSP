#pragma warning (disable: 4996)

#include "Project1.h"

void class_list()
{
    int nCount;

    printf("�� ���� ������ �Է��Ͻðڽ��ϱ�?\n");
    printf("���Ǹ�, ����, ����, ����, ���ǽ��� ���ʷ� �Է��ϼ���.\n");
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
        printf("=================== ���� %d ===================\n", i + 1);
        printf("���Ǹ� : %s\n", Data[i].szName);
        printf("���� : %s\n", Data[i].szDay);
        printf("���� : %d����\n", Data[i].nTime);
        printf("��米�� : %s\n", Data[i].szProfes);
        printf("���ǽ� : %s\n", Data[i].szRoom);
    }
    printf("===============================================\n\n");
    main();
}

int menu()
{
    int n;
    printf(" ** �˰� ���� ������ �����ϼ��� **\n");
    printf("1. ���� ��ð�\n");
    printf("2. �н� ��ð�\n");
    printf("3. �н� �޴�\n");
    printf("4. ���ư���\n");
    printf("\n�������ּ���: ");
    scanf_s("%d", &n);
    return n;
}

void print(int n)
{
    char time1[2][20] = { "11:00", "10:00" };
    char time2[2][20] = { "8�ð�", "8�ð�" };
    char* mn[] = { "������", "����Ƣ��쵿", "�����ݱ���", "�������", "��������ġ�", "����Ƣ��˹�", "�Թ�ī����", "����������" };
    
    while (1)
    {
        if (n == 1)
        {
            printf("**���� ��ð�**\n");
            printf("���� �ð�: %s\n", time1[0]);
            printf("� �ð�: %s\n", time2[0]);
            printf("================================================\n");
        }
        else if (n == 2)
        {
            printf("**�н� ��ð�**\n");
            printf("���� �ð�: %s\n", time1[1]);
            printf("� �ð�: %s\n", time2[1]);
            printf("================================================\n");
        }
        else if (n == 3)
        {
            printf("**�н� �޴�**\n");
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
        printf("�л��ΰ��� �����ΰ���? (�л�:s / ����: p /����: 'q'): ");
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
                printf("   1. ����   \n   2. ����   \n   3. ���   \n   4. ����   \n   5. ���ư���   \n");
                printf("-------------\n");
                printf("��ȣ�� �����Ͻÿ�: ");
                scanf("%d", &n);
                printf("\n");

                if (n == 1)
                {
                    getchar();
                    printf("������ ���� �Ҹ������� �Է��Ͻÿ�: ");
                    gets_s(list.class, 100);

                }
                else if (n == 2)
                {
                    getchar();
                    printf("������ ���� �Ҹ������� �Է��Ͻÿ�: ");
                    gets_s(list.site, 100);

                }
                else if (n == 3)
                {
                    getchar();
                    printf("��翡 ���� �Ҹ������� �Է��Ͻÿ�: ");
                    gets_s(list.event, 100);

                }
                else if (n == 4)
                {
                    getchar();
                    printf("������ ���� �Ҹ������� �Է��Ͻÿ�: ");
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
                printf("   1. ����   \n   2. ����   \n   3. ���   \n   4. ����   \n   5. ���ư���   \n");
                printf("-------------\n");
                printf("��ȣ�� �����Ͻÿ�: ");
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
        printf("������ ����Ͻðڽ��ϱ�? (��:y / �ƴϿ�:n): ");
        scanf(" %c", &a);

        if (a == 'n')
        {
            printf("================================================\n");
            main();
        }

        if (a == 'y')
        {
            printf("������� �Է��ϼ���: ");
            scanf("%s", subject);
            printf("���� ������� ��¥�� �Է��ϼ���: "); // 0000�� 00�� 00�� ���� �ؼ� ���ڸ� �Է�
            scanf("%d %d %d", &year1, &mon1, &day1);
            printf("���� ������� �ð��� �Է��ϼ���: "); // 00�� 00�� ���� �ؼ� ���ڸ� �Է�
            scanf("%d %d", &hour1, &min1);

            printf("---------------------------------------------\n");
            printf("����: %d/%02d/%02d %02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
            printf("�����: %s\n", subject);

            if (year1 == tm.tm_year + 1900)
            {
                if (mon1 < tm.tm_mon + 1)
                {
                    printf("������ �������ϴ�\n");
                }
                else if (mon1 == tm.tm_mon + 1)
                {
                    if (day1 < tm.tm_mday)
                        printf("������ �������ϴ�\n");
                    else if (day1 == tm.tm_mday)
                    {
                        if (hour1 < tm.tm_hour)
                            printf("���� �ð��� �������ϴ�\n");
                        else if (hour1 == tm.tm_hour)
                        {
                            if (min1 < tm.tm_min)
                                printf("���� �ð��� �������ϴ�\n");
                            else if (min1 == tm.tm_min)
                                printf("���� �ð��Դϴ�\n");
                            else
                            {
                                min2 = min1 - tm.tm_min;
                                printf("00:%02d ���ҽ��ϴ�\n", min2);
                            }
                        }
                        else // if (hour1 > tm.tm_hour)
                        {
                            if (min1 < tm.tm_min)
                            {
                                hour2 = hour1 - tm.tm_hour - 1;
                                min2 = 60 - tm.tm_min + min1;
                                printf("������ �������Դϴ�\n");
                                printf("%02d:%02d ���ҽ��ϴ�\n", hour2, min2);
                            }
                            else if (min1 == tm.tm_min)
                            {
                                hour2 = hour1 - tm.tm_hour;
                                printf("������ �������Դϴ�\n");
                                printf("%02d:00 ���ҽ��ϴ�\n", hour2);
                            }
                            else // if (min1 > tm.tm_min)
                            {
                                hour2 = hour1 - tm.tm_hour;
                                min2 = min1 - tm.tm_min;
                                printf("������ �������Դϴ�\n");
                                printf("%02d:%02d ���ҽ��ϴ�\n", hour2, min2);
                            }
                        }
                    }
                    else // if (day1 > tm.tm_mday)
                    {
                        day2 = day1 - tm.tm_mday;
                        printf("%d�� ���ҽ��ϴ�\n", day2);
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
                            printf("%d�� ���ҽ��ϴ�\n", day2);
                        else
                            printf("%d�� %d�� ���ҽ��ϴ�\n", mon2, day2);
                    }
                    else if (day1 == tm.tm_mday)
                    {
                        mon2 = mon1 - tm.tm_mon - 1;
                        printf("%d�� ���ҽ��ϴ�\n", mon2);
                    }
                    else // if (day1 > tm.tm_mday)
                    {
                        mon2 = mon1 - tm.tm_mon - 1;
                        day2 = day1 - tm.tm_mday;
                        printf("%d�� %d�� ���ҽ��ϴ�\n", mon2, day2);
                    }
                }
            }
            else if (year1 > tm.tm_year + 1900)
            {
                if (year1 - tm.tm_year - 1900 == 1) // �Է��� �⵵�� ������ �⵵�� 1�� ����
                {
                    if (mon1 < tm.tm_mon + 1)
                    {
                        if (day1 < tm.tm_mday)
                        {
                            i = tm.tm_mon + 1;
                            mon2 = 12 - tm.tm_mon - 1 + mon1 - 1;
                            day2 = days[i - 1] - tm.tm_mday + day1;
                            printf("%d�� %d�� ���ҽ��ϴ�\n", mon2, day2);
                        }
                        else if (day1 == tm.tm_mday)
                        {
                            mon2 = 12 - tm.tm_mon - 1 + mon1;
                            printf("%d�� ���ҽ��ϴ�\n", mon2);
                        }
                        else // if (day1 > tm.tm_mday)
                        {
                            mon2 = 12 - tm.tm_mon - 1 + mon1;
                            day2 = day1 - tm.tm_mday;
                            printf("%d�� %d�� ���ҽ��ϴ�\n", mon2, day2);
                        }
                    }
                    else if (mon1 == tm.tm_mon + 1)
                    {
                        if (day1 < tm.tm_mday)
                        {
                            i = tm.tm_mon + 1;
                            mon2 = 11; // 12 - tm.tm_mon + mon2 = 11
                            day2 = days[i - 1] - tm.tm_mday + day1;
                            printf("%d�� %d�� ���ҽ��ϴ�\n", mon2, day2);
                        }
                        else if (day1 == tm.tm_mday)
                        {
                            year2 = 1;
                            printf("%d�� ���ҽ��ϴ�\n", year2);
                        }
                        else // if (day1 > tm.tm_mday)
                        {
                            year2 = 1;
                            day2 = day1 - tm.tm_mday;
                            printf("%d�� %d�� ���ҽ��ϴ�\n", year2, day2);
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
                                printf("%d�� %d�� ���ҽ��ϴ�\n", year2, day2);
                            else
                                printf("%d�� %d�� %d�� ���ҽ��ϴ�\n", year2, mon2, day2);
                        }
                        else if (day1 == tm.tm_mday)
                        {
                            year2 = 1;
                            mon2 = mon1 - tm.tm_mon - 1;
                            printf("%d�� %d�� ���ҽ��ϴ�\n", year2, mon2);
                        }
                        else // if (day1 > tm.tm_mday)
                        {
                            year2 = 1;
                            mon2 = mon1 - tm.tm_mon - 1;
                            day2 = day1 - tm.tm_mday;
                            printf("%d�� %d�� %d�� ���ҽ��ϴ�\n", year2, mon2, day2);
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
                            printf("%d�� %d�� %d�� ���ҽ��ϴ�\n", year2, mon2, day2);
                        }
                        else if (day1 == tm.tm_mday)
                        {
                            year2 = year1 - tm.tm_year - 1900 - 1;
                            mon2 = 12 - tm.tm_mon - 1 + mon1;
                            printf("%d�� %d�� ���ҽ��ϴ�\n", year2, mon2);
                        }
                        else // if (day1 > tm.tm_mday)
                        {
                            year2 = year1 - tm.tm_year - 1900 - 1;
                            mon2 = 12 - tm.tm_mon - 1 + mon1;
                            day2 = day1 - tm.tm_mday;
                            printf("%d�� %d�� %d�� ���ҽ��ϴ�\n", year2, mon2, day2);
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
                            printf("%d�� %d�� %d�� ���ҽ��ϴ�\n", year2, mon2, day2);
                        }
                        else if (day1 == tm.tm_mday)
                        {
                            year2 = year1 - tm.tm_year - 1900;
                            printf("%d�� ���ҽ��ϴ�\n", year2);
                        }
                        else // if (day1 > tm.tm_mday)
                        {
                            year2 = year1 - tm.tm_year - 1900;
                            mon2 = mon1 - tm.tm_mon - 1;
                            day2 = day1 - tm.tm_mday;
                            if (mon2 == 0)
                                printf("%d�� %d�� ���ҽ��ϴ�\n", year2, day2);
                            else
                                printf("%d�� %d�� %d�� ���ҽ��ϴ�\n", year2, mon2, day2);
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
                                printf("%d�� %d�� ���ҽ��ϴ�\n", year2, day2);
                            else
                                printf("%d�� %d�� %d�� ���ҽ��ϴ�\n", year2, mon2, day2);
                        }
                        else if (day1 == tm.tm_mday)
                        {
                            year2 = year1 - tm.tm_year - 1900;
                            mon2 = mon1 - tm.tm_mon - 1;
                            printf("%d�� %d�� ���ҽ��ϴ�\n", year2, mon2);
                        }
                        else // if (day1 > tm.tm_mday)
                        {
                            year2 = year1 - tm.tm_year - 1900;
                            day2 = day1 - tm.tm_mday;
                            printf("%d�� %d�� ���ҽ��ϴ�\n", year2, day2);
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
        printf("�л��ΰ��� �����ΰ���? (�л�:s / ����: p / ����:q): ");
        scanf(" %c", &a);

        if (a == 'q')
            main();

        if (a == 's')
        {
            while (1)
            {
                printf("-------------------\n");
                printf("1. ��� ���� �ۼ�  \n");
                printf("2.  �ǵ�� Ȯ��    \n");
                printf("-------------------\n");
                printf("��ȣ�� �����Ͻÿ�: ");
                scanf("%d", &n);

                if (n == 1)
                {
                    printf("\n�й��� �Է��Ͻÿ�: ");
                    scanf("%d", &list.number);

                    printf("�̸��� �Է��Ͻÿ�: ");
                    scanf("%s", list.name);

                    getchar();
                    printf("��� ������ �Է��Ͻÿ�: ");
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
            printf("\n* %d %s �л��� ��� ��û�� �Ͽ����ϴ�. *\n", list.number, list.name);
            printf("\n------��� ��û ����--------\n\n");
            printf("%s", list.consult_content);
            printf("\n");
            getchar();
            printf("\n--------�ǵ�� �ۼ�---------\n\n");
            gets_s(list.feedback, 100);
            printf("\n");
        }
    }
}