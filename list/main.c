#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linux_list.h"

#define NUM 10

struct classs
{
    char name[10];
    int numOfStu;
    struct list_head students;
};

struct stu
{
    int age;
    int gender;
    int score;
    struct list_head stu_node;
};

int main(int argc, char* argv[])
{
    int i;
    struct list_head *pos, *n;
    struct stu curStu;
    struct stu *posStu;
    struct classs myClass = {0};
    INIT_LIST_HEAD(&myClass.students);

    printf("list      = %u\n", &myClass.students);
    printf("list.prev = %u\n", myClass.students.prev);
    printf("list.next = %u\n", myClass.students.next);
    printf("********************************\n");

    memcpy(myClass.name, "class one", 9);
    for (i = 0; i < NUM; i++)
    {
        posStu = (struct stu *)malloc(sizeof(struct stu));
        memset(posStu, 0, sizeof(struct stu));
        posStu->age = i;
        posStu->gender = i%2;
        posStu->score = 100;
        list_add(&posStu->stu_node, &myClass.students);
        myClass.numOfStu++;
    }

    printf("class\n name  : %s\n number: %d\n", myClass.name, myClass.numOfStu);
    printf("********************************\n");
    list_for_each_entry(posStu, &myClass.students, stu_node)
    {
        printf("age = %2d  gender = %d score = %d\n",
                posStu->age,
                posStu->gender,
                posStu->score);
    }
    printf("********************************\n");

    list_for_each_entry_reverse(posStu, &myClass.students, stu_node)
    {
        printf("age = %2d  gender = %d score = %d\n",
                posStu->age,
                posStu->gender,
                posStu->score);
    }

    list_for_each_safe(pos, n, &myClass.students)
    {
        posStu = list_entry(pos, struct stu, stu_node);
        free(posStu);
        list_del(pos);
    }

    return 0;
}

