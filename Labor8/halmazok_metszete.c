int isin(int set[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (set[i] == val)
        {
            return 1;
        }
    }
    return 0;
}

int *intersection(int set1[], int set1size,
                  int set2[], int set2Size,
                  int *interSize)
{
    *interSize = 0;
    for (int i = 0; i < set1size; i++)
    {
        if (isin(set2, set2Size, set1[i]))
        {
            (*interSize)++;
        }
    }

    int *interSet = (int *)malloc(*interSize * sizeof(int));
    int index = 0;
    for (int i = 0; i < set1size; i++)
    {
        if (isin(set2, set2Size, set1[i]))
        {
            interSet[index] = set1[i];
            index++;
        }
    }
    return interSet;
}