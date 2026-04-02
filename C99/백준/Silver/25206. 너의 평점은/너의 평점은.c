#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 20

int main()
{
    char subject[50];
    double point;
    char score[3];

    double point_sum = 0;
    double score_sum = 0.0;

    for (int i = 0; i < MAX_N; i++)
    {
        scanf("%s %lf %s", subject, &point, score);

        if (strcmp(score, "P") == 0)
        {
            continue;
        }
        else if (strcmp(score, "A+") == 0)
        {
            point_sum += point;
            score_sum += 4.5 * point;
        }
        else if (strcmp(score, "A0") == 0)
        {
            point_sum += point;
            score_sum += 4.0 * point;
        }
        else if (strcmp(score, "B+") == 0)
        {
            point_sum += point;
            score_sum += 3.5 * point;
        }
        else if (strcmp(score, "B0") == 0)
        {
            point_sum += point;
            score_sum += 3.0 * point;
        }
        else if (strcmp(score, "C+") == 0)
        {
            point_sum += point;
            score_sum += 2.5 * point;
        }
        else if (strcmp(score, "C0") == 0)
        {
            point_sum += point;
            score_sum += 2.0 * point;
        }
        else if (strcmp(score, "D+") == 0)
        {
            point_sum += point;
            score_sum += 1.5 * point;
        }
        else if (strcmp(score, "D0") == 0)
        {
            point_sum += point;
            score_sum += 1.0 * point;
        }
        else if (strcmp(score, "F") == 0)
        {
            point_sum += point;
        }
    }

    printf("%lf\n", score_sum / point_sum);

    return 0;
}