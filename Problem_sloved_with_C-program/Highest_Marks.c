/*Problem Statement

There are N students in a class. Recently they got their Math course marks. One of them got the highest marks. So now they want to know how much more marks they need to get the highest mark. Can you calculate for every student what is the difference between their marks and the highest marks and print them!

Input Format

First line will contain N
Second line will contain the marks of N students
Constraints

1 <= N <= 100
0 <= Marks <= 100
Output Format

Output the difference between the marks of any student and highest marks
Sample Input 0

5
15 25 50 24 48
Sample Output 0

35 25 0 26 2
Sample Input 1

3
10 10 10
Sample Output 1

0 0 0*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int m_marks[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m_marks[i]);
    }

    int h_mark = m_marks[0];
    for (int i = 1; i < n; i++)
    {
        if (m_marks[i] > h_mark)
        {
            h_mark = m_marks[i];
        }
    }

    int need_marks[n];
    for (int i = 0; i < n; i++)
    {
        need_marks[i] = h_mark - m_marks[i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", need_marks[i]);
    }

    return 0;
}
