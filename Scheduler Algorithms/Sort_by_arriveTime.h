//
// Created by samy on ١‏/٤‏/٢٠٢٠.
//

#ifndef CPUSCHEDULER_SORT_BY_ARRIVETIME_H
#define CPUSCHEDULER_SORT_BY_ARRIVETIME_H

//we use merge sort as it has O(nlogn) time complexity & O(n) space completixty.
/*merge sort is suitable for our tasks than qucik sort & heap sort ,as it is stable sort (if we sort sorted elements with other croteria the sequence will not change "sorting doesn't change the sequence)*/

//Merge sort uses divide & conquer algorithm "break recursivly into halfs arrays , arrange & merge"

void merge(Process p[], int left, int mid, int right)
{
    int fIdx = left;

    int rIdx = mid + 1;

    int i;


    Process *sortArr = (Process *)malloc(sizeof(Process) * (right + 1));

    int sIdx = left;

    while (fIdx <= mid && rIdx <= right)
    {
        if (p[fIdx].arrivalTime <= p[rIdx].arrivalTime)
            sortArr[sIdx] = p[fIdx++];



        else
            sortArr[sIdx] = p[rIdx++];


        sIdx++;

    }


    if (fIdx > mid)
    {

        for (i = rIdx; i <= right; i++, sIdx++)
            sortArr[sIdx] = p[i];

    }


    else
    {

        for (i = fIdx; i <= mid; i++, sIdx++)
            sortArr[sIdx] = p[i];

    }


    for (i = left; i <= right; i++)
        p[i] = sortArr[i];


    free(sortArr);

};

void merge_sort_by_arrive_time(Process p[], int left, int right)
{
    int mid;



    if (left < right)
    {
        /* get mid element */
        mid = (left + right) / 2;

        /* tree sorting */
        merge_sort_by_arrive_time(p, left, mid);
        merge_sort_by_arrive_time(p, mid + 1, right);


        merge(p, left, mid, right);
    }
};
#endif //CPUSCHEDULER_SORT_BY_ARRIVETIME_H
