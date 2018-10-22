#ifndef SORTS_H
#define SORTS_H

void swapByPtr(double*, double*);

int partitionPos(double*, int, int);
int partitionNeg(double*, int, int);

void quickSort(double*, int, int, int (*comp)(double*, int, int));

#endif // SORTS_H

