void main()
{
    int num = 0;
    printf("어떤 도움이 필요하나요?\n");
    printf("1.수업정보 2.학식,학정 3.불만사항 4.과제정보 5.상담요청 6.그만두기\n");
    scanf("%d", &num);

    while (1)
    {
        if (num == 1)
        {
            printf("================== 수업 정보 ===================\n");
            class_list();
        }
        else if (num == 2)
        {
            printf("================== 학식, 학정 ==================\n");
            int m = menu();
            print(m);
        }
        else if (num == 3)
        {
            printf("=================== 불만사항 ===================\n");
            dissat();
        }
        else if (num == 4)
        {
            printf("================== 과제 정보 ===================\n");
            hw();
        }
        else if (num == 5)
        {
            printf("================== 상담 요청 ===================\n");
            co();
        }
        else if (num == 6)
            exit(0);
    }
}