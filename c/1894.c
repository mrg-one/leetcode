int chalkReplacer(int* chalk, int chalkSize, int k) {

    int demand = 0;

    for (int i = 0; i < chalkSize; i++)
    {
        k -= chalk[i];
        demand += chalk[i];

        if(k < 0)
            return i;
    }

    k %= demand;

    for (int i = 0; i < chalkSize; i++)
    {
        k -= chalk[i];
        if (k < 0)
            return i;
    }

    return 0;
}