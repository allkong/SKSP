#pragma once

#ifndef _PROJECT1_H_
#define _PROJECT1_H_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 260
#define CLASS_LEN 240
#define INFO_LEN 16
#define SIZE 5

enum
{
    eName,
    eDay,
    eTime,
    eProfessor,
    eRoom,
};

struct stClass
{
    char szName[CLASS_LEN];
    char szDay[INFO_LEN];
    int nTime;
    char szProfes[INFO_LEN];
    char szRoom[INFO_LEN];
};

struct category
{
    char class[100];
    char site[100];
    char event[100];
    char major[100];
};

struct Counseling
{
    int number;
    char name[10];
    char consult_content[100];
    char feedback[100];
};

void class_list();
int menu();
void print(int n);
void dissat();
void hw();
void co();
void main();
#endif